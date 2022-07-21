// Class : LStack.cpp
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : 

#include "LStack.h"

LStack::LStack( int maxHeight )
{
	list = new LinkedList();
	this->maxHeight = maxHeight;
}

LStack::~LStack()
{
	delete list;
}

void LStack::push( const DataType &data ) // Function that adds obj to the stack
{
	if( used < maxHeight )
	{
		list->add_to_head( data );
		used++;
	}
}

DataType LStack::peek( int index ) const // Call search function... convert index. top of stack to linkedlist = - current height of stack and take absolute value
{
	if( index > 0 && index <= used )
	{
		return list->search( used - index ); // Convert from stack index to list index
	}
	else
	{
		return " ";
	}
}

void LStack::drop()
{
	while( used > 0 )
	{
		list->remove_from_head();
		used--;
	}
}

int LStack::sizeZ()
{
	return used;
}

bool LStack::is_empty_check() const
{
	return list->size() == 0;
}
