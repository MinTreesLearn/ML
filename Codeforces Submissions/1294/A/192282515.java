import java.io.*;
import java.util.Arrays;

public class Gf {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		int numberSets = Integer.parseInt(br.readLine());
		
		for (int nos = 0; nos < numberSets; nos++) {
			int [] data = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			
			int max = 0;
			for (int i = 0; i < data.length-1; i++) {
				
				max = Math.max(max, data[i]);
			}
			for (int i = 0; i < data.length-1; i++) {
				data[3]-=(max-data[i]);
				
			}
			if (data[3]%3 != 0 || data[3] < 0) {
				System.out.println("NO");
			} else {
				System.out.println("YES");
			}
			
		}

	}

}
