import java.util.*;

public class Restoring_Permutation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0) {
			int n = sc.nextInt();
			int b[] = new int[n];
			HashSet<Integer> set = new HashSet<>();
			int grt = 0;
			for(int i=0;i<n;i++) {
				b[i] = sc.nextInt();
				if(b[i]>n)
					grt++;
			    set.add(b[i]);
			}
			if(set.contains(2*n)||!set.contains(1)||grt>n/2)
				System.out.println(-1);
			else {
				StringBuilder sb = new StringBuilder();
				for(int i=0;i<n;i++) {
					for(int j=b[i]+1;j<=2*n;j++) {
						if(set.contains(j))
							continue;
						else {
							sb.append(b[i]+" "+j+" ");
							set.add(j);
							break;
						}
					}
				}
				if(set.size()!=2*n) {
					System.out.println(-1);
				}else {
					System.out.println(sb);
				}
			}
		}
	}

}
