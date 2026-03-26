import java.util.Scanner;
public class CF0712{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases>0){
			int a = scan.nextInt();
			int b = scan.nextInt();
			int c = scan.nextInt();
			int counter = 0;
			if(b>a){
				int temp = a;
				a = b;
				b = temp;
			}
			if(c>b){
				int temp = b;
				b = c;
				c = temp;
			}
			if(b>a){
				int temp = a;
				a = b;
				b = temp;
			}
			if(a>0){
				counter++;
				a--;
			}if(b>0){
				counter++;
				b--;
			}if(c>0){
				counter++;
				c--;
			}if(a>0 && b>0){
				counter++;a--;b--;
			}if(a>0 && c>0){
				counter++;a--;c--;
			}if(b>0 && c>0){
				counter++; b--;c--;
			}if(a>0 && b>0 && c>0){
				counter++;
			}
			System.out.println(counter);
			testCases--;
		}
	}
}