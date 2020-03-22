#ifndef GTUIterator_H
#define GTUIterator_H
#include <memory>
#include "Node.h"

using namespace GTU_CSE241_2019_2020_HW6;

namespace GTU_CSE241_2019_2020_HW6{

	template<typename T >
	class GTUIterator{
		
		public:
			GTUIterator() ;
			GTUIterator( const shared_ptr< Node<T> >  & new_CurrentPosition  ) ;

			T& operator*() ;
			
			T* operator->() ;
			const GTUIterator<T>& operator=(const GTUIterator & new_CurrentPosition ) ;
			bool operator==( const GTUIterator &other ) ;
			bool operator!=( const GTUIterator &other ) ;
			
			GTUIterator<T> & operator++() ;
			GTUIterator<T> operator++( int IgnoreMe ) ;
			
			GTUIterator<T> & operator--() ;
			GTUIterator<T> operator--( int IgnoreMe ) ;


		protected:
			shared_ptr< Node<T> > CurrentPosition;
	};
}
#endif