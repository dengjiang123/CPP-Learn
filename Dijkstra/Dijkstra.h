#include<iostream>
#include<string>
#include<fstream>

struct Dis {
	int value;
	bool visited;
	std::string path;
	Dis() {
		value = 0;
		visited = false;
		path = "";
	}
};

class Graph_DG {
private:
	int vernum;
	int edgenum;
	int** arc;
	Dis* dis;
public:
	Graph_DG(int vernum, int edgenum);
	~Graph_DG();
	void Create_G();
	void Create(int start, int end, int weight);
	void Print_G();
	void Dijkstra(int begin);
	void Print_Path(int begin);
	void Print_Start_End(int end);
};