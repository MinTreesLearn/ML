import java.util.*;
public class RestoringPermutation {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		outer:
		while(t-->0) {
			int n=sc.nextInt();
			int arr[]=new int[n];
			Set<Integer> foo=new LinkedHashSet<>();
			List<Integer> list=new ArrayList<>();
			for(int i=0;i<n;i++) {
				foo.add(sc.nextInt());
			}
			for(int i=1;i<=(2*n);i++) {
				if(!foo.contains(i)) {
					list.add(i);
				}
			}
			Collections.sort(list);
			List<Integer> foolist = new ArrayList<>();
			List<String> ans=new ArrayList<>();
			foolist.addAll(foo);
			int count=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(foolist.get(i)<list.get(j)) {
						ans.add(foolist.get(i)+" "+list.get(j)+" ");
						foolist.set(i,-1);
						list.set(j, -1);
						count++;
						break;
					}
				}
				if(count==0) {
					System.out.println(-1);
					continue outer;
				}
				count=0;
			}
			for(int i=0;i<ans.size();i++) {
				System.out.print(ans.get(i));
			}
			System.out.println();
		}
	}
}
