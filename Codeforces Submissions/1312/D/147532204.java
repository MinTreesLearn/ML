
import java.util.*;
import java.io.*;

public class CounttheArrays {
	// https://codeforces.com/problemset/problem/1312/D
	
	// I HAVE RIGHT CLOSED FORM, CAN'T DO THE FACTORIALs
	
	static long[] fact, inv_fact;
	static long mod = 998244353;
	
	public static void main(String[] args) throws IOException, FileNotFoundException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader in = new BufferedReader(new FileReader("CounttheArrays.in"));
		// INPUT //

		StringTokenizer st = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(st.nextToken());  
		int m = Integer.parseInt(st.nextToken());  
		long result = 1;
		
		fact = new long[Math.max(m+1, n+1)]; 
		inv_fact = new long[Math.max(m+1, n+1)];
		fact[0] = inv_fact[0] = 1;
		for (int i=1; i<fact.length; i++) {
			fact[i] = fact[i-1] * i;
			fact[i] %= mod;
			inv_fact[i] = pow(fact[i], mod-2, mod);
		}

		result *= choose(m, n-1);
		result %= 998244353;
		result *= (n-2);
		result %= 998244353 ;
		result *= pow(2, n-3, 998244353);
		result %= 998244353;

		// OUTPUT //
		System.out.println(result);

	}
	

    static long pow(long a, long b, long m) {
    	long ans=1;
    	while (b >0) {
    		if (b%2 == 1) {
    			ans *= a;
    			ans %= m;
    		}
    		a *= a;
    		a %= m;
    		b >>= 1;
    	}
    	return ans;
    }

	// top! / bottom! (top - bottom)!
	public static long choose(int top, int bottom) {
		return fact[top] * inv_fact[bottom] % mod * inv_fact[top - bottom] % mod;
	}
	
}

/*

	CLosed form is easy to find
	{m choose n-1} * (n-2) * 2^{n-3}

	// too large
		if (n-1 > m-n+1) {
			for (int i = m; i >= n; i--) {
				result *= i;
			}
			for (int i = m-n+1; i >= 2; i--) {
				result /= i;
			}

		}
		else {
			for (int i = m; i >= m-n+2; i--) {
				result *= i;
			}
			for (int i = n-1; i >= 2; i--) {
				result /= i;
			}
		}
	
	
	ArrayList<Long> factorial = new ArrayList<>();
		factorial.add((long) 1);
		for (int i = 1; i <= m; i++) {
			factorial.add(factorial.get(i-1) * i % 998244353);
			System.out.print(i + " " + factorial.get(i));
			System.out.println();
		}
			
		result *= factorial.get((int) m);
		result /= factorial.get((int) (n-1));
		result /= factorial.get((int) (m-n+1));

*/