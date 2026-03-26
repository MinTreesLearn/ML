import java.io.*;
import java.util.*;
public class HelloWorld{
    
    static class Step{
        long no;
        String comm;
        
        Step(long no, String comm){
            this.no = no;
            this.comm = comm;
        }
    }
    
    private static ArrayList<Step> ls;
    
    private static long k;
    
    private static void check(){
        if(k > 0)   return;
        
        PrintWriter pw = new PrintWriter(System.out);
        
        pw.println("YES");
        pw.println(ls.size());
        
        for(Step step : ls)
            pw.println(+step.no+" "+step.comm);
        
        pw.flush();
        pw.close();
        
        System.exit(0);
    }
    
    private static void addStep(long no, String comm){
        if(no == 0 || comm.length() == 0)
            return;
        
        Step ns = new Step(no, comm);
        ls.add(ns);
        
        k -= no*comm.length();
        check();
        
        //System.out.println(+k);
    }

    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt(), c = sc.nextInt();
        k = sc.nextLong();
        long max = 4*r*c-2*r-2*c;
        
        if(k > max){
            System.out.println("NO");
            System.exit(0);
        }
        
        ls = new ArrayList<>();
        
        for(int i=0; i<r; i++){
            String sdir = (i%2 == 0)?"R":"L";
            
            long lim = Math.min(k, c-1);
            //System.out.println(+lim+" "+sdir);
            addStep(lim, sdir);

            if(i != r-1)
                addStep(1, "D");
        }
        
        for(int i=0; i<r-1; i++){
            String sdir = ((i+r)%2 == 1)?"UDL":"UDR";
            
            long lim = Math.min(k, 3*(c-1));
            
            addStep(lim/3, sdir);
            addStep(1, sdir.substring(0, (int)(lim%3)));
            addStep(1, "U");
        }
        
        addStep(k, "L");
    }
}