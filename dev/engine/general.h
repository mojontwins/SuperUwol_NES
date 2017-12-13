// SuperUwol Engine 
// Copyleft 2015 by The Mojon Twins

signed int add_sign (signed int sign, signed int value) {
	return sign == 0 ? 0 : sign < 0 ? -value : value;
}

signed int saturate (signed int v, signed int max) {
	return v >= 0 ? (v > max ? max : v) : (v < -max ? -max : v);
}

unsigned char cl (unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {
	return x1 + 4 >= x2 && x1 <= x2 + 12 && y1 + 12 >= y2 && y1 <= y2 + 12;
}
