




import java.util.*;
import java.io.*;


public class Main {
	
	
   static class FastReader{
	   BufferedReader br;
	   StringTokenizer st;
	   FastReader(){
		  br=new BufferedReader(new InputStreamReader(System.in));
	   }
	   String next() {
		 while(st==null||!st.hasMoreElements()) {
		   try {
			  st=new StringTokenizer(br.readLine());
		   }catch(IOException e) {
		  e.printStackTrace();
		  }
		 }
		 return st.nextToken();
	   }
	   
	  int nextInt() {
		  return Integer.parseInt(next());
	  }
	  long nextLong() {
		  return Long.parseLong(next());
	  }
	  double nextDouble() {
		  return Double.parseDouble(next());
	  }
	  String nextLine() {
		  String str="";
		  try {
			  str=br.readLine();
		  } catch(IOException e) {
			  e.printStackTrace();
		  }
		  return str;
	  }
   }

	static class Pair{ 
	//implements Comparable<Pair> {
		  long x;
		  long y;
		  Pair(long x,long y){
			  this.x=x;
			  this.y=y;
		  }
//		  @Override
//		  public int compareTo(Pair o) {
//			return this.y-o.y;  
//		  }
		}

 
	
 static long gcd(long a,long b) {
	  if(b==0) return a;
	else
	  return gcd(b,a%b);
   }
   
 static List primeFactors(int n){
     List<Integer> ar=new ArrayList<>();
     int ct=0;
      for(int i=2;i*i<=n;i++) {
	    if(n%i==0) {
		  ar.add(i);
		  ct++;
	     while(n%i==0) {
	       n/=i;
	     }
       }
     }
    if(n>1) {
    	ct++;
	 ar.add(n);
    }
    return ar;
   }
   
 static int lb(ArrayList<Long>ar,long k) {
	int s=0;
	int e=ar.size();
	while(s!=e) {
	  int mid=s+e>>1;
	  if(ar.get(mid)<k)
		 s=mid+1;
	  else
		 e=mid;
     }

	if(s==0)
		return -1;
    return s-1;
  }
  
 static long powM(long x,long y,long mod) {
	if(y==0)
		return 1;
	long k=powM(x,y/2,mod);
	
	if(y%2==1) {
		return (((((long)1*k*k)%mod)*x)%mod);
	}
	else {
		return (((long)1*k*k)%mod);
	}
  }

 static int ub(ArrayList<Integer>ar,int k) {
	int s=0;
	int e=ar.size();
	while(s!=e) {
	  int mid=s+e>>1;
	  if(ar.get(mid)<=k)
		 s=mid+1;
	  else
		 e=mid;
     }
	if(s==ar.size())
		return -1;
    return s;
  }
  
 static boolean isPrime(long n) {
	 boolean flag=true;
	 if(n<2)
		 flag=false;
	 else {
		 for(int i=2;i*i<=n;i++){
			if(n%i==0) {
			 flag=false;
			 break;
			}
		 }
	 }
	 return flag;
 }
 
 static void pArray(int a[]) {
	 for(int i=0;i<a.length;i++) {
		 System.out.print(a[i]+" ");
     }
	 System.out.println();
 }
 
 static String sort(String s) {
	 char ch[]=s.toCharArray();
	 Arrays.sort(ch);
	 return new String(ch);
 }


// static int[] dij(int n,int src, ArrayList<Edge> ar[]) {
//	PriorityQueue<Pair>pq=new PriorityQueue<>();
//	pq.add(new Pair(src,0));
//	Set<Integer>vis=new HashSet<>();
//	int dist[]=new int[n+1];
//	dist[src]=0;
//	Arrays.fill(dist, Integer.MAX_VALUE);
//
//	while(pq.size()>0) {
//		
//	  	Pair cur=pq.poll();
//	  	if(!vis.contains(cur.x)){
//	  		
//	  		vis.add(cur.x);
//	  		
//	  		dist[cur.x]=cur.y;
//	  		
//	  	 for(Edge e:ar[cur.x]) {
//	  		 if(!vis.contains(e.dest)&&dist[e.dest]>cur.y+e.w )
//	  			pq.add(new Pair(e.dest,cur.y+e.w));
//	  	 }
//	  	}
//	  }
//	return dist;
// }
// 
 public static String addCharToString(String str, char c,
         int pos)
{

StringBuffer stringBuffer = new StringBuffer(str);
stringBuffer.insert(pos, c);
return stringBuffer.toString();
}
 
 static int BigMod(String num, int a)
 {
    int res = 0;
    for (int i = 0; i < num.length(); i++)
         res = (res * 10 + (int)num.charAt(i)); 
    return res;

 }
 static boolean isSquare(int n) {
		for(int i=1;i*i<=n;i++) {
			if((i*i)==n)
				return true;
		}
		return false;
 }

 static long firstsetBitPower(long n)
 {
     int k = (int)(Math.log(n) / Math.log(2));
    
     return 1 << k;
 }


 public static void main(String[] args) {
 try {
 
 
  FastReader sc = new FastReader();
  
  //int t=sc.nextInt();
  
  //while(t-->0) {   
    int n=sc.nextInt();
    int a[]=new int[n];
    int b[]=new int[n];
    for(int i=0;i<n;i++) a[i]=sc.nextInt();
    for(int i=0;i<n;i++) b[i]=sc.nextInt();
    
    int sec=0;
    int fir=0;
    
    for(int i=0;i<n;i++) {
     if(a[i]!=b[i]) {
    	if(a[i]==1)
    		fir++;
    	else
    		sec++;
     }
    }
    
    if(fir==0&&sec==0) {
      	System.out.println("-1");
    }
    else if(fir==0) {
    	System.out.println("-1");
    }
    else if(fir>sec) {
       System.out.println("1");	
    }
    else {
       System.out.println((sec/fir)+1);	
    }
  //}
      
 }catch(Exception e) {return;}
 }
}



//https://www.codechef.com/MP3TO401?order=desc&sortBy=successful_submissions






























































































































































