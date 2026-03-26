

/*
 
    /$$$$$  /$$$$$$  /$$    /$$  /$$$$$$                                                                  
   |__  $$ /$$__  $$ |$$    |$$ /$$__  $$                                                                 
          | $$| $$  \ $$|    $$|$$| $$  \ $$                                                                 
          | $$| $$$$$$$$|  $$ / $$/| $$$$$$$$                                                                 
/ $$  | $$| $$__  $$ \  $$ $$/ | $$__  $$                                                                 
| $$  | $$| $$  | $$  \  $$$/  | $$  | $$                                                                 
|  $$$$$$/| $$  | $$   \  $/   | $$  | $$                                                                 
 \______/ |__/  |__/    \_/    |__/  |__/    
 
/$$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$  /$$      /$$ /$$      /$$ /$$$$$$$$ /$$$$$$$ 
| $$__  $$| $$__  $$ /$$__  $$ /$$__  $$| $$__  $$ /$$__  $$| $$$    /$$$| $$$    /$$$| $$_____/| $$__  $$
| $$  \ $$| $$  \ $$| $$  \ $$| $$  \__/| $$  \ $$| $$  \ $$| $$$$  /$$$$| $$$$  /$$$$| $$      | $$  \ $$
| $$$$$$$/| $$$$$$$/| $$  | $$| $$ /$$$$| $$$$$$$/| $$$$$$$$| $$ $$/$$ $$| $$ $$/$$ $$| $$$$$   | $$$$$$$/
| $$____/ | $$__  $$| $$  | $$| $$|_  $$| $$__  $$| $$__  $$| $$  $$$| $$| $$  $$$| $$| $$__/   | $$__  $$
| $$      | $$  \ $$| $$  | $$| $$  \ $$| $$  \ $$| $$  | $$| $$\  $ | $$| $$\  $ | $$| $$      | $$  \ $$
| $$      | $$  | $$|  $$$$$$/|  $$$$$$/| $$  | $$| $$  | $$| $$ \/  | $$| $$ \/  | $$| $$$$$$$$| $$  | $$
|__/      |__/  |__/ \______/  \______/ |__/  |__/|__/  |__/|__/     |__/|__/     |__/|________/|__/  |__/
                                                                                                                                                                                                                
                                                                                                                                                                                                                
 
*/

import java.util.*;
import java.lang.*;
import java.io.*;

public class SleepingSchedule {
    public static void main(String[] args) throws java.lang.Exception {
        // your code goes here
        try {
            // Scanner sc=new Scanner(System.in);
            FastReader sc = new FastReader();
            int t = 1;// sc.nextInt();
            while (t-- > 0) {
                int n=sc.nextInt();
                int h=sc.nextInt();
                int l=sc.nextInt();
                int r=sc.nextInt();
                int[] arr=new int[n];
                for(int i=0;i<n;i++){
                    arr[i]=sc.nextInt();
                }
                int[][] dp=new int[h+1][n];
                for(int i=0;i<=h;i++)Arrays.fill(dp[i],-1);
                int ans=recSol(0,0,h,l,r,arr,dp);
                System.out.println(ans);
                /*
                 * int[] arr=new int[n];
                 * for(int i=0;i<n;i++){
                 * arr[i]=sc.nextInt();
                 * }
                 */

                /*
                 * long[] arr=new long[n];
                 * for(int i=0;i<n;i++){
                 * arr[i]=sc.nextLong();
                 * }
                 */
            }
        } catch (Exception e) {
            return;
        }

    }
    public static int recSol(int ch,int idx,int h,int l,int r,int[] arr,int[][] dp){
        if(idx>=arr.length)return 0;
        if(dp[ch][idx]!=-1)return dp[ch][idx];
        int currTimeLess=(ch+arr[idx]-1)%h;
        int withOut=recSol(currTimeLess,idx+1,h,l,r,arr,dp);
        if(currTimeLess>=l && currTimeLess<=r)withOut++;
        int currTimeMore=(ch+arr[idx])%h;
        int with=recSol(currTimeMore, idx+1, h, l, r, arr, dp);
        if(currTimeMore>=l && currTimeMore<=r)with++;
        return dp[ch][idx]=Math.max(with,withOut);

    }

    public static class pair {
        int ff;
        int ss;

        pair(int ff, int ss) {
            this.ff = ff;
            this.ss = ss;
        }
    }

