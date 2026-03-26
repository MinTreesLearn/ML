import java.util.*;

public class Solution {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        
        int index = scan.nextInt();
        String data = scan.next();
        
        int[] nilai = new int[2];
        
        for(int i=0;i<index;i++){
            if(data.charAt(i)=='L'){
                nilai[0] = nilai[0] - 1;
            }
            else{
                nilai[1] = nilai[1] + 1;
            }
        }
        
        int jumlah = 0;
        
        for(int i=nilai[0];i<=nilai[1];i++){
            jumlah++;
        }
        
        System.out.println(jumlah);
    }
}

   	 		 	 	 								   	 		 	 	