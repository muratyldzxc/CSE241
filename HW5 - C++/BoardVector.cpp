#include <iostream>
#include "AbstractBoard.h"
#include "BoardVector.h"
#include <vector>
using namespace std ;

namespace GTU_CSE241_2019_2020{
	

	BoardVector::BoardVector() : AbstractBoard(){
		// empty
	}

	BoardVector::BoardVector( const BoardVector &other ) : AbstractBoard(){
		
		setSize( other.row, other.column ) ;

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				this->board[i][j] = other.board[i][j] ;

	}

	BoardVector& BoardVector::operator =( const BoardVector  &rightSide ){
		
		if( *this == rightSide )
			return *this ;
		setSize( rightSide.row, rightSide.column ) ;

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				this->board[i][j] = rightSide.board[i][j] ;

		return *this ;

	}
	void BoardVector::setSize( int new_row, int new_column ){

		if( new_row < 3 || new_column < 3 ){ // set as default
			
			for( auto &subVector : board )
		    	subVector.clear() ;
			board.clear() ;
			
			row = 3 ;
			column = 3 ;

			board.resize( row ) ;
			for( auto &subVector : board )
		    	subVector.resize( column ) ;
		}
		else if( new_row != row || new_column != column ){
			
			for( auto &subVector : board )
		    	subVector.clear() ;
			board.clear() ;
		
			row = new_row ;
			column = new_column ;

			board.resize( row ) ;
			for( auto &subVector : board )
		    	subVector.resize( column ) ;
		}

		reset() ;
	}
	
	int& BoardVector::operator () ( int row_cordinate, int column_cordinate ){

		return board[ row_cordinate ][ column_cordinate ] ;
	}

	const int& BoardVector::operator () ( int row_cordinate, int column_cordinate )const{

		return board[ row_cordinate ][ column_cordinate ] ;

	}
	
	BoardVector::~BoardVector(){
		
		// empty
	}

}

