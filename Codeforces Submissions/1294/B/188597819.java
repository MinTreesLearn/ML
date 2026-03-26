//package contest;

import java.io.*;
import java.util.*;


public class A {
	
	static class Pair{
		int x;
		int y;
			public Pair(int x, int y) {
				this.x=x;
				this.y=y;
			}
		}
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0) {
			int n = sc.nextInt();
			Pair arr[] = new Pair[n];
			for(int i=0;i<n;i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				arr[i] = new Pair(x,y);
			}
			Arrays.sort(arr, (p1, p2) -> {
				if(p1.x==p2.x) {
					return p1.y-p2.y;
				}else{
					return p1.x-p2.x;
				}});
			int sx=0,sy=0,ok=1;
			String ans = "";
			for(int i=0;i<n;i++) {
				if(arr[i].x<sx || arr[i].y<sy) {
					ok=0;
					break;
				}
				while(sx<arr[i].x) {
					ans+="R";sx++;
				}
				while(sy<arr[i].y) {
					ans+="U";sy++;
				}
			}
			if(ok==1) {
				System.out.println("YES");
				System.out.println(ans);
			}else {
				System.out.println("NO");
			}
		}
		
	}

}
