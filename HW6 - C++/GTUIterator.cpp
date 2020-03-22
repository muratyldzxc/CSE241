#include "GTUIterator.h"
using namespace std ; 

namespace GTU_CSE241_2019_2020_HW6{

	template<typename T>
	GTUIterator<T>::GTUIterator(){
		CurrentPosition = nullptr ;
	}

	template<typename T>
	GTUIterator<T>::GTUIterator( const shared_ptr< Node<T> > & new_CurrentPosition  ){
		CurrentPosition = new_CurrentPosition ;
	}

	template<typename T>
	T& GTUIterator<T>::operator*(){

		return CurrentPosition->getData();
	}

	template<typename T>
	T* GTUIterator<T>::operator->(){

		return CurrentPosition->getData() ;
	}

	template<typename T>
	GTUIterator<T> & GTUIterator<T>::operator++(){

		CurrentPosition = CurrentPosition->getNextNode();

		return *this;
	}

	template<typename T>
	GTUIterator<T> GTUIterator<T>::operator++(int IgnoreMe){
		
		GTUIterator<T> temp = *this;

		CurrentPosition = CurrentPosition->getNextNode();
		return temp;
	}

	template<typename T>
	GTUIterator<T> & GTUIterator<T>::operator--(){

		CurrentPosition = CurrentPosition->getPrevNode();
		return *this;
	}

	template<typename T>
	GTUIterator<T> GTUIterator<T>::operator--(int IgnoreMe){
		
		GTUIterator<T> temp=*this;
		
		CurrentPosition = CurrentPosition->getPrevNode();
		return temp;
	}

	template<typename T>
	bool GTUIterator<T>::operator==(const GTUIterator &other){

		return ( CurrentPosition == other.CurrentPosition );
	}

	template<typename T>
	bool GTUIterator<T>::operator!=(const GTUIterator &other){

		return !( CurrentPosition == other.CurrentPosition );
	}

	template<typename T>
	const GTUIterator<T>& GTUIterator<T>::operator=(const GTUIterator & other ){

		CurrentPosition = other.CurrentPosition;
		return *this;
	}

}