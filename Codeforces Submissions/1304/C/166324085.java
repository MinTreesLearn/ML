import java.util.*;
public class AirConditioner {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		outer:
		while(t-->0) {
			int n=sc.nextInt();
			int temp=sc.nextInt();
			long arr[][]=new long[n+1][3];
			for(int i=1;i<=n;i++) {
				arr[i][0]=sc.nextInt();
				arr[i][1]=sc.nextInt();
				arr[i][2]=sc.nextInt();
			}
			arr[0][0]=0;
			arr[0][1]=temp;
			arr[0][2]=temp;
			long a=0,h=0,l=0;
			for(int i=1;i<=n;i++) {
				a=arr[i][0]-arr[i-1][0];
				l=arr[i-1][1]-a;
				h=arr[i-1][2]+a;
				if(l<=arr[i][2] && h>=arr[i][1]) {
					arr[i][1]=Math.max(arr[i][1],l);
					arr[i][2]=Math.min(arr[i][2],h);
				}
				else {
					System.out.println("NO");
					continue outer;
				}
			}
//			System.out.println(Arrays.deepToString(arr));
			System.out.println("YES");
		}
	}

}
