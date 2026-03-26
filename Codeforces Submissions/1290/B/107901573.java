import java.io.*;

final public class B {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        char[] arr = br.readLine().toCharArray();
        int q = Integer.parseInt(br.readLine()), len = arr.length;
        int[][] pref = new int[len+1][26];
        for(int i = 1; i<= len; i++){
            for(int j = 0; j<26; j++) {
                if(j == arr[i-1]-97) pref[i][j] = pref[i-1][j] + 1;
                else pref[i][j] = pref[i-1][j];
            }
        }
        for(int i = 0; i< q; i++){
            String[] str = br.readLine().split(" ");
            int l = Integer.parseInt(str[0])-1, r = Integer.parseInt(str[1])-1;
            int cnt = 0;
            for(int j = 0; j<26; j++){
                if((pref[r+1][j] - pref[l][j])>0) cnt++;
            }
            if(cnt >= 3 || r == l || arr[l]!=arr[r]) sb.append("Yes");
            else sb.append("No");
            sb.append('\n');
        }
        System.out.println(sb);
    }
}
