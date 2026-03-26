import java.io.*;
import java.util.*;

public class cowHaybales
{

    public static void main(String[] args)throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        int t=Integer.parseInt(st.nextToken());
        for(int e=1;e<=t;e++)
        {
            st=new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());
            int d=Integer.parseInt(st.nextToken());
            st=new StringTokenizer(br.readLine());
            int sum=Integer.parseInt(st.nextToken());
            for(int i=1;i<n;i++)
            {
                int a=Integer.parseInt(st.nextToken());
                if(a*(i)<=d)
                {
                    d=d-(a*i);
                    sum+=a;
                }
                else
                {
                    sum+=d/i;
                    break;
                }
            }
            System.out.println(sum);
        }
    }
}