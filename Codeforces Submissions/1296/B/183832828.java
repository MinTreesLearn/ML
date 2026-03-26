import java.util.Scanner;

public class foodBuying {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t= sc.nextInt();
        for(int i=0;i<t;i++){
            int n = sc.nextInt();
            int sum=n;
            while(n>=10){
                int temp = (n-n%10)/10;
                sum+= temp;
                n =n-temp*10+temp;
            }
            System.out.println(sum);
        }
    }
}
