// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

void players_init (void) {
	prx_uwol = 20;
	prx_meemaid = 228;
	pfacing_uwol = PFACING_RIGHT;
	pfacing_meemaid = PFACING_LEFT;

	pry_uwol = 144;

	px_uwol = prx_uwol << 4;
	py_uwol = pry_uwol << 4;

	pvx_uwol = pvy_uwol = 0;
	pj_uwol = pctj_uwol = 0;

	ppossee_uwol = 0;
	pstate_uwol = PSTATE_NORMAL;
	pflickering_uwol = 0;
	pdead_uwol = (plife_uwol == 0);

	pry_meemaid = 144;

	px_meemaid = prx_meemaid << 4;
	py_meemaid = pry_meemaid << 4;

	pvx_meemaid = pvy_meemaid = 0;
	pj_meemaid = pctj_meemaid = 0;

	ppossee_meemaid = 0;
	pstate_meemaid = PSTATE_NORMAL;
	pflickering_meemaid = 0;
	pdead_meemaid = (plife_meemaid == 0);
}

// All the killing logic.
void kill_player_uwol (void) {
	if (pflickering_uwol || pdead_uwol) return;
	if (pstate_uwol == PSTATE_NORMAL) {
		pstate_uwol = PSTATE_NAKED;
		pflickering_uwol = 100;
		clothes_create ();
	} else {
		pdead_uwol = 1;
		if (game_mode != GM_2P_VS) plife_uwol --;
		print_life ();
	}
}

void kill_player_meemaid (void) {
	if (pflickering_meemaid || pdead_meemaid) return;
	if (pstate_meemaid == PSTATE_NORMAL) {
		pstate_meemaid = PSTATE_NAKED;
		pflickering_meemaid = 100;
		clothes_create ();
	} else {
		pdead_meemaid = 1;
		if (game_mode != GM_2P_VS) plife_meemaid --;
		print_life ();
	}
}

// Adapted from MK1 NES.
// Collision box is a 8x16 rectangle @ prx, pry.
// Metasprites are 16x32 rectangles (16x24 graphics) but offset (-4, -16).
// Originally, this was just one parametrized function,
// but I've unrolled the arrays and duplicated the function for speed.

