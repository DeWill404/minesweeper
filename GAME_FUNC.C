// Function for flag
char flag(int counter) {
	// Setting up viewport
	clearView(380, 90, 430, 110);

	// To decreament flag
	if (counter == -1)  {
		// If flag is not ZERO
		if (strcmp(flagText, "00") != 0) {
			flagText[0] = '0';      // Set first to zero
			// Second digit if flag is 10			
			if (flagText[1] == '0')
				flagText[1] = '9';
			// Second digit if flag is less  then 10
			else
				flagText[1] -= 1;
			
			// Reset viewport
			resetView();
			return 'F';
		}
	}

	// To Increment flag
	if (counter == 1) {
		// if flag=9 then set it to 10
		if (flagText[1] == '9')  {
			flagText[0] = '1';
			flagText[1] = '0';
		}
		// if flag<9 then flag+1
		else {
			flagText[1] += 1;
		}
	}

	// Reset viewport
	resetView();
	return 'M';
}
// Main game control
void mainGame() {
	int x, y; // (x, y) coordinate
	
	// if game is started
	if (!strcmp(startText,"RESET"))   {
		setCoordinate();   // Get current coordinate
		// When left or right button is clicked
		if (m.p != '-') {
			// When clicked inside game board
			if ((m.X>=95 && m.X<=410) && (m.Y>=130 && m.Y<=445)) {
				x = (m.X - 95)/35;   // get X coordinate
				y = (m.Y - 130)/35;  // get Y coordinate

				// Clear perticular mine
				clearView(96+x*35, 131+y*35, 129+x*35, 164+y*35);

				// If mine is hidden
				if (mineView[x][y] == 'M')
					// If left-click(show mine) else right-click(set flag)
					mineView[x][y] = (m.p == 'L') ? mapStruct[y][x] : flag(-1);

				// If mine is visible or flag is set
				else if ((mineView[x][y]) == 'F' && (m.p == 'L'))
					// Remove flag if present or do nothing
					mineView[x][y] = flag(1); 

				// Reset view
				resetView();
			}
		}
	}
}
// Check whether user won or not
int win() {
	int i, j;  // Iteration variabl
	int c = 0; // correctflag counter

	// Iterating each mine
	for (i=0; i<9; i++) {
		for (j=0; j<9; j++)  {
			
			// if flag is set and mine is under it
			if ((mineView[j][i] == 'F') && (mapStruct[i][j] == '*'))
				c++;
			// if mine is visible, then you lose
			if (mineView[j][i] == '*')
				return -1;
		}
	}

	// if all 10 flag are correct, the you won
	if (c == 10)
		return 1;
	
	// Do nothing
	return 0;
}
