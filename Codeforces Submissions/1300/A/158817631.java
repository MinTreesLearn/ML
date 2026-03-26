import java.util.*;

/*

4
3
2 -1 -1
4
-1 0 0 1
2
-1 2
3
0 -2 1



*/
public class sequenceTransformation {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int t = scan.nextInt();
		while(t > 0) {
			int n = scan.nextInt();
			int sum=0;
			int ret=0;
			int[] arr = new int[n];
			for(int i=0;i<n;i++){
			    arr[i]=scan.nextInt();
			    
			    
			    if(arr[i]==0){
			        ret++;
			        arr[i]=1;
			    }
			    sum+=arr[i];
			    
			}
			int i=0;
			while(sum==0){
			    if(arr[i]>0){
			        arr[i]++;
			        ret++;
			        sum=1;
			    }
			    i++;
			}
			System.out.println(ret);
			t--;
		
		}

	}
	
}
