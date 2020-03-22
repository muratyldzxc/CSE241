#include <iostream>
#include <fstream>
using namespace std ;

#ifndef AbstractBoard_H
#define AbstractBoard_H

namespace GTU_CSE241_2019_2020{
	
	class AbstractBoard{

		public:
			AbstractBoard();
			void print()const ;
			void readFromFile( ifstream &fs ) ;
			void writeToFile( ofstream &fs  ) const ;
			void reset() ;
			
			bool move( char option ) ;
			bool isSolved()const ;
			
			inline static int  NumberOfBoards(){   return CountOfBoards ; }
			inline char lastMove() const { return prevMove ; }
			inline int numberOfMoves() const { return Count_DoneMove ; }

			// overloading operators
			virtual int& operator () ( int row_cordinate, int column_cordinate ) = 0 ;
			virtual const int& operator () ( int row_cordinate, int column_cordinate ) const = 0 ;
			bool operator == ( const AbstractBoard & )const ;

			virtual void setSize( int new_row, int new_column ) = 0 ;

			// extra ffunctions
			inline int getX_Ecell() const { return x_Ecell ; }
            inline int getY_Ecell() const { return y_Ecell ; }

            inline int getRow() const { return row ; }
            inline int getColumn() const { return column ; }

			virtual ~AbstractBoard();

		protected:

			static int CountOfBoards ; // hold how mant Board object created

            int row, column ; // hold row and column
            char prevMove ; // hold last move
            int Count_DoneMove ; // counts how many move done
            int x_Ecell, y_Ecell ; // holds empty cell's cordinatess
            
            inline void setX_Ecell( int x_cordinate ){ x_Ecell = x_cordinate ; }
            inline void setY_Ecell( int y_cordinate ){ y_Ecell = y_cordinate ; }

	};
}

#endif