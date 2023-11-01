#include "pch.h"
#include "CPiano.h"
#include "audio/DirSoundSource.h"
#include <string>
#include "Synthie.h"
#include "NoteToIndex.h"

using namespace std;

const double GAIN = .5;

CPiano::CPiano()
{
    curFrame = 0;
    skippedFrames = 0;
}

void CPiano::Start()
{
    m_time = 0;
    curFrame = 0;
    mFrames_To_Skip = m_manager->getFramesToSkip();

    // Set initial release time (assume no pedal)
    m_releaseEnvelope = .05;
}


bool CPiano::Generate()
{
    // Get current status of the pianos pedal
    // Sustain the note in the release envelope longer to simulate pedal, otherwise have quick release to simulate no pedal
    if (m_manager->getPedal())
        m_releaseEnvelope = 1;
    else
        m_releaseEnvelope = .05;

    if (skippedFrames == 0)
    {
        m_frame[0] = mcurrSample[curFrame];
        m_frame[1] = m_frame[0];

        curFrame++;
    }

    skippedFrames = (skippedFrames + 1) % mFrames_To_Skip;

    // Decay note based on release envelope
    if (m_time > m_duration)
    {
        double dampening_factor = (m_duration - m_time + m_releaseEnvelope) / m_releaseEnvelope;
        m_frame[0] = m_frame[0] * dampening_factor;
        m_frame[1] = m_frame[0];
    }

    // Apply gain
    m_frame[0] = m_frame[0] * GAIN;
    m_frame[1] = m_frame[1] * GAIN;

    m_time += GetSamplePeriod();
    return m_time < (m_duration + m_releaseEnvelope);
}


void CPiano::SetNote(CNote* note)
{
    // Get a list of all attribute nodes and the
    // length of that list
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);

    // Loop over the list of attributes
    for (int i = 0; i < len; i++)
    {
        // Get attribute i
        CComPtr<IXMLDOMNode> attrib;
        attributes->get_item(i, &attrib);

        // Get the name of the attribute
        CComBSTR name;
        attrib->get_nodeName(&name);

        // Get the value of the attribute.  A CComVariant is a variable
        // that can have any type. It loads the attribute value as a
        // string (UNICODE), but we can then change it to an integer 
        // (VT_I4) or double (VT_R8) using the ChangeType function 
        // and then read its integer or double value from a member variable.
        CComVariant value;
        attrib->get_nodeValue(&value);

        if (name == "duration")
        {
            value.ChangeType(VT_R8);
            SetDuration(value.dblVal);
        }

        else if (name == "note")
        {
            int index = NoteToIndex(value.bstrVal);
            mcurrSample = m_manager->getSample(index);
        }

        else if (name == "pedal")
        {
            // Set pedal for the piano system globally, stored in SampleManager
            value.ChangeType(VT_I2);

            if (value.iVal)
                m_manager->setPedal(true);
            else
                m_manager->setPedal(false);
        }

    }

}