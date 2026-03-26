import java.util.*;

public class Solution

{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        long h=sc.nextLong();
        int n=sc.nextInt();
        long[] ar=new long[n];
        long base=h;
        int an=0;
        int pr=0;
        boolean ok=false;
        for(int i=0;i<n;i++){
            ar[i]=sc.nextLong();
            base+=ar[i];
            an++;
            if(base<=0 && ok==false){ok=true;pr=an;}
            
        }
        if(base>=h){
            if(ok)System.out.println(pr);
            else System.out.println("-1");
        }
        else{
           long b=h;
           long max=0;
           long ans=0;long extra=0; 
           long min=0;
            ok=true;
           long overall=0;
           for(int i=0;i<n;i++){
               ans++;
               b+=ar[i];
               min+=ar[i];
               overall+=ar[i];
               if(Math.abs(min)>max && min<0){
                   max=Math.abs(min);
                   extra=i+1;
               }
               if(b<=0 && ok){ok=false;break;}
               
           }
           if(!ok)System.out.println(ans);
           else{
               long rem=b-max;
               overall=Math.abs(overall);
               if(rem<=0){
                    while(true){
                for(int i=0;i<n;i++){
                    if(b<=0)break;
                    b+=ar[i];
                    ans++;
                    if(b<=0)break;
                }
                if(b<=0)break;
              }
               }
               else{
                  long div=rem/overall;
                  rem-=div*overall;
                  div=div*(long)n;
                  ans+=div;
                 
                  rem+=max;
                   while(true){
                for(int i=0;i<n;i++){
                    if(rem<=0)break;
                    rem+=ar[i];
                    ans++;
                    if(rem<=0)break;
                }
                if(rem<=0)break;
              }
                  
               }
               System.out.println(ans);
               
           }
           
        }
    }
}