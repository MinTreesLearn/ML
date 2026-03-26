
// Imports
import java.util.*;
import java.io.*;

public class D1305 {

    /**
     * @param args the command line arguments
     * @throws IOException, FileNotFoundException 
     */
    public static void main(String[] args) throws IOException, FileNotFoundException {
        
        // TODO UNCOMMENT WHEN ALGORITHM CORRECT
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        
        
        // TODO code application logic here
        int N = Integer.parseInt(f.readLine());
        
        ArrayList<Integer>[] edges = new ArrayList[N];
        int[] degree = new int[N];
        ArrayList<Integer> deg1 = new ArrayList<>();
        
        for(int i = 0; i < N; i++) {
            edges[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(f.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            degree[a]++;
            degree[b]++;
            
            if(degree[a] == 1) {
                deg1.add(a);
            }
            else if(degree[a] == 2) {
                deg1.remove((Integer)a);
            }
            
            if(degree[b] == 1) {
                deg1.add(b);
            }
            else if(degree[b] == 2) {
                deg1.remove((Integer)b);
            }
            
            edges[a].add(b);
            edges[b].add(a);
        }
        
        while(1 == 1) {
            if(deg1.size() == 1) {
                System.out.println("! " + (deg1.remove(0) + 1));
                break;
            }
            else {
                int first = deg1.remove(0) + 1;
                int second = deg1.remove(0) + 1;
                
                System.out.println("? " + first + " " + second);
                System.out.flush();
                
                int l = Integer.parseInt(f.readLine());
                
                if(l == first) {
                    // System.out.println(l + " " + first);
                    System.out.println("! " + first);
                    break;
                }
                if(l == second) {
                    // System.out.println(l + " " + second);
                    System.out.println("! " + second);
                    break;
                }
                
                for(int i : edges[first - 1]) {
                    if(degree[i] == 2) {
                        degree[i] = 1;
                        deg1.add(i);
                    }
                    else {
                        degree[i]--;
                    }
                }
                
                for(int i : edges[second - 1]) {
                    if(degree[i] == 2) {
                        degree[i] = 1;
                        deg1.add(i);
                    }
                    else {
                        degree[i]--;
                    }
                }
            }
        }
        
    }

}
