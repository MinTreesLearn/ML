import java.io.*;
import java.util.*;

public class gotoJapan {
	public static void main(String[] args) throws java.lang.Exception {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solution solver = new Solution();
		boolean isTest = false;
		int tC = isTest ? Integer.parseInt(in.next()) : 1;
		for (int i = 1; i <= tC; i++)
			solver.solve(in, out, i);
		out.close();
	}

	/* ............................................................. */
	static class Solution {
		InputReader in;
		PrintWriter out;

		public void solve(InputReader in, PrintWriter out, int test) {
			this.in = in;
			this.out = out;
			int n=ni();
			int m=ni();
			int a[][]=new int[n][m];
			int b[]=new int[(1<<m)+5];
			//Arrays.fill(b, -1);
			int ind[]=new int[(1<<m)+5];
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++)a[i][j]=ni();
				
				for(int j=1;j<(1<<m);j++) {
					int min=(int)1e9;
					for(int k=0;k<m;k++) {
						if(((1<<k)&j)!=0)min=Math.min(a[i][k], min);
					}
					if(min>=b[j]) {
						ind[j]=i+1;
						b[j]=min;
					}
				}
			}
			b[0]=(int)1e9;
			int ans1=ind[(1<<m)-1],ans2=ind[(1<<m)-1],ans=b[(1<<m)-1];
			for(int i=1;i<(1<<m);i++) {
				for(int j=1;j<(1<<m);j++) {
					if((i^j)==((1<<m)-1)) {
						int x=Math.min(b[j], b[i]);
						if(x>=ans) {
							ans=x;
							ans1=ind[i];
							ans2=ind[j];
						}
					}
				}
			}
			out.println(ans1+" "+ans2);
		}

		class Pair {
			int x;
			int y;
			long w;

			Pair(int x, int y, long w) {
				this.x = x;
				this.y = y;
				this.w = w;
			}
		}

		char[] n() {
			return in.next().toCharArray();
		}

		int ni() {
			return in.nextInt();
		}

		long nl() {
			return in.nextLong();
		}

		long[] nal(int n) {
			long a[] = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nl();
			return a;
		}

		void pn(long zx) {
			out.println(zx);
		}

		void pn(String sz) {
			out.println(sz);
		}

		void pn(double dx) {
			out.println(dx);
		}

		void pn(long ar[]) {
			for (int i = 0; i < ar.length; i++)
				out.print(ar[i] + " ");
			out.println();
		}

		void pn(String ar[]) {
			for (int i = 0; i < ar.length; i++)
				out.println(ar[i]);
		}

	}

	/* ......................Just Input............................. */
	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
	/* ......................Just Input............................. */

}