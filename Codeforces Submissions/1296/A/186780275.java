import java.util.*;
public class MyClass {
    public static void main(String args[]) 
    {
        Scanner kb = new Scanner(System.in);
        int t = kb.nextInt();
        while(t-- > 0)
        {
            int n = kb.nextInt();
            int even=0;
            int odd=0;
            int temp=n;
            while(n-- > 0)
            {
                if(kb.nextInt() % 2 == 0)
                {
                    even++;
                }
                else
                {
                    odd++;
                }
            }
            
            if(even == 0)
            {
                if(temp%2==0)
                {
                    System.out.println("NO");
                }
                else
                {
                    System.out.println("YES");
                }
                
            }
            else if(odd == 0)
            {
                System.out.println("NO");
            }
            else
            {
                System.out.println("YES");
            }
        }
    }
}