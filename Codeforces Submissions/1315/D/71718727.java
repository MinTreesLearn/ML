import java.io.*;
import java.util.*;


public class  Main{
	static class publ implements Comparable<publ>{
		int val,t,idx;
		publ(int v,int time,int i){
			val=v;
			t=time;
			idx=i;
		}
		@Override
		public int compareTo(publ o) {
			// TODO Auto-generated method stub
			return val-o.val;
		}
		
	}
	static class publ2 implements Comparable<publ2>{
		int val,t,idx;
		publ2(int v,int time,int i){
			val=v;
			t=time;
			idx=i;
		}
		@Override
		public int compareTo(publ2 o) {
			// TODO Auto-generated method stub
			return t-o.t;
		}
		
	}
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt();
		int[]in=sc.takearr(n);
		int[]t=sc.takearr(n);
		publ[]arr=new publ[n];
		for(int i=0;i<n;i++) {
			arr[i]=new publ(in[i], t[i],i);
		}
		Arrays.sort(arr);
		PriorityQueue<publ2>pq=new PriorityQueue<publ2>(Collections.reverseOrder());
		int i=0;
		long ans=0;
		while(i<n) {
				long val=arr[i].val;
				while(i<n && arr[i].val==val) {
					pq.add(new publ2(arr[i].val, arr[i].t,arr[i].idx));
					i++;
				}
				
				long put=val;
				while((i==n || put<arr[i].val) && !pq.isEmpty()) {
					publ2 cur=pq.poll();
					//System.out.println(cur.val+" "+put+" "+cur.t);
					ans+=(put-cur.val)*1l*cur.t;
					put++;
				}
			
			
		}
		pw.println(ans);
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