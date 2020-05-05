package com;

public class Person {
    String first_name,
            last_name,
            birth_date,
            address,
            phone;

    public Person (String first_name, String last_name, String birth_date, String address, String phone) {
        this.first_name = first_name;
        this.last_name = last_name;
        this.birth_date = birth_date;
        this.address = address;
        this.phone = phone;
    }

    @Override
    public String toString() {
        final String GET_PARAMS = "{\n" +
                "    \"first_name\": \"" + first_name + "\",\r\n" +
                "    \"last_name\": \"" + last_name + "\",\r\n" +
                "    \"birth_date\": \"" + birth_date + "\",\r\n" +
                "    \"address\": \"" + address + "\",\r\n" +
                "    \"phone\": \"" + phone + "\"" + "\n}";
        return GET_PARAMS;
    }
}
