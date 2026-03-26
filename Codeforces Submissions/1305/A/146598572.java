import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class kuroniAndGifts {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t-->0) {
			int n = s.nextInt();
			int arr1[] = new int[n];
			int arr2[] = new int[n];
			for(int i = 0; i<n; i++) {
				arr1[i] = s.nextInt();
			}
			for(int i = 0; i<n; i++) {
				arr2[i] = s.nextInt();
			}
			Arrays.sort(arr1);
			Arrays.sort(arr2);
			for(int i = 0; i<n; i++) {
				System.out.print(arr1[i]+ " ");
			}
			System.out.println();
			for(int i = 0; i<n; i++) {
				System.out.print(arr2[i]+ " ");
			}
		}
        System.out.println();
	}

}
