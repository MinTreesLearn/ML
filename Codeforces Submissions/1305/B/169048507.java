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
String s=sc.next();
ArrayList<Integer> ff=new ArrayList<>();
ArrayList<Integer> ss=new ArrayList<>();
int i=0;
int j=s.length()-1;
while(i<j){
    if(s.charAt(i)=='(' && s.charAt(j)==')'){
        ff.add(i);
        ss.add(j);
        i++;
        j--;

    }
    else if(s.charAt(i)=='(' && s.charAt(j)=='('){
        j--;
    }
    else if(s.charAt(i)==')' && s.charAt(j)==')'){
        i++;
    }else{
        i++;
        j--;
    }
}
if(ff.size()==0){
    System.out.println(0);
}else {
    System.out.println(1);
    System.out.println(ff.size() + ss.size());
    int fd = 0;
    int sd = ss.size() - 1;
    while (fd < ff.size()) {
        System.out.print((ff.get(fd++) + 1) + " ");
    }
    while (sd >= 0) {
        System.out.print((ss.get(sd--) + 1) + " ");
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