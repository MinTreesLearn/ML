import java.io.*;
import java.util.*;

/*


*/

public class A {
	static FastReader sc=null;
	
			
	public static void main(String[] args) {
		sc=new FastReader();
		PrintWriter out=new PrintWriter(System.out);
		char line[]=sc.next().toCharArray();
		int n=line.length;
		
		int q=sc.nextInt();
		int pre[][]=new int[n][26];
		pre[0][line[0]-'a']=1;
		for(int i=1;i<n;i++) 
			for(int j=0;j<26;j++)pre[i][j]=pre[i-1][j]+(line[i]==(char)(j+'a')?1:0);
		
		
		//for(Pair e:seg)System.out.println(e.l+" "+e.r);
		
		while(q-->0) {
			int l=sc.nextInt()-1,r=sc.nextInt()-1;
			
			int count=0;
			for(int i=0;i<26;i++)if(pre[r][i]!=pre[l][i])count++;
			
			if(line[l]!=line[r] || l==r || count>2)
				out.println("Yes");
			else 
				out.println("No");
			
		}
		out.close();
		
		
		
	}
	
	
	
	static int[] ruffleSort(int a[]) {
		ArrayList<Integer> al=new ArrayList<>();
		for(int i:a)al.add(i);
		Collections.sort(al);
		for(int i=0;i<a.length;i++)a[i]=al.get(i);
		return a;
	}
	static void print(int a[]) {
		for(int e:a) {
			System.out.print(e+" ");
		}
		System.out.println();
	}
	
	static class FastReader{
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while(!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				}
				catch(IOException e){
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		int[] readArray(int n) {
			int a[]=new int[n];
			for(int i=0;i<n;i++)a[i]=sc.nextInt();
			return a;
		}
	}
}






