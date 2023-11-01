#pragma once
#include <vector>

class CSampleManager
{
public:
	CSampleManager();
	void LoadSamples();
	int getFramesToSkip() { return mFrames_To_Skip; }
	std::vector<short> getSample(int i) { return m_samples[i]; }
	bool getPedal() { return m_pedalToggle; }
	void setPedal(bool toggle) { m_pedalToggle = toggle; }

private:
	std::vector<std::vector<short>> m_samples;
	int mFrames_To_Skip;
	bool m_pedalToggle;
};

