

import java.util.*;
import java.io.*;

public class YetAnotherTetrisProblem {
    public static void main(String[] args){
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            boolean par = true;
            boolean res = true;
            for (int i = 0; i < n; i++){
                int a = sc.nextInt();
                if(i == 0 && a % 2 == 0) par = true;
                else if(i == 0 && a % 2 == 1) par = false;
                if(par && i != 0){
                    if(a % 2 == 1) res = false;
                }
                else if(!par && i != 0){
                    if(a % 2 == 0) res = false;
                }
            }            
            System.out.println(res ? "YES":"NO");
        }
    }

    static class Maths {
        public static int gcd(int a, int b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        public static int lcm(int a, int b) {
            return a * b / gcd(a, b);
        }
    }

    static class NextPermutation {

        // Function to swap the data
        // present in the left and right indices
        public static int[] swap(int data[], int left, int right)
        {

            // Swap the data
            int temp = data[left];
            data[left] = data[right];
            data[right] = temp;

            // Return the updated array
            return data;
        }

        // Function to reverse the sub-array
        // starting from left to the right
        // both inclusive
        public static int[] reverse(int data[], int left, int right)
        {

            // Reverse the sub-array
            while (left < right) {
                int temp = data[left];
                data[left++] = data[right];
                data[right--] = temp;
            }

            // Return the updated array
            return data;
        }

        // Function to find the next permutation
        // of the given integer array
        public static boolean findNextPermutation(int data[])
        {

            // If the given dataset is empty
            // or contains only one element
            // next_permutation is not possible
            if (data.length <= 1)
                return false;

            int last = data.length - 2;

            // find the longest non-increasing suffix
            // and find the pivot
            while (last >= 0) {
                if (data[last] < data[last + 1]) {
                    break;
                }
                last--;
            }

            // If there is no increasing pair
            // there is no higher order permutation
            if (last < 0)
                return false;

            int nextGreater = data.length - 1;

            // Find the rightmost successor to the pivot
            for (int i = data.length - 1; i > last; i--) {
                if (data[i] > data[last]) {
                    nextGreater = i;
                    break;
                }
            }

            // Swap the successor and the pivot
            data = swap(data, nextGreater, last);

            // Reverse the suffix
            data = reverse(data, last + 1, data.length - 1);

            // Return true as the next_permutation is done
            return true;
        }
    }
    static class UnionFind { // OOP style
        private ArrayList<Integer> p, rank, setSize;
        private int numSets;

        public UnionFind(int N) {
            p = new ArrayList<Integer>(N);
            rank = new ArrayList<Integer>(N);
            setSize = new ArrayList<Integer>(N);
            numSets = N;
            for (int i = 0; i < N; i++) {
                p.add(i);
                rank.add(0);
                setSize.add(1);
            }
        }

        public int findSet(int i) {
            if (p.get(i) == i)
                return i;
            else {
                int ret = findSet(p.get(i));
                p.set(i, ret);
                return ret;
            }
        }

        public Boolean isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        public void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                numSets--;
                int x = findSet(i), y = findSet(j);
                // rank is used to keep the tree short
                if (rank.get(x) > rank.get(y)) {
                    p.set(y, x);
                    setSize.set(x, setSize.get(x) + setSize.get(y));
                } else {
                    p.set(x, y);
                    setSize.set(y, setSize.get(y) + setSize.get(x));
                    if (rank.get(x) == rank.get(y))
                        rank.set(y, rank.get(y) + 1);
                }
            }
        }

        public int numDisjointSets() {
            return numSets;
        }

        public int sizeOfSet(int i) {
            return setSize.get(findSet(i));
        }
    }

    static class Pair<A, B> {
        A first;
        B second;

        // Constructor
        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }

    static class FastReader {
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

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

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

        boolean hasNext() {
            if (st != null && st.hasMoreTokens()) {
                return true;
            }
            String tmp;
            try {
                br.mark(1000);
                tmp = br.readLine();
                if (tmp == null) {
                    return false;
                }
                br.reset();
            } catch (IOException e) {
                return false;
            }
            return true;
        }
    }
}
