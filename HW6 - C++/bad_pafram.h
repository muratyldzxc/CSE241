#ifndef BAD_PAFRAM_H
#define BAD_PAFRAM_H 

#include <string>
#include <iostream>

using namespace std ;
namespace std {
	class bad_pafram
	{
		public:
			bad_pafram( const string & new_error_message ) ;
			void print_error_message()const ;
		private:
			string error_message ;
	};
}

#endif