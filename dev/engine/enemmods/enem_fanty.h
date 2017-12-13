// Taken from MK1, modified for speed and simplicity

if (!paused) {

	// Who should I pursue?
	if (game_mode == GM_1P) {
		prx = prx_uwol; pry = pry_uwol;
	} else {
		/*
		rda = DELTA (prx_uwol, en_x [3]); // dx
		rdb = DELTA (pry_uwol, en_y [3]); // dy
		rdc = MIN (rda, rdb);
		d1 = (rda + rdb - (rdc >> 1) - (rdc >> 2) + (rdc >> 4));

		rda = DELTA (prx_meemaid, en_x [3]); // dx
		rdb = DELTA (pry_meemaid, en_y [3]); // dy
		rdc = MIN (rda, rdb);
		d2 = (rda + rdb - (rdc >> 1) - (rdc >> 2) + (rdc >> 4));

		if (d1 <= d2) {
			prx = prx_uwol; pry = pry_uwol;
		} else {
			prx = prx_meemaid; pry = pry_meemaid;
		}
		*/
		// Let's try something way more simple...
		// Fanty pursues the one with more coins
		
		rda = 0;
		if (pscore_uwol > pscore_meemaid) {
			rda = 1;
		}
		if (pscore_meemaid > pscore_uwol) {
			rda = 2;
		}
		if (!rda) rda = 1 + (n_pant & 1);
		if (rda == 1) {
			if (pdead_uwol || pflickering_uwol) {
				rda = 2;
			}
		} else {
			if (pdead_meemaid || pflickering_meemaid) {
				rda = 1;
			}
		}	

		if (rda == 1) {
			prx = prx_uwol; pry = pry_uwol;
		} else {
			prx = prx_meemaid; pry = pry_meemaid;
		}
	}

	// Modify v
	/*
	enf_vx = saturate (enf_vx + add_sign (prx - en_x [3], FANTY_A), FANTY_MAXV);
	enf_vy = saturate (enf_vy + add_sign (pry - en_y [3], FANTY_A), FANTY_MAXV);
	*/
	// This is faster:

	if (prx < en_x [3]) { enf_vx -= FANTY_A; if (enf_vx < -FANTY_MAXV) enf_vx = -FANTY_MAXV; }
	else if (prx > en_x [3]) { enf_vx += FANTY_A; if (enf_vx > FANTY_MAXV) enf_vx = FANTY_MAXV; }
	if (pry < en_y [3]) { enf_vy -= FANTY_A; if (enf_vy < -FANTY_MAXV) enf_vy = -FANTY_MAXV; }
	else if (pry > en_y [3]) { enf_vy += FANTY_A; if (enf_vy > FANTY_MAXV) enf_vy = FANTY_MAXV; }

	// Horizontal
	enf_x += enf_vx; 
	if (enf_x < 0) enf_x = 0;
	if (enf_x > 3840) enf_x = 3840;
	en_x [3] = enf_x >> 4;

	enf_y += enf_vy ; 
	if (enf_y < 0) enf_y = 0;
	if (enf_y > 2816) enf_y = 2816;
	en_y [3] = enf_y >> 4;
}

msl_add (
	en_x [3], en_y [3] + sprite_adjust, 
	spr_fanty [((en_x [3] < prx) ? 0 : 2) + ((en_x [3] >> 3) & 1)]
	);
