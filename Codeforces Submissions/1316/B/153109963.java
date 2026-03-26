import java.util.*;

public class String_Modification {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0) {
			int n = sc.nextInt();
			sc.nextLine();
			String s = sc.nextLine();
			String ans = s;
			int k = 1;
			int count = 1;
			for(int i=1;i<n;i++) {
				count++;
				String str = s.substring(i, n);
				if((n-count+1)%2==1) {
					str += new StringBuilder(s.substring(0, i)).reverse().toString();
				}else {
					str += s.substring(0,i);
				}
				if(str.compareTo(ans)<0) {
					ans = str;
					k = count;
				}
			}
			System.out.println(ans);
			System.out.println(k);
		}
	}
	
}
