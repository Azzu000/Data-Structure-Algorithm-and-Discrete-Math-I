/*By Ruiqi Huang
* 2/11/2023
* 
* Description:
* This is the driver class of both creatures and maze. We will be using this main class to test the functioanlity of both our maze class and creature class. Since we need 
* the maze class to test the creature class, we will be creating mazes using maze0.txt, mazeNoExit1.txt, and mazeSimple.txt given by the professor. 
*/

#include "maze.h"
#include "creature.h"

void Test1() {
	Maze maze1("maze0.txt");
	cout << maze1 << endl;

	cout << " Testing on our first maze." << endl;
	//Testing what happens if creature spawns at wall
	Creature c1(4, 1);
	cout << "Path to exit is: " << c1.Solve(maze1) << endl;
	cout << endl;

	cout << "Testing on our second maze." << endl;
	Maze maze2("mazeNoExit1.txt");
	cout << maze2 << endl;
	Creature c2(1, 1);
	cout << "Path to exit is: " << c2.Solve(maze2) << endl;

	cout << "Testing on our third maze." << endl;
	Maze maze3("mazeSimple.txt");
	cout << maze3 << endl;
	Creature c3(1, 7);
	cout << "Path to exit for maze 3: " << c3.Solve(maze3) << endl;
	cout << endl;

	cout << "Testing on maze 0." << endl;
	Maze maze("maze.txt");
	cout << maze << endl;
	Creature c0(5, 16);
	cout << "Path to exit for maze 0: " << c0.Solve(maze) << endl;
}

void myTest() {
	cout << "Testing my maze 1." << endl;
	Maze maze1("maze1.txt");
	cout << maze1 << endl;
	Creature c1(4, 5);
	cout << c1 << endl;
	cout << "Path to exit for my maze 1: " << c1.Solve(maze1) << endl;
	cout << endl;

	cout << "Testing my maze 2." << endl;
	Maze maze2("maze2.txt");
	cout << maze2 << endl;
	Creature c2(1, 2);
	cout << c2 << endl;
	cout << "Path to exit for my maze 1: " << c2.Solve(maze2) << endl;
}

void testAll() {
	Test1();
	myTest();
	cout << "TEST COMPLETE!" << endl;
}
int main() {
	testAll();
	return 0;
}