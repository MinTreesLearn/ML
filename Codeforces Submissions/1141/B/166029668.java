// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
 public class HelloWorld {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        int n = scan.nextInt();
        int[] arr = new int[n];
       
        for(int i =0;i<n;i++){
            arr[i]=scan.nextInt();
            
        }
        
        int currOne = 0,maxOne = 0;
        for(int i =0;i<2 *arr.length;i++){
            if(arr[i % n]==1){
                currOne +=1;
                maxOne = Math.max(maxOne,currOne);
            }
            else{
                currOne = 0;
            }
        }
        System.out.println(maxOne);
       
    }
}