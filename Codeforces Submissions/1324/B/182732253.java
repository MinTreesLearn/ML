import java.util.Scanner;

public class Codeforces1324 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());
        StringBuffer sb = new StringBuffer();

        for (int i=0;i < n;++i) {
            int m = Integer.parseInt(in.nextLine());
            String[] items = in.nextLine().split(" ");
            int j = 0;
            boolean found = false;
            while (j < m - 2) {
                for (int k = m - 1; k > j + 1;--k) {
                    if (items[j].equals(items[k])) {
                        found = true;
                        break;
                    }
                }
                if (found)                         {
                    sb.append("YES").append("\n");
                    break;
                } else {
                    ++j;
                }
            }
            if (!found)  sb.append("NO").append("\n");
        }
        System.out.print(sb.substring(0, sb.length() - 1));

    }
}
