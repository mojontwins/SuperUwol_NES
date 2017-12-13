// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

// Code adapted from MK1 NES (& simplified)

// Loads enems from n_pant
void enems_load (void) {
	// Read 3 enemies from enems ROM pool and populate my arrays properly.

	// UWOL custom: If screen has been visited, all enemies are off.
	if (visited [n_pant]) { gpit = 3; while (gpit --) en_t [gpit] = 0; }
	
	// Each screen holds 3 * 4 bytes of enemies, that's 12 bytes per screen.
	// 12 = 4 + 8 so you know the drill...
	gp_gen = (unsigned char *) (enems + (n_pant << 2) + (n_pant << 3));

	// Notice that enemies are writen backwards. Take in account in the future

	gpit = 3; while (gpit --) {
		// First get T, then do whatever I need
		en_t [gpit] = *gp_gen ++;

		// General...

		// XY1
		rda = *gp_gen ++;
		en_x [gpit] = en_x1 [gpit] = rda & 0xf0;
		en_y [gpit] = en_y1 [gpit] = rda << 4;

		// XY2
		rda = *gp_gen ++;
		en_x2 [gpit] = rda & 0xf0;
		en_y2 [gpit] = rda << 4;

		// P, here used for speed
		rda = *gp_gen ++;
		en_mx [gpit] = add_sign (en_x2 [gpit] - en_x1 [gpit], rda);
		en_my [gpit] = add_sign (en_y2 [gpit] - en_y1 [gpit], rda);

		switch (en_t [gpit]) {
			case 1:
			case 2:
			case 3:
			case 4:
				// Linear enems.			

				// HL conversion
				en_s [gpit] = (en_t [gpit] - 1) << 1;
				if (rda == 1) {
					en_status [gpit] = 1; 
				} else {
					en_status [gpit] = 0;
					en_mx [gpit] >>= 1;
					en_my [gpit] >>= 1;
				}
				
				break;	
			case 8:
				// Saws

				// emerging sense
				rda = ABS (en_mx [gpit]); if (!rda) rda = ABS (en_my [gpit]);
				rda --;

				// Sense
				rdb = en_mx [gpit] ? 
					SGNC (en_x2 [gpit], en_x1 [gpit], SAW_V_DISPL) :
					SGNC (en_y2 [gpit], en_y1 [gpit], SAW_V_DISPL);

				// Store:
				en_my [gpit] = rda; // EMERGING SENSE
				en_mx [gpit] = rdb; // MOVING SENSE

				en_alive [gpit] = 1;
				en_ct [gpit] = SAW_EMERGING_STEPS;
				break;
		}
	}
	en_t [3] = 0;
}

void fanty_init (void) {
	en_x [3] = 120; en_y [3] = 88;
	enf_x = 120 << 4; enf_y = 88 << 4;
	enf_vx = 0; enf_vy = 0;
}

void enems_move (void) {
	// Enems 0-2 normal
	// Enems 3 fanty
	for (gpit = 0; gpit < 4; gpit ++) {	
		if (en_t [gpit]) {
			if (gpit < 3) {
				#include "engine/enemmods/enem_linear.h"
			} else if (fanty_on) {
				#include "engine/enemmods/enem_fanty.h"
			}

			// Collide <-> player
			if (!pflickering_uwol && !pdead_uwol && cl (prx_uwol, pry_uwol, en_x [gpit], en_y [gpit])) {
				pvx_uwol = add_sign (en_mx [gpit], PLAYER_V_REBOUND); en_mx [gpit] = add_sign (en_x [gpit] - prx_uwol, ABS (en_mx [gpit]));
				pvy_uwol = add_sign (en_my [gpit], PLAYER_V_REBOUND); if (!en_mx [gpit]) en_my [gpit] = add_sign (en_y [gpit] - pry_uwol, ABS (en_my [gpit]));
				sfx_play (SFX_PLAYER_HIT, SC_UWOL);
				kill_player_uwol ();
			}

			if (game_mode != GM_1P) {
				if (!pflickering_meemaid && !pdead_meemaid && cl (prx_meemaid, pry_meemaid, en_x [gpit], en_y [gpit])) {
					pvx_meemaid = add_sign (en_mx [gpit], PLAYER_V_REBOUND); en_mx [gpit] = add_sign (en_x [gpit] - prx_meemaid, ABS (en_mx [gpit]));
					pvy_meemaid = add_sign (en_my [gpit], PLAYER_V_REBOUND); if (!en_mx [gpit]) en_my [gpit] = add_sign (en_y [gpit] - pry_meemaid, ABS (en_my [gpit]));
					sfx_play (SFX_PLAYER_HIT, SC_MEEMAID);
					kill_player_meemaid ();
				}
			}
		} else {
			// Send empty sprite, out of bounds to msl.
			msl_add_empty ();
		}
	}	
}
