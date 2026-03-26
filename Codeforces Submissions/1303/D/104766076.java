import java.io.*; 
import java.util.*; 
//import javafx.util.*; 
import java.math.*;
//import java.lang.*;
public class Main 
{ 
    
   // static int n;
    static HashSet<Integer> adj[];
    
     static boolean vis[];
   //  static long ans[];
    static int arr[];
    static long mod=1000000007;
    static final long oo=(long)1e18;
    // static int n;
    public static void main(String[] args) throws IOException { 
    //    Scanner sc=new Scanner(System.in);
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        br = new BufferedReader(new InputStreamReader(System.in));
        int test=nextInt();
       // int test=1;
        outer: while(test--!=0){ 
            int a[]=new int[64];
            long n=nextLong();
            int m=nextInt();
         
            Long arr[]=new Long[m];

            for(int i=0;i<m;i++){
                arr[i]=nextLong();
                a[(int)(Math.log(arr[i])/Math.log(2))]++;
            }
            int ans=0;
            for(int i=0;i<62;i++){
                if((n&(1l<<i))!=0){
                 //   pw.println(i);
                    boolean yes=false;
                    int j=i;
                    for(j=i;j<62;j++){
                        if(a[j]>0){
                            yes=true;
                            break;
                        }
                    }
                    if(yes){
                        while(j!=i){
                            a[j]--;
                            a[j-1]+=2;
                            ans++;
                            j--;
                        }
                        a[j]--;
                        
                    }
                    else{
                        pw.println("-1");
                        continue outer;
                    }
                }
                a[i+1]+=a[i]/2;
            }
            pw.println(ans);
           // Arrays.sort(arr,Collections.reverseOrder());
            

        }   
        pw.close();
    }
    static boolean dfs(int v,int parent){
       // System.out.println(v);
        vis[v]=true;
        for(int a:adj[v]){
            if(!vis[a]){
                if(dfs(a,v)){
                    return true;
                }
            }
            else if(a!=parent){
                return true;
            }
        }
        return false;
    }
static ArrayList<ArrayList<Integer>> permutation2(int[] a, int n) {
        ArrayList<ArrayList<Integer>> gen = new ArrayList<>();
        if(n == 1) {
            ArrayList<Integer> new_permutation = new ArrayList<>();
            new_permutation.add(a[n-1]);
            gen.add(new_permutation);
        } else {
            Iterator<ArrayList<Integer>> itr = permutation2(a, n-1).iterator();
            while(itr.hasNext()) {
                ArrayList<Integer> permutation = itr.next();
                // (create new permutation with this element in every position)
                for(int i = 0;i <= permutation.size();i++) {
                    ArrayList<Integer> new_permutation = new ArrayList<>(permutation);
                    new_permutation.add(i, a[n-1]);
                    gen.add(new_permutation);
                }
            }
        }
        return gen;
    }
    static void decToBinary(int n) 
    { 
        // array to store binary number 
        int[] binaryNum = new int[1000]; 
   
        // counter for binary array 
        int i = 0; 
        while (n > 0)  
        { 
            // storing remainder in binary array 
            binaryNum[i] = n % 2; 
            n = n / 2; 
            i++; 
        } 
   
        // printing binary array in reverse order 
        for (int j = i - 1; j >= 0; j--) 
            System.out.print(binaryNum[j]); 
        System.out.println();
    } 

    static long ncr(long n,long r){
        if(r==0)
            return 1;
        long val=ncr(n-1,r-1);
        val=(n*val)%mod;
        val=(val*modInverse(r,mod))%mod;
        return val;
    }

    static int find(ArrayList<Integer> a,int i){
        
        if(a.size()==0||i<0)return 0;
        ArrayList<Integer> l=new ArrayList<Integer>();
        ArrayList<Integer> r=new ArrayList<Integer>();
        for(int v:a){
            if((v&(1<<i))!=0)l.add(v);
            else r.add(v);
        }

        if(l.size()==0)return find(r,i-1);
        if(r.size()==0)return find(l,i-1);
        return Math.min(find(l,i-1),find(r,i-1))+(1<<i);
    }
    
    
    public static BufferedReader br;
    public static StringTokenizer st;
    public static String next() {
        while (st == null || !st.hasMoreTokens()) {
       try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }
 
    public static Integer nextInt() {
        return Integer.parseInt(next());
    }
    public static Long nextLong() {
        return Long.parseLong(next());
    }
 
    public static Double nextDouble() {
        return Double.parseDouble(next());
    }
    // static class Pair{
    //     int x;int y;
    //     Pair(int x,int y,int z){
    //         this.x=x;
    //         this.y=y;
    //        // this.z=z;
    //      //   this.z=z;
    //       //  this.i=i;
    //     }
    // }
    // static class sorting implements Comparator<Pair>{
    //     public int compare(Pair a,Pair b){
    //         //return (a.y)-(b.y);
    //         if(a.y==b.y){
    //             return -1*(a.z-b.z);
    //         }
    //         return (a.y-b.y);
    //     }
   // }
    public static int[] na(int n)throws IOException{
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = nextInt();
        return a;
    }
    static class query implements Comparable<query>{
        int l,r,idx,block;
        static int len;
        query(int l,int r,int i){
            this.l=l;
            this.r=r;
            this.idx=i;
            this.block=l/len;
        }   
        public int compareTo(query a){
            return block==a.block?r-a.r:block-a.block;
        }
    }
    static class Pair implements Comparable<Pair>{
        int x;int y;
        Pair(int x,int y){
            this.x=x;
            this.y=y;
            //this.z=z;
        }   
        public int compareTo(Pair p){
            
            //return (x-p.x);
            if(x>p.x)
                return 1;
            if(x<p.x)
                return -1;
            return y-p.y;
            //return (x-a.x)>0?1:-1;
        }
    }
    // static class sorting implements Comparator<Pair>{  
    //     public int compare(Pair a1,Pair a2){  
    //         if(o1.a==o2.a)
    //             return (o1.b>o2.b)?1:-1;  
    //         else if(o1.a>o2.a)  
    //             return 1;  
    //         else  
    //             return -1;  
    //     }
    // }  
    static boolean isPrime(int n) { 
        if (n <= 1) 
            return false; 
        if (n <= 3) 
            return true; 
        if (n % 2 == 0 ||  
            n % 3 == 0) 
            return false; 
      
        for (int i = 5; 
                 i * i <= n; i = i + 6) 
            if (n % i == 0 || 
                n % (i + 2) == 0) 
                return false; 
      
        return true; 
    } 
    static long gcd(long a, long b) { 
      if (b == 0) 
        return a; 
      return gcd(b, a % b);  
    }  
    // To compute x^y under modulo m 
    static long power(long x, long y, long m){ 
        if (y == 0) 
            return 1;      
        long p = power(x, y / 2, m) % m; 
        p = (p * p) % m; 
      
        if (y % 2 == 0) 
            return p; 
        else
            return (x * p) % m; 
    }
    static long fast_pow(long base,long n,long M){
        if(n==0)
           return 1;
        if(n==1)
        return base;
        long halfn=fast_pow(base,n/2,M);
        if(n%2==0)
            return ( halfn * halfn ) % M;
        else
            return ( ( ( halfn * halfn ) % M ) * base ) % M;
    }
       static long modInverse(long n,long M){
        return fast_pow(n,M-2,M);
    }
    // (1,1)   

    //     (3,2)   (3,5)

} 