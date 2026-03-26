import java.io.*;
import java.util.*;

public class We {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		int numberSets = Integer.parseInt(br.readLine());
		
		for (int nos = 0; nos < numberSets; nos++) {
			int size = Integer.parseInt(br.readLine());
			Set <Integer> set = new HashSet <> ();
			int [] data = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			for (int i = 0; i < data.length; i++) {
				set.add(data[i]);
			}
			System.out.println(set.size());
		}

	}

}
