/*By Ruiqi Huang
* 2/10/2023
*
*Implementation Details:
* We used fstream to read a file and get the width, height, row_exit, and column_exit to the maze. We will also use fstream to get the actual maze. The implementation for 
* the functions such as isClear, isPath, etc are all going to use if statements to check whether their statement is true or false. Cerr will be used to display the errors
* with respect to the pre-conditions. For the output stream, we are going to use a nested for loop in order to read the 2 dimensional array. Just like how you would use a 
* single for loop to read a 1 dimensional array. 
*/

#include "maze.h"

Maze::Maze(string mazeFile)
{
	ifstream file;
	file.open(mazeFile);

	//If the file fails we will print out an error using cerr and exit
	if (file.fail()) {
		cerr << "ERROR: cannot open " << mazeFile << endl;
		exit(1);
	}

	//Read in the follwoing values
	file >> width;
	file >> height;
	file >> row_exit;
	file >> column_exit;

	//...
	string string;
	getline(file, string);

	//i is going to be how many rows there is (height represents how many rows)
	for (int i = 0; i < height; i++) {
		//j is going to be how many columns there is (width repersents how many columns)
		for (int j = 0; j < width; j++) {
			file.get(field[i][j]);
		}
		getline(file, string);
	}

	//closing file after done or else error
	file.close();
}

int Maze::getWidth()
{
	return width;
}

int Maze::getHeight()
{
	return height;
}

int Maze::getRowExit()
{
	return row_exit;
}

int Maze::getColumnExit()
{
	return column_exit;
}

//Pre-condition: path given does not have a negative coordinates
bool Maze::IsClear(int row, int column) const
{
	if ((column < 0) || (row < 0)) {
		cerr << "ERROR: Cannot have negative amount of rows or columns" << endl;
		return false;
	}
	//We know the path is clear when the path is not marked
	if (field[row][column] == ' ') {
		return true;
	}

	//returns false if it is anything but a space
	return false;
}

//Pre-condition: path given does not have a negative coordinates
//This method is similar to IsClear but checks if path have 'X' since X represents a wall
bool Maze::IsWall(int row, int column) const
{
	if ((column < 0) || (row < 0)) {
		cerr << "ERROR: Cannot have negative amount of rows or columns" << endl;
		return false;
	}
	//We know the path has a wall if it has a x
	if (field[row][column] == 'x' || field[row][column] == 'X') {
		return true;
	}

	//returns false if it is anything but a x
	return false;
}

//Pre-condition: path given does not have a negative coordinates
//This method is similar to IsClear but checks if path have '*' since * represents a path
bool Maze::IsPath(int row, int column) const
{
	if ((column < 0) || (row < 0)) {
		cerr << "ERROR: Cannot have negative amount of rows or columns" << endl;
		return false;
	}
	//We know the path is a path when it is marked with a *
	if (field[row][column] == '*') {
		return true;
	}

	//returns false if it is anything but a *
	return false;
}

//Pre-condition: path given does not have a negative coordinates
//This method is similar to IsClear but checks if path have '+' or '*' bcause we only mark paths visited
bool Maze::IsVisited(int row, int column) const
{
	if ((column < 0) || (row < 0)) {
		cerr << "ERROR: Cannot have negative amount of rows or columns" << endl;
		return false;
	}
	//We know the path is visited when it has a * or a +
	if (field[row][column] == '*' || field[row][column] == '+') {
		return true;
	}

	//returns false if it is anything but a * or a +
	return false;
}

bool Maze::IsExit(int row, int column) const
{
	if ((row == row_exit) && (column == column_exit)) {
		return true;
	}
	return false;
}

//Pre-condition: path given does not have a negative coordinates, is within the maze, is a space
//We assume that any path that we mark as path is not a wall and is not already visited
void Maze::MarkAsPath(int row, int column)
{
	//Checking pre-conditions
	if ((column < 0) || (row < 0)) {
		cerr << "ERROR: Cannot have negative amoutn of rows or columns" << endl;
	}
	else if (field[row][column] == 'x' || field[row][column] == 'X' || field[row][column] == '+') {
		cerr << "ERROR: Path has either already been visited or is a wall" << endl;
	}
	else if ((row > height) || (column > width)) {
		cerr << "ERROR: Path chasen is out of bound" << endl;
	}
	else {
		field[row][column] == '*';
	}
}

//Pre-considtion: path given does not have a negative coordinate, is withtin the maze, is not a wall
void Maze::MarkAsVisited(int row, int column)
{
	//Checking pre-conditions
	if ((column < 0) || (row < 0)) {
		cerr << "ERROR: Cannot have negative amoutn of rows or columns" << endl;
	}
	else if (field[row][column] == 'x' || field[row][column] == 'X') {
		cerr << "ERROR: Path is a wall" << endl;
	}
	else if ((row > height) || (column > width)) {
		cerr << "ERROR: Path chasen is out of bound" << endl;
	}
	else {
		field[row][column] == '+';
	}
}


ostream& operator<<(ostream& out, const Maze& maze)
{
	out << maze.width << " " << maze.height << endl;
	out << maze.row_exit << " " << maze.column_exit << endl;
	//i is going to be how many rows there is (height represents how many rows)
	for (int i = 0; i < maze.height; i++) {
		//j is going to be how many columns there is (width repersents how many columns)
		for (int j = 0; j < maze.width; j++) {
			out << maze.field[i][j];
		}
		out << endl;
	}
	out << endl;
	return out;
}