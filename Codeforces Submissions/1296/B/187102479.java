
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
			int res = 0;
			while (number >= 10) {
				res += number - number%10;
				number = number/10 + number%10;
			}
			res+= number;
			System.out.println(res);
		}

	}

}