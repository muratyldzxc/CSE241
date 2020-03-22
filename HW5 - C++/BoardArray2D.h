#include <iostream>
#include "AbstractBoard.h"
using namespace std ;

#ifndef BoardArray2D_H
#define BoardArray2D_H

namespace GTU_CSE241_2019_2020{
	
	class BoardArray2D : public AbstractBoard 
	{

		public:

			BoardArray2D();

			BoardArray2D( const BoardArray2D &other );

			BoardArray2D& operator =(const BoardArray2D &rightSide);
			
			int& operator () ( int row_cordinate, int column_cordinate ) override ;
			const int& operator () ( int row_cordinate, int column_cordinate ) const override ;
			void setSize( int new_row, int new_column ) override ;

			~BoardArray2D() override ;

		private:
			int ** board ;
	};
}

#endif