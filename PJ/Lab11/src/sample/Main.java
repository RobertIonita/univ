package sample;

import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

// driver class
public class Main {

    // styling for console logs for easier reading
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_RESET = "\u001B[0m";

    // driver function
    public static void main(String[] args) throws IOException {

        // list of all employees
        List<Employee> employees = new ArrayList<>();

        // collection of employees with leading position employed in April
        List<Employee> aprilLeaders = new ArrayList<>();

        // collection of employees with non-leading position
        List<Employee> nonLeaders = new ArrayList<>();

        // collection of employees' names written in upper case
        List<String> upperCasedNames = new ArrayList<>();

        // create buffer from input file
        InputStream inputStream = Main.class.getResourceAsStream("/input.txt");
        InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

        // read from buffer records about employees
        String line = null;
        while ((line = bufferedReader.readLine()) != null) {
            String[] employeeData = line.split(", ");

            // create an Employee object from read data, then it is added to employees List
            employees.add(new Employee(
                    employeeData[0],
                    employeeData[1],
                    LocalDate.parse(employeeData[2], DateTimeFormatter.ofPattern("d.M.yyyy")),
                    Float.parseFloat(employeeData[3])
            ));
        }

        // display all employees' data
        System.out.println(ANSI_BLUE + "\nToate inregistrarile despre angajati:" + ANSI_RESET);
        for (Employee employee : employees) {
            System.out.println(employee.toString());
        }

        // display only those employees whose salary is bigger than 2500
        System.out.println(ANSI_BLUE + "\nAngajati cu salarii mai mari de 2500RON:" + ANSI_RESET);
        employees.stream()
                .filter(employee -> employee.hasSalaryBiggerThan(2500))
                .forEach(System.out::println);

        // create a new List with employees whose employment month is April and has a leading position
        System.out.println(ANSI_BLUE + "\nAngajati in luna aprilie cu functie de conducere:" + ANSI_RESET);
        aprilLeaders = employees.stream()
                .filter(employee -> employee.isMonthOfEmployment(4))
                .filter((Employee::hasLeadingPosition))
                .collect(Collectors.toList());

        // display aprilLeaders List
        for (Employee aprilLeader : aprilLeaders) {
            System.out.println(aprilLeader.toString());
        }

        // collect and sort a List of non-leading employees
        nonLeaders = employees.stream()
                .filter(employee -> !employee.hasLeadingPosition())
                .collect(Collectors.toList());

        // display non-leading employees sorted by their salary in descending order
        System.out.println(ANSI_BLUE + "\nAngajati fara functie de conducere sortati descrescator dupa salariu:" + ANSI_RESET);
        nonLeaders.sort(Comparator.comparing(Employee::getSalary).reversed());
        for (Employee nonLeader : nonLeaders) {
            System.out.println(nonLeader.toString());
        }

        // collect and display a List of employees' names written in uppercase
        System.out.println(ANSI_BLUE + "\nNumele angajatilor scris cu mjuscule:" + ANSI_RESET);
        upperCasedNames = employees.stream()
                .map(employee -> employee.getName().toUpperCase())
                .collect(Collectors.toList());
        for (String name : upperCasedNames) {
            System.out.println(name);
        }

        // display salaries lover than 3000
        System.out.println(ANSI_BLUE + "\nSalariile ce nu depasesc 3000RON:" + ANSI_RESET);
        employees.stream()
                .filter(employee -> !employee.hasSalaryBiggerThan(3000 - 1))
                .map(Employee::getSalary)
                .forEach(System.out::println);
    }
}
