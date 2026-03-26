import java.util.Arrays;
import java.util.Scanner;

public class CR622A {
	public static int parts(int a, int b, int c) {
		int count = 0;
		if (a!=0) {
			count++;a--;
		}
		if (c!=0) {
			count++;c--;
		}
		if (b!=0) {
			count++;b--;
		}
		if (a!=0 && b!=0) {
			count++;
			a--;b--;
		}
		if (a!=0 && c!=0) {
			count++;
			a--;c--;
		}
		if (c!=0 && b!=0) {
			count++;
			c--;b--;
		}
		
		if (a!=0 && b!=0 && c!=0) {
			count++;
		}
		return count;
	}
	
	public static void main (String[] args) {
		Scanner m = new Scanner(System.in);
		int n = m.nextInt();
		int[] arr = new int[3];
		for (int i=0; i<n; i++) {
			arr[0]= m.nextInt();;
			arr[1]= m.nextInt();;
			arr[2]= m.nextInt();;
			Arrays.sort(arr);
			System.out.println(parts(arr[2],arr[1],arr[0]));
		}
	}
 
}
