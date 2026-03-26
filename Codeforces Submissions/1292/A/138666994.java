
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
public class codeee
{		//public static int mod=1000000007;
	public static ArrayList<Integer> Factors(int n)
    {
		ArrayList<Integer> arr=new ArrayList<Integer>();
        int k=0;
        while (n%2==0)
        {
            k++;
            n /=2;
            arr.add(2);
        }
	int p=(int) Math.sqrt(n); 
        for (int i = 3; i <=p; i+= 2)
        
        {  if(n==1)break;
            while (n%i == 0)
            {
                k++;
                arr.add(i);
                n /= i;
            }
        }
        if (n > 2)
        {
        	arr.add(n);
        }
           
 //arr.add(1);
   return arr;
    } 
	static class Reader {
		 
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
	 public static long gcd(long x, long p)
	    {
	        if (x == 0)
	            return p;
	         
	        return gcd(p%x, x);
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
	 static int sieve =  1000000 ;


	 static boolean[] prime =  new boolean[sieve + 1] ;

	 public static void sieveOfEratosthenes() 
	     { 
	         // FALSE == prime and 1 // TRUE ==  COMPOSITE
	         
	         // time complexity = 0(NlogLogN)== o(N)
	         
	         // gives prime nos bw 1 to N // size - 1e7(at max)
	         
	         for(int i = 4; i<= sieve ; i++)
	         {
	             prime[i] = true  ; i++ ;
	            
	         }
	         
	         for(int p = 3; p*p <= sieve; p++) 
	         { 
	            if(prime[p] == false) 
	             { 
	                     for(int i = p*p; i <= sieve; i += p) 
	                     prime[i] = true; 
	             } 
	             
	             p++ ;
	         } 
	           
	     } 
	 public static void arrInpInt(int [] arr, int n) throws IOException
	 {
		 Reader reader = new Reader();
		 for(int i=0;i<n;i++)
	   		{
	   			arr[i]=reader.nextInt();	
	   		}
	 }
	 public static void arrInpLong(long [] arr, int n) throws IOException
	 {
		 Reader reader = new Reader();
		 for(int i=0;i<n;i++)
	   		{
	   			arr[i]=reader.nextLong();	
	   		}
	 }
	 public static void printArr(int[] arr)
	 {
		 for(int i=0;i<arr.length;i++)
		 {
			 System.out.print(arr[i]+" ");
		 }
		 System.out.println();
	 }
	 public static int[] decSort(int[] arr)
	 {
		  int[] arr1 = Arrays.stream(arr).boxed().sorted(Collections.reverseOrder()).mapToInt(Integer::intValue).toArray();	
		  return arr1;
	 }
	 
	
	//if present - return the first occurrence of the no
	//not present- return the index of next greater value 
	//if greater than all the values return N(taking high=N-1)
	//if smaller than all the values return 0(taking low =0)
	static int lower_bound(int arr[], int low,int high, int X)
	{

	 if (low > high) {
	     return low;
	 }
	 int mid = low + (high - low) / 2;
	 if (arr[mid] >= X) {
	     return lower_bound(arr, low,
	                        mid - 1, X);
	 }

	 return lower_bound(arr, mid + 1,
	                    high, X);
	}
	//if present - return the index of next greater value
	//not present- return the index of next greater value 
	//if greater than all the values return N(taking high=N-1)
	//if smaller than all the values return 0(taking low =0)\
	
	static int upper_bound(int arr[], int low, int high, int X)
{

if (low > high)
    return low;

int mid = low + (high - low) / 2;
if (arr[mid] <= X) {
    return upper_bound(arr, mid + 1,
                       high, X);
}

return upper_bound(arr, low,
                   mid - 1, X);
}
	
	
	 public static class Pair  {// comparator with class
		    int x;
		    int y;
		 public Pair(int x, int y)
		    {
		        this.x = x;
		        this.y = y;
		    }
		}
	
	 public static void sortbyColumn(int arr[][], int col)  // send 2d array and col no
	    {
	        Arrays.sort(arr, new Comparator<int[]>() {       
	          @Override              
	          public int compare(final int[] entry1, 
	                             final int[] entry2) {
	            if (entry1[col] > entry2[col])
	                return 1;
	            else if (entry1[col] < entry2[col])
	                return -1;
	              else return 0;
	          }
	        });
	    }
	 public static void sortbyColumn1(int arr[][], int col)  // send 2d array and col no
	    {
	        Arrays.sort(arr, new Comparator<int[]>() {       
	          @Override              
	          public int compare(final int[] entry1, 
	                             final int[] entry2) {
	            if (entry1[col] > entry2[col])
	                return 1;
	            else if (entry1[col] < entry2[col])
	                return -1;
	            else if(entry1[col] == entry2[col])
	            {
	            	if(entry1[col-1]>entry2[col-1])
	            		return -1;
	            	else if(entry1[col-1]<entry2[col-1])
	            		return 1;
	            	else return 0;
	            }
	              else return 0;
	          }
	        });
	    }
	 public static void print2D(int mat[][])
	    {
	        // Loop through all rows
	        for (int i = 0; i < mat.length; i++)
	 
	        {  // Loop through all elements of current row
	        {
	            for (int j = 0; j < mat[i].length; j++)
	                System.out.print(mat[i][j] + " ");
	        }
	            System.out.println();
	        }
	    }
	 public static int biggestFactor(int num) {
		  int  result = 1;
		  for(int  i=2; i*i <=num; i++){
		      if(num%i==0){
		          result = num/i;
		          break;
		      }
		  }
		  return result;
		}
	    public static class  p
	     {
	    	 int no;
	    	 int h;
	    	 public p(int no, long h)
	    	 {
	    		 this.no=no;
	    		 this.h=(int) h;
	    	 }
	     }
	    public static class  k
	     {
	    	 boolean inc;
	    	 int min;
	    	 int max;
	    	 public k(boolean inc,int min, int max)
	    	 {
	    		 this.inc=inc;
	    		 this.min=min;
	    		 this.max=max;
	    	 }
	     }
	    
	  static    class com implements Comparator<p>{
	            public int compare(p s1, p s2) {
	                if (s1.h > s2.h)
	                    return -1;
	                else if (s1.h < s2.h)
	                    return 1;
	                else if(s1.h==s2.h)
	                {
	                	if(s1.no>s2.no)return -1;
	                	else return 1;
	                }
	                                return 0;
	                }
	        }
	  static long hcf(long a,long b)
	  {
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b; 
	        a = temp;
	    }
	    return a;
	   }
	  
