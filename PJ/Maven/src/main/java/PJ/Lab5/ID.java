package PJ.Lab5;

import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.time.format.FormatStyle;
import java.util.Scanner;

public class ID {
    static class LengthException extends Exception {
        private static final long serialVersionUID = 7954058351316808640L;
        String id;

        public LengthException(String cnp) {
            this.id = cnp;
        }

        public String toString() {
            return "Invalid length, was inserted: " + this.id;
        }
    }

    static class GenderException extends Exception {
        private static final long serialVersionUID = 8923692447036904248L;
        String id;

        public GenderException(String cnp) {
            this.id = cnp;
        }

        public String toString() {
            return "Invalid gender, was inserted: " + this.id;
        }
    }

    static class MonthException extends Exception {
        private static final long serialVersionUID = 2208394304352755512L;
        String id;

        public MonthException(String cnp) {
            this.id = cnp;
        }

        public String toString() {
            return "Invalid month, was inserted: " + this.id;
        }
    }

    static class DayException extends Exception {
        private static final long serialVersionUID = -5544180063277854698L;
        String id;

        public DayException(String cnp) {
            this.id = cnp;
        }

        public String toString() {
            return "Invalid day, was inserted: " + this.id;
        }
    }

    static Boolean validLength(String id) throws LengthException {
        if (id.length() != 13) {
            throw new LengthException(id);
        } else {
            return true;
        }
    }

    static boolean isNumerical(String id) {
        if (id == null) {
            return false;
        }
        int len = id.length();
        for (int i = 0; i < len; i++) {
            if ((Character.isLetter(id.charAt(i)) == false)) {
                return false;
            }
        }
        return true;
    }

    static Boolean validGender(String str) throws GenderException {
        if (str.charAt(0) >= 1 || str.charAt(0) <= 6) {
            return true;
        } else {
            throw new GenderException(str);
        }
    }

    static Boolean validMonth(String str) throws MonthException {
        if (Integer.parseInt(str.substring(3, 5)) >= 01 && Integer.parseInt(str.substring(3, 5)) <= 12) {
            return true;
        } else {
            throw new MonthException(str);
        }
    }

    static Boolean validDay(String str) throws DayException {
        if (Integer.parseInt(str.substring(5, 7)) >= 0 && Integer.parseInt(str.substring(5, 7)) <= 31) {
            return true;
        } else {
            throw new DayException(str);
        }
    }

    static Boolean validateID(String str)
            throws LengthException, GenderException, MonthException, DayException, NumberFormatException {
        if (validLength(str) && isNumerical(str) && validGender(str) && validMonth(str) && validDay(str)) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {

        Boolean valid = false;
        String id = null;
        String name = null;
        Scanner scanner = new Scanner(System.in);
        do {
            try {
                System.out.print("Name: ");
                name = scanner.nextLine();
                System.out.print("ID: ");
                id = scanner.next();
                validateID(id);
            } catch (LengthException length) {
                System.out.println("Invalid length");
            } catch (GenderException gender) {
                System.out.println("Invalid gender");
            } catch (MonthException month) {
                System.out.println("Invalid month");
            } catch (DayException day) {
                System.out.println("Invalid day");
            } catch (NumberFormatException e) {
                System.out.println("Invalid numeric format");
            }
            valid = true;

        } while (!valid);
        scanner.close();
        LocalDate now = LocalDate.now();
        String year = id.substring(1, 3) + id.substring(3, 5) + id.substring(5, 7);
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyMMdd");
        now.format(DateTimeFormatter.ofLocalizedDate(FormatStyle.SHORT));
        LocalDate birthday = LocalDate.parse(year, formatter);
        Period diff = Period.between(birthday, now);
        System.out.print("" + name + " is ");
        if (diff.getYears() > 0)
            System.out.println(diff.getYears());
        else
            System.out.println(diff.getYears() + 100);
        System.out.println("Birth date: " + id.substring(5, 7) + "/" + id.substring(3, 5) + "/" + id.substring(1, 3));
    }
}
