#include <iostream>
#include "musicalConstants.h"
#include "notesAndChords.h"
#include "musicUtils.h"
#include "keySignatures.h"

MajorKey::MajorKey(Note* &key, Note* sharpsOrFlats[])
{
    this->firstDegree = new Chord(*key, ChordQuality::MAJOR);
    int notePos = key->semitonePosition;

    this->secondDegree = new Chord(*sharpsOrFlats[incrementSemitonePosition(notePos, 2)], ChordQuality::MINOR);
    this->thirdDegree = new Chord(*sharpsOrFlats[incrementSemitonePosition(notePos, 2)], ChordQuality::MINOR);
    this->fourthDegree = new Chord(*sharpsOrFlats[incrementSemitonePosition(notePos, 1)], ChordQuality::MAJOR);
    this->fifthDegree = new Chord(*sharpsOrFlats[incrementSemitonePosition(notePos, 2)], ChordQuality::MAJOR);
    this->sixthDegree = new Chord(*sharpsOrFlats[incrementSemitonePosition(notePos, 2)], ChordQuality::MINOR);
    this->seventhDegree = new Chord(*sharpsOrFlats[incrementSemitonePosition(notePos, 2)], ChordQuality::DIMINISHED);
}

std::ostream &operator << (std::ostream &output, const MajorKey* key)
{   
    
    output << "Key: " << std::endl;
    output << *key->firstDegree->root << key->firstDegree->quality << " Address: " << key->firstDegree->root << std::endl;
    output << *key->secondDegree->root << key->secondDegree->quality << " Address: " << key->secondDegree->root << std::endl;
    output << *key->thirdDegree->root << key->thirdDegree->quality << " Address: " << key->thirdDegree->root << std::endl;
    output << *key->fourthDegree->root << key->fourthDegree->quality << " Address: " << key->fourthDegree->root << std::endl;
    output << *key->fifthDegree->root << key->fifthDegree->quality << " Address: " << key->fifthDegree->root << std::endl;
    output << *key->sixthDegree->root << key->sixthDegree->quality << " Address: " << key->sixthDegree->root << std::endl;
    output << *key->seventhDegree->root << key->seventhDegree->quality << " Address: " << key->seventhDegree->root << std::endl;
    return output;
}
