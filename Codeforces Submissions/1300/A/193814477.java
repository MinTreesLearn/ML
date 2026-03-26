/*package whatever //do not write package name here */

import java.util.Scanner;
import java.util.Arrays;
public class code{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while(t-->0){
            int n = s.nextInt();
            int[] arr = new int[n];
            int count_zero = 0;
            int sum = 0;
            for(int i = 0;i<n;i++){
                arr[i] = s.nextInt();
                if(arr[i]==0){
                    arr[i] = 1;
                    count_zero +=1;
                }
                sum+=arr[i];
            }
            

            
                if(sum!=0){
                    System.out.println(count_zero);
                }else{
                    // find the smallest number and make it non-negative 
                   // Arrays.sort(arr);
                   
                    System.out.println(1+count_zero);
                }
            
            
        }
    }
}