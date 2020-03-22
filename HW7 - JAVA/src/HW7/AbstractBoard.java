
package HW7;
import java.io.*;
/**
 * @author murat
 * @since 15.01.2020
 *
 */

/**
 * A class which helping subclasses to represent NPuzzle problem 
 *
 */
public abstract class AbstractBoard {
		/**
		 * Holds how many Board object created
		 * <p> It's initial value is zero
		 */
		public static int CountOfBoards = 0 ; 
		/**
		 * Holds row size of the board 
		 * <p> It's initial value is zero
		 */
        protected int row ;
        /**
		 * Holds column size of the board
		 * <p> It's initial value is zero
		 */
        protected int column ; 
        /**
         * Holds last move of the board
         * <p> It's initial value is 'S'
         */
        protected char prevMove ;
        /**
         * Holds how many move done by the user in that board
         * <p> It's initial value is zero
         */
        protected int Count_DoneMove ; 
        /**
         * Holds empty cell x axis coordinate
         * <p> It's initial value is zero
         */
        protected int x_Ecell ;
        /**
         * Holds empty cell y axis coordinate
         * <p> It's initial value is zero
         */
        protected int y_Ecell ; 
        
        /**
         * Initialize fields of AbstractBoard class
         * <p> Initialize {@link #row} as 0
         * <p> Initialize {@link #column} as 0
         * <p> Initialize {@link #prevMove} as S
         * <p> Initialize {@link #Count_DoneMove} as 0
         * <p> Initialize {@link #x_Ecell} as 0
         * <p> Initialize {@link #y_Ecell} as 0
         * <p> Increments {@link #CountOfBoards} by 1
         */
        public AbstractBoard() {
    		
			this.row = 0;
			this.column = 0;
			this.prevMove = 'S';
			this.Count_DoneMove = 0 ;
			this.x_Ecell = 0;
			this.y_Ecell = 0;
			
			CountOfBoards ++ ;
		}

