#ifndef MOVETOME_H
#define MOVETOME_H

#include <QDir>
#include "moveaction.h"

class MoveToMe {
public:
	MoveToMe(QDir baseDir);
	MoveAction from(const QString &filePath);
private:
	QDir _baseDir;
	uint _currentSubDir;
	QDir getTargetDir(QDir dir);
};

#endif // MOVETOME_H
