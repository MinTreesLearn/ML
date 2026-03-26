import java.util.*;
import java.io.*;
 
public class Main {
  public static void main(String[] args) throws Exception {
    //Code here
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter wr = new PrintWriter(System.out);
    
    int n = Integer.parseInt(br.readLine());
    String s = br.readLine();
    int count = 0;
    
    for(char ch = 'z';ch>='a';ch--){
        for(int i =0;i<s.length();i++){
            if(s.length()==1) break;
            if(s.charAt(i)!=ch) continue;
            if(i==0){
                if(s.charAt(i+1)==ch-1){
                    count++;
                    s = s.substring(0,i) + s.substring(i+1);
                }
            }else if(i==s.length()-1){
                if(s.charAt(i-1)==ch-1){
                    count++;
                    s = s.substring(0,i) + s.substring(i+1);
                }
            }else{
                if(s.charAt(i+1)==ch-1||s.charAt(i-1)==ch-1){
                    count++;
                    s = s.substring(0,i) + s.substring(i+1);
                    i-=2;
                }
            }
        }
    }
    wr.println(count);
    wr.close();
  }
}