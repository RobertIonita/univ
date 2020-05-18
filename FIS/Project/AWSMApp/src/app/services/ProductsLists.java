package app.services;

import app.components.Component;
import app.promotions.Promotion;

import java.util.ArrayList;

public class ProductsLists {

    static ArrayList<Component> componentsList = new ArrayList<>();
    static ArrayList<System> systemsList = new ArrayList<>();
    static ArrayList<Promotion> promotionsList = new ArrayList<Promotion>();


    public static void push(Component component) {
        componentsList.add(component);
    }
    public void push(System system) {
        systemsList.add(system);
    }
    public void push(Promotion promotion) {
        promotionsList.add(promotion);
    }


    public static int getComponentsAmount() {
        return componentsList.size();
    }
    public static Component getComponent (int i) {
        return componentsList.get(i);
    }
}
