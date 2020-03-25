// package PJ.Lab5;

// import java.util.Scanner;

// class Validate {
//     private static float numerator, denumerator;

//     public static void check() {
//         boolean valid = false;
//         Scanner scanner = new Scanner(System.in);
//         String line;
//         do {
//             try {
//                 System.out.print("Insert numerator: ");
//                 line = scanner.nextLine();
//                 numerator = Float.parseFloat(line);
//                 valid = true;
//             } catch (Exception e) {
//                 System.out.println("Float expected! Error - " + e.getMessage());
//             }
//         } while (!valid);
//         valid = false;
//         do {
//             try {
//                 System.out.print("Insert denumerator: ");
//                 line = scanner.nextLine();
//                 denumerator = Float.parseFloat(line);
//                 try {
//                     if (denumerator == 0)
//                         throw new ArithmeticException();
//                     else
//                         valid = true;
//                 } catch (Exception s) {
//                     System.out.println("Division by zero is illegal!");
//                 }
//             } catch (Exception e) {
//                 System.out.println("Float expected! Error - " + e.getMessage());
//             }
//         } while (!valid);
//         scanner.close();
//     }

//     @Override
//     public String toString() {
//         return numerator + " divided by " + denumerator + " is equal to: " + numerator / denumerator;
//     }
// }

// public class Dividing extends Exception {
//     private static final long serialVersionUID = 1L;

//     public static void main(String[] args) {
//         try {
//             Validate.check();
//             Validate validate = new Validate();
//             System.out.println(validate.toString());
//         } catch (Exception e) {
//             e.printStackTrace();
//         }
//     }
// }

package PJ.Lab5;
import java.util.Scanner;

public class Dividing extends Exception {
    private static final long serialVersionUID = 1L;
    private static float numerator, denumerator;

    @Override
    public String toString() {
        return numerator + " divided by " + denumerator + " is equal to: " + numerator / denumerator;
    }

    public static void main(String[] args) {
        boolean valid = false;
        Scanner scanner = new Scanner(System.in);
        String line;
        do {
            try {
                System.out.print("Insert numerator: ");
                line = scanner.nextLine();
                numerator = Float.parseFloat(line);
                valid = true;
            } catch (Exception e) {
                System.out.println("Float expected! Error - " + e.getMessage());
            }
        } while (!valid);
        valid = false;
        do {
            try {
                System.out.print("Insert denumerator: ");
                line = scanner.nextLine();
                denumerator = Float.parseFloat(line);
                try {
                    if (denumerator == 0)
                        throw new ArithmeticException();
                    else
                        valid = true;
                } catch (Exception s) {
                    System.out.println("Division by zero is illegal!");
                }
            } catch (Exception e) {
                System.out.println("Float expected! Error - " + e.getMessage());
            }
        } while (!valid);
        scanner.close();
        Dividing division = new Dividing();
        System.out.println(division.toString());
    }
}
