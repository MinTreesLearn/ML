import java.util.*;
public class C {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		while(t-->0) {
			int n = sc.nextInt();
			char[] s = sc.next().toCharArray();
			Map<String, Integer> vis = new HashMap<String, Integer>();
			
			int x = 0, y = 0, step = 0;
			vis.put(x+" "+y, step);
			step++;
			
			int min = Integer.MAX_VALUE, p = -1;
			for(int i=0;i<n;i++) {
				if(s[i]=='U')
					y++;
				else if(s[i]=='D')
					y--;
				else if(s[i]=='L')
					x--;
				else
					x++;
				
				if(vis.containsKey(x+" "+y) && step-vis.get(x+" "+y)+1<min) {
					p = vis.get(x+" "+y);
					min = step-p+1;
				}
				vis.put(x+" "+y, step);
				step++;
			}
			
			System.out.println(p==-1 ? p : (p+1)+" "+(p+min-1));
		}
	}

}
