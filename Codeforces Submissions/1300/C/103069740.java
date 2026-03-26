import java.util.*;
public class Codeforces {
    static Scanner sr = new Scanner(System.in);
    public static void main(String[] args) throws java.lang.Exception {
        int n = sr.nextInt();
        long a[] = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sr.nextLong();
        }
        int m=0;
        int c[] = new int[30];
        for (int i = 0; i < n; i++){
            long x=a[i];
            m=0;
            while(x>=Math.pow(2,m))
            {
                if((x&(long)Math.pow(2,m))==Math.pow(2,m))
                {
                    c[m]++;
                }
                ++m;
            }
        }
        for(int i=29;i>-1;i--)
        {
            if(c[i]==1)
            {
                m=i;
                break;
            }
        }
        for (int i = 0; i < n; i++){
            if((a[i]&(long)Math.pow(2,m))==Math.pow(2,m)){
                System.out.print(a[i]+" ");
                a[i]=-1;
                break;
            }
        }
        for (int i = 0; i < n; i++){
            if(a[i]!=-1)
                System.out.print(a[i]+" ");
        }
        System.out.println();
    }
}


