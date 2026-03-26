import java.io.*;
        import java.lang.reflect.Array;
        import java.util.*;


public class edu130 {
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
    public static void main(String[] args) {
        //RSRRSRSSSR
        try {
            FastReader sc = new FastReader();
            FastWriter out = new FastWriter();
int t=sc.nextInt();
while(t-->0){
    int n=sc.nextInt();
    int k=sc.nextInt();
    int [] arr=new int[n];
    int [] arr2=new int[k];
    int [] temp=new int[n];
    HashMap<Integer,Integer> map=new HashMap<>();

    for(int i=0;i<n;i++){
        arr[i]=sc.nextInt();
        temp[i]=arr[i];
    }
    for(int i=0;i<k;i++){
        int b=sc.nextInt();
            arr2[i]=b-1;
    map.put(arr2[i],0);

    }
    Arrays.sort(temp);
    boolean tt=false;
    for(int i=0;i<n;i++){
        if(map.containsKey(i)){
            int j=i;
            while(j<n && map.containsKey(j)){
                j++;
            }
            Arrays.sort(arr,i,j+1);
            i=j;
        }
    }
    for(int i=0;i<n;i++){
        if(temp[i]!=arr[i]){
            tt=true;
            break;
        }
    }
    if(tt){
        System.out.println("NO");
    }else{
        System.out.println("YES");
    }
}


        }catch(Exception e){
            return;
        }

    }

    private static void swap(long[] arr, int i, int ii) {
        long temp=arr[i];
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