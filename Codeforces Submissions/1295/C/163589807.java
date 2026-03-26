import java.util.*;
public class Solution
{
    public static void main(String[] args)
    {
    
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
           while(t-->0)
            {
            String given = sc.next();
            String target = sc.next();
            System.out.println(solve(given,target));
            
            
            
        }
    }
    private static int solve(String given , String target){
          HashMap<Character, TreeSet<Integer>> hm = new HashMap<>();
          for (int i = 0; i < given.length(); i++)
        {
            char ch = given.charAt(i);
            if(!hm.containsKey(ch)){
            hm.put(ch, new TreeSet<>());
            }
            hm.get(ch).add(i);
        }
      //  boolean flag = false;
        for (char ch : target.toCharArray())
        {
            if (!hm.containsKey(ch))
            {
               // System.out.println(-1);
                //flag=true;
                return -1;
            }
        }
        //if(flag==false){
        int ans = 1;
        int index = hm.get(target.charAt(0)).first();
        for (int i = 1; i < target.length(); i++)
        {
            char ch = target.charAt(i);
            TreeSet<Integer> idxes = hm.get(ch);
            Integer next_index = idxes.higher(index);
            if (next_index == null)
            {
                ans++;
                index = hm.get(ch).first();
            }
            else
            {
                index = next_index;
            }
       // }
      //  System.out.println(ans);
        //return ans;
    }
      return ans;
    }
                
            }