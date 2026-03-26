//package assignment;

import java.io.PrintWriter;
import java.util.*;

public class TreapMap<K extends Comparable<K>, V> implements Treap<K, V> {
    TreapNode<K, V> head;
    @Override
    public V lookup(K key) {
        TreapNode<K, V> tr = lookupH(key);
        if(tr == null) return null;
        else return tr.getValue();
    }
    private TreapNode<K, V> lookupH(K key) {
        TreapNode<K, V> curr = head;
        while (true) {
            if(curr == null) return null;
            int compareVal = curr.getKey().compareTo(key);
            if (compareVal > 0) curr = curr.getLeft();
            else if (compareVal < 0) curr = curr.getRight();
            else return curr;
        }
    }
    public void insert(K key, V value, int prio) {
        TreapNode<K, V> curr = head;
        TreapNode<K, V> toInsert = new TreapNode<>(key, value, prio);
        ArrayList<TreapNode<K, V>> path = new ArrayList<>();
        if(head == null) {
            head = toInsert;
            return;
        }
        while (true) {
            path.add(curr);
            int compareVal = curr.getKey().compareTo(key);
            if (compareVal > 0) {
                if(curr.getLeft() == null) {
                    curr.setLeft(toInsert);
                    break;
                }
                curr = curr.getLeft();
            }
            else if(compareVal == 0 && prio != Treap.MAX_PRIORITY) { // override if we're not adding a split node
                curr.setValue(value);
                return;
            }
            else {
                if(curr.getRight() == null) {
                    curr.setRight(toInsert);
                    break;
                }
                curr = curr.getRight();
            }
        }
        curr = toInsert;
        for(int i = path.size() - 1; i >= 1; i--) {
            if(path.get(i).getPrio() < curr.getPrio()) {
                if(path.get(i - 1).getLeft() == path.get(i) && path.get(i).getLeft() == curr) {
                    rotateLL(path.get(i - 1));
                }
                else if(path.get(i - 1).getLeft() == path.get(i) && path.get(i).getRight() == curr) {
                    rotateLR(path.get(i - 1));
                }
                else if(path.get(i - 1).getRight() == path.get(i) && path.get(i).getLeft() == curr) {
                    rotateRL(path.get(i - 1));
                }
                else if(path.get(i - 1).getRight() == path.get(i) && path.get(i).getRight() == curr) {
                    rotateRR(path.get(i - 1));
                }
                else {
                    System.out.println("insert is BROKEN LOL");
                }
            }
            else break;
        }
        if(head.getPrio() < curr.getPrio()) {
            if(head.getLeft() == curr) {
                head.setLeft(curr.getRight());
                curr.setRight(head);
            }
            else {
                head.setRight(curr.getLeft());
                curr.setLeft(head);
            }
            head = curr;
        }
    }
    @Override
    public void insert(K key, V value) {
        Random r = new Random();
        insert(key, value, r.nextInt(Treap.MAX_PRIORITY));
    }

    @Override
    public V remove(K key) {
        TreapNode<K, V> par = null;
        TreapNode<K, V> curr = head;
        while (true) {
            if(curr == null) return null;
            if(curr.getKey() == null) break; // join case
            int compareVal = curr.getKey().compareTo(key);
            if (compareVal > 0) {
                par = curr;
                curr = curr.getLeft();
            }
            else if (compareVal < 0) {
                par = curr;
                curr = curr.getRight();

            }
            else break;
        }
        while(curr.getLeft() != null || curr.getRight() != null) {
            int lPrio = -1;
            if(curr.getLeft() != null) lPrio = curr.getLeft().getPrio();
            int rPrio = -1;
            if(curr.getRight() != null) rPrio = curr.getRight().getPrio();
            if(rPrio > lPrio) { // swap with right then
                if(par == null) { // curr = head
                    TreapNode<K, V> temp = curr.getRight();
                    assert temp != null;
                    curr.setRight(temp.getLeft());
                    temp.setLeft(curr);
                    head = temp;
                    par = temp;
                }
                else {
                    TreapNode<K, V> temp = curr.getRight();
                    if(par.getLeft() == curr) {
                        par.setLeft(temp);
                    }
                    else {
                        par.setRight(temp);
                    }
                    curr.setRight(temp.getLeft());
                    temp.setLeft(curr);
                    par = temp;
                }
            } else {
                if(par == null) { // curr = head
                    TreapNode<K, V> temp = curr.getLeft();
                    assert temp != null;
                    curr.setLeft(temp.getRight());
                    temp.setRight(curr);
                    head = temp;
                    par = temp;
                }
                else {
                    TreapNode<K, V> temp = curr.getLeft();
                    if(par.getLeft() == curr) {
                        par.setLeft(temp);
                    }
                    else {
                        par.setRight(temp);
                    }
                    curr.setLeft(temp.getRight());
                    temp.setRight(curr);
                    par = temp;
                }
            }
        }
        if(par == null) head = null; // head = node
        else if(par.getLeft() == curr) par.setLeft(null);
        else if(par.getRight() == curr) par.setRight(null);
        return curr.getValue();
    }

