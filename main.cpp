#include <iostream>
#include <string>
#include <vector>
#include "musicalConstants.h"
#include "notesAndChords.h"
#include "musicUtils.h"
#include "keySignatures.h"
#include "barsAndPieces.h"
#include "linkedList.h"

struct Notes
{
    static Note* C_NATURAL;
    static Note* C_SHARP; 
    static Note* C_FLAT;

    static Note* D_NATURAL;
    static Note* D_SHARP;
    static Note* D_FLAT;

    static Note* E_NATURAL;
    static Note* E_SHARP;
    static Note* E_FLAT;

    static Note* F_NATURAL;
    static Note* F_SHARP;
    static Note* F_FLAT;

    static Note* G_NATURAL;
    static Note* G_SHARP;
    static Note* G_FLAT;

    static Note* A_NATURAL;
    static Note* A_SHARP;
    static Note* A_FLAT;

    static Note* B_NATURAL;
    static Note* B_SHARP;
    static Note* B_FLAT;

    static Note* ALL_NOTES_FLATS[12];
    static Note* ALL_NOTES_SHARPS[12];
};

Note* Notes::C_NATURAL = new Note(SemitonePositions::C, Accidentals::NATURAL);
Note* Notes::C_SHARP = new Note(SemitonePositions::C, Accidentals::SHARP);
Note* Notes::C_FLAT = new Note(SemitonePositions::C, Accidentals::FLAT);

Note* Notes::D_NATURAL = new Note(SemitonePositions::D, Accidentals::NATURAL);
Note* Notes::D_SHARP = new Note(SemitonePositions::D, Accidentals::SHARP);
Note* Notes::D_FLAT = new Note(SemitonePositions::D, Accidentals::FLAT);

Note* Notes::E_NATURAL = new Note(SemitonePositions::E, Accidentals::NATURAL);
Note* Notes::E_SHARP = new Note(SemitonePositions::E, Accidentals::SHARP);
Note* Notes::E_FLAT = new Note(SemitonePositions::E, Accidentals::FLAT);

Note* Notes::F_NATURAL = new Note(SemitonePositions::F, Accidentals::NATURAL);
Note* Notes::F_SHARP = new Note(SemitonePositions::F, Accidentals::SHARP);
Note* Notes::F_FLAT = new Note(SemitonePositions::F, Accidentals::FLAT);

Note* Notes::G_NATURAL = new Note(SemitonePositions::G, Accidentals::NATURAL);
Note* Notes::G_SHARP = new Note(SemitonePositions::G, Accidentals::SHARP);
Note* Notes::G_FLAT = new Note(SemitonePositions::G, Accidentals::FLAT);

Note* Notes::A_NATURAL = new Note(SemitonePositions::A, Accidentals::NATURAL);
Note* Notes::A_SHARP = new Note(SemitonePositions::A, Accidentals::SHARP);
Note* Notes::A_FLAT = new Note(SemitonePositions::A, Accidentals::FLAT);

Note* Notes::B_NATURAL = new Note(SemitonePositions::B, Accidentals::NATURAL);
Note* Notes::B_SHARP = new Note(SemitonePositions::B, Accidentals::SHARP);
Note* Notes::B_FLAT = new Note(SemitonePositions::B, Accidentals::FLAT);

Note* Notes::ALL_NOTES_SHARPS[12] = {
    Notes::C_NATURAL, Notes::C_SHARP, Notes::D_NATURAL,
    Notes::D_SHARP, Notes::E_NATURAL, Notes::F_NATURAL,
    Notes::F_SHARP, Notes::G_NATURAL, Notes::G_SHARP,
    Notes::A_NATURAL, Notes::A_SHARP, Notes::B_NATURAL
};

Note* Notes::ALL_NOTES_FLATS[12] = {
    Notes::C_NATURAL, Notes::D_FLAT, Notes::D_NATURAL,
    Notes::E_FLAT, Notes::E_NATURAL, Notes::F_NATURAL,
    Notes::G_FLAT, Notes::G_NATURAL, Notes::A_FLAT,
    Notes::A_NATURAL, Notes::B_FLAT, Notes::B_NATURAL
};

struct MajorKeys
{
    static MajorKey* C_MAJOR;
    static MajorKey* D_MAJOR;
    static MajorKey* E_MAJOR;
    static MajorKey* F_MAJOR;
    static MajorKey* G_MAJOR;
    static MajorKey* A_MAJOR;
    static MajorKey* B_MAJOR;  

    static MajorKey* C_SHARP_MAJOR;
    static MajorKey* D_SHARP_MAJOR;
    static MajorKey* F_SHARP_MAJOR;
    static MajorKey* G_SHARP_MAJOR;
    static MajorKey* A_SHARP_MAJOR;   

