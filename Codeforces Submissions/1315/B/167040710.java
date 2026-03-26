import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Homecoming {

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr=new PrintWriter(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t!=0){
            solve(br,pr);
            t--;
        }
        pr.flush();
        pr.close();
    }

    public static void solve(BufferedReader br,PrintWriter pr) throws IOException{
        String[] temp=br.readLine().split(" ");
        int a=Integer.parseInt(temp[0]);
        int b=Integer.parseInt(temp[1]);
        int p=Integer.parseInt(temp[2]);
        String s=br.readLine();
        char[] letters=s.toCharArray();
        int n=s.length();
        long[] needed=new long[n];
        needed[n-2]=(letters[n-2]=='A'?a:b);
        for(int i=n-3;i>=0;i--){
            needed[i]=needed[i+1];
            if(letters[i]!=letters[i+1]){
                needed[i]+=(letters[i]=='A'?a:b);
            }
        }
        for(int i=0;i<n;i++){
            if(needed[i]<=p){
                pr.println(i+1);
                return;
            }
        }
    }
}
