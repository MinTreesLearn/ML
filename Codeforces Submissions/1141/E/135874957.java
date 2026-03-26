				
			 import java.util.*;
			 import java.math.*;
			 import java.io.*; 
			 import java.util.stream.Collectors;
	import java.text.DecimalFormat;
		       public class A{
		              static FastScanner scan=new FastScanner();
		              public static PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));
		static int n;
		static long PS[];
		static long MIN[];
		static boolean check(long x,long TH)
		{

			TH+=(PS[n-1]*((x-(x%n))/n));
		//	TH+=(PS[n-1]*((x-(x%n))/n));
			x=x%n;
			x--;
		//	out.println(x);
			if(x>=0)
			TH+=MIN[(int)x];
         
			return TH<=0;
		}

				public static void main(String[] args)  throws Exception 
				     {		
				  			
					int tt=1;
					
				
		//	System.out.println(check(0));
		//			tt=scan.nextInt();
			//	scan=new FastScanner("clumsy.in");
				//out=new PrintWriter("clumsy.out");

				outer:while(tt-->0)
					{
long H=scan.nextLong();
long TH=H;
						 n=scan.nextInt();
						 long arr[]=new long[n];
						 MIN=new long[n];
						 PS=new long[n];
						 for(int i=0;i<n;i++)
						 {
						 	arr[i]=scan.nextLong();
						 	TH+=arr[i];
						 	if(TH<=0)
						 	{
						 		out.println(i+1);
						 		out.close();
						 		return;
						 	}
						 }
						 PS[0]=arr[0];
						 for(int i=1;i<n;i++)
						 {
						 	PS[i]=arr[i];
						 	PS[i]+=PS[i-1];
						 }
						 MIN[0]=PS[0];
						 for(int i=1;i<n;i++)
						 {
						 	MIN[i]=Math.min(PS[i],MIN[i-1]);
						 }
						 if(PS[n-1]>=0)
						 {
						 	out.println(-1);
						 	out.close();
						 	return;
						 }
						 long l=1,r=(long)1e18,ans=(long)1e18+5;
//out.println(PS[n-1]);
//out.println(H)
					//out.println(check(4301,H));
						long abs=-PS[n-1];
						for(int i=0;i<n;i++)
						{
							if(PS[i]>=0)
								continue;
							TH=H;

							TH+=PS[i];
							ans=Math.min(ans,(i+1)+((TH/abs)+(TH%abs==0?0:1))*n);
//out.println(ans+" "+i+" "+TH+" "+PS[0]+" "+((TH/abs)+(TH%abs==0?0:1))*n);
						
						}
						 out.println(ans);


						

	}
				out.close();
							}
							
					
				
										   
										    
										  
										     static class FastScanner
								{
								    private int BS = 1 << 16;
								    private char NC = (char) 0;
								    private byte[] buf = new byte[BS];
								    private int bId = 0, size = 0;
								    private char c = NC;
								    private double cnt = 1;
								    private BufferedInputStream in;
								 
								    public FastScanner() {
								        in = new BufferedInputStream(System.in, BS);
								    }
								 
								    public FastScanner(String s) {
								        try {
								            in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
								        } catch (Exception e) {
								            in = new BufferedInputStream(System.in, BS);
								        }
								    }
								 
								    private char getChar() {
								        while (bId == size) {
								            try {
								                size = in.read(buf);
								            } catch (Exception e) {
								                return NC;
								            }
								            if (size == -1) return NC;
								            bId = 0;
								        }
								        return (char) buf[bId++];
								    }
								 
								    public int nextInt() {
								        return (int) nextLong();
								    }
								 
								    public int[] nextInts(int N) {
								        int[] res = new int[N];
								        for (int i = 0; i < N; i++) {
								            res[i] = (int) nextLong();
								        }
								        return res;
								    }
								 
								    public long[] nextLongs(int N) {
								        long[] res = new long[N];
								        for (int i = 0; i < N; i++) {
								            res[i] = nextLong();
								        }
								        return res;
								    }
								 
								    public long nextLong() {
								        cnt = 1;
								        boolean neg = false;
								        if (c == NC) c = getChar();
								        for (; (c < '0' || c > '9'); c = getChar()) {
								            if (c == '-') neg = true;
								        }
								        long res = 0;
								        for (; c >= '0' && c <= '9'; c = getChar()) {
								            res = (res << 3) + (res << 1) + c - '0';
								            cnt *= 10;
								        }
								        return neg ? -res : res;
								    }
								 
								    public double nextDouble() {
								        double cur = nextLong();
								        return c != '.' ? cur : cur + nextLong() / cnt;
								    }
								 
								    public double[] nextDoubles(int N) {
								        double[] res = new double[N];
								        for (int i = 0; i < N; i++) {
								            res[i] = nextDouble();
								        }
								        return res;
								    }
								 
								    public String next() {
								        StringBuilder res = new StringBuilder();
								        while (c <= 32) c = getChar();
								        while (c > 32) {
								            res.append(c);
								            c = getChar();
								        }
								        return res.toString();
								    }
								 
								    public String nextLine() {
								        StringBuilder res = new StringBuilder();
								        while (c <= 32) c = getChar();
								        while (c != '\n') {
								            res.append(c);
								            c = getChar();
								        }
								        return res.toString();
								    }
								 
								    public boolean hasNext() {
								        if (c > 32) return true;
								        while (true) {
								            c = getChar();
								            if (c == NC) return false;
								            else if (c > 32) return true;
								        }
								    }
								}

										     static class Pair implements Comparable<Pair>{
										            public long x, y,z;
										            public Pair(long x1, long y1,long z1) {
										                x=x1;
										                y=y1;
										                z=z1;
										            }
										             public Pair(long x1, long y1) {
										                x=x1;
										                y=y1;
										    
										            }
										            
										            @Override
										            public int hashCode() {
										                return (int)(x + 31 * y);
										            }
										            public String toString() {
										                return x + " " + y+" "+z;
										            }
										            @Override
										            public boolean equals(Object o){
										                if (o == this) return true;
										                if (o.getClass() != getClass()) return false;
										                Pair t = (Pair)o;
										                return t.x == x && t.y == y&&t.z==z;
										            }
										    public int compareTo(Pair o)
										    {
										  	
										return (int)(o.x-x);
										     
										        }
										     
										    }
										}

										
										    
										   

										     
