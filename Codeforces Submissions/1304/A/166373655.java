import java.util.Scanner;
import java.lang.Math;
public class CF3107{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases-->0){
			int leftPos = scan.nextInt();
			int rightPos = scan.nextInt();
			int leftD = scan.nextInt();
			int rightD = scan.nextInt();
			
			int n = leftD+rightD;
			int leftEq = leftPos-leftD;
			int rightEq = rightPos+rightD;
			//System.out.println(rightEq-leftEq);
			if((rightEq-leftEq)%n==0){
				System.out.println((rightEq-leftEq)/n-1);
			}else{
				System.out.println(-1);
			}

		}
	}
	public static int getSumDigits(long num){
		int sum = 0;
		while(num>0){
			sum += num%10;
			num = num/10;
		}
		return sum;
	}


}