import java.io.*;
import java.util.*;

public class EvenorOdd {
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int n=Integer.parseInt(f.readLine());
		String s=f.readLine();
		String s2=f.readLine();
		TreeSet<Integer>[] arr=new TreeSet[27];
		TreeSet<Integer>[] barr=new TreeSet[27];
		for(int i=0;i<27;i++) {
			arr[i]=new TreeSet<Integer>();
			barr[i]=new TreeSet<Integer>();
		}
		for(int i=0;i<n;i++) {
			if(s.charAt(i)=='?') {
				arr[26].add(i+1);
			}
			else {
				arr[s.charAt(i)-97].add(i+1);
			}
			if(s2.charAt(i)=='?') {
				barr[26].add(i+1);
			}
			else {
				barr[s2.charAt(i)-97].add(i+1);
			}
		}
		int ans=0;
		StringBuffer sb=new StringBuffer();
		for(int i=0;i<26;i++) {
			while(!arr[i].isEmpty()&&!barr[i].isEmpty()) {
				ans++;
				sb.append(arr[i].pollFirst()+" "+barr[i].pollFirst()+"\n");
			}
		}
		for(int i=0;i<26;i++) {
			while(!arr[i].isEmpty()&&!barr[26].isEmpty()) {
				ans++;
				sb.append(arr[i].pollFirst()+" "+barr[26].pollFirst()+"\n");
			}
			while(!arr[26].isEmpty()&&!barr[i].isEmpty()) {
				ans++;
				sb.append(arr[26].pollFirst()+" "+barr[i].pollFirst()+"\n");
			}
		}
		while(!arr[26].isEmpty()&&!barr[26].isEmpty()) {
			ans++;
			sb.append(arr[26].pollFirst()+" "+barr[26].pollFirst()+"\n");
		}
		out.println(ans);
		out.println(sb.toString());
		out.close();
		f.close();
	}
}