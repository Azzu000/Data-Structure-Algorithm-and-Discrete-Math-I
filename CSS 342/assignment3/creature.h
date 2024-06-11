/*By Ruiqi Huang
* 2/10/2023
* 
* Description:
* The creature class inherits the maze class and have a creature find the specific exit to the maze. We can go North, West, East, and South to find the exit to the 2 dimensional 
* maze. Once we find the maze a path of each direction will be shown by using the Solve function. More details on the implementation on the creature.cpp file where all the implementation
* is.
*/

#pragma once
#ifndef CREATURE_H_
#define CREATURE_H_
#include <string>
#include <iostream>
#include "maze.h"

using namespace std;

class Creature
{
public:
	//This creates a creature and determines where the creature will start in the maze
	Creature(int new_row, int new_column);

	//Prints out the location of the creature
	friend ostream& operator<<(ostream& out, const Creature& creature);

	//returns a string in the form of the path that will lead to the exit and returns X if the creature cannot get to an exit
	string Solve(Maze& maze);

	//Moves creature North if possible
	bool goNorth(Maze& maze);
	//Moves creature West if possible
	bool goWest(Maze& maze);
	//Moves creature South if possible
	bool goSouth(Maze& maze);
	//Moves creature East if possible
	bool goEast(Maze& maze);

private:
	//this string will keep out track of our path
	string path;
	//Keeps track of the current row of creature
	int row;
	//Keeps track of the current column of creature
	int column;
	//Keep track fo the row we first started at
	int start_row;
	//Keep track of the column we started at
	int start_column;
};
#endif CREATURE_H_