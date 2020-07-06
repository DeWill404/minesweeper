// Making Register union
union REGS in, out;
// Struct to return mouse cordinate and click
struct Mouse {
	char p; // To store click
	int X;  // To store x position
	int Y;  // To store y position
} m;
// To check wether mouse is available or not
int status() {
	// Setting reg to 0, to get status
	in.x.ax = 0;
	int86(0x33, &in, &out);
	return out.x.ax;
}
// To make cursor visible
void cursorVisible() {
	// Setting reg to 1, to print cursor
	in.x.ax = 1;
	int86(0x33, &in, &out);
}
// To set cursor position
void setCursor(int x, int y) {
	// Setting reg to 4, to start seting mode
	in.x.ax = 4;
	in.x.cx = x;	// Passing x coordinate
	in.x.dx = y;    // Passing y coordinate
	int86(0x33, &in, &out);
}
// To return coordinate & click of mouse
void setCoordinate() {
	// Setting reg to 3, to get click & coordinate
	in.x.ax = 3;
	int86(0x33, &in, &out);

	// If clicked
	if (out.x.bx != 0)  {
		if (out.x.bx == 1)      // Left click
			m.p = 'L';
		else if (out.x.bx == 2) // Right click
			m.p = 'R';
	}
	else {	// If no click
		m.p = '-';
	}

	m.X = out.x.cx;	// X coordinate
	m.Y = out.x.dx; // Y coordinate
}
