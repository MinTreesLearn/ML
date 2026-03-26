import java.util.*;
import java.io.*;
import java.security.KeyStore.Entry;

public class Main{
    static final Random random=new Random();
    static long mod=1000000007L;
    static HashMap<String,Integer>map=new HashMap<>();
   
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
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
            String str="";
            try {
                str=br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
        int[] readIntArray(int n){
            int[] res=new int[n];
            for(int i=0;i<n;i++)res[i]=nextInt();
            return res;
        }
    }
    static class FastWriter {
		private final BufferedWriter bw;

		public FastWriter() {
			this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
		}

		public void print(Object object) throws IOException {
			bw.append("" + object);
		}

		public void println(Object object) throws IOException {
			print(object);
			bw.append("\n");
		}

		public void close() throws IOException {
			bw.close();
		}
	}
    static int ans=0;
    public static void main(String[] args) {
        try {
            FastReader in=new FastReader();
            FastWriter out = new FastWriter();
            //int testCases=in.nextInt();
            int testCases=1;
            while(testCases-- > 0){
                solve(in);
            }
            out.close();
        } catch (Exception e) {
            System.out.println(e);
            return;
        }
    }
    public static void solve( FastReader in){
        int n=in.nextInt();
        //int m=in.nextInt();
        //String s=in.next();
        //String t=in.next();
        //long y=in.nextInt();
        //long n=in.nextLong();
        //int k=in.nextInt();
        //long k=in.nextLong();
        StringBuilder res=new StringBuilder();
        int[] arr=in.readIntArray(n);
        HashMap<Integer,Long> hp=new HashMap<>();
        for(int i=0;i<n;i++){
            hp.put(arr[i]-(i+1),(long)hp.getOrDefault(arr[i]-(i+1),0L)+arr[i]);
        }
        ArrayList<Long> ls=new ArrayList<>(hp.values());
        Collections.sort(ls);
        long ans=ls.get(ls.size()-1);
        res.append(""+ans);
        System.out.println(res.toString());
    }
    
   
    static void dfs1(Map<String,String> hp,int i,int n,String r){
        if(i>n){
            ans+=ch(hp,n,r);
            return;
        }
        for(char x='a';x<='f';x++){
            dfs1(hp,i+1,n,r+x);
        }
    }
    static int ch(Map<String,String> hp,int n,String r){
        for(int i=0;i<n-1;i++){
            String x=r.substring(0,2);
            if(!hp.containsKey(x))return 0;
            r=hp.get(x)+r.substring(2);
        }
        if(r.equals("a"))return 1;
        return 0;
    }
    static int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }

    static void sort(int[] arr)
    {
        
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr)
            ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }
    static void reversesort(int[] arr)
    {
        
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr)
            ls.add(x);
        Collections.sort(ls);
        Collections.reverse(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }

    static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }

    static void debug(String x){
        System.out.println(x);
    }
    static < E > void print(E res)
    {
        System.out.println(res);
    }
    static String rString(String s){
        StringBuilder sb=new StringBuilder();
        sb.append(s);
        return sb.reverse().toString();
    }
}