import java.util.*;
import java.io.*;
 
public class File {
	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		
		public FastScanner() {
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
	}
		
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		int test=sc.nextInt();
		while(test>0)
		{
		    int n=sc.nextInt();
		    String s=sc.next();
		    String ans="";
		    int a=0;
		    for(int i=1;i<=n;i++)
		    {
		        StringBuilder temp=new StringBuilder();
		        temp.append(s.substring(i-1));
		        StringBuilder add=new StringBuilder();
		        add.append(s.substring(0,i-1));
		        if(temp.length()%2!=0)add.reverse();
		        temp.append(add);
		        if(ans=="" || ans.compareTo(temp.toString())>0)
		        {
		           ans=temp.toString();
		           a=i;
		        }
		    }
		    out.println(ans);
		    out.println(a);
		    test--;
		}
		out.close();
	}
	
}