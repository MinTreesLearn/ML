
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

public class PalindromeProb {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

        var st = new StringTokenizer(r.readLine());
        var t = Integer.parseInt(st.nextToken());
        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(r.readLine());
            var n = Integer.parseInt(st.nextToken());
            var list = new int[n];
            st = new StringTokenizer(r.readLine());
            for (int j = 0; j < n; j++) {
                list[j] = Integer.parseInt(st.nextToken());
            }
            var hashMap = new HashMap<Integer, Integer>();
            var check = false;
            for (int j = 0; j < list.length; j++) {
                var last = hashMap.get(list[j]);
                if (last != null) {
                    if (j - last > 1) {
                        System.out.println("YES");
                        check = true;
                        break;
                    }
                    continue;
                }
                hashMap.put(list[j], j);
            }
            if (!check) {
                System.out.println("NO");
            }
        }
    }
}
