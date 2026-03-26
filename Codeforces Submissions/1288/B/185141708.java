
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class MemeProb {

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

        var st = new StringTokenizer(r.readLine());
        var t = Integer.parseInt(st.nextToken());
        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(r.readLine());
            var first = Integer.parseInt(st.nextToken());
            var str = st.nextToken();
            var len = 0L;
            for (char j : str.toCharArray()) {
                if (j=='9') {
                    len++;
                }
            }
            if(len!=str.length()) {
                len= str.length()-1;
            }
            System.out.println(first*len);
        }
    }
}