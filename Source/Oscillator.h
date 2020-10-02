/*
  ==============================================================================

    Oscillator.h
    Created: 30 Sep 2020 3:01:15pm
    Author:  zx130

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
using namespace juce;
//==============================================================================
/*
*/
class Oscillator  : public juce::Component,
    private ComboBox::Listener
{
public:
    Oscillator(SynthFrameworkAudioProcessor&);
    ~Oscillator() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

private:
    ComboBox oscMenu;

    SynthFrameworkAudioProcessor& audioProcessor;

    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
