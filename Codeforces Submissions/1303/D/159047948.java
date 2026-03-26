import java.util.*;

public class Hello {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            long N = sc.nextLong();
            int M = sc.nextInt();
            int freq[] = new int[65];
            long sum = 0;
            for (int index = 0; index < M; index++) {
                int val = sc.nextInt();
                for (int ctr = 0; ctr < 64; ctr++) {
                    if ((val & (1L << ctr)) != 0L) {
                        freq[ctr]++;
                        break;
                    }
                }
                sum += val;
            }
            if (N > sum) {
                System.out.println("-1");
                continue;
            }

            int count = 0;
            for (int ctr = 0; ctr < 64; ctr++) {
                if ((N & (1L << ctr)) == 0L) {
                    freq[ctr + 1] += freq[ctr] / 2;
                    continue;
                }
                for (int val = ctr; val < 64; val++) {
                    if (freq[val] != 0) {
                        freq[val]--;
                        break;
                    }
                    freq[val]++;
                    count++;
                }
                freq[ctr + 1] += freq[ctr] / 2;
            }

            System.out.println(count);
        }
    }
}