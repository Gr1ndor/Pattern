//#pragma once
//#include "Bomb.h"
//#include "Plane.h"
//
//class Visitor
//{
//public:
//    virtual void visit(Bomb* b) = 0;
//    virtual void visit(Plane* p) = 0;
//};
//
//class LogVisitor : public Visitor
//{
//    void visit(Bomb* b)
//    {
//        std::ofstream fout;
//        fout.open("log.txt");
//        fout << "logging bomb";
//        fout.close();
//    }
//    void visit(Plane* p)
//    {
//        std::ofstream fout;
//        fout.open("log.txt");
//        fout << "logging plane";
//        fout.close();
//    }
//};