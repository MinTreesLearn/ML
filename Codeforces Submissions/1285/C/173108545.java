import java.util.*;
public class Main{
      
	static long gcd(long a, long b){
		if(a%b==0) return b;
		return gcd(b, a%b);
	}

	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		long x = sc.nextLong();
		long a = 1;
		for(long i=1; i*i<=x; i++){
			if(x%i==0&&gcd(i,x/i)==1)	a = i;
		}
		System.out.println(a+ " "+ (x/a));
	}


}