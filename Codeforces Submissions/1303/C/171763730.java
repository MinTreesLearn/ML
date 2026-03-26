import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static int globalVariable = 123456789;
    static String author = "pl728 on codeforces";

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter pw = new PrintWriter(System.out);
        MathUtils mathUtils = new MathUtils();
        ArrayUtils arrayUtils = new ArrayUtils();

        int tc = sc.ni();
        while (tc-- != 0) {
            String s = sc.ns();

            // separate the string into two parts
            // if one part is a palindrome, and the other part has no repeating letters
            // then it's possible
            char[] keyboard = new char[26];
            List<Character> alphabet = new ArrayList<>();
            Set<Character> alphabetSet = new HashSet<>();
            int n = s.length();
            for (int i = 0; i < 26; i++) {
                alphabet.add((char) (i + 97));
                alphabetSet.add((char) (i + 97));
            }
            if (n == 1) {
                pw.println("YES");
                keyboard[0] = s.charAt(0);
                alphabet.remove(s.charAt(0) - 97);
                for (int i = 0; i < alphabet.size(); i++) {
                    keyboard[i + 1] = alphabet.get(i);
                }
                pw.println(keyboard);
                continue;
            }
            boolean ans = true;
            StringBuilder sb = new StringBuilder(s.charAt(0) + "" + s.charAt(1));
            int x = 1;
            alphabetSet.remove(s.charAt(0));
            alphabetSet.remove(s.charAt(1));

            for(int i = 2; i < n && ans; i++) {
                int m = sb.length();
                if(!alphabetSet.contains(s.charAt(i))) {
                    if(x == m - 1) {
                        if(sb.charAt(x - 1) == s.charAt(i)) x--;
                        else ans = false;
                    } else if (x == 0) {
                        if(sb.charAt(x + 1) == s.charAt(i)) x++;
                        else ans = false;
                    } else {
                        if(sb.charAt(x + 1) == s.charAt(i)) x++;
                        else if(sb.charAt(x - 1) == s.charAt(i)) x--;
                        else ans = false;
                    }
                } else {
                    if(x != m-1 && x != 0) {
                        ans = false;
                    } else {
                        if(x == 0) {
                            sb.insert(0, s.charAt(i));
                        } else {
                            sb.append(s.charAt(i));
                            x++;
                        }
                        alphabetSet.remove(s.charAt(i));
                    }
                }
            }

            if(ans) {
                pw.println("YES");
                pw.print(sb);
                for(char k : alphabetSet) {
                    pw.print(k);
                }
                pw.println();
            } else {
                pw.println("NO");
            }


        }
        pw.flush();
    }

    static class FastReader {
        /**
         * Uses BufferedReader and StringTokenizer for quick java I/O
         * get next int, long, double, string
         * get int, long, double, string arrays, both primitive and wrapped object when array contains all elements
         * on one line, and we know the array size (n)
         * next: gets next space separated item
         * nextLine: returns entire line as space
         */
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            this.br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        // to parse something else:
        // T x = T.parseT(fastReader.next());
        public int ni() {
            return Integer.parseInt(next());
        }

        public String ns() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public String[] readStringArrayLine(int n) {
            String line = "";
            try {
                line = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return line.split(" ");
        }

        public String[] readStringArrayLines(int n) {
            String[] result = new String[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.next();
            }
            return result;
        }

        public int[] readIntArray(int n) {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.ni();
            }
            return result;
        }

        public long[] readLongArray(int n) {
            long[] result = new long[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nl();
            }
            return result;
        }

        public Integer[] readIntArrayObject(int n) {
            Integer[] result = new Integer[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.ni();
            }
            return result;
        }

        public long nl() {
            return Long.parseLong(next());
        }

        public char[] readCharArray(int n) {
            return this.ns().toCharArray();
        }

    }

    static class MathUtils {
        public MathUtils() {
        }

        public long gcdLong(long a, long b) {
            if (a % b == 0)
                return b;
            else
                return gcdLong(b, a % b);
        }

        public long lcmLong(long a, long b) {
            return a * b / gcdLong(a, b);
        }
    }

    static class ArrayUtils {
        public ArrayUtils() {
        }

        public static int[] reverse(int[] a) {
            int n = a.length;
            int[] b = new int[n];
            int j = n;
            for (int i = 0; i < n; i++) {
                b[j - 1] = a[i];
                j = j - 1;
            }

            return b;
        }

        public int sumIntArrayInt(int[] a) {
            int ans = 0;
            for (int i = 0; i < a.length; i++) {
                ans += a[i];
            }

            return ans;
        }

        public long sumLongArrayLong(int[] a) {
            long ans = 0;
            for (int i = 0; i < a.length; i++) {
                ans += a[i];
            }

            return ans;
        }
    }

    public static int lowercaseToIndex(char c) {
        return (int) c - 97;
    }
}
