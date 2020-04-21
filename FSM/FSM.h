#pragma once
#include <map>

// ״̬ö��
enum eState
{
	eState_Idle,
};

// ״̬����
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
	std::map<eState, StateBase*>	m_States;	//״̬��
	eState							m_Curstate;	//��ǰ״̬
};

