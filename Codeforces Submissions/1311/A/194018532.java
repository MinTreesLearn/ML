import java.util.*;
public class Same{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        //System.out.println("enter n:");
        int n=s.nextInt();
        for(int i=0;i<n;i++){
           int count=0,d=0;
           int a=s.nextInt();
           int b=s.nextInt();
           if(a==b){
             System.out.println("0");
             continue;
           }
           if(a>b){
              d=a-b;
             count+=1;
             if(d%2!=0){
                count+=1;
             }
           }
           if(a<b){
             d=b-a;
             count+=1;
             if(d%2!=1){
                count+=1;
             }
           }
           System.out.println(count);
        }
    }
}