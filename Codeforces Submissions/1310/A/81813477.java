    
import java.util.*;
import java.io.*;
public class Main {
    static FastReader in=new FastReader();
    static StringBuilder Sd=new StringBuilder();
    static List<Integer>Gr[]; 
    static long Mod=998244353;
    static Map<Integer,Integer>map=new HashMap<>();
    public static void main(String [] args) {
    	//Dir by MohammedElkady
    	int n=in.nextInt();
    	int a[]=fillint(n);
    	node[]node=new node[n];
    	long ans=0L;
    	for(int i=0;i<n;i++){
    		int t=in.nextInt();
    	 node[i]=(new node(a[i],t));
    	}
    	Sorting.bucketSort((node),n);
    	for(int i=n-1;i>=0;i--) {
    		int x=node[(i)].x,t=node[i].t;
    		if(!map.containsKey(x)) {map.put(x, x+1);}
    		else {
    			int z=MakeHash(x);
    			int lol=z-1-x;
    			ans+=((long)lol*(long)t);
    		}
    	}
    	Soutln(ans+"");
    Sclose();
    
}
    static int MakeHash(int z) {
    	if(map.containsKey(z)) {
    		int w=map.get(z);
    		w=MakeHash(w);
    		map.put(z, w);
    		return w;
    	}
    	else {
    		map.put(z, z+1);
    		return z+1;
    	}
    }
    static long power(long x, long y, long p) 
    { 
          
        // Initialize result 
        long res = 1; 
      
        // Update x if it is more than or 
        // equal to p 
        x = x % p; 
                      
        while (y > 0) 
        { 
              
            // If y is odd, multiply x 
            // with result 
            if (y % 2 == 1) 
                res = (res * x) % p; 
      
            // y must be even now 
            y = y >> 1; // y = y/2 
            x = (x * x) % p; 
        } 
          
        return res; 
    } 
      
    // Returns n^(-1) mod p 
    static long modInverse(long n, long p) 
    { 
        return power(n, p-2, p); 
    } 
      
    // Returns nCr % p using Fermat's 
    // little theorem. 
    static long nCrModPFermat(int n, int r, 
                                    long p) 
    { 
          
        // Base case 
        if (r == 0) 
            return 1; 
      
        // Fill factorial array so that we 
        // can find all factorial of r, n 
        // and n-r 
        long[] fac = new long[n+1]; 
        fac[0] = 1; 
          
        for (int i = 1 ;i <= n; i++) 
            fac[i] = fac[i-1] * i % p; 
      
        return (fac[n]* modInverse(fac[r], p) 
                % p * modInverse(fac[n-r], p) 
                                    % p) % p; 
    } 
    static long fac(int n , int m,int l) {
    	long res=1;
    	for(int i=l,u=1;i<=n||u<=m;i++,u++) {
    		if(i<=n) {res*=i;}
    		if(u<=m) {res/=u;}
    		while(res>Mod)
    		res-=Mod;
    	}
    	return res;
    }
    static long posation(int n) {
     long res=1;
     for(int i=0;i<n-3;i++) {res*=2L;
     while(res>Mod)
     res-=Mod;
     while(res<=0)res+=Mod;}
     return res;
    }
   
    static long gcd(long g,long x){
        if(x<1)return g;
        else return gcd(x,g%x);
    }
    //array fill
    static long[]filllong(int n){long a[]=new long[n];for(int i=0;i<n;i++)a[i]=in.nextLong();return a;}
    static int[]fillint(int n){int a[]=new int[n];for(int i=0;i<n;i++)a[i]=in.nextInt();return a;}
    //OutPut Line
    static void Sout(String S) {Sd.append(S);}
    static void Soutln(String S) {Sd.append(S+"\n");}
    static void Soutf(String S) {Sd.insert(0, S);}
    static void Sclose() {System.out.println(Sd);}
    static void Sclean() {Sd=new StringBuilder();}
}
class node implements Comparable<node>{
int x,t;
	node(int x,int p){
		this.x=x;
		this.t=p;
	}
	@Override
	public int compareTo(node o) {
       return (t-o.t);
	}
}
class FastReader
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
}
 
class Sorting{
 
 public static node[] bucketSort(node[] array, int bucketCount) {
 
 if (bucketCount <= 0) throw new IllegalArgumentException("Invalid bucket count");
 
 if (array.length <= 1) return array; //trivially sorted
 
 
 
 int high = array[0].t;
 
 int low = array[0].t;
 
 for (int i = 1; i < array.length; i++) { //find the range of input elements
 
 if (array[i].t > high) high = array[i].t;
 
 if (array[i].t < low) low = array[i].t;
 
 }
 
 double interval = ((double)(high - low + 1))/bucketCount; //range of one bucket
 
 
 ArrayList<node> buckets[] = new ArrayList[bucketCount];
 
 for (int i = 0; i < bucketCount; i++) { //initialize buckets
 
 buckets[i] = new ArrayList();
 
 }
 
 
 
 for (int i = 0; i < array.length; i++) { //partition the input array
 
 buckets[(int)((array[i].t - low)/interval)].add(array[i]);
 
 }
 
 
 int pointer = 0;
 
 for (int i = 0; i < buckets.length; i++) {
 
 Collections.sort(buckets[i]); //mergeSort
 
 for (int j = 0; j < buckets[i].size(); j++) { //merge the buckets
 
 array[pointer] = buckets[i].get(j);
 
 pointer++;
 
 }
 
}
 
return array;
 
}
}