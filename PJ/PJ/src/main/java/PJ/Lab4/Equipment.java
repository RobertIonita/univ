package PJ.Lab4;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

class GeneralInfo {
    String name;
    int idNumber;
    float price;
    String department;
    String status;
    String type;

    GeneralInfo(String[] s) {
        this.name = s[0];
        this.idNumber = Integer.parseInt(s[1]);
        this.price = Float.parseFloat(s[2]);
        this.department = s[3];
        this.status = s[4];
        this.type = s[5];
    }

    GeneralInfo() {

    }

    public String getName() {
        return this.type;
    }

    public void setStatus(String s) {
        this.status = s;
    }

    @Override
    public String toString() {
        return "\nGeneralInfo [name=" + name + ", idNumber=" + idNumber + ", price=" + price + ", department="
                + department + ", status=" + status + "]";
    }

}

class Printer extends GeneralInfo {
    int pagesPerMinute;
    String resolution;
    int pagesPerCartridge;
    String printMode;

    Printer(String[] s) {
        super(s);
        this.pagesPerMinute = Integer.parseInt(s[6]);
        this.resolution = s[7];
        this.pagesPerCartridge = Integer.parseInt(s[8]);
        this.printMode = s[9];

    }

    Printer() {

    }

    public String getName() {
        return "printer";
    }

    public void setPrintMode(String s) {
        printMode = s;
    }

    @Override
    public String toString() {
        return super.toString() + "\nPrinter [pagesPerMinute=" + pagesPerMinute + ", resolution=" + resolution
                + ", pagesPerCartridge=" + pagesPerCartridge + ", printMode=" + printMode + "]";
    }

}

class Xerox extends GeneralInfo {
    int pagesPerTonner;
    int pagesPerMinute;
    String copyFormat;

    Xerox(String[] s) {
        super(s);
        this.pagesPerMinute = Integer.parseInt(s[6]);
        this.pagesPerTonner = Integer.parseInt(s[7]);
        this.copyFormat = s[8];
    }

    @Override
    public String toString() {
        return super.toString() + "\nXerox [pagesPerTonner=" + pagesPerTonner + ", pagesPerMinute=" + pagesPerMinute
                + ", copyFormat=" + copyFormat + "]";
    }

    public String getName() {
        return "xerox";
    }

    public void setFormat(String s) {
        this.copyFormat = s;
    }
}

class ComputerSystem extends GeneralInfo {
    String monitorType;
    float clockFrequncy;
    int storage;
    String operatingSystem;

    ComputerSystem(String[] s) {
        super(s);
        this.monitorType = s[6];
        this.clockFrequncy = Float.parseFloat(s[7]);
        this.storage = Integer.parseInt(s[8]);
        this.operatingSystem = s[9];

    }

    @Override
    public String toString() {

        return super.toString() + "\nComputerSystem [monitorType=" + monitorType + ", clockFrequncy=" + clockFrequncy
                + ", storage=" + storage + ", operatingSystem=" + operatingSystem + "]";
    }

    public String getName() {
        return "computer system";
    }

    public void setOS(String s) {
        this.operatingSystem = s;
    }

}

public class Equipment {

    public static void main(String[] args) throws IOException {

        ArrayList<GeneralInfo> list = new ArrayList<GeneralInfo>();
        File file = new File("PJ/PJ/src/main/java/PJ/Lab4/equipment.txt");
        Scanner scan = new Scanner(file);

        while (scan.hasNextLine()) {
            String[] s = scan.nextLine().toString().split(";");
            switch (s[5]) {
                case "printer":
                    list.add(new Printer(s));
                    break;
                case "xerox":
                    GeneralInfo x = new Xerox(s);
                    list.add(x);
                    break;
                case "computer system":
                    ComputerSystem cs = new ComputerSystem(s);
                    list.add(cs);
                    break;
                default:
                    System.out.println("Invalid type of component:" + s[5]);

            }
        }
        list.get(0).setStatus("EXPUS");
        scan.close();
        Scanner s = new Scanner(System.in);
        int option;
        String str;
        do {
            System.out.println("1.Show Printers\n2.Show Xerox\n3.Show Computer Systems\n4.Modify status\n"
                    + "5.Printing mode for printer\n6.Set format for Xerox\n7.Install OS\n8.Show sold items\n0.EXIT");
            option = s.nextInt();
            int nr;
            switch (option) {
                case 1:
                    for (int i = 0; i < list.size(); i++)
                        if (list.get(i).getName().compareTo("printer") == 0)
                            System.out.println(list.get(i));

                    break;
                case 2:
                    for (int i = 0; i < list.size(); i++)
                        if (list.get(i).getName().compareTo("xerox") == 0)
                            System.out.println(list.get(i));
                    break;
                case 3:
                    for (int i = 0; i < list.size(); i++)
                        if (list.get(i).getName().compareTo("computer system") == 0)
                            System.out.println(list.get(i));
                    break;
                case 4:
                    System.out.print("Change status for product nr: ");
                    nr = s.nextInt();
                    System.out.print("Update status to:");
                    str = s.nextLine();

                    list.get(nr).setStatus(str);

                    break;
                case 5:

                    System.out.print("Change print mode for product nr: ");
                    nr = s.nextInt();
                    System.out.print("Change to:");
                    str = s.nextLine();
                    Printer a = (Printer) list.get(nr);
                    a.setStatus(str);
                    break;
                case 6:
                    System.out.print("Change format for product nr: ");
                    nr = s.nextInt();
                    System.out.print("Change to:");
                    str = s.nextLine();

                    Xerox x = (Xerox) list.get(nr);
                    x.setFormat(str);
                    break;
                case 7:
                    System.out.print("Change OS for product nr: ");
                    nr = s.nextInt();
                    System.out.print("Change to:");
                    str = s.nextLine();

                    ComputerSystem c = (ComputerSystem) list.get(nr);
                    c.setOS(str);
                    break;
                case 8:
                    for (int i = 0; i < list.size(); i++) {
                        if ((list.get(i).status.compareTo("vandut") == 0)) {
                            System.out.println(list.get(i));
                        }
                    }
                    break;

            }

        } while (option != 0);

        s.close();
    }
}
