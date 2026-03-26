import java.util.Scanner;

public class Maths_5 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int n=sc.nextInt();
            int odd=0,even=0;
            for(int i=0;i<n;i++){
                int x=sc.nextInt();
                if((x&1)==0)
                    even++;
                else
                    odd++;
            }
            if((odd&1)==1)
                System.out.println("YES");
            else{
                if(odd>=1&&even>=1)
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
        }
    }
}
