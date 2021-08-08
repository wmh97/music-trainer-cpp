#ifndef KEY_SIGNATURES_H
#define KEY_SIGNATURES_H

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

    MajorKey(Note* &key, Note* sharpsOrFlats[]);

    friend std::ostream &operator << (std::ostream &output, const MajorKey* key);
};

#endif