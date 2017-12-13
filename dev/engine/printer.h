// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

#define TI_FLOORS		8
#define TI_CEILINGS		12
#define TI_BACKGROUNDS	16
#define TI_SHADOWS		20
#define TI_BLOCKS		24
#define TI_BLOCKS_ALT	28
#define TI_BLOCKS_VERT	32
#define TI_PLAT			6
#define TI_KILL			7

#ifdef DEBUG
unsigned char hex_digit (unsigned char n) {
	if (n < 10) return n + 16;
	return n + 23;
}

void debug_pt_hex (unsigned char x, unsigned char y, unsigned char n) {
	vram_adr (NAMETABLE_A + x + (y << 5));
	vram_put (hex_digit (n >> 4));
	vram_put (hex_digit (n & 0x0f));
}
#endif

void cls (void) {
	vram_adr (NAMETABLE_A);
	vram_fill (0, 1024);
}

void reset_attributes (void) {
	gpit = 64; while (gpit --) attr_table [gpit] = rda;
}

void draw_attributes (void) {
	vram_adr (NAMETABLE_A + 960);
	vram_write (attr_table, 64);
}

void  fade_out (void) {
	for (fader = 4; fader > -1; fader --) {
		pal_bright (fader);
		delay (FADE_DELAY);
	}	
}

void  fade_in (void) {
	for (fader = 0; fader < 5; fader ++) {
		pal_bright (fader);
		delay (FADE_DELAY);
	}	
}

void upd_attr_table (unsigned char x, unsigned char y, unsigned char tl) {
	rdc = (x >> 2) + ((y >> 2) << 3);
	rdb = ((x >> 1) & 1) + (((y >> 1) & 1) << 1);
	rda = attr_table [rdc];
	rda = (rda & bitmasks [rdb]) | (tileset_pals [tl] << (rdb << 1));
	attr_table [rdc] = rda;
}

// Draws tile rdt @ rdx, rdy
void draw_game_tile () {
	gp_tsmap = (unsigned char *) tileset_tmaps + (rdt << 2);
	rda = rdx << 1; rdb = TOP_ADJUST + (rdy << 1);
	gp_addr = NAMETABLE_A + rda + (rdb << 5);
	vram_adr (gp_addr);
	vram_put (*gp_tsmap ++);
	vram_put (*gp_tsmap ++);
	vram_adr (gp_addr + 32);
	vram_put (*gp_tsmap ++);
	vram_put (*gp_tsmap);
	upd_attr_table (rda, rdb, rdt);
}

void print_16_strip (void) {
	rdx = 0; rdit = 16; while (rdit --) {
		rdt = *gp_gen ++; if (rdt) draw_game_tile (); 
		rdx ++;
	}
}

void print_logo (void) {
	gp_gen = (unsigned char *) tm_logo; 
	print_16_strip ();
}

// Draws screen pointed by n_pant
void draw_scr (void) {
	tileset_pals = (unsigned char *) tsmap_pals;
	tileset_tmaps = (unsigned char *) tsmap_tmaps;
	rda = 0xff; reset_attributes ();

	// (Pre)calculate metatile indexes from n_pant
	// n_pant is a 6 bits number. 
	// ppbbff
	c_pal_bg = (unsigned char *) pal_bgs [n_pant >> 4];
	pal_bg (c_pal_bg);
	rdbg = (n_pant & 0x0f) >> 2;
	rdfg = n_pant & 0x03;

	// Each screen is 48 bytes.
	gp_map = (unsigned char *) map + (n_pant << 5) + (n_pant << 4);

	// Render
	rdx = rdy = 0;
	rdct = 0; rdbyte = *gp_map ++; 
	for (rdit = 0; rdit < 192; rdit ++) {
		rdxt = rdbyte & 0x03;
		rdbyte = rdbyte >> 2;
		rdct = (rdct + 1) & 3; if (!rdct) rdbyte = *gp_map ++;
	
		scr_buff [rdit] = rdxt << 1;
		
		switch (rdxt) {
			case 1:
				// Kill tile
				rdt = TI_KILL;
				draw_game_tile ();
				break;
			case 2:
				// platform
				rdt = TI_PLAT;
				draw_game_tile ();
				break;
			case 3:
				// floor/ceiling/block
				if (!rdy) 
					rdt = TI_CEILINGS + rdfg;
				else if (rdy >= 11)
					rdt = TI_FLOORS + rdfg;
				else
					rdt = (rand8 () & 15) == 1 ? TI_BLOCKS_ALT + rdfg : TI_BLOCKS + rdfg;
				draw_game_tile ();
				break;
		}
		rdx = (rdx + 1) & 15; if (!rdx) rdy ++;
	}

	// 2nd pass: shadowed bkg
	gp_tsmbk = (unsigned char *) tsmap_tmaps + ((TI_BACKGROUNDS + rdbg) << 2);
	gp_tsmsh = (unsigned char *) tsmap_tmaps + ((TI_SHADOWS + rdbg) << 2);
	rdx = rdy = 0;
	for (rdit = 0; rdit < 192; rdit ++) {
		if (!scr_buff [rdit]) {
			// Believe it or not, this draws a bkg tile with shadows.
			gp_addr = NAMETABLE_A + (((rdy << 1) + TOP_ADJUST) << 5) + (rdx << 1);
			vram_adr (gp_addr);
		rdb = ATTR (rdx - 1, rdy);
			vram_put (((!rdy && rdb) || ATTR (rdx - 1, rdy - 1)) ? gp_tsmsh [0] : gp_tsmbk [0]);
			vram_put (ATTR (rdx, rdy - 1) ? gp_tsmsh [1] : gp_tsmbk [1]);
			vram_adr (gp_addr + 32);
			vram_put (rdb ? gp_tsmsh [2] : gp_tsmbk [2]);
			vram_put (gp_tsmbk [3]);
			upd_attr_table (rdx << 1, TOP_ADJUST + (rdy << 1), TI_BACKGROUNDS + rdbg);
		} else if (scr_buff [rdit] == 3) {
			if (
					(ATTR (rdx, rdy - 1) || ATTR (rdx, rdy + 1)) && 
					!((rdx & ATTR (rdx - 1, rdy) == 3) || (rdx < 15 & ATTR (rdx + 1, rdy) == 3))
			) {
				rdt = TI_BLOCKS_VERT + rdfg;
				draw_game_tile ();
			}
		}
		rdx = (rdx + 1) & 15; if (!rdx) rdy ++;
	}

	// Logo
	if (!ntsc) { print_logo (); }

	draw_attributes ();
}

