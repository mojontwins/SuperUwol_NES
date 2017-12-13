// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

void exits_init (void) {
	if (scr_buff [0xa2] == 6) {
		exit_left = 0;
	} else {
		exit_left = 1;
		rdx = 2; rdy = 11; rdt = 2;
		draw_game_tile_update_list ();
	}

	if (scr_buff [0xad] == 6) {
		exit_right = 0;
	} else {
		exit_right = 1;
		rdx = 13; rdy = 11; rdt = 3;
		draw_game_tile_update_list ();
	}

	// Remove linear baddies
	gpit = 3; while (gpit --) {
		en_t [gpit] = 0;
	}
}

unsigned char exits_move (void) {
	if (exit_left) {
		msl_add (32, sprite_adjust + exit_bounce [frame_counter & 15], spr_items [2]);
	} else msl_add_empty ();

	if (exit_right) {
		msl_add (208, sprite_adjust + exit_bounce [(8 + frame_counter) & 15], spr_items [2]);
	} else msl_add_empty ();

	// Exits instead of coins. 
	// That means that MAX_COINS - 2 blank sprites must be sent to the mixer
	gpit = MAX_COINS - 2; while (gpit --) {
		msl_add_empty ();
	}

	if ((pad0 & PAD_DOWN) || (pad0 & PAD_B)) {
		if (prx_uwol >= 32-4 && prx_uwol <= 32+12 && pry_uwol == 160) {
			return GS_WIN_LEFT;
		}
		if (prx_uwol >= 208-4 && prx_uwol <= 208+12 && pry_uwol == 160) {
			return GS_WIN_RIGHT;
		}
	}

	if ((pad1 & PAD_DOWN) || (pad1 & PAD_B)) {
		if (prx_meemaid >= 32-4 && prx_meemaid <= 32+12 && pry_meemaid == 160) {
			return GS_WIN_LEFT;
		}
		if (prx_meemaid >= 208-4 && prx_meemaid <= 208+12 && pry_meemaid == 160) {
			return GS_WIN_RIGHT;
		}
	}

	return 0;
}
