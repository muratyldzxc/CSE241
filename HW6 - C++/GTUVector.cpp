#include <iostream>
#include "GTUVector.h"
#include <string>

using namespace std ;
using namespace GTU_CSE241_2019_2020_HW6 ;

namespace GTU_CSE241_2019_2020_HW6{


	template<typename T>
	GTUVector<T> :: GTUVector() : KeepData(nullptr), _size(0){
		EndOfData = make_shared < Node < T > > () ;
	}

	template<typename T>
	GTUVector<T> :: GTUVector( shared_ptr< Node<T> > new_KeepData ){

		KeepData = new_KeepData ;
		KeepData->setNextNode( EndOfData ) ;
		EndOfData->setPrevNode( KeepData ) ;
	}

	template<typename T>
	GTUVector<T> :: GTUVector( const GTUVector<T>  &other ){
		
		EndOfData = make_shared < Node < T > > () ; 

		shared_ptr< Node<T> > temp_node_my ;
		shared_ptr< Node<T> > temp_node_other ;

		shared_ptr< Node<T> > head_node = make_shared < Node < T > > () ;
		head_node->setData( other.KeepData->getData() ) ;

		temp_node_my = head_node ;
		temp_node_other = other.KeepData->getNextNode() ;
		
		for( int i = 0; i< other._size - 1; i++){

			shared_ptr< Node<T> > new_node ( new Node<T> () ) ;

			new_node->setData( temp_node_other->getData() ) ;
			
			temp_node_my->setNextNode( new_node ) ;
			new_node->setPrevNode( temp_node_my ) ;

			temp_node_my = temp_node_my->getNextNode() ;
			temp_node_other = temp_node_other->getNextNode() ;
		}

		KeepData = head_node ;
		temp_node_my->setNextNode( EndOfData ) ;
		EndOfData->setPrevNode( temp_node_my ) ;

		_size = other._size ;

	}

	template<typename T>
	GTUVector<T> GTUVector<T>::operator=( const GTUVector<T> &other ){

		if ( _size > 0 )
			this->clear() ;

		EndOfData = make_shared < Node < T > > () ; 

		shared_ptr< Node<T> > temp_node_my ;
		shared_ptr< Node<T> > temp_node_other ;

		shared_ptr< Node<T> > head_node = make_shared < Node < T > > () ;
		head_node->setData( other.KeepData->getData() ) ;

		temp_node_my = head_node ;
		temp_node_other = other.KeepData->getNextNode() ;
		
		for( int i = 0; i< other._size - 1; i++){

			shared_ptr< Node<T> > new_node ( new Node<T> () ) ;

			new_node->setData( temp_node_other->getData() ) ;
			
			temp_node_my->setNextNode( new_node ) ;
			new_node->setPrevNode( temp_node_my ) ;

			temp_node_my = temp_node_my->getNextNode() ;
			temp_node_other = temp_node_other->getNextNode() ;
		}

		KeepData = head_node ;
		temp_node_my->setNextNode( EndOfData ) ;
		EndOfData->setPrevNode( temp_node_my ) ;
		_size = other._size ;

		return *this ;

	}

	template<typename T>
	T& GTUVector<T>::operator[]( int get ) {
		
		int i = 0 ;
		
		shared_ptr< Node<T> > temp_node = KeepData ;

		while( i != get ){
			temp_node = temp_node->getNextNode() ;
			i++ ;
		}

		return temp_node->getData() ;
	
	}
	template<typename T>
	const T& GTUVector<T>::operator[]( int get ) const{
		int i = 0 ;
		
		shared_ptr< Node<T> > temp_node = KeepData ;

		while( i != get ){
			temp_node = temp_node->getNextNode() ;
			i++ ;
		}

		return temp_node->getData() ;
	}

	template<typename T>
	bool GTUVector<T>::empty()const {
		
		if( KeepData == nullptr )
			return true ;
		else 
			return false ;
	} 

	template<typename T>
	int GTUVector<T>::size()const {
		return _size ;
	}

	template<typename T>
	int GTUVector<T>::max_size()const {
		return _max_size ;
	}

	template<typename T>
	GTUIterator <T> GTUVector<T> :: begin(){

		return GTUIterator <T> ( KeepData ) ;
	}

	template<typename T>
	GTUIterator <T> GTUVector<T> :: end(){

		return GTUIterator <T> ( EndOfData ) ;
	}

