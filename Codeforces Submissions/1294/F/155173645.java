import javax.lang.model.type.ArrayType;
import javax.swing.text.Segment;
import javax.xml.stream.events.ProcessingInstruction;
import java.math.BigInteger;
import java.sql.Array;
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.toList;

public class Solution
{
    private static class FastIO {
        private static class FastReader
        {
            BufferedReader br;
            StringTokenizer st;

            FastReader()
            {
                br = new BufferedReader(new InputStreamReader(System.in));
            }

            String next()
            {
                while (st == null || !st.hasMoreElements())
                {
                    try
                    {
                        st = new StringTokenizer(br.readLine());
                    }
                    catch (IOException e)
                    {
                        e.printStackTrace();
                    }
                }
                return st.nextToken();
            }
            int nextInt() { return Integer.parseInt(next()); }
            long nextLong() { return Long.parseLong(next()); }
            double nextDouble() { return Double.parseDouble(next()); }
            String nextLine()
            {
                String str = "";
                try
                {
                    str = br.readLine();
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
                return str;
            }
        }

        private static PrintWriter out = new PrintWriter(System.out);
        private static FastReader in = new FastReader();

        public void print(String s) {out.print(s);}

        public void println(String s) {out.println(s);}

        public void println() {
            println("");
        }

        public void print(int i) {out.print(i);}
        public void print(long i) {out.print(i);}
        public void print(char i) {out.print(i);}
        public void print(double i) {out.print(i);}

        public void println(int i) {out.println(i);}
        public void println(long i) {out.println(i);}
        public void println(char i) {out.println(i);}
        public void println(double i) {out.println(i);}

        public void printIntArrayWithoutSpaces(int[] a) {
            for(int i : a) {
                out.print(i);
            }
            out.println();
        }
        public void printIntArrayWithSpaces(int[] a) {
            for(int i : a) {
                out.print(i + " ");
            }
            out.println();
        }

        public void printIntArrayNewLine(int[] a) {
            for(int i : a) {
                out.println(i);
            }
        }

        public int[] getIntArray(int n) {
            int[] res = new int[n];
            for(int i = 0; i < n; i++) {
                res[i] = in.nextInt();
            }
            return res;
        }
        public List<Integer> getIntList(int n) {
            List<Integer> list = new ArrayList<>();
            for(int i = 0; i < n; i++) {
                list.add(in.nextInt());
            }
            return list;
        }

        public static void printKickstartCase(int i) {
            out.print("Case #" + i + ": ");
        }

        public String next() {return in.next();}
        int nextInt() { return in.nextInt(); }
        char nextChar() {return in.next().charAt(0);}
        long nextLong() { return in.nextLong(); }
        double nextDouble() { return in.nextDouble(); }
        String nextLine() {return in.nextLine();}

        public void close() {
            out.flush();
            out.close();
        }
    }
    private static final FastIO io = new FastIO();

    private static class MathUtil {

        public static final int MOD = 1000000007;

        public static int gcd(int a, int b) {
            if(b == 0) {
                return a;
            }
            return gcd(b, a % b);
        }

        public static int gcd(int[] a) {
            if(a.length == 0) {
                return 0;
            }
            int res = a[0];
            for(int i = 1; i < a.length; i++) {
                res = gcd(res, a[i]);
            }
            return res;
        }

        public static int gcd(List<Integer> a) {
            if(a.size() == 0) {
                return 0;
            }
            int res = a.get(0);
            for(int i = 1; i < a.size(); i++) {
                res = gcd(res, a.get(i));
            }
            return res;
        }

        public static int modular_mult(int a, int b, int M) {
            long res = (long)a * b;
            return (int)(res % M);
        }
        public static int modular_mult(int a, int b) {
            return modular_mult(a, b, MOD);
        }

        public static int modular_add(int a, int b, int M) {
            long res = (long)a + b;
            return (int)(res % M);
        }
        public static int modular_add(int a, int b) {
            return modular_add(a, b, MOD);
        }

        public static int modular_sub(int a, int b, int M) {
            long res = ((long)a - b) + M;
            return (int)(res % M);
        }
        public static int modular_sub(int a, int b) {
            return modular_sub(a, b, MOD);
        }

