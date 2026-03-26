import java.util.Scanner;
public class problemUnnamed {
	static Scanner sc= new Scanner(System.in);
	public static void main(String[] args) {
		int x=sc.nextInt();
		int n;
		int d;
		for(int i=0;i<x;i++) {
			if(testCases()) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
			
		}
		
	}
	public static boolean testCases() {
		int n=sc.nextInt();
		int d=sc.nextInt();
		if(n>=d) {
			return true;
		}
		return optimize(n,d);
		
	}
	//d is greater than n
	public static boolean optimize(int n,int d) {
		
		for(int i=n;i>0;i--) {
			if(func(d,i)<=n){
				return true;
			}
		}
		return false;
		
		
	}
	
	
	
	
	
	public static int func(int d, int i) {
		double x =i+(double)d/(i+1);
		int y=i+d/(i+1);
		if(x>y) {
			return y+1;
		}
		return y;
	}
}