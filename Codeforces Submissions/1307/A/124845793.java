
import java.util.Scanner;

public class CowAndHaybales {
	public static void main(String[]args) {
		Scanner sn = new Scanner(System.in);
		int t = sn.nextInt();
		for(int i=0; i<t; i++) {
			int n = sn.nextInt();
			int k = sn.nextInt();
			int arr[] = new int[n];
			for(int j =0; j<n; j++) {
				arr[j] = sn.nextInt();
			}
			if(n==1) {
				System.out.println(arr[0]);
			} else {
				for(int j=1; j<arr.length && k>0; j++) {
					int max_bales = arr[j]*j;
					int max_K = (k/j)*j;
					int energyUsed = Math.min(max_K, max_bales);
					int balesShifted = energyUsed/j;
					k-=energyUsed;
					arr[0]+=balesShifted;
				}
				
				System.out.println(arr[0]);
			}
		}
	}
}
