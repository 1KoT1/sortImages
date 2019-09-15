#include "imageclassifikator.h"

ImageClassifikator::ImageClassifikator(QObject *parent) : QObject(parent) {

}

const QString ImageClassifikator::showedImage() const {
	return "test";
}

void ImageClassifikator::moveToTrash() {

}

void ImageClassifikator::moveToValid() {

}
