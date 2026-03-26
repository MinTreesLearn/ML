import java.io.*;





import java.util.*;
/*


*/









public class B {
	static FastReader sc=null;
	static int nax=(int)1e5;
	static int even=0,odd=0;
	static int a[];
	static int n;
	
	public static void main(String[] args) {
		sc=new FastReader();
		n=sc.nextInt();
		a=sc.readArray(n);
		if(n==1) {
			System.out.println(0);
			return;
		}
		//DP[I][J][2] -> IS THE MINIMUM PARITY TILL 'I' WE CAN GET IF WE PLACE 'J' EVEN PARITY ONES 
		//[0] -> INDICATES THE ONE BEFORE IT IS EVEN PARITY
		//[1] -> INDICATES THE ONE BEFORE IT IS ODD PARITY
		
		//DP[I][J][0] = DP[I-1][J-1][0] | DP[I-1][J-1][1] + [PLACE EVEN PARITY ONE HERE]
		//DP[I][J][1] = DP[I-1][J][0] | DP[I-1][J][1] + [PLACE ODD PARITY ONE HERE]
		
		
		//DP[I][J][0|1] -> IF NOT '0' = DP[I-1][J][0]

		
		Set<Integer> s=new HashSet<>();
		for(int e:a)if(e!=0)s.add(e);
		
		for(int i=1;i<=n;i++) {
			if(!s.contains(i)) {
				if(i%2==0)even++;
				else odd++;
			}
		}
		int dp[][][]=new int[n][even+1][2];
		for(int i=0;i<n;i++)
			for(int j=0;j<=even;j++)Arrays.fill(dp[i][j], nax);
		int curr=0;
		if(a[0]!=0) {
			dp[0][0][0]=dp[0][0][1]=0;
			if(a[0]%2==0) dp[0][0][1]=nax;
			else dp[0][0][0]=nax;
		}
		else {
			curr++;
			dp[0][0][1]=0;
			dp[0][1][0]=0;
		}
		for(int i=1;i<n;i++) {
			for(int j=0;j<=even;j++) {
				if(a[i]!=0) {
					if(a[i]%2==0) {
						dp[i][j][0]=Math.min(dp[i-1][j][0],dp[i-1][j][1]+1);
						dp[i][j][1]=nax;
					}
					else {
						dp[i][j][1]=Math.min(dp[i-1][j][1],dp[i-1][j][0]+1);
						dp[i][j][0]=nax;
					}
				}
				else {
					
					dp[i][j][1]=Math.min(dp[i-1][j][1], dp[i-1][j][0]+1);
					if(j>0)dp[i][j][0]=Math.min(dp[i-1][j-1][0], dp[i-1][j-1][1]+1);
					curr++;
				}
			}
		}
		
		System.out.println(Math.min(dp[n-1][even][0],dp[n-1][even][1]));
		
	
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






