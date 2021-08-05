#include <iostream>
#include <string>

enum SemitonePositions
{
    C = 0,
    D = 2,
    E = 4,
    F = 5,
    G = 7,
    A = 9,
    B = 11
};

enum Accidentals
{
    SHARP = 1,
    NATURAL = 0,
    FLAT = -1
};

enum ChordQuality
{
    MAJOR,
    MINOR,
    DIMINISHED
};

enum Intervals
{
    ASCENDING_MINOR_2ND = 1,
    ASCENDING_MAJOR_2ND = 2,
    ASCENDING_MINOR_3RD = 3,
    ASCENDING_MAJOR_3RD = 4,
    ASCENDING_PERFECT_4TH = 5,
    ASCENDING_TRITONE = 6,
    ASCENDING_PERFECT_5TH = 7,
    ASCENDING_MINOR_6TH = 8,
    ASCENDING_MAJOR_6TH = 9,
    ASCENDING_MINOR_7TH = 10,
    ASCENDING_MAJOR_7TH = 11,
    ASCENDING_OCTAVE = 12,

    DESCENDING_MINOR_2ND = -1,
    DESCENDING_MAJOR_2ND = -2,
    DESCENDING_MINOR_3RD = -3,
    DESCENDING_MAJOR_3RD = -4,
    DESCENDING_PERFECT_4TH = -5,
    DESCENDING_TRITONE = -6,
    DESCENDING_PERFECT_5TH = -7,
    DESCENDING_MINOR_6TH = -8,
    DESCENDING_MAJOR_6TH = -9,
    DESCENDING_MINOR_7TH = -10,
    DESCENDING_MAJOR_7TH = -11,
    DESCENDING_OCTAVE = -12
};

class Note
{
public:
    int semitonePosition;
    char note[2] = {'0'}; 

    Note(SemitonePositions position, Accidentals accidental)
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

    int operator + (Note endNote)
    {
        /*
            Return the absolute interval between two notes.
        */
        return std::abs(this->semitonePosition - endNote.semitonePosition);
    }

    bool operator == (Note otherNote)
    {
        if(semitonePosition == otherNote.semitonePosition) return true;
        return false;
    }

    friend std::ostream &operator << (std::ostream &output, const Note note)
    {   
        if(note.note[1] != '0')
        {
            output << note.semitonePosition << " " << note.note[0] << note.note[1];
            return output;
        }
        output << note.semitonePosition << " " << note.note[0];
        return output;
    }
};

class Chord
{
public:

    Note* root;
    std::string quality;
    SemitonePositions key;

    // Without the & the constructor uses the same address in memory to copy things into the instance,
    // so each root member would end up with the same address.
    Chord(Note &note, ChordQuality chordQuality)
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
    
    friend std::ostream &operator << (std::ostream &output, const Chord &chord)
    {   
        output << *chord.root << chord.quality;
        return output;
    }

};

class MajorKey
{
public:
    Note* firstDegree;
    Note* secondDegree;
    Note* thirdDegree;
    Note* fourthDegree;
    Note* fifthDegree;
    Note* sixthDegree;
    Note* seventhDegree;

    MajorKey(Note* key)
    {
        this->firstDegree = key;
    }
};

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

    static void printNote(Note* note);
    static Intervals getAscendingInterval(Note* startNote, Note* endNote);
    static Intervals getDescendingInterval(Note* startNote, Note* endNote);
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

void Notes::printNote(Note* note)
{
    std::cout << *note << std::endl;
}

Intervals Notes::getAscendingInterval(Note* startNote, Note* endNote)
{
    return Intervals(*startNote + *endNote);
}

Intervals Notes::getDescendingInterval(Note* startNote, Note* endNote)
{
    return Intervals((*startNote + *endNote)-12);
}

int main()
{

    Notes::printNote(Notes::C_FLAT);


    std::cout << Notes::getAscendingInterval(Notes::C_NATURAL, Notes::B_FLAT) << std::endl;
    std::cout << Notes::getDescendingInterval(Notes::E_NATURAL, Notes::C_NATURAL) << std::endl;
    std::cout<< Notes::getAscendingInterval(Notes::F_NATURAL, Notes::B_FLAT);


    return 0;
}