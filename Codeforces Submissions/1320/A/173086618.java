import java.util.HashMap;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class journey {
	
 
	public static void main(String[] args) throws IOException {
	
		
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
		int[] a = new int[n];
		HashMap<Integer,Long> h = new HashMap<>();
		int max =  0;
		
		for(int i = 0; i<n; i++) {
			a[i] = in.nextInt();
			max = Math.max(a[i], max);
	}
		
		long ans = max;
		
		for(int i  = 0; i<n; i++) {
			int x = a[i]-i;
			
			h.put(x, h.getOrDefault(x,0L)+a[i]);
			ans = Math.max(ans,h.get(x));
		}
		
		log.write(ans+"\n");
		log.flush();
		
		

}

	
}