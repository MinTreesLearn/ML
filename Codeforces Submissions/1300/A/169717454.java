//<———My cp————
//https://takeuforward.org/interview-experience/strivers-cp-sheet/?utm_source=youtube&utm_medium=striver&utm_campaign=yt_video
import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
public class Solution{
    static PrintWriter pw = new PrintWriter(System.out);
    private static long MOD = 1_000_000_007;

    public static void main(String[] args) throws Exception{
        FastReader fr = new FastReader(System.in);                
        int t = fr.nextInt();

        while(t-->0){
            int n = fr.nextInt();
            int[] vals = new int[n];

            int total = 0;
            int count = 0;
            for(int i=0;i<n;i++){
                vals[i]=fr.nextInt();
                total=total+vals[i];
                if(vals[i]==0){
                    total++;
                    count++;
                }
            }

            if(total==0){
                count++;
            }

            pw.println(count);



        }

        pw.close();
        
    }


    public static long opNeeded(long c,long[] vals){

        long tempResult = 0;
        for(int j = 0;j<vals.length;j++){
            tempResult=tempResult+Math.abs((long)(vals[j]-Math.pow(c,j)));
        }

        if(tempResult<0){
            tempResult=Long.MAX_VALUE;
        }
        return tempResult;
    }


    private static long pow(long a, long b) {
        long res = 1;
        while (b > 0) {
            if (b % 2 == 0) {
                a = (a * a) % MOD;
                b /= 2;
            } else {
                res = (res * a) % MOD;
                b--;
            }
        }
        return res;
    }

    static class DSU{
        int[] rank,parent;
        int n;

        public DSU(int n){
            this.n = n;            
            rank = new int[n];
            parent = new int[n];
            makeSet();
        }

        void makeSet(){
            for(int i = 0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(parent[x]==x){
                return x;
            }
            int p = find(parent[x]);
            parent[x]=p;
            return p;
        }

        void union(int x,int y){
            int xRoot = find(x);
            int yRoot = find(y);

            if(xRoot==yRoot){
                return;
            }

            if(rank[xRoot]>rank[yRoot]){
                parent[yRoot]=xRoot;
            }else if(rank[xRoot]<rank[yRoot]){
                parent[xRoot]=yRoot;
            }else{
                parent[yRoot]=xRoot;
                rank[xRoot]+=1;
            }
        }
        
    } 



    static int lowerBound(int left,int right,int[] vals,int value){
        int mid = (left+right)/2;

        while(left<right){
            mid = (left+right)/2;
            if(vals[mid]<value){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }

    static int upperBound(int left,int right,int[] vals,int value){
        while(left<right){
            int mid = (left+right+1)/2;
            if(vals[mid]<=value){
                left=mid;
            }else{
                right=mid-1;
            }
        }
        return left;
    }


    static class Pair{
        int min;
        int max;

        public Pair(int min,int max){
            this.min = min;
            this.max = max;
        }
    }


    static int isPerfectSquare(int vals){
        int lastPow=1;
        while(lastPow*lastPow<vals){
            lastPow++;
        }
        if(lastPow*lastPow==vals){
            return lastPow*lastPow;
        }else{
            return -1;
        }
    }




    public static int[] sort(int[] vals){
        ArrayList<Integer> values = new ArrayList<>();
        for(int i = 0;i<vals.length;i++){
            values.add(vals[i]);
        }
        Collections.sort(values);

        for(int i =0;i<values.size();i++){
            vals[i] = values.get(i);
        }
        return vals;
    }



    public static long[] sort(long[] vals){
        ArrayList<Long> values = new ArrayList<>();
        for(int i = 0;i<vals.length;i++){
            values.add(vals[i]);
        }
        Collections.sort(values);
        for(int i =0;i<values.size();i++){
            vals[i] = values.get(i);
        }
        return vals;
    }

    public static void reverseArray(long[] vals){
        int startIndex = 0;
        int endIndex = vals.length-1;
        while(startIndex<=endIndex){
            long temp =  vals[startIndex];
            vals[startIndex] = vals[endIndex];
            vals[endIndex] = temp;
            startIndex++;
            endIndex--;
        }
    }

    public static void reverseArray(int[] vals){
        int startIndex = 0;
        int endIndex = vals.length-1;
        while(startIndex<=endIndex){
            int temp =  vals[startIndex];
            vals[startIndex] = vals[endIndex];
            vals[endIndex] = temp;
            startIndex++;
            endIndex--;
        }
    }
    


    static class FastReader{
     
        byte[] buf = new byte[2048];
        int index, total;
        InputStream in;
 
        FastReader(InputStream is) {
            in = is;
        }

        int scan() throws IOException {
            if (index >= total) {
                index = 0;
                total = in.read(buf);
                if (total <= 0) {
                    return -1;
                }
            }
            return buf[index++];
        }
 
        String next() throws IOException {
            int c;
            for (c = scan(); c <= 32; c = scan());
            StringBuilder sb = new StringBuilder();
            for (; c > 32; c = scan()) {
                sb.append((char) c);
            }
            return sb.toString();
        }
 
        int nextInt() throws IOException {
            int c, val = 0;
            for (c = scan(); c <= 32; c = scan());
            boolean neg = c == '-';
            if (c == '-' || c == '+') {
                c = scan();
            }
            for (; c >= '0' && c <= '9'; c = scan()) {
                val = (val << 3) + (val << 1) + (c & 15);
            }
            return neg ? -val : val;
        }
 
        long nextLong() throws IOException {
            int c;
            long val = 0;
            for (c = scan(); c <= 32; c = scan());
            boolean neg = c == '-';
            if (c == '-' || c == '+') {
                c = scan();
            }
            for (; c >= '0' && c <= '9'; c = scan()) {
                val = (val << 3) + (val << 1) + (c & 15);
            }
            return neg ? -val : val;
        }
    }

    public static int GCD(int numA, int numB){
        if(numA==0){
            return numB;
        }else if(numB==0){
            return numA;
        }else{
            if(numA>numB){
                return GCD(numA%numB,numB);
            }else{
                return GCD(numA,numB%numA);
            }
        }
    }
}
