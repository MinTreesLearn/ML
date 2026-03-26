import java.util.Scanner;
public class CF1009{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases>0){
			String firstString = scan.next();
			String secondString = scan.next();
			String thirdString = scan.next();
			boolean flag = false;
			for(int i=0; i<firstString.length(); i++){
				char a = firstString.charAt(i);
				char b = secondString.charAt(i);
				char c = thirdString.charAt(i);
				if(a != b && b != c && a != c || a == b && c!=b){
					flag = true;
				}
			}
			if(flag){
				System.out.println("NO");
			}else{
				System.out.println("YES");
			}
			testCases--;
		}
	}
}