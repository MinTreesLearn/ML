import java.util.*;public class J{public static void main(String[]h){Scanner s=new Scanner(System.in);int x=s.nextInt();for(int i=0;i<x;i++){int a=s.nextInt(),b=s.nextInt(),c=s.nextInt(),n=s.nextInt();int m=Math.max(a,Math.max(b,c)),z=(n-(m*3-(a+b+c)));if(z%3==0&&z>-1)
System.out.println("YES");else
System.out.println("NO");}}}