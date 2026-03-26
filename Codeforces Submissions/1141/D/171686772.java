// package codeforce;
import java.util.*;
import java.net.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;
public class A {
	static class Node {
		
		
		 int id1;
		int id2;
		
		Node(int  v1, int w1){
			
			this.id1= v1;
			this.id2=w1;
			
		}
		Node(){}

	}
    static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next(){ 
            while (st == null || !st.hasMoreElements()){ 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e){ 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt(){ 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong(){ 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble(){ 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine(){ 
            String str = ""; 
            try{ 
                str = br.readLine(); 
            } 
            catch (IOException e){ 
                e.printStackTrace(); 
            } 
            return str; 
        }
        int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
    }
    
    static boolean[] seiveofEratoSthenes(int n) {
		boolean[] isPrime= new boolean[n+1];
		Arrays.fill(isPrime, true);
		isPrime[0]=false;
		isPrime[1]= false;
		for(int i=2;i*i<=n;i++) {
			for(int j=2*i; j<=n;j=j+i) {
				isPrime[j]= false;
			}
		}
		return isPrime;
	}
    static int in = 2;
    
 // Function check whether a number
 // is prime or not
 public static boolean isPrime(int n)
 {
	 // Check if number is less than
     // equal to 1
     if (n <= 1)
         return false;

     // Check if number is 2
     else if (n == 2)
         return true;

     // Check if n is a multiple of 2
     else if (n % 2 == 0)
         return false;

     // If not, then just check the odds
     for (int i = 3; i <= Math.sqrt(n); i += 2)
     {
         if (n % i == 0)
             return false;
     }
     return true;
 }
static class SortingComparator implements Comparator<Node>{
	@Override
	public int compare(Node p1, Node p2) {
//		 int n = p1.id1-p2.id1;
//		 if(n!=0)return n;
		 return p1.id2-p2.id2;
}
		
	
}
static int pp =1;
static long[] dp = new long[500001];
	public static void main(String[] args) throws UnknownHostException {
		
		    FastReader sc = new FastReader();
		    PrintWriter out = new PrintWriter(System.out);
		    long n = sc.nextLong();
		   char[] a= sc.next().toCharArray();
		   char[] b = sc.next().toCharArray();
		   HashMap<Character, PriorityQueue<Integer>> hs = new HashMap<>();
		   HashSet<Integer> anonq= new HashSet<Integer>();
		   for(int i=0; i<a.length; i++) {
			   if(hs.containsKey(a[i])) {
				   PriorityQueue<Integer> al = hs.get(a[i]);
				   al.add(i);
				   hs.put(a[i], al);
			   }
			   else {
				   PriorityQueue<Integer> al= new PriorityQueue<Integer>();
				   al.add(i);
				   hs.put(a[i], al);
				   
			   }
			   if(a[i]!='?')anonq.add(i);
		   }
		   int ans =0;
		   
		   HashMap<Integer, Integer> hm = new HashMap<>();
		   PriorityQueue<Integer> bques= new PriorityQueue<Integer>();
		   PriorityQueue<Integer> bnonq= new PriorityQueue<Integer>();
		   for(int i=0; i<b.length; i++) {
			   
			   
			   if(hs.containsKey(b[i]) && b[i]!='?') {
				   ans++;
				   PriorityQueue<Integer> al = hs.get(b[i]);
				   int p = al.poll();
				   hm.put(i, p);
				   anonq.remove(p);
				   if(al.size()==0) {
					   hs.remove(b[i]);
				   }
			   }
			   else if(b[i]=='?'){
				   bques.add(i);
			   }
			   else {
				   bnonq.add(i);
			   }
		   }
		   PriorityQueue<Integer> aques= new PriorityQueue<Integer>();
		   if(hs.containsKey('?')) {
			   
			   for(int e:hs.get('?')) {
				   aques.add(e);
			   }
		   }
		   while(aques.size()>0 && bnonq.size()>0) {
			   ans++;
			   hm.put(bnonq.poll(), aques.poll());
		   }
		   PriorityQueue<Integer> ano= new PriorityQueue<Integer>();
		   for(int e: anonq) {
			   ano.add(e);
		   }
		   while(ano.size()>0 && bques.size()>0) {
			   ans++;
			   hm.put(bques.poll(), ano.poll());
		   }
		   while(aques.size()>0 && bques.size()>0) {
			   ans++;
			   hm.put(bques.poll(), aques.poll());
		   }
		  out.println(ans);
		   for(HashMap.Entry<Integer, Integer> e: hm.entrySet() ) {
			   out.println((e.getValue()+1)+" "+(e.getKey()+1));
		   }
		   out.close();
		    
		    
		    
		
	}
	static long nextPowerOf2(long N)
    {
        // if N is a power of two simply return it
        if ((N & (N - 1)) == 0)
            return N;
        return 0x4000000000000000L
            >> (Long.numberOfLeadingZeros(N) - 2);
    }
 
	public static int[] solve(int[] arr, int[] it) {
		
			HashMap<Integer, Integer> hm = new HashMap<>();
			for(int i=0; i<arr.length; i++) {
				hm.put(arr[i], hm.getOrDefault(arr[i], 0)+1);
				
			}
			for(int i=0; i<arr.length; i++) {
				it[i]= hm.get(arr[i]); 
			}
			return it;
			
		
	}
	public static void rec(int l, int e, int[] arr) {
		if(l>e || e>=arr.length || l<=0)return;
		int mid = (e-l+1)%2==0?(e+l-1)/2:(e+l)/2;
		if(arr[mid]==0 ) {
		arr[mid]=pp;
		pp++;
//		if(pp>1)return;
		}
		if(e-mid-1<=mid-l-1) {rec(l, mid-1, arr);
		rec(mid+1, e, arr);
		}
		else {
			rec(mid+1, e, arr);
			rec(l, mid-1, arr);
			
		}
		
	}
	static double fact(double n)
	{
	   int i=1;
             	    double fact=1;
	    while(i<=n)
	    {
	   	   fact=fact*i;
		   i++;
 	    }
  	      return fact;
	}
	static double combination(int n,int r)
	{
		double com=fact(n)/(fact(n-r)*fact(r));
		return com;
	}
	static boolean digit(long n) {
		long ans = n;
		while(n>0) {
			long rem = n%10;
			if(rem!=0 && ans%rem!=0)return false;
			n=n/10;
		}
		return true;
	}

	static int nCr(int n, int r)
	{
	    return fact(n) / (fact(r) *
	                  fact(n - r));
	}
	 
	// Returns factorial of n
	static int fact(int n)
	{
	    int res = 1;
	    for (int i = 2; i <= n; i++)
	        res = res * i;
	    return res;
	}
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l, Collections.reverseOrder());
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

	static boolean isPalindrome(char[] arr, int i, int j) {
		while(i<j) {
			if(arr[i]!=arr[j])return false;
			i++;
			j--;
		}
		return true;
	}
	static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }

	static int max =0;
	static void dfs(int i, boolean[] vis , ArrayList<ArrayList<Integer>> adj) {
		max = Math.max(max,  i);
		vis[i]= true;
		for(int e: adj.get(i)) {
			if(vis[e]==false) {
				dfs(e, vis, adj);
			}
		}
	}

	
	static int gcd(int a, int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
     
	static double pow(int a, int b) {
		long res= 1;
		while(b>0) {
			if((b&1)!=0) {
				res= (res*a);
			}
			a= (a*a);
			b= b>>1;
		}
		return res;
	}
	
	static void permute(String s , String answer, HashSet<String> hs)
	{   
	    if (s.length() == 0)
	    {
	        hs.add(answer);
	        return;
	    }
	      
	    for(int i = 0 ;i < s.length(); i++)
	    {
	        char ch = s.charAt(i);
	        String left_substr = s.substring(0, i);
	        String right_substr = s.substring(i + 1);
	        String rest = left_substr + right_substr;
	        permute(rest, answer + ch, hs);
	    }
	}
	}


