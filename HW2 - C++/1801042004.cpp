#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

void Init_GAMEBOARD( int ** GameBoard, int row, int column ) ;
void Print_GAMEBOARD( int ** GameBoard, int row, int column ) ;
int Check_GAMEBOARD ( int ** GameBoard, int row, int column ) ;
void Option_L ( int ** GameBoard, int * x_Ecell, int * y_Ecell ) ;
void Option_R ( int ** GameBoard, int * x_Ecell, int * y_Ecell ) ;
void Option_U ( int ** GameBoard, int * x_Ecell, int * y_Ecell ) ;
void Option_D ( int ** GameBoard, int * x_Ecell, int * y_Ecell ) ;
void Option_S ( int ** GameBoard, int row, int column, int * x_Ecell, int * y_Ecell ) ;
void Option_I ( int ** GameBoard, int row, int column, int * x_Ecell, int * y_Ecell ) ;
void FindCoordinatesGivenValue( int ** GameBoard, int row, int column, int value, int * x_Value, int * y_Value ) ;
int ABS ( int input ) ;
void Find_Ecell ( int ** GameBoard, int row, int column, int * x_Ecell, int * y_Ecell ) ;
int Find_diffState( int curState[][3], int finState[][3] ) ;
int Check_GAMEBOARDHW2( int ** puzzle, const int& row, const int& column ) ;
void Play_NPuzzleGameHW1() ;

void SetBordersOfPuzlle ( string file_name, int& row, int& column ) ;
void Option_Y ( string file_name, int *** puzzle, int& row, int& column );
void Option_T ( int score ) ;
void Option_E ( int** curPuzzle, int row, int column ) ;
void Option_V( int ** GameBoard, int row, int column, int * x_Ecell, int * y_Ecell, int score ) ;
void Print_GAMEBOARDHW2( int** curPuzzle, int row, int column ) ;
void Play_NPuzzleGameHW2( string file_name ){
    int row = 0, column = 0, score = 0, finish = 0 ;
    int x_Ecell, y_Ecell ;
    char option ;
    string textfile ;
    int ** GAMEBOARD  ;

    srand( time(NULL) );

    Option_Y( file_name, &GAMEBOARD, row, column ) ;   
    
    Option_S( GAMEBOARD, row, column, &x_Ecell, &y_Ecell ) ;
    Find_Ecell( GAMEBOARD, row, column, &x_Ecell, &y_Ecell ) ;
    cout << "\nYour initial random board is \n" ;

    do{
        cout<< endl ;
        Print_GAMEBOARDHW2( GAMEBOARD, row, column ) ;
        cout << "\nYour move: " ;
        cin >> option ;

        switch( option ){

            case 'L' :
                if( 0 <= ( x_Ecell - 1 ) && GAMEBOARD[ y_Ecell ][ x_Ecell - 1  ] != 0 ){
                    Option_L( GAMEBOARD, &x_Ecell, &y_Ecell ) ;
                    score ++ ;
                }
                else
                    cout << "\nYou can not go out of the puzzle.\n" ;
                break ;

            case 'R' :
                if( ( x_Ecell + 1 ) < column && GAMEBOARD[ y_Ecell ][ x_Ecell + 1  ] != 0 ){
                    Option_R( GAMEBOARD, &x_Ecell, &y_Ecell ) ;
                    score ++ ;
                }
                else
                    cout << "\nYou can not go out of the puzzle.\n" ;
                break ;

            case 'U' :
                if( 0 <= ( y_Ecell -1 ) && GAMEBOARD[ y_Ecell - 1 ][ x_Ecell ] != 0 ){
                    Option_U( GAMEBOARD, &x_Ecell, &y_Ecell ) ;
                    score ++ ;
                }
                else
                    cout << "\nYou can not go out of the puzzle.\n" ;
                break ;

            case 'D' :
                if( ( y_Ecell + 1 ) < row && GAMEBOARD[ y_Ecell + 1 ][ x_Ecell ] != 0 ){
                    Option_D( GAMEBOARD, &x_Ecell, &y_Ecell ) ;
                    score ++ ;
                }
                else
                    cout << "\nYou can not go out of the puzzle.\n" ;
                break ;
            case 'I' :
                Option_I( GAMEBOARD, row, column, &x_Ecell, &y_Ecell );
                score ++ ;
                break ;
            case 'S' :
                Option_S( GAMEBOARD, row, column, &x_Ecell, &y_Ecell ) ;
                break ;
            case 'E' :
                Option_E( GAMEBOARD, row, column ) ;
                break ;
            case 'Y' :
                cout << "Please give the file name : " ;
                cin >> textfile ;
                Option_Y( textfile, &GAMEBOARD, row, column) ;
                break ;
            case 'V' :
                Option_V( GAMEBOARD, row, column, &x_Ecell, &y_Ecell, score ) ;
                break ;
            case 'T' :
                Option_T( score ) ;
                break ;
            case 'Q' : 
                cout << "\nShut down the program ...\n" ;
                break ;
            default :
                cout << "\nYou entered an invalid input !! PLEASE TRY AGAIN  !!\n" ;
        }
        finish = Check_GAMEBOARDHW2( GAMEBOARD, row, column ) ;

        if( finish == 1 ){
            cout << "\nPromlem solved!" ;
            Option_T( score ) ;
        }
    }while ( option != 'Q' && finish == 0 ) ;
    
}




