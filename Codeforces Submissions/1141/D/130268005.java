import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;
/*
-> Give your 100%, that's it!
-> Rules To Solve Any Problem:
    1. Read the problem.
    2. Think About It.
    3. Solve it!
*/

public class Template {
    
	static int mod = 1000000007;

	public static void main(String[] args){
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int yo = 1;
        while (yo-- > 0) {
            int n = sc.nextInt();
            char[] a = sc.next().toCharArray();
            char[] b = sc.next().toCharArray();
            
            int[] aa = new int[27];
            int[] bb = new int[27];
            
            for(char c : a){
                if(c == '?'){
                    aa[26]++;
                    continue;
                }
                aa[c-'a']++;
            }
            for(char c : b){
                if(c == '?'){
                    bb[26]++;
                    continue;
                }
                bb[c-'a']++;
            }
            
            Map<Integer,Set<Integer>> map1 = new HashMap<>();
            Map<Integer,Set<Integer>> map2 = new HashMap<>();
            
            for(int i = 0; i < 27; i++){
                map1.computeIfAbsent(i, x -> new LinkedHashSet<>());
                map2.computeIfAbsent(i, x -> new LinkedHashSet<>());
            }
            
            for(int i = 0; i < n; i++){
                char c = a[i];
                if(c == '?'){
                    map1.get(26).add(i);
                    continue;
                }
                map1.get(c-'a').add(i);
            }
            
            
            for(int i = 0; i < b.length; i++){
                char c = b[i];
                if(c == '?'){
                    map2.get(26).add(i);
                    continue;
                }
                map2.get(c-'a').add(i);
            }
            
            List<String> list = new ArrayList<>();
            for(int i = 0; i < 26; i++){
                int min = Math.min(aa[i],bb[i]);
                if(min != 0){
                    aa[i] -= min;
                    bb[i] -= min;
                    Set<Integer> set1 = map1.get(i);
                    Set<Integer> set2 = map2.get(i);
                    while(!set1.isEmpty() && !set2.isEmpty()){
                        int i1 = set1.iterator().next();
                        int i2 = set2.iterator().next();
                        set1.remove(i1);
                        set2.remove(i2);
                        list.add((i1+1) + " " + (i2+1));
                    }
                }
            }
            
            if(aa[26] != 0){
                for(int i = 0; i < 27; i++){
                    int min = Math.min(aa[26],bb[i]);
                    if(min != 0){
                        aa[26] -= min;
                        bb[i] -= min;
                        Set<Integer> set1 = map1.get(26);
                        Set<Integer> set2 = map2.get(i);
                        while(!set1.isEmpty() && !set2.isEmpty()){
                            int i1 = set1.iterator().next();
                            int i2 = set2.iterator().next();
                            set1.remove(i1);
                            set2.remove(i2);
                            list.add((i1+1) + " " + (i2+1));
                        }
                    } 
                }
            }
            if(bb[26] != 0){
                for(int i = 0; i < 27; i++){
                    int min = Math.min(aa[i],bb[26]);
                    if(min != 0){
                        aa[i] -= min;
                        bb[26] -= min;
                        Set<Integer> set1 = map1.get(i);
                        Set<Integer> set2 = map2.get(26);
                        while(!set1.isEmpty() && !set2.isEmpty()){
                            int i1 = set1.iterator().next();
                            int i2 = set2.iterator().next();
                            set1.remove(i1);
                            set2.remove(i2);
                            list.add((i1+1) + " " + (i2+1));
                        }
                    } 
                }
            }
            
            out.println(list.size());
            for(String s : list){
                out.println(s);
            }
            
        }
        out.close();
	}
    
   
    
    
    /*
    Source: hu_tao
         Random stuff to try when stuck:
            -if it's 2C then it's dp
            -for combo/probability problems, expand the given form we're interested in
            -make everything the same then build an answer (constructive, make everything 0 then do something)
            -something appears in parts of 2 --> model as graph
            -assume a greedy then try to show why it works
            -find way to simplify into one variable if multiple exist
            -treat it like fmc (note any passing thoughts/algo that could be used so you can revisit them)
            -find lower and upper bounds on answer
            -figure out what ur trying to find and isolate it
            -see what observations you have and come up with more continuations
            -work backwards (in constructive, go from the goal to the start)
            -turn into prefix/suffix sum argument (often works if problem revolves around adjacent array elements)
            -instead of solving for answer, try solving for complement (ex, find n-(min) instead of max)
            -draw something
            -simulate a process
            -dont implement something unless if ur fairly confident its correct
            -after 3 bad submissions move on to next problem if applicable
            -do something instead of nothing and stay organized
            -write stuff down
         Random stuff to check when wa:
            -if code is way too long/cancer then reassess
            -switched N/M
            -int overflow
            -switched variables
            -wrong MOD
            -hardcoded edge case incorrectly
         Random stuff to check when tle:
            -continue instead of break
            -condition in for/while loop bad
         Random stuff to check when rte:
            -switched N/M
            -long to int/int overflow
            -division by 0
            -edge case for empty list/data structure/N=1
      */

