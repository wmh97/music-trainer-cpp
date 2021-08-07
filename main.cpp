#include <iostream>
#include <string>
#include <vector>

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

int incrementSemitonePosition(int &position, int increment);

class MajorKey
{
public:
    Chord* firstDegree;
    Chord* secondDegree;
    Chord* thirdDegree;
    Chord* fourthDegree;
    Chord* fifthDegree;
    Chord* sixthDegree;
    Chord* seventhDegree;

    MajorKey(Note* &key, Note* sharpsOrFlats[])
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

    friend std::ostream &operator << (std::ostream &output, const MajorKey* key)
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

// more to be added.
enum TimeSignatures
{
    FOUR_FOUR = 44,
    THREE_FOUR = 34
};

class Bar
{
public:
    TimeSignatures timeSignature;
    int numberOfBeats;
    Chord** beats; // ** means pointer to pointer - this will be an array of pointers which will be dynamically allocated.

    Bar(TimeSignatures timeSig)
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

    void addChordAtBeat(Chord* &chord, int beat)
    {   
        if(beat > numberOfBeats)
        {
            std::cout << "Beat position invalid" << std::endl;
            return;
        }

        beat -= 1; // the beats 
        this->beats[beat] = chord; // setting the chord to the beat of the bar specified.
    }

    friend std::ostream &operator << (std::ostream &output, const Bar &bar)
    {   
        for (int i = 0; i < bar.numberOfBeats; i++)
        {
            output << *bar.beats[i] << " ";
        }
        return output;
    }
};

class Piece
{
public:
    std::string pieceTitle = "";

    TimeSignatures timeSignature;
    std::vector<Bar> bars;

    Chord* latestChord = nullptr;
    std::vector<Intervals> intervals;


    Piece(TimeSignatures timeSig)
    {
        this->timeSignature = timeSig;
    }

    Piece(std::string title, TimeSignatures timeSig)
    {
        this->pieceTitle = title;
        this->timeSignature = timeSig;
    }

    void addBar(Bar &bar)
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

    void printIntervals()
    {
        std::cout << "Intervals: " << std::endl;
        for(Intervals interval : this->intervals)
        {
            std::cout << interval;
        }
    }

    friend std::ostream &operator << (std::ostream &output, const Piece &piece)
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

};

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

    return 0;
}