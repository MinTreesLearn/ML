import java.io.*;
import java.util.*;

public class B {
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


	public static void main(String args[]) {
		if (System.getProperty("ONLINE_JUDGE") == null) {
			// Input is a file
			try {
				System.setIn(new FileInputStream("input.txt"));
				System.setOut(new PrintStream(new FileOutputStream("output.txt")));
			} catch (Exception e) {
				System.err.println("Error");
			}
		} else {
			// Input is System.in
		}

		FastReader sc = new FastReader();
		// Scanner sc = new Scanner(System.in);
		//System.out.println(java.time.LocalTime.now());

		StringBuilder sb = new StringBuilder();
		// int t = sc.nextInt();


		// while (t > 0) {
		long n = sc.nextLong();

		int sq = (int)Math.sqrt(n);

		ArrayList<Long> al = new ArrayList<>();
		//System.out.println(sq);
		long a = 0, b = 0;

		for (int i = sq; i >= 1; i--) {
			if (n % i == 0) {
				if (gcd(i, (n / i)) == 1) {
					a = i;
					b = n / i;
					break;
				}
			}
		}

		sb.append(a + " " + b + "\n");



		// 	t--;
		// }

		System.out.println(sb);


	}





//------------------------------------------------------------------------//

	class Pair implements Comparable<Pair> {

		int a; //first member of pair
		int b; //second member of pair

		public Pair(int a,  int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public String toString() {
			return "(" + this.a + ", " + this.b + ")";
		}

		@Override
		public int compareTo(Pair o) {
			return this.a - o.a;
		}
	}



//----------------------------------------------------//
	public static void shuffleArray(int[] arr) {
		int n = arr.length;
		Random rnd = new Random();
		for (int i = 0; i < n; ++i) {
			int tmp = arr[i];
			int randomPos = i + rnd.nextInt(n - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}


//----------------------------------------------------//
	public static boolean isPowerOfTwo(long x) {
		return x != 0 && ((x & (x - 1)) == 0);
	}





//----------------------------------------------------//
	public static long digSum(long a) {
		long sum = 0;
		while (a > 0) {
			sum += a % 10;
			a /= 10;
		}

		return sum;
	}

//----------------------------------------------------//
	public static boolean isPrime(int n) {
		if (n <= 1)return false;
		if (n <= 3)return true;
		if (n % 2 == 0 || n % 3 == 0)return false;

		for (int i = 5; i * i <= n; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0)return false;
		}

		return true;
	}

//----------------------------------------------------//
	public static int nextPrime(int n) {
		while (true) {
			n++;
			if (isPrime(n)) break;

		}

		return n;
	}

//----------------------------------------------------//
	public static long gcd(long a, long b) {
		if (b == 0)return a;

		return gcd(b, a % b);
	}

//----------------------------------------------------//
	// public static int lcm(int a, int b) {
	// 	return (a * b) / gcd(a, b);
	// }


}