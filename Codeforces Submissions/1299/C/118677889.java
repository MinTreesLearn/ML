import java.util.*;
import java.io.*;
 
public class water_balance {
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer line = new StringTokenizer(in.readLine());
		
		int n = Integer.parseInt(line.nextToken());
		
		int[] a = new int[n];
		
		line = new StringTokenizer(in.readLine());
		
		for (int i = 0; i < n; i++)
			a[i] = Integer.parseInt(line.nextToken());
		
		Stack<double[]> stack = new Stack();
		for (int i = n - 1; i >= 0; i--) {
			double sum = a[i];
			int len = 1;
			while (!stack.isEmpty()) {
				double[] top = stack.peek();
 
				if (sum / len > top[0]) {
					sum += top[0] * top[1];
					len += top[1];
					stack.pop();
				} else
					break;
 
			}
			double curr = sum / len;
			stack.push(new double[] { curr, len });
		}
		while (!stack.isEmpty()) {
			double[] curr = stack.pop();
			while (curr[1]-- > 0)
				out.printf("%.10f\n", curr[0]);
		}
		out.close();
 
	}
 
	static void sort(int[] a) {
		shuffle(a);
		Arrays.sort(a);
	}
 
	static void shuffle(int[] a) {
		int n = a.length;
		Random rand = new Random();
		for (int i = 0; i < n; i++) {
			int tmpIdx = rand.nextInt(n);
			int tmp = a[i];
			a[i] = a[tmpIdx];
			a[tmpIdx] = tmp;
		}
	}
 
}