import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Donatello")

    Rectangle {
        id: turtleShape
        width: 20
        height: 30
        color: "green"

        //accessing turtle object x, y, and angle values. Default values (top left corner in window with 0 degree angle) if turtle object not yet avaialble
        x: turtle ? turtle.x : 0
        y: turtle ? turtle.y : 0
        rotation: turtle ? turtle.angle : 0
    }

    //QML element defines drawable surface, Canvas, for rendering items to be drawn
    Canvas {
        id: drawingCanvas

        //Canvas size same as window size
        anchors.fill: parent

        //empty list for storing lines to be drawn
        property var lines: []

        //function to add a line and request Canvas repaint
        function addLine(startX, startY, endX, endY) {
            lines.push({ startX: startX, startY: startY, endX: endX, endY: endY });
            requestPaint(); //triggering Canvas paint
        }

        //event handler trigger when Canvas need to be repainted
        onPaint: {
            var ctx = getContext("2d"); //setting up the 2D drawing context for the Canvas

            ctx.beginPath(); //defining everything to drawn until stroke()
            ctx.strokeStyle = "black"; //setting line colour
            ctx.lineWidth = 2; //setting line width

            for (var i = 0; i < lines.length; i++) { //looping through all stored lines to be drawn on the Canvas
                var line = lines[i]; //accessing current line element
                ctx.moveTo(line.startX, line.startY); //starting point of line
                ctx.lineTo(line.endX, line.endY); //ending point of line
            }

            ctx.stroke(); //draw everything on Canvas since beginPath()
        }
    }

    //establishing connection between the turtle's signals (turtle.h) and the Canvas to handle drwaing
    Connections {
        target: turtle

        //handling drawLine signal by ading new line to Canvas with specified start and end points
        function onDrawLine(startX, startY, endX, endY) {
            drawingCanvas.addLine(startX, startY, endX, endY);
        }
    }
}
