#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

// Fill the gameboard as it final state
void Init_GAMEBOARD( int ** GameBoard, int size ) ; 
 // Print the gameboard
void Print_GAMEBOARD( int ** GameBoard, int size ) ; 
//  if same return 1 , if it is not return 0
int Check_GAMEBOARD ( int ** GameBoard, int size ) ; 
// Perform the L option (moves empty cell to left) , Ecell means empty cell
void Option_L ( int ** GameBoard, int * x_Ecell, int * y_Ecell ) ;  
// Perform the R option (moves empty cell to right)
void Option_R ( int ** GameBoard, int * x_Ecell, int * y_Ecell ) ;
// Perform the U option (moves empty cell to up)
void Option_U ( int ** GameBoard, int * x_Ecell, int * y_Ecell ) ;
// Perform the R option (moves empty cell to down)
void Option_D ( int ** GameBoard, int * x_Ecell, int * y_Ecell ) ;
// Shuffle the gameboard
void Option_S ( int ** GameBoard, int size, int * x_Ecell, int * y_Ecell ) ;
// Turns negative number to positive number
int ABS ( int input ) ;
// Calculates distance of two state and return the apporiate one
int Find_diffState( int curState[][3], int finState[][3] ) ;
// Do an intelligent move
void Option_I ( int ** GameBoard, int size, int * x_Ecell, int * y_Ecell ) ;
// Finds empty cell cordinates
void Find_Ecell ( int ** GameBoard, int size, int * x_Ecell, int * y_Ecell ) ;
// Starts the game
void Play_NPuzzleGame() ;

