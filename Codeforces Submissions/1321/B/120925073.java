import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.security.KeyStore.Entry;
import java.util.*;

import java.io.*;
public class j19 {
    public static void main(String[] args) throws Exception{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      ArrayList<Integer> al = new ArrayList<>();
      ArrayList<Integer> al1 = new ArrayList<>();
      st = new StringTokenizer(br.readLine());
      int i=1;
      while(st.hasMoreTokens()){
        int k = Integer.parseInt(st.nextToken());
        al.add(k);
        al1.add(i-k);
        i++;
      }
      HashMap<Integer,ArrayList<Integer>> map = new HashMap<Integer,ArrayList<Integer>>();
      for(int j=0;j<n;j++){
        if(!map.containsKey(al1.get(j))){
          map.put(al1.get(j),new ArrayList<>());
          map.get(al1.get(j)).add(j);
        }
        else{
          map.get(al1.get(j)).add(j);
        }
      }
      long max = 0;
      for(int j  : map.keySet()){
       long ans = 0L;
       for(int l : map.get(j)){
         ans += al.get(l);
       }
        max = Math.max(max,ans);
        }
        System.out.println(max);
      }
     }