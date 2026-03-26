//<———My cp————
//https://takeuforward.org/interview-experience/strivers-cp-sheet/?utm_source=youtube&utm_medium=striver&utm_campaign=yt_video
import java.util.*;
import java.io.*;
public class Solution{
    static PrintWriter pw = new PrintWriter(System.out);
    static FastReader fr = new FastReader(System.in);                
    private static long MOD = 1_000_000_007;
    
    public static void main(String[] args) throws Exception{
        int t = fr.nextInt();
        
        while(t-->0){
            int n = fr.nextInt();
            int[] vals = new int[n];

            int spaceC = 0 ;
            for(int i = 0;i<n;i++){
                vals[i] = fr.nextInt();
                if(vals[i]==-1){
                    spaceC++;
                }
            }

            if(spaceC==n){
                pw.println(0+" "+0);
                
            }else{
                long minElement = Integer.MAX_VALUE;
                long maxValue = Integer.MIN_VALUE;
    
                for(int i  =0;i<n;i++){
                    if(vals[i]==-1){
                        if(i!=n-1 && vals[i+1]!=-1){
                            minElement = Math.min(vals[i+1], minElement);
                            maxValue = Math.max(vals[i+1], maxValue);
                        }

                        if(i!=0 && vals[i-1]!=-1){
                            minElement = Math.min(vals[i-1], minElement);
                            maxValue = Math.max(vals[i-1], maxValue);
                        }
                    }
                }

                long lowMid = (maxValue+minElement)/2;
                long highMid = (maxValue+minElement+1)/2;

                long lowDiff = calc(vals,lowMid);
                long highDiff =  calc(vals, highMid);
                if(lowDiff<highDiff){
                    pw.println(lowDiff+" "+lowMid);
                }else{
                    pw.println(highDiff+" "+highMid);
                }

            }


        }
        pw.close();
        
    }

    public static long calc(int[] vals,long mid){
        long maxDiff = 0;
        for (int i = 0; i < vals.length-1; i++) {
            long a = vals[i];
            long b = vals[i+1];
            if(a==-1){
                a=mid;
            }

            if(b==-1){
                b=mid;
            }

            maxDiff=Math.max(Math.abs(a-b), maxDiff);
        }

        return maxDiff;
    }

    public static boolean poss(int[][] mat,int r,int c,int n){
        if(r<0||c<0||r>=n||c>=n||mat[r][c]!=0){
            return false;
        }
        return true;
    }




    static class Pair{
        int min;
        int max;

        public Pair(int min,int max){
            this.min = min;
            this.max = max;
        }
        @Override
        public String toString() {
            return "min: "+min+" max: "+max;
        }
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

