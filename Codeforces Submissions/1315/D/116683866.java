import java.io.*;
import java.lang.*;
import java.util.*;

public class A1310 {
    public static void main(String[] args) throws IOException{
        StringTokenizer st;
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] a = new int[n];
        int[] t = new int[n];
        st = new StringTokenizer(f.readLine());
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(f.readLine());
        for(int i = 0; i < n; i++){
            t[i] = Integer.parseInt(st.nextToken());
        }
        f.close();
        point[] arr = new point[n];
        for(int i = 0; i < n; i++){
            arr[i] = new point(a[i], t[i]);
        }
        Arrays.sort(arr);
        //System.out.println(Arrays.toString(arr));
        long last = arr[0].x;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        long end = 0;
        long sum = 0;
        for(int i = 0; i < n; i++){
            if(arr[i].x == last){
                pq.add(arr[i].y);
            }else{
                for(int x = 0; x < arr[i].x - last && !pq.isEmpty(); x++) {
                    int r = pq.poll();
                    sum-=r;
                    end+=sum;
                }
                pq.add(arr[i].y);
            }
            sum+=arr[i].y;
            last = arr[i].x;
        }
        while(!pq.isEmpty()) {
            int r = pq.poll();
            sum-=r;
            end+=sum;
        }
        System.out.println(end);
    }
    public static class point implements Comparable<point>{
        long x;
        int y;
        public point(long x,int y){
            this.x = x;
            this.y = y;
        }
        public String toString(){
            return(x + " " + y);
        }
        public boolean equals(Object x){
            point y = ((point)(x));
            if (this.x == y.x && this.y == y.y){
                return true;
            }
            return false;
        }
        public int hashCode(){
            return Objects.hash(x,y);
        }
        public int compareTo(point other){
            if(this.x > other.x || (this.x == other.x && this.y > other.y)){
                return 1;
            }else if(this.x == other.x && this.y == other.y){
                return 0;
            }
            return -1;
        }
    }
}