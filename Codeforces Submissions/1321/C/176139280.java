import java.util.*;
import java.io.*;

public class Main {
    static Integer dp[][];
  public static void main(String[] args) throws Exception {
    //Code here
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter wr = new PrintWriter(System.out);
    
    int n = Integer.parseInt(br.readLine());
    dp = new Integer[n][n];
    String s = br.readLine();
    System.out.println(dfs(s,0,n-1));
  }
  
  // m2 submitted below
  private static int dfs(String s , int i , int j){
      if(i>j) return 0;
      if(dp[i][j]!=null) return dp[i][j];
      int max = 0;
      
      for(int k = i;k<=j;k++){
          int left = dfs(s,i,k-1);
          int right = dfs(s,k+1,j);
          int currScore = left+right;
          if(left==k-i&&right==j-k){
          int counter = 0;
          if(i-1>=0){
              if((s.charAt(k)-s.charAt(i-1))==1) counter =1;
          }
          if(j+1<s.length()){
              if((s.charAt(k)-s.charAt(j+1))==1) counter = 1;
          }
          currScore+=counter;
          }
          max = Math.max(max,currScore);
         }
         
         return dp[i][j] = max;
      }
  }