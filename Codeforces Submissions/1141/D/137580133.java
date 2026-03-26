import java.util.*;
import java.lang.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
public class Pupil
{
   
	
    static FastReader sc = new FastReader();

	public static void main (String[] args) throws java.lang.Exception
	{
	           	
	// your code goes here
             int t=1;
             while(t>0){
            	 int n=sc.nextInt();
            	 String s1=sc.next();
            	 String s2=sc.next();
         
            	 PriorityQueue<pair>pr1=new PriorityQueue<pair>(Collections.reverseOrder());
            	 PriorityQueue<pair>pr2=new PriorityQueue<pair>(  Collections.reverseOrder());
            	 for(int i=0;i<s1.length();i++)
            	 {
            		  char c=s1.charAt(i);
            		  if(c=='?')
            		  {
            			  pr1.add(new pair(200,i));
            		  }
            		  else {
            			  pr1.add(new pair((int)c,i));
            		  }
            	 }
             	 for(int i=0;i<s2.length();i++)
            	 {
            		  char c=s2.charAt(i);
            		  if(c=='?')
            		  {
            			  pr2.add(new pair(200,i));
            		  }
            		  else {
            			  pr2.add(new pair((int)c,i));
            		  }
            	 }
            // 	 while(!pr1.isEmpty())
            // 	 {
            // 	     pair j=pr1.poll();
            // 	     	 System.out.println(j.value+" "+j.index);
            // 	 }
            
            

             	ArrayList<pair>waste1=new ArrayList<pair>();
           	 ArrayList<pair>waste2=new ArrayList<pair>();
           	 ArrayList<pair>ans=new ArrayList<pair>(); 
           	ArrayList<pair>question1=new ArrayList<pair>();
           	ArrayList<pair>question2=new ArrayList<pair>();
           	
           	
           	
           	 
           	while(!pr1.isEmpty() && !pr2.isEmpty())
           	{
           		pair val1=pr1.poll();
           		pair val2=pr2.poll();
           		int check1=val1.value;
           		int check2=val2.value;
           		
           	if(check1==200 || check2==200)
           		{
           		if(check1==200 && check2==200)
           		{
           			question1.add(new pair(check1,val1.index));	
           			question2.add(new pair(check2,val2.index));
           		}
           			
           	else if(check1==200)
           			{
           				question1.add(new pair(check1,val1.index));
           			 pr2.add(new pair(check2,val2.index));
           			}
           			else {
           				question2.add(new pair(check2,val2.index));
           			  pr1.add(new pair(check1,val1.index));
           			}
           		}
           	else if(check1==check2 && check1!=200)
           		{
           			ans.add(new pair(val1.index+1,val2.index+1));
           		}
           		else {
           			if(check1>check2)
           			{
           			    waste2.add(new pair(check2,val2.index));
           			    pr1.add(new pair(check1,val1.index));
           			}
           			else {
           			 waste1.add(new pair(check1,val1.index));	
           			 pr2.add(new pair(check2,val2.index));
           			}
           		}
           				
           	}
        
           	
           	if(!pr1.isEmpty())
           	{
           	       while(!pr1.isEmpty())
           	       {
           	    	   pair g=pr1.poll();
           	    	   if(g.value==200)
           	    	   {
           	    		question1.add(new pair(g.value,g.index));	
           	    	   }
           	    	   else {
           	    		   waste1.add(new pair(g.value,g.index));
           	    	   }
           	       }
           	}
           	else if(!pr2.isEmpty())
           	{
           	       while(!pr2.isEmpty())
           	       {
           	    	   pair g=pr2.poll();
           	    	   if(g.value==200)
           	    	   {
           	    		question2.add(new pair(g.value,g.index));	
           	    	   }
           	    	   else {
           	    		   waste2.add(new pair(g.value,g.index));
           	    	   }
           	       }
           	}
           	else {}
           	
    //   for(int i=0;i<waste1.size();i++)
    //   {
    //       pair waste=waste1.get(i);
    //       System.out.println(waste.value+" "+waste.index);
    //   }
    //   System.out.println();
       
       
    //   for(int i=0;i<waste2.size();i++)
    //   {
    //       pair waste=waste2.get(i);
    //       System.out.println(waste.value+" "+waste.index);
    //   }
    //   System.out.println();
       
       
    //   for(int i=0;i<question1.size();i++)
    //   {
    //       pair waste=question1.get(i);
    //       System.out.println(waste.value+" "+waste.index);
    //   }
    //   System.out.println();
       
    //   for(int i=0;i<question2.size();i++)
    //   {
    //       pair waste=question2.get(i);
    //       System.out.println(waste.value+" "+waste.index);
    //   }
    //   System.out.println();
           	 int chick1=0;
           	 for(int i=0;i<Math.min(waste1.size(), question2.size());i++)
           	 {
           		pair waste=waste1.get(i);
           		pair question=question2.get(i);
           		ans.add(new pair(waste.index+1,question.index+1));
           		chick1=i+1;
           	 }
                      	 
        	int chick2=0;
           	 for(int i=0;i<Math.min(waste2.size(), question1.size());i++)
           	 {
           		pair waste=waste2.get(i);
           		pair question=question1.get(i);
           		ans.add(new pair(question.index+1,waste.index+1));
           		chick2=i+1;
           	 }
           	 
           	 if(question1.size()>waste2.size() && question2.size()>waste1.size())
           	 {
           	     int jinx1=question1.size()-chick1;
           	     int jinx2=question2.size()-chick2;
           	     for(int i=0;i<Math.min(jinx1,jinx2);i++)
           	     {
           	         pair u=question1.get(chick1);
           	                 pair u1=question2.get(chick2);
           	         ans.add(new pair(u.index+1,u1.index+1));
           	         chick1++;
           	   
           	     
           	         chick2++;
           	         
           	     }
           	 }
           	
                  

System.out.println(ans.size());
for(int i=0;i<ans.size();i++)
{
	pair obaidbhadwa=ans.get(i);
	
	System.out.println(obaidbhadwa.value+" "+obaidbhadwa.index);
}






              t--;
                }

   

 
 
         
		}
	
	
	
	
	//	FAST I/O
	static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
	}