        //public static int modular_div(int a, int b, int M) {}
        //public static int modular_div(int a, int b) {return modular_div(a, b, MOD);}

        public static int pow(int a, int b, int M) {
            int res = 1;
            while (b > 0) {
                if ((b & 1) == 1) {
                    res = modular_mult(res, a, M);
                }
                a = modular_mult(a, a, M);
                b = b >> 1;
            }
            return res;
        }

        public static int pow(int a, int b) {
            return pow(a, b, MOD);
        }

        /*public static int fact(int i, int M) {

        }

        public static int fact(int i) {

        }

        public static void preComputeFact(int i) {

        }

        public static int mod_mult_inverse(int den, int mod) {

        }

        public static void C(int n, int r) {

        }*/

    }
    private static class ArrayUtil {

        @FunctionalInterface
        private static interface NumberPairComparator {
            boolean test(int a, int b);
        }

        public static int[] nextGreaterOrSmallerRight(int[] a, NumberPairComparator npc) {
            int n = a.length;
            int[] res = new int[n];
            Stack<Integer> stack = new Stack<>();
            for(int i = 0; i < n; i++) {
                int cur = a[i];
                while(!stack.isEmpty() && npc.test(a[stack.peek()], cur)) {
                    res[stack.pop()] = i;
                }
                stack.push(i);
            }
            while(!stack.isEmpty()) {
                res[stack.pop()] = n;
            }
            return res;
        }

        public static int[] nextGreaterOrSmallerLeft(int[] a, NumberPairComparator npc) {
            int n = a.length;
            int[] res = new int[n];
            Stack<Integer> stack = new Stack<>();
            for(int i = n - 1; i >= 0; i--) {
                int cur = a[i];
                while(!stack.isEmpty() && npc.test(a[stack.peek()], cur)) {
                    res[stack.pop()] = i;
                }
                stack.push(i);
            }
            while(!stack.isEmpty()) {
                res[stack.pop()] = n;
            }
            return res;
        }


        public static Map<Integer, Integer> getFreqMap(int[] a) {
            Map<Integer, Integer> map = new HashMap<>();
            for(int i : a) {
                map.put(i, map.getOrDefault(i, 0) + 1);
            }
            return map;
        }

        public static long arraySum(int[] a) {
            long sum = 0;
            for(int i : a) {
                sum += i;
            }
            return sum;
        }

        private static int maxIndex(int[] a) {
            int max = Integer.MIN_VALUE;
            int max_index = -1;
            for(int i = 0; i < a.length; i++) {
                if(a[i] > max) {
                    max = a[i];
                    max_index = i;
                }
            }
            return max_index;
        }
    }

    private static final int M = 1000000007;
    private static final String yes = "YES";
    private static final String no = "NO";
    private static int MAX = M / 100;
    private static final int MIN = -MAX;

    private static final int UNVISITED = -1;

    private static class Tree {
        List<List<Integer>> list;
        int n;
        Tree(int n) {
            this.n = n;
            list = new ArrayList<>();
            for(int i = 0; i < n; i++) {
                list.add(new ArrayList<>());
            }
        }

        public void addUndirectedEdge(int a, int b) {
            list.get(a).add(b);
            list.get(b).add(a);
        }

        public boolean isLeaf(int i) {
            return (i != 0 && getNeighbours(i).size() == 1);
        }

        public List<Integer> getNeighbours(int i) {
            return list.get(i);
        }

        public void sortAdjList(Comparator<Integer> comp) {
            for(List<Integer> sublist : list) {
                Collections.sort(sublist, comp);
            }
        }

        public int[] bfs(int source) {
            int[] res = new int[n];
            ArrayDeque<Integer> q = new ArrayDeque<>();
            ArrayDeque<Integer> q_parent = new ArrayDeque<>();

            q.add(source);
            q_parent.add(-1);

            int level = 0;
            while(!q.isEmpty()) {
                int q_size = q.size();
                for(int i = 0; i < q_size; i++) {
                    int cur = q.poll();
                    int parent = q_parent.poll();
                    res[cur] = level;
                    List<Integer> neighbours = getNeighbours(cur);
                    for(int neighbour : neighbours) {
                        if(neighbour == parent) {
                            continue;
                        }
                        q.add(neighbour);
                        q_parent.add(cur);
                    }
                }
                level ++;
            }
            return res;
        }

