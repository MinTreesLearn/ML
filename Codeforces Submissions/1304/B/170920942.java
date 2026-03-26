

import java.util.HashSet;
import java.util.Scanner;

public class LongestPalindrome {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String arr[] = new String [n];
        for(int i=0;i<n;i++){
            arr[i]= sc.next();
        }
        HashSet<String>s1 = new HashSet<>();
        HashSet<String>s2 = new HashSet<>();
        for(int i=0;i<n;i++){
            String rev = reverse(arr[i]);
            if(!s1.contains(arr[i])&&!s1.contains(rev)){
                s1.add(arr[i]);
            }else if(s1.contains(rev)&&!s2.contains(arr[i])){
                s2.add(arr[i]);
            }
        }

        String fs ="";
        String ls ="";
        for(String key:s2){
           String rev = reverse(key);
           if(s1.contains(rev)){
               fs+=rev;
               ls=key+ls;
           }
        }

        String mid ="";
        for(String s:s1){
            if(!s2.contains(s))
            if(isPalindrome(s)){
                mid = s;
                break;
            }
        }
        String ans = fs+mid+ls;
        System.out.println(ans.length());
        System.out.println(ans);
    }

    private static boolean isPalindrome(String s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    private static String reverse(String s) {
        String ans = "";
        for(int i=s.length()-1;i>=0;i--){
            ans+=s.charAt(i);
        }
        return ans;
    }
}
