#include <iomanip>
#include <string.h>
#include <iostream>
#include "clothes.h"
#include "shoes.h"
#include "customer.cpp"
#include "store.cpp"

int main(){
    Clothes pr1("Nike", TypeClothes::shirt , 19.99, "M", "dark");
    Clothes pr2("Zara", TypeClothes::skirt, 50.9999, "S", "rose");
    Clothes pr3("H&M" , TypeClothes::pants, 99.99, "XS", "white");
    Clothes pr4("Puma", TypeClothes::shirt, 50, "S", "rose");

    for(int i = 0; i < 3; i++){
        //clothes[i].Print();
        //clothes[i].MakeProductDiscount(20);
    }
//    pr1 = pr2;
//    pr1.Print();
//
//    Shoes s1;
//    Shoes snickers("Adidas", "snickers", 199.99, 39, "white");
//    s1 = snickers;
//    s1.Print();
//    snickers.Print();
    Clothes allClothes[4];
    allClothes[0] = pr1;
    allClothes[1] = pr2;
    allClothes[2] = pr3;
    allClothes[3] = pr4;
    Clothes clothes[3];
    clothes[0] = pr1;
    clothes[1] = pr2;
    clothes[2] = pr3;

    Customer<Clothes> customers[1];
    Customer<Clothes> Anita("Anita", "Sofia, Mladost 2", 3, &clothes[3]);
    cout << "Print Anita's info: " << endl;
    Anita.Print();
    customers[1] = Anita;
    cout << endl;
//    Clothes pr4("Puma", TypeClothes::shirt, 50, "S", "rose");
//    Anita.addProducts(pr4);
    Anita.removeProducts(1);
    Anita.Print();

    Store<Clothes> ASOS("ASOS", 4, &allClothes[4]);
    cout << "Print ASOS info: " << endl;
    ASOS.Print();

    return 0;
}
