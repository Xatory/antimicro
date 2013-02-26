#include <cmath>

#include "joyaxisbutton.h"
#include "joyaxis.h"
#include "event.h"

const QString JoyAxisButton::xmlName = "axisbutton";

JoyAxisButton::JoyAxisButton(JoyAxis *axis, QObject *parent) :
    JoyButton(parent)
{
    this->axis = axis;
}

JoyAxisButton::JoyAxisButton(JoyAxis *axis, int index, QObject *parent) :
    JoyButton(parent)
{
    this->axis = axis;
    this->index = index;
}

QString JoyAxisButton::getXmlName()
{
    return this->xmlName;
}

void JoyAxisButton::mouseEvent(JoyButtonSlot *buttonslot)
{
    QTime* mouseInterval = buttonslot->getMouseInterval();

    int mousemode = buttonslot->getSlotCode();
    int mousespeed;
    int timeElapsed = mouseInterval->elapsed();

    if (mousemode == JoyButtonSlot::MouseRight)
    {
        mousespeed = mouseSpeedX;
    }
    else if (mousemode == JoyButtonSlot::MouseLeft)
    {
        mousespeed = mouseSpeedX;
    }
    else if (mousemode == JoyButtonSlot::MouseDown)
    {
        mousespeed = mouseSpeedY;
    }
    else if (mousemode == JoyButtonSlot::MouseUp)
    {
        mousespeed = mouseSpeedY;
    }

    if (isButtonPressed && timeElapsed >= 1)
    {
        double difference = axis->calculateNormalizedAxisPlacement();
        int mouse1 = 0;
        int mouse2 = 0;
        double sumDist = buttonslot->getDistance();

        if (mousemode == JoyButtonSlot::MouseRight)
        {
            sumDist += difference * (mousespeed * JoyButtonSlot::JOYSPEED * timeElapsed) / 1000.0;
            int distance = (int)floor(sumDist + 0.5);
            mouse1 = distance;
        }
        else if (mousemode == JoyButtonSlot::MouseLeft)
        {
            sumDist += difference * (mousespeed * JoyButtonSlot::JOYSPEED * timeElapsed) / 1000.0;
            int distance = (int)floor(sumDist + 0.5);
            mouse1 = -distance;
        }
        else if (mousemode == JoyButtonSlot::MouseDown)
        {
            sumDist += difference * (mousespeed * JoyButtonSlot::JOYSPEED * timeElapsed) / 1000.0;
            int distance = (int)floor(sumDist + 0.5);
            mouse2 = distance;
        }
        else if (mousemode == JoyButtonSlot::MouseUp)
        {
            sumDist += difference * (mousespeed * JoyButtonSlot::JOYSPEED * timeElapsed) / 1000.0;
            int distance = (int)floor(sumDist + 0.5);
            mouse2 = -distance;
        }

        if (sumDist < 1.0)
        {
            buttonslot->setDistance(sumDist);
        }
        else if (sumDist >= 1.0)
        {
            sendevent(mouse1, mouse2);
            sumDist = 0.0;

            buttonslot->setDistance(sumDist);
        }

        mouseInterval->restart();
    }

    if (isButtonPressed)
    {
        QMetaObject::invokeMethod(this, "mouseEvent", Qt::QueuedConnection, Q_ARG(JoyButtonSlot*, buttonslot));
    }
    else
    {
        buttonslot->setDistance(0.0);
        mouseInterval->restart();
    }
}