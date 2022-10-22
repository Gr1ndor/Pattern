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

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;

    class BombIterator
    {
        std::vector<DynamicObject*>& vecDynamicObj2;
        int curIndex;
        Bomb* ptr;
    public:
        BombIterator(std::vector<DynamicObject*>& vec) : vecDynamicObj2(vec), curIndex(-1), ptr(nullptr) { ++(*this); }
        void reset() { curIndex = -1; ptr = nullptr; }
        BombIterator& operator++ ()
        {
            curIndex++;
            if (curIndex == -1)
                curIndex = 0;
            for (; curIndex < vecDynamicObj2.size(); curIndex++)
            {
                Bomb* pBomb = dynamic_cast<Bomb*>(vecDynamicObj2[curIndex]);
                if (pBomb != nullptr)
                {
                    ptr = pBomb;
                    break;
                }
            }
            if (curIndex == vecDynamicObj2.size())
            {
                curIndex = -1;
                ptr = nullptr;
            }
            return *this;
        }
        BombIterator& operator-- () 
        {
            if (curIndex == -1)
                curIndex = vecDynamicObj2.size() - 1;
            for (; curIndex >= 0; curIndex--)
            {
                Bomb* pBomb = dynamic_cast<Bomb*>(vecDynamicObj2[curIndex]);
                if (pBomb != nullptr)
                {
                    ptr = pBomb;
                    break;
                }
            }
            if (curIndex == -1)
            {
                ptr = nullptr;
            }
            return *this;
        }
        Bomb*& operator*()
        {
            return ptr;
        }
        bool operator==(BombIterator it) 
        {
            if (curIndex == it.curIndex &&
                ptr == it.ptr &&
                vecDynamicObj2 == it.vecDynamicObj2)
            {
                return true;
            }
            return false;
        }
        bool operator!=(BombIterator it) 
        {
            return !(*this == it);
        }
    };
    BombIterator begin() { BombIterator it(vecDynamicObj); return it; }
    BombIterator end() { BombIterator it(vecDynamicObj); it.reset(); return it; }


    std::vector<Bomb*> FindAllBombs();

    
    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};

