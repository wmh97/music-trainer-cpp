#include <iostream>
#include "musicalConstants.h"
#include "notesAndChords.h"

Intervals getAscendingInterval(Note* startNote, Note* endNote)
{
    return Intervals(*startNote + *endNote);
}

Intervals getDescendingInterval(Note* startNote, Note* endNote)
{
    return Intervals((*startNote + *endNote)-12);
}

int incrementSemitonePosition(int &position, int increment)
{
    position = position + increment;
    if(position > 11) return (position-12);
    return position;
}