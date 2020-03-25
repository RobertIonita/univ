package PJ.Lab5;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Pairs {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String line = null;
        int x = 0, y = 0;
        do {
            try {
                System.out.print("Insert first number: ");
                line = scanner.next();
                x = Integer.parseInt(line);
                try {
                    System.out.print("Insert second number: ");
                    line = scanner.next();
                    y = Integer.parseInt(line);
                    if (y <= x) {
                        System.out.println("Invalid input, please insert the pair in ascendent order!\n");
                        throw new Exception();
                    }
                } catch (Exception e) {
                    continue;
                }
            } catch (Exception e) {
                continue;
            }

        } while (y <= x);
        String outputFile;
        if (args.length > 0)
            outputFile = args[0];
        else
            outputFile = "PJ/PJ/src/main/java/PJ/Lab5/ascending_pair.txt";
        FileWriter fw = new FileWriter(outputFile);
        fw.write("the pair is: " + x + "," + y);
        fw.close();
        scanner.close();
    }
}
