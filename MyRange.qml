import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as T


T.RangeSlider {
    id: control
    property int newWidth: 20
    property int newHeight: 10
    from: 0
    to: 100

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            first.implicitHandleWidth + leftPadding + rightPadding,
                            second.implicitHandleWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             first.implicitHandleHeight + topPadding + bottomPadding,
                             second.implicitHandleHeight + topPadding + bottomPadding)

    padding: 6
    rotation: 90
    scale: 0.55
    transformOrigin: Item.TopLeft

    first.handle: Rectangle {
        x: control.leftPadding + (control.horizontal ? control.first.visualPosition * (control.availableWidth - width) : (control.availableWidth - width) / 2)
        y: control.topPadding + (control.horizontal ? (control.availableHeight - height) / 2 : control.first.visualPosition * (control.availableHeight - height))
        implicitWidth: newHeight
        implicitHeight: newWidth
        border.width: activeFocus ? 2 : 1
        border.color: "#50b4b5"
        color: "#50b4b5"
    }

    second.handle: Rectangle {
        x: control.leftPadding + (control.horizontal ? control.second.visualPosition * (control.availableWidth - width) : (control.availableWidth - width) / 2)
        y: control.topPadding + (control.horizontal ? (control.availableHeight - height) / 2 : control.second.visualPosition * (control.availableHeight - height))
        implicitWidth: newHeight
        implicitHeight: newWidth
        border.width: activeFocus ? 2 : 1
        border.color: "#50b4b5"
        color: "#50b4b5"
    }

    background: Rectangle {
        x: control.leftPadding + (control.horizontal ? 0 : (control.availableWidth - width) / 2)
        y: control.topPadding + (control.horizontal ? (control.availableHeight - height) / 2 : 0)
        implicitWidth: control.horizontal ? 200 : newWidth
        implicitHeight: control.horizontal ? newWidth : 200
        width: control.horizontal ? control.availableWidth : implicitWidth
        height: control.horizontal ? implicitHeight : control.availableHeight
        radius: 3
        color: "#eeeaea"
        scale: control.horizontal && control.mirrored ? -1 : 1

        Rectangle {
            x: control.horizontal ? control.first.position * parent.width + 3 : 0
            y: control.horizontal ? 0 : control.second.visualPosition * parent.height + 3
            width: control.horizontal ? control.second.position * parent.width - control.first.position * parent.width - 6 : 6
            height: control.horizontal ? newWidth : control.second.position * parent.height - control.first.position * parent.height - newWidth

            color: "#50b4b5"
        }
    }
}
