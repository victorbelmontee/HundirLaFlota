    #include <iostream>
    #include <ctime>

int main() {
    // Inicializar Tableros
    const unsigned short tamTablero = 10;
    // Creamos dos tableros, para que vean donde se encuntra cada barco de cada jugador
    char tableroVisibleJ1[tamTablero][tamTablero];
    char tableroVisibleJ2[tamTablero][tamTablero];
    // Tableros para controlar la ubicación de los barcos
    bool tableroControlBarcosJ1[tamTablero][tamTablero];
    bool tableroControlBarcosJ2[tamTablero][tamTablero];
    // Tableros para el juego
    char tableroJuegoJ1[tamTablero][tamTablero];
    char tableroJuegoJ2[tamTablero][tamTablero];
    
    // Caracteres
    const char caracterInicial = '~';
    const char barcoTres = '3';
    const char barcoCuatro = '4';
    const char barcoCinco = '5';
    const char barcoSeis = '6';
	const char tocado = 'O';
	const char agua = 'X';

    // Inicializar los tableros
    for (int f = 0; f < tamTablero; f++) {
        for (int c = 0; c < tamTablero; c++) {
            tableroVisibleJ1[f][c] = caracterInicial;
            tableroVisibleJ2[f][c] = caracterInicial;
            tableroControlBarcosJ1[f][c] = false;
            tableroControlBarcosJ2[f][c] = false;
            tableroJuegoJ1[f][c] = caracterInicial;
            tableroJuegoJ2[f][c] = caracterInicial;
        }
    }

    // Imprimir Tablero del Jugador 1
    std::cout << "Tablero Jugador 1" << std::endl;
    for (int f = 0; f < tamTablero; f++) {
        for (int c = 0; c < tamTablero; c++) {
            std::cout << tableroVisibleJ1[f][c] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n";

    // Imprimir Tablero del Jugador 2
    std::cout << "Tablero Jugador 2" << std::endl;
    for (int f = 0; f < tamTablero; f++) {
        for (int c = 0; c < tamTablero; c++) {
            std::cout << tableroVisibleJ2[f][c] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n\n";

    srand(time(NULL));

    // Empieza el Juego
    std::cout << "Para empezar el juego pulsa ENTER...!" << std::endl;
    std::cin.ignore();
    system("cls");

    // Colocar barcos para el Jugador 1
    // Barco de 3 casillas
    bool barcoColocadoTresJ1 = false;
    while (!barcoColocadoTresJ1) {
        bool horizontal = rand() % 2; // 0 = vertical, 1 = horizontal
        unsigned short fila;
        unsigned short columna;
        bool espacioLibre = true;
        if (horizontal) {
            fila = rand() % tamTablero;
            columna = rand() % (tamTablero - 3 + 1);
            for (short i = 0; i < 3; i++) {
                if (tableroControlBarcosJ1[fila][columna + i]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (int i = 0; i < 3; i++) {
                    tableroVisibleJ1[fila][columna + i] = barcoTres;
                    tableroControlBarcosJ1[fila][columna + i] = true;
                }
                barcoColocadoTresJ1 = true;
            }
        }
        else {
            fila = rand() % (tamTablero - 3 + 1);
            columna = rand() % tamTablero;
            for (short i = 0; i < 3; i++) {
                if (tableroControlBarcosJ1[fila + i][columna]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 3; i++) {
                    tableroVisibleJ1[fila + i][columna] = barcoTres;
                    tableroControlBarcosJ1[fila + i][columna] = true;
                }
                barcoColocadoTresJ1 = true;
            }
        }
    }

    // Barco de 4 casillas
    bool BarcoColocadoCuatroJ1 = false;
    while (!BarcoColocadoCuatroJ1) {
        bool horizontal = rand() % 2;
        unsigned short fila;
        unsigned short columna;
        bool espacioLibre = true;
        if (horizontal) {
            fila = rand() % tamTablero;
            columna = rand() % (tamTablero - 4 + 1);
            for (short i = 0; i < 4; i++) {
                if (tableroControlBarcosJ1[fila][columna + i]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 4; i++) {
                    tableroVisibleJ1[fila][columna + i] = barcoCuatro;
                    tableroControlBarcosJ1[fila][columna + i] = true;
                }
                BarcoColocadoCuatroJ1 = true;
            }
        }
        else {
            fila = rand() % (tamTablero - 4 + 1);
            columna = rand() % tamTablero;
            for (short i = 0; i < 4; i++) {
                if (tableroControlBarcosJ1[fila + i][columna]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 4; i++) {
                    tableroVisibleJ1[fila + i][columna] = barcoCuatro;
                    tableroControlBarcosJ1[fila + i][columna] = true;
                }
                BarcoColocadoCuatroJ1 = true;
            }
        }
    }

    // Barco de 5 casillas
    bool BarcoColocadoCincoJ1 = false;
    while (!BarcoColocadoCincoJ1) {
        bool horizontal = rand() % 2;
        unsigned short fila;
        unsigned short columna;
        bool espacioLibre = true;
        if (horizontal) {
            fila = rand() % tamTablero;
            columna = rand() % (tamTablero - 5 + 1);
            for (short i = 0; i < 5; i++) {
                if (tableroControlBarcosJ1[fila][columna + i]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 5; i++) {
                    tableroVisibleJ1[fila][columna + i] = barcoCinco;
                    tableroControlBarcosJ1[fila][columna + i] = true;
                }
                BarcoColocadoCincoJ1 = true;
            }
        }
        else {
            fila = rand() % (tamTablero - 5 + 1);
            columna = rand() % tamTablero;
            for (short i = 0; i < 5; i++) {
                if (tableroControlBarcosJ1[fila + i][columna]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 5; i++) {
                    tableroVisibleJ1[fila + i][columna] = barcoCinco;
                    tableroControlBarcosJ1[fila + i][columna] = true;
                }
                BarcoColocadoCincoJ1 = true;
            }
        }
    }

    // Barco de 6 casillas
    bool BarcoColocadoSeisJ1 = false;
    while (!BarcoColocadoSeisJ1) {
        bool horizontal = rand() % 2;
        unsigned short fila;
        unsigned short columna;
        bool espacioLibre = true;
        if (horizontal) {
            fila = rand() % tamTablero;
            columna = rand() % (tamTablero - 6 + 1);
            for (short i = 0; i < 6; i++) {
                if (tableroControlBarcosJ1[fila][columna + i]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 6; i++) {
                    tableroVisibleJ1[fila][columna + i] = barcoSeis;
                    tableroControlBarcosJ1[fila][columna + i] = true;
                }
                BarcoColocadoSeisJ1 = true;
            }
        }
        else {
            fila = rand() % (tamTablero - 6 + 1);
            columna = rand() % tamTablero;
            for (short i = 0; i < 6; i++) {
                if (tableroControlBarcosJ1[fila + i][columna]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 6; i++) {
                    tableroVisibleJ1[fila + i][columna] = barcoSeis;
                    tableroControlBarcosJ1[fila + i][columna] = true;
                }
                BarcoColocadoSeisJ1 = true;
            }
        }
    }

    // Imprimir Tablero del Jugador 1
    std::cout << "Tablero Jugador 1" << std::endl;
    for (int f = 0; f < tamTablero; f++) {
        for (int c = 0; c < tamTablero; c++) {
            std::cout << tableroVisibleJ1[f][c] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n";

    // Repetir el mismo proceso para el Jugador 2
    // Barco de 3 casillas
    bool BarcoColocadoTresJ2 = false;
    while (!BarcoColocadoTresJ2) {
        bool horizontal = rand() % 2;
        unsigned short fila;
        unsigned short columna;
        bool espacioLibre = true;
        if (horizontal) {
            fila = rand() % tamTablero;
            columna = rand() % (tamTablero - 3 + 1);
            for (short i = 0; i < 3; i++) {
                if (tableroControlBarcosJ2[fila][columna + i]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (int i = 0; i < 3; i++) {
                    tableroVisibleJ2[fila][columna + i] = barcoTres;
                    tableroControlBarcosJ2[fila][columna + i] = true;
                }
                BarcoColocadoTresJ2 = true;
            }
        }
        else {
            fila = rand() % (tamTablero - 3 + 1);
            columna = rand() % tamTablero;
            for (short i = 0; i < 3; i++) {
                if (tableroControlBarcosJ2[fila + i][columna]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 3; i++) {
                    tableroVisibleJ2[fila + i][columna] = barcoTres;
                    tableroControlBarcosJ2[fila + i][columna] = true;
                }
                BarcoColocadoTresJ2 = true;
            }
        }
    }

    // Barco de 4 casillas
    bool BarcoColocadoCuatroJ2 = false;
    while (!BarcoColocadoCuatroJ2) {
        bool horizontal = rand() % 2;
        unsigned short fila;
        unsigned short columna;
        bool espacioLibre = true;
        if (horizontal) {
            fila = rand() % tamTablero;
            columna = rand() % (tamTablero - 4 + 1);
            for (short i = 0; i < 4; i++) {
                if (tableroControlBarcosJ2[fila][columna + i]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 4; i++) {
                    tableroVisibleJ2[fila][columna + i] = barcoCuatro;
                    tableroControlBarcosJ2[fila][columna + i] = true;
                }
                BarcoColocadoCuatroJ2 = true;
            }
        }
        else {
            fila = rand() % (tamTablero - 4 + 1);
            columna = rand() % tamTablero;
            for (short i = 0; i < 4; i++) {
                if (tableroControlBarcosJ2[fila + i][columna]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 4; i++) {
                    tableroVisibleJ2[fila + i][columna] = barcoCuatro;
                    tableroControlBarcosJ2[fila + i][columna] = true;
                }
                BarcoColocadoCuatroJ2 = true;
            }
        }
    }

    // Barco de 5 casillas
    bool BarcoColocadoCincoJ2 = false;
    while (!BarcoColocadoCincoJ2) {
        bool horizontal = rand() % 2;
        unsigned short fila;
        unsigned short columna;
        bool espacioLibre = true;
        if (horizontal) {
            fila = rand() % tamTablero;
            columna = rand() % (tamTablero - 5 + 1);
            for (short i = 0; i < 5; i++) {
                if (tableroControlBarcosJ2[fila][columna + i]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 5; i++) {
                    tableroVisibleJ2[fila][columna + i] = barcoCinco;
                    tableroControlBarcosJ2[fila][columna + i] = true;
                }
                BarcoColocadoCincoJ2 = true;
            }
        }
        else {
            fila = rand() % (tamTablero - 5 + 1);
            columna = rand() % tamTablero;
            for (short i = 0; i < 5; i++) {
                if (tableroControlBarcosJ2[fila + i][columna]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 5; i++) {
                    tableroVisibleJ2[fila + i][columna] = barcoCinco;
                    tableroControlBarcosJ2[fila + i][columna] = true;
                }
                BarcoColocadoCincoJ2 = true;
            }
        }
    }

    // Barco de 6 casillas
    bool BarcoColocadoSeisJ2 = false;
    while (!BarcoColocadoSeisJ2) {
        bool horizontal = rand() % 2;
        unsigned short fila;
        unsigned short columna;
        bool espacioLibre = true;
        if (horizontal) {
            fila = rand() % tamTablero;
            columna = rand() % (tamTablero - 6 + 1);
            for (short i = 0; i < 6; i++) {
                if (tableroControlBarcosJ2[fila][columna + i]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 6; i++) {
                    tableroVisibleJ2[fila][columna + i] = barcoSeis;
                    tableroControlBarcosJ2[fila][columna + i] = true;
                }
                BarcoColocadoSeisJ2 = true;
            }
        }
        else {
            fila = rand() % (tamTablero - 6 + 1);
            columna = rand() % tamTablero;
            for (short i = 0; i < 6; i++) {
                if (tableroControlBarcosJ2[fila + i][columna]) {
                    espacioLibre = false;
                    break;
                }
            }
            if (espacioLibre) {
                for (short i = 0; i < 6; i++) {
                    tableroVisibleJ2[fila + i][columna] = barcoSeis;
                    tableroControlBarcosJ2[fila + i][columna] = true;
                }
                BarcoColocadoSeisJ2 = true;
            }
        }
    }

    // Imprimir Tablero del Jugador 2
    std::cout << "Tablero Jugador 2" << std::endl;
    for (int f = 0; f < tamTablero; f++) {
        for (int c = 0; c < tamTablero; c++) {
            std::cout << tableroVisibleJ2[f][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n" << "Para continuar con el juego pulsa ENTER...!" << std::endl;
    std::cin.ignore();
    system("cls");
    bool juegoActivo = true;

    while (juegoActivo)
    {
        // Juego

        // Turno del Jugador 1
        std::cout << "\n" << "Turno del Jugador 1" << std::endl;

        bool disparoValido = false;
        bool turno = false;

        while (!disparoValido && !turno)
        {
            unsigned short disparoFila;
            unsigned short disparoColumna;
            std::cout << "\n" << "Introduce el Numero de fila" << std::endl;
            std::cin >> disparoFila;
            std::cout << "\n" << "Introduce el Numero de columna" << std::endl;
            std::cin >> disparoColumna;

            // Restar 1 a los inputs para que sean indices validos en los arrays
            disparoFila--;
            disparoColumna--;

            if (disparoFila >= 0 && disparoFila < tamTablero && disparoColumna >= 0 && disparoColumna < tamTablero)
            {
                if (tableroControlBarcosJ2[disparoFila][disparoColumna])
                {
                    std::cout << "\n" << "TOCADO!" << std::endl;
                    tableroJuegoJ2[disparoFila][disparoColumna] = tocado;
                    tableroControlBarcosJ2[disparoFila][disparoColumna] = false;
                }
                else
                {
                    std::cout << "\n" << "AGUA!" << std::endl;
                    tableroJuegoJ2[disparoFila][disparoColumna] = agua;
                }
                disparoValido = true;
                turno = true;

            }
            else
            {
                std::cout << "\n\n\n" << "DISPARO FUERA DEL RANGO DEL TABLERO ESTABLECIDO!" << std::endl << "\n\n\n";
            }
        }

        // Imprimir Tablero del Jugador 2 para ver si el juagador 1 ha tocado algun barco del jugador 2 
        std::cout << "\n" << "Tablero Jugador 2" << std::endl;
        for (int f = 0; f < tamTablero; f++) {
            for (int c = 0; c < tamTablero; c++) {
                std::cout << tableroJuegoJ2[f][c] << " ";
            }
            std::cout << std::endl;
        }

        // Comprobar si el Jugador 2 ha perdido
        bool J2HaPerdido = true;
        for (int f = 0; f < tamTablero; f++) {
            for (int c = 0; c < tamTablero; c++) {
                if (tableroControlBarcosJ2[f][c] == true)
                {
                    J2HaPerdido = false;
                    break;
                }
            }

            if (!J2HaPerdido) {
				turno = false;
                disparoValido = false;
                break;
            }
            if (J2HaPerdido) {                    //GAME OVER
                system("cls");
                std::cout << "JUGADOR 1 GANADOR";
                juegoActivo = false;
                break;
            }
         
        }

        // Turno del Jugador 2

        std::cout << "\n" << "Turno del Jugador 2" << std::endl;

        disparoValido = false;

        while (!disparoValido && turno)
        {
            unsigned short disparoFila;
            unsigned short disparoColumna;
            std::cout << "\n" << "Introduce el Numero de fila" << std::endl;
            std::cin >> disparoFila;
            std::cout << "\n" << "Introduce el Numero de columna" << std::endl;
            std::cin >> disparoColumna;

            // Restar 1 a los inputs para que sean indices validos en los arrays
            disparoFila--;
            disparoColumna--;

            if (disparoFila >= 0 && disparoFila < tamTablero && disparoColumna >= 0 && disparoColumna < tamTablero)
            {
                if (tableroControlBarcosJ1[disparoFila][disparoColumna])
                {
                    std::cout << "\n" << "TOCADO!" << std::endl;
                    tableroJuegoJ1[disparoFila][disparoColumna] = tocado;
                    tableroControlBarcosJ1[disparoFila][disparoColumna] = false;
                }
                else
                {
                    std::cout << "\n" << "AGUA!" << std::endl;
                    tableroJuegoJ1[disparoFila][disparoColumna] = agua;
                }
                disparoValido = true;
                turno = false;
            }
            else
            {
                std::cout << "\n\n\n" << "DISPARO FUERA DEL RANGO DEL TABLERO ESTABLECIDO!" << std::endl << "\n\n\n";
            }
        }

        // Imprimir Tablero del Jugador 1 para ver si el juagador 2 ha tocado algun barco del jugador 1
        std::cout << "\n" << "Tablero Jugador 1" << std::endl;
        for (int f = 0; f < tamTablero; f++) {
            for (int c = 0; c < tamTablero; c++) {
                std::cout << tableroJuegoJ1[f][c] << " ";
            }
            std::cout << std::endl;

        }

        // Comprobar si el Jugador 1 ha perdido
        bool J1HaPerdido = true;
        for (int f = 0; f < tamTablero; f++) {
            for (int c = 0; c < tamTablero; c++) {
                if (tableroControlBarcosJ1[f][c] == true) 
                {
                    J1HaPerdido = false;
                    break;
                }
            }

            if (!J1HaPerdido) {
				turno = true;
				disparoValido = false;
                break;
            }
            if (J1HaPerdido) {                    //GAME OVER
                system("cls");
                std::cout << "JUGADOR 2 GANADOR";
                juegoActivo = false;
				break;
            }        
            
        }

    }
}
