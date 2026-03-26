import java.io.*;
import java.util.*;
 
public class Solution{
    public static void main(String arg[])throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n,q;
        String str[]=br.readLine().split(" ");
        n=Integer.parseInt(str[0]);
        q=Integer.parseInt(str[1]);
        int flippedCells[][] = new int[q][2];
        boolean maze[][] = new boolean[2][n];
        //maze - valcony ==true
        //maze - ground ==false
        for(int i=0;i<q;i++)
            flippedCells[i] = Arrays.stream(br.readLine().
                                split("\\s+")).mapToInt(Integer::valueOf).toArray();

int count=0;
        for(int i=0;i<q;i++)
        {
            int x=flippedCells[i][0]-1,y=flippedCells[i][1]-1;
           if(!maze[x][y]){
               if(maze[x^1][y])count++;
               if(y-1>=0 && maze[x^1][y-1])count++;
               if(y+1<n &&maze[x^1][y+1])count++;
           }else{
               if(maze[x^1][y])count--;
               if(y-1>=0 && maze[x^1][y-1])count--;
               if(y+1<n && maze[x^1][y+1])count--;
           }
           maze[x][y]^=true;
            if(count==0)
                System.out.println("Yes");
            else
                System.out.println("No");
            //break;
        }
    }
}