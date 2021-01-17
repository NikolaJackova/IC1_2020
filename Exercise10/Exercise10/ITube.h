#pragma once
#ifndef TUBE_H
#define TUBE_H

#include <vector>
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


enum Type {
    EAST_WEST,
    NORTH_SOUTH,
    NORTH_SOUTH_EAST_WEST,
    NONE,
    END,
    SOUTH_EAST_WEST
};

struct ATubeElement;
struct ITube {
    virtual ~ITube() { }
    virtual const ATubeElement* getElement(int x, int y) const = 0;
    virtual bool isTubeOk() const = 0;
    virtual const int getSize() const = 0;
};

struct ATubeElement {
    virtual ~ATubeElement() { }
    virtual bool isCorrect(const ITube* potrubi) const = 0;
    virtual const Type getType() const = 0;
    int x;
    int y;
};

class Tube : public ITube {
private:
    std::vector<std::vector<ATubeElement*>> matrix = std::vector<std::vector<ATubeElement*>>();
    int size = 0;
public:
    Tube(const int aX);
    ~Tube();
    void addElement(const int x, const int y, ATubeElement* element);
    const ATubeElement* getElement(int x, int y) const;
    bool isTubeOk() const;
    const int getSize() const;
};

std::ifstream& operator >> (std::ifstream& output, Tube& a);

class Element : public ATubeElement {
private:
    Type typ;
public:
    Element(const int aX, const int aY, Type aTyp);
    ~Element();
    bool isCorrect(const ITube* tube) const;
    const Type getType() const;
};

#endif //TUBE_H
