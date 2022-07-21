// Class : Node.cpp
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description :

#include "Node.h"

// constructor
Node::Node( const DataType &new_data )
{
	data = new_data;
	previous = NULL;
	next = NULL;
}

void Node::set_data( const DataType &new_data )
{
	data = new_data;
}

void Node::set_previous( Node *previous_link )
{ 
	previous = previous_link;
}

void Node::set_next( Node *next_link )
{
	next = next_link;
}

const DataType &Node::get_data() const
{
	return data;
}

Node *Node::get_next()
{
	return next;
}

Node *Node::get_previous()
{
	return previous;
}