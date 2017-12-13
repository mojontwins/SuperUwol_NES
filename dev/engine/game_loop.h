// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

void enter_screen (const unsigned char *pal, void (*func) (void)) {
	scroll (0, 472);
	
	cls ();
	(*func) ();
	
	pal_bg (pal);
	ppu_on_all ();
	fade_in ();
}

void exit_cleanly (void) {
	set_vram_update (0);
	oam_hide_rest (0);
	music_stop ();
	fade_out ();
	ppu_off ();	
}

void pal_cycle (void) {
	pal_col (2, 0x20 | rdb); rdb ++; if (rdb == 0xd) rdb = 1;
}

void game_loop (void) {
	cls ();
	scroll (252, ntsc ? 464 : 472);
	
	msl_init ();
	draw_scr ();
	enems_load ();
	coins_init ();
	players_init ();
	clothes_init ();
	print_hud ();
	
	exits_on = 0;
	half_life = 0;
	frame_counter = 0;
	ticker = 0;
	dead_counter = 100;
	fanty_on = visited [n_pant];
	paused = 0;
	pcoins_uwol = 0; pcoins_meemaid = 0;

	// 1P : Time = 2 x coins.
	// 2P : Time = 1.5 x coins.
	game_time = coins_max << 1;
	if (game_mode != GM_1P) 
		game_time = game_time - (coins_max >> 1);

	ppu_on_all ();
	ppu_mask (0x18); 
	fade_in ();
	
	music_play (MUSIC_INGAME_A + seq_level);
	seq_level ++; if (seq_level == 5) seq_level = 0;
	set_vram_update (update_list);
	
	while (1) {
		update_list_index = 0; // Reset update list
		pad0 = pad_poll (0); pad1 = pad_poll (1);

		if ((pad0 | pad1) & PAD_START) {
			if (!debounce_pause) {
				debounce_pause = 1;
				paused = !paused;
				pal_bright (4 - paused);
				sfx_play (SFX_START, SC_LEVEL);
				music_pause (paused);
			}
		} else debounce_pause = 0;
		
		half_life = 1 - half_life;
		frame_counter ++;

		if (!paused) {
			ticker ++; if (ticker == ticks) {
				ticker = 0; 
				if (game_time) {
					if (game_time <= 6) sfx_play (SFX_TIC_TOC, SC_LEVEL);
					game_time --; show_time ();
				} else if (!fanty_on) {
					music_stop ();
					sfx_play (SFX_FANTY, SC_LEVEL);
					music_play (MUSIC_FANTY);
					fx_flash ();				
					fanty_init ();
					fanty_on = 1; en_t [3] = 6;
				}
			}
		}

		msl_open ();		// Start adding sprites
		
		if (!exits_on) {
			coins_move ();
			if (!coins_max) {
				if (game_mode != GM_2P_VS) {
					exits_on = 1;
					exits_init ();
				} else {
					gen_result = GS_WIN;
					break;
				}
			}
		} else {
			gen_result = exits_move ();
			if (gen_result) {
				while (game_time --) {
					show_time ();
					add_to_score_uwol (SCORE_SECONDS);
					if (game_mode == GM_2P_COOP)
						add_to_score_meemaid (SCORE_SECONDS);
					update_list [update_list_index] = NT_UPD_EOF;
					sfx_play (SFX_COIN, SC_LEVEL);
					delay (4);
					update_list_index = 0; // Reset update list
				}
				break;
			}
		}
		
		clothes_move ();
		enems_move ();
		if (!paused) players_move ();
		
		msl_close ();		// Send sprites to OAM

		update_list [update_list_index] = NT_UPD_EOF;
		ppu_wait_nmi ();

		if (pdead_uwol && (game_mode == GM_1P || pdead_meemaid)) {
			if (dead_counter) {
				dead_counter --;
			} else {
				gen_result = GS_GAME_OVER; break;
			}
		}
	}

	// Exit cleanly...
	exit_cleanly ();
}

void wait_time_or_input (void) {
	rda = ((pad_poll (0) | pad_poll (1)) != 0);
	while (game_time) {
		ticker ++; if (ticker == ticks) {
			ticker = 0;
			game_time --;
		}

		if (pad_poll (0) || pad_poll (1)) {
			if (!rda) break;
		} else {
			rda = 0;
		}

		ppu_wait_nmi ();
	}
}

void pyramid_screen_do (void) {
	enter_screen (pal_bg_p, pyramid_draw);

	// Base for pointing arrow:
	rdx = 1 + 8 * (15 - n_floor + (n_column << 1));
	rdy = SPRITE_ADJUST_PAL + ((PYRAMID_TOP + n_floor) << 3) - 28;

	music_play (MUSIC_PYRAMID);

	game_time = PYRAMID_SCREEN_TIME; ticker = 0;

	rda = ((pad_poll (0) | pad_poll (1)) != 0);
	while (game_time) {
		frame_counter ++;
		ticker ++; if (ticker == ticks) {
			ticker = 0;
			game_time --;
		}

		oam_meta_spr (rdx, rdy - pyramid_bounce [frame_counter & 15], 0, spr_items [2]);
		
		if (pad_poll (0) || pad_poll (1)) {
			if (!rda) break;
		} else {
			rda = 0;
		}

		ppu_wait_nmi ();
	}

	// Exit cleanly	
	exit_cleanly ();
}

