import java.util.*;
 
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    int t = sc.nextInt();
    while(t-- > 0){
      
      int n = sc.nextInt(), m = sc.nextInt();
      String s = sc.next();
      int p[] = new int[n];
      p[n-1]=1;
      for(int i=0; i<m; i++){
        int pi = sc.nextInt();
        p[pi-1]++;
      }
      
      int d6[] = new int[26];
      d6[s.charAt(n-1)-'a']++;
      for(int i=n-2; i>=0; i--){
        p[i] += p[i+1];
        d6[s.charAt(i)-'a']+=p[i];
      }
      
      for(int i=0; i<26; i++) System.out.print(d6[i]+" ");
      System.out.println();
    }
  }
}