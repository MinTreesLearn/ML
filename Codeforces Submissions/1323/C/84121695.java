import java.util.*;
import java.io.*;
import java.lang.*;
 
/**
 	@author Vora Mahammadasim
*/

public class Solution{

		public static void main(String [] args){
				Scanner sc = new Scanner(System.in);
				int n = sc.nextInt();
				char[] s = sc.next().toCharArray();
				int ref = 0,ans = 0,l = 0;
				for(int i=0;i<n;i++){
					if(s[i] == '('){
						ref++;
						if(ref == 0){
							ans += (l + 1);
							l = 0;
						}
					}
					else ref --;
					if(ref < 0) l++;
				}
				System.out.println(ref == 0?ans:-1);
		}
}
