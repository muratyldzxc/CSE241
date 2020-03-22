#include <iostream>
#include <memory>
#include <algorithm>
#include "Node.h"
#include "GTUSet.h" 
#include "GTUSet.cpp" 
#include "GTUVector.h" 
#include "GTUVector.cpp"

using namespace std ;
using namespace GTU_CSE241_2019_2020_HW6 ;

template<typename GTUIterator, typename T>
GTUIterator myfind (GTUIterator begin, GTUIterator end, const T& value)
{
	while ( begin != end ) {

		if ( *begin == value ) 
			return begin ;
   		++begin;
  	}

  	return end;
} 

template<typename GTUIterator , typename UnaryPredicate>
GTUIterator  myfind_if (GTUIterator  begin, GTUIterator  end, UnaryPredicate foo )
{
	while ( begin != end ) {

	    if (foo(*begin)) 
	    	return begin;
	   	++begin;
  	}
  	
  	return end;
}

template<typename GTUIterator, typename Function>
Function myfor_each(GTUIterator begin, GTUIterator end, Function fn)
{
	while ( begin != end) {
		fn (*begin);
		++begin;
	}

 	return fn;      
}

bool IsEven (int i) {
  return ((i%2)==0);
}

void myFunctionPrint (int i) {  // function:
	cout << ':' << i<<": ";
}
int main(){

 // *************************GTUVECTOR************************************
	// called constructors 


/* */

	
	cout << "\n\n************************* TEST FOR GTUVECTOR ************************************\n\n" ; 
	GTUVector<int> vector1, vector2 ;
	GTUIterator < int > it1, it2 ;

	cout << "\n\n vector1 after constructor called, size:  " << vector1.size() << endl ;

	for(int i=0 ; i<10 ; i++){
		try{
			vector1.insert(i);
		}
		catch( const bad_pafram &error ){
			error.print_error_message() ;
		}
	}

	cout << "\n\n vector1 after insert some elements, size:  " << vector1.size() << endl ;
	

	cout << "\n\n vector1 : " ;
	// 'it' is a GTUIterator
	for(auto it = vector1.begin() ; it != vector1.end() ; ++it) 
		cout << *it << ", ";
	
	
	
	if ( ! vector1.empty() )
		cout << "\n\n vector 1 is not empty\n" ;

	if ( vector2.empty() )
		cout << "\n vector 2 is empty\n" ;
 	
	for(int i=10 ; i<20 ; i++){

		try{
			vector2.insert(i);
		}
		catch( const bad_pafram &error ){
			error.print_error_message() ;
		}
	}
	cout << endl ;


	cout << "\n\n vector2 after insert some elements, size:  " << vector2.size() << endl ;
	

	cout << "\n\n printed with iterator vector1 : " ;
	// 'it' is a GTUIterator
	for(auto it = vector1.begin() ; it != vector1.end() ; ++it) 
		cout << *it << ", ";

	cout << "\n\n printed with index operator vector2 : " ;
	for(int i=0 ; i<10 ; i++){
		cout << vector2[i] << ", ";
	}
	cout << endl ;

	for(int i=20 ; i<30 ; i++){
		vector2[i-20] = i ;
	}
	cout << "\n\n after change vector2 elements with index operator " << endl ;

	cout << "\n\n printed with iterator vector1 : " ;
	for(auto it = vector1.begin() ; it != vector1.end() ; ++it) 
		cout << *it << ", ";

	cout << "\n\n printed with index operator vector2 : " ;
	for(int i=0 ; i<10 ; i++){
		cout << vector2[i] << ", ";
	}
	cout << endl ;

	

	// test erase funciton
	it1 = vector1.begin() ;
	cout << "\n\nThe value before erase first element , it1 is pointing to : " << *it1<< endl ;

	try{
		it1 = vector1.erase( it1 ) ;
	}
	catch( const bad_pafram &error ){
		error.print_error_message() ;
	}

	cout << "\n\nThe value after erase first element , it1 is pointing to : " << *it1<< endl ;

	cout << "\n\n vector1 : " ;
	// 'it' is a GTUIterator
	for(auto it = vector1.begin() ; it != vector1.end() ; ++it) 
		cout << *it << ", ";

	it1 = vector1.end() ;
	it1-- ;
	cout << "\n\nThe value before erase last element , it1 is pointing to : " << *it1<< endl ;

	try{
		it1 = vector1.erase( it1 ) ;
	}
	catch( const bad_pafram &error ){
		error.print_error_message() ;
	}

	cout << "\n\nThe value after erase last element , it1 is pointing to : " << *it1<< endl ;
	
	cout << "\n\n vector1 : " ;
	// 'it' is a GTUIterator
	for(auto it = vector1.begin() ; it != vector1.end() ; ++it) 
		cout << *it << ", ";


	it1 = vector1.begin() ;
	it1++ ;
	it1++ ;
	it1++ ;

	cout << "\n\nThe value before erase an element between begin and end , it1 is pointing to : " << *it1<< endl ;

	try{
		it1 = vector1.erase( it1 ) ;
	}
	catch( const bad_pafram &error ){
		error.print_error_message() ;
	}

	cout << "\n\nThe value after erase an element between begin and end , it1 is pointing to : " << *it1<< endl ;
	
	cout << "\n\n vector1 : " ;
	// 'it' is a GTUIterator
	for(auto it = vector1.begin() ; it != vector1.end() ; ++it) 
		cout << *it << ", ";


	it1 = vector1.end() ;
	it1++ ;
	cout << "\n\n while it1 is pointing to out of borders " << endl ;
	try{
		it1 = vector1.erase( it1 ) ;
	}
	catch( const bad_pafram &error ){
		error.print_error_message() ;
	}

	cout << "\n\nAfter try to  erase an element out of borders " << endl ;

	cout << "\n\n vector1 : " ;
	// 'it' is a GTUIterator
	for(auto it = vector1.begin() ; it != vector1.end() ; ++it) 
		cout << *it << ", ";


	try{
		vector1.clear() ;
	}
	catch( const bad_pafram &error ){
		
		error.print_error_message() ;
	}
	cout << "\n\n After cleared  vector1, size:  " << vector1.size() << endl ;

	cout << "\n\n Try to clear second time vector1  "  << endl ;
	try{
		vector1.clear() ;
	}
	catch( const bad_pafram &error ){
		
		error.print_error_message() ;
	}
	
	cout << "\n\n Before pass over the max size, size :  " << vector1.size() << endl ;
	for(int i=0 ; i<2002 ; i++){
		try{
			vector1.insert(i);
		}
		catch( const bad_pafram &error ){
			error.print_error_message() ;
		}
	}
	cout << "\n\n Max size :  " << vector1.max_size() << endl ;
	cout << "\n\n After pass over the max size, size :  " << vector1.size() << endl ; 


 	//************ TESTING GLOBAL FUNCTIONS FOR VECTORS ***********

 	cout << "\n\n************ TESTING GLOBAL FUNCTIONS FOR VECTORS ***********\n\n" ;

 	cout << " vector2 : " ;
	// 'it' is a GTUIterator
	for(auto it = vector2.begin() ; it != vector2.end() ; ++it) 
		cout << *it << ", ";

 	cout << "\n\n find function\n\n" ;
	auto it = myfind (vector2.begin(), vector2.end(), 28);
  	if (it != vector2.end())
   		cout << "Element found in myvector: " << *it << '\n';
  	else
    	cout << "Element not found in myvector\n";

    cout << "\n\n find if function\n\n" ;
    it = myfind_if( vector2.begin(), vector2.end(), IsEven ) ;
    cout << "\nThe first even value is " << *it << '\n';

    cout << "\n\n for each function , print all data \n\n" ;
    myfor_each( vector2.begin(), vector2.end(), myFunctionPrint ) ;
    cout << "\n\n" ;



//**********************************************************
//******************************************************************

//*********************************************************

/* */

	//
	cout << "\n\n************************* TEST FOR GTUSET ************************************\n\n" ;
	GTUSet<int> Set1, Set2 ;

	cout << "\n\n Set1 after constructor called, size:  " << Set1.size() << endl ;
	
	for(int i=0 ; i<10 ; i++){
		try{
			Set1.insert(i);
		}
		catch( const bad_pafram &error ){
			error.print_error_message() ;
		}
		
	}

	cout << "\n\n Set1 after insert some elements, size:  " << Set1.size() << endl ;
	cout << "\n\n Set1 : " ;
	for(auto it = Set1.begin() ; it != Set1.end() ; ++it) 
		cout << *it << ", ";

	cout << "\n\n Try to insert duplicate element 2 into Set1\n\n" ;

	try{
		Set1.insert(2);
	}
	catch( const bad_pafram &error ){
		error.print_error_message() ;
	}
	
	if ( ! Set1.empty() )
		cout << "\n\n Set 1 is not empty\n" ;

	if ( Set2.empty() )
		cout << "\n Set 2 is empty\n" ;
 	
	for(int i=10 ; i<20 ; i++){
		try{
			Set2.insert(i);
		}
		catch( const bad_pafram &error ){
			error.print_error_message() ;
		}
		
	}

	cout << "\n\n Set2 after insert some elements size:  " << Set2.size() << endl ;
	

	cout << "\n\n Set1 : " ;
	// 'it' is a GTUIterator
	for(auto it = Set1.begin() ; it != Set1.end() ; ++it) 
		cout << *it << ", ";

	cout << "\n\n Set2 : " ;
	// 'it' is a GTUIterator
	for(auto it = Set2.begin() ; it != Set2.end() ; ++it) 
		cout << *it << ", ";
	cout << endl ;

	// test erase funciton
	it1 = Set1.begin() ;
	cout << "\n\nThe value before erase first element , it1 is pointing to : " << *it1<< endl ;

	try{
		it1 = Set1.erase( it1 ) ;
	}
	catch( const bad_pafram &error ){
		error.print_error_message() ;
	}

	cout << "\n\nThe value after erase first element , it1 is pointing to : " << *it1<< endl ;

	cout << "\n\n Set1 : " ;
	// 'it' is a GTUIterator
	for(auto it = Set1.begin() ; it != Set1.end() ; ++it) 
		cout << *it << ", ";

	it1 = Set1.end() ;
	it1-- ;
	cout << "\n\nThe value before erase last element , it1 is pointing to : " << *it1<< endl ;

	try{
		it1 = Set1.erase( it1 ) ;
	}
	catch( const bad_pafram &error ){
		error.print_error_message() ;
	}

	cout << "\n\nThe value after erase last element , it1 is pointing to : " << *it1<< endl ;
	
	cout << "\n\n Set1 : " ;
	// 'it' is a GTUIterator
	for(auto it = Set1.begin() ; it != Set1.end() ; ++it) 
		cout << *it << ", ";


	it1 = Set1.begin() ;
	it1++ ;
	it1++ ;
	it1++ ;

	cout << "\n\nThe value before erase an element between begin and end , it1 is pointing to : " << *it1<< endl ;

	try{
		it1 = Set1.erase( it1 ) ;
	}
	catch( const bad_pafram &error ){
		error.print_error_message() ;
	}

	cout << "\n\nThe value after erase an element between begin and end , it1 is pointing to : " << *it1<< endl ;
	
	cout << "\n\n Set1 : " ;
	// 'it' is a GTUIterator
	for(auto it = Set1.begin() ; it != Set1.end() ; ++it) 
		cout << *it << ", ";


	it1 = Set1.end() ;
	it1++ ;

	cout << "\n\n while it1 is pointing to out of borders " << endl ;
	try{
		it1 = Set1.erase( it1 ) ;
	}
	catch( const bad_pafram &error ){
		error.print_error_message() ;
	}

	cout << "\n\nAfter try to  erase an element out of borders " << endl ;

	cout << "\n\n Set1 : " ;
	// 'it' is a GTUIterator
	for(auto it = Set1.begin() ; it != Set1.end() ; ++it) 
		cout << *it << ", ";


	try{
		Set1.clear() ;
	}
	catch( const bad_pafram &error ){
		
		error.print_error_message() ;
	}
	cout << "\n\n After cleared  Set1, size:  " << Set1.size() << endl ;

	cout << "\n\n Try to clear second time Set1  "  << endl ;
	try{
		Set1.clear() ;
	}
	catch( const bad_pafram &error ){
		
		error.print_error_message() ;
	}
	
	cout << "\n\n Before pass over the max size, size :  " << Set1.size() << endl ;
	
	for(int i=0 ; i<2002 ; i++){
		try{
			Set1.insert(i);
		}
		catch( const bad_pafram &error ){
			error.print_error_message() ;
		}
	}
	cout << "\n\n Max size :  " << Set1.max_size() << endl ;
	cout << "\n\n After pass over the max size, size :  " << Set1.size() << endl ;

	//************ TESTING GLOBAL FUNCTIONS FOR VECTORS ***********

 	cout << "\n\n************ TESTING GLOBAL FUNCTIONS FOR VECTORS ***********\n\n" ;

 	cout << " vector2 : " ;
	// 'it' is a GTUIterator
	for(auto it = Set2.begin() ; it != Set2.end() ; ++it) 
		cout << *it << ", ";

 	cout << "\n\n find function\n\n" ;
	it = myfind (Set2.begin(), Set2.end(), 30);
  	if (it != Set2.end())
   		cout << "Element found in myvector: " << *it << '\n';
  	else
    	cout << "Element not found in myvector\n";

    cout << "\n\n find if function\n\n" ;
    it = myfind_if( Set2.begin(), Set2.end(), IsEven ) ;
    cout << "\nThe first odd value is " << *it << '\n';

    cout << "\n\n for each function , print all data \n\n" ;
    myfor_each( Set2.begin(), Set2.end(), myFunctionPrint ) ;
    cout << "\n\n" ;
}