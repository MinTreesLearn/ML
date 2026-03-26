import java.util.*;

public final class C_Unusual_Competitions{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        sc.nextLine();
        String str = sc.nextLine();
        sc.close();
        int count = 0;
        for(char c : str.toCharArray()){
            if(c == '(') count++;
            else count--;
        }
        if(count != 0){
            System.out.println(-1);
        }
        else{
            int j = 0, res = 0;
            while(j < len){
                char c = str.charAt(j);
                if(c == '(') count++;
                else count--;
                int temp = 0;
                if(count < 0){
                    temp++;
                    j++;
                    while(j < len && count < 0){
                        temp++;
                        char ch = str.charAt(j++);
                        if(ch == '(') count++;
                        else count--;
                    }
                }
                else{
                    j++;
                }
                res += temp;
            }
            System.out.println(res);
        }
    }
}