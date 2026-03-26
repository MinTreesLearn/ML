import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;
import java.util.concurrent.locks.ReentrantReadWriteLock.WriteLock;
import java.beans.Visibility;
import java.io.File;
import java.io.FileDescriptor;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.UncheckedIOException;
import java.lang.Thread.State;
import java.lang.reflect.Field;
import java.nio.CharBuffer;
import java.nio.charset.CharacterCodingException;
import java.nio.charset.CharsetEncoder;
import java.nio.charset.StandardCharsets;

public class Main {
	static final long MOD1=1000000007;
	static final long MOD=998244353;
	static long ans=0;
	static long[] two;
	public static void main(String[] args){
		PrintWriter out = new PrintWriter(System.out);
		InputReader sc=new InputReader(System.in);
		int n = sc.nextInt();
		int[] a = sc.nextIntArray(n);
		int[][] dp = new int[n][n];
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp.length; j++) {
				dp[i][j] = Integer.MAX_VALUE/2;
			}
		}
		for (int i = 0; i < dp.length; i++) {
			dp[i][i] = -a[i];
		}
		for (int i = 2; i <= n; i++) {
			for (int l = 0; l + i - 1 < n; l++) {
				int r = l + i - 1;
				for (int k = l; k < r; k++) {
					int a_l = dp[l][k];
					int a_r = dp[k+1][r];
					if (a_l<=0&&a_r<=0){
						if(a_l==a_r) {
							dp[l][r] = -(-a_l+1);
						}else {
							dp[l][r] = 2;
						}
					}else {
						a_l = Math.max(1, a_l);
						a_r = Math.max(1, a_r);
						dp[l][r] = Math.min(dp[l][r], a_l+a_r);
					}
				}
			}
		}
		System.out.println(Math.max(1, dp[0][n-1]));
   	}
	static class InputReader { 
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;
		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}
		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}
 
		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}
 
		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}
 
		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}
 
		public boolean hasNext() {
			skip();
			return hasNextByte();
		}
 
		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
 
		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public double nextDouble() {
			return Double.parseDouble(next());
		}
 
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
		public double[] nextDoubleArray(int n) {
			double[] a = new double[n];
			for (int i = 0; i < n; i++)
				a[i] = nextDouble();
			return a;
		}
		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}
class MinCostFlow {
    private static final class InternalWeightedCapEdge {
        final int to, rev;
        long cap;
        final long cost;
        InternalWeightedCapEdge(int to, int rev, long cap, long cost) { this.to = to; this.rev = rev; this.cap = cap; this.cost = cost; }
    }

    public static final class WeightedCapEdge {
        public final int from, to;
        public final long cap, flow, cost;
        WeightedCapEdge(int from, int to, long cap, long flow, long cost) { this.from = from; this.to = to; this.cap = cap; this.flow = flow; this.cost = cost; }
        @Override
        public boolean equals(Object o) {
            if (o instanceof WeightedCapEdge) {
                WeightedCapEdge e = (WeightedCapEdge) o;
                return from == e.from && to == e.to && cap == e.cap && flow == e.flow && cost == e.cost;
            }
            return false;
        }
    }

    private static final class IntPair {
        final int first, second;
        IntPair(int first, int second) { this.first = first; this.second = second; }
    }

    public static final class FlowAndCost {
        public final long flow, cost;
        FlowAndCost(long flow, long cost) { this.flow = flow; this.cost = cost; }
        @Override
        public boolean equals(Object o) {
            if (o instanceof FlowAndCost) {
                FlowAndCost c = (FlowAndCost) o;
                return flow == c.flow && cost == c.cost;
            }
            return false;
        }
    }

    static final long INF = Long.MAX_VALUE;

    private final int n;
    private final java.util.ArrayList<IntPair> pos;
    private final java.util.ArrayList<InternalWeightedCapEdge>[] g;

    @SuppressWarnings("unchecked")
    public MinCostFlow(int n) {
        this.n = n;
        this.pos = new java.util.ArrayList<>();
        this.g = new java.util.ArrayList[n];
        for (int i = 0; i < n; i++) {
            this.g[i] = new java.util.ArrayList<>();
        }
    }

    public int addEdge(int from, int to, long cap, long cost) {
        rangeCheck(from, 0, n);
        rangeCheck(to, 0, n);
        nonNegativeCheck(cap, "Capacity");
        nonNegativeCheck(cost, "Cost");
        int m = pos.size();
        pos.add(new IntPair(from, g[from].size()));
        int fromId = g[from].size();
        int toId = g[to].size();
        if (from == to) toId++;
        g[from].add(new InternalWeightedCapEdge(to, toId, cap, cost));
        g[to].add(new InternalWeightedCapEdge(from, fromId, 0L, -cost));
        return m;
    }

