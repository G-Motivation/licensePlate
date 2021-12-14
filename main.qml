import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
import QtQuick.Layouts 6.0


Window {
    id: myMainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("License plate monitoring and payment system")


    color: Constants.backgroundColor
    TabBar {
        id: bar
        width: parent.width

        TabButton {
            width: implicitWidth
            text: qsTr("Home")
        }
        TabButton {
            width: implicitWidth
            text: qsTr("Discover")
        }
        TabButton {
            width: implicitWidth
            text: qsTr("Payment")
        }
    }

    StackLayout {
        width: parent.width
        currentIndex: bar.currentIndex
        Item {
            id: homeTab
            Text {
                text: "<b>1</b> <i>World!</i>"
            }
        }
        Item {
            id: discoverTab
            Text {
                text: "<b>2</b> <i>World!</i>"
            }

        }
        Item {
            id: activityTab
            Button {
                objectName: "buttonTest"
                text: "Open"
            }
            Text {
                text: "<b>3</b> <i>World!</i>"
            }


        }
    }
//    Text {
//        id:  nick
//        text: "<b>Hello</b> <i>World!</i>"
//    }
}
