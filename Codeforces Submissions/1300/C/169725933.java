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
                     
        int n = (fr.nextInt());


        int[] vals = new int[n];

        for(int i = 0;i<vals.length;i++){
            vals[i]=fr.nextInt();
        }


        int[] prefix = new int[31];

        for(int i = 0;i<vals.length;i++){
            int curr = vals[i];

            for(int k=0;k<=30;k++){
                if((curr&(1<<k))>0){
                    prefix[k]++;
                }
            }
        }

        // for(int i =0;i<prefix.length;i++){
        //     pw.print(prefix[i]+" ");
        // }
        // pw.println("");

        int maxNum = -1;

        for(int i = prefix.length-1;i>=0 && maxNum==-1;i--){
            if(prefix[i]==1){
                for(int k=0;k<vals.length;k++){
                    int curr = vals[k];
                    if((curr&(1<<i))>0){
                        maxNum=curr;                        
                    }
                }
            }
        }

        if(maxNum!=-1){
            pw.print(maxNum+" ");
        }
        for(int i = 0;i<vals.length;i++){
            if(vals[i]==maxNum){

            }else{
                pw.print(vals[i]+" ");
            }
        }

        pw.println();
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
        int val;
        int valid;

        public Pair(int val,int valid){
            this.val = val;
            this.valid = valid;
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
