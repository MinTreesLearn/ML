import java.util.*;

public class CopyCopyCopyCopyCopy1325B 
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for(int i=0;i<t;i++)
        {
            int n = scan.nextInt();
            Integer[] arr = new Integer[n];
            for(int j=0;j<n;j++)
            {
                arr[j] = scan.nextInt();
            }
            int count = 0;
            Set<Integer> set = new HashSet<Integer>(Arrays.asList(arr));
            for(Integer x : set)
            {
                // System.out.print(x + " ");
                count++;
            }
            System.out.println(count);
        }
        scan.close();
    }    
}
