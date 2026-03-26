import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {
    static Reader input = new Reader();
    public static void main(String[] args) throws IOException {
        int n = input.nextInt();
        char[] s = input.next().toCharArray();
        int[] color = new int[n];
        int[] answer = new int[n];
        for(int i = 1; i < n; ++i) {
            if(s[i] < s[i-1]) {
                color[i] = (color[i-1]+1)%2;
                answer[i] = (color[i-1]+1)%2;
            }
            int pointer = i-1;
            while(pointer > -1) {
                if(s[pointer] <= s[pointer+1]) break;
                if(color[pointer] != color[pointer+1]) {
                    int temp = color[pointer];
                    color[pointer] = color[pointer+1];
                    color[pointer+1] = temp;
                    char t = s[pointer];
                    s[pointer] = s[pointer+1];
                    s[pointer+1] = t;
                } else {
                    System.out.println("NO");
                    return;
                }
                --pointer;
            }
        }
        System.out.println("YES");
        for(int i = 0; i < n; ++i) {
            System.out.print(answer[i]);
        }
    }
    static class Reader {
        BufferedReader reader;
        StringTokenizer string;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }
        public String next() throws IOException {
            while(string == null || ! string.hasMoreElements()) {
                string = new StringTokenizer(reader.readLine());
            }
            return string.nextToken();
        }
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}