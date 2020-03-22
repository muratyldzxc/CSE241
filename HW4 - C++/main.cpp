#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include "NPuzzle.h"
using namespace std ;

int NPuzzle :: Board :: CountOfBoards = 0 ; // init Board object counter


int main( int argc, char *argv[] ){
    
    int size ;
    char option ;
    string file_name ;
    bool validMove ;

    NPuzzle Puzzle ;
    ifstream fin ;

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
        fin.open( argv[1] ) ;
        fin << Puzzle ;
        fin.close() ;      
    }
    do{
        cout >> Puzzle ;
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
                fin.open( file_name ) ;
                fin << Puzzle ;
                fin.close() ;
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
    else if( option == 'Q' )
        cout << "\n You quit from the program.\n\n" ;
    

    return 0 ;
    
}