        @FunctionalInterface
        private interface DfsAction<T> {
            void perform(int parent, int child, List<T> values);
        }

        private <T> void dfs(int node, int parent, DfsAction<T> preOrderAction, DfsAction<T> postOrderAction, DfsAction<T> rootAction, DfsAction<T> leafAction, DfsAction<T> leaveAction,List<T> values) {
            if(node == 0) {
                rootAction.perform(parent, node, values);
            }
            if(isLeaf(node)) {
                leafAction.perform(parent, node, values);
            }
            preOrderAction.perform(parent, node, values);
            List<Integer> children = getNeighbours(node);
            for(int child : children) {
                if(child == parent) {
                    continue;
                }
                dfs(child, node, preOrderAction, postOrderAction, leafAction, rootAction, leaveAction, values);
                postOrderAction.perform(node, child, values);
            }

            leaveAction.perform(parent, node, values);
        }

        public <T> void dfs(int root, DfsAction<T> preOrderAction, DfsAction<T> postOrderAction, DfsAction<T> rootAction, DfsAction<T> leafAction, DfsAction<T> leaveAction, List<T> values) {
            dfs(0, -1, preOrderAction, postOrderAction, rootAction, leafAction, leaveAction, values);
        }

        public <T> void postOrder(int root, DfsAction<T> postOrderAction, DfsAction<T> leafAction, List<T>values) {
            this.<T>dfs(root, (p, c, v) -> {}, postOrderAction, (p, c, v) -> {}, leafAction, (p, c, v) -> {}, values);
        }

    }

    private static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "x: " + x + " y: " + y;
        }
    }

    private static class SearchNode {
        String num;
        int mod;
        int sum_of_digits;

        public SearchNode(String num, int mod, int sum_of_digits) {
            this.num = num;
            this.mod = mod;
            this.sum_of_digits = sum_of_digits;
        }
    }

    private static int binsearch(int x, long left_items, long left_sum, int cost) {
        int lo = 0;
        int hi = 1000000000;
        int res = 0;
        while(lo <= hi) {
            int d = lo + (hi - lo) / 2;
            long balance = x - (left_items * (d - 1)) - (left_sum) - cost - d + 1;
            if(balance >= 0) {
                res = d;
                lo = d + 1;
            }
            else {
                hi = d - 1;
            }
        }
        return res;
    }

    public static void main(String[] args)
    {
        //int t = io.nextInt();
        int t = 1;
        for(int zqt = 0; zqt < t; zqt ++) {
            int n = io.nextInt();
            Tree tree = new Tree(n);
            for(int i = 0; i < n - 1; i++) {
                tree.addUndirectedEdge(io.nextInt() - 1, io.nextInt() - 1);
            }
            int first_end_point = ArrayUtil.maxIndex(tree.bfs(0));
            int[] dist_1 = tree.bfs(first_end_point);
            int second_end_point = ArrayUtil.maxIndex(dist_1);
            int[] dist_2 = tree.bfs(second_end_point);
            int third_end_point = first_end_point;
            int diameter = dist_1[second_end_point];
            int res = diameter;
            if(diameter == n - 1) {
                if(first_end_point != 0 && second_end_point != 0) {
                    third_end_point = 0;
                }
                else if(first_end_point != 1 && second_end_point != 1) {
                    third_end_point = 1;
                }
                else {
                    third_end_point = 2;
                }

                io.println(res);
                io.println((first_end_point + 1) + " " + (second_end_point + 1) + " " + (third_end_point + 1));
                continue;
            }


            for(int i = 0; i < n; i++) {
                int d_plus_two_c = dist_1[i] + dist_2[i];
                int two_c = d_plus_two_c - diameter;
                int c = two_c / 2;
                int local_res = diameter + c;
                if (local_res >= res) {
                    res = local_res;
                    third_end_point = i;
                }
            }
            io.println(res);
            io.println((first_end_point + 1) + " " + (second_end_point + 1) + " " + (third_end_point + 1));
        }

        io.close();
    }

}