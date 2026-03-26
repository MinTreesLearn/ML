import java.util.Scanner;

public class CFR83D2 {
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0){
            t--;
        int a=sc.nextInt();
        int b=sc.nextInt();
     if(a>b&&a%b==0){
        System.out.println( "YES");
     }else{
        System.out.println("NO");
     }

        }
    }
}
