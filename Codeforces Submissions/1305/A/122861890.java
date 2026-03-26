import java.io.*;
import java.util.*;

public class KuroniGifts
{

    public static void main(String[] args)throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        int t=Integer.parseInt(st.nextToken());
        for(int e=1;e<=t;e++)
        {
            int n=Integer.parseInt(br.readLine());
            int[] arr=new int[n];
            int[] arr2=new int[n];
            st=new StringTokenizer(br.readLine());
            for(int i=0;i<n;i++)
                arr[i]=Integer.parseInt(st.nextToken());
            st=new StringTokenizer(br.readLine());
            for(int i=0;i<n;i++)
                arr2[i]=Integer.parseInt(st.nextToken());
            Arrays.sort(arr);
            Arrays.sort(arr2);
            for(int i=0;i<n;i++)
            {
                System.out.print(arr[i]+" ");
            }
            System.out.println();
            for(int i=0;i<n;i++)
            {
                System.out.print(arr2[i]+" ");
            }
            System.out.println();
        }
    }
}
