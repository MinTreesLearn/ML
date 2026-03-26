import java.util.Scanner;
public class CF1809{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int firstArrayLength = scan.nextInt();
		int secondArrayLength = scan.nextInt();
		scan.nextLine(); // for eating
		String[] firstArray = scan.nextLine().split(" ");
		String[] secondArray = scan.nextLine().split(" ");
		int numberOfQueries = scan.nextInt();
		for(int i=0; i<numberOfQueries; i++){
			int year = scan.nextInt();
			String firstYear;
			String secondYear;
			if(year%firstArray.length == 0){
				firstYear = firstArray[firstArray.length-1];
			}else{
				firstYear = firstArray[year%firstArray.length-1];
			}
			if(year%secondArray.length == 0){
				secondYear = secondArray[secondArray.length-1];
			}else{
				secondYear = secondArray[year%secondArray.length-1];
			}
			System.out.println(firstYear+secondYear);
		}
	}
}