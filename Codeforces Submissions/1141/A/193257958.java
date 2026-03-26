
import java.util.*;
import java.io.*;
import java.lang.*;


public class Main {


    /*------------------------ MAIN METHOD ---------------------*/
    public static void main(String arg[]) throws IOException {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        StringTokenizer enter = new StringTokenizer(in.readLine().strip());
        int n = Integer.parseInt(enter.nextToken().strip());
        int m = Integer.parseInt(enter.nextToken().strip());

        if(m%n!=0){
            out.print(-1+"\n");
            out.flush();
        }else{
            int res = m/n;
            int i = 0;
            while(res%2==0){
                i++;
                res/=2;
            }
            int j = 0;
            while(res%3==0){
                j++;
                res/=3;
            }
            
            if(res!=1){
                out.print(-1+"\n");
                out.flush();
            }else{
                out.print(i+j+"\n");
                out.flush();
            }
        }
        /*----------------------------------------*/
 /*----------------------------------------*/ theEnd();
        /*----------------------------------------*/
    }

    /*--------------------------------------------------------------------------------------------------------*/
    public static void theEnd() {
        System.exit(0);
    }
}
