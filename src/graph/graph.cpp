#include <iostream>
#include <list>
#include <tuple>
#include <queue>
#include <vector>

enum edge_state {
	UNDISCOVERED,
	DISCOVERED,
	PROCESSED
};

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

	void process_node(int node) {
		std::cout << "Processing node " << node << std::endl;
	}

	void process_edge(std::tuple<int, int> pair) {
		int x, y;
		std::tie(x, y) = pair;
		std::cout << x << "->" << y << std::endl;
	}

	void BFS(int node = 1) {
		std::vector<edge_state> state(n_vertices);
		std::queue<int> q;
		std::list<int>::iterator it, end;

		state[node] = DISCOVERED;
		q.push(node);

		while (q.size()) {
			node = q.front();
			process_node(node);

			it = vertices[node].begin();
			end = vertices[node].end();

			while (it != end) {
				if (state[*it] != DISCOVERED) {
					q.push(*it);
					state[*it] = DISCOVERED;

				}
				process_edge(std::make_tuple(node, *it));
				it++;
			}

			state[node] = PROCESSED;
			q.pop();
		}
	}

	private:
	std::list<int> *vertices;
	int n_edges;
	int n_vertices;
};

int main(void) {
	graph g(10);
	g.insert_edge(std::make_tuple(0, 7));
	g.insert_edge(std::make_tuple(0, 4));
	g.insert_edge(std::make_tuple(0, 1));
	g.insert_edge(std::make_tuple(7, 5));
	g.insert_edge(std::make_tuple(7, 3));
	g.insert_edge(std::make_tuple(7, 2));
	g.insert_edge(std::make_tuple(5, 9));
	g.insert_edge(std::make_tuple(5, 6));
	g.insert_edge(std::make_tuple(1, 8));
	g.BFS(0);
}
