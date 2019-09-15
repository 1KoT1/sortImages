#include "imageclassifikator.h"

using namespace std;

inline shared_ptr<QDirIterator> makeSourceDirIterator(const QString &sourceDir) {
	return make_shared<QDirIterator>(sourceDir, QStringList() << "*.jpg", QDir::NoFilter, QDirIterator::Subdirectories);
}

ImageClassifikator::ImageClassifikator(const QString &sourceDir, const QString &validDir, const QString &trashDir, QObject *parent) :
  QObject(parent),
  _sourceDir(makeSourceDirIterator(sourceDir)),
  _showedImage(_sourceDir->next()),
  _moveToValid(validDir),
  _moveToTrash(trashDir),
  _lastAction(nullopt)
{

}

const QString ImageClassifikator::showedImage() const {
	return _showedImage;
}

void ImageClassifikator::moveToTrash() {
	_lastAction = _moveToTrash.from(showedImage());
	loadNextImage();
}

void ImageClassifikator::moveToValid() {
	_lastAction = _moveToValid.from(showedImage());
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

void ImageClassifikator::revokeLastAction() {
	if(_lastAction) {
		auto action = _lastAction.value();
		QFile::rename(action.targetPath(), action.sourcePath());
		_lastAction.reset();
		setShowedImage(action.sourcePath());
	}
}
