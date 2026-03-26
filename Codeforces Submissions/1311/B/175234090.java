

import java.util.Arrays;
import java.util.Scanner;

public class B1311 {
	static Scanner sc = new Scanner(System.in);
	static int t = sc.nextInt();
	static int []a = new int[110];
	static boolean []c = new boolean[110];
	static int []p = new int[110];
	public static void main(String[] args) {
		while((t--) > 0) {
			Arrays.fill(c,false);
			boolean flag = true;
			int n = sc.nextInt();
			int m = sc.nextInt();
			for(int i = 1; i <= n; i++) {
				a[i] = sc.nextInt();
			}
			for(int j = 1; j <= m; j++) {
				p[j] = sc.nextInt();
				c[p[j]] = true;
			}
			int k = 0; 
			for(int i1 = 1; i1 <= n; i1++) {
				for(int j = 1; j < n; j++) {
					if(a[j] > a[j + 1]) {
						if(c[j]) {
							k = a[j];
							a[j] = a[j + 1];
							a[j + 1] = k;
						}
						else {
							flag = false;
						}
					}
				}
			}
			if(!flag) {
				System.out.println("NO");
			}else {
				System.out.println("YES");
			}
		}
	}
 }

