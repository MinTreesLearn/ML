import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Scanner;

public class CP{
    public static void main(String[] args)throws IOException {
        FastReader in=new FastReader(System.in);
        StringBuilder sb=new StringBuilder();
        int i,j;
        int n=in.nextInt();
        int m=in.nextInt();
        int itp[]=new int[n+1];
        int arr[]=new int[m];
        int ans[]=new int[n+1];
        int maxp[]=new int[n+1];
        boolean exist[]=new boolean[n+1];
        AVLTreeNew tree=new AVLTreeNew();
        int p=m+1;
        for(i=1;i<=n;i++){
           itp[i]=p;
           tree.insert(p);
           p++;
        }
        for(i=0;i<m;i++) {
            arr[i] = in.nextInt();
            exist[arr[i]]=true;
        }
        for(i=1;i<=n;i++){
            if(exist[i])
                ans[i]=1;
            else
                ans[i]=i;
            maxp[i]=i;
        }
        int x;
        p=m;
        for(i=0;i<m;i++){
            x=itp[arr[i]];
            maxp[arr[i]]=Math.max(maxp[arr[i]],tree.getPosition(x));
            tree.delete(x);
            tree.insert(p);
            itp[arr[i]]=p;
            p--;
        }
        for(i=1;i<=n;i++){
            x=itp[i];
            maxp[i]=Math.max(maxp[i],tree.getPosition(x));
        }
        for(i=1;i<=n;i++){
            sb.append(ans[i]+" "+maxp[i]).append("\n");
        }
        System.out.println(sb);




    }
}
class AVLTreeNew {
    Node root;

    public AVLTreeNew() {
        root = null;
    }

    int height(Node N) {
        if (N == null)
            return 0;
        return N.height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int getBalance(Node N) {
        if (N == null)
            return 0;
        return height(N.left) - height(N.right);
    }

    long getSize(Node N) {
        if (N == null)
            return 0;
        return N.size;
    }

    int size() {
        return (int) getSize(root);
    }

    public void recurse(Node n) {
        if (n == null)
            return;
        System.out.println(n.key + " " + n.size);
        if (n.left != null) {
            System.out.println("GO to left");
            recurse(n.left);
        }
        if (n.right != null) {
            System.out.println("GO to right");
            recurse(n.right);
        }
    }

    Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        x.right = y;
        y.left = T2;

        y.height = max(height(y.left), height(y.right)) + 1;
        x.height = max(height(x.left), height(x.right)) + 1;
        y.size = 1 + getSize(y.left) + getSize(y.right);
        x.size = 1 + getSize(x.left) + getSize(x.right);

        return x;

    }

    Node leftRotate(Node x) {
        Node y = x.right;
        Node T2 = y.left;

        y.left = x;
        x.right = T2;

        x.height = max(height(x.left), height(x.right)) + 1;
        y.height = max(height(y.left), height(y.right)) + 1;
        x.size = 1 + getSize(x.left) + getSize(x.right);
        y.size = 1 + getSize(y.left) + getSize(y.right);

        return y;
    }

    Node minValueNode(Node node) {
        Node current = node;
        while (current.left != null)
            current = current.left;

        return current;
    }

    void insert(int key) {
        root = insert(root, key);

    }

    void delete(int key) {
        root = deleteNode(root, key);
    }

    void display() {
        recurse(root);
    }

    Node insert(Node node, int key) {
        if (node == null)
            return new Node(key);
        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        } else {
            System.out.println(1 / 0);
            node.size += 1;
        }

        node.height = 1 + max(height(node.left), height(node.right));
        node.size = 1 + getSize(node.left) + getSize(node.right);

        int balance = getBalance(node);
        if (balance > 1 && key < node.left.key)
            return rightRotate(node);

        if (balance < -1 && key > node.right.key)
            return leftRotate(node);

        if (balance > 1 && key > node.left.key) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node.right.key) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        return node;

    }

    int getValue(long n) {
        return query(root, n);
    }
    int getPosition(long key){return (int)position(root,key);}

    long position(Node node,long key){
        if(key<node.key)
            return position(node.left,key);
        else if(key>node.key)
            return getSize(node.left)+1+position(node.right,key);
        else
            return getSize(node.left)+1;

    }

    int query(Node node, long n) {
        if (n <= getSize(node.left)) {
            return query(node.left, n);
        }
        if (n == getSize(node.left) + 1) {
            return node.key;
        } else {
            return query(node.right, n - getSize(node.left) - 1);
        }
    }

    Node deleteNode(Node root, int key) {
        if (root == null)
            return root;

        if (key < root.key)
            root.left = deleteNode(root.left, key);
        else if (key > root.key)
            root.right = deleteNode(root.right, key);

        else {

            if ((root.left == null) || (root.right == null)) {
                Node temp = null;
                if (temp == root.left)
                    temp = root.right;
                else
                    temp = root.left;

                if (temp == null) {
                    temp = root;
                    root = null;
                } else
                    root = temp;
            } else {

                Node temp = minValueNode(root.right);
                root.key = temp.key;

                root.right = deleteNode(root.right, temp.key);
            }
        }

        if (root == null)
            return root;

        root.height = max(height(root.left), height(root.right)) + 1;
        root.size = getSize(root.left) + getSize(root.right) + 1;

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root.left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root.left) < 0) {
            root.left = leftRotate(root.left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root.right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalance(root.right) > 0) {
            root.right = rightRotate(root.right);
            return leftRotate(root);
        }

        return root;
    }

    void preOrder(Node node) {
        if (node != null) {
            System.out.print(node.key + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
    }
}

class Node {
    int key, height;
    long size;
    Node left, right;

    public Node(int v) {
        key = v;
        size = 1;
        height = 1;
        left = right = null;
    }
}
class FastReader {

    byte[] buf = new byte[2048];
    int index, total;
    InputStream in;

    FastReader(InputStream is) {
        in = is;
    }

    int scan() throws IOException {
        if (index >= total) {
            index = 0;
            total = in.read(buf);
            if (total <= 0) {
                return -1;
            }
        }
        return buf[index++];
    }

    String next() throws IOException {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        StringBuilder sb = new StringBuilder();
        for (; c > 32; c = scan()) {
            sb.append((char) c);
        }
        return sb.toString();
    }

    String nextLine() throws IOException {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        StringBuilder sb = new StringBuilder();
        for (; c != 10 && c != 13; c = scan()) {
            sb.append((char) c);
        }
        return sb.toString();
    }

    char nextChar() throws IOException {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        return (char) c;
    }

    int nextInt() throws IOException {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+') {
            c = scan();
        }
        for (; c >= '0' && c <= '9'; c = scan()) {
            val = (val << 3) + (val << 1) + (c & 15);
        }
        return neg ? -val : val;
    }

    long nextLong() throws IOException {
        int c;
        long val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+') {
            c = scan();
        }
        for (; c >= '0' && c <= '9'; c = scan()) {
            val = (val << 3) + (val << 1) + (c & 15);
        }
        return neg ? -val : val;
    }
}