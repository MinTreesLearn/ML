import java.util.Scanner;
 
public class codeforce {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int t=scan.nextInt();
		for(int tt=0;tt<t;tt++) {
			int n=scan.nextInt(), dist=scan.nextInt();
			boolean one=false;
			int max=0;
			for(int i=0;i<n;i++) {
				int x=scan.nextInt();
				if(dist==x) {
					one=true;
				}
				max=Math.max(max,x);
			}
			if(one) {
				System.out.println(1);
				continue;
			}
			System.out.println(Math.max((int)Math.ceil(dist*1.0/max),2));
		}
	}
}