#include <limits>
#include <iostream>

#include "Graph.h"

namespace VAN_MAASTRICHT {
	Graph::Graph() {
		adjacency_matrix.resize(1);
		adjacency_matrix[1].resize(1);
		shortest_path.resize(1);
		shortest_path[0].resize(1);
		reset_shortest_path();
		SHORTEST_PATH_GOOD = false;
	}

	Graph::Graph(unsigned int size) {
		adjacency_matrix.resize(size);
		shortest_path.resize(size);
		for(uint i = 0; i < size; i++) {
			adjacency_matrix[i].resize(size);
			shortest_path[i].resize(size);
		}
		SHORTEST_PATH_GOOD = false;
	}

	Graph::Graph(vector<vector<unsigned int>> adj_mat) {
		adjacency_matrix = adj_mat;
		shortest_path.resize(adjacency_matrix.size());
		for(uint i = 0; i < adjacency_matrix.size(); i++) {
			shortest_path[i].resize(adjacency_matrix.size());
		}
		SHORTEST_PATH_GOOD = false;
	}

	void Graph::AddUndirectedEdge(int i, int j) {
		adjacency_matrix[i][j] = 1;
		adjacency_matrix[j][i] = 1;
		SHORTEST_PATH_GOOD = false;
	}

	void Graph::AddDirectedEdge(int i, int j) {
		adjacency_matrix[i][j] = 1;
		SHORTEST_PATH_GOOD = false;
	}

	uint Graph::GetEntry(int i, int j) {
		return adjacency_matrix[i][j];
	}

	const uint Graph::GetEntry(int i, int j) const {
		return adjacency_matrix[i][j];
	}

	uint Graph::GetShortest(int i, int j) {
		return shortest_path[i][j];
	}

	const uint Graph::GetShortest(int i, int j) const {
		return shortest_path[i][j];
	}

	uint Graph::GetSize() {
		return adjacency_matrix.size();
	}

	const uint Graph::GetSize() const {
		return adjacency_matrix.size();
	}

	void Graph::Floyd_Warshall() {
		if(!SHORTEST_PATH_GOOD) {
			reset_shortest_path();
		}
		
		for(uint i = 0; i < shortest_path.size(); i++) {
			shortest_path[i][i] = 0;
		}
		
		for(uint i = 0; i < shortest_path.size(); i++) {
			for(uint j = 0; j < shortest_path[i].size(); j++) {
				if(adjacency_matrix[i][j] == 1) {
					shortest_path[i][j] = 1;
				}
			}
		}
		
		for(uint k = 0; k < shortest_path.size(); k++) {
			for(uint i = 0; i < shortest_path.size(); i++) {
				for(uint j = 0; j < shortest_path.size(); j++) {
					if(shortest_path[i][j] > shortest_path[i][k] + shortest_path[k][j]) {
						shortest_path[i][j] = shortest_path[i][k] + shortest_path[k][j];
					}
				}
			}
		}
		
		SHORTEST_PATH_GOOD = true;
	}

	uint Graph::WeinerIndex() {
		uint weiner_index = 0;

		if(!SHORTEST_PATH_GOOD) {
			Floyd_Warshall();
		}

		for(uint i = 0; i < shortest_path.size(); i++) {
			for(uint j = i + 1; j < shortest_path[i].size(); j++) {
				weiner_index += shortest_path[i][j];
			}
		}

		return weiner_index;
	}

	void Graph::reset_shortest_path() {
		for(uint i = 0; i < shortest_path.size(); i++) {
			for(uint j = 0; j < shortest_path[i].size(); j++) {
				shortest_path[i][j] = (numeric_limits<uint>::max() >> 1) - 1; // set to largest possible uint value divided by 2 then subtract 1.
			}
		}
		SHORTEST_PATH_GOOD = false;
	}

	ostream& operator <<(ostream& outs, const Graph& graph) {
		outs << "Adjacency Matrix:" << endl << endl;
		for(uint i = 0; i < graph.GetSize(); i++) {
			for(uint j = 0; j < graph.GetSize(); j++) {
				outs << graph.GetEntry(i, j) << " ";
			}
			outs << endl;
		}
		outs << endl;
		
		outs << "Shortest Paths:" << endl << endl;
		for(uint i = 0; i < graph.GetSize(); i++) {
			for(uint j = 0; j < graph.GetSize(); j++) {
				outs << graph.GetShortest(i, j) << " ";
			}
			outs << endl;
		}

		return outs;
	}
}
