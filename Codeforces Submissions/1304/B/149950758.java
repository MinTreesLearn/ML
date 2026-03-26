import java.util.*;
public class HelloWorld{

     public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int len=sc.nextInt();
        String ans="";
        String s1="",s2="";
        String pal="";
        HashSet<String>set=new HashSet<>();
        while(n-->0){
            String str=sc.next();
            String rev=reverse(str);
            if(str.equals(rev)){
                pal=str;
            }else if(set.contains(rev)){
                set.remove(rev);
                s1=s1+rev;
                s2=str+s2;
            }else{
                set.add(str);
            }
            
            
        }
        ans=s1+pal+s2;
        System.out.println(ans.length() + "\n" + ans);
     }
     public static String reverse(String s) {
		String str = "";
		for (int i=s.length()-1;i>=0;i-- ) 
			str += s.charAt(i)+"";
		return str;
	}
}