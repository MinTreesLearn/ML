import java.io.*;
import java.util.*;

public class Aq {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		int numberSets = Integer.parseInt(br.readLine());
		
		for (int nos = 0; nos < numberSets; nos++) {
			String s = br.readLine();
			int x1 = s.indexOf('1');
			int x2 = s.lastIndexOf('1');
			if (x1 == -1) {
				System.out.println(0);
				continue;
			}
			int counter = 0;
			for (int i = x1; i < x2; i++) {
				if (s.charAt(i)=='0') {
					counter++;
				}
			}
			System.out.println(counter);
			
		}
	}

}
