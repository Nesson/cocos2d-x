#ifndef __PERFORMANCE_LABEL_TEST_H__
#define __PERFORMANCE_LABEL_TEST_H__

#include "PerformanceTest.h"

class LabelMenuLayer : public PerformBasicLayer
{
public:
    LabelMenuLayer(bool controlMenuVisible, int maxCases = 0, int curCase = 0)
        : PerformBasicLayer(controlMenuVisible, maxCases, curCase)
    {
    }

    virtual void restartCallback(Object* sender) override;
    virtual void nextCallback(Object* sender) override;
    virtual void backCallback(Object* sender) override;
    virtual void showCurrentTest() override;
};

class LabelMainScene : public Scene
{
public:
    static const  int AUTO_TEST_NODE_NUM  = 6;

    virtual ~LabelMainScene();

    std::string title() const;
    void initWithSubTest(int nodes);
    void updateNodes();

    void onIncrease(Object* sender);
    void onDecrease(Object* sender);

    int getSubTestNum() { return 1; }
    int getNodesNum() { return _quantityNodes; }
    
    void  updateAutoTest(float dt);
    void  updateText(float dt);
    void  onAutoTest(Object* sender);

    void  autoShowLabelTests(int curCase,int nodes);

    virtual void onEnter() override;
    virtual void onExit() override;

    static bool _s_autoTest;
    static int  _s_labelCurCase;

private:
    static const  int MAX_AUTO_TEST_TIMES  = 50;
    static const  int MAX_SUB_TEST_NUMS    = 5;
    

    void  dumpProfilerFPS();
    
    void  endAutoTest();
    void  nextAutoTest();
    void  finishAutoTest();
    
    Layer*         _labelContainer;
    LabelTTF*      _title;

    int            _lastRenderedCount;
    int            _quantityNodes;
    
    std::vector<float> _vecFPS;
    int            _executeTimes;

    float          _accumulativeTime;
};

void runLabelTest();

#endif