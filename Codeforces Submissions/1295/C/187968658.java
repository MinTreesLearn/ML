import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.TreeSet;

public class ObtainTheString {



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
        char[] s=br.readLine().toCharArray();
        char[] t=br.readLine().toCharArray();
        TreeSet<Integer>[] indexes=new TreeSet[26];
        for(int i=0;i<26;i++){
            indexes[i]=new TreeSet<>();
        }
        for(int i=0;i<s.length;i++){
            char letter=s[i];
            indexes[letter-'a'].add(i);
        }
        int lastIndex=-1;
        int res=1;
        for(int i=0;i<t.length;i++){
            char letter=t[i];
            if(indexes[letter-'a'].size()==0){
                pr.println(-1);
                return;
            }
            var next=indexes[letter-'a'].ceiling(lastIndex+1);
            if(next!=null){
                lastIndex=next;
            }
            else if(next==null){
                lastIndex=indexes[letter-'a'].first();
                res++;
            }
        }
        pr.println(res);
    }




}

