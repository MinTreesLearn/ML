import java.util.*;
public class MyClass {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            String a=sc.next();
            String b=sc.next();
            String c=sc.next();
            
            boolean flag=true;
            for(int i=0;i<c.length();i++){
                if(c.charAt(i)!=a.charAt(i) && c.charAt(i)!=b.charAt(i)){
                    System.out.println("NO");
                    flag=false;
                    break;
                }
            }
            if(flag)
            System.out.println("YES");
        }
   
    }
}