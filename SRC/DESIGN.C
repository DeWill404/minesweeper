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
	settextstyle(0, HORIZ_DIR, 0);         
	outtextxy(450, 20, "Place holder for");         // Learboard
	outtextxy(450, 40, "Leaderboard");              // Learboard
	outtextxy(450, 60, "Under development");        // Learboard
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

// ###### FILL STARTS ########
void fillAll() {
	setfillstyle(SOLID_FILL, WHITE);    // Title fill
	floodfill(0, 0, WHITE);

	setfillstyle(SOLID_FILL, YELLOW);   // Start button fill
	floodfill(91, 11, YELLOW);
}
// ###### FILL ENDS ########