// I'm done with Java stack overflow.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class ScyScrapers {
    public static void main(String[] args)throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        StringTokenizer st=new StringTokenizer(br.readLine());
        int a[]=new int[n+1];
        for(int i=1;i<=n;i++){
            a[i]=Integer.parseInt(st.nextToken());
        }
        long left[]=new long[n+1];
        long right[]=new long[n+2];
        Stack<Integer> stack=new Stack<>();
        for(int i=1;i<=n;i++){
            int p=0;
            while(!stack.isEmpty()){
                int top=stack.peek();
                if(a[top]>=a[i]){
                    stack.pop();
                }
                else{
                    p=top;
                    break;
                }
            }
            stack.push(i);
            left[i]=left[p]+1l*(i-p)*a[i];
//            System.out.println(stack.toString());
        }
        stack=new Stack<>();
        for(int i=n;i>=1;i--){
            int p=n+1;
            while(!stack.isEmpty()){
                int top=stack.peek();
                if(a[top]>=a[i]){
                    stack.pop();
                }
                else{
                    p=top;
                    break;
                }
            }
            stack.push(i);
            right[i]=right[p]+1l*(p-i)*a[i];
        }
        int maxIndex=-1;
        long max=0;
        for(int i=1;i<=n;i++){
            if(right[i]+left[i]-a[i]>max){
                max=right[i]+left[i]-a[i];
                maxIndex=i;
            }
//            System.out.println(left[i]+" "+right[i]);
        }
        int ans[]=new int[n+1];
        int m=a[maxIndex];
        ans[maxIndex]=a[maxIndex];
        for(int i=maxIndex-1;i>=1;i--){
            if(a[i]>m){
                ans[i]=m;
            }
            else{
                ans[i]=a[i];
                m=ans[i];
            }
        }
        m=a[maxIndex];
        for(int i=maxIndex+1;i<=n;i++){
            if(a[i]>m){
                ans[i]=m;
            }
            else{
                ans[i]=a[i];
                m=ans[i];
            }
        }
        StringBuilder print=new StringBuilder();
        for(int i=1;i<=n;i++){
            print.append(ans[i]+" ");
        }
        System.out.println(print.toString());
    }
}
