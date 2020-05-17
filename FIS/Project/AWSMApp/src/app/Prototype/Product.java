package app.Prototype;

public abstract class Product {

    public int id;
    public String category;
    public String name;
    public int amount;
    public int price;
    public String image;


    public Product(
            int id,
            String category,
            String name,
            int amount,
            int price,
            String image
    ) {
        this.id = id;
        this.category = category;
        this.name = name;
        this.amount = amount;
        this.price = price;
        this.image = image;
    }



    public String getDeleteJSON() {
        return "{\n" +
                "   \"id\": " + id + ",\r\n" +
                "   \"name\": \"" + name + "\"\n}";
    }
}