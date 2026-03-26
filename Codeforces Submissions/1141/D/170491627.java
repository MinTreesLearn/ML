	import java.io.*;
	import java.util.*;
	
	 
	public class ProblemA {
	 
		public static void main(String[] args) throws Exception {
			Scanner in = new Scanner();
			StringBuilder sb = new StringBuilder();
			int n  = in.readInt();
			String a = in.readLine();
			String b  = in.readLine();
			TreeSet<Integer>seta[]  = new TreeSet[27];
			TreeSet<Integer>setb[]  = new TreeSet[27];
			for(int i = 0;i<=26;i++){
				seta[i] = new TreeSet<>();
				setb[i] = new TreeSet<>();
			}
			int count = 0;
			for(int i = 0;i<n;i++){
				if(a.charAt(i) == '?')seta[26].add(i);
				else seta[a.charAt(i)-'a'].add(i);
				if(b.charAt(i) == '?')setb[26].add(i);
				else setb[b.charAt(i)-'a'].add(i);
			}
			for(int i = 0;i<26;i++){
				while(seta[i].size()>0 && setb[i].size()>0){
					int t1 =  seta[i].first();
					int t2 = setb[i].first();
					sb.append((t1+1)+" "+(t2+1));
					seta[i].remove(t1);setb[i].remove(t2);
					sb.append("\n");
					count++;
				}
			}
			for(int i = 0;i<26;i++){
				while(seta[26].size()>0 && setb[i].size()>0){
					int t1 =  seta[26].first();
					int t2 = setb[i].first();
					sb.append((t1+1)+" "+(t2+1));
					seta[26].remove(t1);setb[i].remove(t2);
					sb.append("\n");
					count++;
				}
			}
			for(int i = 0;i<26;i++){
				while(seta[i].size()>0 && setb[26].size()>0){
					int t1 =  seta[i].first();
					int t2 = setb[26].first();
					sb.append((t1+1)+" "+(t2+1));
					seta[i].remove(t1);setb[26].remove(t2);
					sb.append("\n");
					count++;
				}
			}
			while(seta[26].size()>0 && setb[26].size()>0){
				int t1 =  seta[26].first();
				int t2 = setb[26].first();
				sb.append((t1+1)+" "+(t2+1));
				seta[26].remove(t1);setb[26].remove(t2);
				sb.append("\n");
				count++;
			}
			System.out.println(count);
			System.out.println(sb);
			
			
			
			
			
	}
		public static int parity(int a){
			return a%2;
		}
		public static void swap(int a[],int i, int j){
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		
		public static boolean subsequence(String cur,String t){
			int pos = 0;
			for(int i = 0;i<cur.length();i++){
				if(pos<t.length() && cur.charAt(i) == t.charAt(pos)){
					pos++;
				}
			}
			return pos == t.length();
		}
		public static long gcd(long a, long b){
			return b ==0 ?a:gcd(b,a%b);
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
	
	
