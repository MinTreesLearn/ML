import java.io.*;
import java.util.*;

public class codeforces {

    public static void main(String[] args) {
        Scanner scn= new Scanner(System.in);
        int n= scn.nextInt();
        int [] arr= new int [n];
        for(int i=0; i<n; i++){
            arr[i]=scn.nextInt();
        }
       int count=0;
       int max=0;
       for(int j=0; j<2; j++){
       for(int i=0; i<n; i++){
           
           if(arr[i]==1){
               count++;
           }
           else{
               max= Math.max(max, count);
               count=0;
               if(j==1){
                   System.out.println(max);
                   return;
               }
           }

        
       }
    }

    }
}
