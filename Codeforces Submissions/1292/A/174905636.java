import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class neko {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out)); 
		int n = in.nextInt();
		int q = in.nextInt();
		int[][] mat = new int[2][n];
		int cnt = 0;
		
		for(int i = 0; i<q; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			a--;
			b--;
			if(mat[a][b]==0) {
				mat[a][b] = 1;
			}
			else if(mat[a][b]==1) {
				mat[a][b] = 0;
				if(a==1) {
					if(mat[a-1][b]==1) {
						cnt--;
					}
					if(b!=n-1 && mat[a-1][b+1]==1) {
						cnt--;
					}
					if(b!=0 && mat[a-1][b-1]==1) {
						cnt--;
					}
				}
				else {
					if(mat[a+1][b]==1) {
						cnt--;
					}
					if(b!=n-1 && mat[a+1][b+1]==1) {
						cnt--;
					}
					if(b!=0 && mat[a+1][b-1]==1) {
						cnt--;
					}
				}
				
			}
			if(a==1 && mat[a-1][b]==1 && mat[a][b]==1) {
				cnt++;
			}
			if(a==0 && mat[a+1][b]==1 && mat[a][b]==1) {
				cnt++;
			}
			if(a==1 && ((b!=n-1 && mat[a-1][b+1]==1 && mat[a][b]==1))) {
				cnt++;
			}
			if(a==1 && (b!=0 && mat[a-1][b-1]==1 && mat[a][b]==1)) {
				cnt++;
			}
			if(a==0 && (b!=0 && mat[a+1][b-1]==1 && mat[a][b]==1)) {
				cnt++;
			}
			if(a==0 && (b!=n-1 && mat[a+1][b+1]==1 && mat[a][b]==1)) {
				cnt++;
			}
			if(cnt==0) {
				log.write("Yes"+"\n");
			}
			else {
				log.write("No"+"\n");
			}
			
		}
		log.flush();
	}

}
