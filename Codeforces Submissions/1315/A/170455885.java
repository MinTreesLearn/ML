import java.awt.Point;
import java.io.*;
import java.util.*;
 
 public class Main {
    
   public static void main (String[] args) throws java.lang.Exception {
        Scanner sc= new Scanner(System.in);
        int t= sc.nextInt();
        int x=0,y=0,a=0,b=0;

        for(int i=0; i<t; i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            x = sc.nextInt();
            y = sc.nextInt();


            int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
            ans1 = a * y;
            ans2 = b * x;
            ans3 = (a - 1 - x) * b;
            ans4 = a * (b - 1 - y);
            int ans = 0;
            ans = Math.max(ans1, ans2);
            ans = Math.max(ans, Math.max(ans3, ans4));
            System.out.println(ans);


        }
}}