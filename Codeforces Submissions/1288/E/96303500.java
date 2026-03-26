
import java.util.*;
import java.lang.*;
import java.io.*;
 
public class Main {
	static int[] ft;
	static void update(int i, int n, int x) {
		while (i < n) {
			ft[i] += x;
			i |= i + 1;
		}
	}
	static int query(int i) {
		int x = 0;
		while (i >= 0) {
			x += ft[i];
			i &= i + 1; i--;
		}
		return x;
	}    
	public static void r(int arr[],int l,int m,int r) {
		int n1=m-l+1;
		int n2=r-m;
		int L[]=new int[n1];
		int R[]=new int[n2];
		for(int i=0;i<n1;i++)
		{
		  L[i]=arr[l+i];
		}
		for(int j=0;j<n2;j++)
		{
		  R[j]=arr[m+1+j];
		}
		int i=0;
		int j=0;
		int k=l;
		while(i<n1 && j<n2)
		{
		  if(L[i]<=R[j])
		  {
			arr[k]=L[i];
			++i;
		  }
		  else{
			arr[k]=R[j];
			++j;
		  }
		  ++k;
		}
		while(i<n1)
		{
		  arr[k]=L[i];
		  ++i;
		  ++k;
		}
		while(j<n2)
		{
		  arr[k]=R[j];
		  ++j;
		  ++k;
		}
	}
	public static void r2(int arr[],int l,int r)
	{
	  if(l<r)
	  {
		int m=(l+r)/2;
		r2(arr,l,m);
		r2(arr,m+1,r);
		r(arr,l,m,r);
	
	  }
	}
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;
 
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
 
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(next());
		}
 
		long nextLong() {
			return Long.parseLong(next());
		}
 
		double nextDouble() {
			return Double.parseDouble(next());
		}
 
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	} 
	static int gcd(int a, int b) 
	{ 
		if (a == 0) 
			return b; 
		return gcd(b % a, a); 
	}	

public static void main(String args[]) throws Exception
{
//  try {
// //   FileOutputStream output=new FileOutputStream("C:\\Users\\icons\\Desktop\\java\\output.txt");
// //   PrintStream out=new PrintStream(output);
// //   Diverting the output stream into file "temp.out".Comment the below line to use console
// //   System.setOut(out);
  
//   InputStream input=new FileInputStream("C:\\Users\\icons\\Desktop\\java\\input.txt");
//   //Diverting the input stream into file "temp.in".Comment the below line to use console
//   System.setIn(input);
  
//  } catch (FileNotFoundException e) {
//   e.printStackTrace();
//  }
  FastReader sc = new FastReader();
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] ii = new int[m];
		for (int h = 0; h < m; h++)
			ii[h] = sc.nextInt() - 1;
		int[] imin = new int[n];
		int[] imax = new int[n];
		for (int i = 0; i < n; i++)
			imin[i] = imax[i] = i;
		for (int h = 0; h < m; h++)
			imin[ii[h]] = 0;
		int[] hh = new int[n];
		Arrays.fill(hh, m);
		for (int h = m - 1; h >= 0; h--)
			hh[ii[h]] = h;
		ft = new int[m];
		for (int i = n - 1; i >= 0; i--) {
			imax[i] += query(hh[i] - 1);
			update(hh[i], m, 1);
		}
		Arrays.fill(ft, 0);
		Arrays.fill(hh, m);
		for (int h = m - 1; h >= 0; h--) {
			int i = ii[h];
			imax[i] = Math.max(imax[i], query(hh[i] - 1));
			update(hh[i], m, -1);
			hh[i] = h;
			update(hh[i], m, 1);
		}
		for (int i = 0; i < n; i++)
			System.out.println((imin[i] + 1) + " " + (imax[i] + 1));
	}
}
