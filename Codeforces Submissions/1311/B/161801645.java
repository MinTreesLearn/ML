import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class WeirdSort {

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        int count=0;
        while(count<t){
            solve(br);
            count++;
        }
    }

    static int[] father;

    public static void solve(BufferedReader br) throws IOException{
        String[] temp=br.readLine().trim().split(" ");
        int n=Integer.parseInt(temp[0]);
        int m=Integer.parseInt(temp[1]);
        int[] nums=new int[n];
        temp=br.readLine().trim().split(" ");
        Map<Integer,Set<Integer>> map=new HashMap<>();
        for(int i=0;i<n;i++){
            nums[i]=Integer.parseInt(temp[i]);
            if(map.containsKey(nums[i])==false){
                map.put(nums[i],new HashSet<>());
            }
            map.get(nums[i]).add(i);
        }
        int[] pos=new int[m];
        temp=br.readLine().trim().split(" ");
        for(int i=0;i<m;i++){
            pos[i]=Integer.parseInt(temp[i]);
        }
        int[] sorted= nums.clone();
        Arrays.sort(sorted);
        init(n);
        for(int p:pos){
            union(p,p-1);
        }
        for(int i=0;i<n;i++){
            if(sorted[i]==nums[i]){
                continue;
            }
            int shouldBe=sorted[i];
            Set<Integer> indexes=map.get(shouldBe);
            boolean find=false;
            for(int index:indexes){
                if(findFather(i)==findFather(index)){
                    find=true;
                    break;
                }
            }
            if(find==false){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");

    }



    public static void init(int n){
        father=new int[n];
        for(int i=0;i<n;i++){
            father[i]=i;
        }
    }

    public static int findFather(int x){
        if(father[x]==x){
            return father[x];
        }
        father[x]=findFather(father[x]);
        return father[x];
    }

    public static void union(int x1,int x2){
        father[findFather(x1)]=findFather(x2);
    }

}
