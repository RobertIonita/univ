package PJ.Lab1;

import java.util.Scanner;

public class Rectangle {
    private final int width;
    private final int height;

    private Rectangle(final int width, final int height) {
        this.width = width;
        this.height = height;
    }

    public int getArea() {
        return this.width * this.height;
    }

    public int getPerimeter() {
        return this.width + this.height;
    }

    public static void main(final String[] args) {
        int width, height;
        final Scanner scanner = new Scanner(System.in);

        System.out.print("Insert width: ");
        width = scanner.nextInt();
        System.out.print("Insert height: ");
        height = scanner.nextInt();
        final Rectangle rectangle = new Rectangle(width, height);
        System.out.println("Area: "+rectangle.getArea()+", perimeter: "+rectangle.getPerimeter());

        scanner.close();
    }
}
