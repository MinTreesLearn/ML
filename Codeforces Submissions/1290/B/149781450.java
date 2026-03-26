import java.io.*;
import java.util.*;

public class Anagrams {
	public static void main(String[] args) throws Exception {
		FastIO in = new FastIO();
		String s = in.next();
		int[][] prefix = new int[s.length()+1][26];
		for (int i=0; i<s.length(); i++) {
			for (int j=0; j<26; j++) {
				prefix[i+1][j] = prefix[i][j];
			}
			prefix[i+1][s.charAt(i)-'a']++;
		}
		int q = in.nextInt();
		for (int i=0; i<q; i++) {
			int l = in.nextInt();
			int r = in.nextInt();
			if (r-l==0) in.pr.println("Yes");
			else {
				int occ = 0;
				for (int j=0; j<26; j++) {
					if (prefix[r][j]-prefix[l-1][j]>0) occ++;
				}
//				in.pr.println(occ);
				if (occ>=3) in.pr.println("Yes");
				else if (occ==2) {
					if (s.charAt(r-1)==s.charAt(l-1)) in.pr.println("No");
					else in.pr.println("Yes");
				}
				else in.pr.println("No");
			}
		}
		in.pr.close();
	}
	static class FastIO {
		BufferedReader br;
	    StringTokenizer st;
	    PrintWriter pr;
	    public FastIO() throws IOException
	    {
	        br = new BufferedReader(
	            new InputStreamReader(System.in));
	        pr = new PrintWriter(System.out);
	        }
	    

	    public String next() throws IOException
	    {
	        while (st == null || !st.hasMoreElements()) {
	           
	            st = new StringTokenizer(br.readLine());
	        }
	        return st.nextToken();
	    }

	    public int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }

	    public long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }

	    public double nextDouble() throws NumberFormatException, IOException
	    {
	        return Double.parseDouble(next());
	    }

	    public String nextLine() throws IOException
	    {
	        String str = br.readLine();
	        return str;
	    }
	}
}
