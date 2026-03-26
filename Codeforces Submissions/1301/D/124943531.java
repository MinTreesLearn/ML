import java.io.*;
import java.util.*;

public class Main {
    static class data {
        int x;
        StringBuilder s = new StringBuilder();
        data(int x, String s) {
            this.x = x;
            this.s.append(s);
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        if(k > 4 * m * n - 2 * n - 2 * m) {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
        ArrayList<data> s = new ArrayList<>();
        ArrayList<data> ans = new ArrayList<>();
        if(m > 1) {
            s.add(new data(m - 1, "R"));
            s.add(new data(m - 1, "L"));
        }
        for(int i = 2; i <= n; ++i) {
            s.add(new data(1, "D"));
            if(m > 1) {
                s.add(new data(m - 1, "R"));
                s.add(new data(m - 1, "UDL"));
            }
        }
        if(n > 1) 
            s.add(new data(n - 1, "U"));
        for(int i = 0; k > 0; ++i) {
            int cnt = s.get(i).x;
            String ss = s.get(i).s.toString();
            int y = ss.length();
            if(y * cnt <= k) {
                ans.add(new data(cnt, ss));
                k -= cnt * y;
            }
            else {
                int take = k / y;
                k -= take * y;
                if(take > 0)
                    ans.add(new data(take, ss));
                if(k > 0) 
                    ans.add(new data(1, ss.substring(0, k)));
                k = 0;
            }
        }
        int y = ans.size();
        System.out.println(y);
        for(int i = 0; i < y; ++i)
            System.out.println(ans.get(i).x + " " + ans.get(i).s.toString());
    }
}