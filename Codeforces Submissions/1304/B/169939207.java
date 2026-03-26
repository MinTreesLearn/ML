import java.util.*;
import java.io.*;
 
public class practice {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new PrintWriter(System.out)));
        StringBuilder sb = new StringBuilder();
 
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        List<String> l1 = new ArrayList<>();
        List<String> l2 = new ArrayList<>();
        Set<String> set = new HashSet<>();

        boolean flag = false;
        String temp = "";

        for (int i = 0; i < n; i++) {

            String str = br.readLine();
            String str_rev = new StringBuilder(str).reverse().toString();

            if (!flag) {

                boolean pal = true;

                for (int j = 0; j < m / 2 && pal; j++) {

                    if (str.charAt(j) != str.charAt(m - j - 1)) pal = false;
                }

                if (pal) {

                    flag = true;
                    temp = str;
                }
            }

            if (set.contains(str)) {

                l1.add(str_rev);
                l2.add(str);
            } else set.add(str_rev);
        }

        int tot = l1.size() * m * 2 + (flag ? m : 0);
        sb.append(tot).append("\n");

        for (String str_temp : l1) sb.append(str_temp);
        if (flag) sb.append(temp);

        int len = l2.size();

        for (int i = len - 1; i >= 0; i--) sb.append(l2.get(i));
 
        pw.println(sb.toString());
        pw.close();
        br.close();
    }
}