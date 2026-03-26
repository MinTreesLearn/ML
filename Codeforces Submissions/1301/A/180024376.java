    import java.util.*;

    public class Main {

        public static void main(String[] args) {
            new Main();
        }

        public Main() {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            scanner.nextLine();
            for (int i = 0; i < n; i++) {
                String a = scanner.nextLine(), b = scanner.nextLine(), c = scanner.nextLine();
                boolean possible = true;
                for (int j = 0; j < a.length() && possible; j++) {
                    char cc = c.charAt(j);
                    if (a.charAt(j) == cc || b.charAt(j) == cc) continue;
                    possible = false;
                }
                System.out.println(possible ? "YES" : "NO");
            }
        }

    }
