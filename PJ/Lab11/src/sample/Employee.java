package sample;

import java.time.LocalDate;

// Employee class
public class Employee {
    private String name;
    private String position;
    private LocalDate employmentDate;
    private Float salary;

    // constructor
    public Employee(String name,
                    String position,
                    LocalDate employmentDate,
                    Float salary) {
        this.name = name;
        this.position = position;
        this.employmentDate = employmentDate;
        this.salary = salary;
    }

    // get employee name
    public String getName() {
        return this.name;
    }

    // get employee position
    public String getPosition() {
        return this.position;
    }

    // get employee employment date
    public LocalDate getEmploymentDate() {
        return this.employmentDate;
    }

    // get employee salary
    public Float getSalary() {
        return this.salary;
    }

    // set employee name
    public void setName(String name) {
        this.name = name;
    }

    // set employee position
    public void setPosition(String position) {
        this.position = position;
    }

    // set employee employment date
    public void setEmploymentDate(LocalDate employmentDate) {
        this.employmentDate = employmentDate;
    }

    // set employee salary
    public void setSalary(Float salary) {
        this.salary = salary;
    }

    // join employee data
    @Override
    public String toString() {
        return this.name + ", " + this.position + ", " + this.employmentDate + ", " + this.salary;
    }

    // check if employee's salary is bigger than a given value
    public boolean hasSalaryBiggerThan(int salary) {
        return this.salary > salary;
    }

    // check if employee's date of employment is equal to a given value
    public boolean isMonthOfEmployment(int month) {
        return this.employmentDate.getMonthValue() == month;
    }

    // check if employee has a leading position
    public boolean hasLeadingPosition() {
        return this.position.contains("sef") || this.position.contains("director");
    }
}
