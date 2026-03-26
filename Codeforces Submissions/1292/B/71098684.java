;
import java.util.*;
import java.io.*;
import static java.lang.Long.max;
import static java.lang.Math.abs;
import static java.lang.Math.pow;
public class Main {
    static FastReader in=new FastReader();
    public static void main(String [] args) {
   long x=in.nextLong(),y=in.nextLong(),ax=in.nextLong(),ay=in.nextLong(),bx=in.nextLong(),by=in.nextLong();
   long xs=in.nextLong(),ys=in.nextLong(),t=in.nextLong();
   ArrayList<Long>xx=new ArrayList(),yy=new ArrayList();
   xx.add(x);yy.add(y);
   for(;xx.get(xx.size()-1)<=(((Long.MAX_VALUE-1)/ax)-bx)&&yy.get(yy.size()-1)<=(((Long.MAX_VALUE-1)/ay)-by);){
   xx.add(xx.get(xx.size()-1)*ax+bx);
   yy.add(yy.get(yy.size()-1)*ay+by);
   }
   long xl=xs,yl=ys,tt=t;
   for(int i=0;i<xx.size();i++){
   if(tt>=abs(xl-xx.get(i))+abs(yl-yy.get(i))&&abs(xl-xx.get(i))+abs(yl-yy.get(i))>=0){an++;tt-=abs(xl-xx.get(i))+abs(yl-yy.get(i));xl=xx.get(i);yl=yy.get(i);}
   else {anl=max(ans,an);an=0;
   xl=xs;yl=ys;tt=t;}
   }
   
   xl=xs;yl=ys;tt=t;
   for(int i=xx.size()-1;i>=0;i--){
       
   if(tt>=abs(xl-xx.get(i))+abs(yl-yy.get(i))&&abs(xl-xx.get(i))+abs(yl-yy.get(i))>=0){as++;tt-=abs(xl-xx.get(i))+abs(yl-yy.get(i));xl=xx.get(i);yl=yy.get(i);}
   else {anl=max(ans,as);as=0;
   xl=xs;yl=ys;tt=t;}
   
   }
   
   tryy(xx,yy,xs,ys,t);
        as=max(as,an);
        an=max(anl,an);
        System.out.println(max(ans,as));
    }
    static long ans=0L,an,as=0,anl=0;
    static void tryy(ArrayList<Long> xx,ArrayList<Long> yy,long x,long y,long t){
        int c=-1;
        long min =Long.MAX_VALUE-1,z=0,v=0;
        for(int i=0;i<xx.size();i++){
        if(min> Math.abs(x-xx.get(i))+Math.abs(y-yy.get(i))&&Math.abs(x-xx.get(i))+Math.abs(y-yy.get(i))>=0){c=i;z=yy.get(i);v=xx.get(i);min= Math.abs(x-xx.get(i))+Math.abs(y-yy.get(i));}
        
        }
         if(min<=t){t-=min;ans++;
         xx.remove(c);yy.remove(c);
         tryy(xx,yy,v,z,t);
         }
        
    }
    static long gcd(long g,long x){
        if(x<1)return g;
        else return gcd(x,g%x);
    
    }
}

class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
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
}
 
class Sorting{
 
 public static int[] bucketSort(int[] array, int bucketCount) {
 
 if (bucketCount <= 0) throw new IllegalArgumentException("Invalid bucket count");
 
 if (array.length <= 1) return array; //trivially sorted
 
 
 
 int high = array[0];
 
 int low = array[0];
 
 for (int i = 1; i < array.length; i++) { //find the range of input elements
 
 if (array[i] > high) high = array[i];
 
 if (array[i] < low) low = array[i];
 
 }
 
 double interval = ((double)(high - low + 1))/bucketCount; //range of one bucket
 
 
 ArrayList<Integer> buckets[] = new ArrayList[bucketCount];
 
 for (int i = 0; i < bucketCount; i++) { //initialize buckets
 
 buckets[i] = new ArrayList();
 
 }
 
 
 
 for (int i = 0; i < array.length; i++) { //partition the input array
 
 buckets[(int)((array[i] - low)/interval)].add(array[i]);
 
 }
 
 
 int pointer = 0;
 
 for (int i = 0; i < buckets.length; i++) {
 
 Collections.sort(buckets[i]); //mergeSort
 
 for (int j = 0; j < buckets[i].size(); j++) { //merge the buckets
 
 array[pointer] = buckets[i].get(j);
 
 pointer++;
 
 }
 
}
 
return array;
 
}
 
}
