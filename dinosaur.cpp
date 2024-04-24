#include "dinosaur.h"
#include <QPixmap>
#include <QVector>
#include <QMap>
#include "dinosaurbone.h"

///Reviewed by Ethan Heathcote
Dinosaur::Dinosaur() {}

Dinosaur::Dinosaur(QMap<DinosaurBone, QPixmap> bones, QMap<DinosaurBone, QPixmap> digBones)
    : bones(bones)
    , digBones(digBones)
    , complete(false)
{
    shuffleUnfoundBones();
}

QPixmap Dinosaur::getDigBone(DinosaurBone bone){
    return digBones[bone];
}

void Dinosaur::shuffleUnfoundBones(){

    // Adds the bones to the unfoundBones vector
    unfoundBones.append(DinosaurBone::head);
    unfoundBones.append(DinosaurBone::body);
    unfoundBones.append(DinosaurBone::tail);
    unfoundBones.append(DinosaurBone::legs);

    // Shuffles the Dinosaur Bones so they can be found in any order
    for(int i = 0; i < unfoundBones.size(); i++){
        int newIndex = rand() % unfoundBones.size();
        DinosaurBone tempBone = unfoundBones[newIndex];
        unfoundBones[newIndex] = unfoundBones[i];
        unfoundBones[i] = tempBone;
    }
}

DinosaurBone Dinosaur::getNextBone(DinosaurBone foundBone){
    // Adds the bone to found bones if there is one to add
    if (foundBone != DinosaurBone::none){
        foundBones[foundBone] = bones[foundBone];
        foundDigBones[foundBone] = digBones[foundBone];
    }

    if (unfoundBones.size() == 0){
        return DinosaurBone::none;
    }

    DinosaurBone nextBone = unfoundBones[0];
    unfoundBones.removeAt(0);

    return nextBone;
}

QMap<DinosaurBone, QPixmap> Dinosaur::getBoneImages(bool isDigBone){
    if(isDigBone){
        return foundDigBones;
    }

    if (complete){
        return bones;
    }

    return foundBones;
}

QPixmap Dinosaur::getBoneImage(DinosaurBone bone){
    if (bone == DinosaurBone::none){
        return QPixmap();
    }

    return bones[bone];
}
