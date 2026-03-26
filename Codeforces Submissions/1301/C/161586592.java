
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
          
          public int[] check(String s) {
             int ans[]= new int[2];
        int maxans = 0;
        int dp[] = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s.charAt(i - dp[i - 1] - 1) == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                if(dp[i]==maxans)
            ans[1]=ans[1]+1;
            if(dp[i]>maxans){
            ans[0]=dp[i];
            ans[1]=1;
                    maxans = Math.max(maxans, dp[i]);}
            
            }
        }
        if(ans[0]==0)
        ans[1]=1;
        return ans;
    }       
 void main() {
int g=sc.nextInt();
for(int w=0;w<g;w++){
long n=sc.nextLong();
long m=sc.nextLong();
	long ans =n *(n + 1) / 2;
	long z = n - m;
	long k = z / (m + 1);
	ans -= (m + 1)*k*(k + 1)/2;
	ans -= (z%(m + 1))*(k + 1);
	println(ans); }
    }

}


                  

         