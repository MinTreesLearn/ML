import java.util.*;
public class Solution
{
     public static void main(String[] args)
     {
          Scanner sc = new Scanner(System.in);
          long n = sc.nextLong();
          long m = sc.nextLong();
          
          int res = solve(n, m);
          
          if(res >= 10000000) System.out.println(-1);
          else System.out.println(res);
          
     }
     
     private static int solve(long current, long target)
     {
          if(current == target) return 0;
          
          if(current > target || current < 0) return 10000000;
          
          int mulTwo = 1 + solve(current * 2, target);
          int mulThree = 1 + solve(current * 3, target);
          
          return Math.min(mulTwo, mulThree);
     }
}