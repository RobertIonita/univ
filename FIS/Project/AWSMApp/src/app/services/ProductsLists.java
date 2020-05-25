package app.services;

import app.components.Component;
import app.promotions.Promotion;
import app.systems.Systems;

import java.util.ArrayList;

public class ProductsLists {

    static ArrayList<Component> componentsList = new ArrayList<>();
    static ArrayList<Systems> systemsList = new ArrayList<>();
    static ArrayList<Promotion> promotionsList = new ArrayList<Promotion>();


    public static void push(Component component) {
        componentsList.add(component);
    }
    public static void push(Systems systems) {
        systemsList.add(systems);
    }
    public static void push(Promotion promotion) {
        promotionsList.add(promotion);
    }

    public static int getComponentsAmount() {
        return componentsList.size();
    }
    public static Component getComponent (int i) {
        return componentsList.get(i);
    }

    public static int getSystemsAmount() {
        return systemsList.size();
    }
    public static Systems getSystems (int i) { return systemsList.get(i); }

    public static int getPromotionsAmount() {
        return promotionsList.size();
    }

    public static Promotion getPromotion (int id) {
        for (Promotion promotion : promotionsList) {
            if (promotion.system_id == id)
                return promotion;
        }
        return null;
    }
}
