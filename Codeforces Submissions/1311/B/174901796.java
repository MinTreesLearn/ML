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
import java.util.Map;
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
 

        // If string is empty

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

	public static void main(String[] args) 
	{
		MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
		StringBuilder sb = new StringBuilder();
		int t=sc.nextInt();
		while(t-->0)
		{
			int n=sc.nextInt();
			int m=sc.nextInt();
			long arr[]=new long[n];
			long brr[]=new long[m];
			for(int i=0;i<n;i++)
			{
				arr[i]=sc.nextLong();
			}
			for(int i=0;i<m;i++)
			{
				brr[i]=sc.nextLong();
			}
			ArrayList<Integer> x=new ArrayList<Integer>();
			Arrays.sort(brr);
			for(int i=0;i<m;i++)
			{
				int i1=(int) brr[i]-1;
				while(i+1<m &&brr[i+1]-brr[i]==1 )
				{
					i++;
				}
				int i2=(int)brr[i];
				if(i2>i1)
				{
					long crr[]=Arrays.copyOfRange(arr,i1, i2+1);
					Arrays.sort(crr);
					int k=0;
					for(int i3=i1;i3<=i2;i3++)
					{
						arr[i3]=crr[k];
						k++;
					}
				}
				else
				{
					long a=Math.max(arr[i1],arr[i1+1]);
					long b=Math.min(arr[i1],arr[i1+1]);
					arr[i1+1]=a;
					arr[i1]=b;
				}
			}
			long crr[]=Arrays.copyOf(arr, n);
			Arrays.sort(crr);
			if(Arrays.equals(arr,crr))
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