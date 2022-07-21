// Class : Node.h
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : 

#ifndef BROCK_NODE
#define BROCK_NODE

#include <cstdlib>
#include <iostream>

typedef std::string DataType;

class Node
{
    public:
        
        // Constructor
		Node( const DataType &new_data );
	
        void set_data( const DataType &new_data );	// Sets data in node
        void set_next( Node *next_link );	// Sets data in next node
        void set_previous( Node *previous_link );	// Sets data in previous node
        
        const DataType &get_data() const;	// Returns Data in node
		Node *get_next();	// Returns next node
        Node *get_previous();	// Returns previous node
        
    private:
	
        DataType data;	// Data in node
        Node *next;	// Next node
        Node *previous;	// Previous node
};

#endif