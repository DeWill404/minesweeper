//Function for finding absolute value
int abso (int n) {
    return ( (n>0) ? n : ( n * (-1)));
}
//DDA Function for line generation
void Line(int X0, int Y0, int X1, int Y1, int color) {
    int i;
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    // calculate steps required for generating pixels
    int steps = abso(dx) > abso(dy) ? abso(dx) : abso(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (i = 0; i <= steps; i++)
    {
	putpixel (X,Y,color);  // put pixel at (X,Y)
	X += Xinc;           // increment in x at each step
	Y += Yinc;           // increment in y at each step
    }
}
// Calling DDA Line function to draw Rectangle
void Rect(int xmin, int ymin, int xmax, int ymax, int color) {
	Line(xmin, ymin, xmax, ymin, color);
	Line(xmax, ymin, xmax, ymax, color);
	Line(xmax, ymax, xmin, ymax, color);
	Line(xmin, ymax, xmin, ymin, color);
}
