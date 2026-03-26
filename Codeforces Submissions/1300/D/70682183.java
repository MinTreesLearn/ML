import java.util.*;
import java.io.*;
public class Main{


	public static void main (String args[])throws IOException{
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
//		int t=sc.nextInt();
//		while(t-->0) {
			
			int n =sc.nextInt();
			Pair arr[]= new Pair[n];
			
			for(int i=0; i<n; i++)
				arr[i]=new Pair(sc.nextInt(), sc.nextInt());
			
			if(n%2==1)
				out.println("NO");
			else {
				
				boolean b=true;
				for(int i=0; i<n/2-1; i++) {
					int x1=arr[i+1].x-arr[i].x;
					int y1=arr[i+1].y-arr[i].y;
					int x2=arr[n/2+i+1].x-arr[n/2+i].x;
					int y2=arr[n/2+i+1].y-arr[n/2+i].y;
					//out.println(x1+" "+y1+" "+x2+" "+y2);
					if((long)x1*y2!=(long)x2*y1 ||
						distance(arr[i+1], arr[i])!= distance(arr[n/2+i+1], arr[n/2+i])	) {
						b=false;
						break;
					}
				}
				
				if(b)
					out.println("YES");
				else
					out.println("NO");
				
			}
		
	
		out.flush();
		
	}	
	
	
	static long distance(Pair p1, Pair p2) {
		return ((long)p1.x-p2.x)*(p1.x-p2.x)+((long)p1.y-p2.y)*(p1.y-p2.y);
	}
	
	
	
	static void print(int[] arr) {
		for(int i=0; i<arr.length; i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
	
	public static int abs(int x) {return ((x > 0) ? x : -x);}
	
	public static int max(int a, int b) {return Math.max(a, b);}
	
	public static int min(int a, int b) {return Math.min(a, b);}
	
	
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

class Pair{
	int x;
	int y;
	Pair(int a, int b){
		x=a;
		y=b;
	}
}

