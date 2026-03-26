import java.io.*;
import java.util.*;
 
public class ProblemB {
 
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner();
		StringBuilder sb = new StringBuilder();
		int test = s.readInt();
		while(test-->0){
			int n = s.readInt();
			String ss = s.readLine();
			
			int x =0,y = 0;
			String pos = x+" "+y;
			HashMap<String,Integer>map = new HashMap<>();
			String ans = "";
			int min = Integer.MAX_VALUE;
			map.put(pos, -1);
			for(int i = 0;i<n;i++){
				if(ss.charAt(i) == 'R')x++;
				else if(ss.charAt(i) == 'U')y++;
				else if(ss.charAt(i) == 'D')y--;
				else x--;
				pos = x+" "+y;
				if(map.containsKey(pos)){
					int dis = i - map.get(pos)+1 ;
					if(dis<min){
						min = dis;
						ans = map.get(pos)+2 +" "+(i+1);
					}
				}
				map.put(pos, i);
			}
			System.out.println(min==Integer.MAX_VALUE?-1:ans);
		}
		
		System.out.println(sb);
		
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

	     public String readLine() throws IOException{ return br.readLine(); }
	 
	}

}


