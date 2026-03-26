import java.io.*;
import java.util.*;

public class WaterBalance_1299C {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] a = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i ++) a[i] = Integer.parseInt(st.nextToken());
		long[] sums = new long[n];
		int[] starts = new int[n];
		Stack<Integer> stack = new Stack<>();
		for(int i = 0; i < n; i ++) {
			sums[i] = a[i];
			starts[i] = i;
			while(!stack.isEmpty()) {
				int j = stack.peek();
				if(sums[j] * (i - starts[j] + 1) <= (sums[i] + sums[j]) * (j - starts[j] + 1)) break;
				stack.pop();
				sums[i] += sums[j];
				starts[i] = starts[j];
			}
			stack.push(i);
		}
		StringBuilder output = new StringBuilder();
		for(int i : stack) {
			double val = (double)sums[i] / (i - starts[i] + 1);
			for(int j = starts[i]; j <= i; j ++) output.append(val + "\n");
		}
		System.out.println(output.toString());
	}
}