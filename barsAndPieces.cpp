#include <iostream>
#include <string>
#include <vector>
#include "musicalConstants.h"
#include "notesAndChords.h"
#include "barsAndPieces.h"
#include "musicUtils.h"

Bar::Bar(TimeSignatures timeSig)
{
    this->timeSignature = timeSig;
    this->numberOfBeats = timeSig/10;
    
    // new array of pointers. setting to nullptr.
    this->beats = new Chord*[this->numberOfBeats]; 
    for(int i = 0; i < this->numberOfBeats; i++)
    {
        this->beats[i] = nullptr;
    }
}

void Bar::addChordAtBeat(Chord* &chord, int beat)
{   
    if(beat > this->numberOfBeats)
    {
        std::cout << "Beat position invalid" << std::endl;
        return;
    }

    beat -= 1; // the beats 
    this->beats[beat] = chord; // setting the chord to the beat of the bar specified.
}

std::ostream &operator << (std::ostream &output, const Bar &bar)
{   
    for (int i = 0; i < bar.numberOfBeats; i++)
    {
        output << *bar.beats[i] << " ";
    }
    return output;
}


Piece::Piece(TimeSignatures timeSig)
{
    this->timeSignature = timeSig;
}

Piece::Piece(std::string title, TimeSignatures timeSig)
{
    this->pieceTitle = title;
    this->timeSignature = timeSig;
}

void Piece::addBar(Bar &bar)
{
    this->bars.push_back(bar);

    for (int i = 0; i<bar.numberOfBeats; i++)
    {
        Chord* tempChord;
        
        // if there is a chord in the bar, store it in the latestChord. Then if we find a new chord store that in
        // tempChord, calculate the interval and update latestChord to that tempChord.
        if(bar.beats[i])
        {
            if(latestChord)
            {
                tempChord = bar.beats[i];
                this->intervals.push_back(getAscendingInterval(latestChord->root, tempChord->root));
                latestChord = tempChord;
            }
            else
            {
                latestChord = bar.beats[i];
            }
            
        }
    }
}

void Piece::printIntervals()
{
    std::cout << "Intervals: " << std::endl;
    for(Intervals interval : this->intervals)
    {
        std::cout << interval;
    }
}

std::ostream &operator << (std::ostream &output, const Piece &piece)
{   
    if(piece.pieceTitle != "")
    {
        std::cout << piece.pieceTitle << ": " << std::endl;
    }
    
    for(int i = 0; i<piece.bars.size(); i++)
    {
        output << piece.bars[i] << std::endl;
    }
    return output;
}
