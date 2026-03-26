import java.io.*;
import java.util.*;

public class days {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int u = 0;u < T;u++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            long N = Long.parseLong(st.nextToken());
            long G = Long.parseLong(st.nextToken());
            long B = Long.parseLong(st.nextToken());
            long need = N - N/2;
            long turn  = need/G;
            long all = G + B;
            long left = need%G;
            if(left == 0){
                turn --;
                left = G;
            }
            if(turn * B >= N/2 ){
                System.out.println(all*turn + left);
            }else{
                System.out.println(N);
            }
        }
    }
}