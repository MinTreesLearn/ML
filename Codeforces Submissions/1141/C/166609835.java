import java.io.*;
import java.util.*;
 
public class CF1562C extends PrintWriter {
	CF1562C() { super(System.out); }
	public static Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1562C o = new CF1562C(); o.main(); o.flush();
	}

        
	static long calculate(long p, long q)
{
    long mod = 1000000007, expo;
    expo = mod - 2;
 
    // Loop to find the value
    // until the expo is not zero
    while (expo != 0)
    {
 
        // Multiply p with q
        // if expo is odd
        if ((expo & 1) == 1)
        {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
 
        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p;
}
 static String longestPalSubstr(String str)
    {
        // The result (length of LPS)
        int maxLength = 1;
 
        int start = 0;
        int len = str.length();
 
        int low, high;
 
        // One by one consider every
        // character as center
        // point of even and length
        // palindromes
        for (int i = 1; i < len; ++i) {
            // Find the longest even
            // length palindrome with
            // center points as i-1 and i.
            low = i - 1;
            high = i;
            while (low >= 0 && high < len
                   && str.charAt(low)
                          == str.charAt(high)) {
                --low;
                ++high;
            }
           
              // Move back to the last possible valid palindrom substring
            // as that will anyway be the longest from above loop
            ++low; --high;
            if (str.charAt(low) == str.charAt(high) && high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
 
            // Find the longest odd length
            // palindrome with center point as i
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < len
                   && str.charAt(low)
                          == str.charAt(high)) {
                --low;
                ++high;
            }
           
              // Move back to the last possible valid palindrom substring
            // as that will anyway be the longest from above loop
            ++low; --high;
            if (str.charAt(low) == str.charAt(high) && high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
        }
 
  
        return str.substring(start, start + maxLength - 1);
 
    }
 
long check(long a){
                 long ret=0;
                 for(long k=2;(k*k*k)<=a;k++){
                  ret=ret+(a/(k*k*k));                
                 }
                 return ret;
}
/*public static int getFirstSetBitPos(int n)
	{
		return (int)((Math.log10(n & -n)) / Math.log10(2)) + 1;
	}
	public static int bfsq(int n, int m, HashMap<Integer,ArrayList<Integer>>h,boolean v ){
	                 v[n]=true;
	                 if(n==m)
	                 return 1;
	                 else 
	                 {
	                                  int a=h.get(n).get(0);
	                                  int b=h.get(n).get(1);
	                                  if(b>m)
	                                  return(m-n);
	                                  else 
	                                  {
	                                                   int a1=bfsq(a,m,h,v);
	                                                   int b1=bfsq(b,m,h,v);
	                                                   return 1+Math.min(a1,b1);
	                                  }
	                                  
	                 }
	}*/
	static long nCr(int n, int r)
{    return fact(n) / (fact(r) *
                  fact(n - r));
}
 
// Returns factorial of n
static long fact(long n)
{
    long res = 1;
    for (long i = 2; i <= n; i++)
        res = res * i;
    return res;
}
/*void bfs(int src, HashMap<Integer,ArrayList<Integer,Integer>>h,int deg, boolean v[] ){
                 a[src]=deg;
                 Queue<Integer>= new LinkedList<Integer>();
                 q.add(src);
                 while(!q.isEmpty()){
                                  (int a:h.get(src)){
                                                   if()
                                  }
                 }
                 
}*/
           
	 /*   void dfs(int root, int par, HashMap<Integer,ArrayList<Integer>>h,int dp[], int child[]) {
     
     dp[root]=0;
    child[root]=1;
     for(int x: h.get(root)){
         if(x == par) continue;
         dfs(x,root,h,in,dp);
         child[root]+=child[x];
     }
     ArrayList<Integer> mine= new ArrayList<Integer>();
         for(int x: h.get(root)) {
             if(x == par) continue;
             mine.add(x);
         }
         if(mine.size() >=2){
int y= Math.max(child[mine.get(0)] - 1 + dp[mine.get(1)] , child[mine.get(1)] -1 + dp[mine.get(0)]);
         dp[root]=y;}
else if(mine.size() == 1)
         dp[root]=child[mine.get(0)] - 1;
 }
	   */ 
class Pair implements Comparable<Pair>{
		int i;
		int j;
	Pair (int a, int b){
		i = a;
	j = b;
	}
	public int compareTo(Pair A){
		return (int)(this.i-A.i);
	}}
/*static class Pair {
        int i;
        int j;
        
        Pair() {
            
        }
        Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }*/
             /*ArrayList<Integer> check(int a[], int b){
                      int n=a.length;
                      long ans=0;int k=0;
                      ArrayList<Integer>ab= new ArrayList<Integer>();
                      for(int i=0;i<n;i++){
                               if(a[i]%m==0)
                               {k=a[i];
                                        while(a[i]%m==0){
                                                 a[i]=a[i]/m;
                                        }
                                        for(int z=0;z<k/a[i];z++){
                                                 ab.add(a[i]);
                                        }
                                        
                               }
                               else{
                                        ab.add(a[i]);
                               }
                      }
                      return ab;
             } */  
             /*int check[];
             int tree[];
             static void build( int []arr)
    {
         
        // insert leaf nodes in tree
        for (int i = 0; i < n; i++)
            tree[n + i] = arr[i];
         
        // build the tree by calculating
        // parents
        for (int i = n - 1; i > 0; --i){
        int ans= Math.min(tree[i << 1],
                      tree[i << 1 | 1]);
                      int ans1=Math.max((tree[i << 1],
                      tree[i << 1 | 1]));
                      if(ans==0)
                      
            
        }
    }*/
    
/*static void ab(long n)
    {
        // Note that this loop runs till square root
        for (long i=1; i<=Math.sqrt(n); i++)
        {
            if(i==1)
            {
                p.add(n/i);
                continue;
            }
            if (n%i==0)
            {
                // If divisors are equal, print only one
                if (n/i == i)
                    p.add(i);
      
                else // Otherwise print both
                {
                    p.add(i);
                    p.add(n/i);
                }
            }
        }
    }*/
 void main() {
//int g=sc.nextInt();
//int mod=1000000007;
//for(int w=0;w<g;w++){
         int n=sc.nextInt();
         long a[]= new long[n-1];
         for(int i=0;i<n-1;i++)
         a[i]=sc.nextLong();
         
         long mn=a[0];
         long mx=a[0];
         long b[]= new long[n-1];
         b[0]=a[0];
         long ans[]= new long[n];
         boolean check=true;
         boolean v[]= new boolean[n+1];
         for(int i=1;i<n-1;i++){
                  b[i]=b[i-1]+a[i];
                  if(b[i]>mx)
                  mx=b[i];
                  if(b[i]<mn)
                  mn=b[i];
         }int c=1;
         for(c=1;c<=n;c++){
                  if(c+mn>0&&c+mx<=n)
                  break;
         }
         if(c>n){
         println(-1);
         return;}
         else
         {
                  v[c]=true;
                  ans[0]=c;
                  for(int i=0;i<n-1;i++){
                  if(v[(int)(c+b[i])]==true)
                  {
                      check=false;
                      break;
                  }
                  else{
                      ans[i+1]=c+b[i];
                      v[(int)(c+b[i])]=true;
                  }}
                  if(!check)
                  println(-1);
                  else{
                      for(int i=0;i<n;i++)
                      print(ans[i]+" ");
                      println("");
                  }
                  
                  
         }
}
}





         


         