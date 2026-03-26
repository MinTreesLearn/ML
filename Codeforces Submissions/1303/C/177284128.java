import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class PerfectKeyboard {
    public static void main(String[] args) {
        MyScanner scanner = new MyScanner();
        int input = Integer.parseInt(scanner.nextLine());
        for(int i=0; i<input; i++){
            String str = scanner.nextLine();
            Map<Character, Set<Character>> map = new HashMap<>();
            for(int j=0; j<str.length()-1; j++){
                if(!map.containsKey(str.charAt(j))){
                    map.put(str.charAt(j),new HashSet<>());
                }
                if(!map.containsKey(str.charAt(j+1))){
                    map.put(str.charAt(j+1),new HashSet<>());
                }
                map.get(str.charAt(j)).add(str.charAt(j+1));
                map.get(str.charAt(j+1)).add(str.charAt(j));
            }
            helper2(map,str);

        }
    }
    public static void helper2(Map<Character, Set<Character>> map,String str){

        int count = 0;
        for(Set<Character> set:map.values()){
            if(set.size()>2) {
                System.out.println("NO");
                return;
            } else if (set.size() == 1) {
                count++;
            }
        }
        if(count<2 && str.length()>1){
            System.out.println("NO");
            return;
        }
        boolean[] visited = new boolean[26];
        StringBuilder sb = new StringBuilder();

        for(char j='a'; j<='z'; j++){
            if(!visited[j-'a'] && map.getOrDefault(j,new HashSet<>()).size()==1){
                if(!helper(j,map,visited,sb)){
                    System.out.println("NO");
                    return;
                }
            }
        }
        for(char j='a'; j<='z'; j++){
            if(!visited[j-'a'])sb.append(j);
        }
        System.out.println("YES");
        System.out.println(sb);


    }

    public static boolean helper(char curr,Map<Character, Set<Character>> map,boolean[] visited,StringBuilder sb  ){
            visited[curr-'a']=true;
            sb.append(curr);
            for(char letter:map.get(curr)){
                if(!visited[letter-'a']){
                    helper(letter,map,visited,sb);
                }
            }
            return true;

    }
}

class MyScanner {
    BufferedReader br;
    StringTokenizer st;

    public MyScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

}

