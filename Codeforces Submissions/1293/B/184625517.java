import java.io.*;
import java.util.*;

public class JoeOnTV {
    public static void main(String[] args) throws IOException {
        FS msc = new FS(); // ADD FILEINPUT TO INFPUT FILE (OR NOTHING FOR MSC)

        int s = msc.nextInt();

        double answer = 0.0;

        for(int i = 1; i < s + 1; i++){
            answer += 1.0/(double)i;
        }

        System.out.println(answer);
    }
    static class FS {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        FS() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        FS(String file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() { // SEPERATES BY SPACES
            while (!st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
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
    }
}
