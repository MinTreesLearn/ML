        import java.util.*;
        import java.io.*;
        import java.io.DataInputStream;
        import java.io.FileInputStream;
        import java.io.IOException;
        import java.io.InputStreamReader;
        import java.util.Scanner;
        import java.util.StringTokenizer;
        import java.math.BigInteger;

        public class Main{
            static class Node {
                long sum, pre;
                Node(long a, long b) {
                    this.sum = a;
                    this.pre = b;
                }
            }
            static  class SegmentTree {
                int l , r; // range responsible for
                SegmentTree left , right;
                long val;
                SegmentTree(int l,int r,long a[]) {
                    this.l = l;
                    this.r = r;
                    // list= new ArrayList<>();
                    if(l == r) {
                        val = a[l];
                        return ;
                    }
                    int mid = l + (r-l)/2;
                    this.left = new SegmentTree(l ,mid , a);
                    this.right = new SegmentTree(mid + 1 , r,a);
                    this.val = Math.max(this.left.val , this.right.val);
                }
                public  long query(int left ,int right) {
                    if(this.l > right || this.r < left) {
                        return 0l;
                    }
                    if(this.l >= left && this.r <= right) {
                        return this.val;
                    }
                    return this.left.query(left , right ) + this.right.query(left , right );
                }
                // public void pointUpdate(int index , long val) {
                //     if(this.l > index || this.r < index) return;
                //     if(this.l == this.r && this.l == index) {
                //         this.val = val;
                //         return ;
                //     }
                //     this.left.pointUpdate(index ,val);
                //     this.right.pointUpdate(index , val);
                //     this.val = join(this.left.val , this.right.val);
                // }
                // public void rangeUpdate(int left , int right,long val) {
                //     if(this.l > right || this.r < left) return ;
                //     if(this.l >= left && this.r <= right) {
                //         this.val += val;
                //     }
                //     if(this.l == this.r) return;
                //     this.left.rangeUpdate(left , right  , val);
                //     this.right.rangeUpdate(left , right  , val);
                // }
                // public long valueAtK(int k) {
                //     if(this.l > k || this.r < k) return 0;
                //     if(this.l == this.r && this.l == k) {
                //         return this.val;
                //     }
                //     return join(this.left.valueAtK(k) , this.right.valueAtK(k));
                // }
                public int join(int a ,int b) {
                    return a + b;
                }
            }
            
            static class Hash {
                long hash[] ,mod = (long)1e9 + 7 , powT[] , prime , inverse[];
                Hash(char []s)  {
                    prime = 131;
                    int n = s.length;
                    powT = new long[n];
                    hash = new long[n];
                    inverse = new long[n];
                    powT[0] = 1;
                    inverse[n-1] = pow(pow(prime  , n-1 ,mod), mod-2 , mod);
                    for(int i = 1;i < n; i++ ) {
                        powT[i] = (powT[i-1]*prime)%mod;
                    }
                    for(int i = n-2; i>= 0;i-=1)  {
                        inverse[i] = (inverse[i+1]*prime)%mod;
                    }
                    hash[0] = (s[0] - 'a' + 1);
                    for(int i = 1; i < n;i++ ) {
                        hash[i] = hash[i-1] + ((s[i]-'a' + 1)*powT[i])%mod;
                        hash[i] %= mod;
                    }
                }
                public long hashValue(int l , int r) {
                    if(l == 0) return hash[r]%mod;
                    long ans = hash[r]  - hash[l-1] +mod;
                    ans %= mod;
                    // System.out.println(inverse[l] + " " + pow(powT[l], mod- 2 , mod));
                    ans *= inverse[l];
                    ans %= mod;
                    return ans;
                }
            }
            static class ConvexHull {
                Stack<Integer>stack;
                Stack<Integer>stack1;
                int n;
                Point arr[];
                ConvexHull(Point arr[]) { 
                    n = arr.length;
                    this.arr = arr;
                    Arrays.sort(arr , (a , b)-> {
                        if(a.x == b.x) return (int)(b.y-a.y);
                        return (int)(a.x-b.x);
                    });
                    Point min = arr[0];
                    stack =  new Stack<>();
                    stack1 =  new Stack<>();
                    stack.push(0);
                    stack1.push(0);
                    Point ob  = new Point(2,2);
                    for(int i =1;i < n;i++) {
                        if(stack.size() < 2) stack.push(i);
                        else {
                            while(stack.size() >= 2) {
                                int a = stack.pop() , b = stack.pop() ,c = i;
                                int dir = ob.cross(arr[b] , arr[a] , arr[c]);
                                if(dir < 0) {
                                    stack.push(b);
                                    stack.push(a);
                                    stack.push(c);
                                    break;
                                }
                                stack.push(b);
                            }
                            if(stack.size() < 2) {
                                stack.push(i);
                            }
                        }
                    }
                    for(int i =1;i < n;i++) {
                        if(stack1.size() < 2) stack1.push(i);
                        else {
                            while(stack1.size() >= 2) {
                                int a = stack1.pop() , b = stack1.pop() ,c = i;
                                int dir = ob.cross(arr[b] , arr[a] , arr[c]);
                                if(dir > 0) {
                                    stack1.push(b);
                                    stack1.push(a);
                                    stack1.push(c);
                                    break;
                                }
                                stack1.push(b);
                            }
                            if(stack1.size() < 2) {
                                stack1.push(i);
                            }
                        }
                    }
                }
                public List<Point> getPoints() {
                    boolean vis[] = new boolean[n];
                    List<Point> list = new ArrayList<>();
                    // for(int x : stack) {
                    //     list.add(arr[x]);
                    //     vis[x] = true;
                    // }
                    for(int x : stack1) {
                        // if(vis[x]) continue;
                        list.add(arr[x]);
                    } 
                    return list;
                }
            }
            public static class Suffix implements Comparable<Suffix> {
                int index;
                int rank;
                int next;
                public Suffix(int ind, int r, int nr) {
                    index = ind;
                    rank = r;
                    next = nr;
                }
                public int compareTo(Suffix s) {
                    if (rank != s.rank) return Integer.compare(rank, s.rank);
                    return Integer.compare(next, s.next);
                }
            }
            static class Point {
                long x , y;
                Point(long x , long y)  {
                    this.x = x;
                    this.y = y;
                }
                public String toString() {
                    return this.x +  " " + this.y;
                }
                public Point sub(Point a,Point b) {
                    return new Point(a.x - b.x , a.y-b.y);
                }
                public int cross(Point a ,Point b , Point c) {
                    Point g = sub(b,a) , l = sub(c, b);
                    long ans = g.y*l.x - g.x*l.y;
                    if(ans == 0) return 0;
                    if(ans < 0) return -1;
                    return 1;
                }
            }

            static class Kattio extends PrintWriter {
                private BufferedReader r;
                private StringTokenizer st;
            
                // standard input
                public Kattio() { this(System.in, System.out); }
                public Kattio(InputStream i, OutputStream o) {
                    super(o);
                    r = new BufferedReader(new InputStreamReader(i));
                }
                // USACO-style file input
                public Kattio(String problemName) throws IOException {
                    super(new FileWriter(problemName + ".out"));
                    r = new BufferedReader(new FileReader(problemName + ".in"));
                }
            
                // returns null if no more input
                public String next() {
                    try {
                        while (st == null || !st.hasMoreTokens())
                            st = new StringTokenizer(r.readLine());
                        return st.nextToken();
                    } catch (Exception e) { }
                    return null;
                }
            
                public int nextInt() { return Integer.parseInt(next()); }
                public double nextDouble() { return Double.parseDouble(next()); }
                public long nextLong() { return Long.parseLong(next()); }
            }   
            
            static Kattio sc = new Kattio();
            static long  mod  = 998244353l;
            // static Kattio out = new Kattio();
         
            //Heapify function to maintain heap property.
            public static void swap(int i,int j,int arr[]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            public static long max(long ...a) {
                return maxArray(a);
            }
            public static void swap(int i,int j,long arr[]) {
                long temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            public static void swap(int i,int j,char arr[]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            static String endl = "\n" , gap = " ";
            static int size[];
            static int parent[];
            static HashMap<Integer , Long> value;
            // static HashMap<String , Boolean > dp;
            
            // static HashMap<Integer , List<int[]>> graph;

            static boolean vis[];
            static int answer;
            static HashSet<String> guess;
            static long primePow[];
            // static long dp[];
            static int N;
            static int dis[];
            static int height[];
            static long p[];
            // static long fac[];
            // static long inv[];
            static HashMap<Integer ,List<Integer>> graph;
            public static long rd() {
                return (long)((Math.random()*10) + 1);
            }
            
            public static void main(String[] args)throws IOException {
                long t  = 1;
                // List<Integer> list  = new ArrayList<>();
                // int MAX = (int)4e4;
                // for(int i =1;i<=MAX;i++) {
                //     if(isPalindrome(i + "")) list.add(i);
                // }
                // // System.out.println(list);
                // long dp[] = new long[MAX +1];
                // dp[0] = 1;
                // long mod = (long)(1e9+7);
                // for(int x : list) {
                //     for(int i =1;i<=MAX;i++) {
                //         if(i >= x) {
                //             dp[i] += dp[i-x];
                //             dp[i] %= mod;
                //         }
                //     }
                // }
                // int MAK = (int)1e6 + 10;
                // boolean seive[] = new boolean[MAK];
                // Arrays.fill(seive , true);
                // seive[1] = false;
                // seive[0] = false;
                // for (int i = 1; i < MAK; i++) {
                //     if(seive[i]) {
                //         for (int j = i+i; j < MAK; j+=i) {
                //             seive[j] = false;
                //         }    
                //     }
                // }
                // TreeSet<Long>primeSet = new TreeSet<>();
                // for(long i = 2;i <= (long)1e6;i++) {
                //     if(seive[(int)i])primeSet.add(i);
                // }
                // List<Integer>  list = new ArrayList<>();
                // for (int i = 1; i < seive.length; i++) {
                //     if(seive[i]) list.add(i);
                // }
                int test_case = 1;
                while(t-->0) {
                    // sc.print("Case #"+(test_case++)+": ");
                    solve();
                }
                sc.close();
            }
            static int endTime[];
            static int time;
            public static int dis(int a[] , int b[]) {
                return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
            }
            // static Long dp[][][];
            static long fac[], inv[];
            public static long ncr(int a , int b) {
                if(a == b) return 1l;
                return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
            }
            static Long dp[][];
            public static void solve() throws IOException {          
                char s[] = rac();
                long ans = 0;
                int cnt[] = new int[26];
                int n = s.length;
                for(char ch : s) cnt[ch-'a']++;
                for(int i =0;i < 26;i++) ans = Math.max(ans ,cnt[i]);
                HashMap<String  ,Long> map = new HashMap<>();
                for(int i = 0;i < n;i++) {
                    cnt[s[i]-'a']--;
                    for(char c = 'a';c <= 'z';c++) {
                        String g = s[i]+""+c;
                        map.put(g , map.getOrDefault(g , 0l) + cnt[c-'a']);
                    }
                }
                for(String k : map.keySet()) ans = Math.max(ans , map.get(k));
                System.out.println(ans);

            }
            public static void print(PriorityQueue<long[]> que ) {
                for(long a[] : que)  {
                    System.out.print(a[1] + " ");
                }
                System.out.println();
            }
            public static String slope(Point a , Point b) {
                if((a.x-b.x) == 0) return "inf";
                long n = a.y- b.y;
                if(n  == 0) return "0";
                long m = a.x-b.x;
                boolean neg = (n*m < 0?true:false);
                n = Math.abs(n);
                m = Math.abs(m);
                long g = gcd(Math.abs(n),Math.abs(m));
                n /= g;
                m /= g;
                String ans =  n+"/"+m;
                if(neg) ans = "-" + ans;
                return ans;
            }
            public static int lis(int A[], int size) {
                int[] tailTable = new int[size];    
                int len;
                tailTable[0] = A[0];
                len = 1;
                for (int i = 1; i < size; i++) {
                    if (A[i] < tailTable[0]) tailTable[0] = A[i];
                    else if (A[i] > tailTable[len - 1]) tailTable[len++] = A[i];
                    else tailTable[CeilIndex(tailTable, -1, len - 1, A[i])] = A[i];
                }
                return len;
            }
            public static int CeilIndex(int A[], int l, int r, int key) {
                while (r - l > 1) {
                    int m = l + (r - l) / 2;
                    if (A[m] >= key) r = m;
                    else l = m;
                }
                return r;
            }
            public static int lcs(char a[] , char b[]) {
                int n = a.length , m = b.length;
                int dp[][] = new int[n + 1][m + 1];
                for(int i =1;i <= n;i++) {
                    for(int j =1;j <= m;j++) {
                        if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                        else dp[i][j] = Math.max(dp[i-1][j] , dp[i][j-1]);
                    }
                }
                return dp[n][m];
            }
            public static int find(int node) {
                if(node == parent[node]) return node;
                return parent[node]  = find(parent[node]);
            }
            public static void merge(int a ,int b ) {
                a = find(a);
                b = find(b);
                if(a == b) return;
                if(size[a] >= size[b]) {
                    parent[b] = a;
                    size[a] += size[b];
                    // primePow[a] += primePow[b];
                    // primePow[b] = 0;
                }
                else {
                    parent[a] = b;
                    size[b] += size[a];   
                    // primePow[b] += primePow[a];
                    // primePow[a] = 0;
                }
            }
            public static  void processPowerOfP(long arr[]) {
                int n = arr.length;
                arr[0] = 1;
                long mod  = (long)1e9 + 7;
                for(int i =1;i<n;i++) {
                    arr[i] = arr[i-1]*51;
                    arr[i] %= mod;
                }
            }
            public static long hashValue(char s[]) {
                int n = s.length;
                long powerOfP[] = new long[n];
                processPowerOfP(powerOfP);
                long ans =0;
                long mod  = (long)1e9 + 7;
                for(int i =0;i<n;i++) {
                    ans += (s[i]-'a'+1)*powerOfP[i];
                    ans %= mod;
                }
                return ans;
            }
            public static void dfs(int r,int c,char arr[][]) {
                int n  = arr.length , m = arr[0].length;
                arr[r][c] = '#';
                for(int i =0;i<4;i++) {
                    int nr = r + colx[i] , nc = c + coly[i];
                    if(nr < 0 || nc < 0 || nc >= m || nr>=n) continue;
                    if(arr[nr][nc] == '#') continue;
                    dfs(nr,nc,arr);
                }
            }
            
            public static double getSlope(int a , int b,int x,int y) {
                if(a-x == 0) return Double.MAX_VALUE;
                if(b-y == 0) return 0.0;
                return ((double)b-(double)y)/((double)a-(double)x);
            }
            
            public static boolean collinearr(long a[] , long b[] , long c[]) {
                return (b[1]-a[1])*(b[0]-c[0]) == (b[0]-a[0])*(b[1]-c[1]);
            }
            public static boolean isSquare(long sum) {
                long root = (int)Math.sqrt(sum);
                return root*root == sum;
            }
            public static int[] suffixArray(String s) {
                int n = s.length();
                Suffix[] su = new Suffix[n];
                for (int i = 0; i < n; i++) {
                    su[i] = new Suffix(i, s.charAt(i) - '$', 0);
                }
                for (int i = 0; i < n; i++)
                    su[i].next = (i + 1 < n ? su[i + 1].rank : -1);
                Arrays.sort(su);
                int[] ind = new int[n];
                for (int length = 4; length < 2 * n; length <<= 1) {
                    int rank = 0, prev = su[0].rank;
                    su[0].rank = rank;
                    ind[su[0].index] = 0;
                    for (int i = 1; i < n; i++) {
                        if (su[i].rank == prev && su[i].next == su[i - 1].next) {
                            prev = su[i].rank;
                            su[i].rank = rank;
                        }
                        else {
                            prev = su[i].rank;
                            su[i].rank = ++rank;
                        }
                        ind[su[i].index] = i;
                    }
                    for (int i = 0; i < n; i++) {
                        int nextP = su[i].index + length / 2;
                        su[i].next = nextP < n ?
                           su[ind[nextP]].rank : -1;
                    }
                    Arrays.sort(su);
                }
                int[] suf = new int[n];
                for (int i = 0; i < n; i++)
                    suf[i] = su[i].index;
                return suf;
            }  
            public static boolean isPalindrome(String s) {
                int i =0 , j = s.length() -1;
                while(i <= j && s.charAt(i) == s.charAt(j)) {
                    i++;
                    j--;
                }
                return i>j;
            }
            // digit dp hint;
            public static long callfun(String num , int N, int last ,int secondLast ,int bound ,long dp[][][][]) {
                if(N == 1) {
                    if(last == -1 || secondLast == -1) return 0;
                    long answer = 0;
                    int max = (bound==1)?(num.charAt(num.length()-N)-'0') : 9;
                    for(int i = 0;i<=max;i++) {
                        if(last > secondLast && last > i) {
                            answer++;
                        }
                        if(last < secondLast && last < i) {
                            answer++;
                        }
                    }
                    return answer;
                }
                if(secondLast == -1 || last == -1 ){
                    long answer = 0l;
                    int max = (bound==1)?(num.charAt(num.length()-N)-'0') : 9;
                    for(int i =0;i<=max;i++)  {
                        int nl , nsl , newbound = bound==0?0:i==max?1:0;
                        if(last == - 1&& secondLast == -1 && i == 0) {
                            nl = -1 ; nsl = -1;
                        }
                        else {
                            nl = i;nsl = last;
                        }

                        long temp = callfun(num , N-1 , nl , nsl ,newbound, dp);
                        answer += temp;
                        if(last != -1 && secondLast != -1 &&((last > secondLast && last > i)||(last < secondLast && last < i))) answer++;
                    }
                    return answer;    
                }
                if(dp[N][last][secondLast][bound] != -1)  return dp[N][last][secondLast][bound];
                long answer = 0l;
                int max = (bound==1)?(num.charAt(num.length()-N)-'0') : 9;
                for(int i =0;i<=max;i++)  {
                    int nl , nsl , newbound = bound==0?0:i==max?1:0;
                    if(last == - 1&& secondLast == -1 && i == 0) {
                        nl = -1 ; nsl = -1;
                    }
                    else {
                        nl = i;nsl = last;
                    }
                    long temp = callfun(num , N-1 , nl , nsl ,newbound,dp);
                    answer += temp;
                    if(last != -1 && secondLast != -1 &&((last > secondLast && last > i)||(last < secondLast && last < i))) answer++;
                }
                return dp[N][last][secondLast][bound]  = answer;
            }
            public static Long callfun(int index ,int pair,int arr[],Long dp[][]) {
                long mod = 998244353l;
                if(index >= arr.length) return 1l;
                if(dp[index][pair] != null) return dp[index][pair]; 
                Long sum = 0l , ans = 0l;
                if(arr[index]%2 == pair) {
                    return dp[index][pair] = callfun(index + 1,pair^1 , arr,dp)%mod + callfun(index + 1 ,pair , arr , dp)%mod;
                }
                else {
                    return dp[index][pair] = callfun(index + 1,pair ,  arr,dp)%mod;
                }
                // for(int i =index;i<arr.length;i++) {
                //     sum += arr[i];
                //     if(sum%2 == pair) {
                //         ans = ans  +  callfun(i + 1,pair^1,arr , dp)%mod;
                //         ans%=mod;
                //     }
                // }
                // return dp[index][pair]  = ans;
            }
            public static boolean callfun(int index , int n,int neg , int pos , String s) {
                if(neg < 0 || pos < 0) return false;
                if(index >= n) return true;
                
                if(s.charAt(0) == 'P') {
                    if(neg <= 0) return false;
                    return callfun(index + 1,n , neg-1 , pos , s.charAt(1)  + "N");
                }
                else  {
                    if(pos <= 0) return false;
                    return callfun(index + 1 , n , neg , pos-1 , s.charAt(1) + "P");
                }
            }
            
            public static void getPerm(int n , char arr[] , String s ,List<String>list) {
                if(n == 0) {
                    list.add(s);
                    return;
                }
                for(char ch : arr) {
                    getPerm(n-1 , arr , s+ ch,list);
                }
            }
            public static int getLen(int i  ,int j , char s[]) {
                while(i >= 0 && j < s.length && s[i] == s[j]) {
                    i--;
                    j++;
                }
                i++;
                j--;
                if(i>j) return 0;
                return j-i + 1;
            }
            public static int getMaxCount(String x) {
                char s[] = x.toCharArray();
                int max = 0;
                int n = s.length;
                for(int i =0;i<n;i++) {
                    max = Math.max(max,Math.max(getLen(i , i,s) , getLen(i ,i+1,s)));
                }
                return max;
            }
            public static double getDis(int arr[][] , int  x, int y) {
                double ans = 0.0;
                for(int a[] : arr) {
                    int x1 = a[0] , y1 = a[1];
                    ans += Math.sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
                }
                return ans;
            }
            public static boolean valid(String x ) {
                if(x.length() == 0) return true;
                if(x.length() == 1) return false;
                char s[] = x.toCharArray();
                if(x.length()  == 2) {
                    if(s[0] == s[1]) {
                        return false;
                    }
                    return true;
                }
                int r = 0 , b = 0;
                for(char ch : x.toCharArray()) {
                    if(ch == 'R') r++;
                    else b++;
                }
                return (r >0 && b >0);


            }

            public static void primeDivisor(HashMap<Long , Long >cnt , long num) {
                for(long i = 2;i*i<=num;i++) {
                    while(num%i == 0) {
                        cnt.put(i ,(cnt.getOrDefault(i,0l) + 1));
                        num /= i;
                    }
                }
                if(num > 2) {
                    cnt.put(num ,(cnt.getOrDefault(num,0l) + 1));
                }
            }
            
            
            public static boolean isSubsequene(char a[],  char b[] ) {
                int i =0 , j = 0;
                while(i < a.length && j  <b.length) {
                    if(a[i] == b[j]) {
                        j++;
                    }
                    i++;
                }
                return  j >= b.length;
            }
            public static long fib(int n ,long M) {
                if (n == 0) {
                    return 0;
                } else if (n == 1) {
                    return 1;
                } else {
                    long[][] mat = {{1, 1}, {1, 0}};
                    mat = pow(mat, n-1 , M);
                    return mat[0][0];
                }
            }
            public static long[][] pow(long[][] mat, int n ,long M) {
                if (n == 1) return mat;
                else if (n % 2 == 0) return pow(mul(mat, mat , M), n/2 , M);
                else return mul(pow(mul(mat, mat,M), n/2,M), mat , M);
            }
            static long[][] mul(long[][] p, long[][] q,long M) {
                long a = (p[0][0]*q[0][0] + p[0][1]*q[1][0])%M;
                long b = (p[0][0]*q[0][1] + p[0][1]*q[1][1])%M;
                long c = (p[1][0]*q[0][0] + p[1][1]*q[1][0])%M;
                long d = (p[1][0]*q[0][1] + p[1][1]*q[1][1])%M;
                return new long[][] {{a, b}, {c, d}};
            }
            public static long[] kdane(long arr[]) {
                int n = arr.length;
                long dp[] = new long[n];
                dp[0] = arr[0];
                long ans = dp[0];
                for(int i = 1;i<n;i++) {
                    dp[i] = Math.max(dp[i-1] + arr[i] , arr[i]);
                    ans = Math.max(ans , dp[i]);
                }
                return dp;
            }
            
           
            public static void update(int low , int high , int l , int r, int val , int treeIndex ,int tree[]) {

                if(low > r || high < l || high < low) return;
                if(l <= low && high <= r) {
                    System.out.println("At " +low + " and " + high + " ans ttreeIndex  " + treeIndex);
                    tree[treeIndex] += val;
                    return;
                }
                int mid = low + (high - low)/2;
                update(low , mid , l , r , val , treeIndex*2  + 1, tree);
                update(mid + 1 , high , l , r , val , treeIndex*2 + 2 , tree);
            }
            // static int colx[] = {1 ,1, -1,-1 , 2,2,-2,-2};
            // static int coly[] = {-2 ,2, 2,-2,1,-1,1,-1};
            static int colx[] = {1 ,-1, 0,0 , 1,1,-1,-1};
            static int coly[] = {0 ,0, 1,-1,1,-1,1,-1};
            public static void reverse(char arr[])  {
                int i =0 , j = arr.length-1;
                while(i < j) {
                    swap(i , j , arr);
                    i++;
                    j--;
                }
            }
            public static void reverse(long arr[])  {
                int i =0 , j = arr.length-1;
                while(i < j) {
                    swap(i , j , arr);
                    i++;
                    j--;
                }
            }
            public static void reverse(int arr[])  {
                int i =0 , j = arr.length-1;
                while(i < j) {
                    swap(i , j , arr);
                    i++;
                    j--;
                }
            }
            
            public static long inverse(long x  , long mod) {
                return pow(x , mod -2 , mod);
            }
            public static int maxArray(int arr[]) {
                int ans = arr[0] ,  n = arr.length;
                for(int i =1;i<n;i++) {
                    ans = Math.max(ans , arr[i]);
                }
                return ans;
            }
            public static long maxArray(long arr[]) {
                long ans = arr[0];
                int  n = arr.length;
                for(int i =1;i<n;i++) {
                    ans = Math.max(ans , arr[i]);
                }
                return ans;
            }
            public static int minArray(int arr[]) {
                int ans = arr[0] , n = arr.length;
                for(int i =0;i<n;i++ ) {
                    ans = Math.min(ans ,arr[i]);
                }
                return ans;
            }
            public static long minArray(long arr[]) {
                long ans = arr[0];
                int n = arr.length;
                for(int i =0;i<n;i++ ) {
                    ans = Math.min(ans ,arr[i]);
                }
                return ans;
            }
            public static int sumArray(int arr[]) {
                int ans = 0;
                for(int x : arr) {
                    ans  += x;
                }
                return ans;
            }
            public static long sumArray(long arr[]) {
                long ans = 0;
                for(long x : arr) {
                    ans  += x;
                }
                return ans;
            }
            public static long rl() {
                return sc.nextLong();
            }
            public static char[] rac() {
                return sc.next().toCharArray();
            }
            public static String rs() {
                return sc.next();
            }
            public static char rc() {
                return sc.next().charAt(0);
            }
            public static  int [] rai(int n) {
                int ans[] = new int[n];
                for(int i =0;i<n;i++) {
                    ans[i] = sc.nextInt();
                }
                return ans;
            }
            public static  long [] ral(int n) {
                long ans[] = new long[n];
                for(int i =0;i<n;i++) {
                    ans[i] = sc.nextLong();
                }
                return ans;
            }
            public static int ri() {
                return sc.nextInt();
            }

            public static int getValue(int num ) {
                int ans = 0;
                while(num > 0) {
                    ans++;
                    num = num&(num-1);
                }
                return ans;
            }
            public static boolean isValid(int x ,int y , int n,char arr[][],boolean visited[][][][])  {
                return x>=0 && x<n && y>=0 && y <n && !(arr[x][y] == '#');
            }
            // public static Pair join(Pair a , Pair b) {
            //     Pair res = new Pair(Math.min(a.min , b.min) , Math.max(a.max , b.max) , a.count + b.count);
            //     return res;
            // }
            
            // segment tree query over range
            // public static int query(int node,int l , int r,int a,int b ,Pair tree[] ) {
            //     if(tree[node].max < a || tree[node].min > b) return 0;
            //     if(l  > r) return 0;
            //     if(tree[node].min >= a && tree[node].max <= b) {
            //         return tree[node].count;   
            //     }
            //     int mid = l + (r-l)/2;
            //     int ans = query(node*2 ,l , mid ,a , b , tree) + query(node*2 +1,mid + 1, r , a , b, tree);
            //     return ans;
            // }
            // // segment tree update over range
            // public static void update(int node, int i , int j ,int l , int r,long value, long arr[] ) {
            //     if(l >= i && j >= r) {
            //         arr[node]   += value;
            //         return;
            //     }
            //     if(j < l|| r < i) return;
            //     int mid = l + (r-l)/2;
            //     update(node*2 ,i ,j ,l,mid,value, arr);
            //     update(node*2 +1,i ,j ,mid + 1,r, value  , arr);
            // }

            public static long pow(long a , long b  , long mod) {
                if(b == 1) return a;
                if(b == 0) return 1;
                long ans = pow(a , b/2 , mod)%mod;
                if(b%2 == 0) {
                    return (ans*ans)%mod;
                }
                else {
                    return ((ans*ans)%mod*a)%mod;
                }
            }
            
            public static long pow(long a , long b ) {
                if(b == 1) return a;
                if(b == 0) return 1;
                long ans = pow(a , b/2);
                if(b%2 == 0) {
                    return (ans*ans);
                }
                else {
                    return ((ans*ans)*a);
                }
            }
            
            
            public static boolean isVowel(char ch) {
                if(ch == 'a' || ch == 'e'||ch == 'i' || ch == 'o' || ch == 'u') return true;
                if((ch == 'A' || ch == 'E'||ch == 'I' || ch == 'O' || ch == 'U'))  return true;
                return false;
            }

            
            
            // public static int getFactor(int num) {
            //     if(num==1) return 1;
            //     int ans = 2;
            //     int k = num/2;
            //     for(int i = 2;i<=k;i++) {
            //         if(num%i==0) ans++;
            //     }
            //     return Math.abs(ans);
            // }

            public static int[] readarr()throws IOException {
                int n = sc.nextInt();
                int arr[] = new int[n];
                for(int i =0;i<n;i++) {
                    arr[i] =  sc.nextInt();
                }
                return arr;
            }
         
            public static boolean isPowerOfTwo (long x) {
                return x!=0 && ((x&(x-1)) == 0);
            }
            public static boolean isPrime(long num) {
                if(num==1) return false;
                if(num<=3) return true;
                if(num%2==0||num%3==0) return false;
                for(long i =5;i*i<=num;i+=6) {
                    if(num%i==0 || num%(i+2) == 0) return false;
                }
                return true;
            }
            public static boolean isPrime(int num) {
                // System.out.println("At pr " + num);
                if(num==1) return false;
                if(num<=3) return true;
                if(num%2==0||num%3==0) return false;
                for(int i =5;i*i<=num;i+=6) {
                    if(num%i==0 || num%(i+2) == 0) return false;
                }
                return true;
            }
            // public static boolean isPrime(long num) {
            //     if(num==1) return false;
            //     if(num<=3) return true;
            //     if(num%2==0||num%3==0) return false;
            //     for(int i =5;i*i<=num;i+=6) {
            //         if(num%i==0) return false;
            //     }
            //     return true;
            // }                                 
            public static void allMultiple()  {
                // int MAX = 0 , n = nums.length;
                // for(int x : nums) MAX = Math.max(MAX ,x);
                // int cnt[] = new int[MAX + 1];
                // int ans[] = new int[MAX + 1];
                // for (int i = 0; i < n; ++i) cnt[nums[i]]++;
                // for (int i = 1; i <= MAX; ++i) {
                //     for (int j = i; j <= MAX; j += i) ans[i] += cnt[j];
                // }
            }                                                                    
            public static long gcd(long a , long b) {
                if (b == 0) return a;
                return gcd(b, a % b);
            }
            
            public static int gcd(int a , int b) {
                if (b == 0) return a;
                return gcd(b, a % b);
            }
            public static int get_gcd(int a , int b) {
                if (b == 0) return a;
                return gcd(b, a % b);
            }
            public static long get_gcd(long a , long b) {
                if (b == 0) return a;
                return gcd(b, a % b);
            }
            // public static long fac(long num)  {
            //     long ans = 1;
            //     int mod = (int)1e9+7;
            //     for(long i = 2;i<=num;i++) {
            //         ans  =  (ans*i)%mod;
            //     }

            //     return ans;
            // }
        }