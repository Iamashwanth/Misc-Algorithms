#include <iostream>
#include <list>
#include <tuple>

class graph {
	public:

	graph(int n) {
		vertices = new std::list<int>[n];
		n_edges = 0;
		n_vertices = n;
	}

	void insert_edge(std::tuple<int, int> edge_pair) {
		int x, y;

		std::tie(x, y) = edge_pair;
		n_edges++;

		vertices[x].push_back(y);
	}

	private:
	std::list<int> *vertices;
	int n_edges;
	int n_vertices;
};