int main( int argc, char *argv[] ){

   if (argc == 1)
   {
       Play_NPuzzleGameHW1();
   }
   else if( argc == 2)
        Play_NPuzzleGameHW2( argv[1]) ;
        	
    
	return 0 ;
} 

void SetBordersOfPuzlle ( string file_name, int& row, int& column ){
    ifstream fs ;
    fs.open( file_name ) ;
    string data_line ;
    string data_value ;
    int cursor = 0, testvalue= 0 ;

    if ( fs.is_open() ){
        while ( getline( fs, data_line ) ){
            
            while(  cursor < data_line.size() ){

                data_value += data_line[ cursor ] ;
                
                
                if ( data_line[ cursor ] == ' ' || cursor == data_line.size() ){
                    
                    column ++ ;
                }  
                cursor ++ ;          
            }

            cursor = 0;
            row++;
            cout << endl;         
        }
        column = (column / row) + 1  ;
        fs.close();

    }
    else{
        cout << "File is unable to be opened";
    }
}
void Option_Y ( string file_name, int *** puzzle, int& row, int& column ){
    ifstream fs ;
    fs.open( file_name ) ;
    string data_value ;
    int cursor = 0, testvalue= 0 ;

    row = column = 0 ;
    SetBordersOfPuzlle ( file_name, row, column ) ;
    *puzzle = ( int** ) malloc( sizeof( int * ) * row) ;
    for ( int i = 0; i < row; ++i){
        (*puzzle)[i] = ( int* ) malloc( sizeof( int ) * column ) ; ;
    }

    if ( fs.is_open() ){

        for (int i = 0; i < row; ++i){
            for (int j = 0; j < column; ++j){

                
                fs >> data_value ;
                if( data_value == "bb"){
                    testvalue = -1 ;      
                    (*puzzle)[ i ][ j ] = testvalue ;
                }
                else{ 
                    testvalue = stoi( data_value );
                    (*puzzle)[ i ][ j ] = testvalue ;
                }
                
            }
        }
        fs.close();
    }
    else{
        cout << "File is unable to be opened";
    }

}
void Option_T ( int score ){
    cout << "\nTotal number of moves : " << score ;
}
void Option_E ( int** curPuzzle, int row, int column ){
    string file_name ;
    ofstream fs ;
    cout << "\nPlease give the file name which you wanted to store puzzle : " ;
    cin >> file_name ;
    fs.open( file_name ) ;

    for (int i = 0; i < row; ++i){
        for (int j = 0; j < column; ++j){
            
            if( 0 <= curPuzzle[ i ][ j ] && curPuzzle[ i ][ j ] < 10){
                fs << 0 ;
                fs << curPuzzle[ i ][ j ] ;
            }
            else if( -1 == curPuzzle[ i ][ j ] )
                fs << "bb" ;
            else
                fs << curPuzzle[ i ][ j ] ;
            if( j != column-1 )
                fs << " " ;
        }
        if(  i != row-1  )
            fs << "\n" ;
    }
}
void Option_V( int ** GameBoard, int row, int column, int * x_Ecell, int * y_Ecell, int  score ){
    int same = 0 ;

    while( same == 0 ){
        same = Check_GAMEBOARDHW2( GameBoard, row, column );
        if( same != 1){
            Option_I( GameBoard, row, column , x_Ecell, y_Ecell ) ;
            Print_GAMEBOARDHW2( GameBoard, row, column ) ;
            score++ ;
        }
    }
    Option_T(score) ;
}
void Print_GAMEBOARDHW2( int** curPuzzle, int row, int column ){

    for (int i = 0; i < row; ++i){
        for (int j = 0; j < column; ++j){
            
            if( 0 <= curPuzzle[ i ][ j ] && curPuzzle[ i ][ j ] < 10){
                cout <<"\t" ;
                cout << 0 ;
                cout << curPuzzle[ i ][ j ] ;
            }
            else if( -1 == curPuzzle[ i ][ j ] ){
                cout <<"\t" ;
                cout << "bb" ;
            }
                
            else{
                cout <<"\t" ;
                cout << curPuzzle[ i ][ j ] ;

            }
                
        }
        cout << endl ;
    }

}

