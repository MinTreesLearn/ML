import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Problems problems = new Problems();
        problems.solve();
    }
}

class Problems {

    Parser parser = new Parser();

    void solve() {
        int t = 1;
        for (int i = 0; i < t; i++) {
            Problem problem = new Problem();
            problem.solve();
        }
    }

    class Problem {

        int lastSelectedA = -1;
        int lastSelectedB = -1;

        void solve() {
            int n = parser.parseInt();
            int m = parser.parseInt();

            List<List<Integer>> arrs = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                List<Integer> arr = new ArrayList<>();
                for (int j = 0; j < m; j++) {
                    arr.add(parser.parseInt());
                }
                arrs.add(arr);
            }

            int left = -1, right = 1_000_000_009;
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (ok(arrs, mid)) left = mid;
                else right = mid;
            }

            System.out.println(lastSelectedA + " " + lastSelectedB);
        }

        boolean ok(List<List<Integer>> arrs, int v) {
            int n = arrs.size();
            int m = arrs.get(0).size();
            Map<Integer, Integer> counts = new HashMap<>();

            for (int i = 0; i < n; i++) {
                int bit = 0;
                List<Integer> arr = arrs.get(i);
                for (int j = 0; j < m; j++) {
                    if (arr.get(j) < v) continue;
                    bit |= (1 << j);
                }
                counts.put(bit, i);
            }

            for (int i = 0; i < (1 << m); i++) {
                for (int j = 0; j < (1 << m); j++) {
                    if ((i | j) != (1 << m) - 1) continue;
                    if (counts.containsKey(i) &&
                            counts.containsKey(j)) {
                        lastSelectedA = counts.get(i) + 1;
                        lastSelectedB = counts.get(j) + 1;
                        return true;
                    }
                }
            }
            return false;
        }
    }
}

class Parser {
    private final Iterator<String> stringIterator;
    private final Deque<String> inputs;

    Parser() {
        this(System.in);
    }

    Parser(InputStream in) {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        stringIterator = br.lines().iterator();
        inputs = new ArrayDeque<>();
    }

    void fill() {
        while (inputs.isEmpty()) {
            if (!stringIterator.hasNext()) throw new NoSuchElementException();
            inputs.addAll(Arrays.asList(stringIterator.next().split(" ")));
            while (!inputs.isEmpty() && inputs.getFirst().isEmpty()) {
                inputs.removeFirst();
            }
        }
    }

    Integer parseInt() {
        fill();
        if (!inputs.isEmpty()) {
            return Integer.parseInt(inputs.pollFirst());
        }
        throw new NoSuchElementException();
    }

    Long parseLong() {
        fill();
        if (!inputs.isEmpty()) {
            return Long.parseLong(inputs.pollFirst());
        }
        throw new NoSuchElementException();
    }

    Double parseDouble() {
        fill();
        if (!inputs.isEmpty()) {
            return Double.parseDouble(inputs.pollFirst());
        }
        throw new NoSuchElementException();
    }

    String parseString() {
        fill();
        return inputs.removeFirst();
    }
}