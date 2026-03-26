import java.io.*;
import java.util.*;
public class cf {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(r.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] stor = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(r.readLine());
            for (int j = 0; j < m; j++) {
                stor[i][j] = Integer.parseInt(st.nextToken())-1;
            }
        }
        //for (int[] i: stor) pw.println(Arrays.toString(i));
        int ans = 0;
        for (int j = 0; j < m; j++) {//j stands for column :)
            HashMap<Integer, Integer> place = new HashMap<>(n);
            for (int i = 0; i < n; i++) {
                if (stor[i][j]%m == j&& stor[i][j] < n*m) {//check if element belongs in column
                    int val = ((i - stor[i][j]/m)%n+n)%n;
                    add(place, val);
                }
            }
            int min = n;
            for (int i: place.keySet()) {
                min = Math.min(min, n-place.get(i)+i);
            }
            ans += min;
            //System.out.println(place);
            //System.out.println(min);
        }
        pw.println(ans);
        pw.close();
    }
    static void add(Map<Integer, Integer> map, int val) {
        if (!map.containsKey(val)) map.put(val, 1);
        else map.put(val, map.get(val)+1);
    }
}