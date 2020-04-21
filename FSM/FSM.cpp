

StateBase::~StateBase()
{

}

void StateBase::Enter()
{

}

void StateBase::Execute()
{

}

void StateBase::Exit()
{

}

int FSM::Register(eState State)
{
	if (IsExit(State))
		return -1;
	switch (State)
	{
	case eState_Idle:
		m_States[State] = new State_Idle();
		break;
	default:
		break;
	}
	return 0;
}

int FSM::UnRegister(eState State)
{
	if (!IsExit(State))
		return -1;
	delete m_States[State];
	m_States.erase(State);
	return 0;
}

void FSM::ChangeState(eState NewState)
{
	if (NewState == m_Curstate)
		return;

	if (!IsExit(m_Curstate) || !IsExit(NewState))
		return;

	m_States[m_Curstate]->Exit();
	m_Curstate = NewState;
	m_States[m_Curstate]->Enter();
}

bool FSM::IsExit(eState State)
{
	if (m_States.find(State) != m_States.end())
		return true;
	return false;
}

void FSM::Execute()
{
	if (!IsExit(m_Curstate))
		return;
	m_States[m_Curstate]->Execute();
}
