import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Hyperset {


    static int mod = 1000000007;

    public static void main(String[] args) throws IOException {

        FastReader reader = new FastReader();
        FastWriter writer = new FastWriter();
        int[] nk = reader.readIntArray(2);
        int n = nk[0], k = nk[1];

        String[] cards = new String[n];


        for(int i = 0; i<n; i++){
            cards[i] = reader.readString();
        }

        int triple = 0;
        for(int i = 0; i<n; i++){
            HashSet<String> seen = new HashSet<>();
            for(int j = 0; j<i; j++){
                StringBuilder b = new StringBuilder("");
                for(int m = 0; m<k; m++){
                    if(cards[i].charAt(m) == cards[j].charAt(m)) {
                        b.append(cards[i].charAt(m));
                    } else {
                        if(cards[i].charAt(m) != 'S' && cards[j].charAt(m) != 'S'){
                            b.append('S');
                        } else if(cards[i].charAt(m) != 'E' && cards[j].charAt(m) != 'E'){
                            b.append('E');
                        } else {
                            b.append('T');
                        }
                    }
                }
                if(seen.contains(b.toString())) triple++;
                seen.add(cards[j]);
            }
        }

        writer.writeSingleInteger(triple);





    }


    public static void mergeSort(int[] a, int n) {
        if (n < 2) {
            return;
        }
        int mid = n / 2;
        int[] l = new int[mid];
        int[] r = new int[n - mid];

        for (int i = 0; i < mid; i++) {
            l[i] = a[i];
        }
        for (int i = mid; i < n; i++) {
            r[i - mid] = a[i];
        }
        mergeSort(l, mid);
        mergeSort(r, n - mid);

        merge(a, l, r, mid, n - mid);
    }


    public static void merge(int[] a, int[] l, int[] r, int left, int right) {

        int i = 0, j = 0, k = 0;
        while (i < left && j < right) {
            if (l[i] <= r[j]) {
                a[k++] = l[i++];
            }
            else {
                a[k++] = r[j++];
            }
        }
        while (i < left) {
            a[k++] = l[i++];
        }
        while (j < right) {
            a[k++] = r[j++];
        }
    }


    public static class FastReader {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer;


        public int readSingleInt() throws IOException {
            return Integer.parseInt(reader.readLine());
        }

        public int[] readIntArray(int numInts) throws IOException {
            int[] nums = new int[numInts];
            tokenizer = new StringTokenizer(reader.readLine());
            for(int i = 0; i<numInts; i++){
                nums[i] = Integer.parseInt(tokenizer.nextToken());
            }
            return nums;
        }

        public String readString() throws IOException {
            return reader.readLine();
        }

    }



    public static class FastWriter {

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));


        public void writeSingleInteger(int i) throws IOException {
            writer.write(Integer.toString(i));
            writer.newLine();
            writer.flush();
        }

        public void writeSingleLong(long i) throws IOException {
            writer.write(Long.toString(i));
            writer.newLine();
            writer.flush();
        }

        public void writeIntArrayWithSpaces(int[] nums) throws IOException {
            for(int i = 0; i<nums.length; i++){
                writer.write(nums[i] + " ");
            }
            writer.newLine();
            writer.flush();
        }

        public void writeIntArrayListWithSpaces(ArrayList<Integer> nums) throws IOException {
            for(int i = 0; i<nums.size(); i++){
                writer.write(nums.get(i) + " ");
            }
            writer.newLine();
            writer.flush();
        }

        public void writeIntArrayWithoutSpaces(int[] nums) throws IOException {
            for(int i = 0; i<nums.length; i++){
                writer.write(Integer.toString(nums[i]));
            }
            writer.newLine();
            writer.flush();
        }

        public void writeString(String s) throws IOException {
            writer.write(s);
            writer.newLine();
            writer.flush();
        }

    }



}
