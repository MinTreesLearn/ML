
import java.io.*;
import java.util.*;
public class Solution {
    
	public static long gcd(long a,long b) {
		if(a==0) return b;
		return gcd(b%a,a);
	}
	public static long lcm(long a,long b) {
		return (a*b)/gcd(a,b);
	}
	
	public static long [] input(BufferedReader br,int n)  throws java.lang.Exception{
		long ans[]=new long[n];
		String input[]=br.readLine().split(" ");
		for(int i=0;i<n;i++) {
			ans[i]=Long.parseLong(input[i]);
		}
		return ans;
	}
	
	static class FenWick{
		long tree[];
		int n;
		public FenWick(int n) {
			tree=new long[n];
			this.n=n;
		}
		public void add(int idx,long x) {
			while(idx<n) {
				tree[idx]+=x;
				idx+=(idx&-idx);
			}
		}
		public long sum(int idx) {
			long sum=0;
			while(idx>0) {
				sum=sum+tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
	}
	
	public static long[] compress(long s[]) {
		List<Long>list=new ArrayList<>();
		for(long a:s) list.add(a);
		Collections.sort(list);
		HashMap<Long,Long>map=new HashMap<>();
	    Long b=1l;
	    for(int i=0;i<list.size();i++) {
	    	if(!map.containsKey(list.get(i))) {
	    		map.put(list.get(i), b++);
	    	}
	    }
	    long out[]=new long[s.length];
	    for(int i=0;i<s.length;i++) {
	    	out[i]=map.get(s[i]);
	    }
	    return out;
	}
	public static void main(String[] args) throws java.lang.Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out=new PrintWriter(System.out);
		
//		int testCases=Integer.parseInt(br.readLine());
		int testCases=1;
		while(testCases-->0) {
			
			int n=(int)input(br,1)[0];
			long x[]=input(br,n);
			long s[]=input(br,n);
			s=compress(s);
			List<int[]>list=new ArrayList<>();
			for(int i=0;i<n;i++) {
				list.add(new int[] {(int)x[i],(int)s[i]});
			}
			Collections.sort(list,(a,b)->(int)(a[0]-b[0]));
			FenWick obj1=new FenWick(n+1);
			FenWick obj2=new FenWick(n+1);
			long ans=0;
			for(int i=0;i<list.size();i++) {
				int a[]=list.get(i);
				int v=a[1];
				long ct=obj1.sum(v);
				long st=obj2.sum(v);
				ans+=a[0]*ct-st;
				obj1.add(v, 1);
				obj2.add(v, a[0]);
			}
			out.println(ans);
			
		}
		out.close();
	}

}
