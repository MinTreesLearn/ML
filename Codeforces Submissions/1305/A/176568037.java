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
				int numDaughters = input.nextInt();
				int[] necklaces = new int[numDaughters];
				int[] braceletes = new int[numDaughters];
				
				for(int counter = 0; counter < numDaughters; counter++) {
					necklaces[counter] = input.nextInt();
				}
				
				for(int counter = 0; counter < numDaughters; counter++) {
					braceletes[counter] = input.nextInt();
				}
				
				
				Arrays.sort(necklaces);
				Arrays.sort(braceletes);
				
				for(int counter = 0; counter < numDaughters; counter++) {
					System.out.print(necklaces[counter] + " ");
				}
				
				System.out.println();
				
				for(int counter = 0; counter < numDaughters; counter++) {
					System.out.print(braceletes[counter] + " ");
				}
				
				System.out.println();
			}
		}
}