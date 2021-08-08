#ifndef NOTES_AND_CHORDS_H
#define NOTES_AND_CHORDS_H

class Note
{
public:
    int semitonePosition;
    char note[2] = {'0'}; 

    Note(SemitonePositions position, Accidentals accidental);

    int operator + (Note endNote);

    bool operator == (Note otherNote);

    friend std::ostream &operator << (std::ostream &output, const Note note);
};

class Chord
{
public:

    Note* root;
    std::string quality;
    SemitonePositions key;

    // Without the & the constructor uses the same address in memory to copy things into the instance,
    // so each root member would end up with the same address.
    Chord(Note &note, ChordQuality chordQuality);
    
    friend std::ostream &operator << (std::ostream &output, const Chord &chord);

};

#endif