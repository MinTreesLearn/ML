import java.util.Scanner;
public class CF1209{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases>0){
			int arrayLength = scan.nextInt();
			int maxPossibleScore = scan.nextInt();
			int totalSumOfScores = 0;
			for(int i=0; i<arrayLength; i++){
				totalSumOfScores += scan.nextInt();
			}
			if(totalSumOfScores<=maxPossibleScore){
				System.out.println(totalSumOfScores);
			}else{
				System.out.println(maxPossibleScore);
			}
			testCases--;
		}
	}
}