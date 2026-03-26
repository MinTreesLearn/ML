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

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
	
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		
		
		
		
		
		int T = sc.nextInt();
		
		for (int t = 1; t <= T; t++) {
			long n = sc.nextLong();
			long x = sc.nextLong();
			long y = sc.nextLong();	
			
			
			
			// Min = n - #lower score
			// Minimum overall place
			long lowerCount = 0L;
			
			// x-1 participants got a better score
				// Pair those with y_i such that 
				// x_i + y_i > total 
				// x-1 pairs with y+2
				// x-2 pairs with y+3...
			long lowerX = x - 1;
			long greaterY = Math.max(n - y - 1, 0);
			
			long pairs1 = Math.min(lowerX, greaterY);
			long greatestY = Math.min(n + 1, y + pairs1 + 1);
			
			// y-1 participants got a better score 
				// Pair those with x_i such that 
				// y-1 pairs with x+2
				// y-2 pairs with x+3...			
			long lowerY = y - 1;
			long greaterX = Math.max(n - x - 1, 0);
							
			long pairs2 = Math.min(lowerY, greaterX);			
			
			long greatestX = Math.min(n + 1, x + pairs2 + 1);
			
			// Then pair all remaining score x_i > x AND y_i > y with each other.
			long pairs3 = Math.max(0, Math.min(n - greatestY + 1, n - greatestX + 1));
			
			lowerCount = pairs1 + pairs2 + pairs3;
			long min = n - lowerCount;
			
			
			
			
			// Max = #equal score + #lower score
			// Maximum overall place
			long equalCount = 0L;
			lowerCount = 0L;
			
			// x-1 got better score 
				// Pair those with y_i
				// x_i + y_i = total 
				// x-1 pairs with y+1
				// x-2 pairs with y+2...
			long betterX = x - 1; 
			long worseY = n - y;
			pairs1 = Math.min(betterX, worseY);			
			long smallestX = betterX - pairs1;
			
			// y-1 got better y score 
				// Pair with x_i
				// y-1 pairs with x+1
				// y-2 pairs with x+2...
			long betterY = y - 1;
			long worseX = n - x;
			pairs2 = Math.min(betterY, worseX);
			long smallestY = betterY - pairs2;
				
			// Then pair all remaining x_i, y_i where x_i < x AND y_i < y
			pairs3 = Math.max(0, Math.min(smallestX, smallestY));
			
			
			
			equalCount = pairs1 + pairs2;
			lowerCount = pairs3;
			
			
			long max = equalCount + lowerCount + 1; // Including self.
			
			
			
			
			out.println(min + " " + max);
		}
		
		
		
		
		
		out.close();
	}
}








