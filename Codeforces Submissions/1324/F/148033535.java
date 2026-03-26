import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class MaximumWhiteSubtree {


    static int mod = 1000000007;

    public static void main(String[] args) throws IOException {

        FastReader reader = new FastReader();
        FastWriter writer = new FastWriter();

        int n = reader.readSingleInt();
        int[] a = reader.readIntArray(n);


        //Seems very DP.
        // white = + 1, Black = -1, and if a subtree contains a negative count, we can discard that subtree.

        Node[] nodes = new Node[n];
        for(int i = 0; i<n; i++){
            boolean isWhite = (a[i] == 1) ? true : false;
            nodes[i] = new Node(isWhite, i+1);
        }

        for(int i = 0; i<n-1; i++){
            int[] e = reader.readIntArray(2);
            nodes[e[0]-1].adj.add(nodes[e[1]-1]);
            nodes[e[1]-1].adj.add(nodes[e[0]-1]);
        }

        //Root the tree.
        nodes[0].dfs();


        //Calc diffs
        nodes[0].dfsForDiff();

        int[] ans = new int[n];

        for(int i = 0; i<n; i++){
            ans[i] = nodes[i].maxDiff;
        }

        writer.writeIntArrayWithSpaces(ans);


    }

    public static class Node {

        int count = 0, maxDiff = 0, id;
        boolean isWhite;
        Node parent;
        ArrayList<Node> adj = new ArrayList<>();

        public Node(boolean isWhite, int id){
            this.isWhite = isWhite;
            this.id = id;
        }

        public int dfs(){
            count = (isWhite) ? 1 : -1;
            for(int i = 0; i<adj.size(); i++){
                Node n = adj.get(i);
                if(n == parent) continue;
                n.parent = this;
                count += Math.max(0, n.dfs());
            }
            return count;
        }

        public void dfsForDiff(){
            maxDiff = count;
            if(parent != null) {
                //If my maxDiff is positive, then it has been added to my parents... So i can subtract it from my parents,
                //and get what the other trees have contributed.
                if(parent.maxDiff > count && count > 0){
                    maxDiff += (parent.maxDiff - count);
                } else if(count <= 0){
                    maxDiff += Math.max(0, parent.maxDiff);
                }
            }

            for(int i = 0; i<adj.size(); i++){
                Node n = adj.get(i);
                if(n == parent) continue;
                n.dfsForDiff();
            }
        }
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
