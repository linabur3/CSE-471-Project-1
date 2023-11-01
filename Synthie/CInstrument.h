#pragma once
#include "CAudioNode.h"
#include"CNote.h"
#include "CSampleManager.h"

class CInstrument : public CAudioNode
{
public:
	virtual void SetNote(CNote* note) = 0;
	void setManager(CSampleManager* manager) { m_manager = manager; }

protected:
	CSampleManager* m_manager;
};

