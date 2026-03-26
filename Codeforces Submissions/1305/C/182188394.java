
import java.util.*;

public class Codeforces {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
//		int t = sc.nextInt();
//		
//		while (t-- > 0) {
//			int n  = sc.nextInt();
//			int[] arr = new int[n];
//			for(int i = 0 ; i < n ; i++) {
//				arr[i] = sc.nextInt();
//			}
//		
//		}	
		
		long n = sc.nextLong();
	    long m = sc.nextLong();
		long[] arr = new long[(int)n];
		for(int i = 0 ; i < n ; i++) {
			arr[i] = sc.nextLong();
		}
	
	    long res = 1;
	    if(n<=m) {
	    	for(int i = 0 ; i < arr.length ; i++) {
	    		for(int j = i+1 ; j<arr.length ; j++) {
	    			res = (res%m *(Math.abs(arr[i]-arr[j])%m))%m;
	    		}
	    	}
	    }
	    else res = 0;
	    System.out.println(res%m);
 	}
	
	
	public static int lower_bound(List<Integer> l , int x) {
		int start = 0;
		int end = l.size()-1;
		int ans = Integer.MAX_VALUE;
		while(start<=end) {
			int mid = start + (end-start)/2;
			if(l.get(mid)==x) return l.get(mid);
			else if(l.get(mid)>x) {
				ans = Math.min(ans, l.get(mid));
				end = mid -1;
			}
			else start = mid + 1;
		}
		return ans==Integer.MAX_VALUE ? -1 : ans;
	}
}
