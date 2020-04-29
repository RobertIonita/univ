package PJ.Lab1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class Analysis {
    private static int min;
    private static int max;
    private static int summ;
    private static int count;
    private int value;

    private Analysis(int value) {
        this.value = value;
        if (Analysis.max < value)
            Analysis.max = value;
        if (Analysis.min > value)
            Analysis.min = value;
        Analysis.summ += value;
        Analysis.count++;
    }

    private Analysis(String reffernce) {
        int value = Integer.parseInt(reffernce);
        Analysis.max = value;
        Analysis.min = value;
        Analysis.count++;
        Analysis.summ = value;
    }

    public float getAverage() {
        return Analysis.summ / Analysis.count;
    }

    public int getSumm() {
        return Analysis.summ;
    }

    public void display() {
        System.out.println(this.value);
    }

    public void log() throws FileNotFoundException {
        PrintStream stream = new PrintStream("out.txt");
        stream.println(this.value);
        stream.close();
    }

    public static void main(final String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("in.txt"));
        String line = scanner.nextLine();
        Analysis data = new Analysis(line);
        data.display();
        data.log();

        while (scanner.hasNext()) {
            line = scanner.nextLine();
            data = new Analysis(Integer.parseInt(line));
        }
        scanner.close();
    }
}
