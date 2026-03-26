import java.util.*;
import java.io.*;

public class Solution {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;

        while (t-- > 0) {

            // int n = Integer.parseInt(br.readLine());

            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());

            int arr[] = new int[n];
            HashMap<Integer, Integer> map = new HashMap<>();
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                int e = Integer.parseInt(st.nextToken());
                arr[i] = e;
                max = Math.max(max, e);
                map.put(e, -1);
            }

            map.put(0,-1);

            int res = 0;
            if(max >= x)
            res = map.containsKey(x)?1:2;

            else
            {
                int div = x / max;

                if(div != 1)
                {
                    div = (div>1)?div-1:div;

                    x-=(div*max);
    
                    res+=div;
                }

                if(map.containsKey(x))
                res++;

                else
                res+=2;

            }

            output.write(res + "\n");

            // char arr[] = br.readLine().toCharArray();

            // output.write();
            // int n = Integer.parseInt(st.nextToken());

            // HashMap<Character, Integer> map = new HashMap<Character, Integer>();

            // if
            // output.write("YES\n");
            // else
            // output.write("NO\n");

            // long a = Long.parseLong(st.nextToken());
            // long b = Long.parseLong(st.nextToken());

            // if(flag == 1)
            // output.write("NO\n");
            // else
            // output.write("YES\n" + x + " " + y + " " + z + "\n");

            // output.write(n+ "\n");

        }

        output.flush();

    }

}