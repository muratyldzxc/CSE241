#include <iostream>
#include <vector>
#include "AbstractBoard.h"
using namespace std ;

#ifndef BoardVector_H
#define BoardVector_H

namespace GTU_CSE241_2019_2020{
	
	class BoardVector : public AbstractBoard 
	{

		public:

			BoardVector();

			BoardVector( const BoardVector &other );

			BoardVector& operator =(const BoardVector &rightSide);
			
			int& operator () ( int row_cordinate, int column_cordinate ) override ;
			const int& operator () ( int row_cordinate, int column_cordinate ) const override ;
			void setSize( int new_row, int new_column ) override ;

			~BoardVector() override ;

		private:
			vector< vector<int> > board ;
	};
}

#endif