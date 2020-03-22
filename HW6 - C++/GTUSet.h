#ifndef GTUSet_H
#define GTUSet_H

#include "GTUContainer.h"
#include "bad_pafram.h"

using namespace std ; 

namespace GTU_CSE241_2019_2020_HW6{

	template<typename T>
	class GTUSet : public GTUContainer <T>
	{
		public:
			
			GTUSet() ;
			GTUSet( shared_ptr< Node<T> > new_KeepData ) ;
			GTUSet( const GTUSet<T>  &other ) ;
			GTUSet<T> operator=( const GTUSet<T> &other ) ;

			bool empty() const override;
			int size() const override ;
			int max_size() const override ;
			GTUIterator <T> insert ( const T& new_element ) override ;
			GTUIterator <T> erase( const GTUIterator<T> & erase_iter ) override ;	
			void clear() override ;
			GTUIterator <T>  begin() override ;
			GTUIterator <T>  end() override ;

			~GTUSet() ;

			
		private :
			shared_ptr< Node<T> > KeepData ;
			shared_ptr< Node<T> > EndOfData ;
			int _size ;
			const int _max_size = 2000 ;
			
			
	};
}
#endif