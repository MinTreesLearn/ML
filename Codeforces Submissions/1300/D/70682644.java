import java.io.*;
import java.util.*;
import java.util.Map.Entry;


public class  gym{
	static final double EPS = 1e-9;
	static class Point implements Comparable<Point>{

    	

    	double x, y;                  

    	Point(double a, double b) { x = a; y = b; }  
    	
    	public int compareTo(Point p)
    	{
    		if(Math.abs(x - p.x) > EPS) return x > p.x ? 1 : -1;
    		if(Math.abs(y - p.y) > EPS) return y > p.y ? 1 : -1;
    		return 0;
    	}
    	public String toString() {
    		return "("+x+" "+y+")";
    	}
    	public long dist(Point p) { return sq((long)(x - p.x)) + sq((long)(y - p.y)); }
    	
    	static long sq(long x) { return x * x; }
    	
    	Point rotate(double angle)
    	{
    		double c = Math.cos(angle), s = Math.sin(angle);
    		return new Point(x * c - y * s, x * s + y * c);
    	}
    	// for integer points and rotation by 90 (counterclockwise) : swap x and y, negate x
    	
    	Point rotate(double theta, Point p)			//rotate around p
    	{
    		Vector v = new Vector(p, new Point(0, 0));
    		return translate(v).rotate(theta).translate(v.reverse());
    	}
    	
    	Point translate(Vector v) { return new Point(x + v.x , y + v.y); }
    	
    	
    	boolean between(Point p, Point q)
    	{
    		return x < Math.max(p.x, q.x) + EPS && x + EPS > Math.min(p.x, q.x)
    				&& y < Math.max(p.y, q.y) + EPS && y + EPS > Math.min(p.y, q.y);
    	}
    	
    	//returns true if it is on the line defined by a and b
    	boolean onLine(Point a, Point b) 
    	{
    		if(a.compareTo(b) == 0) return compareTo(a) == 0;
    		return Math.abs(new Vector(a, b).cross(new Vector(a, this))) < EPS;
    	}
    	
    	boolean onSegment(Point a, Point b)
    	{
    		if(a.compareTo(b) == 0) return compareTo(a) == 0;
    		return onRay(a, b) && onRay(b, a);
    	}
    	
    	//returns true if it is on the ray whose start point is a and passes through b
    	boolean onRay(Point a, Point b)
    	{
    		if(a.compareTo(b) == 0) return compareTo(a) == 0;
    		return new Vector(a, b).normalize().equals(new Vector(a, this).normalize());	//implement equals()
    	}
    	
    	// returns true if it is on the left side of Line pq
    	// add EPS to LHS if on-line points are accepted
    	static boolean ccw(Point p, Point q, Point r)
    	{
    		return new Vector(p, q).cross(new Vector(p, r)) > 0;
    	}
    	
    	static boolean collinear(Point p, Point q, Point r)
    	{
    		return Math.abs(new Vector(p, q).cross(new Vector(p, r))) < EPS;
    	}
    	
    	
    	
    	static double distToLine(Point p, Point a, Point b) //distance between point p and a line defined by points a, b (a != b)
    	{
    		if(a.compareTo(b) == 0) return p.dist(a);
    		// formula: c = a + u * ab
    		Vector ap = new Vector(a, p), ab = new Vector(a, b);
    		double u = ap.dot(ab) / ab.norm2();
    		Point c = a.translate(ab.scale(u)); 
    		return p.dist(c);
    	}
    	// Another way: find closest point and calculate the distance between it and p

    	static double distToLineSegment(Point p, Point a, Point b) 
    	{
    		Vector ap = new Vector(a, p), ab = new Vector(a, b);
    		double u = ap.dot(ab) / ab.norm2();
    		if (u < 0.0) return p.dist(a);
    		if (u > 1.0) return p.dist(b);        
    		return distToLine(p, a, b); 
    	}
    	// Another way: find closest point and calculate the distance between it and p
    }
	static class Vector {

    	double x, y; 

    	Vector(double a, double b) { x = a; y = b; }

