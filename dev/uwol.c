// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

//#define DEBUG

#define CAM_POS 			252
#define UPDATE_LIST_SIZE	30
#define MSB(x)				((x)>>8)
#define LSB(x)				((x)&0xff)
#define SPRITE_ADJUST_PAL	23
#define SPRITE_ADJUST_NTSC	31
#define TOP_ADJUST			2

// OAM mapping...
/*
	OAM #	byte #	#	what
	0 		0 		4 	P1 (Uwol)
	4 		16		4 	P2 (Meemaid)
	8 		32		2 	Item
	10 		40 		2 	Enem 0
	12 		48		2 	Enem 2
	14 		56 		2 	Enem 3
	16 		64		2 	Fanty
	18 		72	 	2 	Coins... (up to 15)
*/
#define OAM_BASE_P1		0
#define OAM_BASE_P2		16
#define OAM_BASE_ITEM	32
#define OAM_BASE_ENEMS	40
#define OAM_BASE_COINS	72

// Shiru's

#include "neslib.h"

// Some needed stuff...

#include "definitions.h"
#include "config.h"

// Main const includes

#include "assets/palettes.h"
#include "assets/palette_arrays.h"
#include "assets/metatileset.h"
#include "assets/metaspriteset.h"
#include "assets/endingset.h"
#include "assets/titleset.h"
#include "assets/uwolmap.h"
#include "assets/uwolenems.h"
#include "assets/precalcs.h"

const unsigned char bitmasks [] = { 0xfc, 0xf3, 0xcf, 0x3f };

// Some variables

#pragma bss-name (push,"ZEROPAGE")
#pragma data-name(push,"ZEROPAGE")

#include "globals_zp.h"

#pragma bss-name (push,"BSS")
#pragma data-name(push,"BSS")

#include "globals_bss.h"

// Functions

#include "engine/general.h"
#include "engine/printer.h"
#include "engine/hud.h"
#include "engine/spr_mixer.h"
#include "engine/clothes.h"
#include "engine/player.h"
#include "engine/enengine.h"
#include "engine/coins.h"
#include "engine/exits.h"
#include "engine/game_loop.h"
//#include "engine/scroller.h"

// Main

void main (void) {
	ntsc = !!ppu_system ();
	ticks = ntsc ? 60 : 50;
	sprite_adjust = ntsc ? SPRITE_ADJUST_NTSC : SPRITE_ADJUST_PAL;

	oam_size (1);
	pal_bright (0);
	
	intro_screen ();

	pal_spr (pal_ss_0);

	while (1) {
		title_do ();

		n_pant = 0; n_floor = 0; n_column = 0;
		gpit = 55; while (gpit --) visited [gpit] = 0;
		plife_uwol = 5; plife_meemaid = (game_mode == GM_1P ? 0 : 5);
		pwins_uwol = 0; pwins_meemaid = 0;
		total_coins = 0; seq_level = 0;

		while (1) {

			if (game_mode == GM_2P_VS) {
				vs_screen_round ();
			} else {
				pyramid_screen_do ();
			}

			game_loop ();
			
			if (game_mode == GM_2P_VS) {
				vs_screen_do ();
				if (!gen_result) break;
				n_pant ++; if (n_pant == 55) n_pant = 0;
			} else {
				if (gen_result == GS_GAME_OVER) {
					if (!plife_uwol && !plife_meemaid) {
						game_over ();
						break;
					}
				} else {
					visited [n_pant] = 1;
					n_floor ++;
					if (n_floor < 10) {
						if (gen_result == GS_WIN_LEFT) {
							n_pant = n_pant + n_floor;
						} else {
							n_pant = n_pant + n_floor + 1;
							n_column ++;
						}
					} else {
						ending_do ();
						if (!which_ending) {
							n_pant = 0; n_floor = 0; n_column = 0;
						} else break;
					}
				}
			}
		}
	}
}
