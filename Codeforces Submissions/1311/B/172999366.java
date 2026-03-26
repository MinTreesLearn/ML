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
			int[][] arr=new int[n][2];
			HashSet<Integer> p=new HashSet<>();
			st=new StringTokenizer(f.readLine());
			for(int i=0;i<n;i++) {
				arr[i][0]=Integer.parseInt(st.nextToken());
				arr[i][1]=i;
			}
			st=new StringTokenizer(f.readLine());
			for(int i=0;i<m;i++) {
				p.add(Integer.parseInt(st.nextToken())-1);
			}
			Arrays.sort(arr,(a,b)->a[0]-b[0]==0?a[1]-b[1]:a[0]-b[0]);
			HashSet<Integer> ans=new HashSet<>();
			for(int i=0;i<arr.length;i++) {
				if(arr[i][1]>i) {
					for(int j=i;j<arr[i][1];j++) {
						ans.add(j);
					}
				}
				else {
					for(int j=arr[i][1];j<i;j++) {
						ans.add(j);
					}
				}
			}
			boolean good=true;
			for(int i:ans) {
				if(!p.contains(i)) {
					good=false;
					break;
				}
			}
			if(good) {
				out.println("YES");
			}
			else {
				out.println("NO");
			}
		}
		out.close();
		f.close();
	}

}
