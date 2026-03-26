import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Stack;

public class UnusualCompetitions {

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr=new PrintWriter(System.out);
        solve(br,pr);
        pr.flush();
        pr.close();
    }

    public static void solve(BufferedReader br,PrintWriter pr) throws IOException{
        int n=Integer.parseInt(br.readLine());
        if(n%2!=0){
            pr.println(-1);
            return;
        }
        String s=br.readLine();
        int countLeft=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='('){
                countLeft++;
            }
        }
        if(countLeft!=n/2){
            pr.println(-1);
            return;
        }
        int res=0;
        int unMatchedRight=0;
        int index=-1;
        Stack<Character> stack=new Stack<>();
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='('){
                if(unMatchedRight==0){
                    stack.push('(');
                }
                else{
                    unMatchedRight--;
                    if(unMatchedRight==0){
                        res+=i-index+1;
                        index=-1;
                    }
                }
            }
            else if(s.charAt(i)==')'){
                if(stack.size()!=0&&stack.peek()=='('){
                    stack.pop();
                }
                else{
                    if(index==-1){
                        index=i;
                    }
                    unMatchedRight++;
                }

            }
        }
        pr.println(res);

    }
}
