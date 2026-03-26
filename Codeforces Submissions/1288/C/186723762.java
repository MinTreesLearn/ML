import java.util.*;
public class TwoArrays {
	static int n,m;
	static long[][] memo;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		int arr[]=new int[2*m];
		memo=new long[n+1][(2*m)+1];
		for(int i=0;i<=n;i++) {
			for(int j=0;j<=2*m;j++) {
				memo[i][j]=-1;
			}
		}
//		System.out.println(Arrays.deepToString(memo));
		System.out.println(count(0,0,arr));
//		System.out.println(Arrays.deepToString(memo));
	}
	public static long count(int num,int pos,int[] arr) {
//		System.out.println(num+" "+" "+pos);
		if(memo[num][pos]==-1) {
			long ans=0;
			if(pos==2*m) {
				return 1;
			}
			for(int i=1;i<=n;i++) {
				if(i>=num) {
					ans=(ans+count(i,pos+1,arr))%1000000007;
				}
			}
			return memo[num][pos]=ans;
		}
		return memo[num][pos];
	}
}
