#include<iostream>
#include<fstream>
#include<ctime>
#include"Dijkstra.h"
using namespace std;
int main() {
	clock_t start_t, end_t;
	start_t = clock();
	int vernum, edgenum;
	ifstream fin("data.txt");     //起始点数据为1
	fin >> vernum >> edgenum;
	Graph_DG G(vernum, edgenum);
	int start, end, weight;
	for (int i = 0; i < edgenum; i++) {
		fin >> start >> end >> weight;
		G.Create(start, end, weight);
	}
	
	G.Dijkstra(1760);
	G.Print_Path(1760);
	G.Print_Start_End(669);
	//G.Print_G();
	//G.Dijkstra(1);
	//G.Print_Path(1);
	end_t = clock();
	cout << end_t - start_t << " ms\n";
}

/*
6 8
1 3 10
1 5 30
1 6 100
2 3 5
3 4 50
4 6 10
5 6 60
5 4 20
*/