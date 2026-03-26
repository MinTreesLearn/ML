import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;

public class connerajftgdhjgfszdjsgb {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int tt = in.nextInt();
		
		for(int w = 0; w<tt; w++) {
		int n = in.nextInt();
		int s = in.nextInt();  //gdje se nalazi//
		int k = in.nextInt(); // broj zatvorenih//
		int[] a = new int[k];
		HashMap<Integer,Integer> hash =new HashMap<>();
		
		
		for(int i=0; i<k; i++) {
			a[i] = in.nextInt();
			hash.put(a[i], 1);
		}
		int ans = 0;
		for(int i = 0; i<=k; i++) {
			if( s-i>0 && !hash.containsKey(s-i)) {
				ans = i;
				break;
			}
			else if( s+i<=n && !hash.containsKey(s+i)) {
				ans = i;
				break;
			}
		}
		log.write(ans+"\n");
		log.flush();
		
		
		
		}

	}

}
