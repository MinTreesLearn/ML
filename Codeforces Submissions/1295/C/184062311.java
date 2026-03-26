import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int test = Integer.parseInt(r.readLine());
        for (int t = 0; t < test; t++) {
            char[] a = r.readLine().toCharArray();
            char[] b = r.readLine().toCharArray();
            if (!check(a, b)) {
                pw.println(-1);
                continue;
            }
            HashMap<Character, TreeSet<Integer>> loco = new HashMap<>();
            for (int i = 0; i < a.length; i++) {
                if (!loco.containsKey(a[i])) loco.put(a[i], new TreeSet<>());
                loco.get(a[i]).add(i);
            }
            int finalans = 0;
            int ai = -1;
            int bi = 0;
            while (bi < b.length) {
                if (ai < loco.get(b[bi]).last()) {//more substring to add
                    ai = loco.get(b[bi]).higher(ai);
                    bi++;
                }
                else {//we reached end of string a
                    finalans++;
                    ai = -1;
                }
                //pw.println(ai + " " + bi);
            }
            //pw.println(loco);
            pw.println(finalans+1);
        }
        r.close();
        pw.close();
    }
    static boolean check(char[] a, char[] b) {
        HashSet<Character> set = new HashSet<>();
        for (int i = 0; i < a.length; i++) set.add(a[i]);
        for (int i = 0; i < b.length; i++) if (!set.contains(b[i])) return false;
        return true;
    }
}