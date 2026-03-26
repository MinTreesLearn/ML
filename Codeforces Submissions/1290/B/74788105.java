import java.io.*;
import java.util.*;
public class Main{

    /*
        Integer.parseInt(re.readLine());
        Integer.parseInt(tk.nextToken());
        tk = new StringTokenizer(re.readLine());
    */
    
    private static StringTokenizer tk;
    private static BufferedReader re;
    private static ArrayList<TreeSet<Integer>> list;
    
    private static void tokenize()throws IOException{
        tk = new StringTokenizer(re.readLine());
    }

    public static void main(String []args)throws IOException{
        re = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        char s[] = re.readLine().toCharArray();
        
        list = new ArrayList<>();
        
        for(int i=0; i<26; i++)
            list.add(new TreeSet<>());
            
        for(int i=0; i<s.length; i++){
            int k = s[i]-'a';
            list.get(k).add(i);
        }
        
        int q = Integer.parseInt(re.readLine());
        
        while(q-->0){
            tokenize();
            int l = Integer.parseInt(tk.nextToken())-1, r = Integer.parseInt(tk.nextToken())-1;
            
            if(r == l)
            	pw.println("Yes");
            else if(s[l] != s[r])
                pw.println("Yes");
            else{
                int count = 0;
                for(int i=0; i<26; i++){
                	int fp;
                	if(list.get(i).ceiling(l) != null){
                		fp = list.get(i).ceiling(l);
                    	if(fp <= r)
                        	count++;
                	}
                }    
                if(count > 2)
                    pw.println("Yes");
                else
                    pw.println("No");
            }
        }
        
        pw.flush();
        pw.close();
    }
}