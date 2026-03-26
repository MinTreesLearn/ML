import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int ttt=1;
//		ttt=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for(int tt=0;tt<ttt;tt++) {
			int n=f.nextInt();
			int[] arr=f.readArray(n);
			int[][] l=new int[n][30];
			for(int i=0;i<n;i++) {
				int num=arr[i];
				int ind=0;
				while(num>0) {
					l[i][ind++]=num%2;
					num/=2;
				}
			}
			int num=-1;
			for(int i=29;i>-1;i--) {
				int count=0;
				int curr=-1;
				for(int j=0;j<n;j++) {
					if(l[j][i]==1) {
						count++;
						curr=j;
					}
				}
				if(count==1) {
					num=curr;
					break;
				}
			}
			if(num>-1) {
				int temp=arr[num];
				arr[num]=arr[0];
				arr[0]=temp;
			}
			for(int i:arr) System.out.print(i+" ");
			System.out.println();
		}
		out.close();
	} 
	static void sort(int[] p) {
        ArrayList<Integer> q = new ArrayList<>();
        for (int i: p) q.add( i);
        Collections.sort(q);
        for (int i = 0; i < p.length; i++) p[i] = q.get(i);
    }
    static long gcd(long a,long b) {
    	if(a==0) return b;
    	return gcd(b%a,a);
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