

import java.util.LinkedList;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        solve(s.nextInt(), s.nextInt(), s.nextInt());
    }


    public static void solve(int h, int w, int d) {
        if (d > 4 * h * w - 2 * h - 2 * w) {System.out.println("NO"); return;}
        System.out.println("YES");

        LinkedList<String> moves = new LinkedList<>();

        for (int i = 1; i < w; i++) {
            if (d != 0) {
                moves.add("1 R");
                d--;
            }

            if (h != 1) {
                if (d >= h - 1) {
                    d -= h - 1;
                    moves.add((h - 1) + " D");
                } else {
                    if (d == 0) break;
                    moves.add(d + " D");
                    d = 0;
                    break;
                }

                if (d >= h - 1) {
                    d -= h - 1;
                    moves.add((h - 1) + " U");
                } else {
                    if (d == 0) break;
                    moves.add(d + " U");
                    d = 0;
                    break;
                }
            }
        }

        if (w != 1) {
            if (d >= w - 1) {
                d -= w - 1;
                moves.add((w - 1) + " L");
            } else {
                if (d != 0)
                    moves.add(d + " L");
                d = 0;
            }
        }

        for (int i = 1; i < h; i++) {
            if (d != 0) {
                moves.add("1 D");
                d--;
            }

            if (w != 1) {
                if (d >= w - 1) {
                    d -= w - 1;
                    moves.add((w - 1) + " R");
                } else {
                    if (d == 0) break;
                    moves.add(d + " R");
                    d = 0;
                    break;
                }

                if (d >= w - 1) {
                    d -= w - 1;
                    moves.add((w - 1) + " L");
                } else {
                    if (d == 0) break;
                    moves.add(d + " L");
                    d = 0;
                    break;
                }
            }
        }

        if (h != 1) {
            if (d >= h - 1) {
                d -= h - 1;
                moves.add((h - 1) + " U");
            } else {
                if (d != 0)
                    moves.add(d + " U");
                d = 0;
            }
        }

        System.out.println(moves.size());
        for (String i: moves) System.out.println(i);
    }
}
