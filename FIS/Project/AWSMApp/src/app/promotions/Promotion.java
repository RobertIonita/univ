package app.promotions;
public class Promotion {

    public String category, name, provider, image;
    public int id, system_id, amount;
    public Promotion(int id, int system_id, String category, String name, int amount, String provider, String image) {
        this.id=id;
        this.system_id = system_id;
        this.category=category;
        this.name=name;
        this.amount=amount;
        this.provider=provider;
        this.image=image;
    }
}
