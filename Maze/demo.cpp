#include<iostream>
#include"maze.h"
using namespace std;
int main() {
	Maze All(20);
	//All.init();
	All.Rand_M();
	All.Out_M();
	if (!All.Path(1, 1, 19, 19))
		cout << "没有找到!\n";
	All.Out_M();
}
