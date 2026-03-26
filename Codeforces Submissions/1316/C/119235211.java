import java.io.*;
import java.util.*;

public class E {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        //int tst = Integer.parseInt(br.readLine());
        int tst = 1;
        while(tst-->0){
            String[] str = br.readLine().split(" ");
            int n = Integer.parseInt(str[0]), m = Integer.parseInt(str[1]), p = Integer.parseInt(str[2]);
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int ans = 0;
            for(int i = 0; i<n; i++){
                int x = Integer.parseInt(st1.nextToken());
                if(x%p != 0){
                    ans = i;
                    break;
                }
            }
            for(int i = 0; i<m; i++){
                int x = Integer.parseInt(st2.nextToken());
                if(x%p != 0){
                    ans += i;
                    break;
                }
            }
            System.out.println(ans);
        }
        //System.out.println(sb);
    }
}
