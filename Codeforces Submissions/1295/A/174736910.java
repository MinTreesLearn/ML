import java.io.*;
import java.util.*;
public class cf1 {
    // author: Utkarsh Singh 

    // PRIMARY VARIABLES
    //private static int n, m, k, x, y;
    //private static int[] a, b;
    private static long ans=0;
    private static long[] a;
    private static long[][] dp;
    //private static String s, t;
    //private static HashMap<Integer, ArrayList<Integer>> g;
    //static ArrayList<Integer> al;//=new ArrayList<Integer>();
    //static ArrayList<ArrayList<Integer>> al;
    private static HashMap<Long,Long> hm=new HashMap<Long,Long>();
    private static HashSet<Long> hs=new HashSet<Long>();
    //private static Stack<Integer> sk=new Stack<Integer>();
    //private static Queue<Integer> q=new LinkedList<Integer>();
    //private static PriorityQueue<Integer> pq=new PriorityQueue<Integer>();
    //for(int i=0;i<n;i++)
    //for (Map.Entry<Integer, Integer> entry : hm.entrySet()) {
    // CONSTANTS
    /*private static final int MOD = (int) 1e9 + 7;
    private static final int[] dx = { -1, 1, 0, 0 };
    private static final int[] dy = { 0, 0, -1, 1 };
    private static final int MAX = Integer.MAX_VALUE;
    private static final int MIN = Integer.MIN_VALUE;
    private static final long MAXL = (long) 1e18;
    private static final long MINL = -(long) 1e18;*/
    static Scanner in= new Scanner(System.in);

    public static void main(String[] args) {
        //print("Utkarsh");
        //int t=ini();
        //while(t-->0)
        solve();
    }

    public static void solve()
    {
        int n=ini();
        for(int k=0;k<n;k++)
        {
            int x=ini();
            if(x%2==0)
            {
                for(int i=0;i<x/2;i++)
                    System.out.print("1");
                System.out.println();
            }
            else
            {
                System.out.print("7");
                x-=3;
                for(int i=0;i<x/2;i++)
                    System.out.print("1");
                System.out.println();
            }
        }

    }
    // INPUT SHORTCUTS
    private static long[] ina(int n) {
        long[] temp = new long[n];
        for (int i = 0; i < n; i++) {
            temp[i] = in.nextLong();
        }
        return temp;
    }

    private static long[][] ina2d(int n, int m) {
        long[][] temp = new long[n][m];
        for (int i = 0; i < n; i++) {
            temp[i] = ina(m);
        }
        return temp;
    }

    private static char[][] ina2dChar(int n, int m) {
        char[][] temp = new char[n][];
        for (int i = 0; i < n; i++) {
            temp[i] = ins().toCharArray();
        }
        return temp;
    }

    private static int ini() {
        return in.nextInt();
    }

    private static long inl() {
        return in.nextLong();
    }

    private static double ind() {
        return Double.parseDouble(ins());
    }

    private static String ins() {
        return in.next();
    }
    // PRINT ANSWER
    private static void print(Object o) {
        System.out.println(o);
    }

    private static void printT(Object o, int testCaseNo) {
        System.out.println("Case #" + testCaseNo + ": " + o);
    }

    private static void printA(int[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
}

