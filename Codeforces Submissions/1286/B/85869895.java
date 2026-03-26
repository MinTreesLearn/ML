import java.util.*;

public class Solution {
    static ArrayList<Integer> tree[];
    static int c[];
    public static void main(String[] args) {

        Scanner input=new Scanner(System.in);
        int n=input.nextInt();
        c=new int[n+1];
        tree=new ArrayList[n+1];
        for (int i = 0; i <=n ; i++) {
            tree[i]=new ArrayList<>(); }
        for (int i = 1; i <=n ; i++) {
            int x=input.nextInt();
            tree[x].add(i);
            c[i]=input.nextInt();
        }
        ArrayList<Integer> res=dfs(tree[0].get(0));
        if (!flag) {
            int a[] = new int[n + 1];
            for (int i = 0; i < n; i++) {
                a[res.get(i)] = i + 1;

            }
            System.out.println("YES");
            for (int i = 1; i <= n; i++) {
                System.out.print(a[i] + " ");
            }
        }else {
            System.out.println("NO");
        }
    }

    static boolean flag=false;
    private static ArrayList<Integer> dfs(Integer root) {
        ArrayList<Integer> res=new ArrayList<>();
        for (Integer a:tree[root]) {
            res.addAll(dfs(a));
            if (flag){
                return new ArrayList<>();
            }
        }
        if (c[root]>res.size()){
           flag=true;
           return new ArrayList<>();
        }
        res.add(c[root],root);
        return res;
    }

}
