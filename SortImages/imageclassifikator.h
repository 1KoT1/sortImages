#ifndef IMAGECLASSIFIKATOR_H
#define IMAGECLASSIFIKATOR_H

#include <QDirIterator>
#include <QObject>

class ImageClassifikator : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString showedImage READ showedImage NOTIFY showedImageChanged)
public:
	explicit ImageClassifikator(const QString &sourceDir, QObject *parent = nullptr);

	const QString showedImage() const;

	Q_INVOKABLE void moveToTrash();
	Q_INVOKABLE void moveToValid();
signals:
	void showedImageChanged();
public slots:
private:
	QDirIterator _sourceDir;
	QString _showedImage;
	void setShowedImage(const QString &newValue);
};

#endif // IMAGECLASSIFIKATOR_H
