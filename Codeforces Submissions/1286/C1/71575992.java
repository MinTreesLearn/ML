import java.io.*;
import java.util.*;


public class  Main{
	static int getSum(int i) {
		return (i*(i+1))/2;
	}
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt();
		if(n==1) {
			pw.println('?'+" "+1+" "+1);
			pw.flush();
			String x=sc.nextLine();
			pw.println("! "+x);
			pw.flush();
			return;
		}
		HashMap<String, Integer>occ=new HashMap<String, Integer>();
		pw.println("? "+1+" "+n);
		pw.flush();
		int substrings=getSum(n);
		for(int i=0;i<substrings;i++) {
			String x=sc.nextLine();
			char[]xs=x.toCharArray();
			Arrays.sort(xs);
			StringBuilder sb=new StringBuilder();
			for(char c:xs) {
				sb.append(c);
			}
			x=sb.toString();
			occ.put(x, occ.getOrDefault(x, 0)+1);
		}
		
		pw.println("? "+2+" "+n);
		pw.flush();
		
		substrings=getSum(n-1);
		for(int i=0;i<substrings;i++) {
			String x=sc.nextLine();
			char[]xs=x.toCharArray();
			Arrays.sort(xs);
			StringBuilder sb=new StringBuilder();
			for(char c:xs) {
				sb.append(c);
			}
			x=sb.toString();
			occ.put(x, occ.getOrDefault(x, 0)-1);
		}
		
		String[]prefixes=new String[n];
		for(String x:occ.keySet()) {
			if(occ.get(x)==1) {
				prefixes[x.length()-1]=x;
			}
		}
		StringBuilder ans=new StringBuilder();
		for(int i=0;i<n;i++) {
			int[]chars=new int[26];
			for(int j=0;j<prefixes[i].length();j++) {
				chars[prefixes[i].charAt(j)-'a']++;
			}
			for(int j=0;j<ans.length();j++) {
				chars[ans.charAt(j)-'a']--;
			}
			for(int j=0;j<26;j++) {
				if(chars[j]==1) {
					char o=(char)('a'+j);
					ans.append(o);
					break;
				}
			}
		}
		pw.println("! "+ans);
		pw.flush();
	}
	static class MScanner {
		StringTokenizer st;
		BufferedReader br;
		public MScanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}
 
		public MScanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public int[] takearr(int n) throws IOException {
	        int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public long[] takearrl(int n) throws IOException {
	        long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public Integer[] takearrobj(int n) throws IOException {
	        Integer[]in=new Integer[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public Long[] takearrlobj(int n) throws IOException {
	        Long[]in=new Long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
 
		public char nextChar() throws IOException {
			return next().charAt(0);
		}
 
		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}