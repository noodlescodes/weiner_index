#include <limits>
#include <iostream>

#include "Graph.h"

namespace VAN_MAASTRICHT {
	Graph::Graph() {
		adjacency_matrix.resize(1);
		adjacency_matrix[1].resize(1);
		shortest_path.resize(1);
		shortest_path[0].resize(1);
		shortest_path[0][0] = numeric_limits<uint>::max();
	}

	Graph::Graph(unsigned int size) {
		adjacency_matrix.resize(size);
		shortest_path.resize(size);
		for(uint i = 0; i < size; i++) {
			adjacency_matrix[i].resize(size);
			shortest_path[i].resize(size);
			for(uint j = 0; j < shortest_path[i].size(); j++) {
				shortest_path[i][j] = numeric_limits<uint>::max();
			}
		}
	}

	Graph::Graph(vector<vector<unsigned int>> adj_mat) {
		adjacency_matrix = adj_mat;
		shortest_path.resize(adjacency_matrix.size());
		cout << "test" << endl;
		for(uint i = 0; i < adjacency_matrix.size(); i++) {
			shortest_path[i].resize(adjacency_matrix.size());
			for(uint j = 0; j < shortest_path[i].size(); j++) {
				shortest_path[i][j] = numeric_limits<uint>::max();
			}
		}
	}
}
