package HW7;

/**
 * @author murat
 * @since 15.01.2020
 *
 */
/**
 * A class which to represent NPuzzle problem.It keeps data as one dimensional integer array.
 * @see AbstractBoard
 */
public class BoardArray1D extends AbstractBoard {
	/** 
	 * Keep data in one dimensional integer array.
	 */
	private int [] board ;
	/** 
	 * Initialize fields
	 * <p> Calls AbstractBoard() as a  super class constructor
	 * @see AbstractBoard#AbstractBoard()
	 */
	public BoardArray1D(){
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
			board = new int [row * column] ;

		}
		else if( newRow != row || newColumn != column ){

			row = newRow ;
			column = newColumn ;
			board = new int [row * column] ;
		}
		
		super.reset() ;
	}

	public int cell(int rowIndex, int columnIndex) {
		
		return board[(rowIndex * column) + columnIndex] ;
	}

	
	public void setCell(int rowIndex, int columnIndex, int setValue) {
		
		board[(rowIndex * column) + columnIndex] = setValue ;
	}
}
