import java.util.*;
import java.io.*;

public class perfectkeyboard {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		while (t-- > 0) {
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			boolean[] vis = new boolean[26];
			ArrayList<Character> res = new ArrayList<Character>();
			boolean ispos = true;
			int ix = -1;
			for (char ch : str.toCharArray()) {
				if (vis[ch - 'a']) {
					if (ix - 1 >= 0 && res.get(ix - 1) == ch)
						ix--;
					else if (ix + 1 < res.size() && res.get(ix + 1) == ch)
						ix++;
					else {
						ispos = false;
						break;
					}

				} else {
					if (ix + 1 == res.size()) {
						res.add(ch);
						ix++;
					} else if (ix == 0) {
						res.add(0, ch);
						ix = 0;
					} else {
						ispos = false;
						break;
					}
					vis[ch - 'a'] = true;
				}
				if (!ispos)
					break;
			}
			if (!ispos) {
				pw.println("NO");
			} else {
				pw.println("YES");
				for (char ch : res) {
					pw.print(ch);
				}
				for (int i = 0; i < 26; i++) {
					if (!vis[i]) {
						pw.print((char) (i + 'a'));
					}
				}
				pw.println();
			}
		}

		pw.close();

	}
}