	public static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void sort(int[] arr) {
		ArrayList<Integer> ls = new ArrayList<Integer>();
		for (int x : arr)
			ls.add(x);
		Collections.sort(ls);
		for (int i = 0; i < arr.length; i++)
			arr[i] = ls.get(i);
	}

	public static long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	static boolean[] sieve(int N) {
		boolean[] sieve = new boolean[N + 1];
		for (int i = 2; i <= N; i++)
			sieve[i] = true;

		for (int i = 2; i <= N; i++) {
			if (sieve[i]) {
				for (int j = 2 * i; j <= N; j += i) {
					sieve[j] = false;
				}
			}
		}
		return sieve;
	}

	public static long power(long x, long y, long p) {
		long res = 1L;
		x = x % p;
		while (y > 0) {
			if ((y & 1) == 1)
				res = (res * x) % p;
			y >>= 1;
			x = (x * x) % p;
		}
		return res;
	}

	public static void print(int[] arr, PrintWriter out) {
		//for debugging only
		for (int x : arr)
			out.print(x + " ");
		out.println();
	}

	static class FastScanner {
		private int BS = 1 << 16;
		private char NC = (char) 0;
		private byte[] buf = new byte[BS];
		private int bId = 0, size = 0;
		private char c = NC;
		private double cnt = 1;
		private BufferedInputStream in;

		public FastScanner() {
			in = new BufferedInputStream(System.in, BS);
		}

		public FastScanner(String s) {
			try {
				in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
			} catch (Exception e) {
				in = new BufferedInputStream(System.in, BS);
			}
		}

		private char getChar() {
			while (bId == size) {
				try {
					size = in.read(buf);
				} catch (Exception e) {
					return NC;
				}
				if (size == -1)
					return NC;
				bId = 0;
			}
			return (char) buf[bId++];
		}

		public int nextInt() {
			return (int) nextLong();
		}

		public int[] readInts(int N) {
			int[] res = new int[N];
			for (int i = 0; i < N; i++) {
				res[i] = (int) nextLong();
			}
			return res;
		}

		public long[] readLongs(int N) {
			long[] res = new long[N];
			for (int i = 0; i < N; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public long nextLong() {
			cnt = 1;
			boolean neg = false;
			if (c == NC)
				c = getChar();
			for (; (c < '0' || c > '9'); c = getChar()) {
				if (c == '-')
					neg = true;
			}
			long res = 0;
			for (; c >= '0' && c <= '9'; c = getChar()) {
				res = (res << 3) + (res << 1) + c - '0';
				cnt *= 10;
			}
			return neg ? -res : res;
		}

		public double nextDouble() {
			double cur = nextLong();
			return c != '.' ? cur : cur + nextLong() / cnt;
		}

		public double[] readDoubles(int N) {
			double[] res = new double[N];
			for (int i = 0; i < N; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

		public String next() {
			StringBuilder res = new StringBuilder();
			while (c <= 32)
				c = getChar();
			while (c > 32) {
				res.append(c);
				c = getChar();
			}
			return res.toString();
		}

		public String nextLine() {
			StringBuilder res = new StringBuilder();
			while (c <= 32)
				c = getChar();
			while (c != '\n') {
				res.append(c);
				c = getChar();
			}
			return res.toString();
		}

		public boolean hasNext() {
			if (c > 32)
				return true;
			while (true) {
				c = getChar();
				if (c == NC)
					return false;
				else if (c > 32)
					return true;
			}
		}
	}

	//	For Input.txt and Output.txt	
	//	FileInputStream in = new FileInputStream("input.txt");
	//	FileOutputStream out = new FileOutputStream("output.txt");
	//	PrintWriter pw = new PrintWriter(out);
	//	Scanner sc = new Scanner(in);
}