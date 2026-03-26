import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int n = sc.nextInt();
			int[] a = new int[n];
			int[] b = new int[n];
			for(int i=0; i<n; i++) a[i] = sc.nextInt();
			for(int i=0; i<n; i++) b[i] = sc.nextInt();
			Arrays.sort(a);
			Arrays.sort(b);
			for(int i=0; i<n; i++)
				System.out.print(a[i] + " ");
			System.out.println("");
			for(int i=0; i<n; i++)
				System.out.print(b[i] + " ");
			System.out.println("");
		}
	}
}