import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.lang.reflect.Array;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

import org.w3c.dom.NamedNodeMap;

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.*;


public class ispcff {

	public static void main(String[] args)  throws java.lang.Exception {
		ispcff.FastReader sc =new FastReader();
int n = sc.nextInt(); int m = sc.nextInt(); 
String arr[]=new String [n];
String arr1[]= new String [m];
for (int i=0;i<n;i++) {
	arr[i]= sc.next();
}
for (int i =0;i<m;i++) {
arr1[i]= sc.next();	
}

int r = sc.nextInt();
for (int e=0;e<r;e++) {
	int  y=sc.nextInt();
	int w = y%n;    int ww = y%m;
	if(w==0) {
		System.out.print(arr[n-1]);
	}
	else {
		System.out.print(arr[w-1]);
	}
	if(ww==0) {
		System.out.print(arr1[m-1]);
	}
	else {
		System.out.print(arr1[ww-1]);
	}
	System.out.println();
}
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
		
		static void reverse_sorted(int[] arr)
		{
		    ArrayList<Integer> list = new ArrayList<>();
		    for(int i=0;i<arr.length;i++)
		    {
		        list.add(arr[i]);
		    }
		    Collections.sort(list , Collections.reverseOrder());
		    for(int i=0;i<arr.length;i++)
		    {
		        arr[i] = list.get(i);
		    }
		}
		
		static int LowerBound(int a[], int x) { // x is the target value or key
	        int l=-1,r=a.length;
	        while(l+1<r) {
	            int m=(l+r)>>>1;
	            if(a[m]>=x) r=m;
	            else l=m;
	        }
	        return r;
	    }
	    
	    static int UpperBound(ArrayList<Integer> list, int x) {// x is the key or target value
	        int l=-1,r=list.size();
	        while(l+1<r) {
	            int m=(l+r)>>>1;
	            if(list.get(m)<=x) l=m;
	            else r=m;
	        }
	        return l+1;
	    }
	    
	    public static HashMap<String, Integer> sortByValue(HashMap<String, Integer> hm)
	    {
	        // Create a list from elements of HashMap
	        List<Map.Entry<String, Integer> > list =
	               new LinkedList<Map.Entry<String, Integer> >(hm.entrySet());
	 
	        // Sort the list
	        Collections.sort(list, new Comparator<Map.Entry<String, Integer> >() {
	            public int compare(Map.Entry<String, Integer> o1,
	                               Map.Entry<String, Integer> o2)
	            {
	                return (o1.getValue()).compareTo(o2.getValue());
	            }
	        });
	         
	        // put data from sorted list to hashmap
	        HashMap<String, Integer> temp = new LinkedHashMap<String, Integer>();
	        for (Map.Entry<String, Integer> aa : list) {
	            temp.put(aa.getKey(), aa.getValue());
	        }
	        return temp;
	    }
	    
	    static class Queue_Pair implements Comparable<Queue_Pair> {
			int first , second;
			public Queue_Pair(int first, int second) {
				this.first=first;
				this.second=second;
			}
			public int compareTo(Queue_Pair o) {
				return Integer.compare(o.first, first);
			}
		}
	    
	    static void leftRotate(int arr[], int d, int n)
	    {
	        for (int i = 0; i < d; i++)
	            leftRotatebyOne(arr, n);
	    }
	 
	    static void leftRotatebyOne(int arr[], int n)
	    {
	        int i, temp;
	        temp = arr[0];
	        for (i = 0; i < n - 1; i++)
	            arr[i] = arr[i + 1];
	        arr[n-1] = temp;
	        
	    }
	    
	    static boolean isPalindrome(String str)
	    {
	 
	        // Pointers pointing to the beginning
	        // and the end of the string
	        int i = 0, j = str.length() - 1;
	 
	        // While there are characters to compare
	        while (i < j) {
	 
	            // If there is a mismatch
	            if (str.charAt(i) != str.charAt(j))
	                return false;
	 
	            // Increment first pointer and
	            // decrement the other
	            i++;
	            j--;
	        }
	 
	        // Given string is a palindrome
	        return true;
	    }
	    
	    static boolean palindrome_array(char arr[], int n)
	    {
	        // Initialise flag to zero.
	        int flag = 0;
	 
	        // Loop till array size n/2.
	        for (int i = 0; i <= n / 2 && n != 0; i++) {
	 
	            // Check if first and last element are different
	            // Then set flag to 1.
	            if (arr[i] != arr[n - i - 1]) {
	                flag = 1;
	                break;
	            }
	        }
	 
	        // If flag is set then print Not Palindrome
	        // else print Palindrome.
	        if (flag == 1)
	            return false;
	        else
	            return true;
	    }
	    
		static boolean allElementsEqual(long[] arr,int n)
		{
		    int z=0;
		        for(int i=0;i<n-1;i++)
			    {
			        if(arr[i]==arr[i+1])
			        {
			            z++;
			        }
			    }
			    if(z==n-1)
			    {
			        return true;
			    }
			    else
			    {
			        return false;
			    }
			    
		}
		
		static boolean allElementsDistinct(int[] arr,int n)
		{
		    int z=0;
		        for(int i=0;i<n-1;i++)
			    {
			        if(arr[i]!=arr[i+1])
			        {
			            z++;
			        }
			    }
			    if(z==n-1)
			    {
			        return true;
			    }
			    else
			    {
			        return false;
			    }
			    
			    
		}
		
		public static void reverse(int[] array)
	    {
	  
	        // Length of the array
	        int n = array.length;
	  
	        // Swaping the first half elements with last half
	        // elements
	        for (int i = 0; i < n / 2; i++) {
	  
	            // Storing the first half elements temporarily
	            int temp = array[i];
	  
	            // Assigning the first half to the last half
	            array[i] = array[n - i - 1];
	  
	            // Assigning the last half to the first half
	            array[n - i - 1] = temp;
	        }
	    }
	    
	    public static void reverse_Long(long[] array)
	    {
	  
	        // Length of the array
	        int n = array.length;
	  
	        // Swaping the first half elements with last half
	        // elements
	        for (int i = 0; i < n / 2; i++) {
	  
	            // Storing the first half elements temporarily
	            long temp = array[i];
	  
	            // Assigning the first half to the last half
	            array[i] = array[n - i - 1];
	  
	            // Assigning the last half to the first half
	            array[n - i - 1] = temp;
	        }
	    }
		
		static boolean isSorted(int[] a)
	    {
	        for (int i = 0; i < a.length - 1; i++)
	        {
	            if (a[i] > a[i + 1]) {
	                return false;
	            }
	        }
	 
	        return true;
	    }
	    
	    
	    
	    static boolean isReverseSorted(int[] a)
	    {
	        for (int i = 0; i < a.length - 1; i++)
	        {
	            if (a[i] < a[i + 1]) {
	                return false;
	            }
	        }
	 
	        return true;
	    }
	    
	    static int[] rearrangeEvenAndOdd(int arr[], int n)
	    {
	        ArrayList<Integer> list = new ArrayList<>();
			    
			    for(int i=0;i<n;i++)
			    {
			        if(arr[i]%2==0)
			        {
			            list.add(arr[i]);
			        }
			    }
			    
			    for(int i=0;i<n;i++)
			    {
			        if(arr[i]%2!=0)
			        {
			            list.add(arr[i]);
			        }
			    }
			    int len = list.size();
			    int[] array = list.stream().mapToInt(i->i).toArray();
			    return array;
	    }
	    
	    static long[] rearrangeEvenAndOddLong(long arr[], int n)
	    {
	        ArrayList<Long> list = new ArrayList<>();
			    
			    for(int i=0;i<n;i++)
			    {
			        if(arr[i]%2==0)
			        {
			            list.add(arr[i]);
			        }
			    }
			    
			    for(int i=0;i<n;i++)
			    {
			        if(arr[i]%2!=0)
			        {
			            list.add(arr[i]);
			        }
			    }
			    int len = list.size();
			    long[] array = list.stream().mapToLong(i->i).toArray();
			    return array;
	    }
		
		
	    
	    static boolean isPrime(long n)
	    {
	 
	        // Check if number is less than
	        // equal to 1
	        if (n <= 1)
	            return false;
	 
	        // Check if number is 2
	        else if (n == 2)
	            return true;
	 
	        // Check if n is a multiple of 2
	        else if (n % 2 == 0)
	            return false;
	 
	        // If not, then just check the odds
	        for (long i = 3; i <= Math.sqrt(n); i += 2)
	        {
	            if (n % i == 0)
	                return false;
	        }
	        return true;
	    }
	    
	    static long getSum(long n)
	    {    
	        long sum = 0;
	          
	        while (n != 0)
	        {
	            sum = sum + n % 10;
	            n = n/10;
	        }
	      
	    return sum;
	    }
	    
	    static int gcd(int a, int b)
	    {
	      if (b == 0)
	        return a;
	      return gcd(b, a % b);
	    }
	     
	    static long gcdLong(long a, long b)
	    {
	        if (b == 0)
	        return a;
	      return gcdLong(b, a % b);
	    }
	    
	    static void swap(int i, int j)
	    {
	        int temp = i;
	        i = j;
	        j = temp;
	    }
		
		static int countDigit(int n)
	    {
	        return (int)Math.floor(Math.log10(n) + 1);
	    }
		
	









//Arrays.sort(arr, Comparator.comparingDouble(o -> o[0]));
//        					q.replace(i, i+1, "4");
//		StringBuilder q = new StringBuilder(w);























	}