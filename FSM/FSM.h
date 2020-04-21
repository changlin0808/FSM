#pragma once
#include <map>

// ״̬ö��
enum eState
{
	eState_Idle,
};

// ״̬����
class StateBasic
{
public:
	virtual ~StateBasic();
	virtual void Enter();
	virtual void Execute();
	virtual void Exit();
};

class State_Idle : public StateBasic
{
};

// ����״̬��
class FSM
{
public:
	// ״̬ע��
	int Register(eState State);

	// ״̬ע��
	int UnRegister(eState State);

	// ״̬�л�
	void ChangeState(eState NewState);

	// ״̬�Ƿ����
	bool IsExit(eState State);

	// ��ǰ״̬��tick
	void Execute();

private:
	std::map<eState, StateBasic*>	m_States;	//״̬��
	eState							m_Curstate;	//��ǰ״̬
};

