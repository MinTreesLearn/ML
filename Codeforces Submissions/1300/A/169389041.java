import java.io.*;
import java.util.*;
public class main{
	public static void main(String args[]){
		Scanner scn = new Scanner(System.in);
		int t = Integer.parseInt(scn.nextLine());

		while(t-->0){
		    int n =Integer.parseInt(scn.nextLine()); 
			String inputs[] = scn.nextLine().split(" ");
			int sum = 0;
			int ans = 0;
			for(int i=0;i<n;i++){
			    sum += Integer.parseInt(inputs[i]);
			    if(Integer.parseInt(inputs[i])==0){
			        ans+=1;
			        sum+=1;
			    }
			}
			if(sum==0)ans+=1;
			System.out.println(ans);
			
		}
	}
}