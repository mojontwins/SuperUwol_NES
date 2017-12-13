// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

void add_to_score_uwol (unsigned char score) {
	pscore_uwol += score;
	p_t5 (0x0f, 0, pscore_uwol);
}

void add_to_score_meemaid (unsigned char score) {
	pscore_meemaid += score;
	p_t5 (0x0f, 1, pscore_meemaid);
}

void show_coins (void) {
	p_t3 (0x1c, 0, total_coins);
}

void add_to_coins (void) {
	if (game_mode == GM_2P_VS) return;
	total_coins ++;
	show_coins ();
}

void show_time (void) {
	p_t2 (0x1d, 1, game_time);
}

void print_life (void) {
	p_t2 (0x05, 0, plife_uwol);
	if (game_mode == GM_2P_COOP) {
		p_t2 (0x05, 1, plife_meemaid);
	}
}

/* 
GM_1P:

	0               1
	0123456789abcdef0123456789abcdef
	 1UP=XX  SCORE=ZZZZZ  COINS=XXX
	 LEVEL=XX/YY            TIME=XX

GM_2P_COOP:

	0               1
	0123456789abcdef0123456789abcdef
	 1UP=XX  SCORE=ZZZZZ  COINS=XXX
	 2UP=YY  SCORE=ZZZZZ    TIME=XX

GM_2P_VS:

	0               1
	0123456789abcdef0123456789abcdef
	 1UP COINS=XX             
	 2UP COINS=YY           TIME=XX
*/

void print_hud (void) {
	switch (game_mode) {
		case GM_1P:
			p_s (0x01, 0x00, "1UP=");
			p_t2d (0x05, 0, plife_uwol);
			p_s (0x09, 0x00, "SCORE=");
			p_t5d (0x0f, 0, pscore_uwol);
			p_s (0x16, 0x00, "COINS=");
			p_t3d (0x1c, 0, total_coins);
			p_s (0x01, 0x01, "LEVEL=  /");
			p_t2d (0x07, 1, n_floor);
			p_t2d (0x0a, 1, n_column);
			p_s (0x18, 0x01, "TIME=");
			p_t2d (0x1d, 1, game_time);
			break;
		case GM_2P_COOP:
			p_s (0x01, 0x00, "1UP=");
			p_t2d (0x05, 0, plife_uwol);
			p_s (0x01, 0x01, "2UP=");
			p_t2d (0x05, 1, plife_meemaid);
			p_s (0x09, 0x00, "SCORE=");
			p_t5d (0x0f, 0, pscore_uwol);
			p_s (0x09, 0x01, "SCORE=");
			p_t5d (0x0f, 1, pscore_uwol);
			p_s (0x16, 0x00, "COINS=");
			p_t3d (0x1c, 0, total_coins);
			p_s (0x18, 0x01, "TIME=");
			p_t2d (0x1d, 1, game_time);
			break;
		case GM_2P_VS:
			p_s (0x01, 0x00, "1UP COINS=00");
			p_s (0x01, 0x01, "2UP COINS=00");
			p_s (0x18, 0x01, "TIME=");
			p_t2d (0x1d, 1, game_time);
			break;
	}
	update_list [update_list_index] = NT_UPD_EOF;
	ppu_wait_nmi ();
}
