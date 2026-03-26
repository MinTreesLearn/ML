import java.util.*;
public class Main {
    
	public static void main (String[] args) {
	    Scanner s = new Scanner(System.in);
		long x0 = s.nextLong();
		long y0 = s.nextLong();
		long ax = s.nextLong();
		long ay = s.nextLong();
		long bx = s.nextLong();
		long by = s.nextLong();
		long xs = s.nextLong();
		long ys = s.nextLong();
		long t = s.nextLong();
		ArrayList<Long> x = new ArrayList<>();
		ArrayList<Long> y = new ArrayList<>();
		long temp = Math.abs(xs-x0) + Math.abs(ys-y0);
		x.add(x0);
		y.add(y0);
		while (true){
		    long newx = ax*x.get(x.size()-1) + bx;
		    long newy = ay*y.get(y.size()-1) + by;
		    //System.out.println(newx + " " + newy);
		    long dist = Math.abs( newx - xs ) + Math.abs( newy - ys );
		    if(dist<0)
		    break;
		    if( newx<=0 && newy<=0  )
		    {
		        break;
		    }
		    if( newx < x.get(x.size()-1) || newy < y.get(y.size()-1) )
		    break;
		    x.add(newx);
		    y.add(newy);
		}
		int answer = 0;
		int size = x.size();
		long[][] dp = new long[size][size];
		for(int dif=0;dif<size;dif++)
		{
		    for(int l=0;l<size;l++)
		    {
		        int r = l + dif;
		        if(r>=size)
		        break;
		        if(l==r)
		        {
		            dp[l][r] = 0;
		            long yy = Math.abs(xs-x.get(l)) + Math.abs(ys-y.get(l)) + dp[l][r];
		            if(yy <=t)
		            {
		                int z = r-l+1;
		                if(z>answer)
		                answer = z;
		            }
		        }
		        else
		        {
		            dp[l][r] = dp[l][l+1] + dp[l+1][r];
		            if((r-l)==1)
		            {
		                dp[l][r] = x.get(r)-x.get(l) + y.get(r) - y.get(l);
		            }
		            long yy = Math.min( Math.abs(xs-x.get(l)) + Math.abs(ys-y.get(l)) ,  
		                               Math.abs(xs-x.get(r)) + Math.abs(ys-y.get(r)) );
		            if(yy <=(t-dp[l][r]))
		            {
		                int z = r-l+1;
		                if(z>answer)
		                answer = z;
		            }
		        }
		    }
		}
		/*for(int i=0;i<size;i++)
		{
		    System.out.println(x.get(i)+" "+y.get(i));
		    for(int j=0;j<size;j++)
		    System.out.print(dp[i][j]+" ");
		    System.out.println();
		}*/
		System.out.println(answer);
	}
}