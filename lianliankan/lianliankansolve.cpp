#include<iostream>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;
void Read_Data(int** M);
void Show_Data(int** M);
int Oncecheck(int** M, int i, int j, int m, int n);
int Twicecheck(int** M, int i, int j, int m, int n);
int Threecheck(int** M, int i, int j, int m, int n);
int Matching(int** M, int i, int j, int m, int n);
void Solve(int** M);
void Copy(int** M1, int** M2);
int Test(int** M1, int** M2);
int main() {
	int** M = new  int* [11];
	int** M1 = new  int* [11];
	for (int i = 0; i < 11; i++) {
		M[i] = new int[19];
		M1[i] = new int[19];
	}
	Read_Data(M);
	Show_Data(M);
	Copy(M, M1);
	int n = 0;
	clock_t start_t, end_t;
	start_t = clock();
	while (1) {
		n++;
		Solve(M);
		if (Test(M, M1))
			break;
		Copy(M, M1);
	}
	end_t = clock();
	cout << end_t - start_t << " ms" << endl;
	cout << n << endl;
	return 0;
}

void Solve(int** M) {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 19; j++) {
			for (int m = 0; m < 11; m++) {
				for (int n = 0; n < 19; n++) {
					if (M[i][j] != 0 && M[i][j] == M[m][n] && Matching(M, i, j, m, n)) {
						M[i][j] = 0;
						M[m][n] = 0;
						cout << "[" << i << "," << j << "]" << " and " << "[" << m << "," << n << "]\n";
						Show_Data(M);
					}
				}
			}
		}
	}
}

int Matching(int** M, int i, int j, int m, int n) {
	if (i == m && j == n)
		return 0;
	if (Oncecheck(M, i, j, m, n))
		return 1;
	if (Twicecheck(M, i, j, m, n))
		return 1;
	if (Threecheck(M, i, j, m, n))
		return 1;
	return 0;
}

int Threecheck(int** M, int i, int j, int m, int n) {
	for (int b = 0; b < 19; b++) {
		if (b != j && b != n && Oncecheck(M, i, j, i, b) && Twicecheck(M, i, b, m, n) && M[i][b] == 0)
			return 1;
	}
	for (int a = 0; a < 11; a++) {
		if (a != i && a != m && Oncecheck(M, i, j, a, j) && Twicecheck(M, a, j, m, n) && M[a][j] == 0)
			return 1;
	}
	return 0;
}

int Twicecheck(int** M, int i, int j, int m, int n) {
	if (Oncecheck(M, i, j, i, n) && Oncecheck(M, i, n, m, n) && M[i][n] == 0)
		return 1;
	if (Oncecheck(M, i, j, m, j) && Oncecheck(M, m, j, m, n) && M[m][j] == 0)
		return 1;
	return 0;
}

int Oncecheck(int** M, int i, int j, int m, int n) {
	int max_n, min_n;
	if (j == n && i == m)
		return 0;
	if (j == n) {
		max_n = max(i, m);
		min_n = min(i, m);
		for (int k = min_n + 1; k < max_n; k++) {
			if (M[k][j] != 0)
				return 0;
		}
		return 1;
	}
	if (i == m) {
		max_n = max(j, n);
		min_n = min(j, n);
		for (int k = min_n + 1; k < max_n; k++) {
			if (M[i][k] != 0)
				return 0;
		}
		return 1;
	}
	return 0;
}

void Show_Data(int** M) {
	cout << "Êä³ö¾ØÕó:\n";
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 19; j++) {
			cout << right << setw(4) << M[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Read_Data(int** M) {
	ifstream fin("111.txt");
	int temp;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 19; j++) {
			fin >> temp;
			M[i][j] = temp;
		}
	}
	fin.close();
}

void Copy(int** M1, int** M2) {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 19; j++) {
			M2[i][j] = M1[i][j];
		}
	}
}

int Test(int** M1, int** M2) {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 19; j++) {
			if (M2[i][j] != M1[i][j])
				return 0;
		}
	}
	return 1;
}