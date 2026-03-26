import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
	
	private static int getTotal(int sum , int n) {
		int ans = 0 , s = 0;
		Set<Integer> set = new HashSet<>();
		set.add(0);		
		for (int i = 1;i <= n;i ++) {
			s += a[i];			
			int need = s - sum;
			if (set.contains(need)) {
				set.clear();
				set.add(s);				
				ans ++;			
			} else {
				set.add(s);					
			}
		}
		return ans;
	}
	
	private static void solve(int sum , int n) {
		Map<Integer , Integer> map = new HashMap<>();
		int i , s = 0;		
		List<int[]> list = new ArrayList<>();
		map.put(0 , 0);		
		for (i = 1;i <= n;i ++) {
			s += a[i];
			int need = s - sum;
			if (map.containsKey(need)) {
				list.add(new int[] {map.get(need) + 1 , i});
				map.clear();
				map.put(s , i);				
			} else {
				map.put(s , i);				
			}
		}
		System.out.println(list.size());
		for (int[] result : list) {
			System.out.println(result[0] + " " + result[1]);
		}
	}
	
	private static int[] a = new int[2000];
	
	public static void main(String[] args) {															
		
		Scanner scan = new Scanner(System.in);		
	
		int i , j , n = scan.nextInt() , max = 0 , s = 0;
		Set<Integer> set = new HashSet<>();		
		for (i = 1;i <= n;i ++) {
			a[i] = scan.nextInt();			
		}
		for (i = 1;i <= n;i ++) {
			int sum = 0;			
			for (j = i;j <= n;j ++) {
				sum += a[j];
				set.add(sum);				
			}
		}	
		for (int sum : set) {
			int total = getTotal(sum , n);
			if (total > max) {
				max = total;	
				s = sum;
			}
		}
		solve(s , n);
		
	}
    
}


