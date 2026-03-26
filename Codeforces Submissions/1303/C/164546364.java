import java.io.*;
import java.util.*;
 
public class cf {

	public static void main(String[] args) throws IOException {

		BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(br.readLine());
		
		while(T-->0){
			String str = br.readLine();
			char[] c = str.toCharArray();
			boolean[] vis = new boolean[26];
			ArrayList<Character> al = new ArrayList<Character>();
			boolean pos = true;
			int ix = -1;
			for(char ch: c){
				if (vis[ch-'a']==true){
					if (ix-1>=0 && al.get(ix-1)==ch){
						ix--;
					}else if (ix+1<al.size() && al.get(ix+1)==ch){
						ix++;
					}else{
						pos = false;
						break;
					}
					
				}
				else{
					if (ix+1==al.size()){
						al.add(ch);
						ix++;
					}else if (ix==0){
						al.add(0 , ch);
						ix=0;
					}else{
						pos = false;
						break;
					}
					vis[ch-'a'] = true;	
				}
				if (pos==false){
					break;
				}
			}

			if(pos){
				System.out.println("YES");
				StringBuilder ans = new StringBuilder();
				for (char ch:al){
					ans.append(ch);
				}
				for (int i=0;i<26;i++){
					if(!vis[i]){
							ans.append((char)(i+'a'));
					}
				}
				System.out.println(ans);
			}else{
				System.out.println("NO");
			}
		}
	}
}