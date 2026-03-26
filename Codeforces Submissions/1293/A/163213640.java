import java.io.*;
import java.util.*;
 
public class cf {
	public static void main(String[] args) throws IOException {

		Scanner input = new Scanner(System.in);
		

		int t = input.nextInt();

		while(t-->0){
			int n = input.nextInt();
			int s = input.nextInt();
			int k = input.nextInt();

			HashSet<Integer> set = new HashSet<>();

			while(k-->0){
				set.add(input.nextInt());
			}

			int distance = 0;

			for(int i=0; i<n; i++){
				int down = s-i;
				int up = s+i;

				if(down>0 && !set.contains(down)){
					distance=i;
					break;
				}

				if(up<n+1 && !set.contains(up)){
					distance=i;
					break;
				}
			}

			System.out.println(distance);
		}
	}
}