/*
 * switch.cc
 *
 *  Created on: 21/09/2024
 *      Author: Bryan
 */
#include <omnetpp.h>
#include <stdio.h>
#include <string.h>

using namespace omnetpp;

class Terminal1 : public cSimpleModule
{
private:
    cMessage *timeout;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    int generateRandomHeader();  // Función para generar encabezado aleatorio
};
Define_Module(Terminal1);

void Terminal1::initialize()
{
    timeout = new cMessage("timer");
    scheduleAt(simTime() + 0.5, timeout); // Inicializa el temporizador
}

void Terminal1::handleMessage(cMessage *msg)
{
    if (msg == timeout) {
        // Generar el encabezado aleatorio
        int header = generateRandomHeader();

        // Crear el mensaje con el encabezado
        cMessage *msg1 = new cMessage("header");
        msg1->setKind(header);

        // Enviar el mensaje
        send(msg1, "out");

        // Volver a programar el temporizador
        scheduleAt(simTime() + 0.5, timeout);
    }
}

int Terminal1::generateRandomHeader()
{
    // Generar aleatoriamente un número 0, 1 o 2
    int randomValue = intuniform(0, 2);  // Genera un valor entre 0 y 2
    switch(randomValue) {
        case 0: return 2;  // Encabezado "01" en binario
        case 1: return 3;  // Encabezado "10" en binario
        case 2: return 4;  // Encabezado "11" en binario
        default: return 1; // Valor por defecto (nunca debería llegar aquí)
    }
}

class Terminal2 : public cSimpleModule
{
private:
    cMessage *timeout;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    int generateRandomHeader();  // Función para generar encabezado aleatorio
};
Define_Module(Terminal2);

void Terminal2::initialize()
{
    timeout = new cMessage("timer");
    scheduleAt(simTime() + 0.5, timeout); // Inicializa el temporizador
}

void Terminal2::handleMessage(cMessage *msg)
{
    if (msg == timeout) {
        // Generar el encabezado aleatorio
        int header = generateRandomHeader();

        // Crear el mensaje con el encabezado
        cMessage *msg1 = new cMessage("header");
        msg1->setKind(header);

        // Enviar el mensaje
        send(msg1, "out");

        // Volver a programar el temporizador
        scheduleAt(simTime() + 0.5, timeout);
    }
}

int Terminal2::generateRandomHeader()
{
    // Generar aleatoriamente un número 0, 1 o 2
    int randomValue = intuniform(0, 2);  // Genera un valor entre 0 y 2
    switch(randomValue) {
        case 0: return 1;  // Encabezado "01" en binario
        case 1: return 3;  // Encabezado "10" en binario
        case 2: return 4;  // Encabezado "11" en binario
        default: return 1; // Valor por defecto (nunca debería llegar aquí)
    }
}

class Terminal3 : public cSimpleModule
{
private:
    cMessage *timeout;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    int generateRandomHeader();  // Función para generar encabezado aleatorio
};
Define_Module(Terminal3);

void Terminal3::initialize()
{
    timeout = new cMessage("timer");
    scheduleAt(simTime() + 0.5, timeout); // Inicializa el temporizador
}

void Terminal3::handleMessage(cMessage *msg)
{
    if (msg == timeout) {
        // Generar el encabezado aleatorio
        int header = generateRandomHeader();

        // Crear el mensaje con el encabezado
        cMessage *msg1 = new cMessage("header");
        msg1->setKind(header);

        // Enviar el mensaje
        send(msg1, "out");

        // Volver a programar el temporizador
        scheduleAt(simTime() + 0.5, timeout);
    }
}

int Terminal3::generateRandomHeader()
{
    // Generar aleatoriamente un número 0, 1 o 2
    int randomValue = intuniform(0, 2);  // Genera un valor entre 0 y 2
    switch(randomValue) {
        case 0: return 1;  // Encabezado "01" en binario
        case 1: return 2;  // Encabezado "10" en binario
        case 2: return 4;  // Encabezado "11" en binario
        default: return 1; // Valor por defecto (nunca debería llegar aquí)
    }
}

class Terminal4 : public cSimpleModule
{
private:
    cMessage *timeout;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    int generateRandomHeader();  // Función para generar encabezado aleatorio
};
Define_Module(Terminal4);

void Terminal4::initialize()
{
    timeout = new cMessage("timer");
    scheduleAt(simTime() + 0.5, timeout); // Inicializa el temporizador
}

void Terminal4::handleMessage(cMessage *msg)
{
    if (msg == timeout) {
        // Generar el encabezado aleatorio
        int header = generateRandomHeader();

        // Crear el mensaje con el encabezado
        cMessage *msg1 = new cMessage("header");
        msg1->setKind(header);

        // Enviar el mensaje
        send(msg1, "out");

        // Volver a programar el temporizador
        scheduleAt(simTime() + 0.5, timeout);
    }
}

int Terminal4::generateRandomHeader()
{
    // Generar aleatoriamente un número 0, 1 o 2
    int randomValue = intuniform(0, 2);  // Genera un valor entre 0 y 2
    switch(randomValue) {
        case 0: return 1;  // Encabezado "01" en binario
        case 1: return 2;  // Encabezado "10" en binario
        case 2: return 3;  // Encabezado "11" en binario
        default: return 1; // Valor por defecto (nunca debería llegar aquí)
    }
}

class Switch : public cSimpleModule
{
protected:
    virtual void handleMessage(cMessage *msg) override; // Método para manejar los mensajes
    void forwardMessage(cMessage *msg, int header);     // Método para redirigir el mensaje basado en el encabezado
};

Define_Module(Switch);

void Switch::handleMessage(cMessage *msg)
{
    // Leer el encabezado del mensaje
    int header = msg->getKind();

    // Redirigir el mensaje al destino adecuado
    forwardMessage(msg, header);
}

void Switch::forwardMessage(cMessage *msg, int header)
{
    cGate *outGate = nullptr; // Inicializar puntero de la puerta de salida

    // Seleccionar la puerta de salida de acuerdo al encabezado del mensaje
    switch (header) {
        case 1:  // Encabezado "00" -> Terminal 1
            outGate = gate("out1");
            break;
        case 2:  // Encabezado "01" -> Terminal 2
            outGate = gate("out2");
            break;
        case 3:  // Encabezado "10" -> Terminal 3
            outGate = gate("out3");
            break;
        case 4:  // Encabezado "11" -> Terminal 4
            outGate = gate("out4");
            break;
        default: // Valor de encabezado no válido
            EV << "Invalid header: " << header << ". Dropping message." << endl;
            delete msg;
            return;
    }

    // Enviar el mensaje a la puerta correspondiente
    EV << "Forwarding message with header " << header << " to Terminal " << header + 1 << endl;
    send(msg, outGate); // Redirigir el mensaje
}
