import java.util.ArrayList;

public class Graph {
	private int[][] adjacency_matrix;
	private int[][] shortest_path;
	
	private boolean SHORTEST_PATH_GOOD;
	
	public Graph() {
		adjacency_matrix = new int[1][1];
		shortest_path = new int[1][1];
		reset_shortest_path();
	}
	
	public Graph(int size){
		adjacency_matrix = new int[size][size];
		shortest_path = new int[size][size];
		reset_shortest_path();
	}
	
	public Graph(int[][] adj_mat) {
		adjacency_matrix = adj_mat; // is this how memory works in java?
	}
	
	void AddUndirectedEdge(int i, int j) {
		adjacency_matrix[i][j] = 1;
		adjacency_matrix[j][i] = 1;
		SHORTEST_PATH_GOOD = false;
	}
	
	void AddDirectedEdge(int i, int j) {
		adjacency_matrix[i][j] = 1;
		SHORTEST_PATH_GOOD = false;
	}
	
	int GetEntry(int i, int j) {
		return adjacency_matrix[i][j];
	}
	
	int GetShortest(int i, int j) {
		return shortest_path[i][j];
	}
	
	int GetSize() {
		return adjacency_matrix.length;
	}
	
	void Floyd_Warshall() {
		if(!SHORTEST_PATH_GOOD) {
			reset_shortest_path();
		}
		
		for(int i = 0; i < shortest_path.length; i++) {
			shortest_path[i][i] = 0;
		}
		
		for(int i = 0; i < shortest_path.length; i++) {
			for(int j = 0; j < shortest_path.length; j++) {
				if(adjacency_matrix[i][j] == 1) {
					shortest_path[i][j] = 1;
				}
			}
		}
		
		for(int k = 0; k < shortest_path.length; k++) {
			for(int i = 0; i < shortest_path.length; i++) {
				for(int j = 0; j < shortest_path.length; j++) {
					if(shortest_path[i][j] > shortest_path[i][k] + shortest_path[k][j]) {
						shortest_path[i][j] = shortest_path[i][k] + shortest_path[k][j];
					}
				}
			}
		}
	}
	
	int WeinerIndex() {
		int weiner_index = 0;
		
		if(!SHORTEST_PATH_GOOD) {
			Floyd_Warshall();
		}
		
		for(int i = 0; i < shortest_path.length; i++) {
			for(int j = i + 1; j < shortest_path[i].length; j++) {
				weiner_index += shortest_path[i][j];
			}
		}
		
		return weiner_index;
	}
	
	private void reset_shortest_path() {
		for(int i = 0; i < shortest_path.length; i++) {
			for(int j = 0; j < shortest_path.length; j++) {
				shortest_path[i][j] = (Integer.MAX_VALUE >> 1) - 1;
			}
		}
	}
	
	public String toString() {
		StringBuilder result = new StringBuilder();
		String NEW_LINE = System.getProperty("line.separator");
		
		result.append("Adjacency Matrix:" + NEW_LINE + NEW_LINE);
		for(int i = 0; i < adjacency_matrix.length; i++) {
			for(int j = 0; j < adjacency_matrix.length; j++) {
				result.append(adjacency_matrix[i][j] + " ");
			}
			result.append(NEW_LINE);
		}
		
		result.append(NEW_LINE);
		
		result.append("Shortest Paths:" + NEW_LINE + NEW_LINE);
		for(int i = 0; i < adjacency_matrix.length; i++) {
			for(int j = 0; j < adjacency_matrix.length; j++) {
				result.append(GetShortest(i, j) + " ");
			}
			result.append(NEW_LINE);
		}
		
		return result.toString();
	}
}