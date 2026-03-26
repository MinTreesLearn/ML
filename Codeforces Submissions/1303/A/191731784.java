import java.io.*;
import java.util.*;
public class Codeforces {
    public static void solve() {
        FastReader input = new FastReader();
        int testcases=input.nextInt();
        while(testcases-->0){
			String str=input.next();
			int first=0,last=0;
			int count1=0,count0=0;
			for(int i=0;i<str.length();i++){
				if(str.charAt(i)=='1'){
					count1++;
				}
				else if(str.charAt(i)=='0'){
					count0++;
				}
			}
			if(count1==0||count0==0){
				System.out.println(0);
				}
				else{
			for(int i=0;i<str.length();i++){
				if(str.charAt(i)=='1'){
					first=i;
					break;
				}
			}
			for(int i=str.length()-1;i>=0;i--){
				if(str.charAt(i)=='1'){
					last=i;
					break;
					}
			}
			int count=0;
			for(int i=first;i<=last;i++){
				if(str.charAt(i)=='0'){
					count++;
				}
			}
			System.out.println(count);
		}
		}
    }
    public static void input_output() {
        try {
            System.setIn(new FileInputStream("input.txt"));
            //System.setOut(new PrintStream("output.txt"));
        } catch (Exception e) {
            //System.out.println("Error");
        }
    }
    public static void main(String[] args)throws java.lang.Exception {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input_output();
            solve();
            } 
            else {
                solve();
            }
    }
    public static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                if (st.hasMoreTokens()) {
                    str = st.nextToken("\n");
                } else {
                    str = br.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
