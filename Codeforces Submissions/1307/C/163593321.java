import java.util.*;
import java.io.*;
public class Main {	

    public static void main(String[] args) throws Exception {
    	
        FastReader sc = new FastReader();
        PrintWriter writer = new PrintWriter(System.out);
        long mod = 1000000007;

        int t = 1;
        while(t-->0) {
        	String s = sc.next();
    		long mat [][] = new long[26][26];
    		long ind[] = new long[26];
    		long max = 0;
    				
    		for(int i = 0; i < s.length(); i++) {
    			int val = s.charAt(i) - 'a';
    			for(int j = 0; j < 26; j++) {
    				mat[val][j]+=ind[j];
    				max = Math.max(max, mat[val][j]);
    			}
    			ind[val]++;
    			max = Math.max(max, ind[val]);
    		}
    		
    		writer.println(max);
        }

        writer.flush();
        writer.close();
    
    }    

	private static long power (long a, long n, long p) {
    	long res = 1;
    	while(n!=0) {
    		if(n%2==1) { 
    			res=(res*a)%p;
    			n--;
    		}else {
    			a= (a*a)%p;
    			n/=2;
    		}
    	}
    	return res;
    }
    
	private static boolean isPrime(int c) {
    	for (int i = 2; i*i <= c; i++) {
    		if(c%i==0)return false;
    	}
    	return true;
    }
	
	private static int find(int a , int arr[]) {
    	if(arr[a] != a) return arr[a] = find(arr[a], arr);
    	return arr[a];
    }
    
    private static void union(int a, int b, int arr[]) {
    	int aa = find(a,arr);
    	int bb = find(b, arr);
    	arr[aa] = bb;
    }
    
    private static int gcd(int a, int b) {
    	if(a==0)return b;
    	return gcd(b%a, a);
    }

public static int[] readIntArray(int size, FastReader s) {
    int[] array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = s.nextInt();
    }
    return array;
}

static class FastReader {
        BufferedReader br;
        StringTokenizer st;
    
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
    
        String next()
        {
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
    
        int nextInt() { return Integer.parseInt(next()); }
    
        long nextLong() { return Long.parseLong(next()); }
    
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
    
        String nextLine()
        {
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
    
}

class SegmentTree{
	int size;
	long arr[];
	SegmentTree(int n){
		size = 1;
		while(size<n)size*=2;
		arr = new long[size*2];
	}
	
	public void build(int input[]) {
		build(input, 0,0, size);
	}
	
	public void set(int i, int v) {
		set(i,v,0,0,size);
	}
	
	// sum from l + r-1
	public long sum(int l, int r) {
		return sum(l,r,0,0,size);
	}
	
	private void build(int input[], int x, int lx, int rx) {
		if(rx-lx==1) {
			if(lx < input.length )
			arr[x] = 1;
			return;
		}
		
		int mid = (lx+rx)/2;
		build(input, 2*x+1, lx, mid);
		build(input,2*x+2,mid,rx);
		arr[x] = arr[2*x+1] + arr[2*x+2];
		
	}
	
	private void set(int i, int v, int x, int lx, int rx) {
		if(rx-lx==1) {
			arr[x] = v;
			return;
		}
		
		int mid = (lx+rx)/2;
		if(i < mid) set(i, v, 2*x+1, lx, mid);
		else set(i,v,2*x+2,mid,rx);
		
		arr[x] = arr[2*x+1] + arr[2*x+2];
	}
	
	private long sum(int l, int r, int x, int lx, int rx) {
		if(lx>=r || rx <= l)return 0;
		if(lx>=l && rx <= r)return arr[x];
		int mid = (lx+rx)/2;
		long s1 = sum(l,r,2*x+1,lx,mid);
		long s2 = sum(l,r,2*x+2,mid,rx);
		return s2+s1;				
	}
	
//	int first_above(int v, int l, int x, int lx, int rx) {
//		if(arr[x].a<v)return -1;
//		if(rx<=l)return -1;
//		if(rx-lx==1)return lx;
//		int m = (lx+rx)/2;
//		int res = first_above(v,l,2*x+1,lx,m);
//		if(res==-1)res = first_above(v,l,2*x+2,m,rx);
//		return res;
//		
//	}
	
}

class Pair implements Comparable<Pair>{
    int a;
    int b;
    int c;
    Pair(int a, int b, int c){
        this.a = a;
        this.b = b;
        this.c = c;
    }

//    @Override
//    public boolean equals(Object obj) {
//          
//    if(this == obj) return true;
//    if(obj == null || obj.getClass()!= this.getClass()) return false;
//          
//        Pair pair = (Pair) obj;
//        return (pair.a == this.a && pair.b == this.b);
//    }

//    @Override
//  public int hashCode()
//  {
//    //	return Objects.hash(a,b);
//    	return new Long(a).hashCode() * 31 + new Long(b).hashCode();
//  }

	@Override
	public int compareTo(Pair o) {
		if(this.c != o.c)
	    return Integer.compare(this.c, o.c);
		else if(this.a != o.a)
		return Integer.compare(this.a, o.a);
		return Integer.compare(this.b, o.b);
	}
	
	@Override
	public String toString() {
		return this.a + " " + this.b;
	}

}