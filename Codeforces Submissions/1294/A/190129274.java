import java.util.*;
public class Collectingcoins {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i=0;i<n;i++)
        {
            int a[]=new int[3];
            for(int j=0;j<3;j++)
            {
                a[j]=in.nextInt();
            }
            int no = in.nextInt();
            Arrays.sort(a);
            int g = a[2]-a[0];
            int h =a[2]-a[1];
            no=no-(g+h);
            if(no%3==0&&no>=0)
                System.out.println("YES");
            else
                System.out.println("NO");

        }
    }
}
