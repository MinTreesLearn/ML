/*
6 9
1 5
5 4
1 2
2 3
3 4
4 1
2 6
6 4
4 2
4
1 2 3 4

8 13
8 7
8 6
7 5
7 4
6 5
6 4
5 3
5 2
4 3
4 2
3 1
2 1
1 8
5
8 7 5 2 1
*/
import java.util.*;
import java.io.*;

public class Main{
  public static int n; //n intersections
  public static int m; //m paths 
  public static ArrayList<Integer>[] edges; //edges, directed, for the purposes of calculating # of rebuilds that may occur throughout Polycarp's journey
  public static ArrayList<Integer>[] reversed; //edges, directed, reversed for the purposes of finding shortest
  public static int[] shortest; //shortest[i] = shortest distance between i and the place where Polycarp's workplace is situated
  public static int k; //# of intersections on Polycarp's path
  public static int[] path; //Polycarp's path
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer details = new StringTokenizer(br.readLine());
    n = Integer.parseInt(details.nextToken());
    m = Integer.parseInt(details.nextToken());
    edges = new ArrayList[n];
    reversed = new ArrayList[n];
    for(int a = 0; a < n; a++){
      edges[a] = new ArrayList<Integer>(); 
      reversed[a] = new ArrayList<Integer>(); 
    }
    for(int a = 0; a < m; a++){
      StringTokenizer ed = new StringTokenizer(br.readLine());
      int f = Integer.parseInt(ed.nextToken()) - 1;
      int s = Integer.parseInt(ed.nextToken()) - 1; 
      edges[f].add(s);
      reversed[s].add(f);
    }

    k = Integer.parseInt(br.readLine());
    path = new int[k];
    StringTokenizer pt = new StringTokenizer(br.readLine());
    for(int a = 0; a < k; a++){
      path[a] = Integer.parseInt(pt.nextToken()) - 1; 
    }

    //find shortest
    run(path[k - 1]);

    int least = 0; //least # of rebuilds 
    int most = 0; //most # of rebuilds

    //System.out.println(Arrays.toString(shortest));

    for(int cur = 0; cur < k-1; cur++){
      HashSet<Integer> s = new HashSet<Integer>(); 
      int st = 1000000000; 
      for(int edge : edges[path[cur]]){
        if(shortest[edge] < st){
          s.clear(); 
          s.add(edge);
          st = shortest[edge];
        }
        else if(shortest[edge] == st){
          s.add(edge);
        }
      }
      //System.out.println(edges[path[cur]] + " " + path[cur + 1]);
      //System.out.println(s);
      //three cases:
      //multiple shortest paths, polycarp follows one --> add one to most (can project shortest path that polycarp is following or some other shortest path)
      if(s.contains(path[cur+1]) && s.size() > 1){
        most++; 
      }
      //polycarp does not follow a shortest path --> must add one to least and most (rebuilds no matter what)
      else if(!s.contains(path[cur+1])){
        most++; 
        least++; 
      }
      //only one shortest path, polycarp follows it --> cannot add to least or most (no rebuilds no matter what)
    }

    System.out.println(least + " " + most);      
    br.close();
  }
  public static void run(int start){
    shortest = new int[n];
    boolean[] seen = new boolean[n];
    Arrays.fill(shortest, 1000000000);
    shortest[start] = 0; 
    Queue<Integer> q = new LinkedList<Integer>(); 
    q.add(start);
    while(!q.isEmpty()){
      int cur = q.poll(); 
      if(!seen[cur]){
        seen[cur] = true; 
        for(int edge : reversed[cur]){
          if(shortest[edge] > shortest[cur] + 1){
            shortest[edge] = shortest[cur] + 1; 
            q.add(edge);
          }
        }
      }
    }
  }
}