// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

void scroll_update (void) {
	if (game_mode == GM_1P) {
		cam_pos = prx [0] - 120;
	} else {
		if (prx [0] < prx [1]) {
			cam_pos = prx [0] + ((prx [1] - prx [0]) >> 1);
		} else {
			cam_pos = prx [1] + ((prx [0] - prx [1]) >> 1);
		}
	}

	scroll (cam_pos, 472);
}
