import java.util.*;
import java.io.*;

public class OTCD {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        //PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        ArrayList<Integer> [] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int x = sc.nextInt(); int y = sc.nextInt();
            adj[x].add(y); adj[y].add(x);
        }
        boolean [] bad = new boolean[n + 1];
        while (true) {
            ArrayList<Integer> a = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                if (!bad[i] && adj[i].size() == 1) a.add(i);
                if (a.size() == 2) break;
            }
            if (a.size() == 0) {
                for (int i = 1; i <= n; i++) {
                    if (adj[i].size() == 0) {
                        System.out.println("! " + i); return;
                    }
                }
            }
            System.out.println("? "  + a.get(0) + " " + a.get(1));
            System.out.flush();
            int lca = sc.nextInt();
            if (lca == a.get(0) || lca == a.get(1)) {
                System.out.println("! " + lca);
                return;
            } else {
                adj[adj[a.get(0)].get(0)].remove(a.get(0));
                adj[adj[a.get(1)].get(0)].remove(a.get(1));
                bad[a.get(0)] = true; bad[a.get(1)] = true;
            }
        }
        //out.close();
    }


    //-----------MyScanner class for faster input----------
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