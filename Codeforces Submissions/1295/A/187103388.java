
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Vc {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		int numberSets = Integer.parseInt(br.readLine());
		
		for (int nos = 0; nos < numberSets; nos++) {
			// int [] data = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			int number  = Integer.parseInt(br.readLine());
			StringBuilder sb = new StringBuilder();
			if (number%2 == 0) {
				for (int i = 0; i < number/2; i++) {
					sb.append("1");
				}
				System.out.println(sb.toString());
			} else {
				sb.append("7");
				for (int i = 0; i < (number-3)/2; i++) {
					sb.append("1");
				}
				
				System.out.println(sb.toString());
			}
		}

	}

}