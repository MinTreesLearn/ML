import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.Entry;

public class Solution2 {
	
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
                }
                catch (IOException e) {
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
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
	
	static boolean isPrime(long n)
    {
        // Corner cases
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
  
        // This is checked so that we can skip
        // middle five numbers in below loop
        if (n % 2 == 0 || n % 3 == 0)
            return false;
  
        for (long i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
  
        return true;
    }
		
	public static int gcd(int a, int b) {
	    int t;
	    while(b != 0){
	        t = a;
	        a = b;
	        b = t%b;
	    }
	    return a;
	}
	
	public static boolean relativelyPrime(int a, int b) {
	    return gcd(a,b) == 1;
	}
	
	static int __gcd(int a, int b)  
    {  
        return b == 0? a:__gcd(b, a % b);     
    }
  
	// recursive implementation
	static int GcdOfArray(int[] arr, int idx)
	{
	    if (idx == arr.length - 1) {
	        return arr[idx];
	    }
	    int a = arr[idx];
	    int b = GcdOfArray(arr, idx + 1);
	    return __gcd(
	        a, b); // __gcd(a,b) is inbuilt library function
	}

	public static class Pair{
		long a;
		long b;
		Pair(long a, long b){
			this.a = a;
			this.b = b;
		}
	}
	
	static int merge(ArrayList<int[]> intervals){
		
		int[] temp = new int[2];
	    temp[0] = intervals.get(0)[0];
	    temp[1] = intervals.get(0)[1];
	    ArrayList<int[]> ls = new ArrayList<>(); 
	    ls.add(temp);
	    int j = 0;
	    for(int i=0; i<intervals.size()-1; i++){
	        if((temp[1]>=intervals.get(i+1)[0] && temp[1]<=intervals.get(i+1)[1]) ||  (temp[0]>=intervals.get(i+1)[0] && temp[0]<=intervals.get(i+1)[1])){
	        	if(temp[0]<intervals.get(i+1)[0]) temp[0] = intervals.get(i+1)[0];
	            if(temp[1]>intervals.get(i+1)[1]) temp[1] = intervals.get(i+1)[1];
	        }
	        else{
	        	return 0;
	        }
	    }
//	   	for(int[] arr: ls) {
//			System.out.println(arr[0] + " " + arr[1]);
//	   	}
	    return Math.abs(temp[1]-temp[0]);
	}
		
	public static void main(String[] args) throws Exception{
						
		FastReader sc = new FastReader();	
	
		int t = sc.nextInt();
		while(t-- > 0) {
		
			long n = sc.nextLong();
			long x = sc.nextLong();
			long y = sc.nextLong();
			
			long total = x + y;
			
			long a = x==1&&y==1 ? total - 2 : total - 1;
			if(a<=0) a = 1;
			if(a>n) a = n;
			
			if(a<y) {
				a++;
			}
			long worst = a;
			
			long b = y==n&&x==n ? n-1 : n;
			
			long c = total - b + 1;
			if(c<=0) c = 1;
			if(c>n) c = n;
			System.out.println(c + " " + worst);
			
			
//			for(int i=1; i<n+1; i++) {
//				if(i!=x) {
//					if(j!=y && j>0) {
//						if(total<i+j) ans++;
//						j--;
//					}
//					else {
//						j--;
//					}
//				}
//			}1
//			1000000000 1 1000000000
//			System.out.println(ans + " " + Integer.valueOf(n-ans));
			
 		}
		
	}
}
