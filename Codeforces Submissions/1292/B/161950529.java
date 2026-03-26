import java.util.*;
import java.util.Map.Entry;

import javax.swing.ToolTipManager;

import org.xml.sax.HandlerBase;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.*;
import java.sql.Array;





public class Simple{
    public static class Node{
        int v;
        int val;
        
        public Node(int v,int val){
            this.val = val;
            this.v = v;
        }

    }
    static final Random random=new Random();
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str="";
            try {
                str=br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    static class FastWriter {
		private final BufferedWriter bw;

		public FastWriter() {
			this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
		}

		public void print(Object object) throws IOException {
			bw.append("" + object);
		}

		public void println(Object object) throws IOException {
			print(object);
			bw.append("\n");
		}

		public void close() throws IOException {
			bw.close();
		}
	}
    static void ruffleSort(int[] a) {
        int n=a.length;
        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n), temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }
    static void ruffleSort(long[] a) {
        int n=a.length;
        for (int i=0; i<n; i++) {
            long oi=random.nextInt(n), temp=a[(int)oi];
            a[(int)oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }
    
    public static class Pair implements Comparable<Pair>{
        int x;
        int y;

        public Pair(int x,int y){
            this.x = x;
            this.y = y;
        }
        public int compareTo(Pair other){
            
            return this.y - other.y;
            
        }
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + x;
            result = prime * result + y;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            Pair other = (Pair) obj;

            if (x != other.x)
                return false;
            if (y != other.y)
                return false;
            return true;
        }
        // public boolean equals(Pair other){
        //     if(this.x == other.x && this.y == other.y)return true;
        //     return false;
        // }
        // public int hashCode(){
        //     return 31*x + y;
        // }
        // @Override
        // public int compareTo(Simple.Pair o) {
        //     // TODO Auto-generated method stub
        //     return 0;
        // }
         
    }
    static long power(long x, long y, long p)
    {
 
        // Initialize result
        long res = 1;
 
        // Update x if it is more than or
        // equal to p
        x = x % p;
 
        while (y > 0) {
 
            // If y is odd, multiply x
            // with result
            if (y % 2 == 1)
                res = (res * x) % p;
 
            // y must be even now
            y = y >> 1; // y = y/2
            x = (x * x) % p;
        }
 
        return res;
    }
 
    // Returns n^(-1) mod p
    static long modInverse(long n, long p)
    {
        return power(n, p - 2, p);
    }
 
    // Returns nCr % p using Fermat's
    // little theorem.
    static long nCrModPFermat(long n, long r,
                             long p)
    {
 
          if (n<r)
              return 0;
      // Base case
        if (r == 0)
            return 1;
 
        // Fill factorial array so that we
        // can find all factorial of r, n
        // and n-r
        long[] fac = new long[(int)n + 1];
        fac[0] = 1;
 
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % p;
 
        return (fac[(int)n] * modInverse(fac[(int)r], p)
                % p * modInverse(fac[(int)n - (int)r], p)
                % p)
            % p;
    }

    static int nCrModp(int n, int r, int p)
    {
        if (r > n - r)
            r = n - r;
 
        // The array C is going to store last
        // row of pascal triangle at the end.
        // And last entry of last row is nCr
        int C[] = new int[r + 1];
 
        C[0] = 1; // Top row of Pascal Triangle
 
        // One by constructs remaining rows of Pascal
        // Triangle from top to bottom
        for (int i = 1; i <= n; i++) {
 
            // Fill entries of current row using previous
            // row values
            for (int j = Math.min(i, r); j > 0; j--)
 
                // nCj = (n-1)Cj + (n-1)C(j-1);
                C[j] = (C[j] + C[j - 1]) % p;
        }
        return C[r];
    }

    
    static int gcd(int a, int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
    static long gcd_long(long a, long b)
    {
        // Everything divides 0
        if (a == 0)
          return b;
        if (b == 0)
          return a;
      
        // base case
        if (a == b)
            return a;
      
        // a is greater
        if (a > b)
            return gcd_long(a-b, b);
        return gcd_long(a, b-a);
    }
    

    
    // public static int helper(int arr[],int n ,int i,int j,int dp[][]){
    //     if(i==0 || j==0)return 0;
        
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(helper(arr, n, i-1, j-1, dp)>=0){
    //         return dp[i][j]=Math.max(helper(arr, n, i-1, j-1,dp)+arr[i-1], helper(arr, n, i-1, j,dp));
    //     }
    //     return dp[i][j] = helper(arr, n, i-1, j,dp);

    // }
    // public static void  dfs(ArrayList<ArrayList<Integer>> al,int levelcount[],int node,int count){
    //     levelcount[count]++;
    //     for(Integer x : al.get(node)){
    //         dfs(al, levelcount, x, count+1);
    //     }
        
    // }


    public static long __gcd(long a, long b)
    {
        if (b == 0)
            return a;
        return __gcd(b, a % b);
        
    }
 
    public static class DSU{
        int n;
        int par[];
        int rank[];

        public DSU(int n){
            this.n = n;
            par = new int[n+1];
            rank = new int[n+1];

            for(int i=1;i<=n;i++){
                par[i] = i ;
                rank[i] = 0;
            }
        }
        public int findPar(int node){
            if(node==par[node]){
                return node;
            }
            return par[node] = findPar(par[node]);//path compression
        }
        public void union(int u,int v){
            u = findPar(u);
            v = findPar(v);
            if(rank[u]<rank[v]){
                par[u] = v;
            }
            else if(rank[u]>rank[v]){
                par[v] = u;
            }
            else{
                par[v] = u;
                rank[u]++;
            }
        }
    }  
    public static boolean isPallindrome(char[] arr,int n,boolean vis[]){
        int i=0;
        int j= n-1;
        while(i<j){
            if(vis[i])i++;
            else if(vis[j])j--;
            else{
                if(arr[i]!=arr[j])return false;
                i++;
                j--;
            }
        }
        return true;
    }
    public static List<List<Integer>> permute(int[] nums) {
        List<Integer> list = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        
        helper(ans,list,nums,nums.length);
        return ans;
    }
    
    public static void  helper(List<List<Integer>> ans,List<Integer> list,int nums[],int n){
        if(list.size()==n){
            ans.add(new ArrayList<>(list));
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!list.contains(nums[i])){
                list.add(nums[i]);
                helper(ans,list,nums,n);
                list.remove(list.size()-1);
                
            }
            
        }
        
        
    }
    static int level = 0;
    static ArrayList<Integer> nodes;
    public static int printShortestPath(Map<Integer,Integer> par, int s, int d)
        {
            level = 0;
  
            // If we reached root of shortest path tree
            if (par.get(s) == -1)
            {
                System.out.printf("Shortest Path between"+ 
                                "%d and %d is %s ", s, d, s);
                return level;
            }
  
            printShortestPath(par, par.get(s), d);
  
            level++;
            // if (s < this.V)
            //     System.out.printf("%d ", s);
  
            return level;
        }
  
        // finds shortest path from source vertex 's' to
        // destination vertex 'd'.
  
        // This function mainly does BFS and prints the
        // shortest path from src to dest. It is assumed
        // that weight of every edge is 1
    public static void swap(char arr[],int i){
        char c = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = c;
    }
    public static String mul(String str,int n){
        int carry = 0;
        StringBuilder muli = new StringBuilder(); 
        for(int i=n-1;i>=0;i--){
            int val = str.charAt(i) - '0';
            int ans = val*2 + carry;
            carry = ans/10;
            ans = ans%10;
            char c = (char)(ans + '0');
            muli.append(c);
        }
        if(carry!=0){
            muli.append((char)(carry + '0'));

        }
        muli.reverse();
        return muli.toString();
    }
    static boolean isSmaller(String str1, String str2)
    {
        // Calculate lengths of both string
        int n1 = str1.length(), n2 = str2.length();
        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;
 
        for (int i = 0; i < n1; i++)
            if (str1.charAt(i) < str2.charAt(i))
                return true;
            else if (str1.charAt(i) > str2.charAt(i))
                return false;
 
        return false;
    }
 
    // Function for find difference of larger numbers
    static String findDiff(String str1, String str2)
    {
        // Before proceeding further, make sure str1
        // is not smaller
        if (isSmaller(str1, str2)) {
            String t = str1;
            str1 = str2;
            str2 = t;
        }
 
        // Take an empty string for storing result
        String str = "";
 
        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();
 
        // Reverse both of strings
        str1 = new StringBuilder(str1).reverse().toString();
        str2 = new StringBuilder(str2).reverse().toString();
 
        int carry = 0;
 
        // Run loop till small string length
        // and subtract digit of str1 to str2
        for (int i = 0; i < n2; i++) {
            // Do school mathematics, compute difference of
            // current digits
            int sub
                = ((int)(str1.charAt(i) - '0')
                   - (int)(str2.charAt(i) - '0') - carry);
 
            // If subtraction is less then zero
            // we add then we add 10 into sub and
            // take carry as 1 for calculating next step
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;
 
            str += (char)(sub + '0');
        }
 
        // subtract remaining digits of larger number
        for (int i = n2; i < n1; i++) {
            int sub = ((int)(str1.charAt(i) - '0') - carry);
 
            // if the sub value is -ve, then make it
            // positive
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;
 
            str += (char)(sub + '0');
        }
        
        // reverse resultant string
        return new StringBuilder(str).reverse().toString();
    }
    public static double cal1(double x1,double x2,double y1,double y2){
        double x = Math.abs(x1 - x2);
        double y = Math.abs(y1 - y2);
        double ans = x*x + y*y;
        return Math.sqrt(ans);
    }
    
    public static void main(String args[]){  
        
        try {
            FastReader s=new FastReader();
            FastWriter out = new FastWriter();
            // Scanner s = new Scanner(System.in);
            // int testCases=s.nextInt();
            int testCases = 1;
            int counter = 0;
            // int something = 0;
            while(testCases-- > 0){
                // counter++;
                // x0, y0, ax, ay, bx, by
                long x0 = s.nextLong();
                long y0 = s.nextLong();
                long ax = s.nextLong();
                long ay = s.nextLong();
                long bx = s.nextLong();
                long by = s.nextLong();


                long xs = s.nextLong();
                long ys = s.nextLong();
                long time = s.nextLong();


                ArrayList<Long> x = new ArrayList<>();
                ArrayList<Long> y = new ArrayList<>();
                x.add(x0);
                y.add(y0);
                
                long max = (long)Math.pow(10, 18);
                while(true){
                    long x00 = x0;
                    long y00 = y0;
                    x0 = ax*x0 + bx;
                    y0 = ay*y0 + by;
                    if(x00>=x0 || y00>=y0)break;
                    if(x0>=max || y0>=max || x0< 0 || y0<0)break;
                    x.add(x0);
                    y.add(y0);
                }
                int size = x.size();
                // System.out.println(x.toString());
                // System.out.println(y.toString());
                long ans = 0;
                for(int i=0;i<size;i++){
                    long temp = time;
                    long cover = 0;
                    temp-= (Math.abs(xs - x.get(i)) + Math.abs(ys - y.get(i)));
                    if(temp>=0)cover++;
                    for(int j =i -1;j>=0 && temp>=0;j--){
                        temp-= (Math.abs(x.get(j) - x.get(j+1)) + Math.abs(y.get(j) - y.get(j+1)));
                        if(temp>=0 || temp>time)cover++;
                        else break;
                    }
                    ans = Math.max(ans,cover);
                    temp = time;
                    cover =0 ;
                    temp-= (Math.abs(xs - x.get(i)) + Math.abs(ys - y.get(i)));
                    if(temp>=0)cover++;
                    for(int j =i +1;j<size && temp>=0;j++){
                        temp-= (Math.abs(x.get(j) - x.get(j-1)) + Math.abs(y.get(j) - y.get(j-1)));
                        if(temp>=0 || temp > time)cover++;
                        else break;
                    }
                    ans = Math.max(ans, cover);
                }
                System.out.println(ans);
            }
               
            
        } 
        catch (Exception e) {
            System.out.println(e.toString());
            // System.out.println("Eh");
            return;
        }
        
    }
    
}    

/*
1 3 4 5 2
2 4 3 5 1


*/