    @Override
    public Treap<K, V>[] split(K key) {
        Treap<K, V>[] ans = new TreapMap[2];
        this.insert(key, null, Treap.MAX_PRIORITY);
        TreapMap<K, V> t1 = new TreapMap<>();
        t1.head = head.getLeft();
        TreapMap<K, V> t2 = new TreapMap<>();
        t2.head = head.getRight();
        ans[0] = t1;
        ans[1] = t2;
        return ans;
    }

    @Override
    public void join(Treap<K, V> t) {
        if(!(t instanceof TreapMap)) throw new IllegalArgumentException();
        TreapMap<K, V> tTr = (TreapMap<K, V>) t;
        TreapNode<K, V> joiner = new TreapNode<>(null, null, Treap.MAX_PRIORITY);
        if(tTr.head.getKey().compareTo(this.head.getKey()) < 0) {
            joiner.setLeft(tTr.head);
            joiner.setRight(this.head);
        }
        else {
            joiner.setRight(tTr.head);
            joiner.setLeft(this.head);
        }
        head = joiner;
        remove(null);
    }

    @Override
    public void meld(Treap<K, V> t) throws UnsupportedOperationException {
        if(!(t instanceof TreapMap)) return;
        meldRec(((TreapMap<K, V>) t).head);
    }
    private void meldRec(TreapNode<K, V> curr) {
        if(curr == null) return;
        TreapNode<K, V> oldHead = head;
        this.insert(curr.getKey(), curr.getValue(), curr.getPrio());
        head = this.lookupH(curr.getKey());
        meldRec(curr.getLeft());
        meldRec(curr.getRight());
        head = oldHead;
    }
    @Override
    public void difference(Treap<K, V> t) throws UnsupportedOperationException {
        if(!(t instanceof TreapMap)) return;
        diffRec(((TreapMap<K, V>) t).head);
    }
    private void diffRec(TreapNode<K, V> curr) {
        if(curr == null) return;
        TreapNode<K, V> oldHead = head;
        TreapNode<K, V> tr = this.lookupH(curr.getKey());
        if(tr != null) {
            this.remove(curr.getKey());
            this.head = tr;
        }
        meldRec(curr.getLeft());
        meldRec(curr.getRight());
        head = oldHead;
    }
    @Override
    public Iterator<K> iterator() {
        ArrayList<K> arr = new ArrayList<>();
        dfs2(arr, head);
        return arr.iterator();
    }

    private void dfs2(ArrayList<K> trav, TreapNode<K, V> curr) {
        if(curr == null) return;
        dfs2(trav, curr.getLeft());
        trav.add(curr.getKey());
        dfs2(trav, curr.getRight());
    }
    @Override
    public double balanceFactor() throws UnsupportedOperationException {
        return 0;
    }

    private void rotateLL(TreapNode<K, V> p) {
        TreapNode<K, V> c1 = p.getLeft();
        TreapNode<K, V> c2 = c1.getLeft();
        TreapNode<K, V> temp = c2.getRight();
        p.setLeft(c2);
        c2.setRight(c1);
        c1.setLeft(temp);
    }

    private void rotateLR(TreapNode<K, V> p) {
        TreapNode<K, V> c1 = p.getLeft();
        TreapNode<K, V> c2 = c1.getRight();
        TreapNode<K, V> temp = c2.getLeft();
        p.setLeft(c2);
        c2.setLeft(c1);
        c1.setRight(temp);
    }

    private void rotateRL(TreapNode<K, V> p) {
        TreapNode<K, V> c1 = p.getRight();
        TreapNode<K, V> c2 = c1.getLeft();
        TreapNode<K, V> temp = c2.getRight();
        p.setRight(c2);
        c2.setRight(c1);
        c1.setLeft(temp);
    }

    private void rotateRR(TreapNode<K, V> p) {
        TreapNode<K, V> c1 = p.getRight();
        TreapNode<K, V> c2 = c1.getRight();
        p.setRight(c2);
        TreapNode<K, V> temp = c2.getLeft();
        c2.setLeft(c1);
        c1.setRight(temp);
    }
    private void dfs(ArrayList<String> trav, TreapNode<K, V> curr) {
        if(curr == null) return;
        trav.add(String.format("[%d] <%s, %s>%n", curr.getPrio(), curr.getKey().toString(), curr.getValue().toString()));
        dfs(trav, curr.getLeft());
        dfs(trav, curr.getRight());
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        ArrayList<String> trav = new ArrayList<>();
        dfs(trav, head);
        for(String str : trav) sb.append(str);
        return sb.toString();
    }

