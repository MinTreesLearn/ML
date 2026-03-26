import java.io.*;
import java.util.*;
public class d2prac implements Runnable 
{
	private boolean console=false;

	public void solve()
	{
		int i; int n=in.ni(); char a[]=in.ns().toCharArray(); int max[]=new int[n]; int min[]=new int[n]; int p=n;
		ArrayList<Integer> lo=new ArrayList(); ArrayList<Integer> hi=new ArrayList(); int left=0; 
		for(i=0;i<p-1;i++)
			if(a[i]=='<')
			{
				lo.add(n); hi.add(n); n--;
			}
		Collections.reverse(hi);
		max[0]=min[0]=n--;
		for(i=0;i<p-1;i++)
		{
			if(a[i]=='<')
			{
				int st=i; 
				while(i<p-1&&a[i]=='<')
				{
					min[i+1]=lo.remove(lo.size()-1); i++;  
				}
				i--;
				for(int j=i;j>=st;j--)
					max[j+1]=hi.remove(hi.size()-1);
			}
			else
			{
				min[i+1]=n; max[i+1]=n--;
			}
		}
		for(int v:max) out.print(v+" "); out.println();
		for(int v:min) out.print(v+" "); out.println();
	}
	@Override
	public void run() {
		try {  init();  }  
		catch (FileNotFoundException e) {  e.printStackTrace();  }

		int t= in.ni();

		while (t-->0) {
			solve();
			out.flush(); }
	}
	private FastInput in;    private PrintWriter out;
	public static void main(String[] args) throws Exception {	 new d2prac().run();	 }

	private void init() throws FileNotFoundException {
		InputStream inputStream = System.in; 	 OutputStream outputStream = System.out;
		try {  if (!console && System.getProperty("user.name").equals("sachan")) {
			outputStream = new FileOutputStream("/home/sachan/Desktop/output.txt");
			inputStream = new FileInputStream("/home/sachan/Desktop/input.txt");   	}
		}	catch (Exception ignored) {	}
		out = new PrintWriter(outputStream); 	 in = new FastInput(inputStream);
	}
	static class FastInput { InputStream obj;
	public FastInput(InputStream obj) {	this.obj = obj;	}
	byte inbuffer[] = new byte[1024];  int lenbuffer = 0, ptrbuffer = 0;
	int readByte() { if (lenbuffer == -1) throw new InputMismatchException();
	if (ptrbuffer >= lenbuffer) { ptrbuffer = 0;
	try { lenbuffer = obj.read(inbuffer);  }
	catch (IOException e) { throw new InputMismatchException(); } }    
	if (lenbuffer <= 0) return -1;return inbuffer[ptrbuffer++]; }

	String ns() { int b = skip();StringBuilder sb = new StringBuilder();
	while (!(isSpaceChar(b)))	  { sb.appendCodePoint(b);b = readByte(); }return sb.toString();}

	int ni() { int num = 0, b;boolean minus = false;
	while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
	if (b == '-') { minus = true;b = readByte(); }
	while (true) { if (b >= '0' && b <= '9') { num = num * 10 + (b - '0'); } else {
		return minus ? -num : num; }b = readByte(); }}

	long nl() { long num = 0;int b;boolean minus = false;
	while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
	if (b == '-') { minus = true;b = readByte(); }
	while (true) { if (b >= '0' && b <= '9') { num = num * 10L + (b - '0'); } else {
		return minus ? -num : num; }b = readByte(); } }

	boolean isSpaceChar(int c) { return (!(c >= 33 && c <= 126)); }
	int skip() { int b;while ((b = readByte()) != -1 && isSpaceChar(b)) ;return b; }
	float nf() {return Float.parseFloat(ns());}
	double nd() {return Double.parseDouble(ns());}
	char nc() {return (char) skip();}
	}
}

