import java.io.*;
import java.util.*;
public class function {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int testcases = Integer.parseInt(r.readLine());
        for (int t = 0; t < testcases; t++) {
            StringTokenizer st = new StringTokenizer(r.readLine());
            long len = Integer.parseInt(st.nextToken());
            long ones = Integer.parseInt(st.nextToken());
            long zeroes = len-ones;
            long complement = 0;
            complement += substrings(zeroes/(ones+1)+1) * (zeroes%(ones+1));
            //pw.println(substrings(zeroes/(ones+1)+1));
            //pw.println("complement is " + complement);
            complement += substrings(zeroes/(ones+1)) * ((ones+1)-zeroes%(ones+1));
            long total = len*(len+1)/2;
            //pw.println("complement is " + complement);
            pw.println(total - complement);
        }
        pw.close();
    }
    public static long substrings(long n) {
        return n*(n+1)/2;
    }
}