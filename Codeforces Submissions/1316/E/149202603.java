/*
4 1 2
1 16 10 3
18
19
13
15

Number of people, number of players chosen for the team, number of players chosen for the audience  
Bonus that each person adds if they are put into the audience  
For every person, bonus that they add if they are put into the team at position i  

Bitmask DP - dp[i][j] = max score that Alice can get given the first i people and that j slots in the team are filled
*/
import java.util.*;
import java.io.*;

public class Main{
  public static int n; //total people in town
  public static int p; //players for the team
  public static int k; //players for the audience
  public static Person[] people; 
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer details = new StringTokenizer(br.readLine());
    n = Integer.parseInt(details.nextToken());
    p = Integer.parseInt(details.nextToken());
    k = Integer.parseInt(details.nextToken());
    people = new Person[n];
    StringTokenizer ad = new StringTokenizer(br.readLine());
    for(int a = 0; a < n; a++){
      StringTokenizer pos = new StringTokenizer(br.readLine());
      long[] ps = new long[p];
      for(int b = 0; b < p; b++) ps[b] = Long.parseLong(pos.nextToken());
      people[a] = new Person(a, Long.parseLong(ad.nextToken()), ps);
    }
    Arrays.sort(people);
    //System.out.println(Arrays.toString(people));

    long[][] dp = new long[n + 1][(1 << p)];
    for(long[] row : dp) Arrays.fill(row, -1000000000000000000L);
    dp[0][0] = 0;
    for(int a = 1; a <= n; a++){
      //forward dp? Try putting this person in the team at position b, or putting them in the audience (?) --> how to figure out which people are in the audience and not in the audience?
      for(int mask = 0; mask < (1 << p); mask++){
        //either occupied or not occupied, try putting this person at position pos
        dp[a][mask] = dp[a - 1][mask];
        int aud = a - 1 - Integer.bitCount(mask); //size of current audience
        if(aud < k) dp[a][mask] = Math.max(dp[a - 1][mask] + people[a - 1].add, dp[a][mask]);
        for(int pos = 0; pos < p; pos++){
          if((mask & (1 << pos)) > 0){
            dp[a][mask] = Math.max(dp[a][mask], dp[a - 1][mask - (1 << pos)] + people[a - 1].pAdd[pos]);
          } 
          //can also try just putting this person in the audience, sorted from greatest contribution to the audience to least contribution to the audience
        }
      }
    }

    System.out.println(dp[n][(1 << p) - 1]);
      
    br.close();
  }
}
class Person implements Comparable<Person>{
  int id; 
  long add; 
  long[] pAdd; 
  public Person(int i, long a, long[] pa){
    id = i; 
    add = a; 
    pAdd = pa; 
  }
  public String toString(){
    return id + " id, adds " + add + " to audience, cost for each pos is " + Arrays.toString(pAdd);
  }
  public int compareTo(Person p){
    if(add > p.add) return -1; 
    if(add < p.add) return 1; 
    return id - p.id; 
  }
}