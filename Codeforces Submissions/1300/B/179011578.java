import java.util.*;
public class Solution
{
     public static void main(String[] args)
     {
          Scanner sc = new Scanner(System.in);
          int testCases = sc.nextInt();
          
          while(testCases != 0)
          {
               int n = sc.nextInt() * 2;
               int[] arr = new int[n];
               for(int i = 0; i < n; i++)
               {
                    arr[i] = sc.nextInt();
               }
               
               Arrays.sort(arr);
               int mid = arr.length / 2;
               System.out.println(Math.abs(arr[mid] - arr[mid - 1]));
               
               testCases -= 1;
          }
          
          return;
     }
     
     private static int getPartition(int[] arr)
     {
          Arrays.sort(arr);
          ArrayList<Integer> left = new ArrayList<>();
          ArrayList<Integer> right = new ArrayList<>();
          
          
          for(int i = 0; i < arr.length; i++)
          {
               if(i % 2 == 0)
               {
                    left.add(arr[i]);
               }
               else
               {
                    right.add(arr[i]);
               }
          }
          
          int mid = left.size() / 2;
          return Math.abs(left.get(mid) - right.get(mid));
          
     }
     
     
}