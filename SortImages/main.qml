import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 1.6

Window {
	id: window
	visible: true
	width: 640
	height: 480
	title: qsTr("Сортировать востановленные картинки.")

	Button {
		id: moveToTrashBtn
		y: 0
		text: qsTr("<- В мусор")
		anchors.left: parent.left
		anchors.right: parent.horizontalCenter
		onClicked: imageClassifikator.moveToTrash()
	}

	Button {
		id: moveToValidBtn
		y: 0
		text: qsTr("В отобранные ->")
		anchors.left: parent.horizontalCenter
		anchors.right: parent.right
		onClicked: imageClassifikator.moveToValid()
	}

	Button {
		id: revokeLastActionBtn
		text: qsTr("Отменить")
		anchors.left: parent.left
		anchors.right: parent.right
		anchors.top: moveToTrashBtn.bottom
		onClicked: imageClassifikator.revokeLastAction()
	}

	Image {
		id: currentImage
		source: "file:" + imageClassifikator.showedImage
		anchors.left: parent.left
		anchors.right: parent.right
		anchors.top: revokeLastActionBtn.bottom
		anchors.bottom: parent.bottom
		fillMode: Image.PreserveAspectFit

		focus: true
		Keys.onLeftPressed: imageClassifikator.moveToTrash()
		Keys.onRightPressed: imageClassifikator.moveToValid()
	}
}
