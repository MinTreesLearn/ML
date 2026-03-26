import java.util.*;
 
public class Main {
 
    public static void main(String[] args) {
 
Scanner s=new Scanner(System.in);
int n=s.nextInt();
int m=s.nextInt();
s.nextLine();
String s1=s.nextLine();
String[] str=s1.split(" ");
String s2=s.nextLine();
String[] str1=s2.split(" ");
int q=s.nextInt();
for(int i=0;i<q;i++)
{
    int x=s.nextInt();
    x--;
    System.out.println(str[x%n]+str1[x%m]);
}
 
 
    }
}