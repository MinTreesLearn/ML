import java.io.*;
import java.util.*;

public class D {
	
	public static boolean DEBUG = true;
	
    public static void main(String[] args) throws IOException {
    	FastScanner scan;
    	PrintWriter out;
    	if (DEBUG) {
    		scan = new FastScanner();
        	out = new PrintWriter(System.out);
    	}
    	else {
        	scan = new FastScanner("test.in");
        	out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
    	}
        
        int N = scan.nextInt();
        int M = scan.nextInt();

        ArrayList<Integer>[] from = (ArrayList<Integer>[])new ArrayList[N];
        ArrayList<Integer>[] to = (ArrayList<Integer>[])new ArrayList[N];
        for(int i=0; i<N; i++) {
            from[i] = new ArrayList<Integer>();
            to[i] = new ArrayList<Integer>();
        }

        for(int i=0; i<M; i++) {
            int a = scan.nextInt()-1;
            int b = scan.nextInt()-1;

            from[b].add(a);
            to[a].add(b);
        }

        int P = scan.nextInt();
        int[] path = new int[P];
        for(int i=0; i<P; i++) {
            path[i] = scan.nextInt()-1;
        }
        
        int[] shortestPaths = new int[N];
        Arrays.fill(shortestPaths,Integer.MAX_VALUE);

        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a,b) -> shortestPaths[a] - shortestPaths[b]);
        pq.add(path[P-1]);

        shortestPaths[path[P-1]] = 0;

        while(!pq.isEmpty()) {
            int n = pq.poll();

            for(int i : from[n]) {
                if(shortestPaths[n] + 1 < shortestPaths[i]) {
                    shortestPaths[i] = shortestPaths[n] + 1;
                    pq.add(i);
                }
            }
        }

        int min = 0;
        int maxAdd = 0;

        for(int i=0; i<P-1; i++) {

            int shortest = Integer.MAX_VALUE;
            boolean twice = false;

            for(int j : to[path[i]]) {
                if(shortestPaths[j] + 1 < shortest) {
                    shortest = shortestPaths[j] + 1;
                    twice = false;
                } else if (shortestPaths[j] + 1 == shortest) twice = true;
            }

            if(twice && shortestPaths[path[i+1]] + 1 == shortest) maxAdd++;
            else if(shortestPaths[path[i+1]] + 1 > shortest) min++;
        }
        
        System.out.println(min + " " + (min+maxAdd));

        out.close();
    }

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}