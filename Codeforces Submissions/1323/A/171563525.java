import java.util.Scanner;
public class CF1009{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases>0){
			int indexOfEvenNumber = -1;
			int indexOfFirstOddNumber = -1;
			int indexOfSecondOddNumber = -1;
			int arrayLength = scan.nextInt();
			for(int i=1; i<=arrayLength; i++){
				int num = scan.nextInt();
				if(num%2==0){
					indexOfEvenNumber = i;
					scan.nextLine();
					break;
				}else if(indexOfFirstOddNumber==-1){
					indexOfFirstOddNumber = i;
				}else{
					indexOfSecondOddNumber=i;
				}
			}
			if(indexOfEvenNumber!=-1){
				System.out.println(1);
				System.out.println(indexOfEvenNumber);
			}else if(indexOfFirstOddNumber>0 && indexOfSecondOddNumber>0){
				System.out.println(2);
				System.out.println(indexOfFirstOddNumber+" "+indexOfSecondOddNumber);
			}else{

				System.out.println(-1);
			}
			testCases--;
		}
	}
}