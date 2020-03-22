#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include "NPuzzle.h"
using namespace std ;

//*****************************************************************************************

// NPuzzle constructors
NPuzzle :: NPuzzle (){

}
void NPuzzle :: print () const {

    GameBoard[0].print() ;
}

// begin of none same functions
void NPuzzle :: printReport () const{
    cout << "\n Total number of moves : " << GameBoard[0].numberOfMoves() << "\n\n ";
    if ( GameBoard[0].isSolved() )
        cout << "\n You finished the game. \n" ;
}

void NPuzzle :: readFromFile ( const string& file_name ){

    GameBoard.resize(0) ;
    TempBoard.readFromFile( file_name ) ;
    GameBoard.push_back( TempBoard ) ;
}

void NPuzzle :: writeToFile ( const string& file_name )const {

   GameBoard[0].writeToFile( file_name ) ;
}

// shuffle board by n times 
void NPuzzle :: shuffle ( int N_times ) {

    int i = 0 ;
    bool same ; 

    do{
        while( i < N_times ){ //  shuffle N times
        
            moveRandom() ;      
            i++ ;       
        }
        same = TempBoard.isSolved() ; 
    }while( same == true ) ; // if it is same with final solution after the shuffle , it shuffles again 
    
    TempBoard.resetCountDoneMove() ;
    TempBoard.setLastMove( 'S' ) ;

    GameBoard.resize(0) ;
    GameBoard.push_back( TempBoard ) ;

}

void NPuzzle :: reset(){

    GameBoard.resize(0) ;
    TempBoard.reset() ;     
}

bool NPuzzle :: setSize ( int size ){

    return TempBoard.setSize( size ) ;
}

bool NPuzzle :: setSize ( int new_row, int new_column ){

    return TempBoard.setSize( new_row, new_column ) ;
}

void NPuzzle :: setSize ( const string& file_name ){

    TempBoard.setSize( file_name ) ;
}

// makes a valid random move
char NPuzzle :: moveRandom () {
    int choice ;
    char option ;

    do{
        choice = rand() % 4 ;
        if( choice == 0 )
            option = 'U' ;
        else if( choice == 1 )
            option = 'D' ;
        else if( choice == 2 )
            option = 'L' ;
        else if( choice == 3 )
            option = 'R' ;

    }while( !TempBoard.move( option ) ) ;

    GameBoard.resize(0) ;
    GameBoard.push_back( TempBoard ) ;

    return option ;
}

