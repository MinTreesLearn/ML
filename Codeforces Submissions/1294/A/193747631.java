import java.util.*;
public class Main
{
	public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        while(n-->0)
        {
           int a=s.nextInt();
           int b=s.nextInt();
           int c=s.nextInt();
           int q=s.nextInt();
           int target=(a+b+c+q)/3;
           if((a<=target)&&(b<=target)&&(c<=target)&&((a+b+c+q)%3==0))
           {
               System.out.println("YES");
           }
           else
           {
               System.out.println("NO");
           }
        }
}
}
