import java.util.*;

public class MergeSort {

    static int[][] move = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {-1, 1}, {0, -1}, {-1, -1}, {0, -1}};

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int test = 1;
        while (test-- > 0) {
            String s = sc.nextLine();
            int i=0;int j=s.length()-1;
            List<Integer> list = new ArrayList<>();
            while(i<j){
                if(s.charAt(i)=='('){
                    if(s.charAt(j)==')'){
                        list.add(i);
                        list.add(j);
                        i++;
                    }
                    j--;
                }else{
                    i++;
                }
            }
            Collections.sort(list);
            if (list.isEmpty())
                System.out.print(0);
            else {
                System.out.println(1);
                System.out.println(list.size());
                for (Integer x : list)
                    System.out.print((x + 1) + " ");
            }
        }
    }


    static class Group implements Comparable<Group>{
        int x;int y;
        Group(int x, int y){
            this.x=x;this.y=y;
        }

        @Override
        public int compareTo(Group o) {
            return x-o.x;
        }
    }


    //////////Helper Functions////////////////////////////////////

    private static char getCharFromASCII(int c) {
        return (char) (c + 96);
    }

    private static boolean isValidPos(long x, long y, long i, long j) {
        return i < x && i >= 0 && j >= 0 && j < y;
    }

    private static int getFactorial(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++) res = res * i;
        return res;
    }

    private static boolean isPalindrome(char[] s) {
        int start = 0, last = s.length - 1;
        while (start < last) {
            if (s[start] != s[last]) return false;
            start++;
            last--;
        }
        return true;
    }

    private static void swap(int i, int j, long[] arr) {
        long temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static void swap(int i, int j) {
        int temp = i;
        i = j;
        j = temp;
    }

    private static boolean isEven(int a) {
        return a % 2 == 0;
    }

    static int findGCD(int x, int y) {
        int r = 0, a, b;
        a = Math.max(x, y);
        b = Math.min(x, y);
        r = b;
        while (a % b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return r;
    }

    static int findLcm(int a, int b) {
        return (a * b) / findGCD(a, b);
    }

    private static boolean primalityTest(int n) {
        if (n == 1) return false;
        for (int i = 2; i * i < n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    private static void swap(int i, int j, char[] arr) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static Pair asFraction(long a, long b) {
        long gcd = gcd(a, b);
        return new Pair(a / gcd, b / gcd);
    }

    static class Pair {
        long x, y, z;

        Pair(int x, int y){
            this.x=(int)x;this.y=(int)y;
        }

        Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        Pair(long x, long y, long z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
}
