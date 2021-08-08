#ifndef BARS_AND_PIECES_H
#define BARS_AND_PIECES_H

class Bar
{
public:
    TimeSignatures timeSignature;
    int numberOfBeats;
    Chord** beats; // ** means pointer to pointer - this will be an array of pointers which will be dynamically allocated.

    Bar(TimeSignatures timeSig);
    
    void addChordAtBeat(Chord* &chord, int beat);

    friend std::ostream &operator << (std::ostream &output, const Bar &bar);
};

class Piece
{
public:
    std::string pieceTitle = "";

    TimeSignatures timeSignature;
    std::vector<Bar> bars;

    Chord* latestChord = nullptr;
    std::vector<Intervals> intervals;


    Piece(TimeSignatures timeSig);

    Piece(std::string title, TimeSignatures timeSig);

    void addBar(Bar &bar);

    void printIntervals();

    friend std::ostream &operator << (std::ostream &output, const Piece &piece);

};

#endif