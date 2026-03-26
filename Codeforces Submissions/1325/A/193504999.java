import java.util.*;
public class Main {
    public static void display(int[] x){
        for(int i = 0; i < x.length; i++){
            System.out.println(1 + " " + (x[i] - 1));
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        int[] x = new int[num];
        for(int i = 0; i < x.length; i++){
            x[i] = in.nextInt();
        }
        display(x);
    }
}
	 	 		 	  	    		   			 		 		