    private InternalWeightedCapEdge getInternalEdge(int i) {
        return g[pos.get(i).first].get(pos.get(i).second);
    }

    private InternalWeightedCapEdge getInternalEdgeReversed(InternalWeightedCapEdge e) {
        return g[e.to].get(e.rev);
    }
    
    public WeightedCapEdge getEdge(int i) {
        int m = pos.size();
        rangeCheck(i, 0, m);
        InternalWeightedCapEdge e = getInternalEdge(i);
        InternalWeightedCapEdge re = getInternalEdgeReversed(e);
        return new WeightedCapEdge(re.to, e.to, e.cap + re.cap, re.cap, e.cost);
    }

    public WeightedCapEdge[] getEdges() {
        WeightedCapEdge[] res = new WeightedCapEdge[pos.size()];
        java.util.Arrays.setAll(res, this::getEdge);
        return res;
    }

    public FlowAndCost minCostMaxFlow(int s, int t) {
        return minCostFlow(s, t, INF);
    }
    public FlowAndCost minCostFlow(int s, int t, long flowLimit) {
        return minCostSlope(s, t, flowLimit).getLast();
    }
    java.util.LinkedList<FlowAndCost> minCostSlope(int s, int t) {
        return minCostSlope(s, t, INF);
    }

    public java.util.LinkedList<FlowAndCost> minCostSlope(int s, int t, long flowLimit) {
        rangeCheck(s, 0, n);
        rangeCheck(t, 0, n);
        if (s == t) {
            throw new IllegalArgumentException(
                String.format("%d and %d is the same vertex.", s, t)
            );
        }
        long[] dual = new long[n];
        long[] dist = new long[n];
        int[] pv = new int[n];
        int[] pe = new int[n];
        boolean[] vis = new boolean[n];
        long flow = 0;
        long cost = 0, prev_cost = -1;
        java.util.LinkedList<FlowAndCost> result = new java.util.LinkedList<>();
        result.addLast(new FlowAndCost(flow, cost));
        while (flow < flowLimit) {
            if (!dualRef(s, t, dual, dist, pv, pe, vis)) break;
            long c = flowLimit - flow;
            for (int v = t; v != s; v = pv[v]) {
                c = Math.min(c, g[pv[v]].get(pe[v]).cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                InternalWeightedCapEdge e = g[pv[v]].get(pe[v]);
                e.cap -= c;
                g[v].get(e.rev).cap += c;
            }
            long d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost == d) {
                result.removeLast();
            }
            result.addLast(new FlowAndCost(flow, cost));
            prev_cost = cost;
        }
        return result;
    }

    private boolean dualRef(int s, int t, long[] dual, long[] dist, int[] pv, int[] pe, boolean[] vis) {
        java.util.Arrays.fill(dist, INF);
        java.util.Arrays.fill(pv, -1);
        java.util.Arrays.fill(pe, -1);
        java.util.Arrays.fill(vis, false);
        class State implements Comparable<State> {
            final long key;
            final int to;
            State(long key, int to) { this.key = key; this.to = to; }
            public int compareTo(State q) {
                return key > q.key ? 1 : -1;
            }
        };
        java.util.PriorityQueue<State> pq = new java.util.PriorityQueue<>();
        dist[s] = 0;
        pq.add(new State(0L, s));
        while (pq.size() > 0) {
            int v = pq.poll().to;
            if (vis[v]) continue;
            vis[v] = true;
            if (v == t) break;
            for (int i = 0, deg = g[v].size(); i < deg; i++) {
                InternalWeightedCapEdge e = g[v].get(i);
                if (vis[e.to] || e.cap == 0) continue;
                long cost = e.cost - dual[e.to] + dual[v];
                if (dist[e.to] - dist[v] > cost) {
                    dist[e.to] = dist[v] + cost;
                    pv[e.to] = v;
                    pe[e.to] = i;
                    pq.add(new State(dist[e.to], e.to));
                }
            }
        }
        if (!vis[t]) {
            return false;
        }

        for (int v = 0; v < n; v++) {
            if (!vis[v]) continue;
            dual[v] -= dist[t] - dist[v];
        }
        return true;
    }

    private void rangeCheck(int i, int minInlusive, int maxExclusive) {
        if (i < 0 || i >= maxExclusive) {
            throw new IndexOutOfBoundsException(
                String.format("Index %d out of bounds for length %d", i, maxExclusive)
            );
        }
    }

    private void nonNegativeCheck(long cap, java.lang.String attribute) {
        if (cap < 0) {
            throw new IllegalArgumentException(
                String.format("%s %d is negative.", attribute, cap)
            );
        }
    }
}