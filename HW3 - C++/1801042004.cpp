#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std ;







class NPuzzle{

    public:
        NPuzzle () ;
        NPuzzle ( const int& size ) ; // for HW1 , get size from user
        NPuzzle ( const string& file_name ) ; // for HW2 , get size from file
        void print () const ;
        void readFromFile ( const string& file_name ) ;
        void writeToFile ( const string& file_name ) const ;
        void reset () ;

        bool setSize ( const int& size ) ;
        bool setSize ( const int& new_row, const int& new_column ) ;
        void setSize ( const string& file_name ) ;

        bool move ( const char& option ) ;

        // end of same functions with Board class
        void printReport () const ;
        void shuffle ( const int& N ) ;
        char moveRandom () ;
        void moveIntelligent () ;
        void solvePuzzle () ;
        
        // extra functions
        void Find_Ecell () ;
        bool isSolved () const ;
        int getSize() const ;

    private:
        class Board
        {
            public:
                //constructors
                Board () ;
                Board( const int& size ) ; // for HW1 , get size from user
                Board( const string& file_name ) ; // for HW2 , get size from file


                void print () const ;
                void readFromFile ( const string& file_name ) ;
                void writeToFile ( const string& file_name ) const ;
                void reset () ;

                bool setSize ( const int& size ) ;
                bool setSize ( const int& new_row, const int& new_column ) ;
                void setSize ( const string& file_name ) ;

                bool move ( const char& option ) ;
                bool isSolved () const ;

                // extra functions
                void Find_Ecell () ;
                int getSize() const ;
                int getCountDonemove() const ;
                int FindCorrectMove()  ;
                int Find_diffState(  int curState[][3], int finState[][3] ) ;
                void FindCoordinatesGivenValue( int finalBoard[9][9], int value, int * x_value, int * y_value )  ;
                int ABS ( const int& input ) const ;
                int getPrevMove() const ;
                void resetCountDoneMove() ;

            private:
                int row, column ;
                int prevMove ;
                int Count_DoneMove ; // counts how many move done
                int x_Ecell, y_Ecell ;
                int board[9][9] ;      
        };
        Board GameBoard ; // hold board configration       
};





int main( int argc, char *argv[] ){
    
    char option ;
    string file_name ;
    int size ;
    bool validMove ;
    NPuzzle Puzzle ;

    srand( time(NULL) );

    if ( argv[1] == NULL){ // set board for HW1
        
        do{
            cout << "\nPlease enter the problem size: " ;
            cin >> size ;
            cout << endl ;
            
        }while( !Puzzle.setSize ( size ) ) ;

        Puzzle.reset () ; // init the board to final solution
        Puzzle.Find_Ecell() ;
        
        Puzzle.shuffle( size * size * size ) ;
        Puzzle.Find_Ecell() ;
        
    }
    else if( argv[1] != NULL ){ // set board for HW2    
        Puzzle.readFromFile ( argv[1] ) ;        
    }
    
    do{
        Puzzle.print() ;
        cout <<"\n Your option : " ;
        cin >> option ;

        switch ( option ){
            case 'V' :
                Puzzle.solvePuzzle() ;
                break ; 
            case 'T' :
                Puzzle.printReport() ;
                break ;

            case 'E' :
                cout << "\nPlease enter the file name : " ;
                cin >> file_name ;
                Puzzle.writeToFile( file_name ) ;
                break ; 

            case 'O' :
                cout << "\nPlease enter the file name : " ;
                cin >> file_name ;
                Puzzle.readFromFile( file_name ) ;
                break ;

            case 'L' :
                validMove = Puzzle.move( option ) ;
                if( !validMove )
                    cout << "\nYou can not go out of the puzzle.\n" ;
                break ;

            case 'R' :
                validMove = Puzzle.move( option ) ;
                if( !validMove )
                    cout << "\nYou can not go out of the puzzle.\n" ;
                break ;

            case 'U' :
                validMove = Puzzle.move( option ) ;
                if( !validMove )
                    cout << "\nYou can not go out of the puzzle.\n" ;
                break ;

            case 'D' :
                validMove = Puzzle.move( option ) ;
                if( !validMove )
                    cout << "\nYou can not go out of the puzzle.\n" ;
                break ;     

            case 'I' :
                Puzzle.moveIntelligent() ;
                break ;   
            case 'S' :
                size = Puzzle.getSize() ;
                Puzzle.shuffle( size * size ) ;
                break ; 
            case 'Q' :
                break ;

            default:
                cout << "\n You entered an invalid choice. Please give it again.\n" ;
        }

        
    }while( option != 'Q' && !Puzzle.isSolved() ) ;

    if( Puzzle.isSolved() && option != 'V' )
        Puzzle.printReport() ;
    else
        cout << "\n You quit from the program.\n\n" ;

    return 0 ;
    
}
// NPuzzle constructors
NPuzzle :: NPuzzle (){

    Board() ;  
}
NPuzzle :: NPuzzle ( const int& size ){

    GameBoard = Board( size ) ;
}

