import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scn = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);
        // Always print a trailing "\n" and close the OutputWriter as shown at the end of your output
        
        // example;
        ArrayList<Integer> arr1=new ArrayList<Integer>();
        prime(arr1);
        int t=scn.nextInt();
        for(int i1=0;i1<t;i1++){
            long a=scn.nextLong();long m=scn.nextLong();
            long g=gcd1(m,a);a=a/g;m=m/g;
            long ans=m;
            for(int p:arr1){
                if(m%p==0){
                   while(m%p==0){
                       m=m/p;
                   } 
                   ans=ans*(p-1)/p;
                }
            }
            if(m>1){
                ans=(ans/m)*(m-1);
            }
            out.print(Long.toString(ans)+"\n");
        }
        
        out.close();
    }
    public static long gcd1(long a,long b){
        if(a>=b){
            while(b>0){
                long m=a%b;
                a=b;
                b=m;
            }
            return(a);
        }
        else{
            return(gcd1(b,a));
        }
    }
    public static void prime(ArrayList<Integer> arr1){
        int[] arr=new int[100001];
        for(int i=2;i<=100000;i++){
            if(arr[i]==0){
                arr1.add(i);
                if(i>=1000){
                    continue;
                }
                for(int j=i*i;j<=100000;j=j+i){
                    arr[j]=1;
                }
            }
        }
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