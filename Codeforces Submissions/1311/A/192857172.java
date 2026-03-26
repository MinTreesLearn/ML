import java.util.*;
public class Main
{
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t--!=0){
		    int a=sc.nextInt();
		    int b=sc.nextInt();
		    int ans=0;
		    boolean p=true;
		    if(a==b){
		        p=false;
		        System.out.println(0);
		    }
		    else if(a>b){
		        int d=a-b;
		        ans++;
		        if(d%2!=0){
		            ans+=1;
		        }
		    }
		    else{
		        int d=b-a;
		        ans++;
		        if(d%2!=1){
		            ans++;
		        }
		    }
		    if(p==true){
		        System.out.println(ans);
		    }
		    
		}
	}
}