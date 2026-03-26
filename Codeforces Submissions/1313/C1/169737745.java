// package CP;

import java.util.*;
import java.io.*;

public class Main {
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
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) throws java.lang.Exception {
        FastReader sc = new FastReader();
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = 1;
        // t = sc.nextInt();
        while (t-- != 0) {
            int n = sc.nextInt();
            int m[] = new int[n];
            int lr_nextSmaller[] = new int[n];
            int rl_nextSmaller[] = new int[n];
            for (int i = 0; i < n; i++) {
                m[i] = sc.nextInt();
            }
            Stack<Integer> st = new Stack<>();
            for (int i = n - 1; i >= 0; i--) {
                while (!st.isEmpty() && m[i] <= m[st.peek()]) {
                    st.pop();
                }
                if (st.isEmpty()) {
                    lr_nextSmaller[i] = -1;
                } else {
                    lr_nextSmaller[i] = st.peek();
                }
                st.push(i);
            }
            st.clear();
            for (int i = 0; i < n; i++) {
                while (!st.isEmpty() && m[i] <= m[st.peek()]) {
                    st.pop();
                }
                if (st.isEmpty()) {
                    rl_nextSmaller[i] = -1;
                } else {
                    rl_nextSmaller[i] = st.peek();
                }
                st.push(i);
            }

            long leftdp[] = new long[n];
            leftdp[0] = m[0];
            for (int i = 1; i < n; i++) {
                if (m[i - 1] <= m[i]) {
                    leftdp[i] = leftdp[i - 1] + m[i];
                } else {
                    int nextSmaller = rl_nextSmaller[i];
                    if (nextSmaller == -1) {
                        leftdp[i] = m[i] * (i * 1L - (-1L));
                    } else {
                        leftdp[i] = leftdp[nextSmaller] + m[i] * (i * 1L - nextSmaller);
                    }
                }
            }

            long rightdp[] = new long[n];
            rightdp[n - 1] = m[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                if (m[i + 1] <= m[i]) {
                    rightdp[i] = rightdp[i + 1] + m[i];
                } else {
                    int nextSmaller = lr_nextSmaller[i];
                    if (nextSmaller == -1) {
                        rightdp[i] = m[i] * (n * 1L - i * 1L);
                    } else {
                        rightdp[i] = rightdp[nextSmaller] + m[i] * (nextSmaller - i * 1L);
                    }
                }
            }

            int max = 0;
            for (int i = 0; i < n; i++) {
                if ((leftdp[max] + rightdp[max] - m[max]) < (leftdp[i] + rightdp[i] - m[i])) {
                    max = i;
                }
            }
            for (int i = max + 1; i < n; i++) {
                m[i] = Math.min(m[i - 1], m[i]);
            }
            for (int i = max - 1; i >= 0; i--) {
                m[i] = Math.min(m[i + 1], m[i]);
            }

            for (int i = 0; i < n; i++) {
                w.write(m[i] + "\n");
            }

        }
        w.flush();
        w.close();
    }

}