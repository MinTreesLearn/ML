import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();//test cases
        ArrayList<int[]> list = new ArrayList<>();
        for(int i =0 ; i < n ;i++){
            int numbers= inp.nextInt();
            int[] a = new int[numbers];
            for(int j = 0 ; j<numbers;j++){
                a[j]= inp.nextInt();
            }
            list.add(a);
        }
        for(int i=0; i<list.size();i++){
            ArrayList<Integer> ans = calc(list.get(i));
            if(ans.size()==0){
                System.out.println(-1);
            }else{
                System.out.println(ans.size());
                for(int x : ans){
                    System.out.print(x + " ");

                }
                System.out.println();
            }
        }


        inp.close();
    }
    public static ArrayList<Integer> calc(int[] a){
        ArrayList<Integer> evens = new ArrayList<>();
        for(int i = 0 ; i<a.length ; i++){
            if(a[i] %2==0){
                evens.add(i+1);
                return evens;
            }else {
                for(int j=i+1; j<a.length; j++){
                    if(a[j] % 2==1){
                        evens.add(i+1);
                        evens.add(j+1);
                        return evens;
                    }
                }
            }
        }
        return new ArrayList<>();
    }


}
