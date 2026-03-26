import java.io.*;
import java.util.*;

public class Zx {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		int numberSets = Integer.parseInt(br.readLine());
		
		for (int nos = 0; nos < numberSets; nos++) {
			int size = Integer.parseInt(br.readLine());
			int [] data = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			int counter = 0;
			for (int i = 0; i < size; i++) {
				if (data[i]%2==0) {
					counter++;
				}
			}
			if (counter > 0 && counter < size) {
				System.out.println("YES");
				continue;
			}
			if (counter == 0 && size%2 != 0) {
				System.out.println("YES");
				continue;
			}
			System.out.println("NO");
			
		}
	}

}