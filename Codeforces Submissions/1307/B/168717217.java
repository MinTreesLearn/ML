

import java.util.Scanner;
public class mo {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int tt = in.nextInt();
		
		for(int w = 0 ; w < tt; w++) {
			int n = in.nextInt();
			int k = in.nextInt();
			long[] a = new long[n];
			long max = Long.MIN_VALUE;
			boolean nasao = false;
			for(int i = 0 ; i<n; i++) {
				a[i] = in.nextLong();
				max = Math.max(a[i], max);
				if(a[i]==k) {
					nasao = true;
				}
			}
			if(nasao) {
				System.out.println(1);
			}
			else {
				System.out.println(Math.max((int) Math.ceil((double) k/max),2));
			}
			
		}

	}

}
