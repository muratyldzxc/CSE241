#include <iostream>
#include "AbstractBoard.h"
#include "BoardArray2D.h"
using namespace std ;

namespace GTU_CSE241_2019_2020{
	

	BoardArray2D::BoardArray2D() : AbstractBoard() , board(nullptr){
		// empty
	}

	BoardArray2D::BoardArray2D( const BoardArray2D &other ) : AbstractBoard(){
		
		setSize( other.row, other.column ) ;

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				this->board[i][j] = other.board[i][j] ;

	}

	BoardArray2D& BoardArray2D::operator =( const BoardArray2D  &rightSide ){
		
		if( *this == rightSide )
			return *this ;
		setSize( rightSide.row, rightSide.column ) ;

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				this->board[i][j] = rightSide.board[i][j] ;

		return *this ;

	}
	void BoardArray2D::setSize( int new_row, int new_column ){

		if( new_row < 3 || new_column < 3 ){ // set as default

			for (int i = 0; i < row; ++i)
				delete [] board[i] ;
			delete [] board ;

			row = 3 ;
			column = 3 ;

			board = new int * [row] ;
			for (int i = 0; i < row; ++i)
				board[i] = new int [column] ;

		}
		else if( new_row != row || new_column != column ){

			for (int i = 0; i < row; ++i)
				delete [] board[i] ;
			delete [] board ;

			row = new_row ;
			column = new_column ;

			board = new int * [row] ;
			for (int i = 0; i < row; ++i)
				board[i] = new int [column] ;
		}
		
		reset() ;
	}

	
	
	int& BoardArray2D::operator () ( int row_cordinate, int column_cordinate ){

		return board[ row_cordinate ][ column_cordinate ] ;
	}

	const int& BoardArray2D::operator () ( int row_cordinate, int column_cordinate )const{

		return board[ row_cordinate ][ column_cordinate ] ;

	}
	
	BoardArray2D::~BoardArray2D(){
		for (int i = 0; i < row; ++i)
				delete [] board[i] ;
			delete [] board ;
	}

}