    // testing- proof by ac
    // https://codeforces.com/contest/1278/problem/C
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        loop:
        while(t-- > 0) {
            int x = sc.nextInt();
            TreapMap<Integer, Integer> hs = new TreapMap<>();
            for(int i=1;i<=2*x;i++){
                hs.insert(i, 0);
            }
            int[] arr = new int[2*x];
            for(int i=0;i<2*x;i+=2){
                arr[i]=sc.nextInt();
                hs.remove(arr[i]);
            }
            //pw.println(hs);
            for(int i=1;i<2*x;i+=2){
                if(hs.lookup(arr[i-1]+1) != null){
                    arr[i]=arr[i-1]+1;
                    hs.remove(arr[i]);
                }
                else{
                    for(int j=arr[i-1];j<=2*x;j++){
                        if(hs.lookup(j) != null){
                            arr[i]=j;
                            hs.remove(j);
                            break;
                        }
                        if(j==2*x){
                            pw.println(-1);
                            continue loop;
                        }
                    }
                }
            }
            for(int trr : arr){
                pw.print(trr+" ");
            }
            pw.println();
        }
        pw.close();
    }
}
class TreapNode<K, V> {
    private int prio;
    private K key;
    private V value;
    private TreapNode<K, V> left;
    private TreapNode<K, V> right;

    public int getPrio() {
        return prio;
    }

    public V getValue() {
        return value;
    }

    public K getKey() {
        return key;
    }

    public TreapNode<K, V> getLeft() {
        return left;
    }

    public TreapNode<K, V> getRight() {
        return right;
    }

    public void setLeft(TreapNode<K, V> left) {
        this.left = left;
    }

    public void setValue(V value) {
        this.value = value;
    }

    public void setRight(TreapNode<K, V> right) {
        this.right = right;
    }

    public TreapNode(K key, V value, int prio) {
        this.key = key;
        this.value = value;
        this.prio = prio;
    }
    public String toString() {
        return String.format("{%s, %d}", this.key.toString(), prio);
    }
}
interface Treap<K extends Comparable<K>, V> extends Iterable<K> {

    /**
     * The maximum priority that a node can have.
     */
    public static final int MAX_PRIORITY = 65535;

    /**
     * Retrieves the value associated with a key in this dictionary.
     * If the key is null or the key is not present in this
     * dictionary, this method returns null.
     *
     * @param key   the key whose associated value
     *              should be retrieved
     * @return      the value associated with the key, or
     *              null if the key is null or the key is not in
     *              this treap
     */
    V lookup(K key);

    /**
     * Adds a key-value pair to this dictionary.  Any old value
     * associated with the key is lost.  If the key or the value is
     * null, the pair is not added to the dictionary.
     *
     * @param key      the key to add to this dictionary
     * @param value    the value to associate with the key
     */
    void insert(K key, V value);

    /**
     * Removes a key from this dictionary.  If the key is not present
     * in this dictionary, this method does nothing.  Returns the
     * value associated with the removed key, or null if the key
     * is not present.
     *
     * @param key      the key to remove
     * @return         the associated with the removed key, or null
     */
    V remove(K key);

    /**
     * Splits this treap into two treaps.  The left treap should contain
     * values less than the key, while the right treap should contain
     * values greater than or equal to the key.
     *
     * @param key    the key to split the treap with
     * @return       the left treap in index 0, the right in index 1
     */
    Treap<K, V> [] split(K key);

    /**
     * Joins this treap with another treap.  If the other treap is not
     * an instance of the implementing class, both treaps are unmodified.
     * At the end of the join, this treap will contain the result.
     * This method may destructively modify both treaps.
     *
     * @param t    the treap to join with
     */
    void join(Treap<K, V> t);

    /**
     * Melds this treap with another treap.  If the other treap is not
     * an instance of the implementing class, both treaps are unmodified.
     * At the end of the meld, this treap will contain the result.  This
     * method may destructively modify both treaps.
     *
     * If you don't implement this method, just throw an
     * UnsupportedOperationException.
     *
     * @param t    the treap to meld with.  t may be modified.
     */
    void meld(Treap<K, V> t) throws UnsupportedOperationException;

    /**
     * Removes elements from another treap from this treap.  If the
     * other treap is not an instance of the implementing class,
     * both treaps are unmodified.  At the end of the difference,
     * this treap will contain no keys that were in the other
     * treap.  This method may destructively modify both treaps.
     *
     * If you don't implement this method, just throw an
     * UnsupportedOperationException.
     *
     * @param t   a treap containing elements to remove from this
     *            treap.  t may be destructively modified.
     */
    void difference(Treap<K, V> t) throws UnsupportedOperationException;


    /**
     * Build a human-readable version of the treap.
     * Each node in the treap will be represented as
     *
     *     [priority] <key, value>\n
     *
     * Subtreaps are indented one tab over from their parent for
     * printing.  This method prints out the string representations
     * of key and value using the object's toString(). Treaps should
     * be printed in pre-order traversal fashion.
     */
    String toString();


    /**
     * @return a fresh iterator that points to the first element in
     * this assignment.Treap and iterates in sorted order.
     */
    Iterator<K> iterator();

    /**
     * Returns the balance factor of the treap.  The balance factor
     * is the height of the treap divided by the minimum possible
     * height of a treap of this size.  A perfectly balanced treap
     * has a balance factor of 1.0.  If this treap does not support
     * balance statistics, throw an exception.
     *
     * If you don't implement this method, just throw an
     * UnsupportedOperationException.
     */
    double balanceFactor() throws UnsupportedOperationException;
}