import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;
 
public class ProblemA {
 
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int test = Integer.parseInt(br.readLine());
		while(test-->0){
			
			int n = Integer.parseInt(br.readLine());
			String line[] = br.readLine().split(" ");
			boolean ok = false;
			for(int i = 0;i<n;i++){
				int a = Integer.parseInt(line[i]);				
				int count = 0;
				for(int j = i+1;j<n;j++){
					if(Integer.parseInt(line[j]) == a){
						count++;
						if(j - i>1){
							ok = true;
							break;
						}
						
					}
				}
				if(count>=3 || ok){
					ok = true;
					break;
				}
			}
			if(ok)sb.append("YES");
			else sb.append("NO");
			sb.append("\n");
			
	}
	System.out.println(sb);
		
		
		
}
	public static int search(int target,int arr[]){
		int l = 0;
		int r = arr.length-1;
		int index = -1;
		while(l<=r){
			int mid = (l+r)/2;
			if(arr[mid]<=target){
				index = mid;
				l = mid+1;
			}else r = mid-1;
			
		}
		return index;
		
	}
	public static void sort(int arr[]){
		ArrayList<Integer>list = new ArrayList<>();
		for(int it:arr)list.add(it);
		Collections.sort(list);
		for(int i = 0;i<list.size();i++)arr[i]  = list.get(i);
	}
	
		
	
}
class Pair{
	int x,y;
	public Pair(int x,int y){
		this.x = x;
		this.y = y;
	}
}

