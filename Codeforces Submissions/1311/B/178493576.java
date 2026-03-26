import java.util.Arrays;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testNum = sc.nextInt();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < testNum; i++) {
            int arrLen = sc.nextInt();
            int setLen = sc.nextInt();
            //先读取数组的数据
            int[] arr = new int[arrLen + 1];
            int[] arrCopy = new int[arrLen + 1];
            int[] set = new int[setLen + 1];
            //arr
            for (int j = 1; j <= arrLen; j++) {
                arr[j] = sc.nextInt();
                arrCopy[j] = arr[j];
            }
            arrCopy[0] = -100;
            //正确的顺序
            Arrays.sort(arrCopy);
            //set
            for (int j = 1; j <= setLen; j++) {
                set[j] = sc.nextInt();
            }
            for (int j = 1; j <= arrLen; j++) {
                for (int k = 1; k <= setLen; k++) {
                    if (arr[set[k]] > arr[set[k] + 1]) {
                        int temp = arr[set[k]];
                        arr[set[k]] = arr[set[k] + 1];
                        arr[set[k] + 1] = temp;
                    }
                }
            }
            Boolean flag = true;
            for (int j = 1; j <= arrLen; j++) {
                if (arr[j] != arrCopy[j]) {
                    ans.append("NO\n");
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.append("YES\n");
            }
        }
        System.out.println(ans);
        sc.close();
    }
}
 		  	  		 				 	  	 		 	 		 		