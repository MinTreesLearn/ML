import java.io.*;
import java.util.*;

public class Codeforces
{
    public static void main(String args[])throws Exception
    {
        BufferedReader bu=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        int t=Integer.parseInt(bu.readLine());
        while(t-->0)
        {
            String s[]=bu.readLine().split(" ");
            long n=Integer.parseInt(s[0]),x=Integer.parseInt(s[1]),y=Integer.parseInt(s[2]);
            if(x>y) x=x^y^(y=x);
            long min=Math.max(1,Math.min(n,x+y-n+1));
            long max=Math.min(x+y-1,n);
            sb.append(min+" "+max+"\n");
        }
        System.out.print(sb);
    }
}
