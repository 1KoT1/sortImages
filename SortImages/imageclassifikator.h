#ifndef IMAGECLASSIFIKATOR_H
#define IMAGECLASSIFIKATOR_H

#include<memory>
#include<optional>
#include <QDirIterator>
#include <QObject>
#include "movetome.h"

class ImageClassifikator : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString showedImage READ showedImage NOTIFY showedImageChanged)
public:
	explicit ImageClassifikator(const QString &sourceDir, const QString &validDir, const QString &trashDir, QObject *parent = nullptr);

	const QString showedImage() const;

	Q_INVOKABLE void moveToTrash();
	Q_INVOKABLE void moveToValid();
	Q_INVOKABLE void revokeLastAction();
signals:
	void showedImageChanged();
public slots:
private:
	std::shared_ptr<QDirIterator> _sourceDir;
	QString _showedImage;
	MoveToMe _moveToValid;
	MoveToMe _moveToTrash;
	std::optional<MoveAction> _lastAction;
	void setShowedImage(const QString &newValue);
	void loadNextImage();
};

#endif // IMAGECLASSIFIKATOR_H
