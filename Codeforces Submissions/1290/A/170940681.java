import java.util.*;
public class p1290A {
    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);
        int t=scn.nextInt();
        for(int i1=0;i1<t;i1++){
            int n=scn.nextInt();
            int m=scn.nextInt();
            int k=scn.nextInt();
            int[] arr=new int[n];
            for(int i=0;i<n;i++){
                arr[i]=scn.nextInt();
            }
            if(m<=k+1){
                k=m-1;
            }
            Integer val1=Integer.MIN_VALUE;
            for(int i=0;i<=k;i++){
                int val=Integer.MAX_VALUE;
                for(int j=0;j<=m-k-1;j++){
                    int a=j+i;
                    int b=n-(-i+m-j);
                    val=Math.min(Math.max(arr[a],arr[b]),val);
                }
                if(val>val1){
                    val1=val;
                }
            }
            System.out.println(val1);
        }
    }
}
