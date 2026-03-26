/*
	This article is written by
    Pawan Kumar Kesarwani


	Dynamic Programming Solution
    to reduce the size of array by
	Replacing the two
    consecutive equal 
	elementse greater value
*/    

import java.util.*;
import java.lang.*;
import java.io.*;

public class ReplaceConsecutiveEqualElements
{
	// Method to return minimum of two values
	public static int min(int a, int b)
	{
		if(a>b)
			return b;
		return a;
	}
	
	// Method to replace consecutive equal elements
	// with a one greater value
	
	// It recieves the array and the size of array
	// as parameter
	public static int replaceConsecutiveEqualElements(int arr[], int n)
	{
	  	/*
	  		Creating two arrays to build the solution 
	  		in a bottom up manner
	  		
	  		dp[i][j] = Number of elements remaining after
			replacing consecutive equal elememts  with one
		    greater value in arr[i..j]
	  		
	  		element[i][j] = The result value after replacing 
	  		consecutive equal elememts  with one greater value
	  		in arr[i..j]
	  	*/
		  	
		int[][] dp = new int[n][n];
		int[][] element = new int[n][n];
		
	  	int i, j, k, len;
	  	
	  	// For length = 1  
	  	for(i = 0; i <= n-1; i++)
	    {
	    	dp[i][i] = 1;
	    	element[i][i] = arr[i];
	    }
	  	
	  	// Initialising the dp[i][j] with the number of elements 
	  	// in the range i..j
	    for (i = 0; i <= n-1; i++) 
	    {
	        for (j = i; j <= n-1; j++) 
	        {
	          	dp[i][j] = j - i + 1;
	        }
	    }
	        
	    // len is the length of array considering at a time
	    // Building the solution in a bottom up manner
	    // The loop structure is same as Matrix Chain Multiplication 
	    for(len = 2; len <= n; len++)
	    {
	    	// For all segments of length len
	    	// different possible starting indexes
			for(i = 0; i + len - 1 <= n-1; i++)
			{
				j = i + len - 1;
				for (k = i; k < j; k++)
				{
					// updating the length of segment  in i..j
					dp[i][j] = min (dp[i][j], (dp[i][k] + dp[k + 1][j]));
					
					// if segment i..k and k+1..j both have been converted to 
					// unit length and the value in both segment is same
					// update dp[i][j] to unity and
					// element[i][j] to either element[i][k]+1 or element[k+1][j]+1
					if ((dp[i][k] == 1) && (dp[k + 1][j]==1) && 
						(element[i][k] == element[k + 1][j]))
					{
						dp[i][j] = 1;
						element[i][j] = element[i][k]+1;
					}
				}
			}
		}
	    
	    // Return the number of values remaining in the array[1..n]
	    return dp[0][n-1];
	}

	// Driver Code
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		// The size of the array
		int n = sc.nextInt();
		
		
		// Accepting the array
		int i;
		int[] arr = new int[n];
		for(i = 0; i <= n-1; i++)
		{
			int key = sc.nextInt();
			arr[i] = key;
		}
	  	
	  	// Calling the function and Printing the result
		System.out.println("" + replaceConsecutiveEqualElements(arr, n));
	  	
	}
}

//int arr[] = { 7, 7, 5, 5, 6, 6, 6, 8, 7, 7, 7, 5, 5, 6, 10 };
//int n=15;