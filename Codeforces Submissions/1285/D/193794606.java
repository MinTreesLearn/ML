

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


	static int recursion(ArrayList<Integer> a , int bit) {
		
		if(bit == -1) {
			return 0;
		}
		
		ArrayList<Integer> zero = new ArrayList<>();
		ArrayList<Integer> one = new ArrayList<>();
		
		for(int i=0;i<a.size();i++) {
			if((( 1 << bit) & a.get(i))!= 0){
				one.add(a.get(i));
			}
			else {
				zero.add(a.get(i));
			}
		}
		
		if(zero.size() == a.size()) {
			return recursion(zero,bit-1);
		}
		if(one.size() == a.size()) {
			return recursion(one,bit-1);
		}
		
		return (1<<bit) + Math.min(recursion(zero,bit-1), recursion(one,bit-1));
	}
	public static void main(String args[]) throws Exception {

		Scanner sc = new Scanner();
		StringBuilder res = new StringBuilder();

		int tc = 1;

		while (tc-- > 0) {

			int n = sc.nextInt();

			ArrayList<Integer> a = new ArrayList<>();
			for(int i=0;i<n;i++) {
				a.add(sc.nextInt());
			}
			
			res.append(recursion(a,30));
		}
		System.out.println(res);
	}
}
