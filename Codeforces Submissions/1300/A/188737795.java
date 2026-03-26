import java.util.*;

public class MyClass {
    public static void main(String args[]) 
    {
        Scanner kb = new Scanner(System.in);
        int t = kb.nextInt();
        while(t-- > 0)
        {
            int n = kb.nextInt();
            int sum=0;
            int zero=0;
            for(int i=0;i<n;i++)
            {
                int a = kb.nextInt();
                sum+=a;
                if(a == 0)
                {
                    zero++;
                }
            }
            sum+=zero;
            if(sum == 0)
            {
                zero++;
            }
            
            
            System.out.println(zero);
            
            
            
        }
    }
}