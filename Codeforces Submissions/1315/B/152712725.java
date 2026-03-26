import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Bus {

    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    private static int findIndexWithLesserDelta(long[] dp, long number){
        int start = 0, len = dp.length, index;
        long cur;
        if(dp[dp.length - 1] <= number)
            return dp.length;
        int lastgoodjobs = -1;
        do{
            index = start + len / 2;
            len = len == 1 ? 0 : (len / 2 + len % 2);
            cur = dp[index];
            if(cur >= number) { // ИЩЕМ СЛЕВА
                lastgoodjobs = index;
            }
            else{
                start = index;
            }
        } while (len > 0);
        cur = dp[lastgoodjobs];
        while(lastgoodjobs < dp.length){
            if(cur == dp[lastgoodjobs]){
                lastgoodjobs++;
            }
            else
                break;
        }
        return lastgoodjobs;
    }

    public static void main(String[] args) throws IOException {
        int retries = Integer.parseInt(reader.readLine());
        while(retries > 0){
            retries--;
            int a, b, p;
            {
                String[] str = reader.readLine().split(" ");
                a = Integer.parseInt(str[0]);
                b = Integer.parseInt(str[1]);
                p = Integer.parseInt(str[2]);
            }
            String stations = reader.readLine();
            long[] dp = new long[stations.length()];
            dp[0] = 0;
//            if(p < b && p < a)
//            {
//                System.out.println(stations.length());
//                continue;
//            }
            char cur = stations.charAt(0) == 'A' ? 'B' : 'A';
            for(int i = 1; i < dp.length; i++){
                if(cur != stations.charAt(i - 1)){
                    dp[i] = dp[i - 1] + (cur == 'A' ? b : a);
                    cur = stations.charAt(i - 1);
                }
                else
                    dp[i] = dp[i - 1];
            }
            long delta = dp[stations.length() - 1] - p;
            if(delta <= 0) //ДЕНЕГ ХВАТИТ НА ВСЮ ДОРОГУ
                System.out.println(1);
            else{
                System.out.println(findIndexWithLesserDelta(dp, delta));
            }
        }
    }
}