	template<typename T>
	GTUIterator <T> GTUVector<T>::insert ( const T& new_element ) {
		
		if( _size > _max_size )
			throw bad_pafram("!!You passed over the max size!!") ;

		shared_ptr < Node < T > > temp_node ;

		temp_node = KeepData ;
	
		shared_ptr < Node < T > > new_node = make_shared < Node < T > > ()  ;

		if( temp_node == nullptr ){
			
			new_node->setData( new_element ) ;
			new_node->setNextNode( nullptr ) ;
			new_node->setPrevNode( nullptr ) ;

			KeepData = new_node ;
		}
		
		else{
		
			while( temp_node->getNextNode() != EndOfData ){

				temp_node = temp_node->getNextNode() ;
			}

			new_node->setData( new_element ) ;
			new_node->setNextNode( nullptr ) ;
			new_node->setPrevNode( temp_node ) ;

			temp_node->setNextNode( new_node ) ;

		}

		new_node->setNextNode( EndOfData ) ;
		EndOfData->setPrevNode( new_node ) ;

		_size ++ ;
		
		return GTUIterator <T> ( new_node ) ;		
	}

	template<typename T>
	void GTUVector<T> :: clear(){

		shared_ptr < Node<T> > temp_node = KeepData ;

		if( _size > 0){
			while( temp_node->getNextNode() != EndOfData ){

				temp_node = KeepData->getNextNode() ;

				KeepData->setNextNode( nullptr ) ;
				KeepData-> setPrevNode( nullptr ) ;

				KeepData = temp_node ;
			}
		}
		else
			throw bad_pafram("!!You tried to clear an empty GTUVector!!") ;
		KeepData = nullptr ;
		_size = 0;   
	}


	template<typename T>
	GTUIterator <T> GTUVector<T> :: erase( const GTUIterator<T> & erase_iter ){
		
		shared_ptr < Node < T > > temp_node, prev_node, next_node ;
		GTUIterator <T> temp_iter ;
		int i = 0 ;

		temp_iter = begin() ;
		temp_node = KeepData ;

		while( temp_iter != erase_iter && i < _size ){

			temp_iter++ ;
			temp_node = temp_node->getNextNode() ;
			i++ ;
		}
		
		if( temp_node == nullptr ){
			// if it is null	
			throw bad_pafram("!!You tried to erase an invalid position from GTUVector!!") ;
			GTUIterator <T> return_iter ( EndOfData ) ;
			return_iter -- ;

			return return_iter ;
		} 
		else if( _size <= i ) {
			// if it is out of the border
			throw bad_pafram("!!You tried to erase an invalid position from GTUVector!!") ;
			
			GTUIterator <T> return_iter ( EndOfData ) ;
			return_iter -- ;

			return return_iter ;		
		}

		// if it has only head
		else if( temp_node->getNextNode() == nullptr && temp_node->getPrevNode() == nullptr ){
			temp_node->setNextNode( nullptr ) ;
			temp_node->setPrevNode( nullptr ) ;
			temp_node = nullptr ;

			return GTUIterator <T> ( KeepData ) ;
		}
		// if it is head but not only 
		else if( temp_node->getPrevNode() == nullptr ){
			KeepData = KeepData->getNextNode() ;
			KeepData->setPrevNode( nullptr ) ;

			temp_node->setNextNode( nullptr ) ;
			temp_node->setPrevNode( nullptr ) ;
			temp_node = nullptr ;

			return GTUIterator <T> ( KeepData ) ;
		}
		// if it is end
		else if( temp_node->getNextNode() == EndOfData ){
			prev_node = temp_node->getPrevNode() ;

			prev_node->setNextNode( EndOfData ) ;
			EndOfData->setPrevNode( prev_node ) ;

			temp_node->setNextNode( nullptr ) ;
			temp_node->setPrevNode( nullptr ) ;
			temp_node = nullptr ;

			return GTUIterator <T> ( prev_node ) ;

		}

		// if it is middle
		else{
			next_node = temp_node->getNextNode() ;
			prev_node = temp_node->getPrevNode() ;
	
			prev_node->setNextNode( next_node ) ;
			next_node->setPrevNode( prev_node ) ;	

			temp_node->setNextNode( nullptr ) ;
			temp_node->setPrevNode( nullptr ) ;
			temp_node = nullptr ;

			return GTUIterator <T> ( next_node ) ;
		}

	}
	
	template<typename T>
	GTUVector<T>::~GTUVector(){
		if( _size > 0)
			clear() ;
	}

}