int main( ){

	Play_NPuzzleGame () ;
	return 0 ;
} 
// Fill the gameboard as it final state
void Init_GAMEBOARD( int ** GameBoard, int size ){
	
	int row,column;

	for ( row = 0; row < size; row++ ){
		for ( column = 1; column <= size; column++ ){
			
			GameBoard[row][column-1] = (row*size) + column ;
		}
	}
	GameBoard[size-1][size-1] = 0 ;
}
// Print the gameboard 
void Print_GAMEBOARD( int ** GameBoard, int size ){
	
	int row,column;
	cout << endl ;

	for ( row = 0; row < size; row++ ){
		for ( column = 0; column < size; column++ ){
			if( GameBoard[row][column] != 0 )
				cout << "\t"<<GameBoard[row][column] ;
			else
				cout << "\t" ;
		}
		cout<<endl;
	}
}
//  if same return 1 , if it is not return 0
int Check_GAMEBOARD ( int ** GameBoard, int size ){
	int row, column, same = 1, finalBoard[size][size] ;

	for ( row = 0; row < size; row++ ){ // build a final board
		for ( column = 1; column <= size; column++ ){
			
			finalBoard[row][column-1] = (row*size) + column ;
		}
	}
	finalBoard[size-1][size-1] = 0 ;

	for ( row = 0; row < size; row++ ){ // compare final board and current board
		for ( column = 0; column < size; column++ ){
			
			if( finalBoard[ row ][ column ] != GameBoard[ row ][ column ] ){ // if doesnt match end the loop
				same = 0 ;
				row = size ;
				column = size ;
			}
		}
	}
	return same ; // if same return 1 , if it is not return 0
}
// Perform the L option (moves empty cell to left) , Ecell means empty cell
void Option_L ( int ** GameBoard, int * x_Ecell, int * y_Ecell ){
	
	int temp_x, temp_y ;
	
	temp_x = (* x_Ecell) ;	// swap empty cell and left cell 
	temp_y = (* y_Ecell) ;
	(* x_Ecell) -- ;

	GameBoard[ temp_y ][ temp_x ] = GameBoard[ *y_Ecell ][ *x_Ecell ] ;
	GameBoard[ *y_Ecell ][ *x_Ecell ] = 0 ;
}
// Perform the R option (moves empty cell to right)
void Option_R ( int ** GameBoard, int * x_Ecell, int * y_Ecell ){
	
	int temp_x, temp_y ;
	
	temp_x = (* x_Ecell) ;	 // swap empty cell and right cell
	temp_y = (* y_Ecell) ;
	(* x_Ecell) ++ ;
	
	GameBoard[ temp_y ][ temp_x ] = GameBoard[ *y_Ecell ][ *x_Ecell ] ;
	GameBoard[ *y_Ecell ][ *x_Ecell ] = 0 ;
}
// Perform the U option (moves empty cell to up)
void Option_U ( int ** GameBoard, int * x_Ecell, int * y_Ecell ){
	
	int temp_x, temp_y ;
	
	temp_x = (* x_Ecell) ;	  // swap empty cell and up cell
	temp_y = (* y_Ecell) ;
	(* y_Ecell) -- ;
	
	GameBoard[ temp_y ][ temp_x ] = GameBoard[ *y_Ecell ][ *x_Ecell ] ;
	GameBoard[ *y_Ecell ][ *x_Ecell ] = 0 ;
}
// Perform the R option (moves empty cell to down)
void Option_D ( int ** GameBoard, int * x_Ecell, int * y_Ecell ){
	
	int temp_x, temp_y ;
	
	temp_x = (* x_Ecell) ;	  // swap empty cell and down cell
	temp_y = (* y_Ecell) ;
	(* y_Ecell) ++ ;

	GameBoard[ temp_y ][ temp_x ] = GameBoard[ *y_Ecell ][ *x_Ecell ] ;
	GameBoard[ *y_Ecell ][ *x_Ecell ] = 0 ;
}
// Shuffle the gameboard
void Option_S ( int ** GameBoard, int size, int * x_Ecell, int * y_Ecell ){
	//dif means random cordinate , old dif is necessary to avoid none-shuflle puzzle
	int dif_x = 0, dif_y = 0, old_dif_x, old_dif_y, i = 0, same = 0 ; 
	do{
		while( i < ( size * size * size  ) ){ // do it to shuffle size^3 times
		
			do{	// do it untill a cordinate came out which is not same with old one and it is convinient 
		
				dif_x = ( rand() % 3 ) - 1 ;
				dif_y = ( rand() % 3 ) - 1 ;
			
			}while( !( ( ( dif_y != 0 && dif_x == 0 ) || ( dif_y == 0 && dif_x != 0 ) ) && !( dif_x == old_dif_x && dif_y == old_dif_y ) ) ) ;
			
			// it checks cordinates to be in borders
			if( ( (*y_Ecell) + dif_y ) < size && ( (*x_Ecell) + dif_x ) < size && 0 <= ( (*y_Ecell) + dif_y ) && 0 <= ( (*x_Ecell) + dif_x ) ){
				
				GameBoard[ *y_Ecell ][ *x_Ecell ] = GameBoard[ (*y_Ecell) + dif_y ][ *(x_Ecell) + dif_x ] ;
				GameBoard[ *y_Ecell + dif_y ][ *x_Ecell + dif_x ] = 0 ;
				
				*x_Ecell += dif_x ;
				*y_Ecell += dif_y ;
			}
			old_dif_x = dif_x ; //save old cordinates to avoid unnecessary moves
			old_dif_y = dif_y ;
			i++ ;
			
			dif_x = 0 ;
			dif_y = 0 ;
			
		}
		same = Check_GAMEBOARD( GameBoard , size ) ;	
	}while( same == 1 ) ; // if it is same with final board after the shuffle , it shuffles again 
		
}
// Turns negative number to positive number
int ABS ( int input ){
	if( input < 0 )
		return ( input * -1) ;
}
// Calculates distance of two state and return the apporiate one
int Find_diffState( int curState[][3], int finState[][3] ){
	int distanceState[4][2], absX, absY ; // distance state holds x,y for each way

	for (int i = 0; i < 4 ; ++i){ // compare two state , find distance between them

		absX = ABS( curState[i][1] - finState[i][1] ) ;
		absY = ABS( curState[i][2] - finState[i][2] ) ;
		distanceState[i][0] = absX + absY ;
	}
	//compare states for each movemont way
	absX = ABS( curState[0][1] - finState[0][1] ) ; // UP
	absY = ABS( curState[0][2] + 1 - finState[0][2] ) ;
	distanceState[0][1] = absX + absY ;

	absX = ABS( curState[1][1] - finState[1][1] ) ; // DOWN
	absY = ABS( curState[1][2] - 1 - finState[1][2] ) ;
	distanceState[1][1] = absX + absY ;

	absX = ABS( curState[2][1] + 1 - finState[2][1] ) ; // LEFT
	absY = ABS( curState[2][2] - finState[2][2] ) ;
	distanceState[2][1] = absX + absY ;

	absX = ABS( curState[3][1] - 1 - finState[2][1] ) ;	// RIGHT
	absY = ABS( curState[3][2] - finState[2][2] ) ;
	distanceState[3][1] = absX + absY ;

	if( distanceState[0][0] > distanceState[0][1] && curState[0][0] != 0 ){	// checks the state that  is it better to move or not
	
		return 0 ;
	}
	else if( distanceState[1][0] > distanceState[1][1] && curState[1][0] != 0 ){

		return 1 ;
	}
	else if( distanceState[2][0] > distanceState[2][1] && curState[1][0] != 0 ){

		return 2 ;
	}
	else if( distanceState[3][0] > distanceState[3][1] && curState[1][0] != 0 ){
		
		return 3 ;
	}
	else	// if nothing is better  than moves random
		return -1 ;
}
// Do an intelligent move
void Option_I ( int ** GameBoard, int size, int * x_Ecell, int * y_Ecell ){
	int currentState[4][3], finalState[4][3], move ; // currentState holds each possible way cordinates in order up,down,left,right
													// finalState holds cordinates that he numbers in each way should be
	for (int i = 0; i < 4; ++i){
		currentState[ i ][0] = 0 ;
	}

	if( 0 <= ( *y_Ecell - 1 ) ){ // up
		currentState[0][1] = *x_Ecell ;
		currentState[0][2] = *y_Ecell - 1 ;
		currentState[0][0] = GameBoard[ currentState[0][2] ][ currentState[0][1] ] ;
	}
	if( ( *y_Ecell + 1 ) < size ){ // down
		currentState[1][1] = *x_Ecell ;
		currentState[1][2] = *y_Ecell + 1 ;
		currentState[1][0] = GameBoard[ currentState[1][2] ][ currentState[1][1] ] ;
	}
	if( 0 <= ( *x_Ecell - 1 ) ){	//left
		currentState[2][1] = *x_Ecell - 1 ;
		currentState[2][2] = *y_Ecell ;
		currentState[2][0] = GameBoard[ currentState[2][2] ][ currentState[2][1] ] ;
	}
	if( ( *x_Ecell + 1 ) < size ){	// right
		currentState[3][1] = *x_Ecell + 1 ;
		currentState[3][2] = *y_Ecell ;
		currentState[3][0] = GameBoard[ currentState[3][2] ][ currentState[3][1] ] ;
	}

	for (int i = 0; i < 4; ++i){ // calculates each number where should  be
		if( currentState[i][0] != 0 ){
			finalState[ i ][0] = currentState[ i ][0] ;
			finalState[ i ][1] = ( currentState[ i ][0] - 1 ) % size  ;
			finalState[ i ][2] = ( currentState[ i ][0] - 1 ) / size ;
		}
		
	}

	move = Find_diffState( currentState, finalState ) ; // get the appropiate movement

	if( move == -1 ) // if no option is better , moves random
		move = 0 ;

	GameBoard[ *y_Ecell ][ *x_Ecell ] = currentState[ move ][0] ; // swap the correct move
	*x_Ecell = currentState[move][1] ;
	*y_Ecell = currentState[move][2] ;
	GameBoard[ *y_Ecell ][ *x_Ecell ] = 0 ;
	
	if( move == 0 )
		cout << "\nIntelligent move chooses U" ;
	else if( move == 1 )
		cout << "\nIntelligent move chooses D" ;
	else if( move == 2 )
		cout << "\nIntelligent move chooses L" ;
	else if( move == 3 )
		cout << "\nIntelligent move chooses R" ;
}
// Finds empty cell cordinates
void Find_Ecell ( int ** GameBoard, int size, int * x_Ecell, int * y_Ecell ){
	int row, column ;

	for( row = 0; row < size; row++ )
		for( column = 0; column < size; column++ )

			if( GameBoard[row][column] == 0 ){ //search empty cell , if it finds it get out the loop
				*x_Ecell = column ;
				*y_Ecell = row ;

				row = size ;
				column = size ;
			}				
}
// Starts the game
void Play_NPuzzleGame(){

	int size, i, score = 0, finish = 0 ;
	int **GAMEBOARD = NULL;
	int x_Ecell, y_Ecell ;
	char option ;

	srand( time(NULL) );

	cout << "\nPlease enter the problem size: " ;
	cin >> size ;

	GAMEBOARD = ( int** ) malloc( sizeof( int * ) * size ) ; // build a gameboard for the game
	for ( i = 0; i < size; ++i){
		GAMEBOARD[i] = ( int* ) malloc( sizeof( int ) * size ) ; ;
	}

	Init_GAMEBOARD( GAMEBOARD, size ) ;
	Find_Ecell( GAMEBOARD, size, &x_Ecell, &y_Ecell ) ;
	Option_S( GAMEBOARD, size, &x_Ecell, &y_Ecell ) ;
	cout << "\nYour initial random board is \n" ;

	do{

		Print_GAMEBOARD( GAMEBOARD, size ) ;
		cout << "\nYour move: " ;
		cin >> option ;

		switch( option ){

			case 'L' :
				if( 0 <= ( x_Ecell - 1 ) ){
					Option_L( GAMEBOARD, &x_Ecell, &y_Ecell ) ;
					score ++ ;
				}
				else
					cout << "\nYou can not go out of the puzzle.\n" ;
				break ;

			case 'R' :
				if( ( x_Ecell + 1 ) < size ){
					Option_R( GAMEBOARD, &x_Ecell, &y_Ecell ) ;
					score ++ ;
				}
				else
					cout << "\nYou can not go out of the puzzle.\n" ;
				break ;

			case 'U' :
				if( 0 <= ( y_Ecell -1 ) ){
					Option_U( GAMEBOARD, &x_Ecell, &y_Ecell ) ;
					score ++ ;
				}
				else
					cout << "\nYou can not go out of the puzzle.\n" ;
				break ;

			case 'D' :
				if( ( y_Ecell + 1 ) < size ){
					Option_D( GAMEBOARD, &x_Ecell, &y_Ecell ) ;
					score ++ ;
				}
				else
					cout << "\nYou can not go out of the puzzle.\n" ;
				break ;
			case 'I' :
				Option_I( GAMEBOARD, size, &x_Ecell, &y_Ecell );
				score ++ ;
				break ;
			case 'S' :
				Option_S( GAMEBOARD, size, &x_Ecell, &y_Ecell ) ;
				break ;
			case 'Q' : 
				cout << "\nShut down the program ...\n" ;
				break ;
			default :
				cout << "\nYou entered an invalid input !! PLEASE TRY AGAIN  !!\n" ;
		}
		finish = Check_GAMEBOARD( GAMEBOARD, size ) ;

		if( finish == 1 ){
			cout << "\nPromlem solved!" ;
			cout <<	"\nTotal number of moves: " << score << endl ;
		}
	}while ( option != 'Q' && finish == 0 ) ;
	
}