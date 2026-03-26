import java.util.Scanner;

public class Main{
	private static Scanner in=new Scanner(System.in);
	public static void solve(){
		int n=in.nextInt();
		int[] res=new int[n/2];
		int idx=0;
		if(n%2==0){
			n/=2;
			for(int i=0;i<n;i++)res[idx++]=1;
		}else if(n%2==1){
			res[idx++]=7;
			n-=3;
			n/=2;
			for(int i=0;i<n;i++)res[idx++]=1;
		}
		for(int i=0;i<idx;i++)System.out.print(res[i]);
		System.out.println();
	}
	public static void main(String[] args){
		int t=in.nextInt();
		while(t>0){t-=1;solve();}
	}
}