import java.io.*;
import java.util.*;



import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;
 
public class Cf131 implements Runnable 
{
    static class InputReader 
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
        private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
        public InputReader(InputStream stream) 
        {
            this.stream = stream;
        }
        
        public int read()
        {
            if (numChars==-1) 
                throw new InputMismatchException();
            
            if (curChar >= numChars) 
            {
                curChar = 0;
                try
                {
                    numChars = stream.read(buf);
                }
                catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                
                if(numChars <= 0)               
                    return -1;
            }
            return buf[curChar++];
        }
     
        public String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }    
            return str;
        }
        public int nextInt() 
        {
            int c = read();
            
            while(isSpaceChar(c)) 
                c = read();
        
            int sgn = 1;
        
            if (c == '-') 
            {
                sgn = -1;
                c = read();
            }
            
            int res = 0;
            do
            {
                if(c<'0'||c>'9') 
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c)); 
        
            return res * sgn;
        }
        
        public long nextLong() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            long res = 0;
            
            do 
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }    
            while (!isSpaceChar(c));
                return res * sgn;
        }
        
        public double nextDouble() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') 
            {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') 
            {
                c = read();
                double m = 1;
                while (!isSpaceChar(c))
                {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
    
        public String readString() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do 
            {
                res.appendCodePoint(c);
                c = read();
            } 
            while (!isSpaceChar(c));
            
            return res.toString();
        }
     
        public boolean isSpaceChar(int c) 
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
     
        public String next()
        {
            return readString();
        }
        
        public interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);
        }
    }
    public static void main(String args[]) throws Exception 
    {
        new Thread(null, new Cf131(),"Main",1<<27).start();
    }
    
    static class Pair{
		int nod;
        int ucn;
        int siz;
		
		Pair(int nod,int ucn,int siz){
			this.nod=nod;
            this.ucn=ucn;
            this.siz = siz;
		}
		
	public static Comparator<Pair> wc = new Comparator<Pair>(){
		public int compare(Pair e1,Pair e2){
            int c1 = e1.ucn - e1.siz;
            int c2 = e2.ucn - e2.siz;
            //reverse order
			if (c1 < c2) 
                return 1;  // 1 for swaping.
            else if (c1 > c2) 
                return -1; 
            else{
                if(e1.siz>e2.siz)
                    return 1;
                else
                    return -1;
            } 
		}
	};	
	}

    public static long gcd(long a,long b){
        if(b==0)return a;
        else return gcd(b,a%b);
    }
//// iterative BFS
    public static void bfs(int s,ArrayList<Integer>[] a,int[] dist,boolean[] b,PrintWriter w){
        b[s]=true;
        
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        while(q.size()!=0){
            int i=q.poll();
        //    w.println(" #"+i+"# ");
            Iterator<Integer> it =a[i].listIterator();
            int z=0;
            while(it.hasNext()){
                z=it.next();
                
                if(!b[z]){
                //    w.println("* "+z+" *");
                    b[z]=true;
                  dist[z] = dist[i]+1;
                //    x.add(z);
                //    w.println("@ "+x.get(x.size()-1)+" @");
                    q.add(z);
                }
            }   
        
        }
    }
////recursive BFS
    public static int bfsr(int s,ArrayList<Integer>[] a,int[] dist,boolean[] b,int[] pre){
        b[s]=true;
        int p = 0;
        int t = a[s].size();
        for(int i=0;i<t;i++){
            int x = a[s].get(i);
            if(!b[x]){
                dist[x] = dist[s] + 1;
                p+= (bfsr(x,a,dist,b,pre)+1);
            }
        }
        pre[s] = p;
        return p;
    }



  


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
  
 
    public void run()
    {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        // int t= sc.nextInt();
        // while(t-->0){
           
            int n = sc.nextInt();
            int q = sc.nextInt();
            int[][] p = new int[3][n+2];
            boolean can = true;
            boolean dest = false;
            int block = 0;
            for(int i=0;i<q;i++){
                int r = sc.nextInt();
                int c = sc.nextInt();
                if(p[r][c]==0){
                    if(p[(r%2)+1][c+1]==1)block++;
                    if(p[(r%2)+1][c-1]==1)block++;
                    if(p[(r%2)+1][c]==1)block++;
                }
                else{
                    if(p[(r%2)+1][c+1]==1)block--;
                    if(p[(r%2)+1][c-1]==1)block--;
                    if(p[(r%2)+1][c]==1)block--;
                }
                p[r][c] = (p[r][c]+1)%2;
                if(p[2][n]==1){
                    w.println("No");
                    continue;
                }
                if(block<=0)w.println("Yes");
                else w.println("No");
        


            }          

        //}    
        w.flush();
        w.close();

        
    }

}