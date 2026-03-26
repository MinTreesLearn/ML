import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.HashMap;

public class Hyperset {

    public static char[] values = new char[]{'S', 'E', 'T'};

    public static void main(String[] args) {
        
        FastReader fr = new FastReader();
    
        int n = fr.nextInt();
        int k = fr.nextInt();

        HashMap<String, Integer> cards = new HashMap<>();
        String[] cardsArray = new String[n];

        for (int i = 0; i < n; i++) {
            cardsArray[i] = fr.nextLine();
            cards.put(cardsArray[i], i);
        }
        int result = 0;
        for (int i = 0; i < n - 2; i++) {

            String cardOne = cardsArray[i];

            for (int j = i + 1; j < n - 1; j++) {

                String cardTwo = cardsArray[j];

                String neededCard = calcNeededCard(cardOne, cardTwo);
                if (cards.containsKey(neededCard) && cards.get(neededCard) > j) {
                    result++;
                }
            }
        }
    
        System.out.println(result);
    }


    public static String calcNeededCard(String c1, String c2) {

        StringBuilder sbr = new StringBuilder();

        for (int i = 0; i < c1.length(); i++) {

            if (c1.charAt(i) == c2.charAt(i)) {
                sbr.append(c1.charAt(i));
            } else if (c1.charAt(i) == 'S' || c2.charAt(i) == 'S'){

                if (c1.charAt(i) == 'E' || c2.charAt(i) == 'E') {
                    sbr.append('T');
                } else {
                    sbr.append('E');
                }
                
            } else {
                sbr.append("S");
            }

        }

        return sbr.toString();

    }


    /** HELPER */

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }

        int[] nextLineAsIntArray(int n) {
            int[] result = new int[n];

            for (int i = 0; i < n; i++) {
                result[i] = nextInt();
            }
            return result;
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
