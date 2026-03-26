import java.io.*;
import java.util.*;

public class B {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        //int tst = Integer.parseInt(br.readLine());
        int tst = 1;
        while(tst-->0){
            String[] str = br.readLine().split(" ");
            long x0 = Long.parseLong(str[0]), y0 = Long.parseLong(str[1]);
            long ax = Long.parseLong(str[2]), ay = Long.parseLong(str[3]);
            long bx = Long.parseLong(str[4]), by = Long.parseLong(str[5]);
            String[] s = br.readLine().split(" ");
            long xs = Long.parseLong(s[0]), ys = Long.parseLong(s[1]), t = Long.parseLong(s[2]);
            long[] x = new long[65];
            long[] y = new long[65];
            long lim = ((long)1<<56)-1;
            int n = 1;
            x[0] = x0;
            y[0] = y0;
            int bonus = (xs == x0 && ys == y0)?1:0;
            while((lim-bx)/ax>=x[n-1] && (lim-by)/ay>=y[n-1]){
                x[n] = ax*x[n-1] + bx;
                y[n] = ay*y[n-1] + by;
                bonus = Math.max((xs == x[n] && ys == y[n])?1:0, bonus);
                n++;
            }
            int max = 0;
            for(int l = 0; l<n; l++){
                for(int r = l; r<n; r++){
                    //check if this range is poss!
                    long dist_x = Math.abs(x[l]-x[r]);
                    long dist_y = Math.abs(y[l]-y[r]);
                    long shrt = Math.min((Math.abs(x[r]-xs) + Math.abs(y[r]-ys)), (Math.abs(x[l]-xs)+Math.abs(y[l]-ys)));
                    if(dist_x+dist_y+shrt<=t){
                        //System.err.println(dist_x+dist_y+shrt + " "+l+" "+r+" "+(r-l+1+bonus));
                        max = Math.max(max, r-l+1);
                    }
                }
            }
            sb.append(max).append('\n');
        }
        System.out.println(sb);
    }
}
