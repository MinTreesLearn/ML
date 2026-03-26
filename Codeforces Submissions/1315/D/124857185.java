import java.io.*;
import java.util.*;

public class Main {
    static class pair {
        int x, y;
        public pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] aa = new int[n];
        ArrayList<pair> list = new ArrayList<>();
        for(int i = 0; i < n; ++i)
            aa[i] = in.nextInt();
        for(int i = 0; i < n; ++i)
            list.add(new pair(aa[i], in.nextInt()));
        Collections.sort(list, new Comparator<pair>() {
            @Override public int compare(pair a, pair b) {
                return a.x - b.x;
            }
        });
        pair[] a = new pair[n];
        for(int i = 0; i < n; ++i)
            a[i] = list.get(i);
        int pos = 0, num = a[0].x;
        long sum = 0, ans = 0;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        while(pos < n || !mp.isEmpty()) {
            if(mp.isEmpty() || (pos < n && a[pos].x == num)) {
                int j;
                for(j = pos; j < n && a[j].x == a[pos].x; ++j) {
                    sum += a[j].y;
                    Integer cnt = mp.get(a[j].y);
                    if(cnt == null)
                        mp.put(a[j].y, 1);
                    else
                        mp.put(a[j].y, cnt + 1);
                }
                num = a[pos].x;
                pos = j;
            }
            int key = mp.lastKey(), cnt = mp.get(key);
            sum -= key;
            ans += sum;
            ++num;
            if(cnt > 1)
                mp.put(key, cnt - 1);
            else
                mp.remove(key);
        }
        System.out.println(ans);
    }
}