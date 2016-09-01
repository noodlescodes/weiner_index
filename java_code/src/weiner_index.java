import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;

public class weiner_index {
	
	public static ArrayList<Graph> readFromFile(String filename) {
		ArrayList<Graph> g_list = new ArrayList<Graph>();
		
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			String line = br.readLine();
			int order = line.length();
			String g = "";
			while(line != null) {
				for(int i = 0; i < order; i++) {
					g += line;
					line = br.readLine();
				}
				g_list.add(new Graph(g, order));
				g = "";
			}
			br.close();
		}
		catch(Exception e) {
		}
		
		return g_list;
	}
	
	public static void splitFile(String filename) {
		int file_number = 0;
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			PrintWriter writer;
			String line = br.readLine();
			int c = 1;
			writer = new PrintWriter("mat\\mat10_" + file_number + ".txt");
			while(line != null) {
				writer.println(line);
				c++;
				line = br.readLine();
				if(c == 1000001) {
					c = 1;
					writer.close();
					file_number++;
					writer = new PrintWriter("mat\\mat10_" + file_number + ".txt");
					System.out.println(file_number);
				}
			}
			br.close();
			writer.close();
		}
		catch(Exception e) {
		}
	}
	
	public static void main(String[] args) {	
		
		int max = 165;
		int min = 45;
		
		long startTime;
		long totalTime = System.currentTimeMillis();
		int count[] = new int[max - min + 1];
		
		for(int file_number = 0; file_number < 118; file_number++) {
			startTime = System.currentTimeMillis();
			System.out.println(file_number + " ");
			ArrayList<Graph> g_list = readFromFile("mat\\mat10_" + file_number + ".txt");
			
			for(int i = 0; i < g_list.size(); i++) {
				g_list.get(i).Floyd_Warshall();
				//System.out.println(g_list.get(i));
				//System.out.println("Weiner Index: " + g_list.get(i).WeinerIndex() + System.getProperty("line.separator"));
				if(max < g_list.get(i).WeinerIndex()) {
					max = g_list.get(i).WeinerIndex();
				}
				if(min > g_list.get(i).WeinerIndex()) {
					min = g_list.get(i).WeinerIndex();
				}
			}
			
			for(int i = 0; i < g_list.size(); i++) {
				count[g_list.get(i).WeinerIndex() - min]++;
			}
			System.out.println("Time taken: " + ((long)(System.currentTimeMillis()) - startTime));
		}
		
		for(int i = 0; i < count.length; i++) {
			System.out.println(count[i]);
		}
		
		System.out.println("Max: " + max);
		System.out.println("Min: " + min);
		System.out.println("Total time: " + ((long)(System.currentTimeMillis()) - totalTime));
	}
}