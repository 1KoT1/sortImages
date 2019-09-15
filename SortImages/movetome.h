#ifndef MOVETOME_H
#define MOVETOME_H

#include <QDir>

class MoveToMe {
public:
	MoveToMe(QDir baseDir);
	void from(const QString &filePath);
private:
	QDir _baseDir;
	uint _currentSubDir;
	QDir getTargetDir(QDir dir);
};

#endif // MOVETOME_H
