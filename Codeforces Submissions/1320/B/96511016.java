import java.util.*;

public class Main {
    static int N = 200005;
    public static void main(String[] args) {
        int[]d = new int[N];
        int n,m,k;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        List<List<Integer>> e = g(n + 1);
        List<List<Integer>> re = g(n + 1);
        for (int i = 0; i < m; i++) {
            int f = sc.nextInt();
            int t = sc.nextInt();
            e.get(f).add(t);
            re.get(t).add(f);
        }
        k = sc.nextInt();
        ArrayList<Integer>p = new ArrayList<>();
        p.add(0);
        for (int i = 0; i < k; i++) {
            p.add(sc.nextInt());
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.add(p.get(k));
        d[p.get(k)] = 1;
        while (!queue.isEmpty()){
            Integer x = queue.poll();
            for(int i : re.get(x)){
                if(d[i] == 0){
                    d[i] = d[x] + 1;
                    queue.add(i);
                }
            }
        }
        int ans1 = 0,ans2 = 0;
        for(int i = 1;i < k;i++){
            if(d[p.get(i)] < d[p.get(i + 1)] + 1){
                ans1++;
            }
            boolean add = false;
            for(int y : e.get(p.get(i))){
                if(y != p.get(i + 1) && d[p.get(i)] == d[y] + 1)
                    add = true;
            }
            ans2 += add ? 1 : 0;
        }
        System.out.println(ans1 + " " + ans2);
    }
    private static List<List<Integer>> g(int len){
        List<List<Integer>>g = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            g.add(new ArrayList<>());
        }
        return g;
    }
}
