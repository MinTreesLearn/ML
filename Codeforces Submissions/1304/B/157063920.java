import java.io.*;
import java.util.*;
import java.lang.*;
public class Codeforces {
   public static void main(String[] args)
    {
		Scanner input= new Scanner(System.in);
		int n=input.nextInt();
		int m=input.nextInt();
		int palincnt=0;
		 HashMap<String,Integer> map = new HashMap<>();
		 String[] strings=new String[n];
		 ArrayList<String> anslist=new ArrayList<>();
		
		for(int i=0;i<n;i++)
		{
		  strings[i]=input.next();
		  map.put(strings[i],map.getOrDefault(strings,0)+1);
		}
		boolean ok=false;
	        for(int i=0;i<n;i++)
	        {
	       
	          if(map.containsKey(reverse(strings[i])))
	          {
	          if(strings[i].equals(reverse(strings[i])))
	          {
	             if((map.get(strings[i])%2!=0)&&(ok==false)&& map.get(strings[i])>0)
	              {
	               int len=map.get(strings[i])/2;
	                String a=strings[i].repeat(len);
	                if(len!=0){
	                anslist.add(0,a);
	                anslist.add(a);
	                }
	                ok=true;
	                int pos=anslist.size()/2;
	                anslist.add(pos,strings[i]);
	                map.put(strings[i],0);
	              }
	              else
	              {
	              int len=map.get(strings[i])/2;
	              String a=strings[i].repeat(len);
	              if(len!=0){
	                anslist.add(0,a);
	                anslist.add(a);
	                map.put(strings[i],0);
	                }
	              }
	          }
	         else if((map.get(strings[i])!=0)&&(map.get(reverse(strings[i]))!=0)){
	           int a=Math.min(map.get(strings[i]),map.get(reverse(strings[i])));
	           String aa=strings[i].repeat(a);
	           String bb=reverse(strings[i]).repeat(a);
	           anslist.add(0,aa);
	           anslist.add(bb);
	           map.put(strings[i],0);
	           map.put(reverse(strings[i]),0);
	           }
	          }
	        }
	        int length=anslist.size();
	        System.out.println(length*m);
	        for(int i=0;i<length;i++)
	        {
	        System.out.print(anslist.get(i));
	        }
	        System.out.println("");
		
    }
    public static String reverse(String input)
    {
        byte[] strAsByteArray = input.getBytes();
        byte[] result = new byte[strAsByteArray.length];
        for (int i = 0; i < strAsByteArray.length; i++)
            result[i] = strAsByteArray[strAsByteArray.length - i - 1];
        return (new String(result));
    }
}


