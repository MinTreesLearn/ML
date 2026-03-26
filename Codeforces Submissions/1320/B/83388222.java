import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class D
{
    public static void main(String[]args){
        InputReader sc = new InputReader(System.in);
        PrintWriter pw =new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //minimum is the number of times where next isint closer
        //maximum is the times (didnt go smaller) or (have more than one smaller within reach)
        int nodes=sc.nextInt();
        int roads=sc.nextInt();
        ArrayList<Integer>[] road = new ArrayList[nodes+1];
        ArrayList<Integer>[] reversed = new ArrayList[nodes+1];
        for(int i=0;i<road.length;i++){
            road[i]=new ArrayList<Integer>();
            reversed[i]=new ArrayList<Integer>();
        }
        for(int i=0;i<roads;i++){
        	int begin=sc.nextInt();
        	int end=sc.nextInt();
        	road[begin].add(end);
        	reversed[end].add(begin);
        }
        int paths=sc.nextInt();
        int[]path=sc.nextIntArray(paths);
        int destination=path[path.length-1];
        int[]dist=new int[nodes+1];
        Arrays.fill(dist,999999);
        dist[destination]=0;
        Queue<Integer>q=new LinkedList<Integer>();
        q.add(destination);
        while(!q.isEmpty()){
        	Integer p=q.remove();
        	for(int i=0;i<reversed[p].size();i++){
        		if(dist[reversed[p].get(i)]==999999){
        			dist[reversed[p].get(i)]=dist[p]+1;
        			q.add(reversed[p].get(i));
        		}
        	}
        	
        }
        int minimum=0;
        int maximum=0;
        for(int i=0;i<path.length-1;i++){
        	if(dist[path[i+1]]>dist[path[i]]-1)minimum++;
        }
        for(int i=0;i<path.length-1;i++){
        	if(dist[path[i+1]]>dist[path[i]]-1)maximum++;
        	else{
        		//if there exist another path
        		int cc=0;
        		for(int a=0;a<road[path[i]].size();a++){
        			if(dist[road[path[i]].get(a)]<=dist[path[i]]-1)cc++;
        			
        		}
        		if(cc>1)maximum++;
        	}

      
        }
        System.out.println(minimum+" "+maximum);
        pw.flush();
    }
    
    static class InputReader
    {
        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private SpaceCharFilter filter;
        public InputReader(InputStream stream)
        {
                this.stream = stream;
        }
        public int snext()
        {
                if (snumChars == -1)
                        throw new InputMismatchException();
                if (curChar >= snumChars)
                {
                        curChar = 0;
                        try
                        {
                                snumChars = stream.read(buf);
                        } catch (IOException e)
                        {
                                throw new InputMismatchException();
                        }
                        if (snumChars <= 0)
                                return -1;
                }
                return buf[curChar++];
        }
        public int nextInt()
        {
                int c = snext();
                while (isSpaceChar(c))
                {
                        c = snext();
                }
                int sgn = 1;
                if (c == '-')
                {
                        sgn = -1;
                        c = snext();
                }
                int res = 0;
                do
                {
                        if (c < '0' || c > '9')
                                throw new InputMismatchException();
                        res *= 10;
                        res += c - '0';
                        c = snext();
                } while (!isSpaceChar(c));
                return res * sgn;
        }
        public long nextLong()
        {
                int c = snext();
                while (isSpaceChar(c))
                {
                        c = snext();
                }
                int sgn = 1;
                if (c == '-')
                {
                        sgn = -1;
                        c = snext();
                }
                long res = 0;
                do
                {
                        if (c < '0' || c > '9')
                                throw new InputMismatchException();
                        res *= 10;
                        res += c - '0';
                        c = snext();
                } while (!isSpaceChar(c));
                return res * sgn;
        }
        public double nextDouble()
        {
                int c = snext();
                while (isSpaceChar(c))
                {
                        c = snext();
                }
                int sgn = 1;
                if (c == '-')
                {
                        sgn = -1;
                        c = snext();
                }
                double res = 0;
                while(c<='9'&&c>='0'){
                    res*=10;
                    res+=c-'0';
                    c=snext();
                }
                if(c=='.'){
                    double decimal=0;
                    long multiplier=1;
                    c=snext();
                    do
                    {
                        if (c < '0' || c > '9')
                                throw new InputMismatchException();
                        decimal *= 10;
                        decimal += c - '0';
                        multiplier*=10;
                        c = snext();
                    } while (!isSpaceChar(c));
                    return sgn*(res+decimal/multiplier);
                }else{
                    if(!isSpaceChar(c)){
                        throw new InputMismatchException();
                    }
                    return sgn*res;
                }
        }
        public int[] nextIntArray(int n)
        {
                int a[] = new int[n];
                for (int i = 0; i < n; i++)
                {
                        a[i] = nextInt();
                }
                return a;
        }
        public long[] nextLongArray(int n)
        {
                long a[] = new long[n];
                for (int i = 0; i < n; i++)
                {
                        a[i] = nextLong();
                }
                return a;
        }
        public String next(){return readString();}
        public String readString()
        {
                int c = snext();
                while (isSpaceChar(c))
                {
                        c = snext();
                }
                StringBuilder res = new StringBuilder();
                do
                {
                        res.appendCodePoint(c);
                        c = snext();
                } while (!isSpaceChar(c));
                return res.toString();
        }
        public String nextLine()
        {
                int c = snext();
                StringBuilder res = new StringBuilder();
                do
                {
                        res.appendCodePoint(c);
                        c = snext();
                } while (!isEndOfLine(c));
                if(isEndOfLine(res.charAt(res.length()-1)))
                return res.deleteCharAt(res.length()).toString();
                return res.toString();
        }
        public ArrayList<String> readAll(){
            ArrayList<String>a=new ArrayList<String>();
            try{
                while(true){
                    a.add(nextLine());
                }
            }catch(Exception e){
                
            }
            return a;
        }
        public boolean hasNext(){
            boolean hasnext=true;
            try{
                hasnext= stream.available()!=0;
            }catch(IOException e){
            }
            return hasnext||curChar<snumChars;
        }
        public boolean isSpaceChar(int c)
        {
                if (filter != null)
                        return filter.isSpaceChar(c);
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
        private boolean isEndOfLine(int c)
        {
                return c == '\n' || c == '\r' || c == -1;
        }
        public interface SpaceCharFilter
        {
                public boolean isSpaceChar(int ch);
        }
    }
}