import java.util.Scanner;
import java.util.Arrays;
import java.util.HashSet;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.TreeSet;
import java.util.PriorityQueue;
public class Solution{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int test_cases = sc.nextInt();
        outer : for(int h=0;h<test_cases;h++){
            //scan the input
           int n = sc.nextInt();
           int a[] = new int[n];
           scan_array(a, n, sc);

           boolean flag = false;
           for(int i=0;i<n-1;i++){
            if(Math.abs(a[i]-a[i+1])%2==1){
                flag = true;
                break;
            }
           }
           if(flag){
            System.out.println("NO");
           }
           else{
            System.out.println("YES");
           }
        }
        sc.close();
    }
    public static void scan_string_array(String s[] , int n, Scanner sc){
        for(int i=0;i<n;i++){
            s[i] = sc.next();
        }
    }
    public static void swap_elements(int a[], int s_index, int e_index){
        int temp = a[s_index];
        a[s_index] = a[e_index];
        a[e_index] = temp;
    }
    public static void scan_array_long(long a[], int n, Scanner sc){
        for(int i=0;i<n;i++){
            a[i] = sc.nextLong();
        }
    }
    public static void scan_array(int a[], int n, Scanner sc){
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
        }
    }
    public static void print_array(int a[]){
        for(int i=0;i<a.length;i++){
            if(i==a.length-1){
                System.out.println(a[i]);
                return;
            }
            System.out.print(a[i]+" ");
        }
    }
    public static long sum_array(long a[]){
        long sum = 0;
        for(int i=0;i<a.length;i++){
            sum+=a[i];
        }
        return sum;
    }
    public static boolean perfect_square(double num){
        boolean isSq = false;
        double b = Math.sqrt(num);
        double c = Math.sqrt(num) - Math.floor(b);
        if(c==0){
            isSq=true;
        }
        return isSq;
    }
    public static boolean ispalindrome(String s){
        int i=0, j =s.length()-1;
        while(i<=j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public static boolean ispowerOftwo(int n){
        if(n>0 && (int)(n & (n-1))==0){
            return true;
        }
        else{
            return false;
        }
    }
    public static int calculate_gcd(int x,int y){
        int gcd = 1;
        if(x%y==0){
            return y;
        }
        else if(y%x==0){
            return x;
        }
        else{
            for(int i=2;i<=x && i<=y;i++){
                if(x%i==0 && y%i==0){
                    gcd = i;
                }
            }
            return gcd;
        }
    }
    public static long calculate_factorial(long x){
        long ans = 1;
        for(int i=1;i<=x;i++){
            ans*=i;
        }
        return ans;
    }
    public static void swap(int a[], int b[], int index_a, int index_b){
        int temp = a[index_a];
        a[index_a] = b[index_b];
        b[index_b] = temp;
    }
    public static int find_maximum(int a[]){
        int max = Integer.MIN_VALUE;
        for(int i=0;i<a.length;i++){
            max = Math.max(a[i], max);
        }
        return max;
    }
    public static int find_minimum(int a[]){
        int min = Integer.MAX_VALUE;
        for(int i=0;i<a.length;i++){
            min = Math.min(a[i], min);
        }
        return min;
    }
    public static void ruffleSort(int[] a) {
        int n=a.length;//shuffle, then sort
        Random random = new Random();
        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n);
            int temp=a[oi];
            a[oi]=a[i]; 
            a[i]=temp;
        }
        Arrays.sort(a);
    }
    public static int sum_of_digits(int n){
        int s =0;
        while(n!=0){
            s+=n%10;
            n/=10;
        }
        return s;
    }
    public static int[] mergeSort(int[] array) {
        if (array.length <= 1) {
            return array;
        }

        int midpoint = array.length / 2;

        int[] left = new int[midpoint];
        int[] right;

        if (array.length % 2 == 0) {
            right = new int[midpoint];
        } else {
            right = new int[midpoint + 1];
        }

        for (int i = 0; i < left.length; i++) {
            left[i] = array[i];
        }

        for (int i = 0; i < right.length; i++) {
            right[i] = array[i + midpoint];
        }

        int[] result = new int[array.length];

        left = mergeSort(left);
        right = mergeSort(right);

        result = merge(left, right);

        return result;
    }

    public static int[] merge(int[] left, int[] right) {

        int[] result = new int[left.length + right.length];
        int leftPointer = 0, rightPointer = 0, resultPointer = 0;

        while (leftPointer < left.length || rightPointer < right.length) {

            if (leftPointer < left.length && rightPointer < right.length) {

                if (left[leftPointer] < right[rightPointer]) {
                    result[resultPointer++] = left[leftPointer++];
                } else {
                    result[resultPointer++] = right[rightPointer++];
                }
            } else if (leftPointer < left.length) {
                result[resultPointer++] = left[leftPointer++];
            } else {
                result[resultPointer++] = right[rightPointer++];
            }
        }
        return result;
    }
}