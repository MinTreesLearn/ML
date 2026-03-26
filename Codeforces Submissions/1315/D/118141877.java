import java.io.*;
import java.util.*;

public class D{
	
	public static void main(String[] args) throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		//new Thread(null, new (), "peepee", 1<<28).start();
		
		read();
		int n = RI();
		
		TreeMap<Integer, List<Integer>> hm = new TreeMap<Integer, List<Integer>>();
		int[] a = new int[n], b = new int[n];
		read();
		for (int i = 0; i < n; i++)a[i] = RI();
		read();
		for (int i = 0; i < n; i++) b[i] = RI();
		
		for (int i = 0; i < n; i++) {
			if (!hm.containsKey(a[i])) hm.put(a[i], new ArrayList<Integer>());
			hm.get(a[i]).add(b[i]);
		}
		long cost = 0;
		PriorityQueue<Integer> costs = new PriorityQueue<Integer>(Collections.reverseOrder());
		long moveup =0;
		int cur = 0;
		HashSet<Integer> placed = new HashSet<Integer>();
		while (true) {
			//System.out.println(costs + " " + cur);
			if (hm.containsKey(cur)) {
				costs.addAll(hm.get(cur));
				for (int x: hm.get(cur)) moveup+=x;
				hm.remove(cur);
			}
			else if (costs.size() > 0) {
				if (!placed.contains(cur)) {
					placed.add(cur);
					moveup-=costs.poll();
				}
				else {
					cost += moveup;
					cur++;
				}
			}
			else {
				Integer res = hm.ceilingKey(cur);
				if (res == null) break;
				cur = res;
			}
		}
		out.println(cost);
		out.close();
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	static StringTokenizer st;
	static void read() throws IOException{st = new StringTokenizer(br.readLine());}	
	static int RI() throws IOException{return Integer.parseInt(st.nextToken());}
	static long RL() throws IOException{return Long.parseLong(st.nextToken());}
	static double RD() throws IOException{return Double.parseDouble(st.nextToken());}
	
}