        /**
         * Returns row size of the board
         * @return row size of the board
         */
		public int getRow() {
			return row;
		}
		/**
		 * Set the given row as row size of the board 
		 * @param row New row size of the board
		 */
		public void setRow(int row) {
			this.row = row;
		}
		/**
		 * Returns column size of the board
		 * @return column size of the board
		 */
		public int getColumn() {
			return column;
		}
		/**
		 * Set the given column as row size of the board 
		 * @param column New column size of the board
		 */
		public void setColumn(int column) {
			this.column = column;
		}
		/**
         * Returns last move of the board
         * @return last move of the board
         */
		public char getPrevMove() {
			return prevMove;
		}
		/**
		 * Set the given prevMove as last move of the board 
		 * @param prevMove New prevMove of the board
		 */
		public void setPrevMove(char prevMove) {
			this.prevMove = prevMove;
		}
		/**
		 * Returns Number of moves done by user in that board
         * @return Number of moves done by user in that board
         */
		public int getCount_DoneMove() {
			return Count_DoneMove;
		}
		/**
		 * Set the given Count_DoneMove as Number of moves done by user in that board 
		 * @param Count_DoneMove New Number of moves done by user of the board
		 */
		public void setCount_DoneMove(int Count_DoneMove) {
			this.Count_DoneMove = Count_DoneMove;
		}
		/**
         * Returns x axis coordinate of the board
         * @return x axis coordinate of the board
         */
		public int getX_Ecell() {
			return x_Ecell;
		}
		/**
		 * Set the given x axis coordinate as x axis coordinate of the board
		 * @param x_Ecell New x axis coordinate of the empty cell
		 */
		protected void setX_Ecell(int x_Ecell) {
			this.x_Ecell = x_Ecell;
		}
		/**
         * Returns y axis coordinate of the board
         * @return y axis coordinate of the board
         */
		public int getY_Ecell() {
			return y_Ecell;
		}
		/**
		 * Set the given x axis coordinate as x axis coordinate of the board
		 * @param y_Ecell New y axis coordinate of the empty cell
		 */
		protected void setY_Ecell(int y_Ecell) {
			this.y_Ecell = y_Ecell;
		}

		
		/**
		 * Returns Board representation as a String
		 * @return Board representation as a String
		 */
		public String toString() {
			
			String Output = new String();
			
			for ( int i = 0; i < row; ++i ){
			    for ( int j = 0; j < column; ++j ){

			        if( cell(i, j) == -1 ){
			            Output += "\t" ;
			            Output += "bb" ;
			        }
			        else if( cell(i, j) == - 2 ){
			        	Output += "\t" ;
			        	Output += "00" ;
			           
			        } 
			        
			        else if( 0 < cell(i, j) && cell(i, j) < 10){
			        	Output += "\t" ;
			        	Output += "0" ;
			        	Output += cell(i, j) ;
			        }
			           
			        else{
			        	Output += "\t" ;
			        	Output += cell(i, j) ;

			        }
			            
			    }
			    Output += "\n" ;
		    }
			
			return Output ;
		}
		/**
		 * Reads board configuration from file
		 * @param file The file that will be opened and read from it
		 * @throws IOException If it can not open the file as given
		 */
		public void readFromFile( File file ) throws IOException {
			String dataValue = new String() ;
			
			FileReader fileInputStream = null ;
			try
			{
				fileInputStream = new FileReader( file ) ;
			}
			catch( IOException exception ) {
				
					System.out.println(" The file can not be opened") ;
			}
			
			int newRow = 1 ;
			int newColumn = 1 ;
			
			int data ;
			do{
				data = fileInputStream.read() ;
				if( (char) data == '\n' ) {
					newRow ++ ;
					newColumn ++ ;
				}
				else if( (char) data == ' ' )
					newColumn ++ ;
				
			}while( data != -1);
			
			newColumn = newColumn/newRow ;
			
			this.setSize(newRow, newColumn);
			
			try
			{
				fileInputStream = new FileReader( file ) ;
			}
			catch( IOException exception ) {
				
					System.out.println(" The file can not be opened") ;
			}
			
			for(int i = 0; i < row; i++) {
				for(int j = 0; j < column; j++) {
					
					dataValue += (char)fileInputStream.read();
					dataValue += (char)fileInputStream.read();
					
	                if( dataValue.equals("bb") ){
	                	
	                    setCell( i, j, -1 ) ;
	                    setX_Ecell( j ) ;
	                    setY_Ecell( i ) ;
	                    
	                }
	                else if( Integer.parseInt( dataValue ) == 0 ){
	
	                	setCell( i, j, -2 ) ;
	                }
	                    
	                else{ 
	                	setCell( i, j, Integer.parseInt( dataValue ) ) ;
	                }
	                dataValue = "" ;
	                fileInputStream.skip(1) ;
				}
			}
			fileInputStream.close() ;
			
		}
		/**
		 * Write board configuration to file
		 * @param file The file that will be opened and write to it
		 * @throws IOException If it can not open the file as given
		 */
		public void writeToFile( File file ) throws IOException {
			
			FileWriter fileOutputStream = null ;
			
			try
			{
				fileOutputStream = new FileWriter( file ) ;
			}
			catch( IOException exception ) {
				
					System.out.println(" The file can not be opened") ;
			}
			
			String Output = new String();
			
			for ( int i = 0; i < row; ++i ){
			    for ( int j = 0; j < column; ++j ){
			    	
			    	if( j != 0)
		        		Output += " " ;
			    	
			        if( cell(i, j) == -1 )
			            Output += "bb" ;
			        else if( cell(i, j) == - 2 )
			        	Output += "00" ;
			        
			        else if( 0 < cell(i, j) && cell(i, j) < 10){
			        	Output += "0" ;
			        	Output += cell(i, j) ;
			        }   
			        else
			        	Output += cell(i, j) ;			            
			    }
			    if( i != row - 1 )
			    	Output += "\n" ;
		    }
			
			fileOutputStream.write( Output ) ;
			fileOutputStream.close() ;
		}
		/**
		 * Resets the board configuration
		 */
		public void reset() {
			int value = 1 ;

		    for ( int i = 0; i < row; i++ ){ // build a final board
		        for ( int j = 0; j < column; j++ ){

		            if( cell(i, j) != -2 ){

		                setCell(i, j, value) ;
		                value ++ ;
		            }
		            else 
		            	setCell(i, j, -2 ) ;            
		        }
		    }
		    
		    setCell( row - 1, column - 1, -1 ) ; 
		    prevMove = 'S' ;
		    Count_DoneMove = 0 ;
		    y_Ecell = row - 1 ;
		    x_Ecell = column - 1 ;
		}
		/**
		 * It moves the empty cell ( up, down, left, right )
		 * @param option To decide which way to go ( up, down, left, right )
		 * @return If option is valid and it's move is valid returns true , otherwise returns false
		 */
		public boolean move( char option) {
			int temp_x, temp_y ;
		    boolean valid = false ;
		    temp_x = x_Ecell ;  
		    temp_y = y_Ecell ;

		    switch( option ){

		         case 'L' :         // LEFT
		            if( 0 <= ( x_Ecell - 1 ) && cell( y_Ecell, x_Ecell - 1 ) != -2 ){    
		                x_Ecell -- ;
		                Count_DoneMove ++ ;
		                prevMove = 'L' ;
		                valid = true ;
		            }
		            break ;

		        case 'R' :          // RIGHT
		            if( ( x_Ecell + 1 ) < column && cell( y_Ecell, x_Ecell + 1 ) != -2 ){
		                x_Ecell ++ ;
		                Count_DoneMove ++ ;
		                prevMove = 'R' ;
		                valid = true ;
		            }
		            break ;

		        case 'U' :          // UP
		            if( 0 <= ( y_Ecell -1 ) && cell( y_Ecell-1, x_Ecell ) != -2 ){
		                y_Ecell -- ;
		                Count_DoneMove ++ ;
		                prevMove = 'U' ;
		                valid = true ;
		            }
		            break ;

		        case 'D' :          // DOWN
		            if( ( y_Ecell + 1 ) < row && cell( y_Ecell+1, x_Ecell ) != -2 ){
		                y_Ecell ++ ;
		                Count_DoneMove ++ ;
		                prevMove = 'D' ;
		                valid = true ;
		            }
		            break ;
		    }
		    setCell( temp_y, temp_x, cell( y_Ecell, x_Ecell ) ) ;
		    setCell( y_Ecell, x_Ecell, -1 ) ;
		    
		    return valid ;
		}
		/**
		 * Check the board if it is solved or not
		 * <p>If the board is solved it returns 1 , otherwise returns 0
		 * @return If the board is solved it returns true , otherwise returns false
		 */
		public boolean isSolved() {
			boolean same = true ;
		    int [][] finalBoard ;
		    int value = 1 ;

		    finalBoard = new int [row][column] ;

		    for ( int i = 0; i < row; i++ ){ // build a final board
		        for ( int j = 0; j < column; j++ ){
		        	
		            if( cell(i, j) != -2 ){
		                finalBoard [ i ][ j ] = value ;
		                value ++ ;
		            }
		            else 
		                finalBoard [ i ][ j ] = -2 ;

		        }
		    }

		    finalBoard [ row - 1 ][ column - 1 ] = -1 ;

		    for ( int i = 0; i < row; i++ ){ // compare final board and current board
		        for ( int j = 0; j < column; j++ ){
		            
		            if( finalBoard[ i ][ j ] != cell(i, j) ){ // if doesnt match end the loop
		                same = false ;
		                i = row ;
		                j = column ;
		            }
		        }
		    }
		    return same ;
			
		}
		/** If two board configuration are the same it returns 1, otherwise returns 0.
		 * <p> It does not compare last move , number of moves done by user
		 * @param other Other board that will compared to
		 * @return If two board configuration are the same it returns true, otherwise returns false.
		 * It does not compare last move and number of moves done by user
		 */
		public boolean Equals( AbstractBoard other ) {
			boolean same = true ;
			// return false if bounderies are not equal
			if( !(this.row == other.row && this.column == other.column) )
				return false ;
			
		    for (int i = 0; i < row ; ++i){
		        for (int j = 0; j < column ; ++j){

		            if( this.cell(i, j) != other.cell( i , j ) )
		                same = false ;
		        }
		    }

		    return same ;
		}
		/**
		 * Returns number of boards created so far
		 * @return number of boards created so far
		 */
		public static int NumberOfBoards() {
			return CountOfBoards ;
		}
		/**
		 * Returns last move done by user
		 * @return last move done by user
		 */
		public char lastMove() {
			return prevMove ;
		}
		/**
		 * Returns number of moves done by user
		 * @return number of moves done by user
		 */
		public int numberOfMoves() {
			return Count_DoneMove ;
		}
		
		/**
		 * Set row size of the board and column size of the board as given parameters and allocate space for board configuration
		 * @param newRow To set row size of the board
		 * @param newColumn To set column size of the board
		 */
		public abstract void setSize( int newRow, int newColumn) ;
		/**
		 * Returns value in indexed position 
		 * @param rowIndex For reaching indexed position
		 * @param columnIndex For reaching indexed position
		 * @return indexed value
		 */
		public abstract int cell( int rowIndex, int columnIndex ) ;
		/**
		 * Sets indexed position with setValue
		 * @param rowIndex For reaching indexed position
		 * @param columnIndex For reaching indexed position
		 * @param setValue Value to be set to indexed position
		 */
		public abstract void setCell( int rowIndex, int columnIndex, int setValue ) ;
		
}
