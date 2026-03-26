import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;

public class PerfectKeyboard {
    static BufferedReader br;
    static PrintWriter pw;
    static HashSet<Character>[] adj = new HashSet[26];

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) test();
    }

    static void test() throws Exception {
        boolean[] visited = new boolean[26];
        String str = br.readLine();
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new HashSet<>();
        }
        for (int i = 0; i < str.length(); i++) {
            int c = str.charAt(i) - 'a';
            if (i > 0) adj[c].add(str.charAt(i - 1));
            if (i < str.length() - 1) adj[c].add(str.charAt(i + 1));
            if (adj[c].size() > 2) {
                System.out.println("NO");
                return;
            }
        }
        for (int i = 0; i < 26; i++) {
            char c = (char) (i + 97);
            if (!visited[i]) {
                boolean cycle = checkCycle(c, c, visited);
                if (cycle) {
                    System.out.println("NO");
                    return;
                }
            }
        }
        System.out.println("YES");
        var index = 0;
        for (int i = 0; i < 26; i++) {
            if (adj[i].size() == 1) {
                index = i;
                break;
            }
        }
        char c = (char) (index + 97);
        StringBuilder sb = getKeyboard(c, c, new StringBuilder(c + ""));
        HashSet<Character> set = new HashSet<>();
        for (int i = 0; i < 26; i++)
            set.add((char) (i + 97));
        for (int i = 0; i < sb.length(); i++)
            set.remove(sb.charAt(i));
        for (char s : set) sb.append(s);

        System.out.println(sb);
    }

    static StringBuilder getKeyboard(char curr, char prev, StringBuilder sb) {
        for (var a : adj[curr - 'a']) {
            if (a != prev) {
                sb.append(a);
                getKeyboard(a, curr, sb);
            }
        }
        return sb;
    }

    static boolean checkCycle(char c, char prev, boolean[] visited) {
        if (visited[c - 'a']) return false;
        visited[c - 'a'] = true;
        for (char a : adj[c - 'a']) {
            int v = a - 'a';
            if (visited[v]) {
                if (a != prev) return true;
            } else {
                if (checkCycle(a, c, visited)) return true;
            }
        }
        return false;
    }
}