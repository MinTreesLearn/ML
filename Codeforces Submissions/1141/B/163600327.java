import java.util.*;
import java.io.*;

public class MaximalContinuousRest {
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());
        int[] hours = new int[size * 2];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < size; i++){
            int currNum = Integer.parseInt(st.nextToken());
            hours[i] = currNum;
            hours[i + size] = currNum;
        }
        ArrayList<Integer> sizes = new ArrayList<>();
        int counter = 0;
        for(int i = 0; i < size * 2; i++){
            if(hours[i] == 0){
                sizes.add(counter);
                counter = 0;
            }
            else if(hours[i] == 1){
                counter++;
            }
        }
        int max = sizes.get(0);
        for(int i = 0; i < sizes.size(); i++){
            if(sizes.get(i) > max){
                max = sizes.get(i);
            }
        }
        System.out.println(max);
    }
}
