import java.io.*;
import java.util.Arrays;

public class Cv {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		int numberSets = Integer.parseInt(br.readLine());
		
		for (int nos = 0; nos < numberSets; nos++) {
			int [] data = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			if (data[0]%data[1] == 0) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
		

	}

}
