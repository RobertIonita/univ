package app.promotions;

import app.services.prototype.Product;

public class Promotion extends Product {
    public Promotion(int id, String category, String name, int amount, int price, String date, String image) {
        super(id, category, name, amount, price, date, image);
    }
}
