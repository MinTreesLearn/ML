import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
public class CF2510{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases>0){
			int arrayLength = scan.nextInt();
			Integer[] bracelets = new Integer[arrayLength];
			Integer[] necklaces = new Integer[arrayLength];
			for(int i=0; i<arrayLength; i++){
				bracelets[i] = scan.nextInt();
			}
			for(int i=0; i<arrayLength; i++){
				necklaces[i] = scan.nextInt();
			}
			Arrays.sort(bracelets, Collections.reverseOrder());
			Arrays.sort(necklaces, Collections.reverseOrder());
			for(int num: bracelets){
				System.out.print(num+" ");
			}
			System.out.println();
			for(int num: necklaces){
				System.out.print(num+" ");
			}
			System.out.println();
			testCases--;
		}
	}
	
}