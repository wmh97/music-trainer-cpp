#include <iostream>
#include <string>
#include "musicalConstants.h"
#include "notesAndChords.h"
#include "musicUtils.h"

Note::Note(SemitonePositions position, Accidentals accidental)
{
    this->semitonePosition = (position + accidental);
    if(this->semitonePosition > 11) this->semitonePosition -= 12;
    else if(this->semitonePosition < 0) this->semitonePosition += 12;

    switch(position)
    {
        case C:
            this->note[0] = 'C';
            break;
        case D:
            this->note[0] = 'D';
            break;
        case E:
            this->note[0] = 'E';
            break;
        case F:
            this->note[0] = 'F';
            break;
        case G:
            this->note[0] = 'G';
            break;
        case A:
            this->note[0] = 'A';
            break;
        case B:
            this->note[0] = 'B';
            break;
        default:
            std::cout << "Invalid Note Entered" << std::endl;
    }

    switch(accidental)
    {
        case SHARP:
            this->note[1] = '#';
            break;
        case FLAT:
            this->note[1] = 'b';
            break;
        case NATURAL:
            break;
        default:
            std::cout << "Ivalid Accidental Entered" << std::endl;
    }

}

int Note::operator + (Note endNote)
{
    /*
        Return the absolute interval between two notes.
    */
    return std::abs(this->semitonePosition - endNote.semitonePosition);
}

bool Note::operator == (Note otherNote)
{
    if(semitonePosition == otherNote.semitonePosition) return true;
    return false;
}

std::ostream &operator << (std::ostream &output, const Note note)
{   
    if(note.note[1] != '0')
    {
        output << note.semitonePosition << " " << note.note[0] << note.note[1];
        return output;
    }
    output << note.semitonePosition << " " << note.note[0];
    return output;
}

// Without the & the constructor uses the same address in memory to copy things into the instance,
// so each root member would end up with the same address.
Chord::Chord(Note &note, ChordQuality chordQuality)
{
    this->root = &note;

    switch(chordQuality)
    {
        case MAJOR:
            this->quality = "maj";
            break;
        case MINOR:
            this->quality = "m";
            break;
        case DIMINISHED:
            this->quality = "dim";
            break;
        default:
            std::cout << "Invalid Chord Quality" << std::endl;
    }
}

std::ostream &operator << (std::ostream &output, const Chord &chord)
{   
    output << *chord.root << chord.quality;
    return output;
}