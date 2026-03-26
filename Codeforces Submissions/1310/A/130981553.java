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
			static int BIT[];
			static int BIT2[];
			static int n;
			static int get(int x){
				int res=0;
				x--;
				while(x>=1)
				{
					res+=BIT[x];
					x-=(x&-x);
				}
				return res;
			}
			static void update(int x,int val)
			{
				//x++;
				while(x<=n)
				{
					BIT[x]+=val;
					x+=(x&-x);
				}
			}
			static int get2(int x)
			{
				int res=0;
				x++;
				while(x<=n)
				{
					res+=BIT2[x];
					x+=(x&-x);
				}
				return res;
			}
			static void update2(int x,int val)
			{
				int res=0;
				//x--;
				while(x>=1)
				{
					//res+=BIT2[x];
					BIT2[x]+=val;
					x-=(x&-x);
				}
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
							   
	//			scan=new FastScanner("D:\\usaco test data\\WW.txt");
	//			out = new PrintWriter("D:\\usaco test data\\WWW.txt");

							
										 							 /*
										 READING 
								
										 3-Introduction to DP with Bit-masking codeforces
										 4-Bit Manipulation hacker-earth
										 5-read more about mobious and inclusion-exclusion 
					 				     6-read more about Fermat little theorem
										 */
										 /*
										   
										 */

					 			
								     
	int tt=1;

								//	tt=scan.nextInt();
									int T=tt;
									 outer:while(tt-->0)
									    {
									    int n=scan.nextInt();
									    Pair arr[]=new Pair[n];
									    Map<Integer,ArrayDeque<Integer>>map=new HashMap<Integer,ArrayDeque<Integer>>();
									   
									    for(int i=0;i<n;i++){
									    	arr[i]=new Pair(scan.nextInt(),0);									    	
									    }
									    for(int i=0;i<n;i++)
									    	arr[i].y=scan.nextInt();
									    PriorityQueue<Long>pq=new PriorityQueue<Long>(Collections.reverseOrder());
									 Arrays.sort(arr);
									long sum=0,res=0;
									int i=0;
									    for(int g=-100;pq.size()>0||i<n;g++)
									    {
									    	while(i<n&&arr[i].x<=g)
									    	{
									    		sum+=arr[i].y;
									    		pq.add(arr[i].y);
									    		i++;
									    	}
									    	if(pq.size()>0)
									    	{
									    		sum-=pq.poll();
									    	}
									    	else{
									    	if(i<n)
									    		g=(int)arr[i].x-1;
									    }
									    	res+=sum;
									    }
									    out.println(res);




									    									    	
	  			   	
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
										    								  	
										return (int)(x-o.x);
										     
										        }
										     
										    }
										}
										
										    
										   

										     
