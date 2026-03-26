import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader in = new BufferedReader(new FileReader(new File("./src/testcase.txt")));
		int t = Integer.parseInt(in.readLine());
		for (int i=0; i<t; i++) {
			String s = in.readLine();
			int cur = 0;
			int max = 1;
			for (int j=0; j<s.length(); j++) {
				if (s.charAt(j) == 'L') {
					cur ++;
				} else {
					max = Math.max(max, cur+1);
					cur = 0;
				}
			}
			max = Math.max(max, cur+1);
			System.out.println(max);
		}
	}
}