import java.util.*;
public class Game23 {
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int a= sc.nextInt();
        int b= sc.nextInt();
        int count=0;
        if(b%a!=0){
            System.out.println(-1);
            return;
        }
        int x=b/a;
        while(x%3==0){
            count++;
            x=x/3;
        }
        while(x%2==0){
            count++;
            x=x/2;
        }
        if(x!=1){
            System.out.println(-1);
            return;
        }
        System.out.println(count);
    }
}
