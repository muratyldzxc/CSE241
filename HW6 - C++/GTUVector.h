#ifndef GTUVector_H
#define GTUVector_H

#include "GTUContainer.h"
#include "bad_pafram.h"

using namespace std ; 

namespace GTU_CSE241_2019_2020_HW6{

	template<typename T>
	class GTUVector : public GTUContainer <T>
	{
		public:
			
			GTUVector() ;
			GTUVector( shared_ptr< Node<T> > new_KeepData ) ;
			GTUVector( const GTUVector<T>  &other ) ;
			GTUVector<T> operator=( const GTUVector<T> &other ) ;

			T& operator[]( int get ) ;
			const T& operator[]( int get ) const ;

			bool empty() const override;
			int size() const override ;
			int max_size() const override ;
			GTUIterator <T> insert ( const T& new_element ) override ;
			GTUIterator <T> erase( const GTUIterator<T> & erase_iter ) override ;	
			void clear() override ;
			GTUIterator <T>  begin() override ;
			GTUIterator <T>  end() override ;

			~GTUVector() ;

			
		private :
			shared_ptr< Node<T> > KeepData ;
			shared_ptr< Node<T> > EndOfData ;
			int _size ;
			const int _max_size = 2000 ;
			
			
	};
}
#endif