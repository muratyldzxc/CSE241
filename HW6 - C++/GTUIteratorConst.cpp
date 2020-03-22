#include "GTUIteratorConst.h"
using namespace std ; 

namespace GTU_CSE241_2019_2020_HW6{

	template<typename T>
	GTUIteratorConst<T>::GTUIteratorConst(){
		CurrentPosition = nullptr ;
	}

	template<typename T>
	GTUIteratorConst<T>::GTUIteratorConst( const shared_ptr< Node<T> > & new_CurrentPosition  ){
		CurrentPosition = new_CurrentPosition ;
	}

	template<typename T>
	const T& GTUIteratorConst<T>::operator*(){

		return CurrentPosition->getData();
	}

	template<typename T>
	const T* GTUIteratorConst<T>::operator->(){

		return CurrentPosition->getData() ;
	}

	template<typename T>
	GTUIteratorConst<T> & GTUIteratorConst<T>::operator++(){

		CurrentPosition = CurrentPosition->getNextNode();

		return *this;
	}

	template<typename T>
	GTUIteratorConst<T> GTUIteratorConst<T>::operator++(int IgnoreMe){
		
		GTUIteratorConst<T> temp = *this;

		CurrentPosition = CurrentPosition->getNextNode();
		return temp;
	}

	template<typename T>
	GTUIteratorConst<T> & GTUIteratorConst<T>::operator--(){

		CurrentPosition = CurrentPosition->getPrevNode();
		return *this;
	}

	template<typename T>
	GTUIteratorConst<T> GTUIteratorConst<T>::operator--(int IgnoreMe){
		
		GTUIteratorConst<T> temp=*this;
		
		CurrentPosition = CurrentPosition->getPrevNode();
		return temp;
	}

	template<typename T>
	bool GTUIteratorConst<T>::operator==(const GTUIteratorConst &other){

		return ( CurrentPosition == other.CurrentPosition );
	}

	template<typename T>
	bool GTUIteratorConst<T>::operator!=(const GTUIteratorConst &other){

		return !( CurrentPosition == other.CurrentPosition );
	}

	template<typename T>
	const GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(const GTUIteratorConst & other ){

		CurrentPosition = other.CurrentPosition;
		return *this;
	}

}
