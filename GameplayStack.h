// Class : GameplayStack.h
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : 

#ifndef BROCK_GSTACK
#define BROCK_GSTACK

#include "LStack.h"
#include <iostream>

class GameplayStack
{
	public:
	
		// Constructor
		GameplayStack();
		
		// Destructor
		~GameplayStack();
		
		// Functions
		void initializeBoard();
		void play( std::string, int );
		void displayBoard();
		void checkWin();
		
	private:
	
		LStack* columns[7];
};

#endif