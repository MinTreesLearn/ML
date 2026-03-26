import java.util.Scanner;
public class CF1508{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases>0){
			int arrayLength = scan.nextInt();
			int totalSum = 0;
			int numberOfZeroes = 0;
			for(int i = 0; i<arrayLength; i++){
				int num = scan.nextInt();
				if(num == 0){
					numberOfZeroes++;
				}
				totalSum += num;
			}
			if(numberOfZeroes==0){
				if(totalSum==0){
					System.out.println(1);
				}else{
					System.out.println(0);
				}
			}else{
				if(totalSum + numberOfZeroes == 0){
					System.out.println(numberOfZeroes+1);
				}else{
					System.out.println(numberOfZeroes);
				}
			}
			testCases--;
		}
	}
}