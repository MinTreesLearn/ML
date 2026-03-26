import java.util.*;
import java.io.*;
public class NewYearAndNaming{
    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();

        String[] pre = new String[n];
        String[] suff = new String[m];

        for(int i=0;i<n;i++){
            pre[i] = scn.next();
        }
        for(int j=0;j<m;j++){
            suff[j] = scn.next();
        }

        int t = scn.nextInt();

        while(t>0){
            int year = scn.nextInt();
            int preidx = (year-1)%n;
            int suffidx = (year-1)%m;

            String name = pre[preidx] + suff[suffidx];
            System.out.println(name);
            t--;
        }
    }
}