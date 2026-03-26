

import java.io.*;
import java.math.*;
import java.util.*;

public class test {

	static class Pair {
		int x;
		int y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;

		}
	}

	static class Compare {

		void compare(Pair arr[], int n) {
			// Comparator to sort the pair according to second element
			Arrays.sort(arr, new Comparator<Pair>() {
				@Override
				public int compare(Pair p1, Pair p2) {
					if (p1.x != p2.x) {
						return (int) (p1.x - p2.x);
					} else {
						return (int) (p1.y - p2.y);
					}
//		            	return Double.compare(a[0], b[0]);
				}
			});

//		        for (int i = 0; i < n; i++) { 
//		            System.out.print(arr[i].x + " " + arr[i].y + " "); 
//		        } 
//		        System.out.println(); 
		}
	}

	static class Scanner {
		BufferedReader br;
		StringTokenizer st;

		public Scanner() {
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

	static int function(int freq[] , int pos) {
		int nextIndex = -1;
		
		for(int i = pos + 1;i<freq.length;i++) {
			if(freq[i] != 0) {
				nextIndex = i;
				break;
			}
		}
		
		if(nextIndex == -1) {
			return nextIndex;
		}
		freq[nextIndex]--;
		
		for(int i = nextIndex-1 ; i>=pos;i--) {
			freq[i]++;
		}
		freq[pos]++;
		
		return nextIndex - pos;
	}
	public static void main(String args[]) throws Exception {

		Scanner sc = new Scanner();
		StringBuilder res = new StringBuilder();

		int tc = sc.nextInt();

		while (tc-- > 0) {

			long n = sc.nextLong();
			int m = sc.nextInt();
			
			long a[] = new long[m];
			
			for(int i=0;i<m;i++) {
				a[i] = sc.nextLong();
			}
			
			int freq[] = new int[64];
			
			for(int i=0;i<m;i++) {
				
				for(int j=0;j<64;j++) {
					if(((1L << j) & a[i] )!= 0) {
						freq[j]++;
						break;
					}
				}
			}
			
			int cnt = 0;
			
			for(int i=0;i<64;i++) {
				
				int set = ((1L << i) & n )!= 0 ? 1 : 0;
				
				if(set == 1) {
					
					if(freq[i] != 0) {
						freq[i]--;
						int nextFill = freq[i] / 2;
						freq[i] = freq[i] % 2;
						freq[Math.min(63, i+1)] += nextFill;
					}
					else {
						
						int add = function(freq,i);
						if(add == -1) {
							cnt = -1;
							break;
						}
						else {
							cnt += add;
						}
					}
				}
				else {
					
					int nextFill = freq[i] / 2;
					freq[i] = freq[i] % 2;
					freq[Math.min(63, i+1)] += nextFill;
				}
			}
			
			res.append(cnt+"\n");
		}
		System.out.println(res);
	}
}