NPuzzle :: NPuzzle ( const string&  file_name ){

    GameBoard = Board( file_name ) ;
}

// Board constructors

NPuzzle :: Board :: Board (){
    
    // init variables
    row = column = 9 ;
    x_Ecell = y_Ecell = 0 ;
    Count_DoneMove = 0 ;
    prevMove = -1 ;

    for ( int i = 0; i < row; i++ ) // build an init board 
        for ( int j = 0; j < column; j++ )
            board [ i ][ j ] = 1 ;

}

NPuzzle :: Board :: Board ( const int& size ){  
    
    Board() ;
    // check the size to be in range 0-9 , and if it is  assign  row = column = size
    setSize ( size ) ;
    reset () ; // init the board to final solution
    Find_Ecell() ;
}

NPuzzle :: Board :: Board ( const string& file_name ){ 

    readFromFile ( file_name ) ; // init the board according to the file
}

// check the size to be in range 0-9 , and if it is  assign  row = column = size
bool NPuzzle :: Board :: setSize ( const int& size ){
    bool valid = true ;
    

    // check the row and column to be in range 0-9
    if( ( size < 3 || size > 9 ) ){
        cout << "\n You entered an invalid number \n " ;
        valid = false ;
    }
    else
        row = column = size ;

    return valid ;
}
bool NPuzzle :: setSize ( const int& size ){

    return GameBoard.setSize( size ) ;
}

// check the row and column to be in range 0-9 , and if it is  assign  row = new_row  column = new_column
bool NPuzzle :: Board :: setSize ( const int& new_row, const int& new_column ){
    bool valid = true ;
    
    // check the row and column to be in range 0-9
    if( ( new_row < 3 || new_row > 9 ) && ( new_column < 3 || new_column > 9 ) ){
        cout << "\n You entered an invalid number \n " ;
        valid = false ;
    }
    else{
        row = new_row ;
        column = new_column ;
    }

    return valid ;   
}
bool NPuzzle :: setSize ( const int& new_row, const int& new_column ){

    return GameBoard.setSize( new_row, new_column ) ;
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
    // check the row and column to be in range 0-9
    if( ( row <= 0 || row > 9 ) && ( column <= 0 || column > 9 ) ){
        cout << "\n You entered an invalid number \n " ;
        cout << "\n Program terminated \n " ;
        exit(1) ;
    }
    setSize( new_row, new_column ) ;
}
void NPuzzle :: setSize ( const string& file_name ){

    GameBoard.setSize( file_name ) ;
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
void NPuzzle :: readFromFile ( const string& file_name ){

    GameBoard.readFromFile( file_name ) ;
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
            else if( -1 == board[ i ][ j ] )
                fs << "bb" ;
            else
                fs << board[ i ][ j ] ;
            if( j != column - 1 )
                fs << " " ;
        }
        if(  i != row - 1 )
            fs << "\n" ;
    }   
}
void NPuzzle :: writeToFile ( const string& file_name )const {

   GameBoard.writeToFile( file_name ) ;
}

