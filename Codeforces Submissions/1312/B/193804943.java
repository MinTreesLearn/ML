/*package whatever //do not write package name here */
import java.util.Scanner;
import java.util.Arrays;
public class code{
    public static void print(int[] arr){
        for(int j = 0;j<arr.length;j++){
            System.out.print(arr[j]+" ");
        }
    }
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while(t-->0){
            int n  = s.nextInt();
            int[] arr = new int[n];
            for(int i = 0;i<n;i++){
                arr[i] = s.nextInt();
            }
            Arrays.sort(arr);
            int[] arr2 = new int[n];
            for(int k = 0;k<n;k++){
                arr2[k] = arr[n-1-k];
            }
            print(arr2);
            System.out.println();
            System.out.println();
        }
    }
}