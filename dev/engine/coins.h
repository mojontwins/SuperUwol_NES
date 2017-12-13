// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

void coins_init (void) {
	// If screen has been visited, there's no coins.
	coins_max = coins_fr = 0;
	if (visited [n_pant]) return;
	gp_coins = (unsigned char *) coins + (n_pant << 4);
	gpit = MAX_COINS; while (gpit --) {
		if (gp_coins [gpit]) {
			scr_buff [gp_coins [gpit]] = 0x03 | (gpit << 4);
			coins_act [gpit] = 1;
			coins_max ++;
		} else coins_act [gpit] = 0;
	}
}

void coins_move (void) {
	if ((frame_counter & 7) == 0) {
		coins_fr ++; if (coins_fr == 6) coins_fr = 0;
	}

	gpit = MAX_COINS; while (gpit --) {
		rdb = gp_coins [gpit];
		rdy = (rdb & 0xf0) + sprite_adjust;
		rdx = rdb << 4;
		if (coins_act [gpit]) { 
			msl_add (rdx, rdy, spr_coins [coins_fr]);
		} else {
			if (coins_ct [gpit]) {
				rda = coins_ct [gpit] --;
				while (rda >= 6) rda -= 6;
				if (coins_ct [gpit] >= 16) {
					rdy = rdy - 32 + ((coins_ct [gpit] - 16) << 2); 
				} else rdy = rdy - 32;
				msl_add (rdx, rdy, spr_coins [rda]);
			} else msl_add_empty ();
		}		
	}
}
