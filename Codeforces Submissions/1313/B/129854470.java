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
									    import java.text.DecimalFormat;
									    import java.util.stream.Collectors;


									       public class A{
							            static FastScanner scan=new FastScanner();
										     public static PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));
static int brute(int i,ArrayList<Integer>GG[],int ans)
{
    if(i==idx){
    //	out.println("AHA");
        return ans;
    }
   //out.println("FUCK");
    int max=0;
    if(GG[i].size()==0)
    {
    	max=Math.max(max,brute(i+1,GG,ans));
    }
    for(int j:GG[i])
    {
    //	out.println("AHA "+gcd(ans,j)+" "+i+" "+GG.length);
        max=Math.max(max,brute(i+1,GG,gcd(ans,j)));
    }
    return max;
}
static int gcd(int x,int y)
{
	if(x==0)
		return y;
	return gcd(y%x,x);
}

//static int gcdS[];
static boolean vis[];
static LinkedList<Pair>edges[];
static Set<Integer>GG[];
static int idx=0;
static void dfs(int x,int fi,int gcd)
{
	vis[x]=true;
	boolean is=false;
	for(Pair v:edges[x])
	{
		if(!vis[(int)v.x])
		{
		//	gcdS[x]=(int)v.y;
			is=true;
			dfs((int)v.x,fi,gcd(gcd,(int)(v.y)));
			//gcdS[x]=gcd(gcdS[x],gcdS[(int)v.x]);
		//	out.println(gcdS[x]);
			//if(x==fi)
			//	GG[idx].add(gcdS[x]);
		//	out.println(x+1);
		}
	}
	if(!is){
//out.println(gcd);
	GG[idx].add(gcd);
}
	//out.println(x+1);
}
			public static void main(String[] args)  throws Exception 
							      {
							 /*
							 very important tips 
							 1-just fucking think backwards once in your shitty life
							 2-consider brute forcing and finding some patterns and observations
							 3-when you're in contest don't get out because you think there is no enough time
							 4-don't get stuck on one approach 
							 */
						   
			//scan=new FastScanner("D:\\usaco test data\\WW.txt");
			//out = new PrintWriter("D:\\usaco test data\\WW.txt");

						
									 							 /*
									 READING 
							
									 3-Introduction to DP with Bit-masking codeforces
									 4-Bit Manipulation hacker-earth
									 5-read more about mobious and inclusion-exclusion 
				 				     6-read more about Fermat little theorem
									 */
									 /*
									   -if the two persons are on the same line then it's not possible because that means the shortest path is either abs(x2-x1) or abs(y2-y1) and Manhattan will be abs(x2-x1)+abs(y2-y1) and it's obvious that it will be at least equal 
									   -if the first person is on vertical and second is on horizontal then it's not possible  
									 */

				 			
									      
int tt=1;
								tt=scan.nextInt();
								int T=1;
								 outer:while(tt-->0)
								    {
								   int n=scan.nextInt(),f=scan.nextInt(),s=scan.nextInt();
								   if(f+s<=n)
								   {
								   	out.println(1+" "+(f+s-1));
								   }
								   else 
								   {
								   	
								   
								   	out.println(Math.min(n,(f+s-n+1))+" "+n);
								   }


							   
								  			   	
	 }							
	
        

			out.close();
						}
						
						

						static class special implements Comparable<special>{
						int cnt,idx;
						String s;
						public special(int cnt,int idx,String s)
						{
							this.cnt=cnt;
							this.idx=idx;
							this.s=s;
						}

							 @Override
									            public int hashCode() {
									                return (int)42;
									            }
							  @Override
									            public boolean equals(Object o){
									            //	System.out.println("FUCK");
									                if (o == this) return true;
									                if (o.getClass() != getClass()) return false;
									                special t = (special)o;
									                return t.cnt == cnt && t.idx == idx;
									            }
									            public int compareTo(special o1)
									            {
									            	if(o1.cnt==cnt)
									            	{
									            		return o1.idx-idx;
									            	}
									            	return o1.cnt-cnt;
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
									    private static void sort(int[] arr) {
									            List<Integer> list = new ArrayList<>();
									            for (int object : arr) list.add(object);
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
									    								  	
									  if(x==o.x)
									  	return (int)(y-o.y);
									    	return (int)(x-o.x);
									     
									        }
									     
									    }
									}
									
									    
									   

									     
