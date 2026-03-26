import java.util.*;
public class Add{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=0;i<t;i++){
            long a,b,c,d;
            a=d=0;
            c=0;
            a=sc.nextLong();
            b=sc.nextLong();
            if(a==b){
                System.out.println("0");
                continue;
            }
            if(a>b){
                d=a-b;
                c++;
                if(d%2!=0){
                    c++;
                }
            }
            else if(a<b){
                d=b-a;
                c++;
                if(d%2!=1){
                    c++;
                }
            }
            System.out.println(c);
        }
    }
}