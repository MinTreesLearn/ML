import java.io.*;
import java.util.*;

public class A{
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        // int T = fs.nextInt();
        // for (int tt=0; tt<T; tt++) {

        // }
		int n = fs.nextInt();
		int a = fs.nextInt();
		int b = fs.nextInt();
		int k = fs.nextInt();
		int[][] arr = new int[n][2];
		int sum = a+b;
		for(int i=0; i<n; i++) {
			arr[i][0] = fs.nextInt();
			int mod = arr[i][0]%sum;
			if(mod==0) mod=sum;
			int skip = 0;
			if(mod>a) {
				mod-=a;
				skip = mod/a;
				if(mod%a!=0) skip++;
			}
			arr[i][1] = skip;
		}
		Arrays.sort(arr, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1]-b[1];
			}
		});
		int res = 0;
		int curSkips = 0;
		for(int i=0; i<n; i++) {
			if(curSkips+arr[i][1]>k) break;
			res++;
			curSkips+=arr[i][1];
		}
		out.println(res);
        out.close();
	}

	static final Random random=new Random();
 
    static void ruffleSort(int[] a) {
        int n=a.length;//shuffle, then sort
        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n), temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }
    
	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens()) {
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

		int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }

	}
}