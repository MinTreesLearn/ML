import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import static java.lang.Math.ceil;

public class App 
{
    public static void main( String[] args ) {
        Scanner in = new Scanner(System.in);

        int datasetNum = Integer.parseInt(in.nextLine());
        List<Integer[]> dataset = new ArrayList<>();

        for (int i = 0; i < datasetNum; i++) {
            String[] stringDataset = in.nextLine().split(" ");
            Integer[] intDataset = new Integer[2];

            for (int j = 0; j < stringDataset.length; j++) {
                intDataset[j] = Integer.parseInt(stringDataset[j]);
            }

            dataset.add(intDataset);
        }

        for (int i = 0; i < datasetNum; i++) {
            int deadlineDays = dataset.get(i)[0];
            int workDays = dataset.get(i)[1];
            boolean flag = false;

            if (deadlineDays >= workDays) {
                flag = true;
            }
            else {
                int x = deadlineDays;

                while(x > 0) {
                    if (x + ceil((double)workDays / (x + 1)) <= deadlineDays) {
                        flag = true;
                        break;
                    }
                    else {
                        x = x / 2;
                        flag = false;
                    }
                }
            }

            if (flag) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
        }
    }
}