#include <iostream>
#include <fstream>
#include "AbstractBoard.h"
using namespace std ;

namespace GTU_CSE241_2019_2020{

	int AbstractBoard :: CountOfBoards = 0 ; // init Board object counter, it is a static data

	AbstractBoard :: AbstractBoard()
			: row(0), column(0), prevMove('S'), Count_DoneMove(0),x_Ecell(0), y_Ecell(0)
	{
		CountOfBoards ++ ;
	}
	void AbstractBoard :: print() const {
		for ( int i = 0; i < row; ++i ){
		    for ( int j = 0; j < column; ++j ){

		        if( operator()(i, j) == -1 ){
		            cout <<"\t" ;
		            cout << "bb" ;
		        }
		        else if( operator()(i, j) == - 2 ){
		            cout <<"\t" ;
		            cout << "00" ;
		           
		        } 
		        
		        else if( 0 < operator()(i, j) && operator()(i, j) < 10){
		            cout <<"\t" ;
		            cout << 0 ;
		            cout << operator()(i, j) ;
		        }
		           
		        else{
		            cout <<"\t" ;
		            cout << operator()(i, j) ;

		        }
		            
		    }
	        cout << endl ;
	    }

	}
	void AbstractBoard :: readFromFile( ifstream &fs ){

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

        setSize( new_row, new_column ) ;

        cursor = 0 ;
        data_value.clear() ;

        
        fs.clear() ;
        fs.seekg( 0, ios::beg ) ;
        
        for ( int i = 0; i < new_row; ++i ){
            for ( int j = 0; j < new_column; ++j ){
                
                fs >> data_value ;
                if( data_value == "bb" ){

                    testvalue = -1 ;      
                    operator()(i,j) = testvalue ;
                    setX_Ecell( j ) ;
                    setY_Ecell( i ) ;
                    
                }
                else if( stoi( data_value ) == 0 ){

                   operator()(i,j) = -2 ;
                }
                    
                else{ 
     
                    testvalue = stoi( data_value );
                    operator()(i,j) = testvalue ;
                }                
            }
        }

	} 

	void AbstractBoard :: writeToFile( ofstream &fs ) const {

		for (int i = 0; i < row; ++i){
	        for (int j = 0; j < column; ++j){
	            
	            if( 0 <= operator()(i, j) && operator()(i, j) < 10){
	                fs << 0 ;
	                fs << operator()(i, j) ;
	            }
	            else if( operator()(i, j) == -1 )
	                fs << "bb" ;
	            else if( operator()(i, j) == -2 ){
	                fs << "00" ;
	            }
	            else
	                fs << operator()(i, j) ;
	            if( j != column - 1 )
	                fs << " " ;
	        }
	        if(  i != row - 1 )
	            fs << "\n" ;
	    } 
	}

	void AbstractBoard :: reset(){
		int value = 1 ;

	    for ( int i = 0; i < row; i++ ){ // build a final board
	        for ( int j = 0; j < column; j++ ){

	            if( operator()(i, j) != -2 ){

	                operator()(i, j) = value ;
	                value ++ ;
	            }
	            
	        }
	    }
	    operator()( row - 1, column - 1 ) = -1 ;
	    prevMove = 'S' ;
	    Count_DoneMove = 0 ;
	    x_Ecell = row - 1 ;
	    y_Ecell = column - 1 ;

	}

	bool AbstractBoard :: move( char option ){
		int temp_x, temp_y ;
	    bool valid = false ;
	    temp_x = x_Ecell ;  
	    temp_y = y_Ecell ;

	    switch( option ){

	         case 'L' :         // LEFT
	            if( 0 <= ( x_Ecell - 1 ) && operator()( y_Ecell, x_Ecell - 1 ) != -2 ){    
	                x_Ecell -- ;
	                Count_DoneMove ++ ;
	                prevMove = 'L' ;
	                valid = true ;
	            }
	            break ;

	        case 'R' :          // RIGHT
	            if( ( x_Ecell + 1 ) < column && operator()( y_Ecell, x_Ecell + 1 ) != -2 ){
	                x_Ecell ++ ;
	                Count_DoneMove ++ ;
	                prevMove = 'R' ;
	                valid = true ;
	            }
	            break ;

	        case 'U' :          // UP
	            if( 0 <= ( y_Ecell -1 ) && operator()( y_Ecell-1, x_Ecell ) != -2 ){
	                y_Ecell -- ;
	                Count_DoneMove ++ ;
	                prevMove = 'U' ;
	                valid = true ;
	            }
	            break ;

	        case 'D' :          // DOWN
	            if( ( y_Ecell + 1 ) < row && operator()( y_Ecell+1, x_Ecell ) != -2 ){
	                y_Ecell ++ ;
	                Count_DoneMove ++ ;
	                prevMove = 'D' ;
	                valid = true ;
	            }
	            break ;
	    }

	    operator()( temp_y, temp_x ) = operator()( y_Ecell, x_Ecell ) ;
	    operator()( y_Ecell, x_Ecell ) = -1 ;

	    return valid ;
	}

	bool AbstractBoard :: isSolved() const {
		bool same = true ;
	    int **finalBoard , value = 1 ;

	    finalBoard = new int* [row];
	    for ( int i = 0; i < row; ++i){
	        finalBoard[i] = new int [column] ;
	    }

	    for ( int i = 0; i < row; i++ ){ // build a final board
	        for ( int j = 0; j < column; j++ ){
	           
	            if( operator()(i, j) != -2 ){
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
	            
	            if( finalBoard[ i ][ j ] != operator()(i, j) ){ // if doesnt match end the loop
	                same = false ;
	                i = row ;
	                j = column ;
	            }
	        }
	    }
	    return same ;
	}

	bool AbstractBoard :: operator == ( const AbstractBoard &second_input )const{
		bool same = true ;

	    for (int i = 0; i < row ; ++i){
	        for (int j = 0; j < column ; ++j){

	            if( this->operator()(i, j) != second_input.operator()( i , j ) )
	                same = false ;
	        }
	    }

	    return same ;
	}

	// destructor
    AbstractBoard::~AbstractBoard(){
    	// empty 
    }

}

