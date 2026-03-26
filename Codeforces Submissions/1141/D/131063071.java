import java.io.*;
import java.util.*;
public class swapSort {
	
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
		int n =Integer.parseInt(br.readLine());
		String s1 = br.readLine();
		String s2 = br.readLine();
		HashMap<Character , Stack<Integer>> ri = new HashMap<>();
		Stack<Integer> q2=new Stack<>();
		Stack<Integer> q1=new Stack<>();
		boolean[] li = new boolean [n];
		for (int i=0;i<n;i++)
		{
			char ch = s2.charAt(i);
			if (ch=='?') {
				q2.push(i+1);
				continue;
			}
			if (!ri.containsKey(ch)) ri.put(ch , new Stack<Integer>());
			ri.get(ch).push((i+1));
		}
		StringBuilder res = new StringBuilder();
		long cnt = 0;
		
		for(int i=0;i<n;i++)
		{
			char ch = s1.charAt(i);
			if (ch=='?') {
				q1.push(i+1);
				li[i]=true; 
				continue;
			}
			if (ri.containsKey(ch) && !ri.get(ch).isEmpty())
			{
				li[i] = true;
				res.append((i+1)+" "+ri.get(ch).pop()+"\n");
				cnt++;
			}
		}
		for(char ch='a';!q1.isEmpty()&&ch<='z';)
		{
			
			if (!ri.containsKey(ch) || ri.get(ch).isEmpty()) ch++;
			else
			{
				res.append(q1.pop()+" "+ri.get(ch).pop()+"\n");
				cnt++;
			}
		}
		for (int i=0;!q2.isEmpty()&&i<n;i++)
		{
			if (!li[i])
			{
			res.append((i+1)+" "+q2.pop()+"\n");
			cnt++;
			}
		}
		while (!q1.isEmpty() && !q2.isEmpty())
		{
		res.append(q1.pop()+" "+q2.pop()+"\n");
		cnt++;
		}
		System.out.println(cnt);
		System.out.println(res);
	}
}