#include<stack>
#include"Dijkstra.h"

Graph_DG::Graph_DG(int vernum, int edgenum) {
	this->vernum = vernum;
	this->edgenum = edgenum;
	arc = new int* [vernum];
	for (int i = 0; i < vernum; i++) {
		arc[i] = new int[vernum];
		for (int j = 0; j < vernum; j++) {
			arc[i][j] = INT_MAX;
		}
	}
	dis = new Dis[vernum];
}

Graph_DG::~Graph_DG() {
	delete[] dis;
	for (int i = 0; i < vernum; i++)
		delete[] arc[i];
	delete arc;
}

void Graph_DG::Create_G() {
	int start, end, weight;
	for (int i = 0; i < edgenum; i++) {
		std::cin >> start >> end >> weight;
		arc[start - 1][end - 1] = weight;
	}
}

void Graph_DG::Create(int start, int end, int weight) {
	arc[start - 1][end - 1] = weight;
	arc[end - 1][start - 1] = weight;   //无向图
}

void Graph_DG::Print_G() {
	std::cout << "\n邻接矩阵为:\n";
	for (int i = 0; i < vernum; i++) {
		for (int j = 0; j < vernum; j++) {
			if (arc[i][j] != INT_MAX)
				std::cout << arc[i][j] << " ";
			else
				std::cout << "∞" << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void Graph_DG::Dijkstra(int begin) {
	for (int i = 0; i < vernum; i++) {
		dis[i].visited = false;
	}
	for (int i = 0; i < vernum; i++) {
		dis[i].value = arc[begin - 1][i];
		dis[i].path = "v" + std::to_string(begin) + "-->v" + std::to_string(i + 1);
	}
	dis[begin - 1].visited = true;
	dis[begin - 1].value = 0;

	int temp = 0;
	int min = INT_MAX;
	for (int count = 1; count < vernum; count++) {
		min = INT_MAX;
		temp = 0;
		for (int i = 0; i < vernum; i++) {
			if (!dis[i].visited && dis[i].value < min) {
				min = dis[i].value;
				temp = i;
			}
		}
		dis[temp].visited = true;
		for (int i = 0; i < vernum; i++) {
			if (!dis[i].visited && arc[temp][i] != INT_MAX && (arc[temp][i] + dis[temp].value) < dis[i].value) {
				dis[i].value = arc[temp][i] + dis[temp].value;
				dis[i].path = dis[temp].path + "-->v" + std::to_string(i + 1);
			}
		}
	}
}

void Graph_DG::Print_Path(int begin) {
	std::cout << "以" << "v" + std::to_string(begin) << "为起点的图的最短路径为：" << std::endl;
	for (int i = 0; i < vernum; i++) {
		if (dis[i].value != INT_MAX)
			std::cout << dis[i].path << " = " << dis[i].value << std::endl;
		else
			std::cout << dis[i].path << "是无最短路径的" << std::endl;
	}
}

void Graph_DG::Print_Start_End(int end) {
	if (dis[end - 1].value != INT_MAX)
		std::cout << dis[end - 1].path << " = " << dis[end - 1].value << std::endl;
	else
		std::cout << dis[end - 1].path << "是无最短路径的" << std::endl;
}