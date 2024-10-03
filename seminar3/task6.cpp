#include <iostream>
#include <string>


int main() {
    int* a = new int{123};
    std::string* catsNDogs = new std::string{"Cats and Dogs"};
    int* mas = new int[5]{10, 20, 30, 40, 50};
    std::string* strMas = new std::string[3]{"Cats", "Dog", "Mouse"};
    std::string_view* strView = new std::string_view[3]{strMas[0], strMas[1], strMas[2]};
    std::cout << *a << "\n" << *catsNDogs << "\n" << mas[0] << " " << mas[1] << " " << mas[2] << " " << mas[3] << " " << mas[4] << "\n" << strMas[0] << " " << strMas[1] << " " << strMas[2] << "\n" << strView << "\n";


    delete a;
    delete catsNDogs;
    delete [] mas;
    delete [] strMas;
    delete [] strView;
    std::cout << "everything destroyed";
}