public static boolean two(int n)//power of two
{
if((n&(n-1))==0)
{
return true;
}
else{
return false;
}
	
}	





public static boolean isPrime(long n){
		    
		    for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
 
        return true;
		}


public static int digit(int n)
{
    int n1=(int)Math.floor((int)Math.log10(n)) + 1;
    return n1;
}

 }
 
 //CAAL THE BELOW FUNCTION IF PARING PRIORITY IS NEEDED //
 
//  PriorityQueue<pair> pq = new PriorityQueue<>(); **********declare the syntax in the main function******
// pq.add(1,2)///////
 
 class pair implements Comparable<pair> {
 	int value, index;
 
 	pair(int v, int i) { index = i; value = v; }
 
 	@Override
 	public int compareTo(pair o) { return o.value - value; }
 }
 

// User defined Pair class
// class Pair {
//    int x;
//     int y;
//  
//     // Constructor
// public Pair(int x, int y)
//     {
//         this.x = x;
//         this.y = y;
//     }
// }


        //     Arrays.sort(arr, new Comparator<Pair>() {
        //     @Override public int compare(Pair p1, Pair p2)
        //     {
        //         return p1.x - p2.x;
        //     }
        // });




// class Pair {
 //       int height, id;
// 
//        public Pair(int i, int s) {
//            this.height = s;
//            this.id = i;
//        }
//    }
        



 
 
 //Arrays.sort(trips, (a, b) -> Integer.compare(a[1], b[1]));
 
// 		ArrayList<ArrayList<Integer>> connections = new ArrayList<ArrayList<Integer>>();
// 		for(int i = 0; i<n;i++)
// 			connections.add(new ArrayList<Integer>());