import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.TreeMap;

public class PerformTheCombo {


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
        int n=Integer.parseInt(temp[0]);
        int m=Integer.parseInt(temp[1]);
        String s=br.readLine();
        temp=br.readLine().split(" ");
        TreeMap<Integer,Integer> map=new TreeMap<>();
        for(int i=0;i<m;i++){
            int pos=Integer.parseInt(temp[i]);
            int start=0;
            int end=pos;
            map.put(start,map.getOrDefault(start,0)+1);
            map.put(end,map.getOrDefault(end,0)-1);
        }
        int[] count=new int[26];
        int pressedTime=0;
        for(int i=0;i<n;i++){
            if(map.containsKey(i)){
                pressedTime+=map.get(i);
            }
            char button=s.charAt(i);
            count[button-'a']+=pressedTime;
            count[button-'a']++;
        }
        for(int i:count){
            pr.print(i+" ");
        }
        pr.print('\n');
    }
}
