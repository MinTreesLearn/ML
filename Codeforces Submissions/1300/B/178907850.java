import java.util.*;
public class AssigningToTheClass {
 
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t=sc.nextInt();
		while(t--!=0) {
			int n=sc.nextInt();
			int a[]= new int[2*n];
			for(int i=0;i<a.length;i++) a[i]=sc.nextInt();
			Arrays.sort(a);
			System.out.println(a[n]-a[n-1]);
		}
 
	}
 
}