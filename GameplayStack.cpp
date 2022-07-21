// Class : GameplayStack.cpp
// By : Brock Brinkworth (c3331952)
// Date : 3/05/2021
// Description : 

#include <string>
#include "GameplayStack.h"

// Creating board of 7 columns with height 6
GameplayStack::GameplayStack()
{
	for( int i = 0; i < 7; i++ )
	{
		columns[i] = new LStack(6);
	}
}

// Deletes each LStack obj for each column
GameplayStack::~GameplayStack()
{
	for( int i = 0; i < 7; i++ )
	{
		delete columns[i];
	}
}

// Drops values in each columns stack
void GameplayStack::initializeBoard()
{
	for( int i = 0; i < 7; i++ )
	{
		columns[i]->drop();
	}
}

// Takes input and plays game
void GameplayStack::play( std::string piece, int row )
{
	if( row > 7 || row < 1 )
	{
		return;
	}
	// Check IF string == "X" or "O", then push to int row
	//if( piece == "X" || piece == "O" )
	//{
		
		columns[row - 1]->push( piece );
		this->checkWin();
	//}
}


// Displays the board after the game
void GameplayStack::displayBoard()
{
	std::string s = "";
	for( int row = 6; row > 0; row-- )
	{
		s += "#";
		for( int col = 0; col < 7; col++ )
		{
			s += " ";
			if( row <= columns[col]->sizeZ() )
			{
				s += columns[col]->peek(row);
			}
			else
			{
				s += " ";
			}
		}
		s += " #\n";
	}
	s += "#################\n";
	s += "  1 2 3 4 5 6 7 ";
	std::cout << s << std::endl;
}

// Checks if a player wins by four in a row horizontally or vertically
void GameplayStack::checkWin()
{
	int checkCols[7] = {0,0,0,0,0,0,0};
	for (int row = 6; row > 0; row--)
	{
		int checkRow = 0;
		for (int col = 0; col < 7; col++)
		{
			std::string piece = columns[col]->peek(row);
			if (piece == " ")
			{
				checkRow = 0;
				checkCols[col] = 0;
			}
			else if (piece == "X")
			{
				if( checkCols[col] >= 0 )
				{
					checkCols[col] = -1;
				}
				else
				{
					checkCols[col]--;
				}
	
				if (checkRow >= 0)
				{
					checkRow = -1;
				}
				else
				{
					checkRow--;
				}
	
			}
			else if (piece == "O")
			{
				if( checkCols[col] <= 0 )
				{
					checkCols[col] = 1;
				}
				else
				{
					checkCols[col]++;
				}
	
				if (checkRow <= 0)
				{
					checkRow = 1;
				}
				else
				{
					checkRow++;
				}
	
			}
	
			if (checkCols[col] == -4 || checkRow == -4)
			{
				std::cout << "X Wins" << std::endl;
				return;
			}
			else if (checkCols[col] == 4 || checkRow == 4)
			{
				std::cout << "O Wins" << std::endl;
				return;
			}
		}
	}
	
	int size = 0;
	for (int col = 0; col < 7; col++)
	{
		size += columns[col]->sizeZ();
	}
	
	if (size == 7*6)
	{
		std::cout << "Game Tie" << std::endl;
	}
	
	return;
}