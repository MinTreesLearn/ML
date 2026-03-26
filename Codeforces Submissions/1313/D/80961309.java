import java.io.*;
import java.util.*;
public class Sol{
	static class event implements Comparable<event>{
		int type;
		int pos;
		int id;
		int bit;
		public event(int type, int pos, int id) {
			this.type = type;
			this.pos = pos;
			this.id = id;
			bit = 0;
		}
		public int compareTo(event e) {
			if(e.pos==this.pos) {
				return Integer.compare(this.type,e.type);
			}else {
				return Integer.compare(this.pos, e.pos);
			}
		}
	}
	public static int n, m, k;
	public static event arr[];
	public static int dp[][];
	public static int parity[];
	public static TreeMap<Integer, Integer> mp = new TreeMap<>();
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		n = sc.nextInt();
		m = sc.nextInt();
		k = sc.nextInt();
		dp = new int[1<<8][2*n];
		parity = new int[1<<8];
		arr = new event [2*n];
		for(int i=0; i<1<<8; ++i) {
			Arrays.fill(dp[i], -1);
			parity[i] = Integer.bitCount(i)%2;
		}
		boolean used[] = new boolean[8];
		for(int i=0; i<n; ++i) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			arr[2*i] = new event(0, l, i);
			arr[2*i+1] = new event(1, r, i);
		}
		Arrays.sort(arr);
		for(int i=0; i<2*n; ++i) {
			if(arr[i].type==0) {
				while(used[arr[i].bit]) {
					arr[i].bit++;
				}
				used[arr[i].bit]= true; 
				mp.put(arr[i].id, arr[i].bit);
			}else {
				arr[i].bit = mp.get(arr[i].id);
				used[arr[i].bit] = false; 
			}
		}
		out.println(go(0, 0));
		out.close();
	}
	public static int go(int msk, int idx) {
		//System.out.println(msk + " " + idx);
		if(idx>=2*n) return 0;
		if(dp[msk][idx]!=-1) return dp[msk][idx];
		int ans = 0;
		if(arr[idx].type==1) {
			int nxt = idx;
			int nxtmsk = msk;
			while(nxt<2*n&&arr[nxt].pos==arr[idx].pos) {
				nxtmsk&=~(1<<arr[nxt++].bit);
			}
			int dist = 0;
			if(nxt<2*n) {
				dist = arr[nxt].pos-arr[idx].pos-1;
			}
			//System.out.println(dist);
			//System.out.println(nxtmsk);
			ans = parity[msk] + dist*parity[nxtmsk] + go(nxtmsk, nxt);
		}else {
			int dist = 0;
			if(idx+1<2*n) {
				dist = arr[idx+1].pos-arr[idx].pos;
			}
			ans = parity[msk|(1<<arr[idx].bit)]*dist  + go(msk|(1<<arr[idx].bit), idx+1);
			ans = Math.max(ans, parity[msk]*dist + go(msk, idx+1));
		}
		//System.out.println(ans);
		return dp[msk][idx] = ans;
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