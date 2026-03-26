import java.util.*;
public class YetAnotherPalindromeProblem {
    public static void main(String args[]) {
        Scanner sr = new Scanner(System.in);
        int t = sr.nextInt();
        HashMap<Integer, Boolean> foundNums = new HashMap<Integer, Boolean>();
        int prevNum;
        int length;
        int currentNum;
        boolean check;
        int count;
        for (int u=0;u<t;u++){
            length=sr.nextInt();
            currentNum=sr.nextInt();
            prevNum=currentNum;
            check=false;
            count=0;
            foundNums.put(currentNum,true);
            for (int i=1;i<length;i++){
                currentNum=sr.nextInt();
                if(foundNums.get(currentNum)!=null){
                    if(currentNum==prevNum){
                        count++;
                        if(count==2){
                            check=true;
                        }
                    }
                    else {
                        check=true;
                    }
                }
                else {
                    count=0;
                }
                prevNum=currentNum;
                foundNums.put(currentNum, true);
            }
            if(check){
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
            foundNums.clear();
        }
    }
}