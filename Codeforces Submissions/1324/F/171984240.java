import java.util.*;
import java.io.*;

public class maximumWhiteSubtreeCF {

    private static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;
		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}
		public Kattio(String problemName) throws IOException {
			super(problemName + ".out");
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}
		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
	}

    public static Hashtable <Integer, ArrayList<Integer>> tree;
    public static int [] dpDown;
    public static int [] dpUp;
    public static void main (String[]args) throws IOException {
        Kattio scan = new Kattio ();

        int nodeNumber = scan.nextInt();
        int edgeNumber = nodeNumber - 1;

        int [] nodeColors = new int [nodeNumber];

        for (int i = 0; i < nodeNumber; i++) {
            nodeColors[i] = scan.nextInt();
        }

        tree = new Hashtable <Integer, ArrayList<Integer>>();

        for (int i = 0; i < nodeNumber; i++) {
            tree.put(i, new ArrayList<Integer>());
        }

        for (int i = 0; i < edgeNumber; i++) {
            int firstNode = scan.nextInt() - 1;
            int secondNode = scan.nextInt() - 1;

            ArrayList<Integer> temp = tree.get(firstNode);
            temp.add(secondNode);
            tree.put(firstNode, temp);

            ArrayList<Integer> tempTwo = tree.get(secondNode);
            tempTwo.add(firstNode);
            tree.put(secondNode, tempTwo);
        }

        dpDown = new int [nodeNumber];

        for (int i = 0; i < nodeNumber; i++) {
            
            // Current node is white
            if (nodeColors[i] == 1) {
                dpDown[i] = 1;
            } 
            // Current node is black
            else {
                dpDown[i] = -1;
            }
        }

        dpDownDFS(0, -1);

        dpUp = new int [nodeNumber];
        dpUp[0] = 0;

        for (int i = 0; i < tree.get(0).size(); i++) {
            dpUpDFS(tree.get(0).get(i), 0);
        }

        for (int i = 0; i < nodeNumber; i++) {
            int curAnswer = 0;

            if (dpDown[i] == -1) {
                curAnswer = -1;

                if (dpUp[i] > 0) {
                    curAnswer += dpUp[i];
                }
            }
            else {
                curAnswer = dpDown[i];

                if (dpUp[i] > 0) {
                    curAnswer += dpUp[i];
                }
            }

            System.out.print(curAnswer + " ");
        }
    }

    public static void dpUpDFS (int currentNode, int parentNode) {
        int curAnswer = 0;
        
        if (dpUp[parentNode] > 0) {
            curAnswer = dpUp[parentNode];
        }

        if (dpDown[currentNode] == -1) {
            curAnswer += dpDown[parentNode];
        }
        else {
            if (dpDown[parentNode] - dpDown[currentNode] > 0) {
                curAnswer += dpDown[parentNode] - dpDown[currentNode];
            }
            else {
                curAnswer -= (dpDown[currentNode] - dpDown[parentNode]);
            }
        }
        
        dpUp[currentNode] = curAnswer;

        ArrayList<Integer> temp = tree.get(currentNode);

        for (int i = 0; i < temp.size(); i++) {
            int childNode = temp.get(i);
            if (childNode == parentNode) {
                continue;
            }

            dpUpDFS(childNode, currentNode);
        }
    }

    public static void dpDownDFS (int currentNode, int parentNode) {
        ArrayList<Integer> temp = tree.get(currentNode);

        for (int i = 0; i < temp.size(); i++) {
            int childNode = temp.get(i);

            if (childNode == parentNode) {
                continue;
            }

            dpDownDFS(childNode, currentNode);
            if (dpDown[childNode] > 0) {
                dpDown[currentNode] += dpDown[childNode];
            } 
        }
    }
}
