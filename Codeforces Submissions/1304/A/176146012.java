import java.util.Scanner;

public class CFR620D2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        while(n>0){
            n--;
            int x=sc.nextInt();
            int y=sc.nextInt();
            int a=sc.nextInt();
            int b=sc.nextInt();
           int L=(y-x);
           int jump=a+b;
           if(L%jump==0){
            System.out.println((int)L/jump);
           }else{
            System.out.println("-1");
           }
        }
    }
}
