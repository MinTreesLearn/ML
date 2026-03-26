
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class ConneR_ARCMarklandN {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

        var st = new StringTokenizer(r.readLine());
        var t = Integer.parseInt(st.nextToken());
        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(r.readLine());
            var n = Integer.parseInt(st.nextToken());
            var s = Integer.parseInt(st.nextToken());
            var k = Integer.parseInt(st.nextToken());
            var hashSet = new HashSet<Integer>();
            st = new StringTokenizer(r.readLine());
            for (int j = 0; j < k; j++) {
                hashSet.add(Integer.parseInt(st.nextToken()));
            }

            var minRight = -1;
            for (int j = s; j <= n; j++) {
                if (hashSet.add(j)) {
                    minRight = j-s;
                    break;
                }
            }
            var minLeft = -1;
            for (int j = s; j >0; j--) {
                if (hashSet.add(j)) {
                    minLeft = s-j;
                    break;
                }
            }
            if (minRight==-1) {
                System.out.println(minLeft);
            }
            else if(minLeft==-1) {
                System.out.println(minRight);
            }
            else {
                System.out.println(Math.min(minRight,minLeft));
            }
        }
    }
}