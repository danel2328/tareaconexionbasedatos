// tareaconexionbasedatos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <windows.h>
#include <sqlext.h>
#include <iostream>

using namespace std;

int main() {
    SQLHENV hEnv;
    SQLHDBC hDbc;

    // Inicializar ODBC
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

    // Cadena de conexión
    SQLCHAR* connStr = (SQLCHAR*)"DSN=miBD;UID=root;PWD=root123;";

    SQLCHAR outstr[1024];
    SQLSMALLINT outstrlen;

    // Conectar
    SQLRETURN ret = SQLDriverConnectA(
        hDbc,
        NULL,
        connStr,
        SQL_NTS,
        outstr,
        sizeof(outstr),
        &outstrlen,
        SQL_DRIVER_COMPLETE
    );

    // Verificar conexión
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        cout << "Conexion exitosa\n";
    }
    else {
        cout << "Error de conexion\n";
    }

    system("pause");
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
