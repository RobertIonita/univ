package com;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

@WebServlet(name = "testServlet", urlPatterns = {"/people"})
public class peopleServlet extends HttpServlet {
    ArrayList<Person> people = new ArrayList<Person>();


    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Person person = new Person(
                request.getParameter("first_name"),
                request.getParameter("last_name"),
                request.getParameter("birth_date"),
                request.getParameter("address"),
                request.getParameter("phone")
        );
        people.add(person);
        response.sendRedirect("people.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        out.println("[");
        int nr_records = people.size();
        for (int i = 0; i < nr_records; i++) {
            out.println(people.get(i).toString());
            if (i < nr_records - 1)
                out.println(",");
        }
        out.println("]");
        out.flush();
    }

}
