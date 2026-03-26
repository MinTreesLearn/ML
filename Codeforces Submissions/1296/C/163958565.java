import java.io.*;
import java.util.*;
 
public class cf {
	public static void main(String[] args) throws IOException {

		BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//st = new StringTokenizer(br.readLine());
		
		int t = Integer.parseInt(br.readLine());

		while(t-->0){
			int n = Integer.parseInt(br.readLine());
			String s = br.readLine();
			Map<String,Integer> map = new HashMap<String, Integer>();

			int x = 0, y = 0,  l = n+1, r = 0; 

			map.put(x + " " + y, 0);

			for(int i=0; i<s.length(); i++){
				char ch = s.charAt(i);
				switch (ch){
					case 'L': x--; break;
					case 'R': x++; break;
					case 'U': y++; break;
					case 'D': y--; break;
				}
				String cord = x + " " + y;
				if(map.containsKey(cord)){
					int cl = i - map.get(cord);
					if(cl < l){
						l = cl; 
						r = i+1;
					}
					map.replace(cord, i+1);
				}       
				else 	map.put(cord, i+1);
			}
			if(l == n+1)	System.out.println(-1);
			else 	System.out.println(r-l + " " + r);
		}
	}
}