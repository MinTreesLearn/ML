//package primitiveprimes;

import java.util.*;
import java.io.*;

public class primitiveprimes {
	public static void main(String[] args) throws IOException {
		BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(fin.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		int a = -1;
		int b = -1;
		st = new StringTokenizer(fin.readLine());
		for(int i = 0; i < n; i++) {
			if(Integer.parseInt(st.nextToken()) % p != 0) {
				a = i;
				break;
			}
		}
		st = new StringTokenizer(fin.readLine());
		for(int i = 0; i < m; i++) {
			if(Integer.parseInt(st.nextToken()) % p != 0) {
				b = i;
				break;
			}
		}
		System.out.println(a + b);
	}
}
