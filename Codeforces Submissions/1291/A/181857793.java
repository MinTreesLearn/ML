import java.util.Scanner;
public class CF2111{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases>0){
			scan.nextInt();
			StringBuffer stringBuffer = new StringBuffer(scan.next());
			System.out.println(getReducedString(stringBuffer));
			testCases--;
		}
	}
	public static String getReducedString(StringBuffer stringBuffer){
		while(stringBuffer.length()>=1 && (stringBuffer.charAt(stringBuffer.length()-1)-'0')%2==0){
			stringBuffer.deleteCharAt(stringBuffer.length()-1);
		}
		//string buffer now contains last character odd.
		int i = stringBuffer.length()-2;
		boolean flag = false;
		while(i >= 0){
			if((stringBuffer.charAt(i)-'0')%2==1){
				stringBuffer.delete(0, i);
				flag = true;
				break;
			}
			i--;
		}
		if(flag	){
			return stringBuffer.toString();
		}
		return "-1";
	}
}