# Ejemplo de protobuf

links de apoyo: 
- https://vorbrodt.blog/2019/03/10/protocol-buffers-or-how-to-serialize-data/
- https://developers.google.com/protocol-buffers/docs/cpptutorial
- https://developers.google.com/protocol-buffers/docs/downloads?hl=es-419

# Compilación:

`protoc -I=. --cpp_out=. mensaje.proto` (este solo se realiza una vez para compilar el .proto, esto generaŕa mensaje.pb.cc y mensaje.pb.h) (link de descarga si no se tiene `protoc`: https://developers.google.com/protocol-buffers/docs/downloads?hl=es-419 )

`g++ protobuftest.cpp mensaje.pb.cc -lprotobuf -o protobuftest` (para compilar el programa)

# Ejecución:
`./protobuftest`
