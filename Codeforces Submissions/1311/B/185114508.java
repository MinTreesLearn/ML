import java.util.*;

public class CF {
    public static void main(String[] args) {
        Scanner cs = new Scanner(System.in);
        int t = cs.nextInt();
        while(t-- > 0) {
            int n = cs.nextInt();
            int m = cs.nextInt();

            int[] arr = new  int[n];
            for(int i=0;i<n;i++) {
                arr[i] = cs.nextInt();
            }

            boolean[] pr = new boolean[n];
            for(int i=0;i<m;i++) {
                int loc = cs.nextInt();
                pr[loc-1] = true;
            }


            for(int i=0;i<n;i++) {
                if(pr[i]) {
                    int loc = i;
                    for(i+=1;i<n;i++) {
                        if(!pr[i]) {
                            break;
                        }
                    }
                    Arrays.sort(arr, loc, i+1);
                }
            }

            int now = arr[0];
            int i=1;
            for(;i<n;i++) {
                if(now > arr[i]) {
                    break;
                }
                now = arr[i];
            }

            if(i == n) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}