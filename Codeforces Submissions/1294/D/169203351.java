import java.io.*;
import java.util.*;
 
public class ProblemD {
 
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner();
		int test = in.readInt();
		int x = in.readInt();
		int count[] = new int[x];
		StringBuilder sb = new StringBuilder();
		HashMap<Integer,Integer>map = new HashMap<>();
		int mx = 0;
		while(test-->0){
			int a = in.readInt();
			count[a%x]++;
			map.put(a%x, map.getOrDefault(a%x, 0)+1);
			while(map.containsKey(mx%x) && map.get(mx%x)>0){
				map.put(mx%x,map.get(mx%x)-1);
				mx++;
			}
			sb.append(mx);
			sb.append("\n");
			
		}
		System.out.println(sb);
		
	}
	
	public static void sort(int arr[]){
		ArrayList<Integer>list = new ArrayList<>();
		for(int it:arr)list.add(it);
		Collections.sort(list);
		for(int i = 0;i<arr.length;i++)arr[i] = list.get(i);
	}
	static class Pair{
		int x,y;
		public Pair(int x,int y){
			this.x = x;
			this.y = y;
		}
	}
	
	static class Scanner{
		BufferedReader br;
		StringTokenizer st;
		
		public Scanner(){
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
	    public String read()
	    {
	         while (st == null || !st.hasMoreElements()) {            
	            try {	st = new StringTokenizer(br.readLine()); }
	            catch (Exception e) {	e.printStackTrace(); }
	         }
	         return st.nextToken();
	     }

	     public int  readInt() { return Integer.parseInt(read()); }

	     public long readLong() { return Long.parseLong(read()); }

	     public double readDouble(){return Double.parseDouble(read());}

	     public  String readLine() throws Exception { return br.readLine(); }  
	 
	}

}