    	Vector(Point a, Point b) { this(b.x - a.x, b.y - a.y); }

    	Vector scale(double s) { return new Vector(x * s, y * s); }              //s is a non-negative value

    	double dot(Vector v) { return (x * v.x + y * v.y); }

    	double cross(Vector v) { return x * v.y - y * v.x; }

    	double norm2() { return x * x + y * y; }

    	Vector reverse() { return new Vector(-x, -y); }

    	Vector normalize() 
    	{ 
    		double d = Math.sqrt(norm2());
    		return scale(1 / d);
    	}		
    }
	public static double angle(Point a, Point o, Point b)  // angle AOB
	{
		Vector oa = new Vector(o, a), ob = new Vector(o, b);
		return Math.acos(oa.dot(ob) / Math.sqrt(oa.norm2() * ob.norm2()));
	}
	static class Line {

    	static final double INF = 1e9, EPS = 1e-9;
    	
    	double a, b, c;
    	
    	Line(Point p, Point q)
    	{
    		if(Math.abs(p.x - q.x) < EPS) {	a = 1; b = 0; c = -p.x;	}
    		else
    		{
    			a = (p.y - q.y) / (q.x - p.x);
    			b = 1.0;
    			c = -(a * p.x + p.y);
    		}
    					
    	}
    	
    	Line(Point p, double m) { a = -m; b = 1; c =  -(a * p.x + p.y); } 
    	
    	boolean parallel(Line l) { return Math.abs(a - l.a) < EPS && Math.abs(b - l.b) < EPS; }
    	
    	boolean same(Line l) { return parallel(l) && Math.abs(c - l.c) < EPS; }
    	
    	Point intersect(Line l)
    	{
    		if(parallel(l))
    			return null;
    		double x = (b * l.c - c * l.b) / (a * l.b - b * l.a);
    		double y;
    		if(Math.abs(b) < EPS)
    			 y = -l.a * x - l.c;
    		else
    			y = -a * x - c;
    		
    		return new Point(x, y);
    	}
    	
    	Point closestPoint(Point p)
    	{
    		if(Math.abs(b) < EPS) return new Point(-c, p.y);
    		if(Math.abs(a) < EPS) return new Point(p.x, -c);
    		return intersect(new Line(p, 1 / a));
    	}
    			
    }
	static class pair implements Comparable<pair>{
		double a, b;
		pair(double  x,double y){
			a=x;b=y;
		}
		@Override
		public int compareTo(pair o) {
			if(Math.abs(a - o.a) > EPS) return a > o.a ? 1 : -1;
    		if(Math.abs(b - o.b) > EPS) return b > o.b ? 1 : -1;
    		return 0;
		}
		 
	}
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt();
		Point[] in1=new Point[n];
		for(int i=0;i<n;i++) {
			in1[i]=new Point(sc.nextInt(), sc.nextInt());
		}
		for(int i=0;i<n;i++) {
			Line l=new Line(in1[i], in1[(i+1)%n]);
			Line l2=new Line(in1[(i+n/2)%n], in1[(1+i+n/2)%n]);
			pair o=new pair(l.a,l.b);
			pair o2=new pair(l2.a,l2.b);
			//System.out.println(l.a+" "+l.b+" "+l2.a+" "+l2.b);
			long d1=in1[i].dist(in1[(i+1)%n]),d2=in1[(i+n/2)%n].dist(in1[(1+i+n/2)%n]);
			if(o.compareTo(o2)!=0 || d1!=d2) {
				pw.println("NO");
				pw.flush();return;
			}
			
		}
		pw.println("YES");
		pw.flush();
	}
	static class MScanner {
		StringTokenizer st;
		BufferedReader br;
		public MScanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}
 
		public MScanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public int[] takearr(int n) throws IOException {
	        int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public long[] takearrl(int n) throws IOException {
	        long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public Integer[] takearrobj(int n) throws IOException {
	        Integer[]in=new Integer[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public Long[] takearrlobj(int n) throws IOException {
	        Long[]in=new Long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
 
		public char nextChar() throws IOException {
			return next().charAt(0);
		}
 
		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}