bool NPuzzle :: move ( char option ){
    bool valid ;
   
    valid = TempBoard.move( option ) ;

    GameBoard.resize(0) ;
    GameBoard.push_back( TempBoard ) ;

    return valid ;
}
// solve the puzzle with new algorithm
void NPuzzle :: solvePuzzle(){
   
    int index = 0, search = 0, temp_NumberOfMoves ;
    bool same = false ;
    vector < char > lastmoves ;


    temp_NumberOfMoves = GameBoard[0].numberOfMoves() ;

    // until found the solution
    while( ! GameBoard[ GameBoard.size() - 1 ].isSolved() && index < GameBoard.size() ){

        TempBoard = GameBoard[ index ] ;

        same = false ;

        // if it is not solved and it is not my inverse move and move is valid
        if( ! GameBoard[ GameBoard.size() - 1 ].isSolved() && TempBoard.lastMove() != 'D' && TempBoard.move( 'U' ) ){ // UP

            // check my vector of Board 
            for (int j = 0; j < GameBoard.size() ; ++j ){

                if( GameBoard[ GameBoard.size() - j - 1 ] == TempBoard )
                    same = true ;
            }
            //if it is not in it  push_back to my vector of Board
            if( same != true ){

                GameBoard.push_back( TempBoard ) ;
                TempBoard = GameBoard[ index ] ;
                
            }
        }

        same = false ;

        // if it is not solved and it is not my inverse move and move is valid
        if( ! GameBoard[ GameBoard.size() - 1 ].isSolved() && TempBoard.lastMove() != 'U' && TempBoard.move( 'D' ) ){ // DOWN
            // check my vector of Board 
            for (int j = 0; j < GameBoard.size() ; ++j ){
            
                if( GameBoard[ GameBoard.size() - j - 1 ] == TempBoard )
                    same = true ;
            }
            //if it is not in it  push_back to my vector of Board
            if( same != true ){

                GameBoard.push_back( TempBoard ) ;
                TempBoard = GameBoard[ index ] ; 
            }
        }

        same = false ;

        // if it is not solved and it is not my inverse move and move is valid
        if( ! GameBoard[ GameBoard.size() - 1 ].isSolved() && TempBoard.lastMove() != 'R' && TempBoard.move( 'L' ) ){ // LEFT
            // check my vector of Board 
            for (int j = 0; j < GameBoard.size() ; ++j ){
            
                if( GameBoard[ GameBoard.size() - j - 1 ] == TempBoard )
                    same = true ;
            }
            //if it is not in it  push_back to my vector of Board
            if( same != true ){

                GameBoard.push_back( TempBoard ) ;
                TempBoard = GameBoard[ index ] ; 
            }
        }

        same = false ;

        // if it is not solved and it is not my inverse move and move is valid
        if( ! GameBoard[ GameBoard.size() - 1 ].isSolved() && TempBoard.lastMove() != 'L' && TempBoard.move( 'R' ) ){ // RIGHT
            // check my vector of Board 
            for (int j = 0; j < GameBoard.size() ; ++j ){
            
                if( GameBoard[ GameBoard.size() - j - 1 ] == TempBoard )
                    same = true ;
            }
            //if it is not in it  push_back to my vector of Board
            if( same != true ){

                GameBoard.push_back( TempBoard ) ;
                TempBoard = GameBoard[ index ] ; 
            }
        }  

        index ++ ;    // go for next element of my vector of Board    
    }

    TempBoard = GameBoard[ GameBoard.size() - 1 ] ;

    search = GameBoard.size() - 2 ;
    // until go to the beginning
    while( search >= 0){

        lastmoves.push_back( TempBoard.lastMove() ) ; // push last move
        inverseMove( TempBoard.lastMove() ) ;        // inverse it 

        same = false ;
        // find moves before the solution , search it
        while( !same ){

            if( GameBoard[ search ] == TempBoard ){
                same = true ;
                TempBoard = GameBoard[ search ] ;
            } 

            search -- ;
        }
    }


    cout << "\n\n The GameBoard \n\n" ;
    GameBoard[0].print() ;
    for ( int j = 0 ; j < lastmoves.size();  ++j ){ // prints all steps while going to solution
        
        cout << "\n\nIntelligent move choose : " << lastmoves[ lastmoves.size() - j - 1 ] << "\n\n" ;

        GameBoard[0].move( lastmoves[ lastmoves.size() - j - 1 ] ) ; 
        GameBoard[0].print() ;

        temp_NumberOfMoves ++ ;
          
    }

    cout << "\n\n" ;
    cout << "\n Total number of moves : " << temp_NumberOfMoves << "\n\n ";
    if ( GameBoard[0].isSolved() )
        cout << "\n You finished the game. \n\n" ;
      
}

// overloading operators

// it reads from a file
ifstream& operator << ( ifstream& fs,  NPuzzle &NPuzzle_input ){
            
            int cursor = 0, new_row = 0, new_column = 0, testvalue = 0 ;
            string data_line ;
            string data_value ;  
            
            while ( getline( fs, data_line ) ){
                
                while(  cursor < data_line.size() ){

                    data_value += data_line[ cursor ] ;
                    
                    
                    if ( data_line[ cursor ] == ' ' || cursor == data_line.size() )
                        new_column ++ ;               

           
                    cursor ++ ;          
                }

                cursor = 0;
                new_row ++ ;
                cout << endl;         
            }
            new_column = ( new_column/ new_row) + 1  ;

            NPuzzle_input.TempBoard.setSize( new_row, new_column ) ;

            cursor = 0 ;
            data_value.clear() ;

            
            fs.clear() ;
            fs.seekg( 0, ios::beg ) ;
            
            for ( int i = 0; i < new_row; ++i ){
                for ( int j = 0; j < new_column; ++j ){
                    
                    fs >> data_value ;
                    if( data_value == "bb" ){

                        testvalue = -1 ;      
                        NPuzzle_input.TempBoard.setBoard( i, j, testvalue );
                        NPuzzle_input.TempBoard.setX_Ecell( j ) ;
                        NPuzzle_input.TempBoard.setY_Ecell( i ) ;
                        
                    }
                    else if( stoi( data_value ) == 0 ){

                        NPuzzle_input.TempBoard.setBoard( i, j, -2 );
                    }
                        
                    else{ 
         
                        testvalue = stoi( data_value );
                        NPuzzle_input.TempBoard.setBoard( i, j, testvalue );
                    }                
                }
            }
            
            NPuzzle_input.GameBoard.resize(0) ;
            NPuzzle_input.GameBoard.push_back( NPuzzle_input.TempBoard ) ;

            return fs ;
}

