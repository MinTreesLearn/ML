
import java.io.*;
import java.util.*;
 
public class Codeforces{
    static long mod = 1000000007L;
//    map.put(a[i],map.getOrDefault(a[i],0)+1);
    // map.putIfAbsent;
    
    static MyScanner sc = new MyScanner();
  //<----------------------------------------------WRITE HERE------------------------------------------->
    static void solve(){
    	
    	int n = sc.nextInt();
    	int m = sc.nextInt();
    	
    	int[] a = sc.readIntArray(n);
    	if(n>m) {
    		out.print(0);
    		return;
    	}
    	long ans = 1;
    	
    	for(int i=0;i<n-1;i++) {
    		for(int j=i+1;j<n;j++) {
    			ans = (ans * (long)(Math.abs(a[i]-a[j])))%m;
    		}
    	}
    	out.println(ans);
    }
    
    static int eea(int a, int b, int[] v) {
    	
    	if(b == 0) {
    		v[0] = 1;
    		v[1] = 0;
    		return a;
    	}
    	int g = eea(b,a%b,v);
    	
    	int x = v[0];
    	int y = v[1];
    	
    	v[0] = y;
    	v[1] = x - y*(a/b);
    	
//    	out.println(a+" "+v[0]+" "+b+" "+v[1]);
    	
    	return g;
    	
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
    static int gcd(int a,int b){
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