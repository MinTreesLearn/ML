import java.io.*;
import java.util.*;

public class Main {
    static class pair {
        int x, y;
        pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        pair[] a = new pair[n];
        for(int i = 0; i < n; ++i)
            a[i] = new pair(in.nextInt(), in.nextInt());
        if(n % 2 == 1) {
            System.out.println("NO");
            return;
        }
        TreeSet<pair> st = new TreeSet<>(new Comparator<pair>() {
            @Override public int compare(pair a, pair b) {
                if(a.x != b.x)
                    return a.x - b.x;
                return a.y - b.y;
            }
        });
        for(int i = 0; i < n / 2; ++i) 
            st.add(new pair(a[i].x + a[i + n / 2].x, a[i].y + a[i + n / 2].y));
        System.out.println(st.size() == 1 ? "YES" : "NO");
    }
}