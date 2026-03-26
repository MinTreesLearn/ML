import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        //BufferedReader f = new BufferedReader(new FileReader("uva.in"));
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = Integer.parseInt(f.readLine());
        char[] s = f.readLine().toCharArray();
        ArrayList<Stack<Integer>> occ = new ArrayList<>(26);
        for(int i = 0; i < 26; i++) {
            occ.add(new Stack<>());
        }
        int[] res = new int[n];
        int cur = 1;
        for(int i = 0; i < n; i++) {
            boolean flag = false;
            for(int j = s[i]-'a'; j >= 0; j--) {
                if(!occ.get(j).isEmpty()) {
                    flag = true;
                    occ.get(s[i]-'a').push(occ.get(j).pop());
                    break;
                }
            }
            if(!flag) {
                occ.get(s[i]-'a').push(cur++);
            }
            res[i] = occ.get(s[i]-'a').peek();
        }
        out.println(cur-1);
        out.print(res[0]);
        for(int i = 1; i < n; i++) {
            out.print(" " + res[i]);
        }
        out.println();
        f.close();
        out.close();
    }
}
