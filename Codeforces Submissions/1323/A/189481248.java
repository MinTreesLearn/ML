

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;
import java.util.Stack;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

   public static void main(String[] args) {
   
     Scanner in = new Scanner(System.in);
     int t = in.nextInt();
    while (t-- != 0) {
      int n = in.nextInt();
     int[] arr = new int[n];
     int index = 0;;
     boolean isEven = false;
     for (int i = 0; i < n; i++) {
      arr[i] = in.nextInt();
      if (arr[i] % 2 == 0) {
        isEven = true;
        index = i+1; 
      }
    }
      if (isEven) {
        System.out.println(1 + "\n" +index);
        continue;
      }
      System.out.println(arr.length == 1 ? -1 : 2 + "\n" + 1 + " " + 2 );
     
    }
    //  int n;
    // cin >> n;
    // int stw[n];
    // int c = 0;
    // for (int i = 0; i < n; i++){
    //     cin >> stw[i];
    // }
    // int ns = sizeof(stw) / sizeof(stw[0]);
    
    // sort(stw,stw+ns);
    // int max = stw[n-1];
    // int min = stw[0];
    // for (int  i = 0; i < n; i++)
    // {   
    //     if (stw[i] < max && stw[i] > min)
    //     {
    //         c++;
    //     }

        
    // }

   }
   }


	 		   	   	    	 	   	 	  		 	