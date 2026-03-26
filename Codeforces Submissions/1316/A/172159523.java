import java.util.*;

public class Main
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while(n-- > 0)
        {
            int no_of_stud = sc.nextInt();
            int highest_mar_poss = sc.nextInt();
            int[] arr = new int[no_of_stud];
            int sum = 0;
            for(int i = 0; i < no_of_stud; i++)
            {
                arr[i] = sc.nextInt();
                sum += arr[i];
            }
            if(sum >= highest_mar_poss)
            {
                System.out.println(highest_mar_poss);
            }
            else
            {
                System.out.println(sum);
            }
            //System.out.println(arr[no_of_stud - 1]);
        }
    }
}