void p_t2 (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	UPDATE = MSB (gp_addr) | NT_UPD_HORZ;
	UPDATE = LSB (gp_addr);
	UPDATE = 2;
	UPDATE = (n / 10) + 16;
	UPDATE = ((n % 10)) + 16;
}

void p_t3 (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	UPDATE = MSB (gp_addr) | NT_UPD_HORZ;
	UPDATE = LSB (gp_addr);
	UPDATE = 3;
	UPDATE = (n / 100) + 16;
	UPDATE = ((n % 100) / 10) + 16;
	UPDATE = ((n % 10)) + 16;
}

void p_t5 (unsigned char x, unsigned char y, unsigned int n) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	UPDATE = MSB (gp_addr) | NT_UPD_HORZ;
	UPDATE = LSB (gp_addr);
	UPDATE = 5;
	UPDATE = (n / 10000) + 16;
	UPDATE = ((n % 10000) / 1000) + 16;
	UPDATE = ((n % 1000) / 100) + 16;
	UPDATE = ((n % 100) / 10) + 16;
	UPDATE = ((n % 10)) + 16;
}

void draw_game_tile_update_list () {
	gp_tsmap = (unsigned char *) tsmap_tmaps + (rdt << 2);
	rda = rdx << 1; rdb = TOP_ADJUST + (rdy << 1);
	gp_addr = NAMETABLE_A + rda + (rdb << 5);
	UPDATE = MSB (gp_addr) | NT_UPD_HORZ;
	UPDATE = LSB (gp_addr);
	UPDATE = 2;
	UPDATE = *gp_tsmap ++;
	UPDATE = *gp_tsmap ++;
	gp_addr += 32;
	UPDATE = MSB (gp_addr) | NT_UPD_HORZ;
	UPDATE = LSB (gp_addr);
	UPDATE = 2;
	UPDATE = *gp_tsmap ++;
	UPDATE = *gp_tsmap ++;
	upd_attr_table (rda, rdb, rdt);
	gp_addr = 0x23c0 + rdc;
	UPDATE = MSB(gp_addr);
	UPDATE = LSB(gp_addr);
	UPDATE = rda;
}

void p_t2d (unsigned char x, unsigned char y, unsigned char n) {
	vram_adr (NAMETABLE_A + (y << 5) + x);
	vram_put ((n / 10) + 16);
	vram_put ((n % 10) + 16);
}

void p_t3d (unsigned char x, unsigned char y, unsigned char n) {
	vram_adr (NAMETABLE_A + (y << 5) + x);
	vram_put ((n / 100) + 16);
	vram_put (((n % 100) / 10) + 16);
	vram_put ((n % 10) + 16);
}

void p_t5d (unsigned char x, unsigned char y, unsigned int n) {
	vram_adr (NAMETABLE_A + (y << 5) + x);
	vram_put ((n / 10000) + 16);
	vram_put (((n % 10000) / 1000) + 16);
	vram_put (((n % 1000) / 100) + 16);
	vram_put (((n % 100) / 10) + 16);
	vram_put ((n % 10) + 16);
}

