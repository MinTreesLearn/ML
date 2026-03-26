import java.io.*;
import java.util.*;

public class maxrest {

	public static void main(String[] args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int count = Integer.parseInt(br.readLine());
		int[]nums=new int[count*2];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<count;i++) {
			nums[i]=Integer.parseInt(st.nextToken());
			nums[i+count]=nums[i];
		}
		
		int c=0;
		int g=0;
		for(int i=0;i<nums.length;i++) {
			if(nums[i]==1) {
				c++;
				if(c>g) {
					g=c;
				}
			}
			if(nums[i]==0) {
				c=0;
			}
		}
		System.out.println(g);
	}

}