#ifndef MUSIC_UTILS_H
#define MUSIC_UTILS_H

Intervals getAscendingInterval(Note* startNote, Note* endNote);

Intervals getDescendingInterval(Note* startNote, Note* endNote);

int incrementSemitonePosition(int &position, int increment);

#endif