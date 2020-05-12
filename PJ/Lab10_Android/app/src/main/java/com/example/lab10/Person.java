package com.example.lab10;

public class Person {
    private String name;
    private int id, age;

    public Person(String name, int id, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "{\n" +
                "    \"first_name\": \"" + id + "\",\r\n" +
                "    \"last_name\": \"" + name + "\",\r\n" +
                "    \"phone\": " + age + "" + "\n}";
    }
}