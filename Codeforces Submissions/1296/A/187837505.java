import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while((t--)>0)
        {
            int n=sc.nextInt();
            int oddCount=0;
            int []arr=new int[n];
            for (int i = 0; i < n; i++) {
                arr[i]= sc.nextInt();
                if(arr[i]%2!=0)
                {
                    oddCount++;
                }
            }
            if(oddCount==0 || (oddCount==n && oddCount%2==0))
            {
                System.out.println("No");
            }
            else System.out.println("Yes");
        }
    }
}
