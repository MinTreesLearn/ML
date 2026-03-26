import java.util.Scanner;
public class food_buying {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int i = 0 ; i < t ; i ++){
            int n = s.nextInt();
            int max = 0 ;
            int e = 0;
            while(true){
                while(n!=0) {
                    e += n % 10;
                    max += (n - n % 10);
                    n = (n - n % 10) / 10;
                }
                if(e<10){
                    System.out.println(max + e);
                    break;
                }
                n = e;
                e = 0 ;
            }
        }
    }
}
