#pragma once
#include <map>

// 状态枚举
enum eState
{
	eState_Idle,
};

// 状态基类
class StateBase
{
public:
	virtual ~StateBase();
	virtual void Enter();
	virtual void Execute();
	virtual void Exit();
};

class State_Idle : public StateBase
{
};

// 有限状态机
class FSM
{
public:
	// 状态注册
	int Register(eState State);

	// 状态注销
	int UnRegister(eState State);

	// 状态切换
	void ChangeState(eState NewState);

	// 状态是否存在
	bool IsExit(eState State);

	// 当前状态的tick
	void Execute();

private:
	std::map<eState, StateBase*>	m_States;	//状态集
	eState							m_Curstate;	//当前状态
};