void players_move (void) {

	// ************
	// *** UWOL ***
	// ************
	
	i = pdead_uwol ? 0 : pad0;
	if (pflickering_uwol) pflickering_uwol --;
	hitv = 0;

	// ********
	// Vertical
	// ********

	// Gravity
	if (pvy_uwol < PLAYER_VY_FALLING_MAX) {
		pvy_uwol += PLAYER_G;
	} else {
		pvy_uwol = PLAYER_VY_FALLING_MAX;
	}

	// Move
	py_uwol += pvy_uwol;
	//if (py_uwol < 0) py_uwol = 0;
	if (py_uwol > 3072) {
		py_uwol = (240 - sprite_adjust) << 4;
		pstate_uwol = PSTATE_NAKED;
		kill_player_uwol ();
	}

	// Collide
	prx_uwol = px_uwol >> 4; pry_uwol = py_uwol >> 4;
	ptx1 = prx_uwol >> 4;
	ptx2 = (prx_uwol + 7) >> 4;
	
	// Ugly yet faster rewrite
	if (pvy_uwol < 0) {
		pty1 = pry_uwol >> 4;
		if ((ATTR (ptx1, pty1) & 0x0f) == 6 || (ATTR (ptx2, pty1) & 0x0f) == 6) {
			pvy_uwol = 0;
			pry_uwol = (pty1 + 1) << 4;
			py_uwol = pry_uwol << 4;
		}
	} else if (pvy_uwol > 0) {
		pty1 = (pry_uwol + 15) >> 4;
		if (((pry_uwol - 1) & 15) < 8) {
			rdb = ATTR (ptx1, pty1) & 0x0f;
			rdc = ATTR (ptx2, pty1) & 0x0f;
			if (rdb >= 4 || rdc >= 4) {
				pvy_uwol = 0;
				pry_uwol = (pty1 - 1) << 4;
				py_uwol = pry_uwol << 4;
			} 
			hitv = (rdb == 2 || rdc == 2);
		}
	}
	pty1 = (pry_uwol + 16) >> 4;
	ppossee_uwol = (ATTR (ptx1, pty1) >= 4 || ATTR (ptx2, pty1) >= 4);

	// Jump
	if (i & PAD_A) {
		if (!pjb_uwol) {
			pjb_uwol = 1;
			if (!pj_uwol) {
				if (ppossee_uwol || hitv) {
					pj_uwol = 1;
					pctj_uwol = 0;
					sfx_play (SFX_JUMP, SC_UWOL);
					pvy_uwol = -PLAYER_VY_JUMP_INITIAL;
				}
			}
		}
		if (pj_uwol) {
			rda = (PLAYER_AY_JUMP - (pctj_uwol >> 2) - (pctj_uwol >> 3));
			pvy_uwol -= (rda > 1 ? rda : 1);
			if (pvy_uwol < -PLAYER_VY_JUMP_MAX) pvy_uwol = -PLAYER_VY_JUMP_MAX;
			pctj_uwol ++; if (pctj_uwol == PLAYER_VY_JUMP_A_STEPS) pj_uwol = 0;
		}
	} else {
		pj_uwol = 0; pjb_uwol = 0;
	}

	// **********
	// Horizontal
	// **********

	// Poll pad
	if (i & PAD_LEFT) {
		pfacing_uwol = PFACING_LEFT;
		if (pvx_uwol > -PLAYER_VX_MAX) pvx_uwol -= PLAYER_AX;
	} else if (i & PAD_RIGHT) {
		pfacing_uwol = PFACING_RIGHT;
		if (pvx_uwol < PLAYER_VX_MAX) pvx_uwol += PLAYER_AX;
	} else {
		if (pvx_uwol > 0) {
			pvx_uwol -= PLAYER_RX; if (pvx_uwol < 0) pvx_uwol = 0;
		} else if (pvx_uwol < 0) {
			pvx_uwol += PLAYER_RX; if (pvx_uwol > 0) pvx_uwol = 0;
		}
	}

	// Move
	px_uwol += pvx_uwol;
	
	// Wrap around
	if (px_uwol < 0) px_uwol += 4096;
	if (px_uwol >= 4096) px_uwol -= 4096;

	// Collision
	prx_uwol = px_uwol >> 4;
	pty1 = pry_uwol >> 4;
	pty2 = (pry_uwol + 15) >> 4;
	if (pvx_uwol) {
		if (pvx_uwol < 0) {
			ptx1 = prx_uwol >> 4;
			ptx2 = (ptx1 + 1) << 4;
		} else {
			ptx1 = (prx_uwol + 7) >> 4;
			ptx2 = ((ptx1 - 1) << 4) + 8; 
		}

		rdb = ATTR (ptx1, pty1);
		rdc = ATTR (ptx1, pty2);

		if (rdb == 6 || rdc == 6) {
			pvx_uwol = 0;
			prx_uwol = ptx2;
			px_uwol = prx_uwol << 4;
		}
	}

	// ************
	// Killing tile
	// ************

	if (hitv && !pdead_uwol) {
		pvy_uwol = -PLAYER_V_REBOUND;
		sfx_play (SFX_SPIKE, SC_UWOL);
		kill_player_uwol ();
	}

	// *************
	// Out of bounds
	// *************
	/*
	if (pry_uwol == 240 - sprite_adjust) {
		pstate_uwol = PSTATE_NAKED;
		kill_player_uwol ();
	}
	*/

	ptx1 = (prx_uwol + 3) >> 4;
	pty1 = (pry_uwol + 7) >> 4;
	rda = (pty1 << 4) + ptx1;
	rdb = (scr_buff [rda] & 0x0f);

	switch (rdb) {
		case 1:
			// *******
			// Clothes
			// *******			
			if (game_mode != GM_2P_COOP || pstate_uwol == PSTATE_NAKED) {
				pstate_uwol = PSTATE_NORMAL;
				gpit = scr_buff [rda] >> 4;
				clxy [gpit] = 0;
				scr_buff [rda] = 0;
				sfx_play (SFX_CLOTHES, SC_UWOL);
				if (game_mode != GM_2P_VS) add_to_score_uwol (SCORE_CLOTHES);
			}

			break;
		case 3:
			// ****
			// Coin
			// ****
			gpit = scr_buff [rda] >> 4;
			scr_buff [rda] = 0;
			coins_act [gpit] = 0;
			coins_ct [gpit] = 24;
			if (game_mode == GM_2P_VS) {
				pcoins_uwol ++; p_t2 (0x0b, 1, pcoins_uwol);
			}
			add_to_coins ();
			coins_max --;
			sfx_play (SFX_COIN, SC_UWOL);
			if (!coins_max) sfx_play (SFX_LAST_COIN, SC_ENEMS);
			if (game_mode != GM_2P_VS) add_to_score_uwol (SCORE_COINS);
	
			break;
	}

	// ******
	// Render
	// ******

	if (pdead_uwol) {
		psprid = PCELL_DEAD;
	} else if (pflickering_uwol > 75) {
		psprid = PCELL_HIT;
	} else if (ppossee_uwol) {
		if (ABS (pvx_uwol) > PLAYER_VX_MIN) {
			psprid = PCELL_RUNNING0 + ((prx_uwol >> 4) & 3);
		} else {
			psprid = PCELL_STANDING;
		}
	} else if (pvy_uwol < 0) {
		psprid = PCELL_ASCEND;
	} else /* if (pvy_uwol > 0) */ {
		psprid = PCELL_DESCEND;
	}

	if (half_life || !pflickering_uwol) {
		oam_meta_spr (
			prx_uwol - CAM_POS, pry_uwol + sprite_adjust,
			OAM_UWOL,
			spr_player [PCELL_UWOL + pstate_uwol + pfacing_uwol + psprid]
		);
	} else {
		oam_meta_spr (0, 240, OAM_UWOL, spr_empty_pl);
	}

	if (game_mode == GM_1P) return;

	// ***************
	// *** MEEMAID ***
	// ***************

	i = pdead_meemaid ? 0 : pad1;
	if (pflickering_meemaid) pflickering_meemaid --;
	hitv = 0;

	// ********
	// Vertical
	// ********

	// Gravity
	if (pvy_meemaid < PLAYER_VY_FALLING_MAX) {
		pvy_meemaid += PLAYER_G;
	} else {
		pvy_meemaid = PLAYER_VY_FALLING_MAX;
	}

	// Move
	py_meemaid += pvy_meemaid;
	//if (py_meemaid < 0) py_meemaid = 0;
	if (py_meemaid > 3072) {
		py_meemaid = (240 - sprite_adjust) << 4;
		pstate_meemaid = PSTATE_NAKED;
		kill_player_meemaid ();
	}

	// Collide
	prx_meemaid = px_meemaid >> 4; pry_meemaid = py_meemaid >> 4;
	ptx1 = prx_meemaid >> 4;
	ptx2 = (prx_meemaid + 7) >> 4;
	
	// Ugly yet faster rewrite
	if (pvy_meemaid < 0) {
		pty1 = pry_meemaid >> 4;
		if ((ATTR (ptx1, pty1) & 0x0f) == 6 || (ATTR (ptx2, pty1) & 0x0f) == 6) {
			pvy_meemaid = 0;
			pry_meemaid = (pty1 + 1) << 4;
			py_meemaid = pry_meemaid << 4;
		}
	} else if (pvy_meemaid > 0) {
		pty1 = (pry_meemaid + 15) >> 4;
		if (((pry_meemaid - 1) & 15) < 8) {
			rdb = ATTR (ptx1, pty1) & 0x0f;
			rdc = ATTR (ptx2, pty1) & 0x0f;
			if (rdb >= 4 || rdc >= 4) {
				pvy_meemaid = 0;
				pry_meemaid = (pty1 - 1) << 4;
				py_meemaid = pry_meemaid << 4;
			} 
			hitv = (rdb == 2 || rdc == 2);
		}
	}
	pty1 = (pry_meemaid + 16) >> 4;
	ppossee_meemaid = (ATTR (ptx1, pty1) >= 4 || ATTR (ptx2, pty1) >= 4);

	// Jump
	if (i & PAD_A) {
		if (!pjb_meemaid) {
			pjb_meemaid = 1;
			if (!pj_meemaid) {
				if (ppossee_meemaid || hitv) {
					pj_meemaid = 1;
					pctj_meemaid = 0;
					sfx_play (SFX_JUMP, SC_UWOL);
					pvy_meemaid = -PLAYER_VY_JUMP_INITIAL;
				}
			}
		}
		if (pj_meemaid) {
			rda = (PLAYER_AY_JUMP - (pctj_meemaid >> 2) - (pctj_meemaid >> 3));
			pvy_meemaid -= (rda > 1 ? rda : 1);
			if (pvy_meemaid < -PLAYER_VY_JUMP_MAX) pvy_meemaid = -PLAYER_VY_JUMP_MAX;
			pctj_meemaid ++; if (pctj_meemaid == PLAYER_VY_JUMP_A_STEPS) pj_meemaid = 0;
		}
	} else {
		pj_meemaid = 0; pjb_meemaid = 0;
	}

	// **********
	// Horizontal
	// **********

	// Poll pad
	if (i & PAD_LEFT) {
		pfacing_meemaid = PFACING_LEFT;
		if (pvx_meemaid > -PLAYER_VX_MAX) pvx_meemaid -= PLAYER_AX;
	} else if (i & PAD_RIGHT) {
		pfacing_meemaid = PFACING_RIGHT;
		if (pvx_meemaid < PLAYER_VX_MAX) pvx_meemaid += PLAYER_AX;
	} else {
		if (pvx_meemaid > 0) {
			pvx_meemaid -= PLAYER_RX; if (pvx_meemaid < 0) pvx_meemaid = 0;
		} else if (pvx_meemaid < 0) {
			pvx_meemaid += PLAYER_RX; if (pvx_meemaid > 0) pvx_meemaid = 0;
		}
	}

	// Move
	px_meemaid += pvx_meemaid;
	
	// Wrap around
	if (px_meemaid < 0) px_meemaid += 4096;
	if (px_meemaid >= 4096) px_meemaid -= 4096;

	// Collision
	prx_meemaid = px_meemaid >> 4;
	pty1 = pry_meemaid >> 4;
	pty2 = (pry_meemaid + 15) >> 4;
	if (pvx_meemaid) {
		if (pvx_meemaid < 0) {
			ptx1 = prx_meemaid >> 4;
			ptx2 = (ptx1 + 1) << 4;
		} else {
			ptx1 = (prx_meemaid + 7) >> 4;
			ptx2 = ((ptx1 - 1) << 4) + 8; 
		}

		rdb = ATTR (ptx1, pty1);
		rdc = ATTR (ptx1, pty2);

		if (rdb == 6 || rdc == 6) {
			pvx_meemaid = 0;
			prx_meemaid = ptx2;
			px_meemaid = prx_meemaid << 4;
		}
	}

	// ************
	// Killing tile
	// ************

	if (hitv && !pdead_meemaid) {
		pvy_meemaid = -PLAYER_V_REBOUND;
		sfx_play (SFX_SPIKE, SC_UWOL);
		kill_player_meemaid ();
	}

	// *************
	// Out of bounds
	// *************
	/*
	if (pry_meemaid == 240 - sprite_adjust) {
		pstate_meemaid = PSTATE_NAKED;
		kill_player_meemaid ();
	}
	*/

	ptx1 = (prx_meemaid + 3) >> 4;
	pty1 = (pry_meemaid + 7) >> 4;
	rda = (pty1 << 4) + ptx1;
	rdb = (scr_buff [rda] & 0x0f);

	switch (rdb) {
		case 1:
			// *******
			// Clothes
			// *******			
			if (game_mode != GM_2P_COOP || pstate_meemaid == PSTATE_NAKED) {
				pstate_meemaid = PSTATE_NORMAL;
				gpit = scr_buff [rda] >> 4;
				clxy [gpit] = 0;
				scr_buff [rda] = 0;
				sfx_play (SFX_CLOTHES, SC_UWOL);
				if (game_mode != GM_2P_VS) add_to_score_meemaid (SCORE_CLOTHES);
			}

			break;
		case 3:
			// ****
			// Coin
			// ****
			gpit = scr_buff [rda] >> 4;
			scr_buff [rda] = 0;
			coins_act [gpit] = 0;
			coins_ct [gpit] = 24;
			if (game_mode == GM_2P_VS) {
				pcoins_meemaid ++; p_t2 (0x0b, 1, pcoins_meemaid);
			}
			add_to_coins ();
			coins_max --;
			sfx_play (SFX_COIN, SC_UWOL);
			if (!coins_max) sfx_play (SFX_LAST_COIN, SC_ENEMS);
			if (game_mode != GM_2P_VS) add_to_score_meemaid (SCORE_COINS);
	
			break;
	}

	// ******
	// Render
	// ******

	if (pdead_meemaid) {
		psprid = PCELL_DEAD;
	} else if (pflickering_meemaid > 75) {
		psprid = PCELL_HIT;
	} else if (ppossee_meemaid) {
		if (ABS (pvx_meemaid) > PLAYER_VX_MIN) {
			psprid = PCELL_RUNNING0 + ((prx_meemaid >> 4) & 3);
		} else {
			psprid = PCELL_STANDING;
		}
	} else if (pvy_meemaid < 0) {
		psprid = PCELL_ASCEND;
	} else /* if (pvy_meemaid > 0) */ {
		psprid = PCELL_DESCEND;
	}

	if (half_life || !pflickering_meemaid) {
		oam_meta_spr (
			prx_meemaid - CAM_POS, pry_meemaid + sprite_adjust,
			OAM_MEEMAID,
			spr_player [PCELL_MEEMAID + pstate_meemaid + pfacing_meemaid + psprid]
		);
	} else {
		oam_meta_spr (0, 240, OAM_MEEMAID, spr_empty_pl);
	}
}