    static int BS(int[] arr, int l, int r, int element) {
        int low = l;
        int high = r;
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < element) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (arr[low] == element) {
            return low;
        } else if (arr[high] == element) {
            return high;
        }
        return -1;
    }

    static int lower_bound(int[] arr, int l, int r, int element) {
        int low = l;
        int high = r;
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < element) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (arr[low] >= element) {
            return low;
        } else if (arr[high] >= element) {
            return high;
        }
        return -1;
    }

    static int upper_bound(int[] arr, int l, int r, int element) {
        int low = l;
        int high = r;
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= element) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (arr[low] > element) {
            return low;
        } else if (arr[high] > element) {
            return high;
        }
        return -1;
    }

    public static long gcd_long(long a, long b) {
        // a/b,a-> dividant b-> divisor
        if (b == 0)
            return a;
        return gcd_long(b, a % b);
    }

    public static int gcd_int(int a, int b) {
        // a/b,a-> dividant b-> divisor
        if (b == 0)
            return a;
        return gcd_int(b, a % b);
    }

    public static int lcm(int a, int b) {
        int gcd = gcd_int(a, b);
        return (a * b) / gcd;
    }

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

        String nextLine() {
            String s = "";
            try {
                s = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return s;
        }

        Long nextLong() {
            return Long.parseLong(next());
        }
    }

    // FACTORISATION OF A NUMBER ---> OPTIMISED CODE
    // TC -->O(sqrt(N));
    public static void factorize(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                System.out.println("DIVISOR is " + i + " " + "COUNT is " + cnt);
            }
        }
        if (n != 1) {
            // n is prime number
            System.out.println("DIVISOR is " + n + " " + "COUNT is " + 1);
        }
    }

    // DISJOINT SET UNINION OPTIMALLY IMPLEMENTED USING PATH COMPRESSION AND RANK
    // ARRAY------>>>>>>>>>>>>>>>>>>>>>
    // parent[i].ff==parent of i and parent[i].ss gives the rant of the set in which
    // i belongs to
    public static int find_set(int a, pair[] parent) {
        if (parent[a].ff == a)
            return a;
        return parent[a].ff = find_set(parent[a].ff, parent);
    }

    public static void union_set(int a, int b, pair[] parent) {
        int a_root = find_set(a, parent);
        int b_root = find_set(b, parent);
        if (a_root == b_root)
            return;
        if (parent[a_root].ss < parent[b_root].ss) {
            parent[a_root].ff = b_root;
        } else if (parent[a_root].ss > parent[b_root].ss) {
            parent[b_root].ff = a_root;
        } else {
            parent[b_root].ff = a_root;
            parent[a_root].ss++;
        }
    }

    public static class UnionFind {
        int[] p, rank, setSize;
        int numSets;

        public UnionFind(int N) {
            p = new int[numSets = N];
            rank = new int[N];
            setSize = new int[N];
            for (int i = 0; i < N; i++) {
                p[i] = i;
                setSize[i] = 1;
            }
        }

        public int findSet(int i) {
            return p[i] == i ? i : (p[i] = findSet(p[i]));
        }

        public boolean isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        public void unionSet(int i, int j) {
            if (isSameSet(i, j))
                return;
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                setSize[x] += setSize[y];
            } else {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }

        public int numDisjointSets() {
            return numSets;
        }

        public int sizeOfSet(int i) {
            return setSize[findSet(i)];
        }
    }
    ////SEGMENT TREE NORMAL ONE FOR MAX ELEMENT OF A RANGE
    public static void buildTree(int v,int l,int r,int[] arr,int[] st){
        if(r<l)return;
        if(l==r){
            st[v]=arr[l];
            return;
        }
        int mid=(r+l)/2;
        buildTree(2*v+1, l, mid, arr, st);
        buildTree(2*v+2, mid+1, r, arr, st);
        st[v]=Math.max(st[2*v+1],st[2*v+2]);
        return;
    }
    public static int query(int v,int cl,int cr,int l,int r,int[] st){
        if(cr<l || cl>r){
            return Integer.MIN_VALUE;
        }
        if(cl>=l && cr<=r){
            return st[v];
        }
        int cmid=(cl+cr)/2;
        return Math.max(query(2*v+1, cl, cmid, l, r, st),query(2*v+2, cmid+1, cr, l, r, st));
    }

}

/*
 * public static boolean lie(int n,int m,int k){ if(n==1 && m==1 && k==0){
 * return true; } if(n<1 || m<1 || k<0){ return false; } boolean
 * tc=lie(n-1,m,k-m); boolean lc=lie(n,m-1,k-n); if(tc || lc){ return true; }
 * return false; }
 */
