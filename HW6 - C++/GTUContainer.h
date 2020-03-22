#ifndef GTUContainer_H
#define GTUContainer_H

#include "GTUIterator.h"
#include "GTUIterator.cpp" 
namespace GTU_CSE241_2019_2020_HW6{

	template<typename T>
	class GTUContainer : public GTUIterator <T>
	{
		public:

			virtual bool empty() const = 0 ;
			virtual int size() const = 0 ;
			virtual int max_size() const = 0 ;
			virtual GTUIterator <T> insert ( const T& new_element ) = 0 ;
			virtual GTUIterator <T> erase( const GTUIterator<T> & erase_iter  ) = 0 ;
			virtual void clear() = 0 ;
			virtual GTUIterator <T> begin() = 0 ;
			virtual GTUIterator <T> end() = 0 ;

			
			
	};
}
#endif