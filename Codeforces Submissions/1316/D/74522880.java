import java.io.*;
import java.util.*;

public class HelloWorld{

    static class Point{
        int x, y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
        public boolean equal(Point other){
            return x == other.x && y == other.y;
        }
    }
    
    private static void notpossible(){
        System.out.println("INVALID");
        System.exit(0);
    }

    public static void main(String []args)throws IOException{
        
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(re.readLine()), cx[] = {-1, +1, 0, 0}, cy[] = {0, 0, +1, -1};
        
        char output[][] = new char[n][n], dir[] = {'U', 'D', 'R', 'L'}, revdir[] = {'D', 'U', 'L', 'R'};
        Point fin[][] = new Point[n][n];
        
        Queue<Point> q = new LinkedList<>();
        
        for(int i=0; i<n; i++){
            StringTokenizer tk = new StringTokenizer(re.readLine());
            for(int j=0; j<n; j++){
                output[i][j] = ' ';
                
                int x = Integer.parseInt(tk.nextToken()), y = Integer.parseInt(tk.nextToken());
                
                if(x == -1 && y == -1)
                    fin[i][j] = new Point(-1, -1);
                else
                    fin[i][j] = new Point(x-1, y-1);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                int fx = fin[i][j].x, fy = fin[i][j].y;
                
                if(fx == -1 && fy == -1){
                    for(int k=0; k<4; k++){
                        int nx = i+cx[k], ny = j+cy[k];
                        
                        if(nx >= 0 && nx < n && ny >= 0 && ny < n && fin[nx][ny].equal(fin[i][j])){
                            output[i][j] = dir[k];
                            q.add(new Point(i, j));
                        }
                    }
                    
                    if(output[i][j] == ' ')
                        notpossible();
                }
                else if(i == fx && j == fy){
                    output[i][j] = 'X';
                    q.add(new Point(i, j));
                }
            }
        }
        
        /*for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                System.out.print(output[i][j]);
            System.out.println();
        }
        
        System.out.println();*/
        
        while(!q.isEmpty()){
            Point curr = q.poll();
            
            int x = curr.x, y = curr.y;
            //System.out.println(+x+" "+y);
            
            /*if(output[x][y] == '\0'){
                if(fin[x][y].x == x && fin[x][y].y == y)
                    output[x][y] = 'X';
                else{
                    
                    for(int i=0; i<4; i++){
                        int nx = x + cx[i], ny = y + cy[i];
                        
                        if(nx >= 0 && nx < n && ny >= 0 && ny < n && fin[nx][ny].equal(fin[x][y])){
                            output[x][y] = dir[i];
                            break;
                        }
                    }
                    
                    /*if(fin[x][y].x == -1 && fin[x][y].y == -1 && output[x][y] == '\0'){
                        for(int i=0; i<4; i++){
                            int nx = x + cx[i], ny = y + cy[i];
                            
                            if(nx >= 0 && nx < n && ny >= 0 && ny < n && fin[nx][ny].equal(fin[x][y])){
                                output[x][y] = dir[i];
                                break;
                            }
                        }
                    }
                    
                    if(output[x][y] == '\0')
                        notpossible();
                }
            }*/
            
            for(int i=0; i<4; i++){
                int nx = x + cx[i], ny = y + cy[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && fin[nx][ny].equal(fin[x][y]) && output[nx][ny] == ' '){
                    output[nx][ny] = revdir[i];
                    q.add(new Point(nx, ny));
                }
            }
        }
        
        /*for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                System.out.print(output[i][j]);
            System.out.println();
        }*/
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(output[i][j] == ' ')
                    notpossible();
            }
        }
        
        PrintWriter pw = new PrintWriter(System.out);
        
        pw.println("VALID");
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                pw.print(output[i][j]);
            pw.println();
        }
        
        pw.flush();
        pw.close();
    }
}