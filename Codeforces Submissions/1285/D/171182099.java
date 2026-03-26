import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class drevilunderscores {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int n = Integer.parseInt(br.readLine());
		StringTokenizer token = new StringTokenizer(br.readLine());
		
		ArrayList<Integer> a = new ArrayList<>();
		for (int i = 0; i < n; i++) a.add(Integer.parseInt(token.nextToken()));
		
		System.out.println(solve(a, 30));
	}
	
	public static int solve(ArrayList<Integer> a, int b) {
		if (b == -1) return 0;
		ArrayList<Integer> l = new ArrayList<>();
		ArrayList<Integer> r = new ArrayList<>();
		for (int i : a) {
			if (((i >> b) & 1) == 0) l.add(i);
			else r.add(i);
		}
		
		if (l.size()==0) return solve(r, b-1);
		if (r.size()==0) return solve(l, b-1);
		return Math.min(solve(l, b-1), solve(r, b-1)) + (1 << b);
	}
}
