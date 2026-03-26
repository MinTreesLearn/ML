import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                if(st.hasMoreTokens()){
                    str = st.nextToken("\n");
                }
                else{
                    str = br.readLine();
                }
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    public static int ans (int[] arr)
    {
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            if(arr[i]==0)
            {
                ans++;
                arr[i] = arr[i] + 1;
            }
            sum+=arr[i];
        }
        if(sum==0)
        {
            return ans+1;
        }
        return ans;
    }
    public static void main(String[] args) throws IOException {
        FastReader s = new FastReader();
        int n = s.nextInt();
        StringBuilder answer = new StringBuilder();
        while (n-->0) {
            int len = s.nextInt();
            int[] arr = new int[len];
            for (int i = 0; i < len; i++) {
                arr[i] = s.nextInt();
            }
            answer.append(ans(arr)).append("\n");
        }
        System.out.println(answer);
    }
}