#include <iostream>
#include <list>
#include <tuple>
#include <queue>
#include <vector>
#include <stack>
#include <map>

enum edge_state {
	UNDISCOVERED,
	DISCOVERED,
	PROCESSED
};

class graph {
	public:

	graph(int n) {
		vertices = new std::list<int>[n];
		parent.reserve(n);
		n_edges = 0;
		n_vertices = n;
	}

	void insert_edge(std::tuple<int, int> edge_pair) {
		int x, y;

		std::tie(x, y) = edge_pair;
		n_edges++;

		vertices[x].push_back(y);
	}

	void bfs(int node = 0) {
		std::vector<edge_state> state(n_vertices);
		std::queue<int> q;
		std::list<int>::iterator it, end;

		state[node] = DISCOVERED;
		q.push(node);
		parent[node] = -1;

		while (q.size()) {
			node = q.front();
			process_node(node);

			it = vertices[node].begin();
			end = vertices[node].end();

			while (it != end) {
				if (state[*it] == UNDISCOVERED) {
					q.push(*it);
					state[*it] = DISCOVERED;
					parent[*it] = node;

				}
				process_edge(std::make_tuple(node, *it));
				it++;
			}

			state[node] = PROCESSED;
			q.pop();
		}
	}

	void dfs(int node = 0) {
		std::vector<int> state(n_vertices);
		dfs_internal(node, state);
	}

	int shortest_path(int node) {
		std::stack<int> s;
		int n;

		s.push(node);

		while (parent[node] != -1) {
			node = parent[node];
			s.push(node);
		}

		std::cout << "Shortest path from root to node " << node << std::endl;
		std::cout << "^ ";

		n = s.size();

		while (s.size()) {
			std::cout << s.top() << "->";
			s.pop();
		}

		std::cout << "\b\b $" << std::endl;
		return n-1;
	}

	void process_node_topological_sort(int node) {
		sorted.push(node);
	}

	void topological_sort(int node=0) {
		process_node_late = true;
		dfs(node);

		std::cout << "Topological sort" << std::endl;

		while (sorted.size()) {
			std::cout << "-> " << sorted.top();
			sorted.pop();
		}

		std::cout << std::endl;
	}

	private:
	std::list<int> *vertices;
	std::vector<int> parent;
	std::stack<int> sorted;
	int n_edges;
	int n_vertices;
	bool process_node_late;

	void process_node(int node) {
		std::cout << "Processing node " << node << std::endl;
	}

	void process_edge(std::tuple<int, int> pair) {
		int x, y;
		std::tie(x, y) = pair;
		std::cout << x << "->" << y << std::endl;
	}

	void dfs_internal(int node, std::vector<int>& state) {
		std::list<int>::iterator it, end;

		process_node(node);
		state[node] = DISCOVERED;

		it = vertices[node].begin();
		end = vertices[node].end();

		while (it != end) {
			if (state[*it] != DISCOVERED)
				dfs_internal(*it, state);
			it++;
		}

		if (process_node_late)
			sorted.push(node);

		state[node] = PROCESSED;
	}
};

void snake_and_ladder() {
	std::map<int, int> snl;
	graph g(30);
	int i, j, end;

	snl[2] = 21;
	snl[4] = 7;
	snl[10] = 25;
	snl[19] = 28;
	snl[16] = 3;
	snl[18] = 6;
	snl[20] = 8;
	snl[26] = 0;

	for (i=0; i<30; i++) {
		for (j=1; j<=6; j++) {
			end = snl[i+j] ? snl[i+j] : i+j;
			if(end < 30)
				g.insert_edge(std::make_tuple(i, end));
		}
	}

	g.bfs(0);
	std::cout << "Min throws " << g.shortest_path(29) << std::endl;
}

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
	std::cout << "BFS Traversal" << std::endl;
	g.bfs(0);
	std::cout << "DFS Traversal" << std::endl;
	g.dfs(0);
	g.shortest_path(9);

	snake_and_ladder();
}