// it prints NPuzzle object to the screen
ostream& operator >> ( ostream &output, const NPuzzle &NPuzzle_input ){

    for ( int i = 0; i < NPuzzle_input.TempBoard.getRow(); ++i ){
        for ( int j = 0; j < NPuzzle_input.TempBoard.getColumn(); ++j ){

            if( NPuzzle_input.TempBoard( i, j ) == -1 ){
                cout <<"\t" ;
                cout << "bb" ;
            }
            else if( NPuzzle_input.TempBoard( i, j ) == - 2 ){
                cout <<"\t" ;
                cout << "00" ;
               
            } 
            
            else if( 0 < NPuzzle_input.TempBoard( i, j ) && NPuzzle_input.TempBoard( i, j ) < 10){
                cout <<"\t" ;
                cout << 0 ;
                cout << NPuzzle_input.TempBoard( i, j ) ;
            }
               
            else{
                cout <<"\t" ;
                cout << NPuzzle_input.TempBoard( i, j ) ;

            }
                
        }
        cout << endl ;
    }
    return output ;
}


// EXTRA FUNCTIONS

// find empty cell cordinates
void NPuzzle :: Find_Ecell () {

    TempBoard.Find_Ecell() ;
}

//  if it is solved returns true, if it is not returns false
bool NPuzzle :: isSolved () const{

   return GameBoard[0].isSolved() ;
}

// return size
int NPuzzle :: getSize() const {

    return TempBoard.getSize() ;
}

// move opposite way of given option
void NPuzzle :: inverseMove( char option ){

    switch( option ){

        case 'U' :         // UP
            TempBoard.move( 'D' ) ;
            break ;
        case 'D' :          // DOWN
            TempBoard.move( 'U' ) ;
            break ;

        case 'L' :          // LEFT
            TempBoard.move( 'R' ) ; 
            break ;
        case 'R' :          // RIGHT
            TempBoard.move( 'L' ) ;
            break ;
    }
}


//*****************************************************************************************

// Board Class

NPuzzle :: Board :: Board (){
    
    // init variables
    row = column = 0 ;
    x_Ecell = y_Ecell = 0 ;
    Count_DoneMove = 0 ;
    prevMove = 'S' ;

    CountOfBoards ++ ;
}

// print board on the console
void NPuzzle :: Board ::  print () const {   
    
    for ( int i = 0; i < row; ++i ){
        for ( int j = 0; j < column; ++j ){

            if( board[ i ][ j ] == -1 ){
                cout <<"\t" ;
                cout << "bb" ;
            }
            else if( board[ i ][ j ] == - 2 ){
                cout <<"\t" ;
                cout << "00" ;
               
            } 
            
            else if( 0 < board[ i ][ j ] && board[ i ][ j ] < 10){
                cout <<"\t" ;
                cout << 0 ;
                cout << board[ i ][ j ] ;
            }
               
            else{
                cout <<"\t" ;
                cout << board[ i ][ j ] ;

            }
                
        }
        cout << endl ;
    }

}

