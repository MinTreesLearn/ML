import java.math.BigInteger;
import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int testcase=sc.nextInt();
        for(int tc=1;tc<=testcase;tc++){
          //System.out.print("Case #"+tc+": ");
          int n = sc.nextInt();
          int a[][] = new int[n][2];
          for(int i=0;i<n;i++){
            a[i][0] = sc.nextInt();
            a[i][1] = sc.nextInt();
          }
          Arrays.sort(a, (x,y) -> x[0]==y[0]? x[1]-y[1] : x[0]-y[0]);
          boolean f = true;
          for(int i=1;i<n;i++){
            if(a[i][1] < a[i-1][1]){
              f = false;
              break;
            }
          }
          if(!f){
            System.out.println("NO");
            continue;
          }
          System.out.println("YES");
          int x = 0, y= 0;
          for(int i=0;i<n;i++){
            while(x < a[i][0]){
              System.out.print("R");
              x++;
            }
            while(y < a[i][1]){
              System.out.print("U");
              y++;
            }
          }
          System.out.println();
        }
//         a,b=[{},{}] # two map
// for _ in range(int(input())):
//     s,x=list(input().split())
//     x=int(x)
//     if s=="+":
//         a[x]=True
//     else:
//         if x in b:
//             y=b[x]
//         else:
//             y=x
//         while y in a:
//             y+=x
//         b[x]=y
//         print(y)
        //}
        sc.close();
    }
    static int binarySearch(int arr[], int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;
 
            // If the element is present at the
            // middle itself
            if (arr[mid] == x)
                return mid;
 
            // If element is smaller than mid, then
            // it can only be present in left subarray
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
 
            // Else the element can only be present
            // in right subarray
            return binarySearch(arr, mid + 1, r, x);
        }
 
        // We reach here when element is not present
        // in array
        return -1;
    }
    static int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
     
    // method to return LCM of two numbers
    // static int lcm(int a, int b)
    // {
    //     return (a / gcd(a, b)) * b;
    // }
    static int upper_bound(int arr[], int key)
    {
        int mid, N = arr.length;
  
        // Initialise starting index and
        // ending index
        int low = 0;
        int high = N;
  
        // Till low is less than high
        while (low < high && low != N) {
            // Find the index of the middle element
            mid = low + (high - low) / 2;
            if(key == arr[mid]) {
              return mid;
            }
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
  
        // If key is greater than last element which is
        // array[n-1] then upper bound
        // does not exists in the array
        if (low > N ) {
            low--;     
        }
  
          // Print the upper_bound index
          return low;
      }
    static int lower_bound(int array[], int key)
    {
        // Initialize starting index and
        // ending index
        int low = 0, high = array.length;
        int mid;
 
        // Till high does not crosses low
        while (low < high) {
 
            // Find the index of the middle element
            mid = low + (high - low) / 2;
 
            // If key is less than or equal
            // to array[mid], then find in
            // left subarray
            if (key <= array[mid]) {
                high = mid;
            }
 
            // If key is greater than array[mid],
            // then find in right subarray
            else {
 
                low = mid + 1;
            }
        }
 
        // If key is greater than last element which is
        // array[n-1] then lower bound
        // does not exists in the array
        if(low==-1)
          low++;
 
        // Returning the lower_bound index
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
    static void sieveOfEratosthenes(int n, Set<Integer> set)
    {
        // Create a boolean array "prime[0..n]" and
        // initialize all entries it as true. A value in
        // prime[i] will finally be false if i is Not a
        // prime, else true.
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;
 
        for (int p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a
            // prime
            if (prime[p] == true) {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which
                // are multiple of p and are less than p^2
                // are already been marked.
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
 
        // Print all prime numbers
        for (int i = 2; i <= n; i++) {
            if (prime[i] == true)
                set.add(i);
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