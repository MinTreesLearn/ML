import java.util.*;
import java.io.*;
public class Main{


	public static void main (String args[])throws IOException{
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
		char[] str = sc.next().toCharArray(); 
		int t =sc.nextInt(), arr[][]=new int[str.length][26], k;
		arr[0][str[0]-97]=1;
		for(int i=1; i<str.length; i++) {
			for(int j=0; j<26; j++)
				arr[i][j] = arr[i-1][j];
			arr[i][str[i]-97]++;
		}
		
		while(t-->0) {
			int start=sc.nextInt()-1, end=sc.nextInt()-1, arr1[]=new int[26];
			if(start==end || str[start]!=str[end])
				out.println("YES");
			else {
				k=0;
				if(start!=0) {
					for(int j=0; j<26 && k<3; j++)
						if(arr[end][j]-arr[start-1][j]>0)
							k++;
				}
				else {
					for(int j=0; j<26 && k<3; j++)
						if(arr[end][j]>0)
							k++;
				}
				
					
				
				if(k==3)
					out.println("YES");
				else
					out.println("NO");
			}
			
		
			out.flush();
		}
		
	}	

	
	
	
	
	
	
	
	
	
	

	static long power(long num, long power) {
		long temp=1;
		for(int i=0; i<power; i++) {
			temp*=num;
			if(temp>100000)
				return -1;
		}
		return temp;
	}
	
	static long nearestKthPower(long num, long k) {
		long temp=1, count=0, a=num;
		
		while(num%2==0) {
			num/=2;
			count++;
		}
		if(count>=k)
			count=count%k;
		else if(count!=0)
			count=k-count;
		while(count-->0) {
			temp*=2;
			if(temp>100000)
				return -1;
		}
		if(num==1)
			return temp;
		for(int i=3; i*i<=a; i+=2) {
			count=0;
			while(num%i==0) {
				num/=i;
				count++;
			}
			if(count>=k)
				count=count%k;
			else if(count!=0)
				count=k-count;
			while(count-->0) {
				temp*=i;
				if(temp>100000)
					return -1;
			}
			if(num==1)
				return temp;
		}
		if(num>1) {
			count=k-1;
			while(count-->0) {
				temp*=num;
				if(temp>100000)
					return -1;
			}
		}
		return temp;
			
	}
	
    static int[] primeGenerator(int num) {
    	int length=0, arr[]=new int[num], a=num, factor=1;
    	if(num%2==0) {
    		while(num%2==0) {
    			num/=2;
    			factor*=2;
    		}
    		arr[length++]=factor;
    	}
    	for(int i=3; i*i<=a; i++) {
    		factor=1;
    		if(num%i==0) {
        		while(num%i==0) {
        			num/=i;
        			factor*=i;
        		}
        		arr[length++]=factor;
    		}
    	}
    	if(num>1)
    		arr[length++]=num;
    	return Arrays.copyOfRange(arr, 0, length);
    }


    static boolean isPrime(int n) 
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
  
        for (int i = 5; i * i <= n; i = i + 6) 
            if (n % i == 0 || n % (i + 2) == 0) 
                return false; 
  
        return true; 
    }












	static class Scanner {
		BufferedReader br;
		StringTokenizer st;

		Scanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		Scanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
		}

		String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		String nextLine() throws IOException {
			return br.readLine();
		}

		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		boolean ready() throws IOException {
			return br.ready();
		}

	}

	static void sort(int[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	static void shuffle(int[] a) {
		int n = a.length;
		Random rand = new Random();
		for (int i = 0; i < n; i++) {
			int tmpIdx = rand.nextInt(n);
			int tmp = a[i];
			a[i] = a[tmpIdx];
			a[tmpIdx] = tmp;
		}
	}
}