// print board on the console
void NPuzzle :: Board ::  print () const {   
    
    for ( int i = 0; i < row; ++i ){
        for ( int j = 0; j < column; ++j ){
            
            if( 0 <= board[ i ][ j ] && board[ i ][ j ] < 10){
                cout <<"\t" ;
                cout << 0 ;
                cout << board[ i ][ j ] ;
            }
            else if( -1 == board[ i ][ j ] ){
                cout <<"\t" ;
                cout << "bb" ;
            }
                
            else{
                cout <<"\t" ;
                cout << board[ i ][ j ] ;

            }
                
        }
        cout << endl ;
    }

}
void NPuzzle :: print () const {

    GameBoard.print() ;
}
// take the board to the solution
void NPuzzle :: Board :: reset(){

    int value = 1 ;

    for ( int i = 0; i < row; i++ ){ // build a final board
        for ( int j = 0; j < column; j++ ){

            if( board [ i ][ j ] != 0 ){

                board [ i ][ j ] = value ;
                value ++ ;
            }
            
        }
    }
    board [ row - 1 ][ column - 1 ] = -1 ;
}
void NPuzzle :: reset(){

    GameBoard.reset() ;
}
// move according to option, if it is a valid option returns true, if it is not returns false
bool NPuzzle :: Board :: move ( const char& option ){
    int temp_x, temp_y ;
    bool valid = false ;
    temp_x = x_Ecell ;  
    temp_y = y_Ecell ;

    switch( option ){

         case 'L' :         // LEFT
            if( 0 <= ( x_Ecell - 1 ) && board[ y_Ecell ][ x_Ecell - 1  ] != 0 ){    
                x_Ecell -- ;
                Count_DoneMove ++ ;
                prevMove = 3 ;
                valid = true ;
            }
            break ;

        case 'R' :          // RIGHT
            if( ( x_Ecell + 1 ) < column && board[ y_Ecell ][ x_Ecell + 1  ] != 0 ){
                x_Ecell ++ ;
                Count_DoneMove ++ ;
                prevMove = 2 ;
                valid = true ;
            }
            break ;

        case 'U' :          // UP
            if( 0 <= ( y_Ecell -1 ) && board[ y_Ecell - 1 ][ x_Ecell ] != 0 ){
                y_Ecell -- ;
                Count_DoneMove ++ ;
                prevMove = 1 ;
                valid = true ;
            }
            break ;

        case 'D' :          // DOWN
            if( ( y_Ecell + 1 ) < row && board[ y_Ecell + 1 ][ x_Ecell ] != 0 ){
                y_Ecell ++ ;
                Count_DoneMove ++ ;
                prevMove = 0 ;
                valid = true ;
            }
            break ;
    }

    board[ temp_y ][ temp_x ] = board[ y_Ecell ][ x_Ecell ] ;
    board[ y_Ecell ][ x_Ecell ] = -1 ;

    return valid ;
}
bool NPuzzle :: move ( const char& option ){

   return GameBoard.move( option );
}
//  if it is solved returns true, if it is not returns false
bool NPuzzle :: Board :: isSolved () const {
    bool same = true ;
    int finalBoard [9][9], value = 1 ;

    for ( int i = 0; i < row; i++ ){ // build a final board
        for ( int j = 0; j < column; j++ ){
           
            if( board [ i ][ j ] != 0 ){
                finalBoard [ i ][ j ] = value ;
                value ++ ;
            }
            else 
                finalBoard [ i ][ j ] = 0 ;

                
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
bool NPuzzle :: isSolved () const{

   return GameBoard.isSolved() ;
}



// begin of none same functions
void NPuzzle :: printReport () const{
    cout << "\nTotal number of moves : " << GameBoard.getCountDonemove() << "\n\n ";
    if ( GameBoard.isSolved() )
        cout << "\nYou finished the game. \n" ;
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

    }while( !GameBoard.move( option ) ) ;

    return option ;
}
// shuffle board by n times 
void NPuzzle :: shuffle ( const int& N_times ) {

    int i = 0 ;
    bool same ; 
    do{
        while( i < N_times ){ //  shuffle N times
        
            moveRandom() ;      
            i++ ;       
        }
        same = GameBoard.isSolved() ; 
    }while( same == true ) ; // if it is same with final solution after the shuffle , it shuffles again 

    GameBoard.resetCountDoneMove() ;
}
// makes an intelligent move
void NPuzzle :: moveIntelligent (){
    int move ;
    move = GameBoard.FindCorrectMove() ;

    if( move == GameBoard.getPrevMove() ){
        
        cout << "\nIntelligent move: " << moveRandom() << "\n\n"; 
    }
    else{
        switch( move ){
            case 0 :
                GameBoard.move( 'U' ) ;
                cout << "\nIntelligent move: U\n\n"; 
                break ;
            case 1 :
                GameBoard.move( 'D' ) ;
                cout << "\nIntelligent move: D\n\n"; 
                break ;
            case 2 :
                GameBoard.move( 'L' ) ;
                cout << "\nIntelligent move: L\n\n"; 
                break ;
            case 3 :
                GameBoard.move( 'R' ) ;
                cout << "\nIntelligent move: R\n\n"; 
                break ;
            case -1 :
                cout << "\nIntelligent move: " << moveRandom() << "\n\n"; 
                break ;
        }

    }
    
}
// solve the puzzle with intelligent move
void NPuzzle :: solvePuzzle(){
    int count = 0 ;
    while( !isSolved() ){
        if( count != 5 ){
            moveIntelligent() ;
            print() ;
            printReport() ;
            cout << "\n\n\n" ; 
        }
        else{
            moveRandom() ;
        }   
    }
}


// extra functions
// find empty cell cordinates
void NPuzzle :: Board :: Find_Ecell ( ){

    for( int i = 0; i < row; i++ )
        for( int j = 0; j < column; j++ )

            if( board[i][j] == -1 ){ //search empty cell , if it finds it get out the loop
                x_Ecell = j ;
                y_Ecell = i ;

                i = row ;   // end loop
                j = column ;        
            }  
    
}
void NPuzzle :: Find_Ecell () {

    GameBoard.Find_Ecell() ;
}
// return CountDonemove
int NPuzzle :: Board :: getCountDonemove() const {

    return Count_DoneMove ;
}
// return prevmove
int NPuzzle :: Board :: getPrevMove() const {

    return prevMove ;
}
// return absolute value of input
int NPuzzle :: Board :: ABS ( const int& input ) const{
    if( input < 0 )
        return ( input * -1) ;
    else
        return input ;
}
// helps intelligent move
void NPuzzle :: Board :: FindCoordinatesGivenValue( int finalBoard[9][9],  int value, int * x_Value, int * y_Value ){

    for( int i = 0; i < row; i++ ){
        for( int j = 0; j < column; j++ ){
            if( finalBoard[i][j] == value ){ //search value , if it finds it get out the loop
               
                *x_Value = j ;
                *y_Value = i ;

                i = row ;
                j = column ;
            }
        }  
    }
}
// helps intelligent move
int NPuzzle :: Board :: Find_diffState( int curState[][3],  int finState[][3] ){

    int distanceState[4][3], absX, absY ;
    int min, validIndex = -1, result ;

    for (int i = 0; i < 4 ; ++i){ // compare two state , find distance between them
        if( curState[i][0] != 0 ){
            absX = ABS( curState[i][1] - finState[i][1] ) ;
            absY = ABS( curState[i][2] - finState[i][2] ) ;
            distanceState[i][0] = absX + absY ;   
        }    
    }

    //compare states for each movemont way
    if( curState[0][0] != 0 ){
        absX = ABS( curState[0][1] - finState[0][1] ) ; // UP
        absY = ABS( curState[0][2] + 1 - finState[0][2] ) ;
        distanceState[0][1] = absX + absY ;  
    }
    if( curState[1][0] != 0 ){
        absX = ABS( curState[1][1] - finState[1][1] ) ; // DOWN
        absY = ABS( curState[1][2] - 1 - finState[1][2] ) ;
        distanceState[1][1] = absX + absY ;
    }
    if( curState[2][0] != 0 ){
        absX = ABS( curState[2][1] + 1 - finState[2][1] ) ; // LEFT
        absY = ABS( curState[2][2] - finState[2][2] ) ;
        distanceState[2][1] = absX + absY ;
    }
    if( curState[3][0] != 0 ){
        absX = ABS( curState[3][1] - 1 - finState[3][1] ) ; // RIGHT
        absY = ABS( curState[3][2] - finState[3][2] ) ;
        distanceState[3][1] = absX + absY ;
    }

    for (int i = 0; i < 4; ++i){
        
        distanceState[i][2] = distanceState[i][0] - distanceState[i][1] ;
    }
    
    min = distanceState[0][1] ;
    for (int i = 0; i < 4; ++i){
        if( 0 < distanceState[i][2] && distanceState[i][1] <= min && curState[i][0] != 0 ){
            min = distanceState[i][1] ;
            validIndex = i ;
        }
    }

    return validIndex ;
  
}
// helps intelligent move, return correct move
int NPuzzle :: Board :: FindCorrectMove() {

    int currentState[4][3], finalState[4][3], finalBoard[9][9], move ; 

    // init current state
    for (int i = 0; i < 4; ++i){
        currentState[ i ][0] = 0 ;
    }

    // build a currentState , currentState[][0] holds the value , currentState[][1] holds x cordinate , currentState[][2] holds y cordinate
    if( 0 <= y_Ecell - 1  && board[ y_Ecell - 1 ][ x_Ecell ] != 0 ){ // up
        currentState[0][1] = x_Ecell ;
        currentState[0][2] = y_Ecell - 1 ;
        currentState[0][0] = board[ currentState[0][2] ][ currentState[0][1] ] ;
    }
    if( y_Ecell + 1  < row && board[ y_Ecell + 1 ][ x_Ecell ] != 0){ // down
        currentState[1][1] = x_Ecell ;
        currentState[1][2] = y_Ecell + 1 ;
        currentState[1][0] = board[ currentState[1][2] ][ currentState[1][1] ] ;
    }
    if( 0 <= x_Ecell - 1  && board[ y_Ecell ][ x_Ecell - 1 ] != 0 ){  //left
        currentState[2][1] = x_Ecell - 1 ;
        currentState[2][2] = y_Ecell ;
        currentState[2][0] = board[ currentState[2][2] ][ currentState[2][1] ] ;
    }
    if( x_Ecell + 1 < column && board[ y_Ecell ][ x_Ecell + 1 ] != 0 ){  // right
        currentState[3][1] = x_Ecell + 1 ;
        currentState[3][2] = y_Ecell ;
        currentState[3][0] = board[ currentState[3][2] ][ currentState[3][1] ] ;
    }

    // build a final solution
    int value = 1 ;
    for ( int i = 0; i < row; i++ ){ // build a final board
        for ( int j = 0; j < column; j++ ){

            if( board [ i ][ j ] != 0 ){

                finalBoard [ i ][ j ] = value ;
                value ++ ;
            }          
        }
    }

    // build a finalState , finalState[][0] holds the value , finalState[][1] holds x cordinate , finalState[][2] holds y cordinate

    for (int i = 0; i < 4; ++i){ // calculates each number where should  be
        if( currentState[i][0] != 0 ){
            finalState[ i ][0] = currentState[ i ][0] ;
            FindCoordinatesGivenValue( finalBoard, currentState[ i ][0], &finalState[ i ][1], &finalState[ i ][2] ) ;
        }
        else
            finalState[ i ][0] = 0 ;   
    }

    move = Find_diffState( currentState, finalState ) ;

    return move ;

}
// reset CountDoneMove
void NPuzzle :: Board :: resetCountDoneMove(){

    Count_DoneMove = 0 ;
}
// return size
int NPuzzle :: Board ::  getSize() const {

    return row * column ;
}
int NPuzzle :: getSize() const {

    return GameBoard.getSize() ;
}