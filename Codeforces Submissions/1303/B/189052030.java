
import java.util.*;
import java.lang.Math.*;

public class MyClass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int count = 0;
        long[] answer = new long[t];
        while(t-- > 0) {
            long n = sc.nextLong();
            long g = sc.nextLong();
            long b = sc.nextLong();

            long ans = (n+1)/2;
            long total = ans/g * (g+b);
            if(ans % g == 0){
                total -= b;
            }else{
                total += ans %g;
            }
            answer[count++] = Math.max(n, total);

        }
        for(long b : answer){
            System.out.println(b);
        }
    }
}
class Point implements Comparable<Point>{
    public int x;
    public int y;
    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }
    public int compareTo(Point o){
        int real_value = Math.abs(o.x);
        int real_this_val = Math.abs(this.x);
        if(real_value > real_this_val){
            return -1;
        }else if(real_value == real_this_val){
            return 0;
        }
        return 1;
    }
}
				 	 	     		  		    	   		