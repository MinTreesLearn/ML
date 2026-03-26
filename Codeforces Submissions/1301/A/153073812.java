import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class LRUD {
	public static void main(String... strings) {
		try (Scanner sc = new Scanner(System.in)) {
			int testCase = sc.nextInt();
			Set<Character> chars;
			while (testCase-- > 0) {
				char a[] = sc.next().toCharArray();
				char b[] = sc.next().toCharArray();
				char c[] = sc.next().toCharArray();
				String result = "YES";
				for (int i = 0; i < a.length; i++) {
					// c is different
					if (a[i] == b[i] && a[i] != c[i]) {
						result = "NO";
						break;
					}
					chars = new HashSet<>(3);
					chars.add(a[i]);
					chars.add(b[i]);
					chars.add(c[i]);
					if (chars.size() == 3) {
						result = "NO";
						break;
					}
				}
				System.out.println(result);
			}

		}
	}
}