/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
 
/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
   //------------------------------------------------input class---------------------------------------//
     static class FastReader {
        BufferedReader br; 
        StringTokenizer st;
        public FastReader() {
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try{    st = new StringTokenizer(br.readLine());  }
                catch (IOException  e){  e.printStackTrace();   }
            } 
            return st.nextToken(); 
        }
        int nextInt() {  return Integer.parseInt(next());  }
        long nextLong() {  return Long.parseLong(next());  }
        double nextDouble() {  return Double.parseDouble(next());   } 
        String nextLine() {
            String str = ""; 
            try{ str = br.readLine();  }
            catch (IOException e){  e.printStackTrace(); } 
            return str; 
        } 
    }
    //-------------------------------------------segment tree-----------------------------------------//
    static int[] segment;
    static void constructSt(int n, int[] arr){
        segment = new int[n*4+1];
        formSt(arr, 1,0,n-1);
    }
    public static void formSt(int[] arr, int node, int s, int e){
        if(s==e){
            segment[node]= arr[s];
            return;
        }
        formSt(arr, node*2,s,s+(e-s)/2);
        formSt(arr, node*2+1,s+(e-s)/2+1,e);
        segment[node]=Math.max(segment[node*2],segment[node*2+1]);
    }
    public static int findMax( int node, int s, int e,int l , int r){
        if(l>e||s>r) return -1;
        if(s==e) return segment[node];
        if(l<=s&&r>=e) return segment[node];
        int mid = s+(e-s)/2;
        return Math.max(findMax(node*2,s,mid,l,r),findMax(node*2+1,mid+1,e,l,r));
    }
    //-----------------------------------------dsu-----------------------------------------//
    static int[] parent,rank;
    public static void dsu(int n){
        parent = new int[n]; rank = new int[n];
        for(int i =0;i<n;i++) parent[i]=i;
    }
    public static int find(int i){
        if(i==parent[i] ) return i;
        return parent[i]=find(parent[i]);
    }
    public static void merge(int i, int j){
        if(rank[i]>=rank[j]){
            rank[i]+=rank[j];
            parent[j]=i;
        }
        else {
            rank[j]+=rank[i];
            parent[i]=j;
        }
    }
    //-------------------------------------------topological sort--------------------------------------//
     public static int[] topo(List<List<Integer>> a , int n , int[] in){
        int[] ans = new int[n+1];
        PriorityQueue<Integer> p = new PriorityQueue<>((x,y)->a.get(x).size()-a.get(y).size());
        for(int i =1;i<=n;i++) if(in[i]==0) p.add(i);
        int i =1;
        while(p.size()>0){
            int e = p.poll();
            ans[i++]= e;
            for(int temp : a.get(e)){
                in[temp]--;
                if(in[temp]==0)
                p.add(temp);
            }
        }
        return ans;
    }
    //-------------------------------------------max--------------------------------------------------//
    public static int max (int a, int b){
        return a>=b?a:b;
    }
      public static long max (long a, long b){
        return a>=b?a:b;
    }
     public static int max (int a, int b, int c){
        return Math.max(a,Math.max(b,c));
    }
     public static long max (long a, long b, long c){
        return Math.max(a,Math.max(b,c));
    }
   
    //------------------------------------------min---------------------------------------------------//
     public static int min (int a, int b){
        return a<=b?a:b;
    }
     public static long min (long a, long b){
        return a<=b?a:b;
    }
     public static int min (int a, int b, int c){
        return Math.min(a,Math.min(b,c));
    }
     public static long min (long a, long b, long c){
        return Math.min(a,Math.min(b,c));
    }
    //----------------------------------------- gcd-----------------------------------------//
    public static int gcd(int a, int b){
        if(a==0) return b;
        if(b==0 ) return a;
        if(a<b) return gcd(b%a,a);
        return gcd(a%b,b);
    }
     public static long gcd(long a, long b){
        if(a==0) return b;
        if(b==0 ) return a;
        if(a<b) return gcd(b%a,a);
        return gcd(a%b,b);
    }
    //-------------------------------------lcm------------------------------------------------------//
    public static int lcm(int a, int b){
        return (a*b)/gcd(a,b);
    }
    public static long lcm(long a, long b){
        return (a*b)/gcd(a,b);
    }
    //---------------------------------------------binary search--------------------------------------//
    public static  int binary(int arr[], int x)
    {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == x) return m;
            if (arr[m] < x) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
     public static int binary(long arr[], long x)
    {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == x)  return m;
            if (arr[m] < x)   l = m + 1;
            else  r = m - 1;
        }
        return -1;
    }
    //---------------------------------------helping methods---------------------------------------------//
   
    //------------------------------------------main------------------------------------------------------//
	public static void main (String[] args) throws java.lang.Exception
	{
	 OutputStream outputStream =System.out;
        PrintWriter out =new PrintWriter(outputStream);
        FastReader sc =new FastReader();
        int t =1;
        while(t-->0){
            char[] a = sc.nextLine().toCharArray();
            int n  = a.length;
            long[][] dp = new long[26][26];
            long[] freq = new long[26];
            long max =0;
            for(char e: a){
                for(int i =0;i<26;i++){
                     dp[e-'a'][i]+= freq[i];
                     max = max(dp[e-'a'][i],max);
                }
                freq[e-'a']++;
                max= max(max, freq[e-'a']);
            }
            out.print(max);
          out.print("\n");
        }
	    out.close();
		// your code goes here"
	}
}
 class pair
    {
        long x;
        long y;
        public pair(long x , long y)
        {
            this.x= x;
            this.y= y;
        }
    }
class node{
    int x, y;
     public node(int x , int y)
        {
            this.x= x;
            this.y= y;
        }
    
}
class solution{
    
    }
