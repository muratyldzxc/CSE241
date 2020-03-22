#include<memory>
using namespace std ;
#ifndef NODE_H
#define NODE_H

namespace GTU_CSE241_2019_2020_HW6{
	
	template < typename T  >

	class Node
	{
		public:
			Node() : next(nullptr), prev(nullptr), data(0){}

			shared_ptr < Node <T> > getNextNode() const ;
			shared_ptr < Node <T> > getPrevNode() const ;
			const T& getData() const ;
			T& getData()  ;

			void setNextNode( const shared_ptr < Node <T> > & new_next ) ;
			void setPrevNode( const shared_ptr < Node <T> > & new_prev ) ;
			void setData( const T & new_data ) ;

		protected:
			T data ;
			shared_ptr < Node <T> > next ;
			shared_ptr < Node <T> > prev ;
	};

	template < typename T  >
	shared_ptr< Node <T> > Node<T>::getNextNode() const {


		return next ;
	}

	template < typename T  >
	shared_ptr < Node <T> > Node <T> :: getPrevNode()const {

		return prev ;
	}

	template < typename T  >
	const T& Node <T> :: getData() const {
		return data ;
	}

	template < typename T  >
	T& Node <T> :: getData(){
		return data ;
	}

	template < typename T  >
	void Node <T> :: setNextNode( const shared_ptr < Node <T> > & new_next ){

		next =new_next ;

	}

	template < typename T  >
	void Node <T> :: setPrevNode( const shared_ptr < Node <T> > & new_prev){

		prev = new_prev ;
	}

	template < typename T  >
	void Node <T> :: setData( const T & new_data ){
		data = new_data ;
	}



}

#endif