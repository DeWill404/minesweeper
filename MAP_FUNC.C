// ###### WORKING FUNCTIONS START ########
clock_t start, stop;    // Clock variable
// To clean a section of view
void clearView(int x1, int y1, int x2, int y2) {
	setviewport(x1, y1, x2, y2, 1); // To set viewport
	setCursor(x2, y2);              // Set cursor at max pos.
	clearviewport();                // clear view port
}
// To Reset viewport
void resetView() {
	setCursor(m.X, m.Y);        // Reset cursor pos. & set max. viewport
 	setviewport(0, 0, getmaxx(), getmaxy(), 0);
}
// To initialize minemap visibility to all hidden
void mapVarInitialize() {
	int i, j;
	for (i=0; i<9; i++)
		for (j=0; j<9; j++)
			mineView[i][j] = 'M';
}
// To reset mine map to default
void resetMineView() {
	int i, j;
	for(i=0; i<9; i++)
		for(j=0; j<9; j++)
			mineView[i][j] = 'M'; // Reset mine

	startText = "START";    // Reset Start
	flagText[0] = '1';      // Reset Flag
	flagText[1] = '0';	// Reset Flag
	timeText = "00:00";     // Reset Timer

	// Clear and Reset view
	clearView(90, 90, 430, 445);    // To clear mine block
	clearView(450, 390, 630, 410);  // To clear win/loss messawe
	clearView(150, 450, 400, 470);  // To clear "Press enter" message
	resetView();
}
// If you want to exit
int isExit()   {
	setCoordinate();  // Get current (x,y) & click
	// Condition for exit
	if (m.p == 'L')
		if ( (m.X>=500 && m.X<=565) && (m.Y>=415 && m.Y<=450) )
			return 1;

	return 0;
}
// When user press start button
void startClick() {
	setCoordinate();  // Get current (x,y) & click

	// Condition for start button
	if (m.p == 'L')
		if ( (m.X>=90 && m.X<=180) && (m.Y>=10 && m.Y<=50) ) {
			// Clearing viewport
			setviewport(91, 11, 179, 49, 1);
			clearviewport();

			// If you want to stop
			if (!strcmp(startText, "START")) {
				startText = "RESET";
				timeCounter = 1;
				start = clock();

			}
			// If you want to start
			else {
				timeCounter = -1;
				resetMineView();
			}

			// Resetting viewport
			setviewport(0, 0, getmaxx(), getmaxy(), 0);
		}
}
// Get timer value
void clockRead() {
	int time;   // variable to store time in sec.

	// If start button is pressed
	if (timeCounter == 1) {
		// Clear viewport
		clearView(90, 90, 220, 110);

		// Get current timer value
		stop = clock();
		time = (stop-start)/CLK_TCK + 0.5;

		// Display
		timeText[0] = time/600 + 48;
		timeText[1] = (time%600)/60 + 48;
		timeText[3] = ((time%600)%60)/10 + 48;
		timeText[4] = ((time%600)%60)%10 + 48;

		// Reset viewport
		resetView();
	}
}
