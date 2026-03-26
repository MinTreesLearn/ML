
import java.util.Scanner;
public class CF{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int testCas = scan.nextInt();
		while(testCas>0){
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
			testCas--;
		}
	}
}