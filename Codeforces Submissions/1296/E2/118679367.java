import java.util.*;
public class string_coloring_hard {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
 
		int n = sc.nextInt();
		char[] s = sc.next().toCharArray();
		int[] dp = new int[n];
		int[] maxdp = new int[26];
		Arrays.fill(dp, 1);
		Arrays.fill(dp, 0);
		
		for(int i=0;i<n;i++) {
			int k = s[i]-'a';
			int max = 0;
			for(int j=k+1;j<26;j++) {
				if(maxdp[j]>max)
					max = maxdp[j];
			}
			dp[i] = max+1;
			maxdp[k] = dp[i];
		}
		
		StringBuilder color = new StringBuilder();
		int max = 0;
		for(int i=0;i<n;i++) {
			color.append(dp[i]+" ");
			if(dp[i]>max)
				max = dp[i];
		}
		
		System.out.println(max);
		System.out.println(color);
	}
 
}