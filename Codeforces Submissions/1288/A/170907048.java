import java.util.*;

public class deadline {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		int count = sc.nextInt(); 
		
		for (int i=0; i<count; i++) {
			int n = sc.nextInt(); // required num days
			int d = sc.nextInt(); // current num days
			boolean yes = false;
			
			for (int j=0; j<n; j++) {
				double x = (double)d / (double)(j + 1);
				int optimized = j + (int)Math.ceil(x);
				if (optimized<=n) {
					yes = true;
					break;	
				}
			}
			if (yes) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
	}

}
