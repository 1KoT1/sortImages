#include "movetome.h"

MoveToMe::MoveToMe(QDir baseDir) :
  _baseDir(baseDir), _currentSubDir(0)
{

}

MoveAction MoveToMe::from(const QString &filePath) {
	auto targetDir = getTargetDir(_baseDir);
	if(targetDir.count() > 1000) {
		++_currentSubDir;
		targetDir=getTargetDir(_baseDir);
	}
	auto action = MoveAction(filePath, targetDir.absoluteFilePath(QFileInfo(filePath).fileName()));
	QFile::rename(action.sourcePath(), action.targetPath());
	return action;
}

QDir MoveToMe::getTargetDir(QDir dir) {
	auto subdirName = QString::number(_currentSubDir);
	if(!dir.cd(subdirName)) {
		dir.mkdir(subdirName);
		dir.cd(subdirName);
	}
	return dir;
}
