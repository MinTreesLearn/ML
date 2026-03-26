import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class AnuHasAFunction {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        final int n = Integer.parseInt(reader.readLine());
        String[] split = reader.readLine().split(" ");
        int[] arr = new int[n];
        for(int i = 0; i < split.length; i++) {
            arr[i] = Integer.parseInt(split[i]);
        }
        int[] bits = new int[32];
        for(int i = 0; i < arr.length; i++) {
            int v = arr[i];
            int bit = 0;
            while(v != 0) {
                if(v % 2 == 1) {
                    bits[bit]++;
                }
                bit++;
                v /= 2;
            }
        }
        int[] answer = new int[n];
        int firstIndex = 0;
        int mostSignificant = -1;
        for(int i = 0; i < arr.length; i++) {
            int v = arr[i];
            int bit = 0;
            while(v != 0) {
                if(v % 2 == 1) {
                    if(bits[bit] == 1 && bit > mostSignificant) {
                        mostSignificant = bit;
                        firstIndex = i;
                    }
                }
                bit++;
                v /= 2;
            }
        }

        int j = 1;
        int p = 0;
        answer[0] = arr[firstIndex];
        while(j < answer.length) {
            if(p == firstIndex) {
                p++;
            } else {
                answer[j] = arr[p];
                j++;
                p++;
            }
        }

        for(int i = 0; i < arr.length; i++) {
            System.out.print(answer[i] + " ");
        }
    }
}