void p_s (unsigned char x, unsigned char y, unsigned char *s) {
	vram_adr (NAMETABLE_A + (y << 5) + x);
	while (rda = *s ++) vram_put (rda - 32);
}

void p_s_up (unsigned char x, unsigned char y, unsigned char l, unsigned char *s) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	UPDATE = MSB (gp_addr) | NT_UPD_HORZ;
	UPDATE = LSB (gp_addr);
	UPDATE = l;
	gpit = l; while (gpit --) UPDATE = *s ++ - 32;
}

void fx_flash (void) {
	pal_bg (pal_light_bg);
	pal_spr (pal_light_fg);
	update_list [update_list_index] = NT_UPD_EOF;
	ppu_wait_nmi ();
	ppu_wait_nmi ();
	pal_bg (c_pal_bg);
	pal_spr (pal_ss_0);
}

void pyramid_draw () {
	tileset_pals = (unsigned char *) tsmap_pals;
	tileset_tmaps = (unsigned char *) tsmap_tmaps;

	for (gpit = 0; gpit < 64; gpit ++) {
		attr_table [gpit] = gpit < 40 ? 0x55 : 0xff;
	}
	rdy = 1; print_logo ();

	gp_gen = visited; rdit = 0;
	for (rdy = 0; rdy < 10; rdy ++) {
		for (rdx = 0; rdx <= rdy; rdx ++) {
			vram_adr (NAMETABLE_A + ((PYRAMID_TOP + rdy) << 5) + 15 - rdy + (rdx << 1));
			if (*gp_gen ++ || rdit == n_pant) {
				vram_put (66);
				vram_put (67);
			} else {
				vram_put (64);
				vram_put (65);
			}
			rdit ++;
		}
	}

	update_list_index = 0; // Reset update list

	rdx = 1; rdy = 9; rdt = 41; draw_game_tile ();
	p_s (0x04, 0x15, "="); p_t2d (0x05, 0x15, plife_uwol);
	p_s (0x09, 0x15, "SCORE="); p_t5d (0x0f, 0x15, pscore_uwol);
	p_s (0x16, 0x15, "COINS="); p_t3d (0x1c, 0x15, total_coins);

	if (game_mode == GM_2P_COOP) {
		rdx = 1; rdy = 10; rdt = 42; draw_game_tile ();
		p_s (0x04, 0x17, "="); p_t2d (0x05, 0x17, plife_meemaid);
		p_s (0x09, 0x17, "SCORE="); p_t5d (0x0f, 0x17, pscore_meemaid);
	}

	draw_attributes ();
}

void game_over_draw (void) {
	rda = 0xff; reset_attributes ();

	p_s (11, 10, "GAME OVER!");

	rdx = 4; rdy = 6; rdt = 41; draw_game_tile ();
	p_s (11, 15, "SCORE="); p_t5d (17, 15, pscore_uwol);

	if (game_mode == GM_2P_COOP) {
		rdx = 4; rdy = 7; rdt = 42; draw_game_tile ();
		p_s (11, 17, "SCORE="); p_t5d (17, 17, pscore_meemaid);
	}

	draw_attributes ();
}

void vs_screen_round_draw (void) {
	tileset_pals = (unsigned char *) tsmap_pals;
	tileset_tmaps = (unsigned char *) tsmap_tmaps;
	rda = 0xff; reset_attributes ();
	rdy = 1; print_logo ();
	p_s (12, 13, "ROUND"); p_t2d (18, 13, n_pant + 1);
	p_s (11, 15, "DALE FRAN!");
	draw_attributes ();
}

void thick_number (unsigned char x, unsigned char y, unsigned char n) {
	gp_gen = (unsigned char *) bn + (n << 4) - n;
	gp_addr = NAMETABLE_A + (y << 5) + x;
	gpit = 5; while (gpit --) {
		vram_adr (gp_addr); 
		gpjt = 3; while (gpjt --) {
			if (*gp_gen ++) vram_put (9); else vram_put (8);
		}
		gp_addr += 32;
	}
}

