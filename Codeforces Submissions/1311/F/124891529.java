import java.util.*;
import java.io.*;

public class F_1311 {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int n = sc.nextInt();
		Pair[] array = new Pair[n];
		for(int i = 0; i < n; i++)
			array[i] = new Pair(sc.nextInt(), 0);
		for(int i = 0; i < n; i++)
			array[i].v = sc.nextInt();
		
		Arrays.sort(array);
		
		long sum = 0;
		long[] sumNeg = new long[n];
		int[] cntNeg = new int[n];
		
		for(int i = 0; i < n; i++)
			if(array[i].v < 0) {
				sumNeg[i] = array[i].x + (i == 0 ? 0 : sumNeg[i - 1]);
				cntNeg[i] = 1 + (i == 0 ? 0 : cntNeg[i - 1]);
			} else if(array[i].v > 0) {
				sumNeg[i] = i == 0 ? 0 : sumNeg[i - 1];
				cntNeg[i] = i == 0 ? 0 : cntNeg[i - 1];
				sum += 1l * cntNeg[i] * array[i].x - sumNeg[i];
			} else {
				sumNeg[i] = i == 0 ? 0 : sumNeg[i - 1];
				cntNeg[i] = i == 0 ? 0 : cntNeg[i - 1];
				sum += 1l * cntNeg[i] * array[i].x - sumNeg[i];
				sumNeg[i] += array[i].x;
				cntNeg[i] += 1;
			}
		
		TreeSet<Integer> set = new TreeSet<>();
		for(int i = 0; i < n; i++)
			if(array[i].v < 0)
				set.add(-array[i].v);
		
		TreeMap<Integer, Integer> map = new TreeMap<>();
		int index = 1;
		for(int i : set)
			map.put(i, index++);
		
		int N = 1;
		while(N < index)
			N <<= 1;
		
		SegmentTree sumTree = new SegmentTree(new long[N + 1]);
		SegmentTree cntTree = new SegmentTree(new long[N + 1]);
		
		for(int i = 0; i < n; i++)
			if(array[i].v < 0) {
				int ind = map.get(-array[i].v);
				sum += 1l * array[i].x * cntTree.query(1, ind) - sumTree.query(1, ind);
				sumTree.update_point(1, array[i].x);
				sumTree.update_point(ind + 1, -array[i].x);
				cntTree.update_point(1, 1);
				cntTree.update_point(ind + 1, -1);
			}
		
		set = new TreeSet<>();
		for(int i = 0; i < n; i++)
			if(array[i].v > 0)
				set.add(array[i].v);
		
		map = new TreeMap<>();
		index = 1;
		for(int i : set)
			map.put(i, index++);
		
		N = 1;
		while(N < index)
			N <<= 1;
		
		sumTree = new SegmentTree(new long[N + 1]);
		cntTree = new SegmentTree(new long[N + 1]);
		
		for(int i = n - 1; i >= 0; i--)
			if(array[i].v > 0) {
				int ind = map.get(array[i].v);
				sum += 1l * sumTree.query(1, ind) - 1l * array[i].x * cntTree.query(1, ind);
				sumTree.update_point(1, array[i].x);
				sumTree.update_point(ind + 1, -array[i].x);
				cntTree.update_point(1, 1);
				cntTree.update_point(ind + 1, -1);
			}
		
		pw.println(sum);
		pw.flush();
	}
	
	public static class Pair implements Comparable<Pair> {
		int x, v;
		
		public Pair(int x, int v) {
			this.x = x;
			this.v = v;
		}
		
		public int compareTo(Pair p) {
			return this.x - p.x;
		}
	}
	
	public static class SegmentTree {
		
		int N;
		long[] in, sTree;
		
		public SegmentTree(long[] array) {
			in = array;
			N = array.length - 1;
			sTree = new long[N<<1];
			build(1, 1, N);
		}
		
		public void build(int node, int b, int e) {
			if(b == e) {
				sTree[node] = in[b];
				return;
			}
			
			int left = node<<1, right = node<<1|1;
			int mid = (b + e)>>1;
			
			build(left, b, mid);
			build(right, mid + 1, e);
			
			sTree[node] = sTree[left] + sTree[right];
		}
		
		public long query(int l, int r) {
			return query(1, 1, N, l, r);
		}
		
		public long query(int node, int b, int e, int l, int r) {
			if(r < b || l > e)
				return 0;
			if(b >= l && e <= r)
				return sTree[node];
			
			int left = node<<1, right = node<<1|1;
			int mid = (b + e)>>1;
						
			return query(left, b, mid, l, r) + query(right, mid + 1, e, l, r);
		}
		
		public void update_point(int n, int v) {
			n += N - 1;
			sTree[n] += v;
			while(n > 1) {
				n /= 2;
				sTree[n] = sTree[n<<1] + sTree[n<<1|1];
			}
		}
	}

	public static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}

		public Scanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public char nextChar() throws IOException {
			return next().charAt(0);
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public int[] nextIntArray(int n) throws IOException {
			int[] array = new int[n];
			for (int i = 0; i < n; i++)
				array[i] = nextInt();
			return array;
		}

		public Integer[] nextIntegerArray(int n) throws IOException {
			Integer[] array = new Integer[n];
			for (int i = 0; i < n; i++)
				array[i] = new Integer(nextInt());
			return array;
		}

		public long[] nextLongArray(int n) throws IOException {
			long[] array = new long[n];
			for (int i = 0; i < n; i++)
				array[i] = nextLong();
			return array;
		}

		public double[] nextDoubleArray(int n) throws IOException {
			double[] array = new double[n];
			for (int i = 0; i < n; i++)
				array[i] = nextDouble();
			return array;
		}

		public static int[] shuffle(int[] a) {
			int n = a.length;
			Random rand = new Random();
			for (int i = 0; i < n; i++) {
				int tmpIdx = rand.nextInt(n);
				int tmp = a[i];
				a[i] = a[tmpIdx];
				a[tmpIdx] = tmp;
			}
			return a;
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}
