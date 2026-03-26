import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.FilterInputStream;
import java.io.BufferedInputStream;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        ScanReader in = new ScanReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DRecommendations solver = new DRecommendations();
        solver.solve(1, in, out);
        out.close();
    }

    static class DRecommendations {
        public void solve(int testNumber, ScanReader in, PrintWriter out) {
            int n = in.scanInt();
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) arr[i] = in.scanInt();
            int b[] = new int[n];
            for (int i = 0; i < n; i++) b[i] = in.scanInt();
            long pair[][] = new long[n][2];

            for (int i = 0; i < n; i++) {
                pair[i][0] = arr[i];
                pair[i][1] = b[i];
            }

            Arrays.sort(pair, new Comparator<long[]>() {

                public int compare(long[] o1, long[] o2) {
                    return Long.compare(o1[0], o2[0]);
                }
            });

            long cc = pair[0][0];
            long Totalcost = pair[0][1];
            AVLTree<Long> avlTree = new AVLTree<>(true);
            avlTree.insert(pair[0][1]);


            long ans = 0;
            for (int i = 1; i < n; i++) {
                while (cc < pair[i][0] && avlTree.getSize() > 0) {
                    cc++;
                    Totalcost -= avlTree.getMaX();
                    avlTree.remove(avlTree.getMaX());
                    ans += Totalcost;
                }

                avlTree.insert(pair[i][1]);
                Totalcost += pair[i][1];
                cc = pair[i][0];
            }


            while (avlTree.getSize() > 0) {
                Totalcost -= avlTree.getMaX();
                avlTree.remove(avlTree.getMaX());
                ans += Totalcost;
            }

            out.print(ans);


        }

    }

    static class ScanReader {
        private byte[] buf = new byte[4 * 1024];
        private int INDEX;
        private BufferedInputStream in;
        private int TOTAL;

        public ScanReader(InputStream inputStream) {
            in = new BufferedInputStream(inputStream);
        }

        private int scan() {
            if (INDEX >= TOTAL) {
                INDEX = 0;
                try {
                    TOTAL = in.read(buf);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (TOTAL <= 0) return -1;
            }
            return buf[INDEX++];
        }

        public int scanInt() {
            int I = 0;
            int n = scan();
            while (isWhiteSpace(n)) n = scan();
            int neg = 1;
            if (n == '-') {
                neg = -1;
                n = scan();
            }
            while (!isWhiteSpace(n)) {
                if (n >= '0' && n <= '9') {
                    I *= 10;
                    I += n - '0';
                    n = scan();
                }
            }
            return neg * I;
        }

        private boolean isWhiteSpace(int n) {
            if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1) return true;
            else return false;
        }

    }

    static class AVLTree<T extends Comparable<? super T>> {
        private Node<T> root;
        private boolean multi;
        private Node<T> tempNode;

        public AVLTree() {
            this.root = null;
            this.multi = false;
        }

        public AVLTree(boolean multi) {
            this.root = null;
            this.multi = multi;
        }

        public T getMaX() {
            if (root == null) return null;
            tempNode = root;
            while (tempNode.right != null) {
                tempNode = tempNode.right;
            }
            return tempNode.data;
        }

        public long getSize() {
            if (root == null) return 0;
            else {
                return root.leftcount + root.rightcount + root.count;
            }
        }

        public void insert(T data, long... count) {
            if (count.length == 0) root = insert(data, root, 1);
            else {
                if (count[0] > 0) root = insert(data, root, count[0]);
            }
        }

        private Node<T> insert(T data, Node<T> tempRoot, long count) {
            if (tempRoot == null) {
                if (!multi) {

                    return new Node<>(data);
                } else {

                    return new Node<>(data, count);
                }
            }


            int compartor = data.compareTo(tempRoot.data);
            if (compartor < 0) {
                tempRoot.left = insert(data, tempRoot.left, count);
            } else if (compartor > 0) {
                tempRoot.right = insert(data, tempRoot.right, count);
            } else {
                if (multi) {
                    tempRoot.count += count;
                }
            }


            tempRoot.leftcount = getLeftCount(tempRoot.left) + getRightCount(tempRoot.left) + getCount(tempRoot.left);
            tempRoot.rightcount = getLeftCount(tempRoot.right) + getRightCount(tempRoot.right) + getCount(tempRoot.right);


            tempRoot.height = Math.max(Hieght(tempRoot.left), Hieght(tempRoot.right)) + 1;


            long diff = getBalence(tempRoot);

            if (diff > 1) {
                if (data.compareTo(tempRoot.left.data) < 0) {
                    return rotateRight(tempRoot);
                } else {
                    tempRoot.left = rotateLeft(tempRoot.left);
                    return rotateRight(tempRoot);
                }
            } else if (diff < -1) {
                if (data.compareTo(tempRoot.right.data) > 0) {
                    return rotateLeft(tempRoot);
                } else {
                    tempRoot.right = rotateRight(tempRoot.right);
                    return rotateLeft(tempRoot);
                }
            }

            return tempRoot;


        }

        public Node<T> rotateRight(Node<T> node) {
            Node<T> x = node.left;
            Node<T> t2 = x.right;


            x.right = node;
            node.left = t2;


            node.height = Math.max(Hieght(node.right), Hieght(node.left)) + 1;
            x.height = Math.max(Hieght(x.left), Hieght(x.right)) + 1;


            node.leftcount = getLeftCount(node.left) + getRightCount(node.left) + getCount(node.left);
            node.rightcount = getLeftCount(node.right) + getRightCount(node.right) + getCount(node.right);


            x.leftcount = getLeftCount(x.left) + getRightCount(x.left) + getCount(x.left);
            x.rightcount = getLeftCount(x.right) + getRightCount(x.right) + getCount(x.right);

            return x;

        }

        public Node<T> rotateLeft(Node<T> node) {
            Node<T> x = node.right;
            Node<T> t2 = x.left;


            x.left = node;
            node.right = t2;


            node.height = Math.max(Hieght(node.right), Hieght(node.left)) + 1;
            x.height = Math.max(Hieght(x.left), Hieght(x.right)) + 1;


            node.leftcount = getLeftCount(node.left) + getRightCount(node.left) + getCount(node.left);
            node.rightcount = getLeftCount(node.right) + getRightCount(node.right) + getCount(node.right);


            x.leftcount = getLeftCount(x.left) + getRightCount(x.left) + getCount(x.left);
            x.rightcount = getLeftCount(x.right) + getRightCount(x.right) + getCount(x.right);

            return x;

        }

        public long getLeftCount(Node<T> node) {
            if (node == null) return 0;
            return node.leftcount;
        }

        public long getRightCount(Node<T> node) {
            if (node == null) return 0;
            return node.rightcount;
        }

        public long getCount(Node<T> node) {
            if (node == null) return 0;
            return node.count;
        }

        long getBalence(Node<T> node) {
            if (node == null)
                return 0;

            return Hieght(node.left) - Hieght(node.right);
        }

        public long Hieght(Node<T> Node) {
            if (Node == null) return 0;
            else return Node.height;
        }

        public void remove(T data) {
            root = remove(root, data, 1);
        }

        private Node<T> remove(Node<T> tempRoot, T data, long num) {


            if (tempRoot == null) return null;
            int compartor = data.compareTo(tempRoot.data);
            if (compartor < 0) {
                tempRoot.left = remove(tempRoot.left, data, num);
            } else if (compartor > 0) {
                tempRoot.right = remove(tempRoot.right, data, num);
            } else {
                if (multi && num < tempRoot.count && tempRoot.count > 1) {
                    tempRoot.count -= num;
                } else {
                    if (tempRoot.left == null && tempRoot.right == null) {
                        return null;
                    } else if (tempRoot.left == null) return tempRoot.right;
                    else if (tempRoot.right == null) return tempRoot.left;
                    else {
                        Node<T> minValueNode = getMinValueNode(tempRoot.right);

                        tempRoot.data = minValueNode.data;
                        tempRoot.count = minValueNode.count;

                        tempRoot.right = remove(tempRoot.right, tempRoot.data, tempRoot.count);
                    }

                }
            }


            tempRoot.leftcount = getLeftCount(tempRoot.left) + getRightCount(tempRoot.left) + getCount(tempRoot.left);
            tempRoot.rightcount = getLeftCount(tempRoot.right) + getRightCount(tempRoot.right) + getCount(tempRoot.right);

            tempRoot.height = Math.max(Hieght(tempRoot.left), Hieght(tempRoot.right)) + 1;


            long diff = getBalence(tempRoot);

            if (diff > 1) {
                if (getBalence(tempRoot.left) >= 0) {
                    return rotateRight(tempRoot);
                } else {
                    tempRoot.left = rotateLeft(tempRoot.left);
                    return rotateRight(tempRoot);
                }
            } else if (diff < -1) {
                if (getBalence(tempRoot.right) <= 0) {
                    return rotateLeft(tempRoot);
                } else {
                    tempRoot.right = rotateRight(tempRoot.right);
                    return rotateLeft(tempRoot);
                }
            }

            return tempRoot;
        }

        public Node<T> getMinValueNode(Node<T> node) {
            if (node == null) return null;
            Node<T> currentNode = node;
            while (currentNode.left != null) {
                currentNode = currentNode.left;
            }
            return currentNode;
        }

        public class Node<T> {
            T data;
            long height;
            Node<T> left;
            Node<T> right;
            long leftcount;
            long rightcount;
            long count;

            public Node(T data) {
                this.data = data;
                this.height = 1;
                this.left = null;
                this.right = null;
                this.leftcount = 0;
                this.rightcount = 0;
                this.count = 1;
            }

            public Node(T data, long count) {
                this.data = data;
                this.height = 1;
                this.left = null;
                this.right = null;
                this.leftcount = 0;
                this.rightcount = 0;
                this.count = count;
            }

        }

    }
}

