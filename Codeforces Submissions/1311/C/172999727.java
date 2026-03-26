import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int t = Integer.parseInt(f.readLine());
		while (t-- > 0) {
			StringTokenizer st = new StringTokenizer(f.readLine());
			int n=Integer.parseInt(st.nextToken());
			int m=Integer.parseInt(st.nextToken());
			char[] arr=f.readLine().toCharArray();
			int[] moves=new int[m+1];
			st=new StringTokenizer(f.readLine());
			for(int i=0;i<m;i++) {
				moves[i]=Integer.parseInt(st.nextToken());
			}
			moves[m]=n;
			int[][] pref=new int[26][n];
			for(int i=0;i<n;i++) {
				int x=arr[i]-'a';
				pref[x][i]++;
			}
			for(int i=1;i<n;i++) {
				for(int j=0;j<26;j++) {
					pref[j][i]+=pref[j][i-1];
				}
			}
			int[] ans=new int[26];
			for(int i=0;i<=m;i++) {
				for(int j=0;j<26;j++) {
					ans[j]+=pref[j][moves[i]-1];
				}
			}
			for(int i=0;i<26;i++) {
				out.print(ans[i]+" ");
			}
			out.println();
		}
		out.close();
		f.close();
	}

}
