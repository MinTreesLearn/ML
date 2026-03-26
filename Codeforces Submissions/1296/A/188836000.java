import java.io.*;
import java.util.*;

public class ProbA {
	static int T;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		for (int t = 0; t < T; t++) {
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			//odd sum dont do anything
			//even sum, make even 
			int even = 0;
			int odd = 0;
			int sum = 0;
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i<N; i++) {
				int a = Integer.parseInt(st.nextToken());
				if(a % 2 == 0) even++;
				else odd++;
				sum += a;
			}
			boolean good = false;
			if(sum  % 2 == 1) {
				good = true;
			}else if(even >= 1 && odd >= 1){
				good = true;
			}
			pw.println(good ? "YES": "NO");
			
		}
		pw.close();

	}

}
