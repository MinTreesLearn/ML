import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class edu130 {
    //private static Object m;

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
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
            String str = "";
            try {
                str = br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
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

    public static boolean func(long x,long k){
        return (k-((x*x)+(x)+1))%(2*x)==0;
    }
    public static void gg(int [] arr, int l, int r, int count , int[] ans){
        if(r<l){
            return;
        }
        if(r==l){
            ans[l]=count;

            return;
        }
        int m=l;
        for(int i=l+1;i<=r;i++){
            if(arr[i]>arr[m]){
                m=i;
            }
        }
        ans[m]=count;
        gg(arr,l,m-1,count+1,ans);
        gg(arr,m+1,r,count+1,ans);



    }

    public static void main(String[] args) {
        //RSRRSRSSSR
        try {
            FastReader sc = new FastReader();
            FastWriter out = new FastWriter();


            int t=sc.nextInt();
            while(t-->0) {
            int n=sc.nextInt();


             String s=sc.next();

             HashMap<String,ArrayList<Integer>> map=new HashMap<>();
                map.put(s,new ArrayList<>());
                map.get(s).add(1);
             for(int i=2;i<=n;i++){
                 if(i==n){
                     StringBuilder ff=new StringBuilder(s);

map.putIfAbsent(ff.reverse().toString(),new ArrayList<>() );
map.get(ff.toString()).add(i);
                 }else{
                     StringBuilder ff=new StringBuilder(s.substring(0,i-1));
                     StringBuilder ss=new StringBuilder(s.substring(i-1,n));
                     if((n-(i-1))%2==0 ){
                         ss.append(ff);
                     }else{
                         ss.append(ff.reverse());
                     }
                     map.putIfAbsent(ss.toString(),new ArrayList<>());
                     map.get(ss.toString()).add(i);
                 }
             }
               // System.out.println(map);
             String [] arr=new String[map.size()];
             int k=0;
             for(String key:map.keySet()){
                 arr[k++]= key.toString();
             }
             Arrays.sort(arr);
             String gg=arr[0];
                System.out.println(gg);
                //System.out.println(map);
                //StringBuilder str=new StringBuilder(gg);
                //System.out.println(map.get(str.toString()));
                //System.out.println(map.get(gg));
                System.out.println(map.get(gg).get(0));


            }
        }catch(Exception e){

            return;
        }

    }

    private static char check(char c, char c1, char c2) {
        if(c2=='-'){


            for(int i=0;i<26;i++){
                char gg=(char)('a'+i);
                if(gg!=c && gg!=c1 ){
                    return gg;
                }
            }
            return '+';
        }else{
            for(int i=0;i<26;i++){
                char gg=(char)('a'+i);
                if(gg!=c && gg!=c1 && gg!=c2){
                    return gg;
                }
            }
            return '+';
        }


    }

    private static char get(StringBuilder sb, int i,char ff,char ss) {
        if(i==sb.length()-1){
            for(int f = 0; f<26; f++){
                if((char)('a'+f)!=ff ){
                    return (char) ('a'+ f);
                }
            }
        }
        else if(i==sb.length()-2){

            for(int f = 0; f<26; f++){
                if((char)('a'+f)!=ff && (char)('a'+f)!=ss && (char)('a'+f)!=sb.charAt(i+1) ){
                    return (char) ('a'+ f);
                }
            }

        }else{
            for(int f = 0; f<26; f++){
                if((char)('a'+f)!=ff && (char)('a'+f)!=ss && (char)('a'+f)!=sb.charAt(i+1) && (char)('a'+f)!=sb.charAt(i+2)){
                    return (char) ('a'+ f);
                }
            }
        }
        return 'l';
    }

    public static  int gg(int num){
        int count=0;
        while(num>0){
            count++;
            num=(num>>1);
        }
        return count;
    }

    private static void swap(int[] arr, int i, int ii) {
        int temp=arr[i];
        arr[i]=arr[ii];
        arr[ii]=temp;
    }

    public static int lcm(int a,int b){
        return (a/gcd(a,b))*b;
    }

    private static int gcd(int a, int b) {
        if(b==0)return a;
        return gcd(b,a%b);
    }

    static class Pair {
        int a;
        int b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;

        }
    }
}