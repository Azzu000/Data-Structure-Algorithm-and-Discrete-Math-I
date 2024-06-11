/*By Ruiqi Huang
* 2/10/2023
*
* Implementation details:
*The main concept of this assignment is recursion and backtracking. We are going to use the goSouth, goNorth, goWest, and goEast function to test whether each direction from the 
* start position which is noted by start_row and start_column.
*/

#include "creature.h"

//Constructure that determines where the creature starts. new_row, and new_column will represent the starting position because I wanted the vairables to be unique.
Creature::Creature(int new_row, int new_column)
{
	//Where the creature starts
	start_row = new_row;
	start_column = new_column;

	//Keep track of where our creature is
	this->row = new_row;
	this->column = new_column;
	
	//path will start out as empty
	path = "";
}

//Pre-condition: If we are not already at exit, we did not spawn on a wall
//returns the string of the path to the exit
string Creature::Solve(Maze& maze)
{
	if (maze.IsWall(row, column) == true) {
		cerr << "ERROR: Cannot spawn on wall" << endl;
		path = "X";
		return path;
	}
	//We needs check if the creature spawned at the exit
	if (maze.IsExit(row, column) == true) {
		path = "Spawned at exit.";
		return path;
	} 
	
	//Mark the starting point
	maze.MarkAsPath(row, column);

	//Now we go find a path from ever direction possible from the starting path.
	//Try going north
	if (goNorth(maze) == true) {
		return path;
	}

	//We have to reset the start coordinates every direction to make sure we have tried the paths from all direction of the starting position
	this->row = start_row;
	this->column = start_column;

	//Try going west
	if (goWest(maze) == true) {
		return path;
	}

	this->row = start_row;
	this->column = start_column;

	//Try going south
	if (goSouth(maze) == true) {
		return path;
	}

	this->row = start_row;
	this->column = start_column;

	//Try going east
	if (goEast(maze) == true) {
		return path;
	}
	
	//If all path fails then path will = X which means that there is no path to exit
	path = "X";
	return path;
}


//Pre-condition: The path north must be clear
bool Creature::goNorth(Maze& maze)
{
	//cout << "Went north" << endl; //Was here to test

	//We know we have explored the whole maze if the path is longer than the entire maze itself. This is to prevent infinite recursion.
	if (path.length() > (maze.getHeight() * maze.getWidth())) {
		return false;
	}

	//This will keep track whether the movement is successful or not. It will be false for now.
	bool IsSuccess = false;
	//Check if going North is clear. North = row -1 for the field array
	if (maze.IsClear(row - 1, column)) {
		maze.MarkAsPath(row - 1, column);
		row = row - 1;
		path += 'N';

		//Checks if we are at exit now
		if (maze.IsExit(row, column)) {
			IsSuccess = true;
		}
		else {
			//Recursive call. Go North if we can.
			IsSuccess = goNorth(maze);

			//If we failed to go north
			if (IsSuccess == false) {

				//See if we can go west
				IsSuccess = goWest(maze);

				//If we failed to go west 
				if (IsSuccess == false) {

					//See if we can go east
					IsSuccess = goEast(maze);
				}
			} 
		}
	}
	else {
		//We failed moving north in the first place. NOTE: We don't have to try to go south because we moved from south
		return false;
	}

	
	return IsSuccess;
}

//Pre-condition: The path west must be clear
bool Creature::goWest(Maze& maze)
{
	//cout << "Went west" << endl; //Was here to test

	//We know we have explored the whole maze if the path is longer than the entire maze itself. This is to prevent infinite recursion.
	if (path.length() > (maze.getHeight() * maze.getWidth())) {
		return false;
	}

	//This will keep track whether the movement is successful or not. It will be false for now.
	bool IsSuccess = false;

	//Check if going West is clear. West = column -1 for the field array
	if (maze.IsClear(row, column - 1)) {
		maze.MarkAsPath(row, column - 1);
		column = column - 1;
		path += 'W';

		//Checks if we are at exit now
		if (maze.IsExit(row, column)) {
			IsSuccess = true;
		}
		else {
			IsSuccess = goWest(maze);

			//If we failed to go west
			if (IsSuccess == false) {

				//See if we can go south
				IsSuccess = goSouth(maze);

				//If we failed to go south
				if (IsSuccess == false) {

					//See if we can go north
					IsSuccess = goNorth(maze);
				}
			}
		}

	}
	else {
		//We failed moving west in the first place. NOTE: We don't have to try to go east because we moved from east
		return false;
	}

	return IsSuccess;
}

//Pre-condition: The path south must be clear
bool Creature::goSouth(Maze& maze)
{
	//cout << "Went south" << endl; //Was here to test

	//We know we have explored the whole maze if the path is longer than the entire maze itself. This is to prevent infinite recursion.
	if (path.length() > (maze.getHeight() * maze.getWidth())) {
		return false;
	}

	//This will keep track whether the movement is successful or not. It will be false for now.
	bool IsSuccess = false;

	//Check if going South is clear. South = row +1 for the field array
	if (maze.IsClear(row + 1, column)) {
		maze.MarkAsPath(row + 1, column);
		row = row + 1;
		path += 'S';

		//Checks if we are at exit now
		if (maze.IsExit(row, column)) {
			IsSuccess = true;
		}
		else {
			IsSuccess = goSouth(maze);

			//If we failed to go south
			if (IsSuccess == false) {

				//See if we can go west
				IsSuccess = goWest(maze);

				//If we failed to go west
				if (IsSuccess == false) {

					//See if we can go east
					IsSuccess = goEast(maze);
				}
			}
		}
	}
	else {
		//We failed moving south in the first place. NOTE: We don't have to try to go north because we moved from north
		return false;
	}

	return IsSuccess;
}

//Pre-condition: The path east must be clear
bool Creature::goEast(Maze& maze)
{
	//cout << "Went east" << endl; //Was here to test

	//We know we have explored the whole maze if the path is longer than the entire maze itself. This is to prevent infinite recursion.
	if (path.length() > (maze.getHeight() * maze.getWidth())) {
		return false;
	}

	//This will keep track whether the movement is successful or not. It will be false for now.
	bool IsSuccess = false;
	//Check if going North is clear. North = row -1 for the field array
	if (maze.IsClear(row, column + 1)) {
		maze.MarkAsPath(row, column + 1);
		column = column + 1;
		path += 'E';

		//Checks if we are at exit now
		if (maze.IsExit(row, column)) {
			IsSuccess = true;
		}
		else {
			IsSuccess = goEast(maze);

			//If we failed to go east
			if (IsSuccess == false) {

				//See if we can go south
				IsSuccess = goSouth(maze);

				//If we failed to go south
				if (IsSuccess == false) {

					//See if we can go north
					IsSuccess = goNorth(maze);
				}
			}
		}
	}
	else {
		// We failed moving east in the first place.NOTE: We don't have to try to go west because we moved from west
		return false;
	}

	return IsSuccess;
}

ostream& operator<<(ostream& out, const Creature& creature)
{
	out << "Current location of creature is at row " << creature.row << " and column " << creature.column << endl;
	return out;
}
