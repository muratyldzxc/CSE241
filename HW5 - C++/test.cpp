#include <iostream>
#include <fstream>
#include <string>
#include "AbstractBoard.h"
#include "BoardArray2D.h"
#include "BoardArray1D.h"
#include "BoardVector.h"
using namespace std ;
using namespace GTU_CSE241_2019_2020 ;


bool test( const AbstractBoard* const AbstractBoard_Array[], int size ){

	int old_x_Ecell, old_y_Ecell, new_x_Ecell, new_y_Ecell ;

	old_x_Ecell = AbstractBoard_Array[0]->getX_Ecell() ;
	old_y_Ecell = AbstractBoard_Array[0]->getY_Ecell() ;
	new_x_Ecell = AbstractBoard_Array[1]->getX_Ecell() ;
	new_y_Ecell = AbstractBoard_Array[1]->getY_Ecell() ;

	if( AbstractBoard_Array[ size - 1 ]->isSolved() ){ // if the final board is a solution
		
		for (int i = 1; i < size; ++i){

			if( old_x_Ecell != new_x_Ecell || old_y_Ecell != new_y_Ecell ){ // if prevBoard  and afterBoard empty cell cordinates are not the same

				for (int row = 0; row < AbstractBoard_Array[0]->getRow(); ++row){ 
				
					for (int column = 0; column < AbstractBoard_Array[0]->getColumn(); ++column)
					{
						if( (*AbstractBoard_Array[ i-1 ]) ( row, column ) != (*AbstractBoard_Array[ i ]) ( row, column ) ){ // check are thw two board same
							
							if ( (*AbstractBoard_Array[ i-1 ]) ( row, column ) != (*AbstractBoard_Array[ i ]) ( new_y_Ecell, new_x_Ecell ) 
								&& (*AbstractBoard_Array[ i-1 ]) ( row, column ) != (*AbstractBoard_Array[ i ]) ( old_y_Ecell, old_x_Ecell ) )
							{
								return false ;

							}	
						}
					}
				}		
			}
			else{
				cout <<"\n\n board "<< i-1 << " board " << i <<" are same board \n\n" ;
				return false ;
			}

			old_x_Ecell = AbstractBoard_Array[i]->getX_Ecell() ;
			old_y_Ecell = AbstractBoard_Array[i]->getY_Ecell() ;

			new_x_Ecell = AbstractBoard_Array[i+1]->getX_Ecell() ;
			new_y_Ecell = AbstractBoard_Array[i+1]->getY_Ecell() ;

		}
			
	}
	else{
		cout << "\n\n it is not solved \n\n" ;
		return false ;
	}	

	return true ;
}

