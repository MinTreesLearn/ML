
import java.util.*;
 
public class AnuHasAFunction {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int l = s.nextInt();
        int[] arr = new int[l];
        int[] cnt = new int[32];
        int[] idx = new int[32];
        for (int i = 0; i < l; i++) {
            arr[i] = s.nextInt();
            for (int j = 0; j < 32; j++) {
                if ((arr[i] & (1 << j)) > 0 ) {
                    cnt[j]++;
                    idx[j] = i;
                }
            }
        }
 
        for (int i = 31; i >= 0; i--) {
            if (cnt[i] == 1) {
                int swap = arr[0];
                arr[0] = arr[idx[i]];
                arr[idx[i]] = swap;
                break;
            }
        }
 
        StringBuilder sb = new StringBuilder();
        for (int i: arr)
            sb.append(Integer.toString(i) + " ");
        System.out.println(sb.toString());
    }
}