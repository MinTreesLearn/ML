import java.util.*;
public class P4{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] a=new int[n];
		int[] b=new int[n];
		Integer[] c=new Integer[n];
		long ans=0;
		for (int i=0;i<n;++i) {
			a[i]=sc.nextInt();
		}
		for (int i=0;i<n;++i) {
			b[i]=sc.nextInt();
			c[i]=a[i]-b[i];
		}
		Arrays.sort(c);
		int l=0,r=n-1;
		while(l<r){
			if ((c[r]+c[l])>0) {
				ans+=r-l;
				--r;
			}
			else{
				++l;
			}
		}
		System.out.println(ans);
	}
}