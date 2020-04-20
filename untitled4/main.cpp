#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    //variables
    string id, beca, ncv, c1, c2, c3, c4;
    string nombre, sede, programa, nivel, estatus;
    string cargos, eca, depp, ajustado, pagado, saldo, saldo_vencido, b1, a1, p1, s1, porcentaje1, b2, a2, p2, s2, porcentaje2, b3, a3, p3, s3, porcentaje3, b4, a4, p4, s4, porcentaje4;
    vector<int>unid_id;
    vector<string>nombre_alumno;
    vector<string>prog_unid;
    vector<double>saldo_venc_moneda;
    vector<int>col_atrasadas;
    vector<bool>marcado;




    string File;
    cout << "Ingresa el nombre del archivo para analizar:";
    cin >> File;

    //lineas
    int i = 0;
    int deudores = 0;

    ifstream read(File);//opening file
    if (read.is_open()){

        string line;
        getline(read, line);

        while (!read.eof()){
            //definimos un get line por cada una de las columnas
            getline(read,id,',');
            unid_id.push_back(stoi(id));
            getline(read, nombre, ',');
            nombre_alumno.emplace_back(nombre);
            getline(read, sede, ',');
            getline(read, programa, ',');
            prog_unid.emplace_back(programa);
            getline(read, nivel, ',');
            getline(read, estatus, ',');
            getline(read, beca, ',' );
            getline(read, cargos, ',');
            getline(read, eca,',');
            getline(read, depp, ',');
            getline(read, ajustado, ',');
            getline(read, pagado, ',');
            getline(read, saldo, ',');
            getline(read, saldo_vencido, ',');
            saldo_venc_moneda.push_back(stod(saldo_vencido));
            if (stoi(saldo_vencido) > 0){
                marcado.emplace_back(true);
                deudores += 1;//contar deudores
            } else marcado.emplace_back(false);
            getline(read, ncv, ',');
            getline(read, c1, ',');
            getline(read, b1, ',');
            getline(read, a1, ',');
            getline(read, p1, ',');
            getline(read, s1, ',');
            getline(read, porcentaje1, ',');
            getline(read, c2, ',');
            getline(read,b2,',');
            getline(read,a2,',');
            getline(read,p2,',');
            getline(read, s2,',');
            getline(read,porcentaje2,',');
            getline(read,c3,',');
            getline(read,b3,',');
            getline(read,a3,',');
            getline(read,p3,',');
            getline(read,s3,',');
            getline(read,porcentaje3,',');
            getline(read,c4,',');
            getline(read,b4,',');
            getline(read,a4,',');
            getline(read,p4,',');
            getline(read,s4,',');
            getline(read,porcentaje4,'\n');//linea nueva

            i += 1; //increment line
        } //while the end of file is not reached
        read.close(); //closing the file

        cout<<"Numero de entradas: " <<i<<endl;

    } else cout << "No se puede abrir el archivo"<<endl; //error

    //output vectors
    cout << "¿Que operación desea realizar?" << endl;
    cout
            << "1)Revisar numero de deudores . 2)Buscar alumno con el ID. 3)Ver por programa academico. 4)Ver todos los deudores. 5)Salir"
            << endl;
    cout << "Numero de opcion: ";
    int numero;
    cin >> numero;


    switch(numero) {
        case 1:
            cout << "Numero de deudores: " << deudores << endl;
            break;
        case 2: {
            cout << "Ingrese el id del alumno: ";
            int id_buscar;
            cin >> id_buscar;
            cout << "ID" << "\t" << "Nombre" << "\t" << "programa" << "\t" << "saldo vencido" << endl;
            for (int j = 0; j < i; j++) {
                if (unid_id[j] == id_buscar)
                    cout << unid_id[j] << "\t" << nombre_alumno[j] << "\t" << prog_unid[j] << "\t"
                         << saldo_venc_moneda[j]    << endl;

            }
        }
            break;
        case 3: {
            cout << "Ingrese la clave del programa: ";
            string buscar_programa;
            cin >> buscar_programa;
            cout << "ID" << "\t" << "Nombre" << "\t" << "programa" << "\t" << "saldo vencido" << endl;
            for (int j = 0; j < i; j++) {
                if (prog_unid[j].compare(buscar_programa) == 0)
                    cout << unid_id[j] << "\t" << nombre_alumno[j] << "\t" << prog_unid[j] << "\t"
                         << saldo_venc_moneda[j] <<   endl;

            }
        }
            break;
        case 4: {
            for (int j = 0; j < i; j++) {
                cout << "ID" << "\t" << "Nombre" << "\t" << "programa" << "\t" << "saldo vencido" << endl;
                if (saldo_venc_moneda[j] > 0)
                    cout << unid_id[j] << "\t" << nombre_alumno[j] << "\t" << prog_unid[j] << "\t"
                         << saldo_venc_moneda[j] << endl;
            }

        }
        case 5:
        {
            return 0;
        }
    }

}



















