#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
const int n = 26;   //皇后数量
bool check(int** chess, int row, int col);
void solve(int** chess, int row);
void output(int** chess);
int sum = 0;
int temp = 0;
clock_t start_t, end_t;
ofstream fout("outfile.txt");   //将皇后摆放方法保存为txt文档
int  main() {
	clock_t t1, t2;
	t1 = clock();
	int** chess = new int* [n];
	for (int i = 0; i < n; i++) {
		chess[i] = new int[n];
		for (int j = 0; j < n; j++)
			chess[i][j] = 0;
	}
	start_t = clock();
	solve(chess, 0);
	fout << "共有" << sum << " 种摆放方式" << endl;
	cout << "共有" << sum << " 种摆放方式" << endl;
	t2 = clock();
	cout << t2 - t1 << " ms" << endl;
}

void solve(int** chess, int row) {    //回溯法求解
	for (int j = 0; j < n; j++) {
		chess[row][j] = row + 1;
		if (check(chess, row, j)) {
			if (row == n - 1) {
				temp = 0;
				output(chess);
				end_t = clock();
				fout << end_t - start_t << " ms" << endl;
				//cout << sum << "   " << end_t - start_t << " ms" << endl;
				start_t = clock();
			}
			else {
				solve(chess, row + 1);
			}
		}
		chess[row][j] = 0;
		if (temp < row) {
			temp = row;
			fout << temp << endl;
		}
	}
}

//判断皇后是否攻击
bool check(int** chess, int row, int col) {
	for (int j = 0; j < n; j++) {
		if (j != col && chess[row][j])
			return false;
	}
	for (int i = 0; i < n; i++) {
		if (i != row && chess[i][col])
			return false;
	}
	for (int i = row + 1, j = col + 1; i < n && j < n; i++, j++) {
		if (chess[i][j])
			return false;
	}
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (chess[i][j])
			return false;
	}
	for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
		if (chess[i][j])
			return false;
	}
	for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
		if (chess[i][j])
			return false;
	}
	return true;
}

void output(int** chess) {
	sum++;
	cout << sum << endl;
	fout << "####################" << sum << "##################" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fout << chess[i][j] << " ";
		}
		fout << endl;
	}
	fout << "#######################################" << endl << endl;
}