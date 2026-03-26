	
	import java.io.*;
	import java.util.*;

	
	
	
	// SCREAM AS LOUD AS YOU CAN 
	
	
	//                      FUCK !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	public class Aqueous {
	
		static MyScanner sc = new MyScanner();
		static PrintWriter pw = new PrintWriter(System.out);
	
		static class pair{
			int k ;
			String s;
			
			public pair(int k , String s) {
				this.k = k;
				this.s = s;
			}
		}
		public static void main(String[] args) {
	
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k =sc.nextInt();
			
			int nn[] = new int[n];
			for(int i = 0; i<n; i++) {
				nn[i] = sc.nextInt();
			}
			
			int mm[] = new int[m];
			for(int i = 0; i<m;i++) {
				mm[i] = sc.nextInt();
			}
			
			int ans[] = gao(nn);
			
//			for(int e : ans) {
//				pw.print(e+" ");
//			}
//			
//			pw.println();
			int ans1[] = gao(mm);
			
//			for(int e : ans1) {
//				pw.print(e+" ");
//			}
//			pw.println();
			
			
			ArrayList<Integer> al = factors(k);
			
			
			long answer = 0;
			
			for(int e: al) {
				if(e<ans.length && (k/e)<ans1.length) {
					answer += ans[e]*ans1[k/e];
				}
			}
			
			pw.println(answer);
			pw.close();
		}
		
		static int[] gao(int a[]) {
			int n = a.length;
			
			int res[] = new int[n+1];
			int i = 0;
			
			while(i<n) {
				if(a[i]==0) {
					i++;
					continue;
				}
				
				int j = i;
				
				while(j<n && a[j]==1) {
					j++;
				}
				
				for(int len = 1; len<=j-i; len++) {
					res[len] +=j-i-len+1;
				}
				i=j;
			}
			return res;
		}
		
		static ArrayList<Integer> factors(int k){
			
			ArrayList<Integer> al = new ArrayList<>();
			al.add(1);
			
			for(int i = 2; i*i<=k; i++) {
				if(k%i==0) {
					al.add(i);
					
					if((k/i)!=i) {
						al.add(k/i);
					}
				}
			}
			
			if(!al.contains(k)) {
				al.add(k);
			}
			return al;
		}
		
	
		static void ruffleSort(int a[]) {
	
			int n = a.length;
	
			Random r = new Random();
	
			for (int i = 0; i < n; i++) {
	
				int oi = r.nextInt(n);
				int temp = a[oi];
				a[oi] = a[i];
				a[i] = temp;
			}
	
			Arrays.sort(a);
		}
	
		static void ruffleSort(long a[]) {
	
			int n = a.length;
	
			Random r = new Random();
	
			for (int i = 0; i < n; i++) {
				int oi = r.nextInt(n);
	
				long temp = a[oi];
				a[oi] = a[i];
				a[i] = temp;
			}
	
			Arrays.sort(a);
		}
	
		public static class MyScanner {
			BufferedReader br;
			StringTokenizer st;
	
			public MyScanner() {
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
	}