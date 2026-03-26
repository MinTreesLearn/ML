
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Codecraft20D
{
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }

    //  long start = System.currentTimeMillis();
//  long end = System.currentTimeMillis();
//  System.out.println((end - start) + "ms");
    static char[][] answer;
    static Pair[][] grid;
    static boolean[][] visited;
    static int n;
    public static void main(String[] args) throws IOException {
        FastReader s=new FastReader();
        n = s.nextInt();
        answer = new char[n][n];
        grid = new Pair[n][n];
        visited = new boolean[n][n];
        ArrayList<Pair> x_list = new ArrayList<>();
        ArrayList<Pair> minusone_list = new ArrayList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int a = s.nextInt();
                int b = s.nextInt();
                Pair p ;
                if(a==-1 || b==-1){
                    p = new Pair(-1,-1);
                    minusone_list.add(new Pair(i,j));
                }
                else {
                    p = new Pair(a-1,b-1);
                    if(i==a-1 && j==b-1){
                        answer[i][j] = 'X';
                        x_list.add(new Pair(i,j));
                    }
                }
                grid[i][j] = p;
            }
        }

        //now dfs on X for every x
        for(Pair p:x_list){
            int x =p.x;
            int y =p.y;
            visited[x][y] = true;
            x_dfs(x,y,p);
        }
        x_list.clear();
        //now we have left with only -1s
//        debug(visited);
        for(Pair p:minusone_list){
            int x =p.x;
            int y = p.y;
            Pair parent = new Pair(-1,-1);
            if(!visited[x][y]){
//                System.out.println(x+" "+y);
                // if this x has no adjacent -1 print -1
                int x_left = x-1;
                int x_right = x+1;
                int y_left = y-1;
                int y_right = y+1;
                if(x_left>=0 && isEqual(parent,grid[x-1][y])){
                    answer[x][y] = 'U';
                    visited[x][y] = true;
                    minus_dfs(x,y);
                }
                else if(x_right<n && isEqual(parent,grid[x+1][y])){
                    answer[x][y] ='D';
                    visited[x][y] = true;
                    minus_dfs(x,y);
                }
                else if(y_left>=0 && isEqual(parent,grid[x][y-1])){
                    answer[x][y] ='L';
                    visited[x][y] = true;
                    minus_dfs(x,y);
                }
                else if(y_right<n && isEqual(parent,grid[x][y+1])){
                    answer[x][y] ='R';
                    visited[x][y] = true;
                    minus_dfs(x,y);
                }
                else {
                    System.out.println("INVALID");
//                    debug(answer);
                    return;
                }
//                minusone_list.remove(p);
            }
//            minusone_list.clear();

        }
        minusone_list.clear();
        //now check if every grid is filled
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(answer[i][j]==(char)0){
                    System.out.println("INVALID");
                    return;
                }
            }
        }
        //print valid
        System.out.println("VALID");
        debug(answer);


    }
    public static void x_dfs(int x,int y,Pair parent){
//        int x_left = x-1;
//        int x_right = x+1;
//        int y_left = y-1;
//        int y_right = y+1;

        if(x-1>=0 && isEqual(parent,grid[x-1][y]) && !visited[x-1][y]){
            visited[x-1][y] = true;
            answer[x-1][y] = 'D';
            x_dfs(x-1,y,parent);
        }
        if(x+1<n && isEqual(parent,grid[x+1][y]) && !visited[x+1][y]){
            visited[x+1][y] = true;
            answer[x+1][y] = 'U';
            x_dfs(x+1,y,parent);
        }
        if(y-1>=0 && isEqual(parent,grid[x][y-1]) && !visited[x][y-1]){
            visited[x][y-1] = true;
            answer[x][y-1] ='R';
            x_dfs(x,y-1,parent);
        }
        if(y+1<n && isEqual(parent,grid[x][y+1]) && !visited[x][y+1]){
            visited[x][y+1] = true;
            answer[x][y+1] ='L';
            x_dfs(x,y+1,parent);
        }

    }
    static Pair parent = new Pair(-1,-1);
    public static void minus_dfs(int x,int y){
        //two conditions if it has  adjacent -1 other than prev then continue
        //else this forms a cycle


            if(x-1>=0 && isEqual(parent,grid[x-1][y]) && !visited[x-1][y]){
                    answer[x-1][y] ='D';
                    visited[x-1][y] = true;
                    minus_dfs(x-1,y);
            }
            if(x+1<n && isEqual(parent,grid[x+1][y]) && !visited[x+1][y]){
                    answer[x+1][y] ='U';
                    visited[x+1][y] = true;
                    minus_dfs(x+1,y);
            }
            if(y-1>=0 && isEqual(parent,grid[x][y-1]) && !visited[x][y-1]){
                    answer[x][y-1]='R';
                    visited[x][y-1] = true;
                    minus_dfs(x,y-1);
            }
            if(y+1<n && isEqual(parent,grid[x][y+1]) && !visited[x][y+1]){
                    answer[x][y+1] ='L';
                    visited[x][y+1] = true;
                    minus_dfs(x,y+1);
            }
    }


    static class Pair{
        int x;
        int y;
        Pair(int x,int y){
            this.x = x;
            this.y = y;
        }

    }

    static boolean isEqual(Pair p,Pair q){
        if(q.x==p.x && q.y == p.y){
            return true;
        }
        return false;
    }

    public static void print(String str,int val){
        System.out.println(str+"  "+val);
    }


    public static void debug(char[][] arr) throws IOException {
        OutputStream out = new BufferedOutputStream( System.out );
        int len = arr.length;
        int len2 = arr[0].length;
        for(int i=0;i<len;i++){
            for(int j=0;j<len2;j++){
               out.write((arr[i][j]+"").getBytes());
            }
            out.write("\n".getBytes());
            out.flush();
        }

        out.close();
    }

    public static void debug(long[][] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(Arrays.toString(arr[i]));
        }
    }
    public static void debug(int[][] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(Arrays.toString(arr[i]));
        }
    }
    public static void debug(boolean[][] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(Arrays.toString(arr[i]));
        }
    }

    public static void print(int[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }
    public static void print(String[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }
    public static void print(long[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }


//    OutputStream out = new BufferedOutputStream( System.out );
//        for(int i=1;i<n;i++){
//    out.write((max_divisor[i]+" ").getBytes());
//}
//        out.flush();



}
