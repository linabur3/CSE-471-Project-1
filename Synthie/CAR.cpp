#include "pch.h"
#include "CAR.h"

CAR::CAR()
{
	m_attack = .05;
	m_release = .05;
	m_time = 0;
}
void CAR::SetSource(CAudioNode* source)
{
	m_source = source;
}

void CAR::Start()
{
	m_time = 0;
}

bool CAR::Generate()
{
	m_time += GetSamplePeriod();
	double note_duration = m_duration * (1 / m_bpm) * 60;

	if (m_time < m_attack)
	{
		m_frame[0] = m_source->Frame(0) * (m_time / m_attack);
		m_frame[1] = m_source->Frame(1) * (m_time / m_attack);
	}
	else if (m_time > (note_duration - m_release))
	{
		m_frame[0] = m_source->Frame(0) * ((note_duration - m_time) / m_release);
		m_frame[1] = m_source->Frame(1) * ((note_duration - m_time) / m_release);
	}
	else
	{
		m_frame[0] = m_source->Frame(0);
		m_frame[1] = m_source->Frame(1);
	}
	return m_time < note_duration;
}