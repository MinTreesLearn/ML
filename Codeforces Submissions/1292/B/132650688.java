					/*
					ID: abdelra29
LANG: JAVA
PROG: zerosum
					*/
						/*
						TO LEARN
				
						2-euler tour
					
						*/
						/*
						TO SOLVE 
						codeforces 722 kavi on pairing duty
						*/
						/*
						bit manipulation shit
						1-Computer Systems: A Programmer's Perspective
						2-hacker's delight
						*/
						/*
						TO WATCH
						
						*/
						            import java.util.*;
								    import java.math.*;
								    import java.io.*; 
								    import java.util.stream.Collectors;

								       public class A{
						            static FastScanner scan=new FastScanner();
									     public static PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));

static long pow,ans;
static BigInteger xs,ys;
				public static void main(String[] args)  throws Exception 
						      {
						 /*
						 very important tips 
						 1-just fucking think backwards once in your shitty life
						 2-consider brute forcing and finding some patterns and observations
						 3-when you're in contest don't get out because you think there is no enough time
						
						 */
						
							//scan=new FastScanner("binary.in");
								///out = new PrintWriter("zerosum.out");
								 
								 							 /*
								 READING 
							
								 3-Introduction to DP with Bitmasking codefoces
								 4-Bit Manipulation hackerearth
								 5-read more about mobious and inculsion-exclusion 
								 */
								 /*
								

								 */
								
					
								    int tt=1;
								 
								    
			//	tt=scan.nextInt();
				int T=1;

							 outer:while(tt-->0)
								    {
								    	BigInteger x0=new BigInteger(scan.next());
								    	BigInteger y0=new BigInteger(scan.next());
								    	BigInteger ax=new BigInteger(scan.next());
								    	BigInteger ay=new BigInteger(scan.next());
								    	BigInteger bx=new BigInteger(scan.next());
								    	BigInteger by=new BigInteger(scan.next());
								    	 xs=new BigInteger(scan.next());
								    	 ys=new BigInteger(scan.next());
								    	 BigInteger t=new BigInteger(scan.next());
								    	//long secondX=ax*x0+bx,secondY=ay*y0+by;
								    	//long diff=secondX-x0,diff2=secondY-y0;*/
								    	ArrayList<BigInteger[]>have=new ArrayList<BigInteger[]>();
								    		have.add(new BigInteger[]{x0,y0});
								    	//have.add(new Pair(secondX,secondY));
								    	for(int i=0;i<100;i++)
								    	{
								    	
								    	BigInteger secondX=ax.multiply(have.get(have.size()-1)[0]).add(bx);
								    	BigInteger secondY=ay.multiply(have.get(have.size()-1)[1]).add(by);
								    		//if((secondX.subtract(have.get(have.size()-1)[0])).abs().add(secondY.subtract(have.get(have.size()-1)[1]).abs())>=0)
								    		have.add(new BigInteger[]{secondX,secondY});
								    	}
								    	//have.remove(0);
								    	//out.println(have);
								    	int res=0;

								    	for(int i=0;i<have.size();i++)
								    	{
								    		BigInteger tmpT=t,tmpXs=xs,tmpYs=ys;
								    		int cnt=0;
								    		for(int j=i;j<have.size();j++)
								    		{
								    			BigInteger first=have.get(j)[0].subtract(tmpXs);
								    			//System.out.println(tmpYs);
								    			BigInteger second=have.get(j)[1].subtract(tmpYs);
								    			BigInteger my1=(have.get(i)[0].subtract(tmpXs).abs()).add(have.get(i)[1].subtract(tmpYs).abs());
								    			BigInteger my2=(have.get(j)[0].subtract(tmpXs).abs()).add(have.get(j)[1].subtract(tmpYs).abs()); 

								    			if((have.get(j)[0].subtract(have.get(i)[0]).abs()).add(have.get(j)[1].subtract(have.get(i)[1]).abs()).compareTo(tmpT.subtract(my1))>0&&(have.get(j)[0].subtract(have.get(i)[0]).abs()).add(have.get(j)[1].subtract(have.get(i)[1]).abs()).compareTo(tmpT.subtract(my2))>0)
								    				break;
								    			if((have.get(j)[0].subtract(have.get(i)[0]).abs()).add(have.get(j)[1].subtract(have.get(i)[1]).abs()).compareTo(tmpT.subtract(my1))>0&&(have.get(j)[0].subtract(have.get(i)[0]).abs()).add(have.get(j)[1].subtract(have.get(i)[1]).abs()).compareTo(tmpT.subtract(my2))<=0){
								    				//out.println(Arrays.toString(have.get(j))+" "+Arrays.toString(have.get(i)));
								    				//out.println("FUCK");
								    			}

//out.println(j);
								    			res=Math.max(res,j-i+1);
								    	//		tmpT=tmpT.subtract((have.get(j)[0].subtract(tmpXs).abs()).add(have.get(j)[1].subtract(tmpYs).abs()));
								    	//	tmpXs=have.get(j)[0];
								    	//	tmpYs=have.get(j)[1];
								    		cnt++;
								    		}
								    		//out.println();
								    		res=Math.max(res,cnt);
								    	} 
								    	
								  
								    	
								    	out.println(res);

	 }

								

		out.close();
					}
					static class DSU{
						int par[];
						long size[];

						public DSU(int n)
						{
							par=new int[n+1];
							size=new long[n+1];
							for(int i=0;i<n;i++)
								par[i]=i;
							Arrays.fill(size,1L);
						}
						void con(int x,int y)
						{
							x=find(x);
							y=find(y);
						//	System.out.println("X "+x+" Y "+y);
							if(x==y)
								return;
							//System.out.println("FUCK");
							ans-=(this.sz(x)*this.sz(y));
							//ans-=sz(y);
							//pow*=2;
							if(size[x]<=size[y])
							{
								par[x]=y;
								size[y]+=size[x];
							}
							else 
							{
								par[y]=x;
								size[x]+=size[y];
							}
						}
						int find(int x)
						{
							if(x==par[x])
								return x;
							return par[x]=find(par[x]);
						}
						boolean is(int x,int y)
						{
							return find(x)==find(y);
						}
						long sz(int x)
						{
							return size[find(x)];
						}

					}
					

					static class special{
					boolean is;
					char c;
					public special(boolean is,char c)
					{
						this.is=is;
						this.c=c;
					}

						 @Override
								            public int hashCode() {
								                return (int)(c+ 31 *(is?1:0));
								            }
						  @Override
								            public boolean equals(Object o){
								            //	System.out.println("FUCK");
								                if (o == this) return true;
								                if (o.getClass() != getClass()) return false;
								                special t = (special)o;
								                return t.is == is && t.c == c;
								            }
					}
		
								   
								     static long binexp(long a,long n)
								    {
								        if(n==0)
								            return 1;
								        long res=binexp(a,n/2);
								        if(n%2==1)
								            return res*res*a;
								        else 
								            return res*res;
								    }
								     
								    static long powMod(long base, long exp, long mod) {
								           if (base == 0 || base == 1) return base;
								           if (exp == 0) return 1;
								           if (exp == 1) return (base % mod+mod)%mod;
								           long R = (powMod(base, exp/2, mod) % mod+mod)%mod;
								           R *= R;
								           R %= mod;
								           if ((exp & 1) == 1) {
								               return (base * R % mod+mod)%mod;
								           }
								           else return (R %mod+mod)%mod;
								       }
								    static double dis(double x1,double y1,double x2,double y2)
								    {
								        return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
								    }
								    static long mod(long x,long y)
								        {
								            if(x<0)
								                x=x+(-x/y+1)*y;
								            return x%y;
								        }
								     public static  long pow(long b, long e) {
								                long r = 1;
								                while (e > 0) {
								                    if (e % 2 == 1) r = r * b ;
								                    b = b * b;
								                    e >>= 1;
								                }
								                return r;
								            }
								    private static void sort(long[] arr) {
								            List<Long> list = new ArrayList<>();
								            for (long object : arr) list.add(object);
								            Collections.sort(list);
								        //Collections.reverse(list);
								            for (int i = 0; i < list.size(); ++i) arr[i] = list.get(i);
								        }
								    private static void sort2(long[] arr) {
								            List<Long> list = new ArrayList<>();
								            for (Long object : arr) list.add(object);
								            Collections.sort(list);
								        Collections.reverse(list);
								            for (int i = 0; i < list.size(); ++i) arr[i] = list.get(i);
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
								  	
								return (int)(x-o.x);
								     
								        }
								     
								    }
								}
								
								    
								   

								     
