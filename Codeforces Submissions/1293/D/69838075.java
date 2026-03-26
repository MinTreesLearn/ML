import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long x0 = sc.nextLong();
		long y0 = sc.nextLong();
		long ax = sc.nextLong();
		long ay = sc.nextLong();
		long bx = sc.nextLong();
		long by = sc.nextLong();
		
		long xs = sc.nextLong();
		long ys = sc.nextLong();
		long t = sc.nextLong();
		
		
		
		LinkedList<Long> x = new LinkedList<>();
		LinkedList<Long> y = new LinkedList<>();
		x.add(x0);
		y.add(y0);
		
		int size = x.size();
		long max = Long.MAX_VALUE;
		while((max-bx)/ax>=x.get(size-1) && (max-by)/ay>=y.get(size-1)) {
			x.add(ax * x.get(size-1) + bx);
			y.add(ay * y.get(size-1) + by);
			size++;
		}
		
		int ans = 0;
		for(int i=0;i<size;i++) {
			for(int j=i;j<size;j++) {
				long lr = x.get(j) - x.get(i) + y.get(j) - y.get(i);
				long sl = Math.abs(xs-x.get(i)) + Math.abs(ys-y.get(i));
				long sr = Math.abs(xs-x.get(j)) + Math.abs(ys-y.get(j));
				
				if(lr>=0 && sl>=0 && sr>=0 && (lr<=t-sl || lr<=t-sr))
					ans = (ans >= j-i+1) ? ans : j-i+1;
				else
					break;
			}
		}
		
		System.out.println(ans);
	}

}
