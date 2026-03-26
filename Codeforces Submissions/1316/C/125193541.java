import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        Scanner scn = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);
        // Always print a trailing "\n" and close the OutputWriter as shown at the end of your output
        
        // example:
        int n=scn.nextInt();int m=scn.nextInt();int p=scn.nextInt();
        int[] a=new int[n];int[] b=new int[m];
        int i1=-1;int i2=-1;
        for(int i=0;i<n;i++){
            a[i]=scn.nextInt()%p;
            if(i1==-1&&a[i]!=0){
                i1=i;
            }
        }
        for(int i=0;i<m;i++){
            b[i]=scn.nextInt()%p;
            if(i2==-1&b[i]!=0){
                i2=i;
            }
        }
        out.print((i1+i2)+"\n");
        out.close();
    }

    // fast input
    static class Scanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public Scanner(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String line = reader.readLine();
                    if (line == null)
                        return null;
                    tokenizer = new StringTokenizer(line);
                } catch (Exception e) {
                    throw(new RuntimeException());
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() { return Integer.parseInt(next()); }
        public long nextLong() { return Long.parseLong(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
    }

    // fast output
    static class OutputWriter {
        BufferedWriter writer;

        public OutputWriter(OutputStream stream) {
            writer = new BufferedWriter(new OutputStreamWriter(stream));
        }

        public void print(int i) throws IOException { writer.write(i); }
        public void print(String s) throws IOException { writer.write(s); }
        public void print(char[] c) throws IOException { writer.write(c); }
        public void close() throws IOException { writer.close(); }
    }


}