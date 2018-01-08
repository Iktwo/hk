import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Window 2.10
import QtQuick.Dialogs 1.3
import Qt.labs.settings 1.0
import com.iktwo.health 1.0 as Health
import QtQuick.Shapes 1.0

ApplicationWindow {
    id: window

    visible: true
    width: 640
    height: 480
    title: qsTr("Health")

    menuBar: MenuBar {
        id: menuBar

        Menu {
            title: qsTr("&File")

            Action {
                text: qsTr("&Open...")
                shortcut: "Ctrl+O"
                onTriggered: fileDialog.open()
            }
        }
    }

    Rectangle {
        anchors {
            top: menuBar.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        color: "#3498db"

        GridView {
            id: gridView

            anchors.fill: parent

            cellHeight: width / 4
            cellWidth: width / 4

            delegate: Item {
                height: gridView.cellHeight
                width: gridView.cellWidth

              ProgressCircle {
                  anchors.centerIn: parent
                  value: model.duration.toFixed(2) / 30
                  color: "#34db98"
                  rotation: -90
              }

              Label {
                  anchors.centerIn: parent
                  text: model.duration.toFixed(2)
              }
            }

            model: healthData.workouts
        }
    }

    Health.HealthData {
        id: healthData

        onWorkoutsChanged: console.log(workouts.count)
    }

    Settings {
        id: settings

        property alias x: window.x
        property alias y: window.y
        property alias width: window.width
        property alias height: window.height
        property alias folder: fileDialog.folder
        property string fileUrl: ""
    }

    FileDialog {
        id: fileDialog

        title: "Please choose a health data file (export.xml)"

        folder: shortcuts.home
        selectMultiple: false
        selectExisting: true
        selectFolder: false

        nameFilters: ["Health Data (export.xml)"]

        onAccepted: {
            healthData.open(fileUrl)
            settings.fileUrl = fileUrl
        }
    }

    Component.onCompleted: {
        if (settings.fileUrl != "") {
            healthData.open(settings.fileUrl)
        }
    }
}
