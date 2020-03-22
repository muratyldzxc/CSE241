import HW7.*;
import java.io.*;

/**
 * @author murat
 * @since 15.01.2020
 *
 */

/**
 * To test  {@link AbstractBoard} , {@link BoardArray1D}, {@link BoardArray2D}
 * @see {@link AbstractBoard} , {@link BoardArray1D}, {@link BoardArray2D}
 */

public class DriverClass {
	/**
	 * Takes AbstractBoard reference array and test it whether is a solution sequence or not
	 * @param AbstractBoard_Array Takes AbstractBoard reference array which will be tested 
	 * @param size Takes size of AbstractBoard reference array
	 * @return If it is a valid sequence it returns true , otherwise returns false 
	 */
	public static boolean test( AbstractBoard AbstractBoard_Array[], int size ){

		int old_x_Ecell, old_y_Ecell, new_x_Ecell, new_y_Ecell ;

		old_x_Ecell = AbstractBoard_Array[0].getX_Ecell() ;
		old_y_Ecell = AbstractBoard_Array[0].getY_Ecell() ;
		new_x_Ecell = AbstractBoard_Array[1].getX_Ecell() ;
		new_y_Ecell = AbstractBoard_Array[1].getY_Ecell() ;

		if( AbstractBoard_Array[ size - 1 ].isSolved() ){ // if the final board is a solution
			
			for (int i = 1; i < size - 1 ; ++i){

				if( old_x_Ecell != new_x_Ecell || old_y_Ecell != new_y_Ecell ){ // if prevBoard  and afterBoard empty cell cordinates are not the same

					for (int row = 0; row < AbstractBoard_Array[0].getRow(); ++row){ 
					
						for (int column = 0; column < AbstractBoard_Array[0].getColumn(); ++column)
						{	// checks are the two board same
							if( AbstractBoard_Array[ i-1 ].cell( row, column ) != AbstractBoard_Array[ i ].cell( row, column ) ){ 
								
								if ( AbstractBoard_Array[ i-1 ].cell( row, column ) != AbstractBoard_Array[ i ].cell( new_y_Ecell, new_x_Ecell ) 
									&& AbstractBoard_Array[ i-1 ].cell( row, column ) != AbstractBoard_Array[ i ].cell( old_y_Ecell, old_x_Ecell ) )
								{
									System.out.printf("\n\n distance between board %d board %d more than one move"
											+ "  , the sequence corrupted \n\n", i, i+1 ) ;
									return false ;
								}	
							}
						}
					}		
				}
				else{
					System.out.printf("\n\n board %d board %d are same boards , the sequence corrupted \n\n", i, i+1 ) ;
					return false ;
				}

				old_x_Ecell = AbstractBoard_Array[i].getX_Ecell() ;
				old_y_Ecell = AbstractBoard_Array[i].getY_Ecell() ;

				new_x_Ecell = AbstractBoard_Array[i+1].getX_Ecell() ;
				new_y_Ecell = AbstractBoard_Array[i+1].getY_Ecell() ;

			}
				
		}
		else{
			System.out.printf("\n\n it is not solved because last board is not a solution\n\n" ) ;
			return false ;
		}	

		return true ;
	}
	/**
	 * To test  {@link AbstractBoard} , {@link BoardArray1D}, {@link BoardArray2D}
	 * @param args Command line argument
	 * @throws IOException Throws exception if an invalid entry given
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		System.out.printf("\n\n Before calling any constructor number of Boards : %d", BoardArray2D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		System.out.printf( "\n\n TESTING BoardArray2D functions " ) ;
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		
		BoardArray2D board2D = new BoardArray2D() ;
		
		//after constructor called
		
		System.out.printf( "\n\n After BoardArray2D constructor called \n\n There is no board configration yet.\n" ) ;
		System.out.println( board2D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board2D.getRow(), board2D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board2D.getX_Ecell(), board2D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board2D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board2D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray2D.NumberOfBoards() ) ;
		
		File readFile = new File("txt_files//BoardArray2D_test.txt") ;
		board2D.readFromFile( readFile );
		
		System.out.printf( "\n\n After BoardArray2D object readed from BoardArray2D_test.txt file \n\n " ) ;
		System.out.println( board2D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board2D.getRow(), board2D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board2D.getX_Ecell(), board2D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board2D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board2D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray2D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n After BoardArray2D object moved up \n\n ") ;
		board2D.move( 'U' ) ;
		System.out.println( board2D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board2D.getRow(), board2D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board2D.getX_Ecell(), board2D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board2D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board2D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray2D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n After BoardArray2D object moved left \n\n " ) ;
		board2D.move( 'L' ) ;
		System.out.println( board2D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board2D.getRow(), board2D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board2D.getX_Ecell(), board2D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board2D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board2D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray2D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n After BoardArray2D object moved down \n\n " ) ;
		board2D.move( 'D' ) ;
		System.out.println( board2D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board2D.getRow(), board2D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board2D.getX_Ecell(), board2D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board2D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board2D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray2D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n After BoardArray2D object moved right \n\n " ) ;
		board2D.move( 'R' ) ;
		System.out.println( board2D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board2D.getRow(), board2D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board2D.getX_Ecell(), board2D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board2D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board2D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray2D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n After BoardArray2D object moved up \n\n ") ;
		board2D.move( 'U' ) ;
		System.out.println( board2D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board2D.getRow(), board2D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board2D.getX_Ecell(), board2D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board2D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board2D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray2D.NumberOfBoards() ) ;
		
		File writeFile = new File("txt_files//BoardArray2D_restore.txt") ;
		board2D.writeToFile( writeFile );
		
		System.out.printf( "\n\n After BoardArray2D object written to file BoardArray2D_restore.txt \n\n " ) ;
		System.out.println( board2D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board2D.getRow(), board2D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board2D.getX_Ecell(), board2D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board2D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board2D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray2D.NumberOfBoards() ) ;
		
		board2D.reset();
		
		System.out.printf( "\n\n After BoardArray2D object reset \n\n " ) ;
		System.out.println( board2D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board2D.getRow(), board2D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board2D.getX_Ecell(), board2D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board2D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board2D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray2D.NumberOfBoards() ) ;
		
		
		
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		System.out.printf( "\n\n TESTING BoardArray1D functions " ) ;
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		
		BoardArray1D board1D = new BoardArray1D() ;
		
		//after constructor called
		
		System.out.printf( "\n\n After BoardArray1D constructor called \n\n There is no board configration yet.\n" ) ;
		System.out.println( board1D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board1D.getRow(), board1D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board1D.getX_Ecell(), board1D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board1D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board1D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray1D.NumberOfBoards() ) ;
		
		readFile = new File("txt_files//BoardArray1D_test.txt") ;
		board1D.readFromFile( readFile );
		
		System.out.printf( "\n\n After BoardArray1D object readed from BoardArray1D_test.txt file \n\n " ) ;
		System.out.println( board1D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board1D.getRow(), board1D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board1D.getX_Ecell(), board1D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board1D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board1D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray1D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n After BoardArray1D object moved up \n\n ") ;
		board1D.move( 'U' ) ;
		System.out.println( board1D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board1D.getRow(), board1D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board1D.getX_Ecell(), board1D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board1D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board1D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray1D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n After BoardArray1D object moved left \n\n " ) ;
		board1D.move( 'L' ) ;
		System.out.println( board1D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board1D.getRow(), board1D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board1D.getX_Ecell(), board1D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board1D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board1D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray1D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n After BoardArray1D object moved down \n\n " ) ;
		board1D.move( 'D' ) ;
		System.out.println( board1D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board1D.getRow(), board1D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board1D.getX_Ecell(), board1D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board1D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board1D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray1D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n After BoardArray1D object moved right \n\n " ) ;
		board1D.move( 'R' ) ;
		System.out.println( board1D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board1D.getRow(), board1D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board1D.getX_Ecell(), board1D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board1D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board1D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray1D.NumberOfBoards() ) ;
		
		System.out.printf( "\n\n After BoardArray1D object moved up \n\n ") ;
		board1D.move( 'U' ) ;
		System.out.println( board1D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board1D.getRow(), board1D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board1D.getX_Ecell(), board1D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board1D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board1D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray1D.NumberOfBoards() ) ;
		
		writeFile = new File("txt_files//BoardArray1D_restore.txt") ;
		board1D.writeToFile( writeFile );
		
		System.out.printf( "\n\n After BoardArray1D object written to file BoardArray1D_restore.txt \n\n " ) ;
		System.out.println( board1D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board1D.getRow(), board1D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board1D.getX_Ecell(), board1D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board1D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board1D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray1D.NumberOfBoards() ) ;
		
		board1D.reset();
		
		System.out.printf( "\n\n After BoardArray1D object reset \n\n " ) ;
		System.out.println( board1D ) ;
		System.out.printf( "\n row: %d , column: %d \n", board1D.getRow(), board1D.getColumn() ) ;
		System.out.printf( " x_Ecell : %d , y_Ecell : %d \n", board1D.getX_Ecell(), board1D.getY_Ecell() ) ;
		System.out.printf( " last move : %c \n", board1D.lastMove() ) ;
		System.out.printf( " number of moves : %d \n", board1D.numberOfMoves() ) ;
		System.out.printf( " number of boards : %d \n", BoardArray1D.NumberOfBoards() ) ;
		
		// End of tested BoardArray1D
		
		
		
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		System.out.printf( "\n\n TESTING for Equals() function between diffrent derived classes \n\n " ) ;
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		
		// both of them read from equal.txt
		readFile = new File("txt_files//equal.txt") ;
		board2D.readFromFile(readFile);
		board1D.readFromFile(readFile);
		
		System.out.printf( "\n Board2D \n%s", board2D.toString() ) ;
		System.out.printf( "\n Board1D \n%s", board1D.toString() ) ;
		
		if( board2D.Equals( board1D ) )
			System.out.printf( "\n\n board1D and board2D are equal \n\n" ) ;
		else
			System.out.printf( "\n\n board1D and board2D are not equal \n\n" ) ;
		
		// one of them readed from equal.txt , one of them read from notEqual.txt
		readFile = new File("txt_files//notEqual.txt") ;
		board2D.readFromFile(readFile);
		
		System.out.printf( "\n Board2D \n%s", board2D.toString() ) ;
		System.out.printf( "\n Board1D \n%s", board1D.toString() ) ;
		
		if( board2D.Equals( board1D ) )
			System.out.printf( "\n\n board1D and board2D are equal \n\n" ) ;
		else
			System.out.printf( "\n\n board1D and board2D are not equal \n\n" ) ;
		
		
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		System.out.printf( "\n\n TESTING for isSolved() function for diffrent derived classes \n\n " ) ;
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		
		System.out.printf( "\n Board2D \n%s", board2D.toString() ) ;
		// for board2D it readed from equal.txt that has a solution board in it
		if( board2D.isSolved() )
			System.out.printf( "\n\n board2D is solved \n\n" ) ;
		else
			System.out.printf( "\n\n board2D is not solved \n\n" ) ;
		
		System.out.printf( "\n Board1D \n%s", board1D.toString() ) ;
		// for board2D it readed from notEqual.txt that has no solution board in it
		if( board1D.isSolved() )
			System.out.printf( "\n\n board1D is solved \n\n" ) ;
		else
			System.out.printf( "\n\n board1D is not solved \n\n" ) ;
		
		
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		System.out.printf( "\n\n TESTING for setSize() function for 3 cases ( to make a bigger puzzle, smaller puzzle and smaller than 3*3 \n\n " ) ;
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		
		// for board1D
		System.out.printf( "\n\n After board1D setSized 3*3 to 5*5 \n\n" ) ;
		board1D.setSize(5, 5);
		System.out.printf( "\n Board1D \n%s", board2D.toString() ) ;
		
		System.out.printf( "\n\n After board1D setSized 5*5 to 2*2 \n\n" ) ;
		board1D.setSize(2, 2);
		System.out.printf( "\n Board1D \n%s", board2D.toString() ) ;
		
		System.out.printf( "\n\n After board1D setSized 2*2 to 3*7 \n\n" ) ;
		board1D.setSize(3, 7);
		System.out.printf( "\n Board1D \n%s", board2D.toString() ) ;
		
		// for board2D
		System.out.printf( "\n\n After board2D setSized 3*3 to 5*5 \n\n" ) ;
		board2D.setSize(5, 5);
		System.out.printf( "\n board2D \n%s", board2D.toString() ) ;
		
		System.out.printf( "\n\n After board2D setSized 5*5 to 2*2 \n\n" ) ;
		board2D.setSize(2, 2);
		System.out.printf( "\n board2D \n%s", board2D.toString() ) ;
		
		System.out.printf( "\n\n After board2D setSized 2*2 to 3*7 \n\n" ) ;
		board2D.setSize(3, 7);
		System.out.printf( "\n board2D \n%s", board2D.toString() ) ;
		
		
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		System.out.printf( "\n\n TESTING for GLOBAL TEST FUNCTION \n\n " ) ;
		System.out.printf( "\n\n*************************************************************************************************" ) ;
		
		AbstractBoard AbstractBoardArray_test1[] = new AbstractBoard [6] ;
		
		BoardArray1D board1D_1 = new BoardArray1D() ;
		BoardArray1D board1D_2 = new BoardArray1D() ;
		BoardArray1D board1D_3 = new BoardArray1D() ;
		BoardArray2D board2D_4 = new BoardArray2D() ;
		BoardArray2D board2D_5 = new BoardArray2D() ;
		BoardArray2D board2D_6 = new BoardArray2D() ;
		
		readFile = new File("txt_files//test_global_function//test1.txt");
		board1D_1.readFromFile(readFile);
		
		readFile = new File("txt_files//test_global_function//test2.txt");
		board1D_2.readFromFile(readFile);
		
		readFile = new File("txt_files//test_global_function//test3.txt");
		board1D_3.readFromFile(readFile);
		
		readFile = new File("txt_files//test_global_function//test4.txt");
		board2D_4.readFromFile(readFile);
		
		readFile = new File("txt_files//test_global_function//test5.txt");
		board2D_5.readFromFile(readFile);
		
		readFile = new File("txt_files//test_global_function//test6.txt");
		board2D_6.readFromFile(readFile);
		
		AbstractBoardArray_test1[0] = board1D_1 ;
		AbstractBoardArray_test1[1] = board1D_2 ;
		AbstractBoardArray_test1[2] = board1D_3 ;
		AbstractBoardArray_test1[3] = board2D_4 ;
		AbstractBoardArray_test1[4] = board2D_5 ;
		AbstractBoardArray_test1[5] = board2D_6 ;
		
		// test 1
		System.out.printf( "\n\n****************** Test 1 ********************************\n\n" ) ;
		
		for (int i = 0; i < 6; ++i) {
			System.out.printf( "\n\n board %d\n\n %s", i+1, AbstractBoardArray_test1[i]  ) ;
		}
		
		if( test( AbstractBoardArray_test1, 6 ) )
			System.out.printf( "\n\n 1.test is valid\n\n" ) ;
		else
			System.out.printf( "\n\n 1.test is not valid\n\n" ) ;
		
		// test 2
		AbstractBoardArray_test1[5] = board2D_5 ;
		System.out.printf( "\n\n****************** Test 2 ********************************\n\n" ) ;
		
		for (int i = 0; i < 6; ++i) {
			System.out.printf( "\n\n board %d\n\n %s", i+1, AbstractBoardArray_test1[i]  ) ;
		}
		
		if( test( AbstractBoardArray_test1, 6 ) )
			System.out.printf( "\n\n 2.test is valid\n\n" ) ;
		else
			System.out.printf( "\n\n 2.test is not valid\n\n" ) ;
		
		// test 3
		AbstractBoardArray_test1[5] = board2D_6 ;
		AbstractBoardArray_test1[2] = board2D_5 ;
		System.out.printf( "\n\n****************** Test 3 ********************************\n\n" ) ;
		
		for (int i = 0; i < 6; ++i) {
			System.out.printf( "\n\n board %d\n\n %s", i+1, AbstractBoardArray_test1[i]  ) ;
		}
		
		if( test( AbstractBoardArray_test1, 6 ) )
			System.out.printf( "\n\n 3.test is valid\n\n" ) ;
		else
			System.out.printf( "\n\n 3.test is not valid\n\n" ) ;
		
		// test 4
		AbstractBoardArray_test1[2] = board1D_3 ;
		System.out.printf( "\n\n****************** Test 4 ********************************\n\n" ) ;
		
		for (int i = 0; i < 6; ++i) {
			System.out.printf( "\n\n board %d\n\n %s", i+1, AbstractBoardArray_test1[i]  ) ;
		}
		
		if( test( AbstractBoardArray_test1, 6 ) )
			System.out.printf( "\n\n 4.test is valid\n\n" ) ;
		else
			System.out.printf( "\n\n 4.test is not valid\n\n" ) ;
		
		// test 5
		AbstractBoardArray_test1[3] = board1D_3 ;
		System.out.printf( "\n\n****************** Test 5 ********************************\n\n" ) ;
		
		for (int i = 0; i < 6; ++i) {
			System.out.printf( "\n\n board %d\n\n %s", i+1, AbstractBoardArray_test1[i]  ) ;
		}
		
		if( test( AbstractBoardArray_test1, 6 ) )
			System.out.printf( "\n\n 5.test is valid\n\n" ) ;
		else
			System.out.printf( "\n\n 5.test is not valid\n\n" ) ;
	}
	
	
	
}
