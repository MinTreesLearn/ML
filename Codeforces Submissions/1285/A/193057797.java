import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        String numOfCommands = scanner.nextLine();
        String command = scanner.nextLine();
//        System.out.println(numOfCommands);
//        System.out.println(command);


        int cntL = 0, cntR = 0;
        for (int i =0; i < command.length(); i++ ){
            if (command.charAt(i)=='L')
                cntL--;
            else if (command.charAt(i)=='R')
                cntR++;


        }
        if (command.length()==0) {
            System.out.println(1);

        }
        else{
            int diff = cntR-cntL +1;
            System.out.println(diff);
        }



    }
}