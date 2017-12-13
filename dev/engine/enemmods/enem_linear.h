if (!paused) {
	if (!en_status [gpit] || half_life) {
		en_x [gpit] += en_mx [gpit];
		en_y [gpit] += en_my [gpit];

		if (en_x [gpit] == en_x1 [gpit] || en_x [gpit] == en_x2 [gpit]) en_mx [gpit] = -en_mx [gpit];
		if (en_y [gpit] == en_y1 [gpit] || en_y [gpit] == en_y2 [gpit]) en_my [gpit] = -en_my [gpit];											
	}

	if (en_mx [gpit] != 0) {
		en_fr = ((en_x [gpit]) >> 4) & 1;
	} else {
		en_fr = ((en_y [gpit]) >> 4) & 1;
	}
}

msl_add (
	en_x [gpit], en_y [gpit] + sprite_adjust, 
	spr_enems [en_s [gpit] + en_fr]
	);
	