import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
    static long mod = (int)1e9+7;
    static PrintWriter out=new PrintWriter(new BufferedOutputStream(System.out));
    public static void main (String[] args) throws java.lang.Exception
    {
        FastReader sc =new FastReader();

        int t=sc.nextInt();
   
    //   int t=1;
   
        O : while(t-->0)
        {
            int n=sc.nextInt();
	        int a[]=sc.readArray(n);
	        boolean gone[]=new boolean[2*n+1];
	        ArrayList<Integer> list=new ArrayList<>();
	        for(int i=0;i<n;i++){
	            gone[a[i]]=true;
	        }
	        for(int i=0;i<n;i++){
	            for(int j=a[i]+1;j<=2*n;j++){
	                if(!gone[j]){
	                    list.add(a[i]);
	                    list.add(j);
	                    gone[j]=true;
	                    break;
	                }
	            }
	        }
	        if(list.size()!=2*n){
	            System.out.println(-1);
	        }
	        else{
	            for(int i=0;i<list.size();i++){
	                System.out.print(list.get(i)+" ");
	            }
	            System.out.println();
	        }
        }
        out.flush();
    }
            
static void printN()
{
    System.out.println("NO");
}
static void printY()
{
    System.out.println("YES");
}

static int findfrequencies(int a[],int n)
{
    int count=0;
    for(int i=0;i<a.length;i++)
    {
        if(a[i]==n)
        {
            count++;
        }
    }
    return count;
}

static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
       
        float nextFloat()
        {
            return Float.parseFloat(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
       
        int[] readArray(int n) {
int[] a=new int[n];
for (int i=0; i<n; i++) a[i]=nextInt();
return a;
}

long[] readArrayLong(int n) {
long[] a=new long[n];
for (int i=0; i<n; i++) a[i]=nextLong();
return a;
}

    }
   
    public static int[] radixSort2(int[] a)
{
int n = a.length;
int[] c0 = new int[0x101];
int[] c1 = new int[0x101];
int[] c2 = new int[0x101];
int[] c3 = new int[0x101];
for(int v : a) {
c0[(v&0xff)+1]++;
c1[(v>>>8&0xff)+1]++;
c2[(v>>>16&0xff)+1]++;
c3[(v>>>24^0x80)+1]++;
}
for(int i = 0;i < 0xff;i++) {
c0[i+1] += c0[i];
c1[i+1] += c1[i];
c2[i+1] += c2[i];
c3[i+1] += c3[i];
}
int[] t = new int[n];
for(int v : a)t[c0[v&0xff]++] = v;
for(int v : t)a[c1[v>>>8&0xff]++] = v;
for(int v : a)t[c2[v>>>16&0xff]++] = v;
for(int v : t)a[c3[v>>>24^0x80]++] = v;
return a;
}

static int[] EvenOddArragement(int nums[])
{
    int i1=0,i2=nums.length-1;
        while(i1<i2){
            while(nums[i1]%2==0 && i1<i2){
                i1++;
            }
            while(nums[i2]%2!=0 && i2>i1){
                i2--;
            }
            int temp=nums[i1];
            nums[i1]=nums[i2];
            nums[i2]=temp;
        }
        return nums;
}
static int gcd(int a, int b) {
    while (b != 0) {
        int t = a;
        a = b;
        b = t % b;
    }
    return a;
}
    static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
   
    public static HashMap<Integer, Integer> sortByValue(HashMap<Integer, Integer> hm)
    {
        // Create a list from elements of HashMap
        List<Map.Entry<Integer, Integer> > list =
               new LinkedList<Map.Entry<Integer, Integer> >(hm.entrySet());
 
        // Sort the list
        Collections.sort(list, new Comparator<Map.Entry<Integer, Integer> >() {
            public int compare(Map.Entry<Integer, Integer> o1,
                               Map.Entry<Integer, Integer> o2)
            {
                return (o1.getValue()).compareTo(o2.getValue());
            }
        });
         
        // put data from sorted list to hashmap
        HashMap<Integer, Integer> temp = new LinkedHashMap<Integer, Integer>();
        for (Map.Entry<Integer, Integer> aa : list) {
            temp.put(aa.getKey(), aa.getValue());
        }
        return temp;
    }
    static int DigitSum(int n)
    {
        int r=0,sum=0;
        while(n>=0)
        {
            r=n%10;
            sum=sum+r;
            n=n/10;
        }
        return sum;
    }
    static boolean checkPerfectSquare(int number)    
    {   
        double sqrt=Math.sqrt(number);   
        return ((sqrt - Math.floor(sqrt)) == 0);   
    }  
    static boolean isPowerOfTwo(int n)
    {
        if(n==0)
        return false;
 
        return (int)(Math.ceil((Math.log(n) / Math.log(2)))) == (int)(Math.floor(((Math.log(n) / Math.log(2)))));
    }
    static boolean isPrime2(int n) 
    {
        if (n <= 1) 
        {
            return false;
        }
        if (n == 2) 
        {
            return true;
        }
        if (n % 2 == 0) 
        {
            return false;
        }
        for (int i = 3; i <= Math.sqrt(n) + 1; i = i + 2) 
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    static String minLexRotation(String str)
    {
        int n = str.length();
        String arr[] = new String[n];
        String concat = str + str;
        for(int i=0;i<n;i++)
        {
            arr[i] = concat.substring(i, i + n);
        }
        Arrays.sort(arr);
        return arr[0];
    }
 
static String maxLexRotation(String str)
    {
        int n = str.length();
        String arr[] = new String[n];
        String concat = str + str;
        for (int i = 0; i < n; i++)
        {
            arr[i] = concat.substring(i, i + n);
        }
        Arrays.sort(arr);
        return arr[arr.length-1];
    }
    static class P implements Comparable<P> {
		int i, j;
		public P(int i, int j) {
			this.i=i;
			this.j=j;
		}
		public int compareTo(P o) {
			return Integer.compare(i, o.i);
		}
	}
	static class pair{
	    int i,j;
	    pair(int x,int y){
	        i=x;
	        j=y;
	    }
	}
	static int binary_search(int a[],int value)
	{
	    int start=0;
	    int end=a.length-1;
	    int mid=start+(end-start)/2;
	    while(start<=end)
	    {
	        if(a[mid]==value)
	        {
	            return mid;
	        }
	        if(a[mid]>value)
	        {
	            end=mid-1;
	        }
	        else
	        {
	            start=mid+1;
	        }
	        mid=start+(end-start)/2;
	    }
	    return -1;
	}
}