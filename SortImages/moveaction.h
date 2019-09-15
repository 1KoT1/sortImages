#ifndef MOVEACTION_H
#define MOVEACTION_H

#include <QString>

class MoveAction {
public:
	MoveAction (QString sourcePath, QString targetPath) :
	  _sourcePath(sourcePath), _targetPath(targetPath){}
	const QString &sourcePath() const { return _sourcePath; }
	const QString &targetPath() const { return _targetPath; }
private:
	QString _sourcePath;
	QString _targetPath;
};

#endif // MOVEACTION_H
