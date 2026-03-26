import java.io.*;
 
 
 
 
import java.util.*;
/*

 
*/
 
 
 
 
 
public class A {
	static FastReader sc=null;
	static int from[];
	
	public static void main(String[] args) {
		sc=new FastReader();
		int n=sc.nextInt();
		Node nodes[]=new Node[n];
		for(int i=0;i<n;i++)nodes[i]=new Node(i);
		for(int i=0;i+1<n;i++) {
			int v=sc.nextInt()-1,w=sc.nextInt()-1;
			nodes[v].adj.add(nodes[w]);
			nodes[w].adj.add(nodes[v]);
		}
		from=new int[n];
		Node a=bfs(nodes,nodes[0]);
		Node b=bfs(nodes,a);
		long ans=b.dist;
		ArrayList<Node> mul=new ArrayList<>();
		mul.add(b);
		Node temp=b;
		while(b!=a) {
			b=nodes[from[b.id]];
			mul.add(b);
		}
		Node c=bfs(nodes,mul,a,b);
		ans+=c.dist;
		System.out.println(ans);
		System.out.println((a.id+1)+" "+(temp.id+1)+" "+(c.id+1));
		
		
		
			
		
		
		
		
	}
	static class Node{
		int id,dist;
		ArrayList<Node> adj=new ArrayList<>();
		Node(int id){
			this.id=id;
		}
	}
	static Node bfs(Node nodes[],Node s) {
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		for(Node nn:nodes)nn.dist=-1;
		s.dist=0;
		bfs.add(s);
		Node far=null;
		while(!bfs.isEmpty()) {
			Node q=bfs.remove();
			far=q;
			for(Node nn:q.adj) {
				if(nn.dist==-1) {
					from[nn.id]=q.id;
					nn.dist=q.dist+1;
					bfs.add(nn);
				}
			}
		}
		return far;
	}
	static Node bfs(Node nodes[],ArrayList<Node> mul,Node a,Node b) {
		ArrayDeque<Node> bfs=new ArrayDeque<>();
		for(Node nn:nodes)nn.dist=-1;
		for(Node nn:mul) {
			bfs.add(nn);
			nn.dist=0;
		}
		Node far=null;
		while(!bfs.isEmpty()) {
			Node q=bfs.remove();
			if(q!=a && q!=b)far=q;
			for(Node nn:q.adj) {
				if(nn.dist==-1) {
					from[nn.id]=q.id;
					nn.dist=q.dist+1;
					bfs.add(nn);
				}
			}
		}
		return far;
	}
	
	
	
	
	
	
	
	
	
 
	
	static int[] reverse(int a[]) {
		ArrayList<Integer> al=new ArrayList<>();
		for(int i:a)al.add(i);
		Collections.sort(al,Collections.reverseOrder());
		for(int i=0;i<a.length;i++)a[i]=al.get(i);
		return a;
	}
	static int gcd(int a,int b) {
		if(b==0)return a;
		else return gcd(b,a%b);
	}
	static int[] ruffleSort(int a[]) {
		ArrayList<Integer> al=new ArrayList<>();
		for(int i:a)al.add(i);
		Collections.sort(al);
		for(int i=0;i<a.length;i++)a[i]=al.get(i);
		return a;
	}
	
	
	
	static void print(int a[]) {
		for(int e:a) {
			System.out.print(e+" ");
		}
		System.out.println();
	}
	static void print(long a[]) {
		for(long e:a) {
			System.out.print(e+" ");
		}
		System.out.println();
	}
	
	
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
        int[] readArray(int n) {
    		int a[]=new int [n];
    		for(int i=0;i<n;i++) {
    			a[i]=sc.nextInt();
    		}
    		return a;
    	}
    } 
}
