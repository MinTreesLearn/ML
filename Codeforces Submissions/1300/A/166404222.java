import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;
 
public class coding {
	
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;
 
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
 
		String next() {
			while(st == null || !st.hasMoreElements()) {
				try {
					String str = br.readLine();
 
					if(str == null)
						throw new InputMismatchException();
 
					st = new StringTokenizer(str);
				} catch(IOException e) {
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
			} catch(IOException e) {
				e.printStackTrace();
			}
 
			if(str == null) 
				throw new InputMismatchException();
			return str;
		}

		public BigInteger nextBigInteger() {
			// TODO Auto-generated method stub
			return null;
		}
	}
	public static <K, V> K getKey(Map<K, V> map, V value)
    {
        for (Map.Entry<K, V> entry: map.entrySet())
        {
            if (value.equals(entry.getValue())) {
                return entry.getKey();
            }
        }
        return null;
    }
	

    public static void main(String args[] ) throws Exception {
       
//    	FastReader sc = new FastReader();
//		PrintWriter out = new PrintWriter(System.out);
    	Scanner sc=new Scanner(System.in);
    	int t=sc.nextInt();
    	while(t-->0)
    	{
			Integer n=sc.nextInt();
			int arr[]=new int[n];
			int s=0;
			int c=0;
			int x=0;
			for(int i=0;i<n;i++)
			{
				arr[i]=sc.nextInt();
				s=s+arr[i];
				if(arr[i]==0)
				{
					c++;
				}
			}
			Arrays.sort(arr);
			if(s==0 && c==0)
			{
				x=1;
			}
			if(s==0 && c>0)
			{
				x=c;
			}
			if(s!=0 && c==0)
			{
				x=0;
			}
			if(s!=0 && c>0)
			{
				x=c;
				s=s+c;
				if(s==0)
				{
					x++;
				}
			}
			System.out.println(x);
		}
    }
}