
import java.io.*;
import java.util.*;
 
public class Codeforces{
    static long mod = 1000000007L;
//    map.put(a[i],map.getOrDefault(a[i],0)+1);
    // map.putIfAbsent;
    
    static MyScanner sc = new MyScanner();
  //<----------------------------------------------WRITE HERE------------------------------------------->
    static void solve(){
    	
    	long n = sc.nextLong();
    	
    	long  a = 1;
    	long b = n;
    	
    	for(long i=2;i*i<=n;i++) {
    		
    		if(n%i == 0 && i != n/i) {
    			
    			if(gcd(i,n/i) == 1) {
    				a = i;
        			b = n/i;
    			}
    		}
    	}
    	out.print(a+" "+b);
	}
    
    private static void sieve(boolean[] a, int n) {
    	
    	a[1] = true;
    	
    	for(int i=2;i*i<=n;i++) {
    		
    		if(!a[i]) {
    			for(int j=i*i;j<=n;j+=i)
    				a[j] = true;
    		}
    	}
    	
    }
    
    static boolean isPrime(long n) {
    	
    	for(int i=2;i*i<=n;i++) {
    		if(n%i == 0) {
    			return false;
    		}
    	}
    	return true;
    }
    
    static long modInv(long x,long mod) {
    	return expo(x,mod-2,mod)%mod;
    }
    
    static long expo(long x,long k,long mod) {
    	
    	long res = 1;
    	
    	while(k>0) {
    		if(k%2 != 0) {
    			res = (res*x)%mod;
    			k--;
    		}
    		x = (x*x)%mod;
    		k /= 2;
    	}
    	return res%mod;
    }
    
  //<----------------------------------------------WRITE HERE------------------------------------------->
    static void swap(int[] a,int i,int j) {
    	int temp = a[i];
    	a[i] = a[j];
    	a[j] = temp;
    }
    static void priArr(int[] a) {
    	for(int i=0;i<a.length;i++) {
    		out.print(a[i] + " ");
    	}
    	out.println();
    }
    static long gcd(long a,long b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    
    static class Pair implements Comparable<Pair>{
        Integer val;
        Integer ind;
        Pair(int v,int f){
            val = v;
            ind = f;
        }
        public int compareTo(Pair p){
        	int s1 = this.ind-this.val;
        	int s2 = p.ind-p.val;
        	
            if(s1 != s2) return s1-s2;
            return this.val - p.val;
        }
    }
    public static void main(String[] args) {
 
        out = new PrintWriter(new BufferedOutputStream(System.out));
//        int t = sc.nextInt();
        int t= 1;
        while(t-- >0){
            solve();
        }
        // Stop writing your solution here. -------------------------------------
        out.close();
    }
    //-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;
 
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
        public int[] readIntArray(int n){
            int arr[] = new int[n];
            for(int i = 0;i<n;i++){
                arr[i] = Integer.parseInt(next());
            }
            return arr;
        }
        int[] reverse(int arr[]){
            int n= arr.length;
            int i = 0;
            int j = n-1;
            while(i<j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j--;i++;
            }
            return arr;
        }
        long[] readLongArray(int n){
            long arr[] = new long[n];
            for(int i = 0;i<n;i++){
                arr[i] = Long.parseLong(next());
            }
            return arr;
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
    private static void sort(int[] arr) {
        List<Integer> list = new ArrayList<>();
        for (int i=0; i<arr.length; i++){
            list.add(arr[i]);
        }
        Collections.sort(list); // collections.sort uses nlogn in backend
        for (int i = 0; i < arr.length; i++){
            arr[i] = list.get(i);
        }
    
    }
}