// Fill the gameboard as it final state
void Init_GAMEBOARD( int ** GameBoard, int row, int column ){

    for ( int i = 0; i < row; i++ ){
        for ( int j = 1; j <= column; j++ ){
            
            GameBoard[i][j-1] = (i*row) + j ;
        }
    }
    GameBoard[row-1][column-1] = -1 ;
}
// Print the gameboard 
void Print_GAMEBOARD( int ** GameBoard, int row, int column ){
    cout << endl ;

    for ( int i = 0; i < row; i++ ){
        for ( int j = 0; j < column; j++ ){
            if( GameBoard[i][j] != -1 )
                cout << "\t"<<GameBoard[i][j] ;
            else
                cout << "\t" ;
        }
        cout<<endl;
    }
}
//  if same return 1 , if it is not return 0
int Check_GAMEBOARD ( int ** GameBoard, int row, int column ){
    int same = 1, finalBoard[row][column] ;

    for ( int i = 0; i < row; i++ ){ // build a final board
        for ( int j = 1; j <= column; j++ ){
            
            finalBoard[i][j-1] = (i*row) + j ;
        }
    }
    finalBoard[row-1][column-1] = -1 ;

    for ( int i = 0; i < row; i++ ){ // compare final board and current board
        for ( int j = 0; j < column; j++ ){
            
            if( finalBoard[ i ][ j ] != GameBoard[ i ][ j ] ){ // if doesnt match end the loop
                same = 0 ;
                i = row ;
                j = column ;
            }
        }
    }
    return same ; // if same return 1 , if it is not return 0
}
// Perform the L option (moves empty cell to left) , Ecell means empty cell
void Option_L ( int ** GameBoard, int * x_Ecell, int * y_Ecell ){
    
    int temp_x, temp_y ;
    
    temp_x = (* x_Ecell) ;  // swap empty cell and left cell 
    temp_y = (* y_Ecell) ;
    (* x_Ecell) -- ;

    GameBoard[ temp_y ][ temp_x ] = GameBoard[ *y_Ecell ][ *x_Ecell ] ;
    GameBoard[ *y_Ecell ][ *x_Ecell ] = -1 ;
}
// Perform the R option (moves empty cell to right)
void Option_R ( int ** GameBoard, int * x_Ecell, int * y_Ecell ){
    
    int temp_x, temp_y ;
    
    temp_x = (* x_Ecell) ;   // swap empty cell and right cell
    temp_y = (* y_Ecell) ;
    (* x_Ecell) ++ ;
    
    GameBoard[ temp_y ][ temp_x ] = GameBoard[ *y_Ecell ][ *x_Ecell ] ;
    GameBoard[ *y_Ecell ][ *x_Ecell ] = -1 ;
}
// Perform the U option (moves empty cell to up)
void Option_U ( int ** GameBoard, int * x_Ecell, int * y_Ecell ){
    
    int temp_x, temp_y ;
    
    temp_x = (* x_Ecell) ;    // swap empty cell and up cell
    temp_y = (* y_Ecell) ;
    (* y_Ecell) -- ;
    
    GameBoard[ temp_y ][ temp_x ] = GameBoard[ *y_Ecell ][ *x_Ecell ] ;
    GameBoard[ *y_Ecell ][ *x_Ecell ] = -1 ;
}
// Perform the R option (moves empty cell to down)
void Option_D ( int ** GameBoard, int * x_Ecell, int * y_Ecell ){
    
    int temp_x, temp_y ;
    
    temp_x = (* x_Ecell) ;    // swap empty cell and down cell
    temp_y = (* y_Ecell) ;
    (* y_Ecell) ++ ;

    GameBoard[ temp_y ][ temp_x ] = GameBoard[ *y_Ecell ][ *x_Ecell ] ;
    GameBoard[ *y_Ecell ][ *x_Ecell ] = -1 ;
}
// Shuffle the gameboard
void Option_S ( int ** GameBoard, int row, int column, int * x_Ecell, int * y_Ecell ){
    //dif means random cordinate , old dif is necessary to avoid none-shuflle puzzle
    int dif_x = 0, dif_y = 0, old_dif_x, old_dif_y, i = 0, same = 0 ; 
    do{
        while( i < ( row* column * row * column  ) ){ // do it to shuffle size^3 times
        
            do{ // do it untill a cordinate came out which is not same with old one and it is convinient 
        
                dif_x = ( rand() % 3 ) - 1 ;
                dif_y = ( rand() % 3 ) - 1 ;
            
            }while( !( ( ( dif_y != 0 && dif_x == 0 ) || ( dif_y == 0 && dif_x != 0 ) ) && !( dif_x == old_dif_x && dif_y == old_dif_y ) ) ) ;
            
            // it checks cordinates to be in borders
            if( ( ( (*y_Ecell) + dif_y ) < row && ( (*x_Ecell) + dif_x ) < column && 0 <= ( (*y_Ecell) + dif_y ) && 0 <= ( (*x_Ecell) + dif_x ) ) && GameBoard[ (*y_Ecell) + dif_y ][ (*x_Ecell) + dif_x ] != 0 ){
                
                GameBoard[ *y_Ecell ][ *x_Ecell ] = GameBoard[ (*y_Ecell) + dif_y ][ *(x_Ecell) + dif_x ] ;
                GameBoard[ *y_Ecell + dif_y ][ *x_Ecell + dif_x ] = -1 ;
                
                *x_Ecell += dif_x ;
                *y_Ecell += dif_y ;
            }
            old_dif_x = dif_x ; //save old cordinates to avoid unnecessary moves
            old_dif_y = dif_y ;
            i++ ;
            
            dif_x = 0 ;
            dif_y = 0 ;
            
        }
        same = Check_GAMEBOARDHW2( GameBoard , row, column ) ; 
    }while( same == 1 ) ; // if it is same with final board after the shuffle , it shuffles again 
        
}
void FindCoordinatesGivenValue( int ** GameBoard, int row, int column, int value, int * x_Value, int * y_Value ){
    for( int i = 0; i < row; i++ )
        for( int j = 0; j < column; j++ )

            if( GameBoard[i][j] == value ){ //search value , if it finds it get out the loop
                *x_Value = j ;
                *y_Value = i ;

                i = row ;
                j = column ;
            }
}
// Turns negative number to positive number
int ABS ( int input ){
    if( input < 0 )
        return ( input * -1) ;
}
// Finds empty cell cordinates
void Find_Ecell ( int ** GameBoard, int row, int column, int * x_Ecell, int * y_Ecell ){

    for( int i = 0; i < row; i++ )
        for( int j = 0; j < column; j++ )

            if( GameBoard[i][j] == -1 ){ //search empty cell , if it finds it get out the loop
                *x_Ecell = j ;
                *y_Ecell = i ;
                i = row ;
                j = column ;
            }               
}
int Check_GAMEBOARDHW2( int ** puzzle, const int& row, const int& column ){
    int k = 1, ** finalBoard, same = 1 ;

    finalBoard = ( int** ) malloc( sizeof( int * ) * row) ;
    for ( int i = 0; i < row; ++i){
        finalBoard[i] = ( int* ) malloc( sizeof( int ) * column ) ; ;
    }
    
    for ( int i = row-1 ; 0 <= i ; i-- ){ // place the bb cell
        for ( int j = 0; j < column; j++ ){
            
            if( puzzle[i][j] != 0 ){
                finalBoard[i][j] = -1 ;
                j = column ;
                i = -1 ;

            }
        }
    }
    

    for ( int i = 0; i < row; i++ ){ // build a final board
        for ( int j = 0; j < column; j++ ){
            
            if( puzzle[i][j] != 0 &&  finalBoard[i][j] != -1 ){
                finalBoard[i][j] = k ;
                k++  ;
            }
            else if( puzzle[i][j] == 0 )
                finalBoard[i][j] = 0 ;
        }
    }

    for ( int i = 0; i < row; i++ ){ // compare final board and current board
        for ( int j = 0; j < column; j++ ){
            
            if( finalBoard[ i ][ j ] != puzzle[ i ][ j ] ){ // if doesnt match end the loop
                same = 0 ;
                i = row ;
                j = column ;
            }
        }
    }
    return same ;
}
// Do an intelligent move

