#include "ITube.h"

Element::Element(const int aX, const int aY, Type aTyp)
{
    x = aX;
    y = aY;
    typ = aTyp;
}

Element::~Element()
{
}

bool Element::isCorrect(const ITube* tube) const
{
    if (this->getType() == EAST_WEST) {
        if (this->y == 0 || this->y == tube->getSize() - 1)
            return false;
        Type left = tube->getElement(x, y - 1)->getType();
        Type right = tube->getElement(x, y + 1)->getType();
        if (left == NONE || right == NONE)
            return false;
    }

    if (this->getType() == SOUTH_EAST_WEST) {
        if (this->y == 0 || this->y == tube->getSize() - 1 || this->x == tube->getSize() - 1)
            return false;
        Type left = tube->getElement(x, y - 1)->getType();
        Type right = tube->getElement(x, y + 1)->getType();
        Type down = tube->getElement(x + 1, y)->getType();
        if (left == NONE || right == NONE || down == NONE)
            return false;
    }

    if (this->getType() == NORTH_SOUTH) {
        if (this->x == 0 || this->x == tube->getSize() - 1)
            return false;
        Type up = tube->getElement(x - 1, y)->getType();
        Type down = tube->getElement(x + 1, y)->getType();
        if (up == NONE || down == NONE)
            return false;
    }

    if (this->getType() == NORTH_SOUTH_EAST_WEST) {
        if (this->y == 0 || this->y == tube->getSize() - 1 ||
            this->x == 0 || this->x == tube->getSize() - 1)
            return false;
        Type left = tube->getElement(x, y - 1)->getType();
        Type right = tube->getElement(x, y + 1)->getType();
        Type up = tube->getElement(x - 1, y)->getType();
        Type down = tube->getElement(x + 1, y)->getType();
        if (left == NONE || right == NONE || up == NONE || down == NONE)
            return false;
    }

    return true;
}

const Type Element::getType() const
{
    return typ;
}


Tube::Tube(const int aSize)
{
    size = aSize;
    for (size_t i = 0; i < aSize; i++)
    {
        matrix.insert(matrix.begin(), std::vector<ATubeElement*>());
    }
}

Tube::~Tube()
{
}

void Tube::addElement(const int x, const int y, ATubeElement* element)
{
    matrix.at(x).insert(matrix.at(x).end(), element);
}

const ATubeElement* Tube::getElement(int x, int y) const
{
    if (matrix.size() < x || matrix.at(x).size() < y || x < 0 || y < 0) {
        throw std::exception("Zadny prvek!");
    }

    return matrix.at(x).at(y);
}

bool Tube::isTubeOk() const
{
    for (int i = 0; i < size; i++)
    {
        std::vector<ATubeElement*> line = matrix.at(i);
        for (int j = 0; j < size; j++)
            if (line.at(j)->isCorrect(this) == false)
                return false;

    }
    return true;
}

const int Tube::getSize() const
{
    return size;
}

std::ifstream& operator >> (std::ifstream& input, Tube& a)
{
    char c = 0;
    ATubeElement* newPrvek = nullptr;
    int xNext = -1;

    std::string line;

    while (std::getline(input, line)) {
        int i = 0;
        ++xNext;
        int yNext = 0;

        for (i = 0; i < line.length(); i++) {
            c = line.at(i);

            switch (c) {
            case '-':
                newPrvek = new Element(xNext, yNext, EAST_WEST);
                break;
            case 'I':
                newPrvek = new Element(xNext, yNext, NORTH_SOUTH);
                break;
            case '+':
                newPrvek = new Element(xNext, yNext, SOUTH_EAST_WEST);
                break;
            case 'O':
                newPrvek = new Element(xNext, yNext, END);
                break;
            case 'T':
                newPrvek = new Element(xNext, yNext, SOUTH_EAST_WEST);
                break;
            case ' ':
                newPrvek = new Element(xNext, yNext, NONE);
                break;
            }
            a.addElement(xNext, yNext++, newPrvek);
        }

        for (; i < a.getSize(); i++)
        {
            newPrvek = new Element(xNext, yNext, NONE);
            a.addElement(xNext, yNext++, newPrvek);
        }
    }

    return input;
}

