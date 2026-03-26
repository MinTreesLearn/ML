// Hydro submission #632f16e3ea0e1b063193825e@1664030435801
import java.util.*;

public class Main {

    static class Person{
        long t, l, h;
        Person(long t, long l, long h){
            this.t = t;
            this.l = l;
            this.h = h;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        g:for(int i=0;i<q;i++){
            int n = scanner.nextInt(), m = scanner.nextInt();
            Person[] p = new Person[n];
            for(int j=0;j<n;j++) p[j] = new Person(scanner.nextLong(), scanner.nextLong(), scanner.nextLong());
            long left = m - p[0].t, right = m + p[0].t;
            for(int j=0;j<n;j++){
                Person cur = p[j];
                if(cur.h < left || cur.l > right){
                    System.out.println("NO");
                    continue g;
                }else if(j == n - 1){
                    System.out.println("YES");
                    continue g;
                }
                if(cur.l >= left && cur.h <= right){ //包含
                    left = cur.l;
                    right = cur.h;
                }else if(cur.l >= left) left = cur.l; //右侧有区间重叠
                else if(cur.h <= right) right = cur.h;
                left -= p[j + 1].t - cur.t;
                right += p[j + 1].t - cur.t;
            }
        }
    }
}