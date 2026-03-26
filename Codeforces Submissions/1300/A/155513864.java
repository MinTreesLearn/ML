import java.util.*;
import java.io.*;
import java.lang.reflect.Array;

public class codeforce {

    public static void main(String[] args) throws IOException {
 
        Scanner read = new Scanner(System.in);
        
        int t = read.nextInt();

        for(int k=0;k<t;k++){

            int n = read.nextInt();

            int[] arr = new int[n];
            int sum = 0;
            int ans = 0;
            for(int i=0;i<n;i++){
                arr[i] = read.nextInt();
                if(arr[i]==0){
                    arr[i]++;
                    ans++;
                }
                sum+=arr[i];
            }
            if(sum==0) ans++;
            
            System.out.println(ans);
        }
        read.close();
    } 
}   