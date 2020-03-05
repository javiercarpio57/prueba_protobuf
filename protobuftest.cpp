
#include <string>
#include <iostream>
#include "mensaje.pb.h"
using namespace std;
using namespace chat;

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // Se crea instacia tipo MiInfoRequest y se setean los valores deseables
    MiInfoRequest* miInfo(new MiInfoRequest);
    miInfo->set_username("username123");
    miInfo->set_ip("12356789");

    // Se crea instancia de Mensaje, se setea los valores deseados
    Mensaje m;
    m.set_option("0");
    m.set_allocated_miinforeq(miInfo);

    // Se serializa el message a string
    string binary;
    m.SerializeToString(&binary);

    /*
        YA CON EL "MENSAJE" SERIALIZADO A STRING SE PUEDE ENVIAR UTILIZANDO SOCKETS CON send()
        EL RECEPTOR RECIBIRÁ EL STRING SERIALIZADO, Y ESTE LO PUEDE DESEREALIZAR A UN OBJETO "MENSAJE"
    */


    // Se deserealiza el string a un objeto Mensaje
    Mensaje m2;
    m2.ParseFromString(binary);

    // Se puede accesar a los valores de la siguiente manera:
    cout << "Option: " << m2.option() << endl;
    cout << "Username: " << m2.miinforeq().username() << endl;
    cout << "ip: " << m2.miinforeq().ip() << endl;

    google::protobuf::ShutdownProtobufLibrary();
    return 1;
}