import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;

public class StringModification {
    
    // static int mod = 998244353;
    static int mod = 1000000007;

    private static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new
            InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) throws Exception {
        FastReader scn = new FastReader();
        PrintWriter pw = new PrintWriter(System.out);
        int t = scn.nextInt();
        outer : while(t-->0){
            int n = scn.nextInt();
            String s = scn.nextLine();
            String[] arr = new String[n+1];
            StringBuilder zero = new StringBuilder();
            for(int i=0; i<=n; i++){
            	zero.append("z");
            }
            arr[0] = zero.toString();
            arr[1] = s;
            arr[n] = reverseStr(s);
            for(int k=2; k<n; k++){
            	StringBuilder sb = new StringBuilder();
            	sb.append(s.substring(k-1));
            	int len = sb.length();
            	String ss = s.substring(0, k-1);
            	if(len % 2 == 1){
            		sb.append(reverseStr(ss));
            	}else{
            		sb.append(ss);	
            	}
            	arr[k] = sb.toString();
            }
            HashMap<String, Integer> hm = new HashMap<>();
            for(int i=n; i>=1; i--){
            	hm.put(arr[i], i);
            }
            Arrays.sort(arr);
            pw.println(arr[0]);
            pw.println(hm.get(arr[0]));
        }
        pw.close();
    }

    public static class Pair{
        int x;
        int y;

        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    private static void sort(int[] arr) {
        List<Integer> list = new ArrayList<>();
        for (int i=0; i<arr.length; i++){
            list.add(arr[i]);
        }
        Collections.sort(list); // collections.sort uses nlogn in backend
        for (int i = 0; i < arr.length; i++){
            arr[i] = list.get(i);
        }
    }

    private static void sort(long[] arr) {
        List<Long> list = new ArrayList<>();
        for(int i=0; i<arr.length; i++){
            list.add(arr[i]);
        }
        Collections.sort(list); // collections.sort uses nlogn in backend
        for (int i = 0; i < arr.length; i++){
            arr[i] = list.get(i);
        }
    }

    // private static void sort(Pair[] arr) {
    //     List<Pair> list = new ArrayList<>();
    //     for(int i=0; i<arr.length; i++){
    //         list.add(arr[i]);
    //     }
    //     Collections.sort(list); // collections.sort uses nlogn in backend
    //     for (int i = 0; i < arr.length; i++){
    //         arr[i] = list.get(i);
    //     }
    // }

    private static void reverseSort(int[] arr){
        List<Integer> list = new ArrayList<>();
        for (int i=0; i<arr.length; i++){
            list.add(arr[i]);
        }
        Collections.sort(list, Collections.reverseOrder()); // collections.sort uses nlogn in backend
        for (int i = 0; i < arr.length; i++){
            arr[i] = list.get(i);
        }
    }

    private static void reverseSort(long[] arr){
        List<Long> list = new ArrayList<>();
        for (int i=0; i<arr.length; i++){
            list.add(arr[i]);
        }
        Collections.sort(list, Collections.reverseOrder()); // collections.sort uses nlogn in backend
        for (int i = 0; i < arr.length; i++){
            arr[i] = list.get(i);
        }
    }

    private static void reverseSort(ArrayList<Integer> list){
        Collections.sort(list, Collections.reverseOrder());
    }

    private static int lowerBound(int[] arr, int x){
        int n = arr.length, si = 0, ei = n - 1;
        while(si <= ei){
            int mid = si + (ei - si)/2;
            if(arr[mid] == x){
                if(mid-1 >= 0 && arr[mid-1] == arr[mid]){
                    ei = mid-1;
                }else{
                    return mid;
                }
            }else if(arr[mid] > x){
                ei = mid - 1; 
            }else{
                si = mid+1;
            }
        }
        return si; 
    }

    private static int upperBound(int[] arr, int x){
        int n = arr.length, si = 0, ei = n - 1;
        while(si <= ei){
            int mid = si + (ei - si)/2;
            if(arr[mid] == x){
                if(mid+1 < n && arr[mid+1] == arr[mid]){
                    si = mid+1;
                }else{
                    return mid + 1;
                }
            }else if(arr[mid] > x){
                ei = mid - 1; 
            }else{
                si = mid+1;
            }
        }
        return si; 
    }

    private static int upperBound(ArrayList<Integer> list, int x){
        int n = list.size(), si = 0, ei = n - 1;
        while(si <= ei){
            int mid = si + (ei - si)/2;
            if(list.get(mid) == x){
                if(mid+1 < n && list.get(mid+1) == list.get(mid)){
                    si = mid+1;
                }else{
                    return mid + 1;
                }
            }else if(list.get(mid) > x){
                ei = mid - 1; 
            }else{
                si = mid+1;
            }
        }
        return si; 
    }

    // (x^y)%p in O(logy)
    private static long power(long x, long y){
        long res = 1; 
        x = x % mod;
        while(y > 0){
            if ((y & 1) == 1){
                res = (res * x) % mod;
            }
            y = y >> 1; 
            x = (x * x) % mod;
        }
        return res;
    }

    public static boolean nextPermutation(int[] arr) {
        if(arr == null || arr.length <= 1){
            return false;
        }
        
        int last = arr.length-2;
        while(last >= 0){
            if(arr[last] < arr[last+1]){
                break;
            }
            last--;
        }

        if (last < 0){
              return false;
        }
        
        if(last >= 0){
            int nextGreater = arr.length-1;
            for(int i=arr.length-1; i>last; i--){
                if(arr[i] > arr[last]){
                    nextGreater = i;
                    break;
                }
            }
            swap(arr, last, nextGreater);
        }
        
        reverse(arr, last+1, arr.length-1);
        return true;
    }
    
    private static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    private static void reverse(int[] arr, int i, int j){
        while(i < j){
            swap(arr, i++, j--);
        }
    }

    private static String reverseStr(String s){
        StringBuilder sb = new StringBuilder(s);
        return sb.reverse().toString();
    }

    // TC- O(logmax(a,b))
    private static int gcd(int a, int b) {
        if(a == 0){
            return b;
        }
        return gcd(b%a, a);
    }

    private static long gcd(long a, long b) {
        if(a == 0L){
            return b;
        }
        return gcd(b%a, a);
    }

    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    // TC- O(logmax(a,b))
    private static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    private static long inv(long x){
        return power(x, mod - 2);
    }

    private static long summation(long n){
        return (n * (n + 1L)) >> 1;
    } 
}