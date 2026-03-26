import java.io.*;
import java.util.*;
 
public class ProblemD {
 
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner();
		int test = in.readInt();
		int x = in.readInt();
		int count[] = new int[x];
		StringBuilder sb = new StringBuilder();
		
		Comparator<Pair>cmp = new Comparator<Pair>(){

			@Override
			public int compare(Pair a, Pair b) {
				return a.x == b.x? a.y - b.y: a.x - b.x; 
			}
			
		};
		TreeSet<Pair>set = new TreeSet<>(cmp);
		for(int i = 0;i<x;i++)set.add(new Pair(count[i],i));
		while(test-->0){
			int val = in.readInt();
			val%=x;
			set.remove(new Pair(count[val],val));
			count[val]++;
			set.add(new Pair(count[val],val));
			sb.append(set.first().x * x + set.first().y);
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