// fill up board according to file
void NPuzzle :: Board :: readFromFile ( const string& file_name ){
    ifstream fs ;
    string data_value ;
    int cursor = 0, testvalue= 0 ;

    fs.open( file_name ) ;
    setSize ( file_name ) ;
    if ( fs.is_open() ){

        for ( int i = 0; i < row; ++i ){
            for ( int j = 0; j < column; ++j ){
                
                fs >> data_value ;
                if( data_value == "bb" ){

                    testvalue = -1 ;      
                    board [ i ][ j ] = testvalue ;
                    x_Ecell = j ;
                    y_Ecell = i ;
                }
                else if( stoi( data_value ) == 0 ){
                    board [ i ][ j ] = -2 ;
                }
                    
                else{ 

                    testvalue = stoi( data_value );
                    board [ i ][ j ] = testvalue ;
                }                
            }
        }
        fs.close();
    }
    else{
        cout << "File is unable to be opened";
    }

}

// write a board configration to file as wanted
void NPuzzle :: Board :: writeToFile ( const string& file_name )const {

    ofstream fs ;
    fs.open( file_name ) ;

    for (int i = 0; i < row; ++i){
        for (int j = 0; j < column; ++j){
            
            if( 0 <= board[ i ][ j ] && board[ i ][ j ] < 10){
                fs << 0 ;
                fs << board[ i ][ j ] ;
            }
            else if( board[ i ][ j ] == -1 )
                fs << "bb" ;
            else if( board[ i ][ j ] == -2 ){
                fs << "00" ;
            }
            else
                fs << board[ i ][ j ] ;
            if( j != column - 1 )
                fs << " " ;
        }
        if(  i != row - 1 )
            fs << "\n" ;
    }   
}

// take the board to the solution
void NPuzzle :: Board :: reset(){

    int value = 1 ;

    for ( int i = 0; i < row; i++ ){ // build a final board
        for ( int j = 0; j < column; j++ ){

            if( board [ i ][ j ] != -2 ){

                board [ i ][ j ] = value ;
                value ++ ;
            }
            
        }
    }
    board [ row - 1 ][ column - 1 ] = -1 ;
}

// check the size to be in range 0-9 , and if it is  assign  row = column = size
bool NPuzzle :: Board :: setSize ( int size ){
    bool valid = true ;
    

    // check the row and column to be in range 0-9
    if( ( size < 3 || size > 9 ) ){
        cout << "\n You entered an invalid number \n " ;
        valid = false ;
    }
    else{
        row = column = size ;
        board.resize(size) ;
        for (int i = 0; i < size; ++i)
        {
            board[i].resize(size) ;
        }
    }

    return valid ;
}


// check the row and column to be in range 0-9 , and if it is  assign  row = new_row  column = new_column
bool NPuzzle :: Board :: setSize ( int new_row, int new_column ){
    bool valid = true ;
    
    // check the row and column to be in range 0-9
    if( ( new_row < 3 || new_row > 9 ) || ( new_column < 3 || new_column > 9 ) ){
        cout << "\n You entered an invalid number \n " ;
        valid = false ;
    }
    else{
        row = new_row ;
        column = new_column ;
        board.resize( new_row ) ;
        for (int i = 0; i < new_row; ++i)
        {
            board[i].resize(new_column) ;
        }
    }

    return valid ;   
}


// check the row and column to be in range 0-9 , and if it is  assign  borders according to file
void NPuzzle :: Board :: setSize ( const string& file_name ){
    ifstream fs ;
    fs.open( file_name ) ;
    string data_line ;
    string data_value ;
    int cursor = 0, new_row = 0, new_column = 0 ;

    if ( fs.is_open() ){
        while ( getline( fs, data_line ) ){
            
            while(  cursor < data_line.size() ){

                data_value += data_line[ cursor ] ;
                
                
                if ( data_line[ cursor ] == ' ' || cursor == data_line.size() )  
                    new_column ++ ;  

                cursor ++ ;          
            }

            cursor = 0;
            new_row ++ ;
            cout << endl;         
        }
        new_column = ( new_column/ new_row) + 1  ;
        fs.close();
    }
    else{
        cout << "File is unable to be opened";
    }

    setSize( new_row, new_column ) ;
}

