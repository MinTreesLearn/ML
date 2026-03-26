import java.util.*;
public class MyClass {
    static class Pair implements Comparable<Pair>{
        int x,y;
        Pair(int x,int y){
            this.x=x; this.y=y;
        }
        public int compareTo(Pair p){
            return Integer.compare(this.y,p.y);
        }
    }
    public static void main(String args[]) {
      Scanner in =new Scanner(System.in);
      HashMap<Long,ArrayList<Pair>> hm=new HashMap<Long,ArrayList<Pair>>();
      int n=in.nextInt();
      int a[]=new int[n];
      long sum[]=new long[n];
      long s=0;
      for(int i=0;i<n;i++){  a[i]=in.nextInt(); s+=a[i]; sum[i]=s; }
      for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
              long x=sum[j]-sum[i]+a[i];
              ArrayList<Pair> temp=new ArrayList<Pair>();
              if(hm.containsKey(x)) { temp=hm.get(x); }
              temp.add(new Pair(i+1,j+1));
              hm.put(x,temp);
          }
      }
      ArrayList<Pair> ans=new ArrayList<Pair>();
      for(Map.Entry em:hm.entrySet()){
          ArrayList<Pair> array=hm.get(em.getKey());
          Collections.sort(array);
          int prev=0;
          ArrayList<Pair> temp=new ArrayList<Pair>();
          for(int i=0;i<array.size();i++){
              if(array.get(i).x>prev){ temp.add(new Pair(array.get(i).x,array.get(i).y)); prev=array.get(i).y; }
          }
        //  System.out.println(temp.size());
          if(temp.size()>ans.size()){
              ans=(ArrayList<Pair>)temp.clone();
          }
      }
      long g=-5;
      System.out.println(ans.size()); 
      for(int i=0;i<ans.size();i++){
          System.out.println(ans.get(i).x+" "+ans.get(i).y);
      }
    }
}