int main (){
	
	cout << " \n\nbefore calling any constructor number of Boards : " << BoardArray2D::NumberOfBoards() << endl ;
	BoardArray2D board2D ;

	ifstream fin ;
	ofstream fout ;

	cout << "\n\n*************************************************************************************************" ;
	cout << "\n\n TESTING BoardArray2D functions " ;
	cout << "\n\n*************************************************************************************************" ;
	//after constructor called
	cout << "\n\n After BoardArray2D constructor called \n\n There is no board configration yet.\n" ;
	board2D.print() ;
	cout << "\nrow : " << board2D.getRow() << " , column : " << board2D.getColumn() << endl ;
	cout << "x_Ecell : " << board2D.getX_Ecell() << " , y_Ecell : " << board2D.getY_Ecell() << endl ;
	cout << "lastmove : " << board2D.lastMove() << endl ;
	cout << "number of moves : " << board2D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board2D.NumberOfBoards() << endl ;


	fin.open( "txt_files/BoardArray2D_test.txt" ) ;
	board2D.readFromFile( fin ) ;

	cout << "\n\n After BoardArray2D object readed from file \n\n " ;
	board2D.print() ;
	cout << "\nrow : " << board2D.getRow() << " , column : " << board2D.getColumn() << endl ;
	cout << "x_Ecell : " << board2D.getX_Ecell() << " , y_Ecell : " << board2D.getY_Ecell() << endl ;
	cout << "lastmove : " << board2D.lastMove() << endl ;
	cout << "number of moves : " << board2D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board2D.NumberOfBoards() << endl ;

	cout << "\n\n After BoardArray2D object moved up \n\n " ;
	board2D.move( 'U' ) ;
	board2D.print() ;
	cout << "\nrow : " << board2D.getRow() << " , column : " << board2D.getColumn() << endl ;
	cout << "x_Ecell : " << board2D.getX_Ecell() << " , y_Ecell : " << board2D.getY_Ecell() << endl ;
	cout << "lastmove : " << board2D.lastMove() << endl ;
	cout << "number of moves : " << board2D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board2D.NumberOfBoards() << endl ;

	cout << "\n\n After BoardArray2D object moved left \n\n " ;
	board2D.move( 'L' ) ;
	board2D.print() ;
	cout << "\nrow : " << board2D.getRow() << " , column : " << board2D.getColumn() << endl ;
	cout << "x_Ecell : " << board2D.getX_Ecell() << " , y_Ecell : " << board2D.getY_Ecell() << endl ;
	cout << "lastmove : " << board2D.lastMove() << endl ;
	cout << "number of moves : " << board2D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board2D.NumberOfBoards() << endl ;

	cout << "\n\n After BoardArray2D object moved down \n\n " ;
	board2D.move( 'D' ) ;
	board2D.print() ;
	cout << "\nrow : " << board2D.getRow() << " , column : " << board2D.getColumn() << endl ;
	cout << "x_Ecell : " << board2D.getX_Ecell() << " , y_Ecell : " << board2D.getY_Ecell() << endl ;
	cout << "lastmove : " << board2D.lastMove() << endl ;
	cout << "number of moves : " << board2D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board2D.NumberOfBoards() << endl ;

	cout << "\n\n After BoardArray2D object moved right \n\n " ;
	board2D.move( 'R' ) ;
	board2D.print() ;
	cout << "\nrow : " << board2D.getRow() << " , column : " << board2D.getColumn() << endl ;
	cout << "x_Ecell : " << board2D.getX_Ecell() << " , y_Ecell : " << board2D.getY_Ecell() << endl ;
	cout << "lastmove : " << board2D.lastMove() << endl ;
	cout << "number of moves : " << board2D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board2D.NumberOfBoards() << endl ;

	cout << "\n\n After BoardArray2D object moved up \n\n " ;
	board2D.move( 'U' ) ;
	board2D.print() ;
	cout << "\nrow : " << board2D.getRow() << " , column : " << board2D.getColumn() << endl ;
	cout << "x_Ecell : " << board2D.getX_Ecell() << " , y_Ecell : " << board2D.getY_Ecell() << endl ;
	cout << "lastmove : " << board2D.lastMove() << endl ;
	cout << "number of moves : " << board2D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board2D.NumberOfBoards() << endl ;

	fout.open( "txt_files/BoardArray2D_restore.txt" ) ;
	board2D.writeToFile( fout ) ;

	cout << "\n\n After BoardArray2D object written to file \n\n " ;
	board2D.print() ;
	cout << "\nrow : " << board2D.getRow() << " , column : " << board2D.getColumn() << endl ;
	cout << "x_Ecell : " << board2D.getX_Ecell() << " , y_Ecell : " << board2D.getY_Ecell() << endl ;
	cout << "lastmove : " << board2D.lastMove() << endl ;
	cout << "number of moves : " << board2D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board2D.NumberOfBoards() << endl ;

	board2D.reset() ;

	cout << "\n\n After BoardArray2D object reset \n\n " ;
	board2D.print() ;
	cout << "\nrow : " << board2D.getRow() << " , column : " << board2D.getColumn() << endl ;
	cout << "x_Ecell : " << board2D.getX_Ecell() << " , y_Ecell : " << board2D.getY_Ecell() << endl ;
	cout << "lastmove : " << board2D.lastMove() << endl ;
	cout << "number of moves : " << board2D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board2D.NumberOfBoards() << endl ;

	fin.close() ;
	fout.close() ;

	cout << "\n\n*************************************************************************************************" ;
	cout << "\n\n TESTING BoardVector functions " ;
	cout << "\n\n*************************************************************************************************" ;
	cout << " \n\nbefore calling another constructor number of Boards : " << BoardVector::NumberOfBoards() << endl ;
	BoardVector boardVector ;

	//after constructor called
	cout << "\n\n After BoardVector constructor called \n\n There is no board configration yet.\n" ;
	boardVector.print() ;
	cout << "\nrow : " << boardVector.getRow() << " , column : " << boardVector.getColumn() << endl ;
	cout << "x_Ecell : " << boardVector.getX_Ecell() << " , y_Ecell : " << boardVector.getY_Ecell() << endl ;
	cout << "lastmove : " << boardVector.lastMove() << endl ;
	cout << "number of moves : " << boardVector.numberOfMoves() << endl ;
	cout << "number of Boards : " << boardVector.NumberOfBoards() << endl ;


	fin.open( "txt_files/BoardVector_test.txt" ) ;
	boardVector.readFromFile( fin ) ;

	cout << "\n\n After BoardVector object readed from file \n\n " ;
	boardVector.print() ;
	
	cout << "\nrow : " << boardVector.getRow() << " , column : " << boardVector.getColumn() << endl ;
	cout << "x_Ecell : " << boardVector.getX_Ecell() << " , y_Ecell : " << boardVector.getY_Ecell() << endl ;
	cout << "lastmove : " << boardVector.lastMove() << endl ;
	cout << "number of moves : " << boardVector.numberOfMoves() << endl ;
	cout << "number of Boards : " << boardVector.NumberOfBoards() << endl ;

	cout << "\n\n After BoardVector object moved up \n\n " ;
	boardVector.move( 'U' ) ;
	boardVector.print() ;
	cout << "\nrow : " << boardVector.getRow() << " , column : " << boardVector.getColumn() << endl ;
	cout << "x_Ecell : " << boardVector.getX_Ecell() << " , y_Ecell : " << boardVector.getY_Ecell() << endl ;
	cout << "lastmove : " << boardVector.lastMove() << endl ;
	cout << "number of moves : " << boardVector.numberOfMoves() << endl ;
	cout << "number of Boards : " << boardVector.NumberOfBoards() << endl ;

	cout << "\n\n After BoardVector object moved left \n\n " ;
	boardVector.move( 'L' ) ;
	boardVector.print() ;
	cout << "\nrow : " << boardVector.getRow() << " , column : " << boardVector.getColumn() << endl ;
	cout << "x_Ecell : " << boardVector.getX_Ecell() << " , y_Ecell : " << boardVector.getY_Ecell() << endl ;
	cout << "lastmove : " << boardVector.lastMove() << endl ;
	cout << "number of moves : " << boardVector.numberOfMoves() << endl ;
	cout << "number of Boards : " << boardVector.NumberOfBoards() << endl ;

	cout << "\n\n After BoardVector object moved down \n\n " ;
	boardVector.move( 'D' ) ;
	boardVector.print() ;
	cout << "\nrow : " << boardVector.getRow() << " , column : " << boardVector.getColumn() << endl ;
	cout << "x_Ecell : " << boardVector.getX_Ecell() << " , y_Ecell : " << boardVector.getY_Ecell() << endl ;
	cout << "lastmove : " << boardVector.lastMove() << endl ;
	cout << "number of moves : " << boardVector.numberOfMoves() << endl ;
	cout << "number of Boards : " << boardVector.NumberOfBoards() << endl ;

	cout << "\n\n After BoardVector object moved right \n\n " ;
	boardVector.move( 'R' ) ;
	boardVector.print() ;
	cout << "\nrow : " << boardVector.getRow() << " , column : " << boardVector.getColumn() << endl ;
	cout << "x_Ecell : " << boardVector.getX_Ecell() << " , y_Ecell : " << boardVector.getY_Ecell() << endl ;
	cout << "lastmove : " << boardVector.lastMove() << endl ;
	cout << "number of moves : " << boardVector.numberOfMoves() << endl ;
	cout << "number of Boards : " << boardVector.NumberOfBoards() << endl ;

	cout << "\n\n After BoardVector object moved up \n\n " ;
	boardVector.move( 'U' ) ;
	boardVector.print() ;
	cout << "\nrow : " << boardVector.getRow() << " , column : " << boardVector.getColumn() << endl ;
	cout << "x_Ecell : " << boardVector.getX_Ecell() << " , y_Ecell : " << boardVector.getY_Ecell() << endl ;
	cout << "lastmove : " << boardVector.lastMove() << endl ;
	cout << "number of moves : " << boardVector.numberOfMoves() << endl ;
	cout << "number of Boards : " << boardVector.NumberOfBoards() << endl ;

	fout.open( "txt_files/BoardVector_restore.txt" ) ;
	boardVector.writeToFile( fout ) ;

	cout << "\n\n After BoardVector object written to file \n\n " ;
	boardVector.print() ;
	cout << "\nrow : " << boardVector.getRow() << " , column : " << boardVector.getColumn() << endl ;
	cout << "x_Ecell : " << boardVector.getX_Ecell() << " , y_Ecell : " << boardVector.getY_Ecell() << endl ;
	cout << "lastmove : " << boardVector.lastMove() << endl ;
	cout << "number of moves : " << boardVector.numberOfMoves() << endl ;
	cout << "number of Boards : " << boardVector.NumberOfBoards() << endl ;

	boardVector.reset() ;

	cout << "\n\n After BoardVector object reset \n\n " ;
	boardVector.print() ;
	cout << "\nrow : " << boardVector.getRow() << " , column : " << boardVector.getColumn() << endl ;
	cout << "x_Ecell : " << boardVector.getX_Ecell() << " , y_Ecell : " << boardVector.getY_Ecell() << endl ;
	cout << "lastmove : " << boardVector.lastMove() << endl ;
	cout << "number of moves : " << boardVector.numberOfMoves() << endl ;
	cout << "number of Boards : " << boardVector.NumberOfBoards() << endl ;
	
	fin.close() ;
	fout.close() ;

	
	cout << "\n\n*************************************************************************************************" ;
	cout << "\n\n TESTING BoardArray1D functions " ;
	cout << "\n\n*************************************************************************************************" ;
	cout << " \n\nbefore calling another constructor number of Boards : " << BoardArray1D::NumberOfBoards() << endl ;
	BoardArray1D board1D ;

	//after constructor called
	cout << "\n\n After BoardArray1D constructor called \n\n There is no board configration yet.\n" ;
	board1D.print() ;
	cout << "\nrow : " << board1D.getRow() << " , column : " << board1D.getColumn() << endl ;
	cout << "x_Ecell : " << board1D.getX_Ecell() << " , y_Ecell : " << board1D.getY_Ecell() << endl ;
	cout << "lastmove : " << board1D.lastMove() << endl ;
	cout << "number of moves : " << board1D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board1D.NumberOfBoards() << endl ;


	fin.open( "txt_files/BoardArray1D_test.txt" ) ;
	board1D.readFromFile( fin ) ;

	cout << "\n\n After BoardArray1D object readed from file \n\n " ;
	board1D.print() ;
	cout << "\nrow : " << board1D.getRow() << " , column : " << board1D.getColumn() << endl ;
	cout << "x_Ecell : " << board1D.getX_Ecell() << " , y_Ecell : " << board1D.getY_Ecell() << endl ;
	cout << "lastmove : " << board1D.lastMove() << endl ;
	cout << "number of moves : " << board1D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board1D.NumberOfBoards() << endl ;

	cout << "\n\n After BoardArray1D object moved up \n\n " ;
	board1D.move( 'U' ) ;
	board1D.print() ;
	cout << "\nrow : " << board1D.getRow() << " , column : " << board1D.getColumn() << endl ;
	cout << "x_Ecell : " << board1D.getX_Ecell() << " , y_Ecell : " << board1D.getY_Ecell() << endl ;
	cout << "lastmove : " << board1D.lastMove() << endl ;
	cout << "number of moves : " << board1D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board1D.NumberOfBoards() << endl ;

	cout << "\n\n After BoardArray1D object moved left \n\n " ;
	board1D.move( 'L' ) ;
	board1D.print() ;
	cout << "\nrow : " << board1D.getRow() << " , column : " << board1D.getColumn() << endl ;
	cout << "x_Ecell : " << board1D.getX_Ecell() << " , y_Ecell : " << board1D.getY_Ecell() << endl ;
	cout << "lastmove : " << board1D.lastMove() << endl ;
	cout << "number of moves : " << board1D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board1D.NumberOfBoards() << endl ;

	cout << "\n\n After BoardArray1D object moved down \n\n " ;
	board1D.move( 'D' ) ;
	board1D.print() ;
	cout << "\nrow : " << board1D.getRow() << " , column : " << board1D.getColumn() << endl ;
	cout << "x_Ecell : " << board1D.getX_Ecell() << " , y_Ecell : " << board1D.getY_Ecell() << endl ;
	cout << "lastmove : " << board1D.lastMove() << endl ;
	cout << "number of moves : " << board1D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board1D.NumberOfBoards() << endl ;

	cout << "\n\n After BoardArray1D object moved right \n\n " ;
	board1D.move( 'R' ) ;
	board1D.print() ;
	cout << "\nrow : " << board1D.getRow() << " , column : " << board1D.getColumn() << endl ;
	cout << "x_Ecell : " << board1D.getX_Ecell() << " , y_Ecell : " << board1D.getY_Ecell() << endl ;
	cout << "lastmove : " << board1D.lastMove() << endl ;
	cout << "number of moves : " << board1D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board1D.NumberOfBoards() << endl ;

	cout << "\n\n After BoardArray1D object moved up \n\n " ;
	board1D.move( 'U' ) ;
	board1D.print() ;
	cout << "\nrow : " << board1D.getRow() << " , column : " << board1D.getColumn() << endl ;
	cout << "x_Ecell : " << board1D.getX_Ecell() << " , y_Ecell : " << board1D.getY_Ecell() << endl ;
	cout << "lastmove : " << board1D.lastMove() << endl ;
	cout << "number of moves : " << board1D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board1D.NumberOfBoards() << endl ;

	fout.open( "txt_files/BoardArray1D_restore.txt" ) ;
	board1D.writeToFile( fout ) ;

	cout << "\n\n After BoardArray1D object written to file \n\n " ;
	board1D.print() ;
	cout << "\nrow : " << board1D.getRow() << " , column : " << board1D.getColumn() << endl ;
	cout << "x_Ecell : " << board1D.getX_Ecell() << " , y_Ecell : " << board1D.getY_Ecell() << endl ;
	cout << "lastmove : " << board1D.lastMove() << endl ;
	cout << "number of moves : " << board1D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board1D.NumberOfBoards() << endl ;

	board1D.reset() ;

	cout << "\n\n After BoardArray1D object reset \n\n " ;
	board1D.print() ;
	cout << "\nrow : " << board1D.getRow() << " , column : " << board1D.getColumn() << endl ;
	cout << "x_Ecell : " << board1D.getX_Ecell() << " , y_Ecell : " << board1D.getY_Ecell() << endl ;
	cout << "lastmove : " << board1D.lastMove() << endl ;
	cout << "number of moves : " << board1D.numberOfMoves() << endl ;
	cout << "number of Boards : " << board1D.NumberOfBoards() << endl ;

	fin.close() ;
	fout.close() ;

	cout << "\n\n*************************************************************************************************" ;
	cout << "\n\n TESTING for == operator between diffrent derived classes \n\n " ;
	cout << "\n\n*************************************************************************************************" ;
	
	fin.open( "txt_files/equal.txt" ) ;
	board1D.readFromFile( fin ) ;
	cout << "\n\n board1D \n\n" ;
	board1D.print() ;
	fin.close() ;

	fin.open( "txt_files/notEqual.txt" ) ;
	board2D.readFromFile( fin ) ;
	cout << "\n\n board2D \n\n" ;
	board2D.print() ;
	fin.close() ;

	fin.open( "txt_files/equal.txt" ) ;
	boardVector.readFromFile( fin ) ;
	cout << "\n\n boardVector \n\n" ;
	boardVector.print() ;
	fin.close() ;


	// for board1D and board2D
	if( board1D == board2D ) 
		cout << "\n\n board1D and board2D are equal \n\n" ;
	else
		cout << "\n\n board1D and board2D are not equal \n\n" ;

	// for board1D and boardVector
	if( board1D == boardVector )
		cout << "\n\n board1D and boardVector are equal \n\n" ;
	else
		cout << "\n\n board1D and boardVector are not equal \n\n" ;

	// for board2D and boardVector
	if( board2D == boardVector )
		cout << "\n\n board2D and boardVector are equal \n\n" ;
	else
		cout << "\n\n board2D and boardVector are not equal \n\n" ;


	cout << "\n\n*************************************************************************************************" ;
	cout << "\n\n TESTING for isSolved\n\n " ;
	cout << "\n\n*************************************************************************************************" ;

	// for board1D 
	if( board1D.isSolved() ) 
		cout << "\n\n board1D is solved \n\n" ;
	else
		cout << "\n\n board1D is not solved \n\n" ;

	// for board2D 
	if( board2D.isSolved() )
		cout << "\n\n board2D is solved \n\n" ;
	else
		cout << "\n\n board2D is not solved \n\n" ;

	// for boardVector
	if( boardVector.isSolved() )
		cout << "\n\n boardVector is solved \n\n" ;
	else
		cout << "\n\n boardVector is not solved \n\n" ;


	cout << "\n\n*************************************************************************************************" ;
	cout << "\n\n TESTING for setSize \n\n " ;
	cout << "\n\n*************************************************************************************************" ;

	cout << "\n\n After board1D  setsize \n\n" ;
	board1D.setSize(5,5) ;
	board1D.print() ;

	cout << "\n\n After board2D  setsize \n\n" ;
	board2D.setSize(3,7) ;
	board2D.print() ;

	cout << "\n\n After boardVector  setsize \n\n" ;
	boardVector.setSize(2,2) ;
	boardVector.print() ;

	// TESTING GLOBAL TEST FUNCTION

	cout << "\n\n*************************************************************************************************" ;
	cout << "\n\n TESTING for GLOBAL TEST FUNCTION \n\n " ;
	cout << "\n\n*************************************************************************************************" ;

	BoardArray1D board1D_1 ;
	BoardArray1D board1D_2 ;
	BoardArray2D board2D_3 ;
	BoardArray2D board2D_4 ;
	BoardVector boardVector_5 ;
	BoardVector boardVector_6 ;
	
	fin.open( "txt_files/test_global_function/test1.txt" ) ;
	board1D_1.readFromFile( fin ) ;
	fin.close() ;

	fin.open( "txt_files/test_global_function/test2.txt" ) ;
	board1D_2.readFromFile( fin ) ;
	fin.close() ;

	fin.open( "txt_files/test_global_function/test3.txt" ) ;
	board2D_3.readFromFile( fin ) ;
	fin.close() ;

	fin.open( "txt_files/test_global_function/test4.txt" ) ;
	board2D_4.readFromFile( fin ) ;
	fin.close() ;

	fin.open( "txt_files/test_global_function/test5.txt" ) ;
	boardVector_5.readFromFile( fin ) ;
	fin.close() ;

	fin.open( "txt_files/test_global_function/test6.txt" ) ;
	boardVector_6.readFromFile( fin ) ;
	fin.close() ;

	AbstractBoard* AbstractBoard_Array_test1[6] ;

	AbstractBoard_Array_test1[0] = &board1D_1 ;
	AbstractBoard_Array_test1[1] = &board1D_2 ;
	AbstractBoard_Array_test1[2] = &board2D_3 ;
	AbstractBoard_Array_test1[3] = &board2D_4 ;
	AbstractBoard_Array_test1[4] = &boardVector_5 ;
	AbstractBoard_Array_test1[5] = &boardVector_6 ;

	// test 1
	cout << "\n\n****************** Test 1 ********************************\n\n" ;
	for (int i = 0; i < 6; ++i)
	{	
		cout << "\n\n board " << i << "\n\n" ;
		AbstractBoard_Array_test1[i]->print() ;
	}

 	
	if( test( AbstractBoard_Array_test1, 6 ) )
		cout << "\n\n 1.test is valid\n\n" ;
	else
		cout << "\n\n 1.test is not valid\n\n" ;


	// test 2
	cout << "\n\n****************** Test 2 ********************************\n\n" ;
	AbstractBoard_Array_test1[5] = &boardVector_5 ;

	for (int i = 0; i < 6; ++i)
	{	
		cout << "\n\n board " << i << "\n\n" ;
		AbstractBoard_Array_test1[i]->print() ;
	}

	if( test( AbstractBoard_Array_test1, 6 ) )
		cout << "\n\n 2.test is valid\n\n" ;
	else
		cout << "\n\n 2.test is not valid\n\n" ;

	// test 3
	cout << "\n\n****************** Test 3 ********************************\n\n" ;
	AbstractBoard_Array_test1[5] = &boardVector_6 ;

	AbstractBoard_Array_test1[2] = &boardVector_5 ;

	for (int i = 0; i < 6; ++i)
	{	
		cout << "\n\n board " << i << "\n\n" ;
		AbstractBoard_Array_test1[i]->print() ;
	}

	if( test( AbstractBoard_Array_test1, 6 ) )
		cout << "\n\n 3.test is valid\n\n" ;
	else
		cout << "\n\n 3.test is not valid\n\n" ;


	// test 4
	cout << "\n\n****************** Test 4 ********************************\n\n" ;
	AbstractBoard_Array_test1[5] = &boardVector_6 ;

	AbstractBoard_Array_test1[2] = &board2D_3;

	for (int i = 0; i < 6; ++i)
	{	
		cout << "\n\n board " << i << "\n\n" ;
		AbstractBoard_Array_test1[i]->print() ;
	}

	if( test( AbstractBoard_Array_test1, 6 ) )
		cout << "\n\n 4.test is valid\n\n" ;
	else
		cout << "\n\n 4.test is not valid\n\n" ;

	// test 5
	cout << "\n\n****************** Test 5 ********************************\n\n" ;
	AbstractBoard_Array_test1[3] = &board2D_3;

	for (int i = 0; i < 6; ++i)
	{	
		cout << "\n\n board " << i << "\n\n" ;
		AbstractBoard_Array_test1[i]->print() ;
	}

	if( test( AbstractBoard_Array_test1, 6 ) )
		cout << "\n\n 5.test is valid\n\n" ;
	else
		cout << "\n\n 5.test is not valid\n\n" ;


	
}