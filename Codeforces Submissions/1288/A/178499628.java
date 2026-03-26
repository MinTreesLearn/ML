
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.function.Supplier;
import java.util.stream.Collectors;

public class cf {
	
	//-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;
    public static int cnt;
    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;
    
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
    
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
    
        int nextInt() {
            return Integer.parseInt(next());
        }
    
        long nextLong() {
            return Long.parseLong(next());
        }
    
        double nextDouble() {
            return Double.parseDouble(next());
        }
    
        String nextLine(){
            String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
        }

		public void close() {
			// TODO Auto-generated method stub
			
		}
	        }
    
    static boolean pal(String s)
    {
    	StringBuilder sb=new StringBuilder();
    	sb.append(s);
    	sb.reverse();
    	String s1=sb.toString();
    	if(s1.contentEquals(s))
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
    
    static boolean isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
    public static int reverseBits(int n)
    {
        int rev = 0;
 
        // traversing bits of 'n'
        // from the right
        while (n > 0)
        {
            // bitwise left shift
            // 'rev' by 1
            rev <<= 1;
 
            // if current bit is '1'
            if ((int)(n & 1) == 1)
                rev ^= 1;
 
            // bitwise right shift
            //'n' by 1
            n >>= 1;
        }
        // required number
        return rev;
    }
    
    public static ArrayList<String> getSequence(String str)

    {
 

        // If 1
//    	string is empty

        if (str.length() == 0) {
 

            // Return an empty arraylist

            ArrayList<String> empty = new ArrayList<>();

            empty.add("");

            return empty;

        }
 

        // Take first character of str

        char ch = str.charAt(0);
 

        // Take sub-string starting from the

        // second character

        String subStr = str.substring(1);
 

        // Recursive call for all the sub-sequences 

        // starting from the second character

        ArrayList<String> subSequences = 

                              getSequence(subStr);
 

        // Add first character from str in the beginning

        // of every character from the sub-sequences

        // and then store it into the resultant arraylist

        ArrayList<String> res = new ArrayList<>();

        for (String val : subSequences) {

            res.add(val);

            res.add(ch + val);

        }
        return res;

    }
    static int fact(int n)
    {
    	int fact=1;
    	while(n>=1)
    	{
    		fact=fact*n;
    		n--;
    	}
    	return fact;
    }
    static long __gcd(long a, long b)
    {
        if (a == 0 || b == 0)
            return 0;
         
        if (a == b)
            return a;
         
        if (a > b)
            return __gcd(a-b, b);
                 
        return __gcd(a, b-a);
    }
    
    static boolean coprime(long a, long b) {
        
        if ( __gcd(a, b) == 1)
            return true;
        else
            return false;    
    }
    static int xor(int n,int a,int b)
    {
		if(n>0)
		{
			xor(n-1,b,a^b);
			return a^b;
		}
		else
		{
			return a^b;
		}
    }
    static ArrayList<ArrayList<Integer>> printSubArrays(int[] arr, int start, int end,ArrayList<ArrayList<Integer>> x)
    {
        if (end == arr.length)
        {
            return x;
        }
        else if (start > end)
        {
            printSubArrays(arr, 0, end + 1,x);
        }
        else 
        {
           ArrayList<Integer> x1=new ArrayList<Integer>();
            for (int i = start; i < end; i++)
            {
               x1.add(arr[i]);
            }
           x1.add(arr[end]);
           x.add(x1);
            printSubArrays(arr, start + 1, end,x);
        }
        return x;
    }
    
    public static ArrayList<ArrayList<Integer>> printSubsequences(int[] arr, int index,
            ArrayList<Integer> path)
{

// Print the subsequence when reach
// the leaf of recursion tree
		ArrayList<ArrayList<Integer>> x=new ArrayList<ArrayList<Integer>>(); 
if (index == arr.length)
{

// Condition to avoid printing
// empty subsequence
if (path.size() > 0)
x.add(path);
return x;
}

else
{

// Subsequence without including
// the element at current index
printSubsequences(arr, index + 1, path);

path.add(arr[index]);
x.add(path);
// Subsequence including the element
// at current index
printSubsequences(arr, index + 1, path);
x.add(path);

// Backtrack to remove the recently
// inserted element
path.remove(path.size() - 1);
x.add(path);
}
return x;
}
	public static void main(String[] args) 
	{
		MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
		int t=sc.nextInt();
		while(t-->0)
		{
			int n=sc.nextInt();
			int d=sc.nextInt();
			int x=1;
			boolean p=false;
			if(d>n)
			{
				while(x<=n)
				{
					long p1=d/(x+1);
					if(d%(x+1)!=0)
					{
						p1++;
					}
					if(x+p1<=n)
					{
						p=true;
						break;
					}
					x++;
				}
			}
			else
			{
				p=true;
			}
			if(p==true)
			{
				out.println("YES");
			}
			else
			{
				out.println("NO");
			}
		}
		out.close();
	}
}
