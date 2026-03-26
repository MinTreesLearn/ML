import java.util.*;
import java.io.*;
public class Solution
{
       static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
  
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
  
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(
                new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
  
        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }
  
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
  
            if (neg)
                return -ret;
            return ret;
        }
  
        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
  
        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
  
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
  
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
  
            if (neg)
                return -ret;
            return ret;
        }
  
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0,
                                 BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
  
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
  
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
    
    static int parent(int a , int p[])
    {
           if(a == p[a])
           return a;
           
           return p[a] = parent(p[a],p);
    }
    
    static void union(int a , int b , int p[] , int sz[])
    {
           a = parent(a,p);
           b = parent(b,p);
           
           if(a == b)
           return;
           
           if(sz[a] < sz[b])
           {
                  int temp = a;
                  a = b;
                  b = temp;
           }
           sz[a] += sz[b];
           p[b] = a;
    }
    
    static int st[];
    static int sz;
    static int lazy[];
    
    static void update(int l , int r , int v ,  int lx , int rx , int x)
    {
          // System.out.println(lx + " " + rx);
           
           if(lazy[x] != 0)
           {
                  st[x] += lazy[x];
                  if(lx != rx)
                  {
                         lazy[2*x+1] += lazy[x];
                         lazy[2*x+2] += lazy[x];
                  }
                  lazy[x] = 0;
           }
           
           if(rx < l || lx > r)
           return;
           
           if(lx >= l && rx <= r)
           {
                  st[x] += v;
                  if(lx != rx)
                  {
                         lazy[2*x+1] += v;
                         lazy[2*x+2] += v;
                  }
                  return;
           }
           
           int mid = (lx+rx)/2;
           update(l,r,v,lx,mid,2*x+1);
           update(l,r,v,mid+1,rx,2*x+2);
           
           st[x] = Math.max(st[2*x+1],st[2*x+2]);
    }
    
    static int get(int l , int r , int lx , int rx , int x)
    {
           
           if(lazy[x] != 0)
           {
                  st[x] += lazy[x];
                  if(lx != rx)
                  {
                         lazy[2*x+1] += lazy[x];
                         lazy[2*x+2] += lazy[x];
                  }
                  lazy[x] = 0;
           }
           
           if(l > rx || r < lx)
           return Integer.MIN_VALUE;
           
           if(lx >= l && rx <= r)
           {
                  return st[x];
           }
           
           int mid = (lx+rx)/2;
           return Math.max(get(l,r,lx,mid,2*x+1),get(l,r,mid+1,rx,2*x+2));
    }
    
    public static void main(String []args) throws IOException
    {
           Reader sc = new Reader();
           int n = sc.nextInt();
           int m = sc.nextInt();
           int p = sc.nextInt();
           
           pair a1[] = new pair[n];
           for(int i = 0 ; i < n ; i++)
           {
                  a1[i] = new pair(sc.nextInt(),sc.nextInt(),0);
           }
           Arrays.sort(a1,new Compare());
           pair a2[] = new pair[m];
           for(int i = 0 ; i < m ; i++)
           {
                  a2[i] = new pair(sc.nextInt(),sc.nextInt(),0);
           }
           Arrays.sort(a2,new Compare());
           TreeMap<Integer,Integer> map = new TreeMap<Integer,Integer>();
           for(int i = 0 ; i < m ; i++)
           {
                 if(!map.containsKey(a2[i].x))
                 map.put(a2[i].x,i);
           }
           pair a3[] = new pair[p];
           for(int i = 0 ; i < p ; i++)
           {
                  a3[i] = new pair(sc.nextInt(),sc.nextInt(),sc.nextInt());
           }
           Arrays.sort(a3, new Compare());
           sz = 1;
           while(sz < m)
           {
                  sz *= 2;
           }
           st = new int[2*sz];
           lazy = new int[2*sz];
           
           for(int i = 0 ; i < m ; i++)
           {
                  update(i,i,-a2[i].y,0,sz-1,0);
           }
           int ans = Integer.MIN_VALUE;
           int j = 0;
          // System.out.println(get(0,m-1,0,sz-1,0));
           for(int i = 0 ; i < n ; i++)
           {
                  while(j < p && a1[i].x > a3[j].x)
                  {
                         if(map.higherKey(a3[j].y) != null)
                         {
                                int pos = map.get(map.higherKey(a3[j].y));
                                update(pos,m-1,a3[j].k,0,sz-1,0);
                         }
                         j++;
                  }
                  ans = Math.max(ans,get(0,m-1,0,sz-1,0)-a1[i].y);
           }
           System.out.println(ans);
    }
}

class pair
{
       int x , y , k;
       public pair(int x , int y , int k)
       {
              this.x = x;
              this.y = y;
              this.k = k;
       }
}

class Compare implements Comparator<pair>
{
       public int compare(pair a , pair b)
       {
              return a.x-b.x;
       }
}