void vs_screen_round (void) {
	enter_screen (pal_bg_p, vs_screen_round_draw);

	music_play (MUSIC_DALE_FRAN);

	game_time = ROUND_SCREEN_TIME; ticker = 0;

	wait_time_or_input ();

	// Exit cleanly	
	exit_cleanly ();	
}

void vs_screen_do (void) {
	rdx = 140;
	rda = 0; rdb = 40;
	if (pcoins_uwol > pcoins_meemaid) {
		pwins_uwol ++;
		rdx = 132; rdb = 63;
	} else if (pcoins_uwol < pcoins_meemaid) {
		pwins_meemaid ++;
		rda = 23;
	} 
	oam_meta_spr (108, 136, 0, spr_player [rda]);
	oam_meta_spr (rdx, 136, 16, spr_player [rdb]);

	enter_screen (pal_bg_p, vs_screen_draw);

	music_play (MUSIC_VS);

	rda = ((pad_poll (0) | pad_poll (1)) != 0);
	while (1) {
		i = (pad_poll (0) | pad_poll (1));
		if (i) {
			if (!rda) {
				rda = 1;
				if (i & PAD_START) { gen_result = 1; break; }
				if (i & PAD_SELECT) { gen_result = 0; break; }
			}
		} else rda = 0;

		ppu_wait_nmi ();
	}

	// Exit cleanly	
	exit_cleanly ();	
}

void title_do (void) {
	enter_screen (pal_bg_t, draw_title_logo);
	scroll (0, 472);

	rdc = 1;
	rda = ((pad_poll (0) | pad_poll (1)) != 0);
	while (rdc) {
		game_time = TITLE_SCREEN_MUSIC_TIME; ticker = 0;
		music_play (MUSIC_TITLE);
		while (game_time) {
			ticker ++; if (ticker == ticks) {
				ticker = 0;
				game_time --;
			}
			if ((pad_poll (0) | pad_poll (1)) & PAD_START) {
				if (!rda) { rdc = 0; break; }
			} else {
				rda = 0;
			}
			ppu_wait_nmi ();
		}
		music_stop ();

		game_time = TITLE_SCREEN_PALSHIFT_TIME; ticker = 0;
		rdb = 1;
		while (game_time) {
			ticker ++; if (ticker == ticks) {
				ticker = 0;
				game_time --;
			}
			
			pal_cycle ();
			if ((pad_poll (0) | pad_poll (1)) & PAD_START) {
				if (!rda) { rdc = 0; break; }
			} else {
				rda = 0;
			}
			ppu_wait_nmi ();
		}
		pal_col (2, 0x26);
	}

	sfx_play (SFX_START, SC_LEVEL);
	draw_title_menu ();

	rda = ((pad_poll (0) | pad_poll (1)) != 0);
	game_mode = 1;
	while (1) {
		frame_counter ++;
		oam_meta_spr (80 - (pyramid_bounce [frame_counter & 15] >> 1), ((17 + game_mode) << 3) + 4, 0, spr_items [3]);
		pal_cycle ();

		rdc = game_mode;
		i = (pad_poll (0) | pad_poll (1));
		if (i) {
			if (!rda) {
				rda = 1;
				if (i & PAD_DOWN) if (game_mode < 3) game_mode ++;
				if (i & PAD_UP) if (game_mode > 1) game_mode --;
				if (i & PAD_SELECT) { game_mode ++; if (game_mode == 4) game_mode = 1; }
				if ((i & PAD_START) || (i & PAD_A)) break;
			}
		} else rda = 0;
		if (game_mode != rdc) sfx_play (SFX_SELECT, SC_LEVEL);

		ppu_wait_nmi ();
	}

	sfx_play (SFX_START, SC_LEVEL);
	delay (60);

	// Exit cleanly
	exit_cleanly ();	
}

void ending_do (void) {
	which_ending = (total_coins >= 256) ? 16 : 0; 
	enter_screen (pal_bg_cuts, draw_ending_picture);

	music_play (MUSIC_ENDING_KO + (which_ending != 0));

	game_time = ENDING_SCREEN_TIME; ticker = 0;
	wait_time_or_input ();

	// Exit cleanly	
	exit_cleanly ();		
}

void game_over (void) {
	enter_screen (pal_bg_p, game_over_draw);

	music_play (MUSIC_GAME_OVER);

	game_time = GAME_OVER_SCREEN_TIME; ticker = 0;
	wait_time_or_input ();

	// Exit cleanly	
	exit_cleanly ();			
}
