import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;


public class Main{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int testcase=sc.nextInt();
        for(int tc=1;tc<=testcase;tc++){
          //System.out.print("Case #"+tc+": ");
          int n = sc.nextInt();
          int a[] = new int[n];
          long sum = 0, max = 0;
          for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
            sum += a[i];
          }
          int b[] = Arrays.copyOf(a, n);
          int c[] = Arrays.copyOf(a, n);
          b[0] = 0;
          c[n-1] = 0;
          max = Math.max(maxSubArraySum(b), maxSubArraySum(c));
          if(sum > max)
            System.out.println("YES");
          else
            System.out.println("NO");
        }
        sc.close();
    }
    static long maxSubArraySum(int a[])
    {
        int size = a.length;
        long max_so_far = Long.MIN_VALUE, max_ending_here
                                            = 0;
 
        for (int i = 0; i < size; i++) {
            max_ending_here = max_ending_here + a[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }
    static long fact(long n)
    {
    
    // single line to find factorial
    return (n == 1 || n == 0) ? 1 : n * fact(n - 1);
    
    }
    static boolean isSorted(int a[]){
      for(int i=1;i<a.length;i++){
        if(a[i] < a[i-1])
          return false;
      }
      return true;
    }
    static int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
    static int upper_bound(int[] arr, int key, int i)
    {
      if(Arrays.binarySearch(arr, key) >= 0)
        return Arrays.binarySearch(arr, key);
      int mid, N = arr.length;
      
        // Initialise starting index and
        // ending index
        int low = 0;
        int high = i;
  
        // Till low is less than high
        while (low < high && low != N) {
            // Find the index of the middle element
            mid = low + (high - low) / 2;
  
            // If key is greater than or equal
            // to arr[mid], then find in
            // right subarray
            if (key >= arr[mid]) {
                low = mid + 1;
            }
  
            // If key is less than arr[mid]
            // then find in left subarray
            else {
                high = mid;
            }
        }
  
        return low;
    }
    static int lower_bound(int[] arr, int key, int i)
    {
      if(Arrays.binarySearch(arr, key) >= 0)
      return Arrays.binarySearch(arr, key);
        // Initialize starting index and
        // ending index
        int low = 0, high = i;
        int mid;
 
        // Till high does not crosses low
        while (low < high) {
 
            // Find the index of the middle element
            mid = low + (high - low) / 2;
 
            // If key is less than or equal
            // to array[mid], then find in
            // left subarray
            if (key <= arr[mid]) {
                high = mid;
            }
 
            // If key is greater than array[mid],
            // then find in right subarray
            else {
 
                low = mid + 1;
            }
        }
        return low;
    }
    static boolean palin(int arr[], int i, int j){
      while(i < j){
        if(arr[i] != arr[j])
          return false;
        i++;
        j--;
      }
      return true;
    }
    static boolean palin(String s){
      int i=0,j=s.length()-1;
      while(i<j){
        if(s.charAt(i)!=s.charAt(j))
          return false;
        i++;
        j--;
      }
      return true;
    }
    static long minSum(int arr[], int n, int k)
    {
        // k must be smaller than n
        if (n < k)
        {
          // System.out.println("Invalid");
           return -1;
        }
      
        // Compute sum of first window of size k
        long res = 0;
        for (int i=0; i<k; i++)
           res += arr[i];
      
        // Compute sums of remaining windows by
        // removing first element of previous
        // window and adding last element of
        // current window.
        long curr_sum = res;
        for (int i=k; i<n; i++)
        {
           curr_sum += arr[i] - arr[i-k];
           res = Math.min(res, curr_sum);
        }
      
        return res;
    }
    static int nextIndex(int a[], int x){
      int n=a.length;
      for(int i=x;i<n-1;i++){
        if(a[i]>a[i+1]){
          return i;
        }
      }
      return n;
    }
    static void rev(int a[], int i, int j){
      while(i<j){
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;
        j--;
      }
    }
    static int sorted(int arr[], int n)
    {
        // Array has one or no element or the
        // rest are already checked and approved.
        if (n == 1 || n == 0)
            return 1;
 
        // Unsorted pair found (Equal values allowed)
        if (arr[n - 1] < arr[n - 2])
            return 0;
 
        // Last pair was sorted
        // Keep on checking
        return sorted(arr, n - 1);
    }
    static void sieveOfEratosthenes(int n, int a[])
    {
      for(int i=2;i<=n;i++){
        a[i]=1;
      }
      for(int i=2;i<=1000;i++){
        for(int j=2*i;j<=n;j+=i){
          a[j]=0;
        }
      }
    }
    static boolean isPowerOfTwo(int n)
    {
        return (int)(Math.ceil((Math.log(n) / Math.log(2))))
            == (int)(Math.floor(((Math.log(n) / Math.log(2)))));
    }
    static int countBits(int number)
    {
         
        // log function in base 2
        // take only integer part
        return (int)(Math.log(number) /
                     Math.log(2) + 1);
    }
    public static void swap(int ans[], int i, int j) {
        int temp=ans[i];
        ans[i]=ans[j];
        ans[j]=temp;
    }

    static int power(int x, int y, int p)
  {
    int res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    if (x == 0)
      return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
 
      // If y is odd, multiply x with result
      if ((y & 1) != 0)
        res = (res * x) % p;
 
      // y must be even now
      y = y >> 1; // y = y/2
      x = (x * x) % p;
    }
    return res;
  }
}