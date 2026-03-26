import java.util.*;
import java.io.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class Main {

    public static void main(String[] args) throws java.lang.Exception {
        Scanner scn = new Scanner(System.in);
        // int t = scn.nextInt();
        // while (t-- > 0) {
        // }
        int n = scn.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=scn.nextInt();
        }

// int c1=0;
//         for(int i=0;i<n;i++){
// if(arr[i]==1){
// c1++;
// }
//         }
//         if(c1==0){
//             System.out.println(0);
//             return;
//         }

//         int curr=0;
//         int max=0;
//         for(int i=1; i<n; i++){
//             if(arr[i-1]==1 && arr[i]==1){
// curr++;
//             }
//             if(curr>=max){
// max=curr;
//             }
//         }
//         if(max==0 && arr[0]==1 && arr[n-1]==1){
//             max=2;
//             System.out.println(max);
// return;
//         }
// System.out.println(max+1);

int res=0;
int fans=0;

for (int i = 0; i < n * 2; i++) {
    if (arr[i % n] == 1) {
        res++;
        fans = Math.max(res, fans);
    } else {

        res = 0;
    }
}
System.out.println(fans);



    }
}
