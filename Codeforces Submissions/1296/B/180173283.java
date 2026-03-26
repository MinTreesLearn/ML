import java.util.ArrayList;
import java.util.Scanner;
public class CF0911{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases>0){
			long currentMoney = scan.nextLong();
			int totalSpent = 0;
			while(currentMoney>=10){
				totalSpent += currentMoney - currentMoney%10;
				currentMoney = currentMoney/10 + currentMoney%10;
			}
			System.out.println(currentMoney + totalSpent);
			testCases--;
		}
	}

}