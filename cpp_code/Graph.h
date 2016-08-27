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

		void AddUndirectedEdge(int i, int j);
		void AddDirectedEdge(int i, int j);
		uint GetEntry(int i, int j);
		const uint GetEntry(int i, int j) const;
		uint GetShortest(int i, int j);
		const uint GetShortest(int i, int j) const;
		uint GetSize();
		const uint GetSize() const;

		void Floyd_Warshall();
		uint WeinerIndex();
		
	private:
		vector<vector<unsigned int> > adjacency_matrix;
		vector<vector<unsigned int> > shortest_path;

		void reset_shortest_path();

		// flags
		bool SHORTEST_PATH_GOOD;
	};

	ostream& operator <<(ostream& outs, const Graph& graph);
}

#endif
