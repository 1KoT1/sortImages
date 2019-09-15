#include "imageclassifikator.h"

using namespace std;

inline shared_ptr<QDirIterator> makeSourceDirIterator(const QString &sourceDir) {
	return make_shared<QDirIterator>(sourceDir, QStringList() << "*.jpg", QDir::NoFilter, QDirIterator::Subdirectories);
}

ImageClassifikator::ImageClassifikator(const QString &sourceDir, QObject *parent) :
  QObject(parent),
  _sourceDir(makeSourceDirIterator(sourceDir)),
  _showedImage(_sourceDir->next())
{

}

const QString ImageClassifikator::showedImage() const {
	return _showedImage;
}

void ImageClassifikator::moveToTrash() {
	loadNextImage();
}

void ImageClassifikator::moveToValid() {
	loadNextImage();
}

void ImageClassifikator::setShowedImage(const QString &newValue) {
	if(_showedImage != newValue){
		_showedImage = newValue;
		emit showedImageChanged();
	}
}

void ImageClassifikator::loadNextImage() {
	if(!_sourceDir->hasNext()) {
		_sourceDir = makeSourceDirIterator(_sourceDir->path());
	}
	setShowedImage(_sourceDir->next());
}
