#include "imageclassifikator.h"

ImageClassifikator::ImageClassifikator(const QString &sourceDir, QObject *parent) :
  QObject(parent),
  _sourceDir(sourceDir, QStringList() << "*.jpg", QDir::NoFilter, QDirIterator::Subdirectories),
  _showedImage(_sourceDir.next())
{

}

const QString ImageClassifikator::showedImage() const {
	return _showedImage;
}

void ImageClassifikator::moveToTrash() {
	setShowedImage(_sourceDir.next());
}

void ImageClassifikator::moveToValid() {
	setShowedImage(_sourceDir.next());
}

void ImageClassifikator::setShowedImage(const QString &newValue) {
	if(_showedImage != newValue){
		_showedImage = newValue;
		emit showedImageChanged();
	}
}
