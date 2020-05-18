package app.components;

import app.services.prototype.Product;

public class Component extends Product {

    public final String provider;
    public final Boolean paid;
    public final Boolean delivered;
    public final String comments;

    public Component(int id, String category, String name, int amount, int price, String date, String image,
                     String provider, Boolean paid, Boolean delivered, String comments) {
        super(id, category, name, amount, price, date, image);
        this.provider = provider;
        this.paid = paid;
        this.delivered = delivered;
        this.comments = comments;
    }
}
