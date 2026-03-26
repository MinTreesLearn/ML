import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int t=1;
		t=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for(int tt=0;tt<t;tt++) {
			long n =f.nextLong();
			int m=f.nextInt();
			int[] l=f.readArray(m);
			int[] c=new int[61];
			long sum=0;
			for(int i:l) {
				sum+=i;
				int p=0;
				while(i!=1) {
					i/=2;
					p++;
				}
				c[p]++;
			}
			if(sum<n) {
				out.println(-1);
				continue;
			}
			int ans=0;
			for(int i=0; i<60; ++i) {
				if((n>>i&1)==1) {
//					System.out.println(i);
					if(c[i]==0) {
						int j=i+1;
//						System.out.println(j);
						while(j<61 && c[j]==0)
							j++;
//						System.out.println(j);
						c[j]--;
						while(--j>=i) {
							++c[j];
							++ans;
						}
						++c[i];
					}
					--c[i];
				}
				c[i+1]+=c[i]/2;
			}
			out.println(ans);;
		}
		out.close();
	} 
	static void sort(int[] p) {
        ArrayList<Integer> q = new ArrayList<>();
        for (int i: p) q.add( i);
        Collections.sort(q);
        for (int i = 0; i < p.length; i++) p[i] = q.get(i);
    }
    
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}
} 	
//Some things to notice
//Check for the overflow
//Binary Search
//Bitmask
//runtime error most of the time is due to array index out of range