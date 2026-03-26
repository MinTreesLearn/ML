/*
7
4 1 2 2 1 5 3
*/
import java.util.*;
import java.io.*;

public class Main{
  public static int n; 
  public static int[] vals; 
  public static HashMap<Integer, ArrayList<Block>> sortedBlocks = new HashMap<Integer, ArrayList<Block>>(); //all blocks of a certain value, sorted from earliest to latest endpoint and then earliest to latest starting point
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    n = Integer.parseInt(br.readLine());
    vals = new int[n];
    StringTokenizer vs = new StringTokenizer(br.readLine());
    for(int a = 0; a < n; a++) vals[a] = Integer.parseInt(vs.nextToken());
    
    int[] pre = new int[n];
    pre[0] = vals[0];
    for(int b = 1; b < n; b++){
      pre[b] = vals[b] + pre[b - 1];
    }

    for(int fi = 0; fi < n; fi++){
      for(int si = fi; si < n; si++){
        int v = pre[si];
        if(fi > 0) v -= pre[fi-1];
        if(!sortedBlocks.containsKey(v)) sortedBlocks.put(v, new ArrayList<Block>());
        sortedBlocks.get(v).add(new Block(fi, si, v));
      }
    }

    //System.out.println(sortedBlocks);

    int lg = 0; //most blocks of a certain value
    String best = ""; 
    for(int value : sortedBlocks.keySet()){
      Collections.sort(sortedBlocks.get(value));
      int t = -1; 
      int sm = 0; 
      StringBuilder cr = new StringBuilder(); 
      for(Block b : sortedBlocks.get(value)){ //given a set of ranges, what is the most ranges that you can use? 
        if(b.a > t){
          t = b.b; 
          sm++; 
          cr.append((b.a + 1) + " " + (b.b + 1) + "\n");
        }
      }
      if(sm > lg){
        lg = sm; 
        best = cr.toString();
      }
    }
    System.out.println(lg + "\n" + best.toString());      
    br.close();
  }
}

class Block implements Comparable<Block>{
  int a; 
  int b; //starting and ending indices
  int val; 
  public Block(int ac, int bc, int v){
    a = ac; 
    b = bc; 
    val = v; 
  }
  public int compareTo(Block c){
    if(c.b != b) return b - c.b;
    if(c.a != a) return a - c.a;  
    return val - c.val; 
  }
  public String toString(){
    return a + " " + b; 
  }
}