	 static int lower_bound_arr(ArrayList<Integer> arr, int low,
	             int high, int X)
	{

	 if (low > high) {
	     return low;
	 }
	 int mid = low + (high - low) / 2;
	 if (arr.get(mid) >= X) {
	     return lower_bound_arr(arr, low,
	                        mid - 1, X);
	 }

	 return lower_bound_arr(arr, mid + 1,
	                    high, X);
	}
	
	 
 	public static void main(String args[]) throws NumberFormatException, IOException ,java.lang.Exception
	{
		
		Reader reader = new Reader();
 	
			
		//sieveOfEratosthenes();
		//System.out.println(prime[0]+" "+prime[1]+" "+prime[2]+" "+prime[3]+" "+prime[4]);
		//Scanner reader=new Scanner(System.in);
		
//	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//		int cases=Integer.parseInt(br.readLine());
		int cases=1;
	//BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
	//	int cases=reader.nextInt();
		
   	while (cases-->0){
   		
   		long V=reader.nextLong();
   		long C=reader.nextLong();
   		//long N=reader.nextLong();
   		//long M=reader.nextLong();
   		
   		//int N=reader.nextInt();
   		//int G=reader.nextInt();
   		//int B=reader.nextInt();
   		//BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
   		// int P=reader.nextInt();
   		//int[][] arr=new int[N][N];
   		//int K=reader.nextInt();
   		//int X=reader.nextInt();
   		//int K=reader.nextInt();
   		//int S=reader.nextInt();
   		//int circum=reader.nextInt();
   		//int K=reader.nextInt();
//   		String[] firs=br.readLine().split(" ");
//     	int N=Integer.parseInt(firs[0]);
   		//char p=first[1].charAt(0);
   		//int P=Integer.parseInt(first[1]);
   		//int K=Integer.parseInt(first[2]);
   		//String[] first=br.readLine().split(" ");
   		//int N=Integer.parseInt(first[0]);
   		//int K=Integer.parseInt(first[1]);
   		//int X=reader.nextInt();
   		//int Y=reader.nextInt();
   		//String s2=br.readLine();
//   		String s3=br.readLine();
//   		char[]  s11=s2.toCharArray();
//	    char[]  s12=new char[s11.length];
   		
   		//String[] first1=br.readLine().split(" ");
   		//int C=Integer.parseInt(first1[0]);
   		//int C1=Integer.parseInt(first1[1]);
   		//char[]  s12=s3.toCharArray();
    	//int max=Integer.MIN_VALUE;
   		//int min=Integer.MAX_VALUE;
   		//int ind=-1;
   		HashMap<String,Integer> map=new HashMap<String,Integer>();
   		HashMap<String,Integer> map1=new HashMap<String,Integer>();
   		//HashMap<Character,Integer> path=new HashMap<Character,Integer>();
   		//TreeMap<Integer,Integer> map=new TreeMap<Integer,Integer>(Collections.reverseOrder());
  		//HashSet<Long> left =new HashSet<Long>();
//   		HashSet<Integer> right =new HashSet<Integer>();
   		//TreeSet<Integer> a =new TreeSet<Integer>();
   		//TreeSet<Long> b =new TreeSet<Long>();
   		//TreeSet<Integer> map=new TreeSet<Integer>();
		
//   		int[] arr=new int[N];
   		//Integer[] arr=new Integer[s11.length];
   	//	Integer[] diff=new Integer[N];
//   		int[] diff=new int[N];
//   		int[] arr1= {2,3,5,7,11,13,17,19,23,29,31};
   		//Integer[] arr2=new Integer[N];
   		//boolean[]arr1=new boolean[N];
//   		long[] arr=new long[N];

//   		ArrayList<Integer> k=new ArrayList<Integer>();
   		//ArrayList<Integer> arr1=new ArrayList<Integer>();
   		//int [][] arr=new int[N][5];
        //System.out.println(map);
   		//PriorityQueue<p> Q=new PriorityQueue<p>(new com());
   		//PriorityQueue<Long> w=new PriorityQueue<Long>();
   		
   		//int min=Integer.MAX_VALUE;
   		
   		//ArrayList<ArrayList<Integer>> arr1=new ArrayList<ArrayList<Ineteger>>();
   		//System.out.println();
   		
   		//System.out.println(zero+" "+one);
   		
   	
	
   		
   		//System.out.println(Arrays.toString(arr2));
   	
   		for(int i=0;i<C;i++)
   		{
   			int x=reader.nextInt();
   			int y=reader.nextInt();
   			if(map.containsKey(x+","+y))
   			{
   				String p=x+","+y;
   				
   				if(x==1)
   				{
   					String k1=p+"+2,"+(y-1);
   					String k2=p+"+2,"+y;
   					String k3=p+"+2,"+(y+1);
   					String k11="2,"+(y-1)+"+"+p;
   					String k12="2,"+y+"+"+p;
   					String k13="2,"+(y+1)+"+"+p;
   					if(map1.containsKey(k1))map1.remove(k1);
   					if(map1.containsKey(k2))map1.remove(k2);
   					if(map1.containsKey(k3))map1.remove(k3);
   					if(map1.containsKey(k11))map1.remove(k11);
   					if(map1.containsKey(k12))map1.remove(k12);
   					if(map1.containsKey(k13))map1.remove(k13);
   				}
   				else 
   				{
   					String k1=p+"+1,"+(y-1);
   					String k2=p+"+1,"+y;
   					String k3=p+"+1,"+(y+1);
   					String k11="1,"+(y-1)+"+"+p;
   					String k12="1,"+y+"+"+p;
   					String k13="1,"+(y+1)+"+"+p;
   					if(map1.containsKey(k1))map1.remove(k1);
   					if(map1.containsKey(k2))map1.remove(k2);
   					if(map1.containsKey(k3))map1.remove(k3);
   					if(map1.containsKey(k11))map1.remove(k11);
   					if(map1.containsKey(k12))map1.remove(k12);
   					if(map1.containsKey(k13))map1.remove(k13);
   				}
   				map.remove(p);
   			}
   			else
   			{
   				map.put(x+","+y, 1);
   				String p=x+","+y;
   				if(x==1)
   				{
   					String k1="2,"+(y-1);
   					String k2="2,"+y;
   					String k3="2,"+(y+1);
   					String k11=p+"+2,"+(y-1);
   					String k21=p+"+2,"+y;
   					String k31=p+"+2,"+(y+1);
   					
   					if(map.containsKey(k1))map1.put(k11,1);
   					if(map.containsKey(k2))map1.put(k21,1);
   					if(map.containsKey(k3))map1.put(k31,1);
   				}
   				else 
   				{
   					String k1="1,"+(y-1);
   					String k2="1,"+y;
   					String k3="1,"+(y+1);
   					String k11=p+"+1,"+(y-1);
   					String k21=p+"+1,"+y;
   					String k31=p+"+1,"+(y+1);
   					
   					if(map.containsKey(k1))map1.put(k11,1);
   					if(map.containsKey(k2))map1.put(k21,1);
   					if(map.containsKey(k3))map1.put(k31,1);
   				}
   			}
//   			System.out.println(map1);
//   			System.out.println(map);
   			if(map1.isEmpty())System.out.println("YES");
   			else System.out.println("NO");
   		}
   		
   		
   		
   }
 }	
   	
}
   	