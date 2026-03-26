import java.util.*;
public class MyClass {
    public static void main(String args[]) {
      Scanner kb = new Scanner(System.in);
      int t  = kb.nextInt();
      while(t-- > 0)
      {
          int n = kb.nextInt();
          int x = 0;
        int[] arr1 = new int[n];
          boolean even = false;
          int index=-1;
          for(int i=0;i<n;i++)
          {
              arr1[i] = kb.nextInt();
              if(arr1[i]%2==0)
              {
                  even = true;
                  index=i+1;
              }
          }
          if(even)
          {
              System.out.println(1);
              System.out.println(index);
          }
          else if(n==1)
          {
              System.out.println(-1);
          }
          else
          {
              System.out.println(2);
              System.out.println(1+" "+2);
          }
            
      }
    }
}