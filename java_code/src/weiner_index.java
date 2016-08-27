public class weiner_index {
	
	public static void main(String[] args) {
		Graph g = new Graph(6);
		
		g.AddUndirectedEdge(0, 1);
		g.AddUndirectedEdge(1, 2);
		g.AddUndirectedEdge(2, 3);
		g.AddUndirectedEdge(3, 4);
		g.AddUndirectedEdge(4, 5);
		g.AddUndirectedEdge(5, 0);
		g.AddUndirectedEdge(2, 5);
		
		g.Floyd_Warshall();
		
		System.out.println(g);
		System.out.println("Weiner Index: " + g.WeinerIndex() + System.getProperty("line.separator"));
	}
}