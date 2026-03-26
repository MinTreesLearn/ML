import java.io.*;
import java.util.*;
/*
        Set<String> hash_Set = new HashSet<String>();
// Demonstrating Set using HashSet
        // Declaring object of type String
        Set<String> hash_Set = new HashSet<String>();

        // Adding elements to the Set
        // using add() method
        hash_Set.add("Geeks");
        hash_Set.add("For");
        hash_Set.add("Geeks");
        hash_Set.add("Example");
        hash_Set.add("Set");

        // Printing elements of HashSet object
        System.out.println(hash_Set);
 */
public class Main {
    static boolean flag = false;
    static BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static StringTokenizer tok;

    public static void check() throws IOException {
        if (tok == null || !tok.hasMoreTokens())
            tok = new StringTokenizer(read.readLine());
    }

    public static int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextString());
    }

    public static String nextString() throws IOException {
        check();
        return tok.nextToken();
    }

    public static void println(Object o) {
        out.println(o);
        out.flush();
    }

    public static int[] nextArray(int n) throws IOException {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }

    static int findLCM(int x, int y) {
        //   LCM(a, b) = (a x b) / GCD(a, b)
        return (x * y) / findGCD(x, y);
    }

    static int findGCD(int x, int y) {
        int r = 0, a, b;
        a = (x > y) ? x : y;
        b = (x < y) ? x : y;
        r = b;
        while (a % b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return r;
    }

    /*
    boolean [] primes = new boolean[n+1];
            for(int i =0; i<primes.length; i++){
                primes[i] =true;
            }
            for(int i =2; i*i< primes.length; i++){
                if(primes[i] == true){
                    for(int j = i*i; j<=n; j+=i){
                        primes[j] =false;
                    }
                }

            }
     */


    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        char[] x = input.next().toCharArray();
        int lCounter = 0;
        int rCounter = 0;
        for(int i = 0; i<x.length; i++){
            if(x[i] == 'L')
                lCounter++;
            else
                rCounter++;
        }

        out.write(lCounter+rCounter+1+"\n");


        out.flush();
        out.close();

    }


    }






/*
5
*
* *
* * *
* * * *
* * * * *
 */










/*
5

*
* *
* * *
* * * *
* * * * *
 */

/*
input:5
output:
*
**
***
****
*****
 */








