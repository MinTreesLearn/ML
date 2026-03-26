 
import java.util.*;
import java.math.*;
import java.io.*;

public class NonZero {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int n = in.nextInt(),sum=0,steps=0;
            int[]arr=new int [n];
            for(int j=0;j<n;j++){
                arr[j]= in.nextInt();
                if(arr[j]==0){
                    arr[j]=1;
                    steps++;
                }
                sum+=arr[j];
            }
            if(sum!=0)
                System.out.println(steps);
            else
                System.out.println(steps+1);


        }
    }
}
