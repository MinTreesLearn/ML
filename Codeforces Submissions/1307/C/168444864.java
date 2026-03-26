import java.util.*;
import java.io.*;

public class Main {
	public static Scanner obj = new Scanner(System.in);
	public static PrintWriter out = new PrintWriter(System.out);
    public static class Node
    {
    	int[] a=new int[27];
    }
	public static void main(String[] args) {
		int len = 1;
		while (len-- != 0) {
			String s=obj.next();
			int n=s.length();
			Node[] a=new Node[n+1];
			a[n]=new Node();
			for(int i=n-1;i>=0;i--)
			{
				a[i]=new Node();
				a[i].a[s.charAt(i)-'a']=1;
			    for(int j=0;j<27;j++) a[i].a[j]+=a[i+1].a[j];
			    
			}
			long ans=0;
			HashMap<String,Long> map=new HashMap<>();
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<26;j++)
				{
					StringBuffer sb=new StringBuffer();
					sb.append(s.charAt(i));
					sb.append((char)('a'+j));
					if(a[i+1].a[j]>0)map.put(sb.toString(), map.getOrDefault(sb.toString(), 0L)+a[i+1].a[j]);
				}
			}
			for(int i=0;i<27;i++)ans=Math.max(ans, a[0].a[i]);
			for(Map.Entry<String,Long> m:map.entrySet())
			{
				ans=Math.max(ans,m.getValue());
			}
			out.println(ans);
		}
		out.flush();
	}
}
