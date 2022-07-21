// Class : LinkedList.h
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : 

#ifndef BROCK_LINKEDLIST
#define BROCK_LINKEDLIST

#include <cstdlib>
#include "Node.h"

class LinkedList
{
	public:
		
		// Constructor
		LinkedList();
		LinkedList( DataType &data );
		
		// Destructor
		~LinkedList();
		
		// Member functions
		void add_to_head( const DataType &data );	// Adds to head
		void add_to_tail( const DataType &data );	// Adds to tail
		void remove_from_head();	// Removes from head
		void remove_from_tail();	// Removes from tail
		DataType search( int index );	// search function
		int size();	// Returns list length

	private:
	
		Node *head_ptr;	// Pointer to head location
		Node *tail_ptr;	// Pointer to tail location
		
		int list_length;	// Amount of data in list
};

#endif