// 1 Sec = 1e8 = 100000000
import java.util.Scanner;
import java.util.Vector;
import java.util.List;
import java.util.ArrayList;
public class Test{
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);

		// GCD(a,b) + LCM(a,b) = x
		// Note:
		// GCD(A , A) = LCM(A , A) = A
		// GCD(1 , Value) = 1
		// LCM(1 , Value) = Value
		// GCD(a,b) + LCM(a,b) = x --> GCD(1,b) + LCM(1,b) = x --> 1 + Value = x --> Value = x - 1
		int t = input.nextInt();
		int x;
		while(t-- != 0){
			x = input.nextInt();
			System.out.println(1 + " " + (x-1)); // We Will Consider The A = 1 And B = X - 1 Because He Said Print Any Of Pairs.
		}




	}
	static long gcd(long A , long B){ // O(Log(Max(A , B)))
		long Temp;
		while(B != 0){
			Temp = A;
			A = B;
			B = Temp % B;
		}
		return A;
	}
	static long lcm(long A , long B){
		// (A * B) / gcd(A, B);
		return A / gcd(A , B) * B; // Because If A = 1e18 And B = 1e18 Then Will Minimize This Step
	}
}