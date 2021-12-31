import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtMultimedia 5.15

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

     Item {
         property int itemW : 100
         property int itemH : 100
         width: parent.width - itemW
         height: parent.height - itemH
         anchors.centerIn: parent
         Camera {
             id: camera
             imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

             exposure {//Methods and properties for adjusting exposure (aperture, shutter speed etc).
                 exposureCompensation: -1.0
                 exposureMode: Camera.ExposurePortrait
             }

             flash.mode: Camera.FlashRedEyeReduction

             imageCapture {//This type allows you to capture still images and be notified when they are available or saved to disk.
                 onImageCaptured: {
                     photoPreview.source = preview  // Show the preview in an Image
                 }
             }
         }

         VideoOutput {
             source: camera
             anchors.fill: parent
             focus : visible // to receive focus and capture key events when visible
         }

         Image {
             id: photoPreview
         }
     }

}
