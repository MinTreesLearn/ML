import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
		public static void main(String[] args) {
			// TODO Auto-generated method stub
			
			Scanner input = new Scanner(System.in);
			int testCases = input.nextInt();
					
			for(int index = 0; index < testCases; index++) {
				int studentsHalved = input.nextInt();
				int students[] = new int[studentsHalved*2];
				int lowestDiff = Integer.MAX_VALUE;
				for(int counter = 0; counter < students.length; counter++) {
					students[counter] = input.nextInt();
				}
				
				Arrays.sort(students);
				
				System.out.println(Math.abs(students[studentsHalved - 1] - students[studentsHalved]));
			}
		}
}