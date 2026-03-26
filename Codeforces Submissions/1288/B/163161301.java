import java.io.*;
import java.util.*;
 
public class sportmafia {
	public static void main(String[] args) throws IOException {

		Scanner input = new Scanner(System.in);

		int t = input.nextInt();

		while(t-->0){
			long A = input.nextLong();
			long B = input.nextLong();

			System.out.println(A*(long)Math.log10(B+1));
		}
	}
}