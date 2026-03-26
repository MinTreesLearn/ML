import java.io.*;
import java.util.*;

public class DeadPixel
{

    public static void main(String[] args)throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        int t=Integer.parseInt(st.nextToken());
        for(int e=1;e<=t;e++)
        {
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            int x=Integer.parseInt(st.nextToken());
            int y=Integer.parseInt(st.nextToken());
            PriorityQueue<Integer> maxPq=new PriorityQueue<>(Collections.reverseOrder());
            maxPq.add(x*b);
            maxPq.add((a-x-1)*b);
            maxPq.add((b-y-1)*a);
            maxPq.add(y*a);
            System.out.println(maxPq.peek());
        }
    }
}