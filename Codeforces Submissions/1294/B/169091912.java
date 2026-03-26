import java.io.*;
import java.util.*;
 
public class ProblemB {
 
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner();
		StringBuilder sb = new StringBuilder();
		int test = in.readInt();
		while(test-->0){
			int n = in.readInt();
			ArrayList<Pair>list = new ArrayList<>();
			list.add(new Pair(0,0));
			for(int i = 0;i<n;i++){
				String line[] = in.readLine().split(" ");
					list.add(new Pair(Integer.parseInt(line[0]),Integer.parseInt(line[1])));
			}
			Comparator<Pair>cmp = new Comparator<Pair>(){

				@Override
				public int compare(Pair a, Pair b) {
					return a.x == b.x? a.y - b.y: a.x - b.x;
				}
				
			};
			Collections.sort(list,cmp);
			
			StringBuilder res = new StringBuilder();
			boolean ok = true;
			for(int i=1;i<=n;i++){
				//System.out.println(list.get(i).x+" "+list.get(i).y);
				if(list.get(i-1).x<=list.get(i).x && list.get(i-1).y<=list.get(i).y){
					int x = list.get(i).x - list.get(i-1).x;
					int y = list.get(i).y - list.get(i-1).y;
					if(x>0)res.append(String.join("", Collections.nCopies(x, "R")));
					if(y>0)res.append(String.join("", Collections.nCopies(y, "U")));
				}else ok = false;
			}
			if(ok){
				sb.append("YES");
				sb.append("\n");
				sb.append(res);
			}else sb.append("NO");
			
			sb.append("\n");
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


