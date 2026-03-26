import java.util.Scanner;

public class SuperheroBattle {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        long H = s.nextLong();
        int n = s.nextInt();
        int a[] = new int[n];
        long pre[] = new long[n];
        for(int i=0; i<n; i++){
            a[i] = s.nextInt();
        }
        pre[0] = a[0];
        for (int i = 1; i < n; ++i) pre[i] += a[i] + pre[i - 1];

        //initial check
        for (int i = 0; i < n; ++i) {
            if (pre[i] + H <= 0) {
                System.out.println(i + 1);
                return;
            }
        }
        if (pre[n - 1] >= 0) {
            System.out.println(-1);
            return;
        }

        //possible
        long ans = Long.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            long time = (-H - pre[i]) / pre[n - 1];
            //System.out.println("time: " + time);
            if (pre[n - 1] * time + pre[i] + H <= 0) {
                ans = Math.min(ans, time*n + (i + 1));
            } else if (pre[n - 1] * (time+1) + pre[i] + H <= 0) {
                ans = Math.min(ans, (time + 1) * n + (i + 1));
            }
        }
        System.out.println(ans);
    }
}
