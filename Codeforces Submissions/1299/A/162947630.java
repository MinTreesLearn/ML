import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1299A {

    public static void main(String[] args) {

        FastScanner s = new FastScanner();
        int n = s.nextInt();
        int[] arr = s.readArray(n);
        for (int i = 31; i >= 0; i--) {
            int count = 0;
            for (int j : arr) {
                if ((j & (1 << i)) > 0) {
                    count++;
                }
            }
            if (count == 1) {
                for (int j = 0; j < n; j++) {
                    if ((arr[j] & (1 << i)) > 0) {
                        int temp = arr[j];
                        arr[j] = arr[0];
                        arr[0] = temp;
                    }
                }
                break;
            }
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            ans.append(arr[i]);
            if (i != n - 1) {
                ans.append(" ");
            }
        }
        System.out.println(ans);

    }

    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }

}
