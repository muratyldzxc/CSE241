#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
using namespace std ;

#ifndef NPuzzle_H
#define NPuzzle_H

class NPuzzle{

    public:
        // constructors
        NPuzzle () ;

        
        void print () const ;
        void printReport () const ;
        void readFromFile ( const string& file_name ) ;
        void writeToFile ( const string& file_name ) const ;
        void shuffle ( int N ) ;
        void reset () ;

        bool setSize ( int size ) ;
        bool setSize ( int new_row, int new_column ) ;
        void setSize ( const string& file_name ) ;

        char moveRandom () ;
        bool move ( char option ) ;
        void solvePuzzle () ;
           

        // test overloading operators
        
        friend ostream& operator >> ( ostream &output, const NPuzzle &NPuzzle_input ) ;
        friend ifstream& operator << ( ifstream& fs,  NPuzzle &NPuzzle_input ) ;

        // extra functions
        void Find_Ecell () ;
        bool isSolved () const ;
        int getSize() const ;
        void inverseMove( char option ) ;
        
        inline static int  NumberOfBoards(){   return Board :: NumberOfBoards() ; }
        
    private:
        class Board
        {
            public:
                //constructors
                Board () ;


                void print () const ;
                void readFromFile ( const string& file_name ) ;
                void writeToFile ( const string& file_name ) const ;
                void reset () ;

                bool setSize ( int size ) ;
                bool setSize ( int new_row, int new_column ) ;
                void setSize ( const string& file_name ) ;

                bool move ( char option ) ;
                bool isSolved () const ;

                //operator overloading
                int operator () ( int x_cordinate, int y_cordinate )const ;
                bool operator == ( const Board& second_input ); 

                inline static int  NumberOfBoards() {   return CountOfBoards ; }
                int numberOfMoves() const ;
                char lastMove() const ;

                //set functions for overload operators
                void setRow( int new_row ){  row = new_row ; }
                void setColumn( int new_column ){  column = new_column  ; }
                void setX_Ecell( int x_cordinate ){ x_Ecell = x_cordinate ; }
                void setY_Ecell( int y_cordinate ){ y_Ecell = y_cordinate ; }
                void setBoard( int x_cordinate, int y_cordinate, int value){ board[ x_cordinate ][ y_cordinate ] = value ; }
                void setLastMove( char move ){ prevMove = move ; } 
                // get functions for overload operators
                int getRow()const { return row ; }
                int getColumn()const { return column ; }       

                // extra functions
                
                void Find_Ecell () ;
                int getSize() const ;
                void resetCountDoneMove() ;

            private:
                static int CountOfBoards ; // hold how mant Board object created
                int row, column ; // hold row and column
                int prevMove ; // hold last move
                int Count_DoneMove ; // counts how many move done
                int x_Ecell, y_Ecell ; // holds epty cell's cordinates
                vector < vector <int> > board ;  // holds board configration 
        };
        vector < Board > GameBoard ; // for new solve algorithm
        Board TempBoard ; // for temporary processes
};

#endif