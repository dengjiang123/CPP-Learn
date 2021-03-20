#include<iostream>
#include<stack>
#include<fstream>
#include<ctime>
#include<Windows.h>
using namespace std;
typedef struct Node {
	int x;
	int y;
	bool visited;
	Node() {
		x = y = 0;
		visited = false;
	}
}Node;

class Maze {
private:
	int n;
	int** M;
	stack<Node> S;
public:
	Maze(int N = 10);
	void init();
	void Out_M();
	bool Path(int xs = 1, int ys = 1, int xe = 8, int ye = 8);
	void Rand_M();
};

bool Maze::Path(int xs, int ys, int xe, int ye) {
	if (M[xs][ys] || M[xe][ye])
		return false;
	Node start;
	start.x = xs;
	start.y = ys;
	//start.visited = true;
	S.push(start);
	int di, i, j, find;
	while (S.size()) {
		cout << S.top().x << " " << S.top().y << endl;
		di = -1;
		i = S.top().x;
		j = S.top().y;
		M[S.top().x][S.top().y] = -1;
		if (i == xe && j == ye) {
			return true;
		}
		find = 0;
		while (di < 4 && find==0) {
			di++;
			switch (di) {
			case 0:
				i = S.top().x - 1; j = S.top().y; break;
			case 1:
				i = S.top().x; j = S.top().y + 1; break;
			case 2:
				i = S.top().x + 1; j = S.top().y; break;
			case 3:
				i = S.top().x; j = S.top().y - 1; break;
			}
			if (i < n && j < n && i >= 0 && j >= 0 && M[i][j] == 0)
				find = 1;
		}
		if (find) {
			Node nn;
			nn.x = i;
			nn.y = j;
			M[i][j] = -1;
			S.push(nn);
		}
		else {
			M[S.top().x][S.top().y] = -2;
			S.pop();
		}
	}
	return false;
}

Maze::Maze(int N) {
	n = N;
	M = new int* [N];
	for (int i = 0; i < N; i++) {
		M[i] = new int[N];
		for (int j = 0; j < N; j++)
			M[i][j] = 1;
	}
}

void Maze::init() {
	ifstream fin("in.txt");
	int temp;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fin >> temp;
			M[i][j] = temp;
		}
	}
}

void Maze::Out_M() {
	cout << "#########################################\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M[i][j] == 1)
				cout << "■";
			else if (M[i][j] == 0)
				cout << "  ";
			else if (M[i][j] == -1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "|" << endl;
	}
	cout << "#########################################\n";
	cout << endl << endl;
}

void Maze::Rand_M() {
	int temp = 1;
	srand(time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//Sleep(100);
			temp = rand() % 5;
			//cout << temp << " ";
			if (temp)
				M[i][j] = 0;
		}
	}
}
