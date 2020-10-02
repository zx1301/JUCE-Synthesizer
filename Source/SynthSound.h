/*
  ==============================================================================

    SynthSound.h
    Created: 25 Sep 2020 12:54:45am
    Author:  zx130

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
using namespace juce;

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber) override
    {
        return true;
    }
    bool appliesToChannel(int midiChannel) override
    {
        return true;
    }
};