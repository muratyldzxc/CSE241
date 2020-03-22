#include <iostream>
#include "AbstractBoard.h"
#include "BoardArray1D.h"
using namespace std ;

namespace GTU_CSE241_2019_2020{
	

	BoardArray1D::BoardArray1D() : AbstractBoard() , board(nullptr){
		// empty
	}

	BoardArray1D::BoardArray1D( const BoardArray1D &other ) : AbstractBoard(){
		
		setSize( other.row, other.column ) ;

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				this->board[ (i * column ) + j ] = other.board[ (i * column ) + j ] ;

	}

	BoardArray1D& BoardArray1D::operator =( const BoardArray1D  &rightSide ){
		
		if( *this == rightSide )
			return *this ;
		setSize( rightSide.row, rightSide.column ) ;

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				this->board[ (i * column ) + j ] = rightSide.board[ (i * column ) + j ] ;

		return *this ;

	}
	void BoardArray1D::setSize( int new_row, int new_column ){

		if( new_row < 3 || new_column < 3 ){ // set as default
			
			delete [] board ;

			row = 3 ;
			column = 3 ;

			board = new int [ row * column ] ;
		}
		else if( new_row != row || new_column != column ){

			delete [] board ;

			row = new_row ;
			column = new_column ;

			board = new int [ row * column ] ;
		}
		
		reset() ;	
	}

	
	
	int& BoardArray1D::operator () ( int row_cordinate, int column_cordinate ){

		return board[ ( row_cordinate * column ) + column_cordinate ] ;
	}

	const int& BoardArray1D::operator () ( int row_cordinate, int column_cordinate )const{

		return board[ ( row_cordinate * column ) + column_cordinate ] ;

	}
	
	BoardArray1D::~BoardArray1D(){
		
		delete [] board ;
	}

}

