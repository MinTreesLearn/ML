import java.util.HashMap;
import java.util.Scanner;

public class Lesson10YetAnotherWalkingRobot {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tcc = sc.nextInt();
		sc.nextLine();
		while (tcc-- > 0) {
			int n = sc.nextInt();
			sc.nextLine();
			String path = sc.nextLine(); 
			HashMap<String, Integer> hm = new HashMap<String, Integer>();
			hm.put("0,0", -1);
			int x = 0;
			int y = 0;
			int startPos = 0;
			int endPos = 0;
			int difference = Integer.MAX_VALUE;
			for (int i = 0; i < path.length(); i++) {
				char target = path.charAt(i);
				if (target == 'L') {
					x--;
				} else if (target == 'R') {
					x++;
				} else if (target == 'U') {
					y++;
				} else if (target == 'D') {
					y--;
				}
				if (hm.containsKey(x + "," + y)) {
					int possibleStartPos = hm.get(x + "," + y);
					if (possibleStartPos < i && i - possibleStartPos + 1 < difference) {
						difference = i - possibleStartPos + 1;
						startPos = possibleStartPos + 2;
						endPos = i + 1;
					}
				}
					hm.put(x + "," + y, i);
					
			}
			if (startPos == endPos && endPos == 0) {
				System.out.println(-1);
			} else {
				System.out.println(startPos + " " + endPos);
			}
		}

	}

}
