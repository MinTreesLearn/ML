import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class FastFoodRestaurent {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for ( int i = 0; i < t; i++){
            ArrayList <Integer> list = new ArrayList<>(1);
            for ( int j = 0; j < 3; j++){
                list.add(in.nextInt());
            }
            Collections.sort(list);
            int sum = 0;
            if(list.get(0) > 0){
                list.set(0,list.get(0)-1);
                sum+=1;
            }
            if(list.get(1) > 0){
                list.set(1,list.get(1)-1);
                sum+=1;
            }
            if(list.get(2)>0){
                list.set(2,list.get(2)-1);
                sum+=1;
            }
            if(list.get(0) > 0 && list.get(2) > 0){
                list.set(2,list.get(2)-1);
                list.set(0,list.get(0)-1);
                sum+=1;
            }
            if(list.get(2) > 0 && list.get(1) > 0){
                list.set(2, list.get(2)-1);
                list.set(1,list.get(1)-1);
                sum+=1;
            }
            if(list.get(0) > 0 && list.get(1) > 0){
                list.set(0, list.get(0)-1);
                list.set(1, list.get(1)-1);
                sum+=1;
            }
            if(list.get(0) > 0 && list.get(1) > 0 && list.get(2) > 0){
                sum+=1;
            }
            System.out.println(sum);
        }
    }
}