void vs_screen_draw (void) {
	tileset_pals = (unsigned char *) tsmap_pals;
	tileset_tmaps = (unsigned char *) tsmap_tmaps;
	rda = 0xff; reset_attributes ();
	rdy = 1; print_logo ();
	
	// Result
	if (pcoins_uwol > pcoins_meemaid) {
		p_s (11, 7, "UWOL WINS!");
	} else if (pcoins_uwol < pcoins_meemaid) {
		p_s (10, 7, "MEEMAID WINS!");
	} else {
		p_s (11, 7, "DRAW GAME!");
	}

	// Big numbers
	p_s (2, 9, "1UP UWOL");
	p_s (20, 9, "2UP MEEMAID");
	for (rdy = 11; rdy <= 17; rdy ++) {
		vram_adr (NAMETABLE_A + (rdy << 5) + 2);
		vram_fill (8, 9);
		vram_adr (NAMETABLE_A + (rdy << 5) + 21);
		vram_fill (8, 9);
	}
	thick_number (3, 12, pwins_uwol / 10);
	thick_number (7, 12, pwins_uwol % 10);
	thick_number (22, 12, pwins_meemaid / 10);
	thick_number (26, 12, pwins_meemaid % 10);
	p_s (2, 19, "COINS=");
	p_t2d (8, 19, pcoins_uwol);
	p_s (22, 19, "COINS=");
	p_t2d (28, 19, pcoins_meemaid);

	// Some floor tiles
	rdx = 6; rdy = 8; rdt = TI_FLOORS + rdfg;
	gpit = 4; while (gpit --) { draw_game_tile (); rdx ++; }

	// Final text
	p_s (6, 21, "PRESS START TO GO!");
	p_s (6, 23, "PRESS SELECT TO EXIT");

	draw_attributes ();
}

void draw_frame (void) {
	rdy = 0; rdx = 0; 
	gp_gen = (unsigned char *) tm_strip_1; 
	print_16_strip ();
	for (rdy = 1; rdy < 11; rdy ++) {
		rdx = 1; rdt = 33; draw_game_tile ();
		rdx = 14; rdt = 34; draw_game_tile ();
	}
	rdx = 0; gp_gen = (unsigned char *) tm_strip_2;
	print_16_strip ();
}

void draw_title_logo (void) {
	tileset_pals = (unsigned char *) title_pals;
	tileset_tmaps = (unsigned char *) title_tmaps;

	rda = 0xff; reset_attributes ();

	draw_frame ();
	rdx = 5; rdy = 1; 
	for (rdt = 0; rdt < 30; rdt ++) {
		draw_game_tile ();
		rdx ++; if (rdx == 11) { rdx = 5; rdy ++; }
	}

	p_s (12, 15, "STARRING");
	p_s (9, 16, "UWOL & MEEMAID");
	p_s (10, 19, "PRESS START!");
	p_s (5, 23, "# 2015 THE MOJON TWINS");

	draw_attributes ();
}

void draw_title_menu (void) {
	update_list_index = 0; // Reset update list
	p_s_up (10, 19, 12, "            ");
	p_s_up (12, 18, 8, "1 PLAYER");
	p_s_up (12, 19, 9, "2 PLAYERS");
	p_s_up (12, 20, 8, "VS. MODE");

	set_vram_update (update_list);
	update_list [update_list_index] = NT_UPD_EOF;
	ppu_wait_nmi ();
	set_vram_update (0);
}

void draw_ending_picture (void) {
	// specify an offset of 16 to draw the "good" image, 0 for bad, in "which_ending".
	
	rda = 0xff; reset_attributes ();

	tileset_pals = (unsigned char *) frame_pals;
	tileset_tmaps = (unsigned char *) title_tmaps;
	draw_frame ();

	tileset_pals = (unsigned char *) ending_pals;
	tileset_tmaps = (unsigned char *) ending_tmaps;
	rdx = 6; rdy = 2;
	for (rdt = which_ending; rdt < which_ending + 16; rdt ++) {
		draw_game_tile ();
		rdx ++; if (rdx == 10) { rdx = 6; rdy ++;}
	}

	if (which_ending) {
		// Good text
		p_s (8, 16, "WHOAH, THAT'S IT!");
		p_s (9, 17, "I THINK WE HAVE");
		p_s (9, 18, "ENOUGH MONEY TO");
		p_s (8, 19, "BUY A CORSHONETA!");
	} else {
		// Bad text
		p_s (8, 16, "NOT ENOUGH MONEY.");
		p_s (6, 17, "I THINK WE'LL HAVE TO");
		p_s (8, 18, "ENTER THE MANSION");
		p_s (9, 19, "ONCE AGAIN...!");
	}

	draw_attributes ();
}
	
void intro_screen (void) {
	scroll (0,0); cls ();
	pal_bg (pal_mt);
	pal_spr (pal_mt);

	p_s (5, 26, "# 2015 THE MOJON TWINS");
	p_s (4, 27, "NOT LICENSED BY NINTENDO");

	ppu_on_all ();
	fade_in ();

	rdy = 240; ticker = 255;
	while (ticker --) {
		if (pad_poll (0) | pad_poll (1)) break;
		if (rdy == 121) sfx_play (SFX_NINTENDONT, SC_LEVEL);
		if (rdy > 120) rdy --;
		oam_meta_spr (102, rdy, 0, spr_logo_00);
		ppu_wait_nmi ();
	}
	oam_hide_rest (0);
	fade_out ();
	ppu_off ();
}
