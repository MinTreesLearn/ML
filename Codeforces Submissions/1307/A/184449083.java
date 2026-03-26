import java.util.Scanner;

public class Problems {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int t = in.nextInt();

		while (t > 0) {
			int n = in.nextInt();
			int d = in.nextInt();
			int[] array = new int[n];
			for (int i = 0; i <n; i++) {
				array[i] = in.nextInt();
			}
			while(d-- > 0) {
				for (int i = 1; i < array.length; i++) {
					if(array[i] > 0) {
						array[i]--;
						array[i-1]++;
						break;
					}
				}
				
			}
			System.out.println(array[0]);
			t--;
		}
	}

}