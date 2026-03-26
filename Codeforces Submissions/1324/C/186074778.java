import java.util.*;


public class frogJumps {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
        int t = sc.nextInt();
        sc.nextLine();
        while(t > 0 ){
            solve();
            t--;
        }
	}

	public static void solve() {
        char[] arr = sc.nextLine().toCharArray();
        long length = 0;
        long max = Integer.MIN_VALUE;
        for(long i = 0;i < arr.length;i++){
            if(arr[(int) i] == 'L') length++;
            else length = 0;
            max = Math.max(max, length);
        }
        System.out.println(max+1);
	}
}