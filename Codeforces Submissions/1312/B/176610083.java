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
				int totalNums = input.nextInt();
				int[] nums = new int[totalNums];
				
				for(int counter = 0; counter < totalNums; counter++) {
					nums[counter] = input.nextInt();
				}
				
				Arrays.sort(nums);
				
				for(int counter = nums.length-1; counter >= 0; counter--) {
					System.out.print(nums[counter] + " ");
				}
				
				System.out.println();
			}
		}
}