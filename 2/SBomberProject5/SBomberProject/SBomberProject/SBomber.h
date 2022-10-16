#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:
    

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb); //1
    void __fastcall DeleteStaticObj(GameObject* pObj); //2

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();  //3

    std::vector<DynamicObject*> vecDynamicObj;  //4
    std::vector<GameObject*> vecStaticObj;  //5
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};

class Command
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
};

class DeleteDynamic : public Command
{
    DynamicObject* obj;
    std::vector<DynamicObject*>& v;
public:
    DeleteDynamic(DynamicObject* pObj, std::vector<DynamicObject*>& _v): obj(pObj), v(_v) {}
    void Execute();
};

class DeleteStatic : public Command
{
    GameObject* obj;
    std::vector<GameObject*>& v;
public:
    DeleteStatic(GameObject* pBomb, std::vector<GameObject*>& _v) : obj(pBomb), v(_v) {}
    void Execute();
};

class DropBombs : public Command
{
    Plane* p;
    std::vector<DynamicObject*>& v;
    uint16_t* bombs;
    int16_t* score;
public:
    DropBombs(Plane* _p, std::vector<DynamicObject*>& _v,uint16_t* _bombs, int16_t* _score) :p(_p), v(_v), bombs(_bombs), score(_score) {}
    void Execute();
};