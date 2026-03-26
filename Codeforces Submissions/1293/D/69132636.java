import java.io.*;
import java.util.*;

public class Day9 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(reader.readLine());
        long x0 = Long.parseLong(st.nextToken());
        long y0 = Long.parseLong(st.nextToken());
        long ax = Long.parseLong(st.nextToken());
        long ay = Long.parseLong(st.nextToken());
        long bx = Long.parseLong(st.nextToken());
        long by = Long.parseLong(st.nextToken());
        st = new StringTokenizer(reader.readLine());
        long xs = Long.parseLong(st.nextToken());
        long ys = Long.parseLong(st.nextToken());
        long t = Long.parseLong(st.nextToken());
        ArrayList<Long> x = new ArrayList<>();
        ArrayList<Long> y = new ArrayList<>();
        x.add(x0);
        y.add(y0);
        long max = Long.parseLong("40000000000000000");
        while(true){
            long nx = x.get(x.size() - 1) * ax + bx;
            long ny = y.get(y.size() - 1) * ay + by;
            if(nx > max || ny > max){
                break;
            }
            x.add(nx);
            y.add(ny);
        }
        int ans = 0;
        for(int i = 0; i < x.size(); ++i){
            long xn = xs;
            long yn = ys;
            long time = t;
            int ind = i;
            int first = i + 1;
            int now = 0;
            while(ind >= 0 && time >= Math.abs(xn - x.get(ind)) + Math.abs(yn - y.get(ind))){
                ++now;
                time -= Math.abs(xn - x.get(ind)) + Math.abs(yn - y.get(ind));
                xn = x.get(ind);
                yn = y.get(ind);
                --ind;
            }
            while(first < x.size() && time >= Math.abs(xn - x.get(first)) + Math.abs(yn - y.get(first))){
                time -= Math.abs(xn - x.get(first)) + Math.abs(yn - y.get(first));
                xn = x.get(first);
                yn = y.get(first);
                ++first;
                ++now;
            }
            ans = Math.max(ans, now);
        }
        writer.println(ans);
        writer.close();
    }
}