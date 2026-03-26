
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while((t--)>0)
        {
            int arr[]=new int[3];
             arr[0]=sc.nextInt();
             arr[1]=sc.nextInt();
             arr[2]=sc.nextInt();
            int x=sc.nextInt();
            Arrays.sort(arr);
            int z=0;
            z=(arr[2]-arr[0]) + (arr[2]-arr[1]);
            if(z>x)
            {
                System.out.println("No");
                continue;
            }
            else
            {
                if((x-z)%3==0)
                {
                    System.out.println("Yes");
                }
                else System.out.println("No");
            }

        }
    }
}
