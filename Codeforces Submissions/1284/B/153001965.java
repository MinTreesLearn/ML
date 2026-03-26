import java.util.*;

public class New_Year_And_Ascent_Sequence {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int t = n;
		long res = 0;
		ArrayList<Integer> first = new ArrayList<>();
		ArrayList<Integer> last = new ArrayList<>();
		
		while(n-->0) {
			int l = sc.nextInt();
			int arr[] = new int[l];
			arr[0] = sc.nextInt();
			boolean flag = false;
			for(int i=1;i<l;i++) {
				arr[i] = sc.nextInt();
				if(arr[i]>arr[i-1])
					flag = true;
			}
			if(!flag) {
				first.add(arr[0]);
				last.add(arr[l-1]);
			}else {
				res += ((2*t)-1);
				t--;
			}
		}
		int m = first.size();
//		res += (long)(m)*(long)(m-1);
		Collections.sort(first);
		Collections.sort(last);
		int i=0,j=0,total =0;
		while(i<m&&j<m) {
			if(last.get(i)<first.get(j)) {
				i++;total++;
			}else {
				res += total;
				j++;
			}
		}
		if(j<m)
			res += (long)(m-j)*(long)(total);
		System.out.println(res);
	}

}
