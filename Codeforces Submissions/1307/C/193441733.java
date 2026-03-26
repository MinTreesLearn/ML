import java.awt.image.AreaAveragingScaleFilter;
import java.awt.image.MemoryImageSource;
import java.io.*;
import java.sql.Array;
import java.util.*;
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


    static int []   parent=new int[100001];
    static int [] rank=new int[100001];

    public static void makeSet(){
        for(int i=0;i<parent.length;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }


    public static int findParent(int num){
        if(parent[num]==num)return num;
        return parent[num]=findParent(parent[num]);
    }
    public static void union(int a,int b){
        int ff=findParent(a);
        int ss=findParent(b);
        if(rank[ff]<rank[ss]){
            parent[ff]=ss;
        }
        else if(rank[ss]<rank[ff]){
            parent[ss]=ff;
        }

        else{
            parent[ff]=ss;
            rank[ss]++;
        }

    }

static class ArrayMaxComparator implements Comparator<int[]> {
    public int compare(int[] a, int[] b) {
        return b[0] - a[0];
    }
}


    public static void main(String[] args) {
        try {
            FastReader sc = new FastReader();
            FastWriter out = new FastWriter();
//int t=sc.nextInt();
//while(t-->0) {
//    int a = sc.nextInt();
//    int b = sc.nextInt();
//int total=sc.nextInt();
//int discount= sc.nextInt();
//long first= (long) b * total;
//
//int times=(total)%(discount+1)==0?(total)/(discount+1):(total)/(discount+1)+1;
//long second= (long) times *discount*a;
//times--;
//long third=(((long) times *discount*a));
//int left=total-(times*discount+times);
//long fourth=third;
//third+= (long) left *b;
//fourth+=(long)left*a;
//
//    System.out.println(Math.min(fourth,Math.min(((long) a *total),Math.min(first,Math.min(second,third)))));
//


        String s=sc.next();
        HashMap<Character,Integer> map=new HashMap<>();
        PriorityQueue<Integer> pq=new PriorityQueue<>(Collections.reverseOrder());
        for(char gg:s.toCharArray()){
            map.put(gg,map.getOrDefault(gg,0)+1);

        }
        for(char key:map.keySet()){
            pq.add(map.get(key));
        }

            long ans= (long) pq.remove();
//        int count=1;
//
//        int n=s.length();
//
//        ArrayList<Integer> occ=new ArrayList<>();
//       for(int i=1;i<n;i++){
//           if(s.charAt(i)!=s.charAt(i-1)){
//               occ.add(count);
//               count=1;
//           }else{
//               count++;
//           }
//       }
//       if(count!=0)occ.add(count);
//       int []prev_max=new int[occ.size()];
//       int [] suff_max=new int[occ.size()];
//       prev_max[0]=occ.get(0);
//for(int i=1;i<occ.size();i++){
//    prev_max[i]=Math.max(occ.get(i),prev_max[i-1]);
//}
//
//
//
//
//suff_max[occ.size()-1]=occ.get(occ.size()-1);
//
//
//
//
//for(int i=occ.size()-2;i>=0;i--){
//    suff_max[i]=Math.max(suff_max[i+1],occ.get(i));
//}
//int ans=0;
//for(int i=0;i<occ.size()-1;i++){
//    ans=Math.max(ans,prev_max[i]*suff_max[i+1]);
//
//}
//            System.out.println(ans);

//            int n=s.length();
//            // int ans=0;
//            HashMap<String,Integer> map2=new HashMap<>();
//            for(int i=0;i<n-1;i++){
//
//                for(int j=i+1;j<n;j++){
//                    String s2=""+s.charAt(i);
//                    s2+=s.charAt(j);
//                    map2.put(s2,map2.getOrDefault(s2,0)+1);
//                    ans=Math.max(ans,map2.get(s2));
//                }
//            }
//            System.out.println(ans);
//
int n=s.length();
            int [][] d_2=new int[n][26];
            for(int i=0;i<n;i++){
                int num=s.charAt(i)-'a';
                if(i==0){
                    for(int ij=0;ij<26;ij++){
                        d_2[i][ij]=ij==num?1:0;
                    }
                }else{
                    for(int ij=0;ij<26;ij++) {

                        d_2[i][ij] =ij==num?d_2[i-1][ij]+1:d_2[i-1][ij];
                    }
                }

            }
            int [][] d_2_prev=new int[n][26];
            for(int i=n-1;i>=0;i--){
                int num=s.charAt(i)-'a';
                if(i==n-1){
                    for(int ij=0;ij<26;ij++){
                        d_2_prev[i][ij]=ij==num?1:0;
                    }
                }else{
                    for(int ij=0;ij<26;ij++) {

                        d_2_prev[i][ij] =ij==num?d_2_prev[i+1][ij]+1:d_2_prev[i+1][ij];
                    }
                }

            }
//            for(int []d:d_2_prev)
//            System.out.println(Arrays.toString(d));
         //   qdpinbmcrfwxpdbfgozvvocemjructoadewegtvbvbfwwrpgyeaxgddrwvlqnygwmwhmrhaizpyxvgaflrsvzhhzrouvpxrkxfza
for(int i=0;i<26;i++){
    for(int j=i;j<26;j++){
        char ff=(char)('a'+i);
        char ss=(char)('a'+j);
       long count=0L;

        for(int k=0;k<n-1;k++){
            if(s.charAt(k)==ff){
                count+= (long) d_2_prev[k + 1][ss - 'a'];
            }
        }
        ans=(long)(Math.max(ans,count));
count=0L;

        for(int k=0;k<n-1;k++){
            if(s.charAt(k)==ss){
                count+= (long) d_2_prev[k + 1][ff - 'a'];
            }
        }
        ans=Math.max(ans,count);



    }
}
            //System.out.println(d_2);
          //  System.out.println();
            System.out.println(ans);


        }catch (Exception e) {
            return;
        }
    }

    public static long doncr(int n,int r){
        long ans=1;
        while(r>0){
            ans=((ans%1000000007)*n)%1000000007;
r--;
n--;
        }
        return ans;
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
        // int c;



        Pair(int a, int b ) {
            this.a = a;
            this.b = b;
            //     this.c=c;
        }
    }
    static class Pair2 {
        String a;
        int b;
        // int c;



        Pair2(String a, int b ) {
            this.a = a;
            this.b = b;
            //     this.c=c;
        }
    }
    static   class ArrayKey {
        private int[] array;

        public ArrayKey(int[] array) {
            this.array = array;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            ArrayKey arrayKey = (ArrayKey) o;
            return Arrays.equals(array, arrayKey.array);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(array);
        }
    }

}