import java.util.HashSet;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;
import java.util.Scanner;
public class A1307{
    
 public static int[] sort(int[] arr,int low,int high){
        int[] sortedArray;
        if (low==high) {
            sortedArray=new int[]{arr[low]};
            return sortedArray;
        }
        int mid=(low+high)/2;
        int[] arr1=sort(arr,low,mid);
        int[] arr2=sort(arr,mid+1,high);

        sortedArray=merge(arr1,low,mid,arr2,mid+1,high);
        return sortedArray;

    }

    public static int[] merge(int[] arr1,int low1,int high1,int[] arr2,int low2,int high2){

        int size1=high1-low1+1;
        int size2=high2-low2+1;
        
        int[] arr=new int[size1+size2];
        int pointer=0;
        low1=0;low2=0;
        while (low1<size1 && low2<size2){
            if (arr1[low1] <= arr2[low2]) {
                arr[pointer++]=arr1[low1++];
            }
            else{
                arr[pointer++]=arr2[low2++];
            }

        }

        while(low1<size1) arr[pointer++]=arr1[low1++];
        while(low2<size2) arr[pointer++]=arr2[low2++];
        return arr;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-- >0){
             int n=sc.nextInt();
             int d=sc.nextInt();
             int[] arr=new int[n];
             for(int i=0;i<n;i++){
                 arr[i]=sc.nextInt();
             }
             int ans=0;
             for(int i=1;i<n;i++){
                 int dist=i;
                 while(arr[i] >  0 && d >= dist){
                     d-=dist;
                     ans++;
                     arr[i]-=1;
                 }
             }
             
             System.out.println(ans+arr[0]);
        }
        sc.close();
    }   
}
