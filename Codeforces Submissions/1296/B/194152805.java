// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(r.readLine());

		int count = Integer.parseInt(st.nextToken());
		int m;
		for(int i = 0; i < count; i++) {
			st = new StringTokenizer(r.readLine());
			m = Integer.parseInt(st.nextToken());
			pw.println(findMax(m));
		}




		pw.close();
	}
	
	public static int findMax(int s)
	{
		if(s < 10)
			return s;
		return (s - s%10) + findMax(s%10 + ((s - s%10) / 10));
	}
}
