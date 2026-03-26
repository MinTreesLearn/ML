import java.util.*;
public class MyClass {
    public static void main(String args[]) 
    {
        Scanner kb = new Scanner(System.in);
        int t = kb.nextInt();
        while(t-- > 0)
        {
            String a = kb.next();
            String b = kb.next();
            String c = kb.next();
            boolean flag = true;
            for(int i=0;i<a.length();i++)
            {
                char c1 = a.charAt(i);
                char c2 = b.charAt(i);
                char c3 = c.charAt(i);
                if(!(c1==c3 ||c2==c3))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
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