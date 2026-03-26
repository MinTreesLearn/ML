import java.io.*;
import java.util.*;
public class Sol{
	public static List<Integer> adj[];
	public static int query[][];
	public static int get[][] = new int[5000][5000];
	public static int edge[];
	public static int par[];
	public static int depth[];
	public static int n, m, D;
	public static void main(String[] args) throws IOException{
		FastIO sc = new FastIO(System.in);
		PrintWriter out = new PrintWriter(System.out);
		boolean poss = true;
		n = sc.nextInt();
		par = new int[n];
		depth = new int[n];
		edge = new int[n-1];
		adj = new ArrayList[n];
		for(int i=0; i<n; ++i) {
			adj[i] = new ArrayList<>();
		}
		int idx = 0;
		for(int i=0; i<n-1; ++i) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
			get[a][b] = idx;
			get[b][a] = idx;
			idx++;
			edge[i] = -1;
		}
		depth[0] = 0;
		par[0] = 0;
		DFS(0, 0);
		int m = sc.nextInt();
		query = new int[m][3];
		for(int i=0; i<m; ++i) {
			query[i][0] =sc.nextInt()-1;
			query[i][1] = sc.nextInt()-1;
			query[i][2] = sc.nextInt();
		}
		ColumnSort(query, 2);
		for(int i=m-1; i>=0; --i) {
			boolean change = false;
			int num = query[i][2];
			int curr1 = query[i][0];
			int curr2 = query[i][1];
			while(curr1!=curr2) {
				if(depth[curr1]>depth[curr2]) {
					idx = get[curr1][par[curr1]];
					if(edge[idx]==-1||edge[idx]==num) {
						edge[idx] = num;
						change = true;
					}
					curr1 = par[curr1];
				}else {
					idx = get[curr2][par[curr2]];
					if(edge[idx]==-1||edge[idx]==num) {
						edge[idx] = num;
						change = true;
					}
					curr2 = par[curr2];
				}
			}
			if(!change) poss = false;
		}
		if(!poss) {
			out.println(-1);
		}else {
			for(int i=0; i<n-1; ++i) {
				out.print(Math.max(edge[i], 1) + " ");
			}
			out.println();
		}
		out.close();
	}
	public static void DFS(int curr, int p) {
		for(int i: adj[curr]) {
			if(i==p) continue;
			par[i] = curr;
			depth[i] = depth[curr]+1;
			DFS(i, curr);
		}
	}
    public static void ColumnSort(int arr[][], int col) { 
        Arrays.sort(arr, new Comparator<int[]>() { 
            @Override 
          public int compare(int[] entry1,  
                             int[] entry2) { 
            	Integer a = entry1[col];
            	Integer b = entry2[col];
            	return a.compareTo(b);
          } 
        }); 
    } 
	static class FastIO {
		 
		// Is your Fast I/O being bad?
 
		InputStream dis;
		byte[] buffer = new byte[1 << 17];
		int pointer = 0;
 
		public FastIO(String fileName) throws IOException {
			dis = new FileInputStream(fileName);
		}
 
		public FastIO(InputStream is) throws IOException {
			dis = is;
		}
 
		int nextInt() throws IOException {
			int ret = 0;
 
			byte b;
			do {
				b = nextByte();
			} while (b <= ' ');
			boolean negative = false;
			if (b == '-') {
				negative = true;
				b = nextByte();
			}
			while (b >= '0' && b <= '9') {
				ret = 10 * ret + b - '0';
				b = nextByte();
			}
 
			return (negative) ? -ret : ret;
		}
 
		long nextLong() throws IOException {
			long ret = 0;
 
			byte b;
			do {
				b = nextByte();
			} while (b <= ' ');
			boolean negative = false;
			if (b == '-') {
				negative = true;
				b = nextByte();
			}
			while (b >= '0' && b <= '9') {
				ret = 10 * ret + b - '0';
				b = nextByte();
			}
 
			return (negative) ? -ret : ret;
		}
 
		byte nextByte() throws IOException {
			if (pointer == buffer.length) {
				dis.read(buffer, 0, buffer.length);
				pointer = 0;
			}
			return buffer[pointer++];
		}
 
		String next() throws IOException {
			StringBuffer ret = new StringBuffer();
 
			byte b;
			do {
				b = nextByte();
			} while (b <= ' ');
			while (b > ' ') {
				ret.appendCodePoint(b);
				b = nextByte();
			}
 
			return ret.toString();
		}
 
	}
}