#ifndef GTUIteratorConst_H
#define GTUIteratorConst_H
#include <memory>
#include "Node.h"

using namespace GTU_CSE241_2019_2020_HW6;

namespace GTU_CSE241_2019_2020_HW6{

	template<typename T >
	class GTUIteratorConst{
		
		public:
			GTUIteratorConst() ;
			GTUIteratorConst( const shared_ptr< Node<T> >  & new_CurrentPosition  ) ;

			const T& operator*() ;
			
			const T* operator->() ;

			const GTUIteratorConst<T>& operator=(const GTUIteratorConst & new_CurrentPosition ) ;
			bool operator==( const GTUIteratorConst &other ) ;
			bool operator!=( const GTUIteratorConst &other ) ;
			
			GTUIteratorConst<T> & operator++() ;
			GTUIteratorConst<T> operator++( int IgnoreMe ) ;
			
			GTUIteratorConst<T> & operator--() ;
			GTUIteratorConst<T> operator--( int IgnoreMe ) ;


		protected:
			shared_ptr< Node<T> > CurrentPosition;
	};
}
#endif