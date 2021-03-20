#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include<iomanip>
using namespace std;
typedef struct Node {
	int x;
	int y;
	Node() {
		x = y = 0;
	}
}Node;

class Maze {
private:
	int n;
	int** M;
	vector<Node> S;
public:
	Maze(int N = 10);
	~Maze();
	void Rand_M();
	void Init();
	void Out_M();
	void Out_Path();
	bool Find_Path(int sx = 1, int sy = 1, int ex = 8, int ey = 8);
};

bool Maze::Find_Path(int sx, int sy, int ex, int ey) {
	if (M[sx][sy] || M[ex][ey])
		return false;
	Node start;
	start.x = sx;
	start.y = sy;
	M[sx][sy] = -1;
	S.push_back(start);
	int direct, i, j, find;
	while (S.size()) {
		//cout << S.back().x << " " << S.back().y << endl;
		i = (S.back()).x;
		j = (S.back()).y;
		if (i == ex && j == ey)
			return true;
		find = 0;
		direct = -1;
		while (direct < 4 && find == 0) {
			direct++;
			switch (direct) {
			case 0:
				i = (S.back()).x + 1; j = (S.back()).y; break;
			case 1:
				i = (S.back()).x; j = (S.back()).y + 1; break;
			case 2:
				i = (S.back()).x - 1; j = (S.back()).y; break;
			case 3:
				i = (S.back()).x; j = (S.back()).y - 1; break;
			}
			if (i < n && j < n && i >= 0 && j >= 0 && M[i][j] == 0)
				find = 1;
		}
		if (find) {
			Node nn;
			nn.x = i;
			nn.y = j;
			M[i][j] = -1;
			S.push_back(nn);
		}
		else {
			M[S.back().x][S.back().y] = -2;
			S.pop_back();
		}
	}
	return false;
}

void Maze::Out_Path() {
	int all = S.size();
	for (int i = 0; i < all; i++) {
		cout << "(" << setw(3) << S[i].x << "," << setw(3) << S[i].y << ")->";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;
}

void Maze::Out_M() {
	cout << "##################################################################\n |";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M[i][j] == 0)
				cout << "  ";
			else if (M[i][j] == 1)
				cout << "■";
			else if (M[i][j] == -1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "|\n |";
	}
	cout << "##################################################################\n\n";
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

Maze::~Maze() {
	for (int i = 0; i < n; i++)
		delete M[i];
	delete[] M;
}

void Maze::Init(){
	ifstream fin("in.txt");
	int temp;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			fin >> temp;
			M[i][j] = temp;
		}
}

void Maze::Rand_M() {
	srand(time(0));
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp = rand() % 3;
			if (temp)
				M[i][j] = 0;
		}
	}
}
