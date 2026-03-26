
import java.util.Scanner;

public class anagram {
public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	String str = s.next();
	int q = s.nextInt();
	int n = str.length();
	int [][] dp = new int[n+1][26];
	for(int i = 1  ;i <= n ; i++) {
		
		for(int j = 0 ; j < 26 ;j++) {
			dp[i][j] = dp[i-1][j];
		}
		dp[i][str.charAt(i-1)-'a']++;
	}
	while(q-->0) {
		int l = s.nextInt();
		int r = s.nextInt();
		int total_unique = 0 ;
		for(int j = 0 ; j < 26 ;j++) {

			if( dp[r][j] - dp[l-1][j] >0) {
				total_unique++;
			}
		}
		
		if(r==l || (total_unique==2 && str.charAt(l-1) != str.charAt(r-1) ) || (total_unique>=3)) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}
}
