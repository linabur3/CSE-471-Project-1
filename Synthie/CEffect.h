#pragma once
class CEffect
{
public:
	CEffect() {}
	virtual void ProcessAudio(double* audio) = 0;
	virtual bool Start() = 0;
	void setSampleRate(double rate) { mSampleRate = rate; }

protected:
	enum State {Attack, Bypass, Active, Release, Knee};
	State mState;
	double mAttack;
	double mRelease;
	double mAttackStart;
	double mReleaseStart;
	double mSampleRate;
	double m_time;     
};

