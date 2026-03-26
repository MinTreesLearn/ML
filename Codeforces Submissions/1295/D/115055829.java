import java.io.*;





import java.util.*;
/*


                                                                                                                                                                                                                        (36210193, 61984219)
*/








public class B {
	static FastReader sc=null;
	
	public static void main(String[] args) {
		sc=new FastReader();
		int t=sc.nextInt();
		while(t-->0) {
			long a=sc.nextLong(),m=sc.nextLong();
			m/=gcd(a,m);
			System.out.println(phi(m));
		}
	
		
		
	}
	static long phi(long n) {
	    long result = n;
	    for (long i = 2; i * i <= n; i++) {
	        if (n % i == 0) {
	            while (n % i == 0)
	                n /= i;
	            result -= result / i;
	        }
	    }
	    if (n > 1)
	        result -= result / n;
	    return result;
	}
	
	
	
	
	
	
	
	
	
	static int[] reverseSort(int a[]) {
		ArrayList<Integer> al=new ArrayList<>();
		for(int i:a)al.add(i);
		Collections.sort(al,Collections.reverseOrder());
		for(int i=0;i<a.length;i++)a[i]=al.get(i);
		return a;
	}
	static int[] reverse(int a[]) {
		ArrayList<Integer> al=new ArrayList<>();
		for(int i:a)al.add(i);
		Collections.reverse(al);
		for(int i=0;i<a.length;i++)a[i]=al.get(i);
		return a;
	}
	static char[] reverse(char a[]) {
		ArrayList<Character> al=new ArrayList<>();
		for(char i:a)al.add(i);
		Collections.reverse(al);
		for(int i=0;i<a.length;i++)a[i]=al.get(i);
		return a;
	}
	static int gcd(int a,int b) {
		if(b==0)return a;
		else return gcd(b,a%b);
	}
	static long gcd(long a,long b) {
		if(b==0)return a;
		else return gcd(b,a%b);
	}
	
	static int[] ruffleSort(int a[]) {
		ArrayList<Integer> al=new ArrayList<>();
		for(int i:a)al.add(i);
		Collections.sort(al);
		for(int i=0;i<a.length;i++)a[i]=al.get(i);
		return a;
	}
	
	
	
	static void print(int a[]) {
		for(int e:a) {
			System.out.print(e+" ");
		}
		System.out.println();
	}
	static void print(boolean a[]) {
		for(boolean e:a) {
			System.out.print(e+" ");
		}
		System.out.println();
	}
	static void print(long a[]) {
		for(long e:a) {
			System.out.print(e+" ");
		}
		System.out.println();
	}
	static void print(char a[]) {
		for(char e:a) {
			System.out.print(e);
		}
		System.out.println();
	}
	
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
        int[] readArray(int n) {
    		int a[]=new int [n];
    		for(int i=0;i<n;i++) {
    			a[i]=sc.nextInt();
    		}
    		return a;
    	}
    } 
}






