
import java.util.Arrays;
import java.util.Scanner;

public class KuroniAndTheGifts {
	public static void main(String[]args) {
		Scanner sn = new Scanner(System.in);
		int t = sn.nextInt();
	
		for(int i=0; i<t; i++) {
			
			int n = sn.nextInt();
			sn.nextLine();
			
			String[] a = sn.nextLine().split(" ");
			String[] b = sn.nextLine().split(" ");
		
			
			int an[] = new int[a.length];
			int bn[] = new int[b.length];
			for(int j=0; j<a.length; j++) {
				an[j] = Integer.parseInt(a[j]);
				bn[j] = Integer.parseInt(b[j]);
			}
			Arrays.sort(an);
			Arrays.sort(bn);
			StringBuffer sb = new StringBuffer();
			for(int j =0; j<a.length; j++) {
				sb.append(an[j]+" ");
			}
			
			sb.append("\n");
			for(int j =0; j<b.length; j++) {
				sb.append(bn[j]+" ");
			}
			
			System.out.println(sb);
		}
	}
}