import java.util.Scanner;
import java.util.Arrays;
public class CF1710{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases>0){
			int arrayLength = scan.nextInt();
			int numberOfDays = scan.nextInt();
			int[] array = new int[arrayLength];
			for(int i=0; i<arrayLength; i++){
				array[i] = scan.nextInt();
			}
			int totalHaysInFirstPile = array[0];
			for(int i=1; i<array.length; i++){
				if(array[i]>0){
					int haysInCurrentArray = array[i];
					if(numberOfDays >= i){
						int haysToMove = numberOfDays/i;
						if(haysToMove >= haysInCurrentArray){
							totalHaysInFirstPile += haysInCurrentArray;
							numberOfDays -= i*haysInCurrentArray;
						}else{
							totalHaysInFirstPile+=haysToMove;
							break;
						}
					}
				}
			}
			System.out.println(totalHaysInFirstPile);
			testCases--;
		}
	}
}