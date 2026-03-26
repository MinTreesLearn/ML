import java.util.*;
public class JavaApplication38 {
    public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T, a, b, c;
        T = in.nextInt();
        for (int t = 0; t < T; t++) {
            a = in.nextInt();
            b = in.nextInt();
            c = in.nextInt();
            int x[] = {a, b, c};
            Arrays.sort(x);
            int ans = 0;
            for (int i = 0; i < 3; i++) {
                if (x[i] > 0) {
                    ans++;
                    x[i]--;
                }
            }
            if (x[0] > 0 && x[2] > 0) {
                ans++;
                x[0]--;
                x[2]--;
            }
            if (x[1] > 0 && x[2] > 0) {
                ans++;
                x[1]--;
                x[2]--;
            }
            if (x[0] > 0 && x[1] > 0) {
                ans++;
                x[0]--;
                x[1]--;
            }
            if (x[0] > 0 && x[1] > 0 && x[2] > 0) {
                ans++;
            }
            System.out.println(ans);
        }
    }
}
	     	 			  	 		    						 	