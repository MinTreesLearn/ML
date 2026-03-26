import java.util.Scanner;
public class CF3107{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases-->0){
			int m = scan.nextInt();
			int n = scan.nextInt();
			if(m%n==0){
				System.out.println("YES");
			}else{
				System.out.println("NO");
			}
		}
	}


}