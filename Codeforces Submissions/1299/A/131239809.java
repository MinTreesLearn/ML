import java.util.*;
public class C {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int[] arr = new int[n];
		String[] a = new String[n];
		for(int i=0;i<n;i++) {
			arr[i] = sc.nextInt();
			a[i] = Integer.toString(arr[i], 2);
			int len = a[i].length();
			while(len<30) {
				a[i] = "0"+a[i];
				len++;
			}
		}
		
		int idx = 0;
		for(int i=0;i<30;i++) {
			int zero = 0;
			for(int j=0;j<n;j++) {
				if(a[j].charAt(i)=='0')
					zero++;
				else
					idx = j;
			}
			if(zero==n-1)
				break;
		}
		
		int tmp = arr[0];
		arr[0] = arr[idx];
		arr[idx] = tmp;
		
		for(int i=0;i<n;i++) {
			System.out.print(i==0 ? arr[i] : " "+arr[i]);
		}
	}

}
