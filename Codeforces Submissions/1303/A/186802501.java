import java.io.*;
import java.util.*;

public class Problems {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int t = in.nextInt();
		String[] array = new String[t];
		for (int i = 0; i < array.length; i++) {
			array[i] = in.next();
		}
		for (int i = 0; i < array.length; i++) {
			int counter = 0;
			String str = array[i];
			if (firstOne(str) == -1) {
				System.out.println(0);
				continue;
			} else {
				for (int j = firstOne(str) + 1; j < lastOne(str); j++) {
					if (str.charAt(j) == '0') {
						counter++;
					}
				}
				System.out.println(counter);
			}
		}

	}

	public static int firstOne(String str) {
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == '1') {
				return i;
			}
		}
		return -1;
	}

	public static int lastOne(String str) {
		for (int i = str.length() - 1; i >= 0; i--) {
			if (str.charAt(i) == '1') {
				return i;
			}
		}
		return -1;
	}

}