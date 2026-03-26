import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Nekos_Maze_Game {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		FastReader sc = new FastReader();
		StringBuilder sb = new StringBuilder();
		
		int n = sc.nextInt();
		int q = sc.nextInt();
		
		HashSet<String> set = new HashSet<>();
		int blocks = 0;
		
		while(q-->0) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			String s = String.valueOf(r)+","+String.valueOf(c);
			if(!set.isEmpty()&&set.contains(s)) {
				set.remove(s);
				int x = func(set,r,c);
				blocks -= x;
			}else {
				set.add(s);
				int x = func(set,r,c);
				blocks += x;
			}
			if(blocks>0)
				System.out.println("No");
			else
				System.out.println("Yes");
		}
		
	}
	public static int func(HashSet<String> set,int r,int c) {
		int count = 0;
		for(int i=-1;i<=1;i++) {
			String s = String.valueOf(r-1)+","+String.valueOf(c+i);
			if(!set.isEmpty()&&set.contains(s))
				count++;
		}
		for(int i=-1;i<=1;i++) {
			String s = String.valueOf(r+1)+","+String.valueOf(c+i);
			if(!set.isEmpty()&&set.contains(s))
				count++;
		}
		return count;
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
