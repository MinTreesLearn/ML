import java.util.*;

public class C1304 {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int q = scn.nextInt();
        while (q-- > 0) {

            int n = scn.nextInt();
            int m = scn.nextInt();

            // maxmium and minimum that we can acheive in k minutes

            int mx = m;
            int mn = m;
            int ct = 0;

            boolean check = true;
            for (int i = 0; i < n; i++) {

                int k = scn.nextInt();

                int l = scn.nextInt();
                int r = scn.nextInt();

                int tl = k - ct;

                mx += tl;
                mn -= tl;

                if (l > mx || r < mn) {
                    check = false;
                }

                mx = Math.min(mx,r);
                mn = Math.max(mn,l);

                ct = k;

            }

            if(check){
                System.out.println("yes");
            }else{
                System.out.println("no");
            }
        }
    }
}
