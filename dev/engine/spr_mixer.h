// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

// The game engine adds metasprites to these lists
// 'Copy to OAM' sends them to the OAM in a different
// order each frame.

// 4 enemies, 2 items, MAX_COINS coins.
#define MS_MAX		6 + MAX_COINS
#define MS_PRIME	7
#define MS_SKIP		72

unsigned char *msl_meta [MS_MAX];
unsigned char msl_x [MS_MAX];
unsigned char msl_y [MS_MAX];
unsigned char msl_i, msl_oami;

// Call this each frame, before adding metasprites

// Version 1 too slow?
/*
void msl_open (void) {
	gpit = MS_MAX; while (gpit --) msl_meta [gpit] = 0;
	msl_i = frame_counter & 7;
}

void msl_add (unsigned char x, unsigned char y, const unsigned char *ms) {
	msl_x [msl_i] = x;
	msl_y [msl_i] = y;
	msl_meta [msl_i] = (unsigned char *) ms;
	msl_i += MS_PRIME; 						// Magic
	if (msl_i >= MS_MAX) msl_i -= MS_MAX; 	// Modulo
}

// Call this each frame, before ppu_wait_nmi:
void msl_close (void) {
	msl_i = MS_SKIP;
	gpit = MS_MAX; while (gpit --) {
		if (msl_meta [gpit])
			msl_i = oam_meta_spr (msl_x [gpit] - CAM_POS, msl_y [gpit], msl_i, msl_meta [gpit]);
	}
	oam_hide_rest (msl_i);
}
*/

// Version 2

void msl_init (void) {
	gpit = MS_MAX; while (gpit --) msl_meta [gpit] = (unsigned char *) spr_empty;
}

void msl_open (void) {
	msl_i = 0;
}

void msl_add (unsigned char x, unsigned char y, const unsigned char *ms) {
	msl_x [msl_i] = x;
	msl_y [msl_i] = y;
	msl_meta [msl_i] = (unsigned char *) ms;
	msl_i ++;
}

void msl_add_empty (void) {
	msl_y [msl_i] = 240;
	msl_meta [msl_i ++] = (unsigned char *) spr_empty;
}

void msl_close (void) {
	gpjt = frame_counter & 7;
	msl_oami = MS_SKIP;

	for (gpit = 0; gpit < MS_MAX; gpit ++) {
		msl_oami = oam_meta_spr (msl_x [gpjt] - CAM_POS, msl_y [gpjt], msl_oami, msl_meta [gpjt]);
		gpjt += MS_PRIME; if (gpjt >= MS_MAX) gpjt -= MS_MAX;
	}
	//oam_hide_rest (msl_oami);
}
