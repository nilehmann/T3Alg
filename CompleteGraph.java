import java.io.BufferedReader;
import java.io.Console;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.text.DecimalFormat;


public class CompleteGraph {
	static int V = 6105;//18632460
	static int E = 7035;
	
	static List<Pair> graph[] = new ArrayList[V];
	static DecimalFormat df = new DecimalFormat("0.000000");
		
	static double dist[][];
	
	
	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("Graphs/OL.cedge"));
		
		readGraph();
		completeGraph();		
	}
	
	static void completeGraph() throws IOException{
		PrintWriter out = new PrintWriter(new FileWriter("Graphs/Complete.cedge")); 
		dist = new double[V][V];
		
		
		for (int i = 0; i < V; i++)
			dijkstra(i, dist[i]);

		System.out.println("Fin Dijkstra");
		
		int c = 0;
		for(int i = 0; i < V; ++i)
			for(int j = i+1; j < V; ++j)
				out.println((c++)+" "+i+" "+j+" "+df.format(dist[i][j]));

		out.close();
		System.out.println(c);
		
	}
	
	static void readGraph() throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		for (int i = 0; i < V; i++) 
			graph[i] = new ArrayList<Pair>();
		

		
		
		for (int i = 0; i < E; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			st.nextToken();
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			double dist = Double.parseDouble(st.nextToken());

			graph[n1].add(new Pair(n2,dist));
			graph[n2].add(new Pair(n1,dist));	
			
		}
	}
	
	
	static void dijkstra(int s, double dist[]) {
		Queue<Pair> q = new PriorityQueue<Pair>();
		
		for (int i = 0; i < V; i++) 
			dist[i] = Integer.MAX_VALUE;
		
		dist[s] = 0;
		q.offer(new Pair(s, 0));
		while (!q.isEmpty()) {
			Pair u = q.poll();
			
			if(u.dist > dist[u.node])
				continue;
			
			dist[u.node] = u.dist;
			
			for (Pair v : graph[u.node]) {				
				double new_dist = v.dist + dist[u.node];
				
				if (new_dist < dist[v.node]){
					q.offer(new Pair(v.node, new_dist));
					dist[v.node] = new_dist;
				}
			}
		}
	}
	
}

class Pair implements Comparable<Pair>{
	int node;
	double dist;

	public Pair(int k, double v) {
		node = k;
		dist = v;
	}

	public int compareTo(Pair arg) {
		if(dist < arg.dist)
			return -1;
		if(dist > arg.dist)
			return 1;
		return 0;
	}
}
