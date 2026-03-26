import java.util.*;
public class Main{
 
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int[] a=new int[n];
		long mul=1;
		for (int i=0;i<n;++i) {
			a[i]=sc.nextInt();
		}
		if (n>m) {
			System.out.println("0");
		}
		else{
		    for (int i=0;i<n-1;++i) {
			for (int j=i+1;j<n;++j) {
				mul= mul%m * Math.abs(a[i]-a[j])%m;
				
			}
		}
		System.out.println(mul%m);
		}
	}
}