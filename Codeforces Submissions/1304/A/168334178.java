import java.util.*;
public class MyClass {
    public static void main(String args[]) 
    {
        Scanner kb = new Scanner(System.in);
        int t = kb.nextInt();
        while(t-- > 0)
        {
        int x = kb.nextInt();
        int y = kb.nextInt();
        int a = kb.nextInt();
        int b = kb.nextInt();
        
        int total = y-x;
        int jump = a+b;
        if(total%jump == 0)
        {
            System.out.println(total/jump);
        }
        else
        {
            System.out.println(-1);
        }
        
        }
        
        
      
    }
}