import javax.crypto.spec.OAEPParameterSpec;
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
            int n=Integer.parseInt(s[0]),m=Integer.parseInt(s[1]),k=Integer.parseInt(s[2]);
            int a[]=new int[n],i;
            s=bu.readLine().split(" ");
            for(i=0;i<n;i++) a[i]=Integer.parseInt(s[i]);

            k=Math.min(k,m-1); int ans=0,j;
            for(i=0;i<=k;i++)
            {
                int cur=Integer.MAX_VALUE;
                for(j=0;j<=m-1-k;j++)
                cur=Math.min(cur,Math.max(a[i+j],a[i+j+n-m]));
                ans=Math.max(ans,cur);
            }
            sb.append(ans+"\n");
        }
        System.out.print(sb);
    }
}
