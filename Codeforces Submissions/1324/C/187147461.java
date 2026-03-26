

import java.util.*;
import java.lang.*;
import java.io.*;
public class CF_018 {
    static PrintWriter out;
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
            out=new PrintWriter(System.out);
        }
        String next(){
            while(st==null || !st.hasMoreElements()){
                try{
                    st= new StringTokenizer(br.readLine());
                }
                catch (IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str = "";
            try{
                str=br.readLine();
            }
            catch(IOException e){
                e.printStackTrace();
            }
            return str;
        }
    }

    public static ArrayList<Integer> allFactors(int n) {
        ArrayList<Integer> list = new ArrayList<>() ;

        for(int i = 1; i*i <= n ;i++) {
            if( n % i == 0) {
                if(i*i == n) 
                    list.add(i) ;
                
                else{
                    list.add(i) ;
                    list.add(n/i) ;

                }
            }
        }

        return list ;


    }


    public static void main (String[] args) throws java.lang.Exception
    {
        FastReader scn = new FastReader() ;

        ArrayList<Integer> list = new ArrayList<>() ;
        

        int t = scn.nextInt() ;

        while(t-- > 0)
        {
            String s = scn.next() ;

            list.add(0) ;

            for(int i =0 ; i < s.length() ; i++ )
            {
                if(s.charAt(i)=='R')
                {
                    list.add(i+1) ;
                }
            }

            list.add(s.length()+1 ) ;

            int max = list.get(1) - list.get(0);

            for(int i = 2; i < list.size() ;i++ )
            {
                if(list.get(i)-list.get(i-1)> max )
                {
                    max = list.get(i)-list.get(i-1) ;
                }
            }

            out.println(max) ;
//out.println(list) ;

            list.clear();
          


        }

        out.flush() ;

    }


}