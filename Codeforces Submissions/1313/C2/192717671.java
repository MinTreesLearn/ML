import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer zer = new StringTokenizer(br.readLine());
        long[] a = new long[n];
        for(int i = 0; i < n; i++){
            a[i] = Long.parseLong(zer.nextToken());
        }
        int pse[], nse[];
        pse = new int[n];
        Arrays.fill(pse, -1);
        nse = new int[n];
        Arrays.fill(nse, -1);
        Stack<Integer> stk = new Stack<>();
        stk.push(0);
        for(int i = 1; i < n; i++){
            while(!stk.empty() && a[stk.peek()] > a[i]){
                nse[stk.pop()] = i;
            }
            stk.push(i);
        }
        while(!stk.empty()){
            stk.pop();
        }
        stk.push(n - 1);
        for(int i = n - 2; i >= 0; i--){
            while(!stk.empty() && a[stk.peek()] > a[i]){
                pse[stk.pop()] = i;
            }
            stk.push(i);
        }
        long[] dlr = new long[n];
        long[] drl = new long[n];
        dlr[0] = a[0];
        for(int i = 1; i < n; i++){
            if(pse[i] == -1){
                dlr[i] = a[i] * (i + 1);
            }else{
                dlr[i] = dlr[pse[i]] + a[i] * (i - pse[i]);
            }
        }
        drl[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(nse[i] == -1){
                drl[i] = a[i] * (n - i);
            }else{
                drl[i] = drl[nse[i]] + a[i] * (nse[i] - i);
            }
        }
        int aidx = 0;
        long maxans = -1;
        for(int i = 0; i < n; i++){
            long curans = dlr[i] + drl[i] - a[i];
            if(curans > maxans){
                maxans = curans;
                aidx = i;
            }
        }
        long[] ans = new long[n];
        ans[aidx] = a[aidx];
        for(int i = aidx + 1; i < n; i++){
            ans[i] = Math.min(ans[i - 1], a[i]);
        }
        for(int i = aidx - 1; i >= 0; i--){
            ans[i] = Math.min(ans[i + 1], a[i]);
        }
        for(long e : ans){
            System.out.print(e + " ");
        }
        System.out.println();
    }
}
