#include<iostream>
#include"maze.h"
using namespace std;
int main() {
	int n = 70;
	Maze All(n);
	//All.Init();
	All.Rand_M();
	All.Out_M();
	if (!All.Find_Path(0, 0, n - 1, n - 1))
		cout << "没有找到!\n";
	else
		All.Out_Path();
	All.Out_M();
}




/*
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
*/

