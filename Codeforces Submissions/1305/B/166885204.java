import java.util.*;
public class sol
{
	public static void main(String[] args) {
// 		System.out.println("Hello World");
        Scanner sc= new Scanner(System.in);
        char ar[]=sc.next().toCharArray();
        int n=ar.length;
        String ans="";
         Queue<Integer> q
            = new LinkedList<>();
             Stack<Integer> q2
            = new Stack<>();
        for(int i=0;i<n;i++){
            if(ar[i]=='('){
                q.add(i+1);
            }
            else if(ar[i]==')') {
                q2.push(i+1);
            }
        }
        int count=0;
        String ans1="";
        String ans2="";
        // System.out.println(q);
        // System.out.println(q2);
        while(!q.isEmpty()&&!q2.isEmpty()){
            // System.out.println("jdkljds");
            int v1=q.remove();
            int v2=q2.pop();
            if(v1<v2){
                ans1+=v1+" ";
                StringBuilder sn2= new StringBuilder(String.valueOf(v2));
                
            ans2+=sn2.reverse().toString()+" "; 
            count+=2;
            }
          
        }
          if(count==0){
            System.out.println("0");
        }
        else{
        StringBuilder sb= new StringBuilder(ans2.substring(0,ans2.length()-1));
        ans2=sb.reverse().toString();
        System.out.println("1");
        System.out.println(count);
        System.out.println(ans1+ans2);
        }
	}
}
