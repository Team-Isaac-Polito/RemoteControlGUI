import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    property int num: 67

    id: root
    width: 800
    height: 480
    visible: true

    //signals for data changed
    signal rangeChanged()
    signal batteryChanged()

    //background
    Image {
        source: "images/Remote.png"
    }

    //first module
    Text {
        id: battery1
        text: backEnd.batteryVoltage1 + "%"
        font.family: "Staatliches"
        font.pointSize: 15
        color: "#2D3C53"
        transformOrigin: Item.TopLeft
        x: 130
        y: 87
    }

    MyRange {
        id: speed1_sx

        property int rangeValue: backEnd.motorSpeed_sx1
        first.value: rangeValue<50 ? rangeValue : 50
        second.value: rangeValue<50 ? 50 : rangeValue

        x: 75
        y: 48
    }

    MyRange {
        id: speed1_dx

        property int rangeValue: backEnd.motorSpeed_dx1
        first.value: rangeValue<50 ? rangeValue : 50
        second.value: rangeValue<50 ? 50 : rangeValue

        x: 242
        y: 48
    }

    //second module
    Text {
        id: battery2
        text: backEnd.batteryVoltage2 + "%"
        font.family: "Staatliches"
        font.pointSize: 15
        color: "#2D3C53"
        transformOrigin: Item.TopLeft
        x: 130
        y: 227
    }

    MyRange {
        id: speed2_sx

        property int rangeValue: backEnd.motorSpeed_sx2
        first.value: rangeValue<50 ? rangeValue : 50
        second.value: rangeValue<50 ? 50 : rangeValue

        x: 75
        y: 178
    }

    MyRange {
        id: speed2_dx

        property int rangeValue: backEnd.motorSpeed_dx2
        first.value: rangeValue<50 ? rangeValue : 50
        second.value: rangeValue<50 ? 50 : rangeValue

        x: 242
        y: 178
    }


    //third module
    Text {
        id: battery3
        text: backEnd.batteryVoltage3 + "%"
        font.family: "Staatliches"
        font.pointSize: 15
        color: "#2D3C53"
        transformOrigin: Item.TopLeft
        x: 130
        y: 367
    }

    MyRange {
        id: speed3_sx

        property int rangeValue: backEnd.motorSpeed_sx3
        first.value: rangeValue<50 ? rangeValue : 50
        second.value: rangeValue<50 ? 50 : rangeValue

        x: 75
        y: 318
    }
    MyRange {
        id: speed3_dx

        property int rangeValue: backEnd.motorSpeed_dx3
        first.value: rangeValue<50 ? rangeValue : 50
        second.value: rangeValue<50 ? 50 : rangeValue

        x: 242
        y: 318
    }
}
