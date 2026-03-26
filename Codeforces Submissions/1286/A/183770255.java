

import java.io.*;
import java.math.*;
import java.util.*;

// @author : Dinosparton 

public class test {

	static class Pair {
		Double x;
		int y;

		Pair(Double x, int y) {
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

	static int dp[][][][];

	static int recursion(int p[], int index,int odd,int even,int last) {
       
		if (index == p.length) {
			return 0;
		}

		if(dp[index][odd][even][last] != -1) {
			return dp[index][odd][even][last];
		}
		if(p[index] == 0) {
			
			int pos1 = 1000;
			int pos2 = 1000;
			
			if(odd > 0) {
				 pos1 = (last!=0 && last == 1 ? 0 : 1) + recursion(p,index+1,odd-1,even,1);
			}
			if(even > 0) {
				 pos2 = (last!=0 && last == 2 ? 0 : 1) + recursion(p,index+1,odd,even-1,2);
			}
			
			return dp[index][odd][even][last] = Math.min(pos1, pos2);
		}
		return dp[index][odd][even][last] = (last!=0 && last == p[index] ? 0 : 1) + recursion(p,index+1,odd,even,p[index]);
	}

	public static void main(String args[]) throws Exception {

		Scanner sc = new Scanner();
		StringBuilder res = new StringBuilder();

		int tc = 1;

		while (tc-- > 0) {

			int n = sc.nextInt();

			int p[] = new int[n];

			for (int i = 0; i < n; i++) {
				p[i] = sc.nextInt();
			}

			boolean visit[] = new boolean[n + 1];

			for (int i = 0; i < n; i++) {
				if (p[i] != 0) {
					visit[p[i]] = true;
				}
			}

			for (int i = 0; i < n; i++) {
				if (p[i] == 0) {
					continue;
				} else {

					p[i] = (p[i] % 2 == 0) ? 2 : 1;
				}
			}
			int odd = 0;
			int even = 0;

			for (int i = 1; i <= n; i++) {
				if (!visit[i]) {
					if (i % 2 == 0) {
						even++;
					} else {
						odd++;
					}
				}
			}

			dp = new int[n+1][odd + 1][even + 1][3];

			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= odd; j++) {
					for (int k = 0; k <= even; k++) {
						for(int l=0;l<3;l++) {
							dp[i][j][k][l] = -1;
						}
						
					}
				}
			}
//            System.out.println(odd);
			res.append(recursion(p, 0,odd,even,0) - 1 + "\n");
		}
		System.out.println(res);
	}
}
