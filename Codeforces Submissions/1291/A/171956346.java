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
        int count=0;
        String s = new String();
        for(int i=0;i<n && count<2;i++){
            if((str.charAt(i)-'0') %2 != 0){
                s+= str.charAt(i);
                count++;
            }
        }   
        if(count==2)
        return s;
        
        return "-1";
    }
}