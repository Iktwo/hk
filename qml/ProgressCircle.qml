import QtQuick 2.4

Canvas {
    id: root

    property color color: "#3aadd9"
    property color backgroundColor: "#e5e6e8"
    property double value: 0
    property real backgroundLineWidth: _radius / 14
    property real progressLineWidth: _radius / 13
    property alias animationEnabled: behaviorOnValue.enabled
    property point _center: Qt.point(width / 2, height / 2)
    property real _radius: Math.min(width / 2, height / 2.15)

    antialiasing: true

    height: 200
    width: 200

    onValueChanged: requestPaint()
    onColorChanged: requestPaint()
    onBackgroundColorChanged: requestPaint()

    onPaint: {
        var start_angle = 0
        var end_angle = Math.PI * 2
        var ctx = getContext('2d')

        ctx.reset()
        ctx.clearRect(0, 0, width, height)

        ctx.strokeStyle = backgroundColor
        ctx.lineWidth = backgroundLineWidth

        ctx.beginPath()
        ctx.arc(_center.x, _center.y, _radius, start_angle, end_angle)
        ctx.stroke()

        start_angle = 0
        end_angle = Math.PI * value * 2

        ctx.strokeStyle = color
        ctx.lineWidth = progressLineWidth

        ctx.beginPath()
        ctx.arc(_center.x, _center.y, _radius, start_angle, end_angle)
        ctx.stroke()
    }

    Behavior on value { id: behaviorOnValue; NumberAnimation { } }
}
