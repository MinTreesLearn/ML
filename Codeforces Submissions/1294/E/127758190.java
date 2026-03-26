import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
  public static void main (String[] args) throws java.lang.Exception
  {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int m = scn.nextInt();
    long[][] arr = new long[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            arr[i][j] = scn.nextLong();
    }
    
    long ans = 0;
    for(int col=0; col<m; col++)
    {
        // Frequency Array Corresponding to Count of Elements to given Cyclic Shift
        // freq[i] = Elements in Right Position for ith cyclic shift
        long[] freq = new long[n];
        
        for(int row = 0; row < n; row++)
        {
            long desiredRow = (arr[row][col] - (col + 1l)) / m;
            if(arr[row][col] % m == (col + 1) % m && desiredRow >= 0 && desiredRow <= n-1)
            {
                if(desiredRow <= row) 
                    freq[row - (int)desiredRow]++;
                else freq[n + row - (int)desiredRow]++; 
            }
        }
        
        long minOperations = n;
        for(int i=0; i<n; i++)
        {
            // Operations = Changes in Values (n - freq[i]) + Cyclic Shifts (i)
            long totalOperations = (n - freq[i]) + i;
            minOperations = Math.min(minOperations, totalOperations);
        }
        
        ans += minOperations;
    }
    System.out.println(ans);
  }
}