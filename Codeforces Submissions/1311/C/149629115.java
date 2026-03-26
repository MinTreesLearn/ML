import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class class15 {static class FastReader {
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
}
static long gcd(long a,long b)
{
	if(a==0)
	{
		return b;
	}
	return gcd(b%a,a);
}
static long findgcd(long a[])
{
	long result=0;
	for(long val:a)
	{
		result=gcd(result,val);
		if(result==1)
		{
			return 1;
		}
	}
	return result;
}
public static void main(String arg[])
{
     Scanner input=new Scanner(System.in);
	int t=input.nextInt();
	while(t-->0) {
		int n=input.nextInt();
		int m=input.nextInt();
		int b[]=new int[n];
		int c[]=new int[26];
		String s=input.next();
		PriorityQueue<Integer>d=new PriorityQueue<>();
		Arrays.fill(b,1);
		for(int i=0;i<m;i++) {
			int temp=input.nextInt();
			d.add(temp);
		}
		int v=0;
		while(d.size()>0) {
			int temp=d.poll();
			if(v==temp) {
				continue;
			}
			else {
				int temp2=d.size()+1;
				for(int j=v;j<temp;j++) {
					b[j]=b[j]+temp2;
				}
				v=temp;
			}
		}
		for(int i=0;i<n;i++) {
			int j=(int)s.charAt(i)-97;
			c[j]=c[j]+b[i];
		}
		for(int i=0;i<26;i++) {
			System.out.print(c[i]+" ");
		}
		System.out.println();
}
}
}