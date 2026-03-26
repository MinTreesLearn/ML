import java.util.*;
public class ErasingZeros {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 0 ; i <n ;i++) {
			int count = 0;
			String s  = sc.next();
			for(int j = s.indexOf('1'); j < s.lastIndexOf('1'); j++) {
				if(s.charAt(j) == '0') {
					count++;
				}
			}
			System.out.println(count);
		}
	}

}
