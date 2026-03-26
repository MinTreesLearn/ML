import java.io.*;
import java.util.*;

public class A1 {
    static final Reader s = new Reader();
    static final PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
//        int t  = s.nextInt();
        int t=1;
        for(int i=1; i<=t; ++i) {
//            out.print("Case #"+i+": ");
            new Solver();
        }
        out.close();
    }
    static class Solver {
        Solver() {
        	Scanner sc = new Scanner(System.in); 
        	int n = sc.nextInt(),m = sc.nextInt();
      	    sc.nextLine();
        	String[] a = sc.nextLine().split(" ");
        	String[] b = sc.nextLine().split(" ");
        	int q = sc.nextInt();
	       	while(q-->0) {
	       		int q1 = sc.nextInt();
	       		int g = q1%n; 
	       		int h = q1%m;
	       		if(g==0)g=n;
	       		if(h==0)h=m;
	       		String ans="";
	       		ans+=a[g-1]+b[h-1];
	     		System.out.println(ans);
	       	}
        }
    }
    static class Reader {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String next() {
            while(st==null||!st.hasMoreTokens()) {
                try {
                    st=new StringTokenizer(in.readLine());
                } catch(Exception e) {}
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

}