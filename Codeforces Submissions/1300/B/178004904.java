import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.*;
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
        InputReader sc = new InputReader(inputStream);
        int i,n,t,j;
        t=sc.nextInt();
        while(t-->0)
        {
            n=sc.nextInt();
            int []arr=new int[2*n];
            for(i=0;i<2*n;i++)
            {
                arr[i]=sc.nextInt();
            }
            Arrays.sort(arr);
            System.out.println(Math.abs(arr[n-1]-arr[n]));
        }
    }
    static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
 
		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}
        public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
				    tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
				    throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
        public int nextInt() {
			return Integer.parseInt(next());
		}
}
}