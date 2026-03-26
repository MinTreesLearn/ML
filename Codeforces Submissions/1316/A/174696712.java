import java.util.*;
public class MyClass {
    public static void main(String args[]) {
      Scanner kb = new Scanner(System.in);
      int t  = kb.nextInt();
      while(t-- > 0)
      {
          int n = kb.nextInt();
          int x = kb.nextInt();
        //  int[ ] arr1 = new int[n];
          int sum=0;
          
          for(int i=0;i<n;i++)
          {
              sum += kb.nextInt();
          }
            System.out.println(Math.min(sum , x));
      }
    }
}