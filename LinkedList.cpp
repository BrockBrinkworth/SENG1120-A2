// Class : LinkedList.cpp
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : 

#include "LinkedList.h"
#include "Node.h"

// Defaults for linked list
LinkedList::LinkedList()
{
	head_ptr    = NULL;
	tail_ptr    = NULL;
	list_length = 0;
}

// LL with data
LinkedList::LinkedList( DataType &data )
{
	head_ptr    = new Node( data );
	tail_ptr    = head_ptr;
	list_length = 1;
}

// Destructor
LinkedList::~LinkedList()
{
    while( head_ptr != NULL )
	{
        remove_from_head();
	}
}

void LinkedList::add_to_head( const DataType &data )
{
    // Add Node
    if ( list_length == 0 )
    {
        head_ptr    = new Node( data );
        tail_ptr    = head_ptr;
        list_length = 1;
    }
	// Insert Node at head
	else
	{
		Node *head_insert = new Node( data );  // New node
		head_ptr->set_previous( head_insert ); // Existing head point prev
		head_insert->set_next( head_ptr );     // New head point next
		head_ptr = head_insert;
		list_length++;
	}
}
   
void LinkedList::add_to_tail( const DataType &data )
{
      // Add Node
      if ( list_length==0 )
	{
          add_to_head( data );
	}
	// Insert Node
	else
	{
          Node *tail_insert = new Node( data );  // New node for tail
          
          tail_ptr->set_next( tail_insert );     // Existing tail point next
          tail_insert->set_previous( tail_ptr ); // New tail point prev
          
          list_length++;
	}
}
   
void LinkedList::remove_from_head()
{
      if ( list_length == 0 )
	{
          return;
	}
      else if ( list_length == 1 )
	{
          delete head_ptr;
          head_ptr = NULL;
          tail_ptr = NULL;
          list_length--;
          return;
	}
      else
	{
          Node *temp_head_ptr = head_ptr;
          head_ptr = temp_head_ptr->get_next();
          delete temp_head_ptr;
          list_length--;
	}
}
   
void LinkedList::remove_from_tail()
{
    if ( list_length == 0 )
    {
        return;
    }
    else if ( list_length == 1 )
    {
        remove_from_head();
        return;
    }
    else
    {
        Node *temp_tail_ptr = tail_ptr;
        tail_ptr = temp_tail_ptr->get_previous();
        delete temp_tail_ptr;
        list_length--;
    }
}

DataType LinkedList::search( int index )
{
	Node* current_ptr = head_ptr;
	int i = 0;
	while( current_ptr != NULL )
	{
		if( i == index )
		{
			return current_ptr->get_data();
		}
		current_ptr = current_ptr->get_next();
		i = i + 1;
	}
	return "g";
}

int LinkedList::size()
{
    return list_length;
}