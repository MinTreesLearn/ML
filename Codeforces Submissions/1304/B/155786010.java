
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static List<String> list = new ArrayList<>();
    static HashSet<String> set = new HashSet<>();
    static HashSet<String> hw = new HashSet<>();

    public static void main(String[] args) {
        InputReader s = new InputReader();
        int n = s.nextInt();
        int k = s.nextInt();
        StringBuilder l = new StringBuilder();
        while (n-- > 0) {
            String str = s.next();
            StringBuilder sb = new StringBuilder(str);
            if (sb.toString().equals(sb.reverse().toString())) hw.add(str);
            list.add(str);
            set.add(str);
        }
        int cnt = 0;
        for (int i = 0; i < list.size(); i++) {
            String cur = list.get(i);
            int len = cur.length();
            StringBuilder sb = new StringBuilder(cur);
            if (!hw.contains(cur) && set.contains(sb.reverse().toString())) {
                cnt += 2*len;
                l.append(cur);
                set.remove(cur);
                set.remove(sb.reverse().toString());
                hw.remove(cur);
            }
        }
        int len = 0;
        String bh = "";
        for (String x : hw) {
            int nlen = x.length();
            if (nlen > len) bh = x;
        }
        cnt+=bh.length();
        String r = l.toString();
        l.reverse().append(bh).append(r);
        System.out.println(cnt);
        System.out.println(l.toString());
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;


    public InputReader() {
        reader = new BufferedReader(new InputStreamReader(System.in), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}