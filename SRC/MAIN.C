#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
/*
	Make sure path of files are correct,
		before using it...
*/
#include "\TURBOC3\BIN\SRC\DDA.C"
#include "\TURBOC3\BIN\SRC\MOUSE.C"
#include "\TURBOC3\BIN\SRC\MAKE_S~1.C"
#include "\TURBOC3\BIN\SRC\DESIGN.C"
#include "\TURBOC3\BIN\SRC\MAP_FUNC.C"
#include "\TURBOC3\BIN\SRC\GAME_F~1.C"

/*
	if case of running on laptop you are using
	trackpad, which have left-click in same position 
	of track,
	so i have made a pointer (Cur) which represent current
	click near exit button.
	So please click sometimes, for it become '-'
	the start game...
*/

void main() {
	int gd = DETECT, gm;
	char Cur[2] = {' ', '\0'};
	initgraph(&gd, &gm, "C:TURBOC3\\BGI");

	// Check if mouse available
	if (status() != 0) {
		makeMineStruct();
		mapVarInitialize();

		// Utill exit
		while (!isExit()) {
		//while(!kbhit()) {
			cursorVisible(); // Get cursor
			mineMap();       // Print striucture
			fillAll();       // Filling Color
			startClick();    // start or stop
			clockRead();     // Get timer
			if (win() == 1) {
				setcolor(WHITE);
				settextstyle(0, HORIZ_DIR, 2);
				outtextxy(460, 390, "YOU WON :)");
				outtextxy(150, 455, "Press enter...");
				getch();
				break;
			}
			else if (win() == -1) {
				setcolor(WHITE);
				settextstyle(0, HORIZ_DIR, 2);
				outtextxy(450, 390, "YOU LOST :(");
				outtextxy(150, 455, "Press enter...");
				getch();
				setviewport(91, 11, 179, 49, 1);
				clearviewport();
				timeCounter = -1;
				resetMineView();
				makeMineStruct();
				setviewport(0, 0, getmaxx(), getmaxy(), 0);
			}
			mainGame();      // Game Function
			Cur[0] = m.p;
			outtextxy(600, 420, Cur);
		}
	}
	else
		printf("Sorry, Your mouse is not available... :(");

	// Go away message
	setcolor(WHITE);
	settextstyle(0, HORIZ_DIR, 2);
	outtextxy(150, 455, "Press enter...");
	setcolor(YELLOW);
	settextstyle(0, HORIZ_DIR, 0);
	outtextxy(450, 455, "Hope you enjoyed it,");
	outtextxy(450, 465, "  Please leave comment.");
	getch();
	// Go away message

	closegraph();
}
