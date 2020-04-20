char *startText = "START";          // Placeholder of start button
int timeCounter = -1;               // Counter to start timer
char *timeText = "00:00";           // Placeholder of timer
char mineView[9][9];                // Mine visibility Variable
char *flagText = "10";	            // Counter variable for flag
// Making design
void mineMap() {

	int box=35;    // Size of single mine box
	int i, j;      // Iteration variable
	int x, y;      // (x, y) coorinate of mine box
	char temp[2] = {'1', '\0'};	// temp string

	// Title Section
	setcolor(BLACK);
	settextstyle(0, VERT_DIR, 4);
	outtextxy(50, 50, "MineSweeper");  // Title
	Line(70, 0, 70, getmaxy(), WHITE); // Border

	// Mine Section
	setcolor(BLUE);
	settextstyle(0, HORIZ_DIR, 2);
	Rect(90, 10, 180, 50, YELLOW);     // Start
	outtextxy(97, 23, startText);      // Buttom
	setcolor(YELLOW);
	settextstyle(4, HORIZ_DIR, 5);
	outtextxy(230, 10, "EASY");        // Level Indicator
	settextstyle(0, HORIZ_DIR, 3);
	outtextxy(380, 90, flagText);      // Flag-Counter
	outtextxy(90, 90, timeText);       // Timer

	///////////////////////////////////// Ground
	for (i=0; i<9; i++) {
		for (j=0; j<9; j++) {
			x = 95 + i*box;
			y = 130 + j*box;
			Rect(x, y, x+box, y+box, YELLOW);
			temp[0] = mineView[i][j];
			outtextxy(x+8, y+8, temp);
		}
	}

	// Detail & exit Section
	Line(440, 0, 440, getmaxy(), RED)   ;   // Border
	setcolor(WHITE);                       
	settextstyle(10, HORIZ_DIR, 1);         
	outtextxy(450, 1, "CG PROJECT");             // Detail
	settextstyle(0, HORIZ_DIR, 0);               //    :
	outtextxy(450, 60, "Siddique Irshad Ahmed"); //    :
	outtextxy(500, 75, "(3118057)");             //    :
	outtextxy(465, 95, "Malik Sultan Ahmed");    //    :
	outtextxy(500, 110, "(3118060)");            //    :
	outtextxy(470, 130, "Syed Mahdi Rizvi");     //    :
	outtextxy(500, 145, "(3118061)");            //    :
	outtextxy(450, 180, "Guided by,");           //    :
	outtextxy(500, 195, "Er. Lutful Islam");     // Detail
	setcolor(YELLOW);
	outtextxy(445, 240, "Instruction :");           // Instruction
	outtextxy(450, 255, "You have find out ");      //     :
	outtextxy(450, 265, "position of mine(*) by");  //     :
	outtextxy(450, 275, "by right-click(F) only");  //     :
	outtextxy(450, 285, "on mine Mine(M).");        //     :
	outtextxy(450, 300, "I assume that you know "); //     :
	outtextxy(450, 310, "this game well.");         //     :
	outtextxy(450, 325, "So, use clue, which is");  //     :
	outtextxy(450, 335, "visible on left-click");   //     :
	outtextxy(450, 345, "on Mine(M).");             //     :
	outtextxy(450, 360, "So,");                     //     :
	outtextxy(450, 370, "  Best of Luck.");         // Instruction
	settextstyle(1, HORIZ_DIR, 2);
	setcolor(RED);
	Rect(440, 230, getmaxx(), getmaxy(), RED); // Seprator
	Rect(500, 415, 565, 450, RED);             // Quit
	outtextxy(510, 420, "QUIT");               // Quit
}
// ###### MAP DESIGN ENDS ########


// ###### FILL STARTS ########
void fillAll() {
	setfillstyle(SOLID_FILL, WHITE);    // Title fill
	floodfill(0, 0, WHITE);

	setfillstyle(SOLID_FILL, YELLOW);   // Start button fill
	floodfill(91, 11, YELLOW);
}
// ###### FILL ENDS ########


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
