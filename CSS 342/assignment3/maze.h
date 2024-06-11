/*By Ruiqi Huang
* 1/31/2023
* 
* Description:
* This maze is going to be a maze taken from a text file. The maze will have a height, width, row_exit, and column_exit defined from the text file. The walls of the maze is 
* going to be represented by 'x' or 'X' depending on the text file. We are going to be able to check if a specific coordinate fo the maze is either clear, is a wall, is a path,
* have been visited or is a exit. This will help our creature who is roaming the maze find an exit be better understanding the layout of the maze. The field itself is going to 
* be a 2 dimensional array with the max width and height size of 100. A path that has been visited will be marked with a '+' and the path to exit will be marked with a '*'.
*/

#pragma once
#ifndef MAZE_H_
#define MAZE_H_
#include<iostream>
#include <string>
#include <fstream>

using namespace std;

class Maze
{
public:
	//Prints the maze
	friend ostream& operator<<(ostream& out, const Maze& maze);

	//Maze constructor that requires a valid file name
	explicit Maze(string mazeFile);

	//Getters
	//Gets the width
	int getWidth();
	//Gets the height
	int getHeight();
	//Gets the row exit
	int getRowExit();
	//Gets the column exit
	int getColumnExit();

	//Check if the path is clear to move
	bool IsClear(int row, int column) const;

	//Check if there is a wall in the way
	bool IsWall(int row, int column) const;

	//Check if it is a path
	bool IsPath(int row, int column) const;

	//Check if we have already visited the path
	bool IsVisited(int row, int column) const;

	//Check if we are at the exit (Making this methods so we can use for the creature)
	bool IsExit(int row, int column) const;

	//Mark the maze with * if it is path
	void MarkAsPath(int row, int column);

	//mark the maze with + if we already visited
	void MarkAsVisited(int row, int column);


private:
	//Keeps the max size of our field width by length
	static const int MAX_SIZE = 100;
	//2 dimensional array that will keep our field
	char field[MAX_SIZE][MAX_SIZE] ;
	//The height and width of our maze
	int width;
	int height;
	//The row and column of the exit to our maze
	int row_exit;
	int column_exit;
};
#endif MAZE_H_