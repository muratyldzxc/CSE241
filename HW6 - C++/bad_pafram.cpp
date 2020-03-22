#include "bad_pafram.h"

using namespace std ;

namespace std {
	bad_pafram::bad_pafram( const string & new_error_message ) : error_message( new_error_message ){

	}
	void bad_pafram::print_error_message()const {

		cout << "\n\n" << error_message << "\n\n" ;
	}
}