// move according to option, if it is a valid option returns true, if it is not returns false
bool NPuzzle :: Board :: move ( char option ){
    int temp_x, temp_y ;
    bool valid = false ;
    temp_x = x_Ecell ;  
    temp_y = y_Ecell ;

    switch( option ){

         case 'L' :         // LEFT
            if( 0 <= ( x_Ecell - 1 ) && board[ y_Ecell ][ x_Ecell - 1  ] != -2 ){    
                x_Ecell -- ;
                Count_DoneMove ++ ;
                prevMove = 'L' ;
                valid = true ;
            }
            break ;

        case 'R' :          // RIGHT
            if( ( x_Ecell + 1 ) < column && board[ y_Ecell ][ x_Ecell + 1  ] != -2 ){
                x_Ecell ++ ;
                Count_DoneMove ++ ;
                prevMove = 'R' ;
                valid = true ;
            }
            break ;

        case 'U' :          // UP
            if( 0 <= ( y_Ecell -1 ) && board[ y_Ecell - 1 ][ x_Ecell ] != -2 ){
                y_Ecell -- ;
                Count_DoneMove ++ ;
                prevMove = 'U' ;
                valid = true ;
            }
            break ;

        case 'D' :          // DOWN
            if( ( y_Ecell + 1 ) < row && board[ y_Ecell + 1 ][ x_Ecell ] != -2 ){
                y_Ecell ++ ;
                Count_DoneMove ++ ;
                prevMove = 'D' ;
                valid = true ;
            }
            break ;
    }

    board[ temp_y ][ temp_x ] = board[ y_Ecell ][ x_Ecell ] ;
    board[ y_Ecell ][ x_Ecell ] = -1 ;

    return valid ;
}

//  if it is solved returns true, if it is not returns false
bool NPuzzle :: Board :: isSolved () const {
    bool same = true ;
    int finalBoard [9][9], value = 1 ;

    for ( int i = 0; i < row; i++ ){ // build a final board
        for ( int j = 0; j < column; j++ ){
           
            if( board [ i ][ j ] != -2 ){
                finalBoard [ i ][ j ] = value ;
                value ++ ;
            }
            else 
                finalBoard [ i ][ j ] = -2 ;

                
        }
    }
    finalBoard [ row - 1 ][ column - 1 ] = -1 ;

    for ( int i = 0; i < row; i++ ){ // compare final board and current board
        for ( int j = 0; j < column; j++ ){
            
            if( finalBoard[ i ][ j ] != board[ i ][ j ] ){ // if doesnt match end the loop
                same = false ;
                i = row ;
                j = column ;
            }
        }
    }
    return same ;

}

// return the value in given cordinates
int NPuzzle :: Board :: operator () ( int row_cordinate, int column_cordinate )const{
    
    if( row_cordinate < 0 || row_cordinate > row ||  column_cordinate < 0 || column_cordinate > column ){
        cout << "\n You entered an invalid index.\n Program terminated.\n" ;
        exit(1) ;
    }

    return board[ row_cordinate ][ column_cordinate ] ;
}

// check 2 Board object if equal return true
bool NPuzzle :: Board :: operator == ( const Board& second_input ){
    
    int same = 1 ;

    for (int i = 0; i < row ; ++i){
        for (int j = 0; j < column ; ++j){

            if( this->board[ i ][ j ] != second_input.board[ i ][ j ] )
                same = 0 ;
        }
    }

    return same ;
}

// return CountDonemove
int NPuzzle :: Board :: numberOfMoves() const {

    return Count_DoneMove ;
}

// return prevmove
char NPuzzle :: Board :: lastMove() const {

    return prevMove ;
}

// EXTRA FUNTIONS

// find empty cell cordinates
void NPuzzle :: Board :: Find_Ecell (){

    for( int i = 0; i < row; i++ ){
        for( int j = 0; j < column; j++ ){

            if( board[i][j] == -1 ){ //search empty cell , if it finds it get out the loop
                x_Ecell = j ;
                y_Ecell = i ;

                i = row ;   // end loop
                j = column ;        
            }  
        }
    }     
}

// reset CountDoneMove
void NPuzzle :: Board :: resetCountDoneMove(){

    Count_DoneMove = 0 ;
}

// return size
int NPuzzle :: Board ::  getSize() const {

    return row * column ;
}