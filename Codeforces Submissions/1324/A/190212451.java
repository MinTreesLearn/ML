/*package whatever //do not write package name here */

import java.util.Scanner;
public class code{
   /* public static boolean perfect(int n){
        double d1 = Math.sqrt(n);
        if(d1==(int)d1){
            return true;
        }
        return false;
    }*/
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int t1 = s.nextInt();
        while(t1-->0){
            int n = s.nextInt();
            int[] arr = new int[n];
            int count_odd = 0;
            int count_even = 0;
            for(int i = 0;i<n;i++){
                arr[i] = s.nextInt();
                if(arr[i]%2==0){
                    count_even+=1;
                }else{
                    count_odd+=1;
                }
            }
            if(count_even==0 && count_odd!=0){
                System.out.println("YES");
            }else if (count_even!=0 && count_odd==0){
                 System.out.println("YES");
            }else{
                System.out.println("NO");
            }
            
            
        }
    }
}