    static MajorKey* D_FLAT_MAJOR;
    static MajorKey* E_FLAT_MAJOR;
    static MajorKey* G_FLAT_MAJOR;
    static MajorKey* A_FLAT_MAJOR;
    static MajorKey* B_FLAT_MAJOR;         
};

MajorKey* MajorKeys::C_MAJOR = new MajorKey(Notes::C_NATURAL, Notes::ALL_NOTES_SHARPS);
MajorKey* MajorKeys::D_MAJOR = new MajorKey(Notes::D_NATURAL, Notes::ALL_NOTES_SHARPS);
MajorKey* MajorKeys::E_MAJOR = new MajorKey(Notes::E_NATURAL, Notes::ALL_NOTES_SHARPS);
MajorKey* MajorKeys::F_MAJOR = new MajorKey(Notes::F_NATURAL, Notes::ALL_NOTES_FLATS);
MajorKey* MajorKeys::G_MAJOR = new MajorKey(Notes::G_NATURAL, Notes::ALL_NOTES_SHARPS);
MajorKey* MajorKeys::A_MAJOR = new MajorKey(Notes::A_NATURAL, Notes::ALL_NOTES_SHARPS);
MajorKey* MajorKeys::B_MAJOR = new MajorKey(Notes::B_NATURAL, Notes::ALL_NOTES_SHARPS);

MajorKey* MajorKeys::C_SHARP_MAJOR = new MajorKey(Notes::C_SHARP, Notes::ALL_NOTES_SHARPS);
MajorKey* MajorKeys::D_SHARP_MAJOR = new MajorKey(Notes::D_SHARP, Notes::ALL_NOTES_SHARPS);
MajorKey* MajorKeys::F_SHARP_MAJOR = new MajorKey(Notes::F_SHARP, Notes::ALL_NOTES_SHARPS);
MajorKey* MajorKeys::G_SHARP_MAJOR = new MajorKey(Notes::G_SHARP, Notes::ALL_NOTES_SHARPS);
MajorKey* MajorKeys::A_SHARP_MAJOR = new MajorKey(Notes::A_SHARP, Notes::ALL_NOTES_SHARPS);

MajorKey* MajorKeys::D_FLAT_MAJOR = new MajorKey(Notes::D_FLAT, Notes::ALL_NOTES_FLATS);
MajorKey* MajorKeys::E_FLAT_MAJOR = new MajorKey(Notes::E_FLAT, Notes::ALL_NOTES_FLATS);
MajorKey* MajorKeys::G_FLAT_MAJOR = new MajorKey(Notes::G_FLAT, Notes::ALL_NOTES_FLATS);
MajorKey* MajorKeys::A_FLAT_MAJOR = new MajorKey(Notes::A_FLAT, Notes::ALL_NOTES_FLATS);
MajorKey* MajorKeys::B_FLAT_MAJOR = new MajorKey(Notes::B_FLAT, Notes::ALL_NOTES_FLATS);

int main()
{
    std::cout << getAscendingInterval(Notes::C_NATURAL, Notes::B_FLAT) << std::endl;
    std::cout << getDescendingInterval(Notes::E_NATURAL, Notes::C_NATURAL) << std::endl;
    std::cout<< getAscendingInterval(Notes::F_NATURAL, Notes::B_FLAT) << std::endl;

    std::cout << MajorKeys::C_MAJOR->firstDegree->root << " == " << Notes::C_NATURAL << std::endl;

    std::cout << MajorKeys::C_MAJOR;
    std::cout << MajorKeys::D_MAJOR;

    Bar bar(TimeSignatures::FOUR_FOUR);

    bar.addChordAtBeat(MajorKeys::C_MAJOR->firstDegree, 1);
    bar.addChordAtBeat(MajorKeys::C_MAJOR->secondDegree, 2);
    bar.addChordAtBeat(MajorKeys::C_MAJOR->thirdDegree, 3);
    bar.addChordAtBeat(MajorKeys::C_MAJOR->fourthDegree, 4);

    std::cout << "Bar: " << std::endl;
    std::cout << bar << std::endl;

    Piece piece("ABCDEFG", TimeSignatures::FOUR_FOUR);
    piece.addBar(bar);
    piece.addBar(bar);
    std::cout << piece;

    piece.printIntervals();
    std::cout << std::endl;

    // testing linked list - need to templatise this.
    // linked list take the place of the vector that currently stores
    // the intervals of between the chord changes.
    LinkedList ll;
    ll.addNodeValue(1);
    ll.addNodeValue(2);
    ll.addNodeValue(3);
    ll.addNodeValue(4);
    ll.addNodeValue(5);
    ll.printList();
    ll.deleteNodeAtIndex(2);
    ll.printList();


    return 0;
}