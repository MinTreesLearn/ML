import java.util.Scanner;

public class Main{
	private static Scanner in = new Scanner(System.in);
	public static void solve(){
		int n=in.nextInt();
		in.nextLine();
		String s=in.nextLine();
		int numOdd=0;
		for(int i=0;i<n;i++)
			if((s.charAt(i)-'0')%2==1)numOdd++;
		if(numOdd<=1)
			System.out.println(-1);
		else{
			int ii=0;
			for(int i=0;i<n;i++)
			if((s.charAt(i)-'0')%2==1){
				System.out.print(s.charAt(i));
				ii++;
				if(ii==2)break;
			}
			System.out.println();
		}
	}
	public static void main(String[] args){
		int t=in.nextInt();
		while(t>0){t--;solve();}
	}
}