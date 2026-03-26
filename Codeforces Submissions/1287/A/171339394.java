import java.util.Scanner;
public class CF0809{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases>0){
			int arrayLength = scan.nextInt();
			System.out.println(getMaxAngry(scan.next()));
			testCases--;
		}
	}
	public static int getMaxAngry(String string){
		int maxPCount = 0;
		int currentPCount = 0;
		boolean flag = false;
		for(char c : string.toCharArray()){
			if(c=='A'){
				if(currentPCount>maxPCount && flag){
					maxPCount = currentPCount;
				}
				currentPCount = 0;
				flag = true;
			}else{
				currentPCount++;
			}
		}
		return (currentPCount>maxPCount && flag)?currentPCount:maxPCount;
	}
}