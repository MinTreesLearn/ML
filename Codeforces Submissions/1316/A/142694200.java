import java.util.*;
import java.lang.*;
import java.io.*;
public class GradeAllocation {
    public static void main(String[] args)throws java.lang.Exception{
        Scanner scn=new Scanner(System.in);
        int a=scn.nextInt();
        while(a-->0){
            int b=scn.nextInt();
            int d=scn.nextInt();
            int f=0;
            int[] arr=new int[b];
            for(int i=0;i<arr.length;i++){
                arr[i]=scn.nextInt();
                f+=arr[i];
            }
           System.out.println(Math.min(d,f));
        }
    }
}
