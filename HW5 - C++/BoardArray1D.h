#include <iostream>
#include "AbstractBoard.h"
using namespace std ;

#ifndef BoardArray1D_H
#define BoardArray1D_H

namespace GTU_CSE241_2019_2020{
	
	class BoardArray1D : public AbstractBoard 
	{

		public:

			BoardArray1D();

			BoardArray1D( const BoardArray1D &other );

			BoardArray1D& operator =(const BoardArray1D &rightSide);
			
			int& operator () ( int row_cordinate, int column_cordinate ) override ;
			const int& operator () ( int row_cordinate, int column_cordinate ) const override ;
			void setSize( int new_row, int new_column ) override ;

			~BoardArray1D() override ;

		private:
			int * board ;
	};
}

#endif