import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        outer: while(t-- > 0) {
            long n = in.nextLong(), sum = 0;
            int m = in.nextInt(), ans = 0;
            TreeMap<Integer, Integer> mp = new TreeMap<>();
            for(int i = 0; i < m; ++i) {
                int x = in.nextInt();
                sum += x;
                int key = 31 - Integer.numberOfLeadingZeros(x);
                Integer cnt = mp.get(key);
                if(cnt == null)
                    mp.put(key, 1);
                else
                    mp.put(key, cnt + 1);
            }
            if(sum < n) {
                System.out.println(-1);
                continue outer;
            }
            for(int i = 0; i < 60; ++i) {
                if((n >> i & 1) != 0) {
                    Integer cnt = mp.get(i);
                    if(cnt != null && cnt > 0)
                        mp.put(i, cnt - 1);
                    else {
                        Integer key = mp.higherKey(i);
                        cnt = mp.get(key);
                        mp.put(key, cnt - 1);
                        Integer low = mp.get(key - 1);
                        if(low == null)
                            mp.put(key - 1, 2);
                        else
                            mp.put(key - 1, low + 2);
                        ++ans;
                        --i;
                        continue;
                    }
                }
                Integer cnt = mp.get(i);
                if(cnt != null && cnt > 1) {
                    Integer high = mp.get(i + 1);
                    if(high == null)
                        mp.put(i + 1, cnt / 2);
                    else
                        mp.put(i + 1, high + cnt / 2);
                }
            }
            System.out.println(ans);
        }
    }
}