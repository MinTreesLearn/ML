
import java.util.*;
import java.io.*;
import java.math.*;

public class CodeForces {
    public static void main(String hi[]) throws Exception {
        BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(infile.readLine());
        int N = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        st = new StringTokenizer(infile.readLine());
        for(int i=0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        int[] freq = new int[1<<18];
        for(int x: arr)
            freq[x]++;
        freq[0]++; //dummy root
        DSU union = new DSU();
        long res = 0L;
        matcha:for(int mask=(1<<18)-1; mask >= 0; mask--)
            for(int temp=mask; temp > 0; temp=(temp-1)&mask) {
                int submask = mask^temp;
                if(submask > temp)
                    break;
                if(freq[temp] > 0 && freq[submask] > 0 && union.find(temp) != union.find(submask)) {
                    res += (long)(freq[temp]+freq[submask]-1)*mask;
                    freq[temp] = freq[submask] = 1; //one subtree each
                    union.merge(temp, submask);
                }
            }
        for(int x: arr)
            res -= x;
        System.out.println(res);
    }
}
class DSU {
    public int[] dsu;

    public DSU() {
        dsu = new int[1<<18];
        for(int i=0; i < (1<<18); i++)
            dsu[i] = i;
    }
    public int find(int x) {
        return dsu[x] == x ? x : (dsu[x] = find(dsu[x]));
    }
    public void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        dsu[fx] = fy;
    }
}