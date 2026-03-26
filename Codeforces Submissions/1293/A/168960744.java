import java.util.*;
public class A1293 {

    public static boolean exist(int[] arr, int x) {
		for (int i=0; i<arr.length; i++) {
			if (arr[i] == x) return true;
		}
		return false;
	}

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int t = scn.nextInt();
        while(t-->0){

            int n = scn.nextInt();
            int s = scn.nextInt();
            int k = scn.nextInt();

            int[] a = new int[k];
            for (int i=0; i<k; i++) a[i] = scn.nextInt();

            // long[] blocked = new long[k];
            for (int i=0; i<=k; i++) {
                if (s-i >= 1 && !exist(a, s-i)) {System.out.println(i);break;}
                if (s+i <= n && !exist(a, s+i)) {System.out.println(i);break;}
            }
            
        }
    }
}
