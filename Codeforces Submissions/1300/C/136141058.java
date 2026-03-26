import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;

public class AnuHasaFunction {
    
    // static int mod = 998244353;
    static int mod = 1000000007;

    public static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(
                new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
 
        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
 
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
 
            if (neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0,
                                 BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }

    public static void main(String[] args) throws Exception {
        Reader scn = new Reader();
        PrintWriter pw = new PrintWriter(System.out);
        int t = 1;
        outer : while(t-->0){
            int n = scn.nextInt();
            int[] arr = new int[n];
            for(int i=0; i<n; i++){
            	arr[i] = scn.nextInt();
            }
            if(n == 1){
            	pw.println(arr[0]);
            	continue outer;
            }
            int[] pref = new int[n];
            int[] suff = new int[n];
            pref[0] = (~arr[0]);
            suff[n-1] = (~arr[n-1]);
            for(int i=1; i<n; i++){
            	pref[i] = ((~arr[i]) & pref[i-1]);
            } 
            for(int i=n-2; i>=0; i--){
            	suff[i] = ((~arr[i]) & suff[i+1]);
            }
            int elem1 = (arr[0] & suff[1]);
            int elem2 = (arr[n-1] & pref[n-2]);
            int max = Math.max(elem1, elem2);
            for(int i=1; i<n-1; i++){
            	int elem = (arr[i] & (pref[i-1] & suff[i+1]));
            	max = Math.max(max, elem);
            }
            if(elem1 == max){
            	pw.print(arr[0] + " ");
            	for(int i=1; i<n; i++){
            		pw.print(arr[i] + " ");
            	}
            	pw.println();
            	continue outer;
            }
            if(elem2 == max){
            	pw.print(arr[n-1] + " ");
            	for(int i=0; i<n-1; i++){
            		pw.print(arr[i] + " ");
            	}
            	pw.println();
            	continue outer;
            }
            int index = -1;
            for(int i=1; i<=n-1; i++){
            	int elem = (arr[i] & (pref[i-1] & suff[i+1]));
            	if(elem == max){
           			index = i;
           			pw.print(arr[i] + " ");
           			for(int j=0; j<n; j++){
           				if(j == index){
           					continue;
           				}else{
           					pw.print(arr[j] + " ");
           				}
           			}
           			pw.println();
           			continue outer;
            	}
            }
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