import java.io.*;
import java.util.*;
 
public class cf {
	public static void main(String[] args) throws IOException {

		BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//st = new StringTokenizer(br.readLine());
		
		int q = Integer.parseInt(br.readLine());

		while(q-->0){
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int t = 0;
			int max = m;
			int min = m;
			int f = 0;
			
			int[][] arr = new int[n][3];

			for(int i=0; i<n; i++){
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());

				max += (a-t);
				min -= (a-t);

				if(max<b || min>c){
					f++;
				}

				max = Math.min(max, c);
				min = Math.max(min, b);
				t = a;
			}

			if(f==0){
				System.out.println("YES");
			}else{
				System.out.println("NO");
			}

		}
	}
}