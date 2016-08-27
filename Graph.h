#ifndef VM_GRAPH
#define VM_GRAPH

#include <vector>
#include <cstdlib>
#include <ostream>

using namespace std;


namespace VAN_MAASTRICHT {
	class Graph {
	public:
		Graph();
		Graph(unsigned int size);
		Graph(vector<vector<unsigned int> > adj_mat);
		
		
	private:
		vector<vector<unsigned int> > adjacency_matrix;
		vector<vector<unsigned int> > shortest_path;
	};

	ostream& operator <<(ostream& outs, const Graph& graph);
}

#endif
