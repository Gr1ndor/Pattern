#pragma once

#include "Visitour.h"
#include "DynamicObject.h"

class Plane : public DynamicObject {
public:

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }
    //void accept(Visitor& v) { v.visit(this); };
private:

};

