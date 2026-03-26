import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            
            String str = sc.next();
            
            System.out.println(ebne(str,n));
            
        }
    }
    public static String ebne(String str,int n){
        int last = str.charAt(n-1) - '0';
            int i;
            if(last%2==0){
                for( i=n-1;i>=0;i--){
                    if((str.charAt(i)-'0')%2!=0)
                    break;
                }
                if(i==-1)
                return "-1";
                else
                str = str.substring(0,i+1);
            }
            int sum=0;
            n = str.length();
            for(i=n-1;i>=0;i--){
                sum+= str.charAt(i)-'0';
                if(sum%2==0){
                    return str.substring(i,n);
                }
            }
            return "-1";
    }
}