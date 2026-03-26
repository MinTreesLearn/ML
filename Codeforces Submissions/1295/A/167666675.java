import java.util.*;
public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i = 0 ; i < n ; i++){
            String tar = "";
            int q = in.nextInt();
            while (q!=0){
                if(q%2==0){
                    tar+="1";
                    q-=2;
                }else{
                    tar+="7";
                    q-=3;
                }
            }
            System.out.println(tar);
        }
    }


}
