// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

#include "assets/metasprites_pl.h"
#include "assets/metasprites_ex.h"
#include "assets/metasprites_en.h"
#include "assets/metasprites_fa.h"
#include "assets/metasprites_it.h"
#include "assets/metasprite_logo.h"

const unsigned char spr_empty [] = {
	0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 
	0x80
};

const unsigned char spr_empty_pl [] = {
	0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 
	0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 
	0x80
};

const unsigned char * const spr_player [] = {
	// 0 UWOL
	// 0 Dressed
	// 0 Right
	spr_pl_00_a, spr_pl_01_a, spr_pl_00_a, spr_pl_02_a, 
	spr_pl_03_a, spr_pl_04_a, spr_pl_14_a, 0,
	// 8 Left
	spr_pl_00_b, spr_pl_01_b, spr_pl_00_b, spr_pl_02_b, 
	spr_pl_03_b, spr_pl_04_b, spr_pl_14_b, 0, 
	// 16 Naked
	// 16 Right
	spr_pl_05_a, spr_pl_06_a, spr_pl_05_a, spr_pl_07_a, 
	spr_pl_08_a, spr_pl_09_a, spr_pl_14_a, spr_ex_00_a,
	// 24 Left
	spr_pl_05_b, spr_pl_06_b, spr_pl_05_b, spr_pl_07_b, 
	spr_pl_08_b, spr_pl_09_b, spr_pl_14_b, spr_ex_00_b, 
	
	// 32 MEEMAID
	// 32 Dressed
	// 32 Right
	spr_pl_0A_a, spr_pl_0B_a, spr_pl_0A_a, spr_pl_0C_a, 
	spr_pl_0D_a, spr_pl_0E_a, spr_pl_15_a, 0,
	// 40 Left
	spr_pl_0A_b, spr_pl_0B_b, spr_pl_0A_b, spr_pl_0C_b, 
	spr_pl_0D_b, spr_pl_0E_b, spr_pl_15_b, 0,
	// 48 Naked
	// 48 Right
	spr_pl_0F_a, spr_pl_10_a, spr_pl_0F_a, spr_pl_11_a, 
	spr_pl_12_a, spr_pl_13_a, spr_pl_15_a, spr_ex_01_a,
	// 56 Left
	spr_pl_0F_b, spr_pl_10_b, spr_pl_0F_b, spr_pl_11_b, 
	spr_pl_12_b, spr_pl_13_b, spr_pl_15_b, spr_ex_01_b
};
// Each sequence: 
// W1 (STANDING), W2, W3, W4
// UP DOWN

const unsigned char * const spr_enems [] = {
	spr_en_00, spr_en_01, spr_en_02, spr_en_03, 
	spr_en_04, spr_en_05, spr_en_06, spr_en_07 
};

const unsigned char * const spr_coins [] = {
	spr_fa_04_a, spr_fa_05_a, spr_fa_06_a, spr_fa_07_a,
	spr_fa_06_b, spr_fa_05_b
};

const unsigned char * const spr_items [] = {
	spr_it_00, spr_it_01, spr_it_02, spr_it_03
};

const unsigned char * const spr_fanty [] = {
	spr_fa_00_a, spr_fa_01_a, spr_fa_00_b, spr_fa_01_b
};
