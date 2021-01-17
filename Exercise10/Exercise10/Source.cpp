#include <iostream>
#include "string"
#include "ITube.h"

using namespace std;

int main() {
    string line;
    int velikost;
    Tube p = Tube(0);
    for (int i = 1; i < 3; i++)
    {
    std:stringstream fileTube;
        fileTube << "file" << i << ".txt";

        string soubor = fileTube.str();
        std::ifstream file(soubor, std::ifstream::in);
            std::getline(file, line);
            velikost = stoi(line);
            p = Tube(velikost);
            file >> p;
            cout << "Soubor " << i << " je:  ";
            cout << p.isTubeOk() << endl;
    }
    return 0;

}
