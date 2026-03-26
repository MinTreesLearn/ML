import java.util.*;

/**
 * B_Food_Buying
 */
public class B_Food_Buying {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            long n = sc.nextLong();
            long ans=0 ;
            while(n!=0){
                if(n<10){
                    ans+=n;
                    n=0;
                }else{
                    long a =n/10;
                    ans += a*10;
                    n %= 10;
                    n+=a;
                } 
            } 
            System.out.println(ans);
            
        }
    }
}