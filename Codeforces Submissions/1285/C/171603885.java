import java.util.*;
public class Main{

	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		long x = sc.nextLong();
		long ans = 1;
		for(long i=1; i<=Math.sqrt(x); i++){
			if(x%i==0&&gcd(i,x/i)==1){
				ans = i;
			}
		}
		System.out.println(ans+ " "+ (x/ans));
	}

	static long gcd(long a, long b){
		if(a%b==0) return b;
		return gcd(b, a%b);
	}
}