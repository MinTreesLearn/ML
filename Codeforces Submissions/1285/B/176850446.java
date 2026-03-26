    import com.sun.security.jgss.GSSUtil;

    import java.io.*;
    import java.lang.reflect.Array;
    import java.util.*;
    import java.util.HashSet;
    import java.util.StringTokenizer;

    public class cf799 {
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

        public static int fast(){
            FastReader sc = new FastReader();

            return sc.nextInt();
        }
        static  boolean isPrime(int num)
        {
            if(num<=1)
            {
                return true;
            }
            for(int i=2;i*i<=num;i++)
            {
                if((num%i)==0)
                    return  false;
            }
            return true;
        }
        static void gfdfg(HashMap<Integer,ArrayList<Integer>> map,boolean[] arrr){
            for(int i=2;i<=100000;i++){

                if(!arrr[i]){
                    map.putIfAbsent(i,new ArrayList<>());
                    map.get(i).add(i);
                    for(int j=i*2;j<=100000;j+=i){
                        arrr[j]=true;
                        // air[j]=i;
                        //ekaur[j]+=1;
                        map.putIfAbsent(j,new ArrayList<>());
                        map.get(j).add(i);
                    }
                }
            }
        }
        public static void main(String[] args) {
            try {
                FastReader sc = new FastReader();
                FastWriter out = new FastWriter();

int t=sc.nextInt();
while (t-->0) {

    int n = sc.nextInt();
    int[] arr = new int[n];
for(int i=0;i<n;i++){
    arr[i]=sc.nextInt();
}
long count1=0;
for(int i=0;i<n;i++){
    count1+=arr[i];
}
long count2=kadane(arr,0,n-1);
long count3=Math.max(count2,kadane(arr,1,n));

if(count1>count3){
    System.out.println("YES");
}else{
    System.out.println("NO");
}


}

            }catch (Exception e) {
                return;
            }
        }
        public static long kadane(int [] arr,int i,int j){
            long ans=0;
            long max=0;
            for(int f=i;f<j;f++){
                max+=arr[f];
                if(max<0){
                    max=0;
                }
                ans=Math.max(ans,max);
            }
            return ans;
        }
        public static long gfg(int [] arr,long num){


            int n=arr.length;
            long submin=Long.MIN_VALUE;
            long sum=0;
            int count=0;
            for(int i=0;i<n;i++){
                if(sum==num){
                    submin=Math.max(submin,count);
                    sum=arr[i];
                    count=1;
                }
                else if(sum>num){
                    submin=-1;
                    break;
                }else{
                    sum+=arr[i];
                    count++;
                }
            }
            if(sum==num){
                submin=Math.max(submin,count);
            }
            if(sum>num){
                submin=-1;
            }
            return submin==Long.MIN_VALUE?-1:submin;


        }

        private static int abcdefghijklmopqrstuvwxyz(int max) {
            int temp=max;
            int num=0;
            while(temp>0){
                num++;
                temp=temp>>1;
            }
            int ans=0;
            int count=1;
            while(num-->0){
                ans+=count;
                count*=2;
            }
            return ans;
        }


        private static void reverse(int[] lowsum) {
            for(int i=lowsum.length-1;i>0;i--){
              lowsum[i]=lowsum[i-1];
            }
            lowsum[0]=0;
        }

        private static void ff(ArrayList<Integer> ar , ArrayList<Integer> ar2) {
            for (Integer integer : ar2) {
                int count = 0;
                int num = integer;
                while (num % 2 == 0) {
                    count++;
                    num /= 2;
                }
                ar.add(count);

            }

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
