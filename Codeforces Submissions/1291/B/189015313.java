import java.util.*;
public class ArraySharpening {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		outer:
		while(t-->0) {
			int n=sc.nextInt();
			int arr[]=new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=sc.nextInt();
			}
			int pos=0;
			for(int i=0;i<n;i++) {
				if(arr[i]<i) {
					break;
				}
				pos=i;
			}
			int k=0;
			for(int i=n-1;i>=pos;i--) {
				if(arr[i]<n-1-i) {
					System.out.println("No");
					continue outer;
				}
				k++;
			}
			System.out.println("Yes");
		}
	}
}
