// 2D array to store random created map
char mapStruct[9][9];
// To check if position is in map
int isvalid(int i, int j){
	if ((i>=0 && i<9) && (j>=0 && j<9))
		return 1;
	return 0;
}
// To place mine on map
void mine() {
	int count = 10;  // Count of mine placed
	int i, j;        // Iteration Variable
	// Setting no. of mine per level
	// Generating random location of mine
	while(count > 0) {
		i = rand()%9;	  //  Random
		j = rand()%9;	  //  x and y
		// Placing mine
		if (mapStruct[i][j] == ' ') {
			mapStruct[i][j] = '*';
			count--;
		}
	}
}
// To place clue on map
void clue() {
	int i, j;    // Iteration variable
	char count;  // Clue counter
	// Placing Clue on map
	for (i=0; i<9; i++) {
		for (j=0; j<9; j++) {
			// Reseting counter
			count = '0';
			// Incrementing counter
			if (mapStruct[i][j] != '*') {
				if (isvalid(i,j+1) && mapStruct[i][j+1]=='*')     count++;
				if (isvalid(i,j-1) && mapStruct[i][j-1]=='*')     count++;
				if (isvalid(i+1,j) && mapStruct[i+1][j]=='*')     count++;
				if (isvalid(i+1,j+1) && mapStruct[i+1][j+1]=='*') count++;
				if (isvalid(i+1,j-1) && mapStruct[i+1][j-1]=='*') count++;
				if (isvalid(i-1,j) && mapStruct[i-1][j]=='*')     count++;
				if (isvalid(i-1,j+1) && mapStruct[i-1][j+1]=='*') count++;
				if (isvalid(i-1,j-1) && mapStruct[i-1][j-1]=='*') count++;
				if (count > '0')	          mapStruct[i][j] = count;
			}
		}
	}
}
// To make map using space( ), mine(*), clue(1,2,...)
void makeMineStruct() {
	int i, j;    // Iteration variable
	// setting seed to random functin
	srand(time(0));
	// Making an empty map
	for (i=0; i<9; i++)
		for (j=0; j<9; j++)
			mapStruct[i][j]=' ';
	mine();  // Placing Mines
	clue();  // Placing Clues
}
