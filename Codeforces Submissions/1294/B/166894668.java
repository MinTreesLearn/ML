import java.util.Arrays;
import java.util.Scanner;

public class sol {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();

		while (t-- > 0) {
			int n = sc.nextInt();

			int[][] arr = new int[n][2];

			for (int i = 0; i < n; i++) {
				arr[i][0] = sc.nextInt();
				arr[i][1] = sc.nextInt();

			}
Arrays.sort(arr,(i1,i2)->{
                if(i1[0]<i2[0]){
                    return -1;
                }
                else if(i1[0]==i2[0]){
                    return i1[1]<i2[1]?-1:i1[1]>i2[1]?1:0;
                }
                else{
                    return 1;
                }
            });
// 			Arrays.sort(arr, (a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));
			StringBuilder sb = new StringBuilder();
			boolean ok = true;
			int x = 0, y = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i][1] < y) {
					ok = false;
					break;
				}

				while (x < arr[i][0]) {
					sb.append("R");
					x++;
				}
				while (y < arr[i][1]) {
					sb.append("U");
					y++;
				}
			}

			if (ok) {
				System.out.println("YES");
				System.out.println(sb);
			} else {
				System.out.println("NO");
			}

		}

	}

}
