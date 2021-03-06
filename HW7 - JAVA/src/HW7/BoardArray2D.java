package HW7;

/**
 * @author murat
 * @since 15.01.2020
 *
 */

/**
 * A class which to represent NPuzzle problem.It keeps data as two dimensional integer array.
 * @see AbstractBoard
 */
public class BoardArray2D extends AbstractBoard {
	/** 
	 * Keep data in two dimensional integer array.
	 */
	private int [][] board ;
	
	/** 
	 * Initialize fields
	 * <p> Calls AbstractBoard() as a  super class constructor
	 * @see AbstractBoard#AbstractBoard()
	 */
	public BoardArray2D(){
		super() ;	
	}
	

	@Override
	public void setSize( int newRow, int newColumn ) {
		
		if( board != null && !( newRow == row && newColumn == column) ) {	

			board = null ;
			System.gc();
		}
		
		if( newRow < 3 || newColumn < 3 ){ // set as default
			
			row = 3 ;
			column = 3 ;
			board = new int [row][column] ;

		}
		else if( newRow != row || newColumn != column ){

			row = newRow ;
			column = newColumn ;
			board = new int [row][column] ;
		}
		
		super.reset() ;
	}

	@Override
	public int cell(int rowIndex, int columnIndex) {
		
		return board[rowIndex][columnIndex] ;
	}

	@Override
	public void setCell(int rowIndex, int columnIndex, int setValue) {
		
		board[rowIndex][columnIndex] = setValue ;
	}
	
	
}
