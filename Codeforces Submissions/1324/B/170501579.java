import java.io.*;import java.util.*;
public class Main {
	static  FastReader fr=new FastReader();
	
		public static void main(String[] args) throws IOException {	
			int tt=1;
			tt=fr.ni();
			while(tt-->0) {
				int n=fr.ni();
				int a[]=iarr(n);
				Map<Integer,Integer> hm=new HashMap<>();
				boolean f=false;
				for(int i=0;i<n;i++) {
					if(hm.containsKey(a[i])) {
						if(i-hm.get(a[i])>1) {
//							System.out.println(i+" i here ");
							f=true;
							break;
						}
					}
					else hm.put(a[i], i);
				}
				System.out.println(f==true?"YES":"NO");
			}	
		}
		
		static void opil(List<Integer> al) {StringBuilder sb= new StringBuilder();for(int x:al)sb.append(x+" ");System.out.println(sb.toString());}
		static void opll(List<Long> al) {StringBuilder sb= new StringBuilder();for(long x:al)sb.append(x+" ");System.out.println(sb.toString());}
		static int[] iarr(int n) {int a[]=new int[n];for(int i=0;i<n;i++)a[i]=fr.ni();return a;}
		static long[] larr(int n) {long a[]=new long[n];for(int i=0;i<n;i++)a[i]=fr.nl();return a;}
		static void op(int a[]) {StringBuilder sb= new StringBuilder();for(int x:a)sb.append(x+" ");System.out.println(sb.toString());}
		static void op(long a[]) {StringBuilder sb= new StringBuilder();for(long x:a)sb.append(x+" ");System.out.println(sb.toString());}
		static void sort(int[] a) {ArrayList<Integer>l=new ArrayList<>();for(int i:a) l.add(i);Collections.sort(l);for (int i=0; i<a.length; i++) a[i]=l.get(i);}
		static void sort(long[] a) {ArrayList<Long>l=new ArrayList<>();for(long i:a) l.add(i);Collections.sort(l);for (int i=0; i<a.length; i++) a[i]=l.get(i);}
		static class FastReader {
	        BufferedReader br;
	        StringTokenizer st;
	 
	        public FastReader()
	        {
	            br = new BufferedReader(
	                new InputStreamReader(System.in));
	        }
	 
	        String next()
	        {
	            while (st == null || !st.hasMoreElements()) {
	                try {
	                    st = new StringTokenizer(br.readLine());
	                }
	                catch (IOException e) {
	                    e.printStackTrace();
	                }
	            }
	            return st.nextToken();
	        }
	 
	        int ni() { return Integer.parseInt(next()); }
	 
	        long nl() { return Long.parseLong(next()); }
	 
	        double nd()
	        {
	            return Double.parseDouble(next());
	        }
	 
	        String nextLine()
	        {
	            String str = "";
	            try {
	                str = br.readLine();
	            }
	            catch (IOException e) {
	                e.printStackTrace();
	            }
	            return str;
	        }
	    }
}
	

