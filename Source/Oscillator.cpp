/*
  ==============================================================================

    Oscillator.cpp
    Created: 30 Sep 2020 3:01:15pm
    Author:  zx130

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(SynthFrameworkAudioProcessor& p): audioProcessor(p)
{
    setSize(200, 200);
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Square", 3);
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);
    oscMenu.setJustificationType(Justification::centred);

    waveSelection = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.tree, "wavetype", oscMenu);
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (juce::Graphics& g)
{

}

void Oscillator::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    juce::Rectangle<int> area = getLocalBounds().reduced(40);

    oscMenu.setBounds(area.removeFromTop(20));
}

void Oscillator::comboBoxChanged(ComboBox* box)
{
    
}