import QtQuick 2.12
import MinersCoffee 1.0
import QtQuick.Studio.Effects 1.0
import QtQuick.Layouts 1.11
import QtQuick.Studio.Components 1.0
import QtQuick3D 1.15
import QtQuick.Studio.MultiText 1.0
import QtQuick.Controls 2.15
import QtQuick.Studio.LogicHelper 1.0
import Qt.SafeRenderer 1.1

Rectangle {
    id: ocRectangle
    width: Constants.width
    height: Constants.height
    color: "#ffffff"

    ComboBox {
        id: gpuSelectionComboBox
        x: 500
        y: 145
        width: 281
        height: 39
        font.family: "Arial"
    }

    Button {
        id: applyButton
        x: 500
        y: 547
        width: 122
        height: 35
        text: qsTr("Apply")
        flat: false
        highlighted: false
        font.family: "Arial"
    }

    Button {
        id: resetButton
        x: 659
        y: 547
        width: 122
        height: 35
        text: qsTr("Reset")
        highlighted: false
        font.family: "Arial"
        flat: false
    }

    GridLayout {
        id: gridLayout
        x: 307
        y: 202
        width: 666
        height: 316
        flow: GridLayout.TopToBottom
        rows: 5
        columns: 4

        Text {
            id: titleText0
            width: 40
            color: "#000000"
            text: qsTr("Item")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            Layout.maximumWidth: 200
            Layout.preferredWidth: 200
            Layout.fillWidth: true
            rightPadding: 0
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: gpuFreqText
            color: "#000000"
            text: qsTr("GPU Frequency Limit (MHz)")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: vramFreqText
            color: "#000000"
            text: qsTr("VRAM Frequency (MHz)")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: fanSpeedText
            color: "#000000"
            text: qsTr("Fan Speed (%)")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: powerText
            color: "#000000"
            text: qsTr("Power Limit (%)")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: titleText1
            width: 80
            color: "#000000"
            text: qsTr("Current")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.NoWrap
            Layout.maximumWidth: 200
            Layout.preferredWidth: 40
            Layout.fillWidth: true
            rightPadding: 0
            padding: 0
            leftPadding: 0
            font.family: "Arial"
            fontSizeMode: Text.FixedSize
            styleColor: "#ffffff"
        }

        Text {
            id: gpuFreqValueText
            width: 30
            color: "#000000"
            text: qsTr("1800")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: vramFreqValueText
            width: 30
            color: "#000000"
            text: qsTr("8000")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: fanSpeedValueText
            width: 30
            color: "#000000"
            text: qsTr("90")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: powerValueText
            width: 30
            color: "#000000"
            text: qsTr("100")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: titleText2
            width: 80
            color: "#000000"
            text: qsTr("Recommended")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.NoWrap
            Layout.maximumWidth: 200
            Layout.preferredWidth: 40
            Layout.fillWidth: true
            rightPadding: 0
            font.family: "Arial"
            fontSizeMode: Text.FixedSize
            styleColor: "#ffffff"
        }

        Text {
            id: gpuFreqRecText
            width: 30
            color: "#000000"
            text: qsTr("1800")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: vramFreqRecText
            width: 30
            color: "#000000"
            text: qsTr("8000")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: fanSpeedRecText
            width: 30
            color: "#000000"
            text: qsTr("90")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: powerRecText
            width: 30
            color: "#000000"
            text: qsTr("100")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            fontSizeMode: Text.HorizontalFit
            styleColor: "#ffffff"
        }

        Text {
            id: titleText3
            width: 80
            color: "#000000"
            text: qsTr("New")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.NoWrap
            Layout.maximumWidth: 200
            Layout.preferredWidth: 40
            Layout.fillWidth: true
            rightPadding: 0
            bottomPadding: 0
            font.family: "Arial"
            fontSizeMode: Text.FixedSize
            styleColor: "#ffffff"
        }

        TextInput {
            id: gpuFreqTextInput
            width: 35
            height: 20
            color: "#000000"
            text: qsTr("2000")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            selectByMouse: true
            readOnly: false
            maximumLength: 5
            selectedTextColor: "#ffffff"
            selectionColor: "#000080"
        }

        TextInput {
            id: vramFreqTextInput
            width: 35
            height: 20
            color: "#000000"
            text: qsTr("8200")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            selectByMouse: true
            readOnly: false
            maximumLength: 5
            selectedTextColor: "#ffffff"
            selectionColor: "#000080"
        }

        TextInput {
            id: fanSpeedTextInput
            width: 35
            height: 20
            color: "#000000"
            text: qsTr("95")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            selectByMouse: true
            readOnly: false
            maximumLength: 5
            selectedTextColor: "#ffffff"
            selectionColor: "#000080"
        }

        TextInput {
            id: powerLimitTextInput
            width: 35
            height: 20
            color: "#000000"
            text: qsTr("65")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: 200
            Layout.fillWidth: true
            font.family: "Arial"
            selectByMouse: true
            readOnly: false
            maximumLength: 5
            selectedTextColor: "#ffffff"
            selectionColor: "#000080"
        }
    }
}
