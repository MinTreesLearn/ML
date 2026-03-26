
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Zz {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		int numberSets = Integer.parseInt(br.readLine());
		
		loop1: for (int nos = 0; nos < numberSets; nos++) {
			int size = Integer.parseInt(br.readLine());
			int [] data = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			
			Map <Integer, Integer> map = new HashMap<Integer,Integer>();
			
			for (int i = 0; i < data.length; i++) {
				if (!map.containsKey(data[i])) {
					map.put(data[i], i);
				} else {
					if (i-map.get(data[i])>1) {
						System.out.println("YES");
						continue loop1;
					}
				}
			}
			System.out.println("NO");
			
		}

	}

}