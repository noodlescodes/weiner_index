#include <cstdlib>
#include <iostream>
#include "Graph.h"

using namespace std;
using namespace VAN_MAASTRICHT;

int main(int argc, char* argv[]) {
	Graph g = Graph(6);

	g.AddUndirectedEdge(0, 1);
	g.AddUndirectedEdge(1, 2);
	g.AddUndirectedEdge(2, 3);
	g.AddUndirectedEdge(3, 4);
	g.AddUndirectedEdge(4, 5);
	g.AddUndirectedEdge(5, 0);
	g.AddUndirectedEdge(2, 5);

	g.Floyd_Warshall();

	cout << g << endl;

	cout << "Weiner Index: " << g.WeinerIndex() << endl;
}
