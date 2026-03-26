import java.io.*;
import java.util.Arrays;

public class Bv {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		int numberSets = Integer.parseInt(br.readLine());
		
		for (int nos = 0; nos < numberSets; nos++) {
			int [] data = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			
			if ((data[1]-data[0])%(data[2]+data[3]) != 0) {
				System.out.println(-1);
			} else {
				System.out.println((data[1]-data[0])/(data[2]+data[3])); 
			}
		}
		

	}

}