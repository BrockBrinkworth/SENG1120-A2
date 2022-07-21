// Class : LStack.h
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : 

#ifndef BROCK_LSTACK
#define BROCK_LSTACK

#include "LinkedList.h"

class LStack
{
	public:
	
		// Constructor
		LStack( int maxHeight );
		
		// Destructor
		~LStack();
		
		// Functions
		void push( const DataType &data );	// Insert obj on top of stack
		DataType peek( int ) const;	// Reference to obj with index in stack
		void drop();	// Drops the stack
		
		// Supporting Functions
		int sizeZ();	// Return amount if obj in stack
		bool is_empty_check() const;	// Checks if LStack is empty
		
	private:
	
		LinkedList *list;	// Pointer to values of stack
		int used;	// Amount of values in stack
		int maxHeight; // Maximum height for stack
};

#endif