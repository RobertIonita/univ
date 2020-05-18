package app.systems;

import app.services.prototype.Product;

public class SystemProduct extends Product {
    public SystemProduct(int id, String category, String name, int amount, int price, String date, String image) {
        super(id, category, name, amount, price, date, image);
    }
}
