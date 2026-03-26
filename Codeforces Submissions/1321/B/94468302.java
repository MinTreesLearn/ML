import java.io.*;
import java.util.*;
public class Pb{
	public static void main(String[] args) throws IOException{
		FastReader sc = new FastReader();
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(java.io.FileDescriptor.out),"ASCII"),512);
			int n = sc.nextInt();
			int[] a = new int[n];
			for(int i=0;i<n;i++){
				a[i] = sc.nextInt();
			}
			long[] b = new long[(int)7e5];
			for(int i=0;i<n;i++) b[a[i]-i+n+1] += a[i];
			long op = 0;
			for(int i=0;i<(int)7e5;i++) op = Math.max(op, b[i]);
			out.write(op + "");
			out.write('\n');
		out.flush();
	}
}
class FastReader{
	BufferedReader br;
	StringTokenizer st;
	public FastReader(){
		br = new BufferedReader(new InputStreamReader(System.in));
	}
	String next(){
		while(st == null || !st.hasMoreElements()){
			try{ 
				st = new StringTokenizer(br.readLine()); 
			} 
			catch (IOException  e){ 
				e.printStackTrace(); 
			} 
		} 
		return st.nextToken();
	}
	int nextInt(){ 
        return Integer.parseInt(next()); 
	}
    long nextLong(){ 
        return Long.parseLong(next()); 
    }
    double nextDouble(){ 
        return Double.parseDouble(next()); 
    }
    String nextLine(){ 
        String str = ""; 
        try{ 
            str = br.readLine(); 
        } 
		catch (IOException e){ 
            e.printStackTrace(); 
        } 
        return str; 
    }
}