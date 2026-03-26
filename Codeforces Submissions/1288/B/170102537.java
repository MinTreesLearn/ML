import java.io.OutputStreamWriter;


import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
public class math {

	public static void main(String[] args) throws IOException {
		
	Scanner in = new Scanner(System.in);
BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int tt = in.nextInt();
		
		for(int w = 0; w<tt; w++) {
		int a = in.nextInt();
		int b = in.nextInt();
		
		
		int p = 9;
		int c = 0;
		
		while(p<=b) {
			p = p*10 +9;
			c++;
		}
		
		if(c==0) {
			log.write(0+"\n");
		}
		else {
			long t = (long) c*a;
			log.write(t+"\n");
		}
		log.flush();
		
		}

	}

}