void Option_I ( int ** GameBoard, int row, int column, int * x_Ecell, int * y_Ecell ){
    int currentState[4][3], finalState[4][3], move ; // currentState holds each possible way cordinates in order up,down,left,right
                                                    // finalState holds cordinates that he numbers in each way should be
    for (int i = 0; i < 4; ++i){
        currentState[ i ][0] = 0 ;
    }

    if( 0 <= ( *y_Ecell - 1 ) && GameBoard[ ( *y_Ecell - 1 ) ][ *x_Ecell ] != 0 ){ // up
        currentState[0][1] = *x_Ecell ;
        currentState[0][2] = *y_Ecell - 1 ;
        currentState[0][0] = GameBoard[ currentState[0][2] ][ currentState[0][1] ] ;
    }
    if( ( *y_Ecell + 1 ) < row && GameBoard[ ( *y_Ecell + 1 ) ][ *x_Ecell ] != 0){ // down
        currentState[1][1] = *x_Ecell ;
        currentState[1][2] = *y_Ecell + 1 ;
        currentState[1][0] = GameBoard[ currentState[1][2] ][ currentState[1][1] ] ;
    }
    if( 0 <= ( *x_Ecell - 1 ) && GameBoard[ *y_Ecell ][ ( *x_Ecell - 1 ) ] != 0 ){  //left
        currentState[2][1] = *x_Ecell - 1 ;
        currentState[2][2] = *y_Ecell ;
        currentState[2][0] = GameBoard[ currentState[2][2] ][ currentState[2][1] ] ;
    }
    if( ( *x_Ecell + 1 ) < column && GameBoard[ *y_Ecell ][ ( *x_Ecell + 1 ) ] != 0 ){  // right
        currentState[3][1] = *x_Ecell + 1 ;
        currentState[3][2] = *y_Ecell ;
        currentState[3][0] = GameBoard[ currentState[3][2] ][ currentState[3][1] ] ;
    }

    for (int i = 0; i < 4; ++i){ // calculates each number where should  be
        if( currentState[i][0] != 0 ){
            finalState[ i ][0] = currentState[ i ][0] ;
            FindCoordinatesGivenValue( GameBoard, row, column, currentState[ i ][0], &finalState[ i ][1], &finalState[ i ][2] ) ;
        }
        
    }

    move = Find_diffState( currentState, finalState ) ; // get the appropiate movement

    if( move == -1 ) // if no option is better , moves random
        move = 0 ;

    GameBoard[ *y_Ecell ][ *x_Ecell ] = currentState[ move ][0] ; // swap the correct move
    *x_Ecell = currentState[move][1] ;
    *y_Ecell = currentState[move][2] ;
    GameBoard[ *y_Ecell ][ *x_Ecell ] = -1 ;
    
    if( move == 0 )
        cout << "\nIntelligent move chooses U\n" ;
    else if( move == 1 )
        cout << "\nIntelligent move chooses D\n" ;
    else if( move == 2 )
        cout << "\nIntelligent move chooses L\n" ;
    else if( move == 3 )
        cout << "\nIntelligent move chooses R\n" ;
}
// Calculates distance of two state and return the apporiate one
int Find_diffState( int curState[][3], int finState[][3] ){
    int distanceState[4][3], absX, absY ; // distance state holds x,y for each way
    int min, index = -1, result ;
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

    absX = ABS( curState[3][1] - 1 - finState[2][1] ) ; // RIGHT
    absY = ABS( curState[3][2] - finState[2][2] ) ;
    distanceState[3][1] = absX + absY ;

    for (int i = 0; i < 4; ++i){
        
        distanceState[i][2] = distanceState[i][0] - distanceState[i][1] ;
    }

    min = 1 ;
    for (int i = 0; i < 4; ++i){
        if( 0 < distanceState[i][2] && distanceState[i][2] <= min ){
            min = distanceState[i][1] ;
            index = i ;
        }
    }
    if( index == -1 ){
        index = rand() % 4 ;
    }

    return index ;
  
}
// Starts the game
void Play_NPuzzleGameHW1(){

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

    Init_GAMEBOARD( GAMEBOARD, size, size ) ;
    Find_Ecell( GAMEBOARD, size, size, &x_Ecell, &y_Ecell ) ;
    Option_S( GAMEBOARD, size, size, &x_Ecell, &y_Ecell ) ;
    cout << "\nYour initial random board is \n" ;

    do{

        Print_GAMEBOARD( GAMEBOARD, size, size ) ;
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
                Option_I( GAMEBOARD, size, size, &x_Ecell, &y_Ecell );
                score ++ ;
                break ;
            case 'S' :
                Option_S( GAMEBOARD, size, size, &x_Ecell, &y_Ecell ) ;
                break ;
            case 'Q' : 
                cout << "\nShut down the program ...\n" ;
                break ;
            default :
                cout << "\nYou entered an invalid input !! PLEASE TRY AGAIN  !!\n" ;
        }
        finish = Check_GAMEBOARD( GAMEBOARD, size, size ) ;

        if( finish == 1 ){
            cout << "\nPromlem solved!" ;
            cout << "\nTotal number of moves: " << score << endl ;
        }
    }while ( option != 'Q' && finish == 0 ) ;
    
}