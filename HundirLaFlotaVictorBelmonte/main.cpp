    #include <iostream>
    #include <ctime>

int main() {
    // Inicializar Tableros
    const unsigned short tamTablero = 10;
    // Creamos dos tableros, para que vean donde se encuntra cada barco de cada jugador
    char tableroVisibleJ1[tamTablero][tamTablero];
    char tableroVisibleJ2[tamTablero][tamTablero];
    // Tableros para controlar la ubicaci�n de los barcos
    bool tableroControlBarcosJ1[tamTablero][tamTablero];
    bool tableroControlBarcosJ2[tamTablero][tamTablero];
    // Tableros para el juego
    char tableroJuegoJ1[tamTablero][tamTablero]; // ELIMINARLOS, IR COMPROBANDO DONDE HAYA UN NUMERO PONER UNA ~
    char tableroJuegoJ2[tamTablero][tamTablero]; // ELIMINARLOS,IR COMPROBANDO DONDE HAYA UN NUMERO PONER UNA ~
    // Arrays colocacion barcos
	const unsigned short tamBarcos[4] = { 3, 4, 5, 6 };
    const char caracteresBarcos[4] = { '3', '4', '5', '6' };
    
    // Caracteres
    const char caracterInicial = '~';
	const char tocado = 'O';
	const char agua = 'X';
	const unsigned short barcosAColocar = 4;

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
    for (int b = 0; b < barcosAColocar; b++) { // Iterar sobre los tama�os de los barcos
        bool barcoColocado = false;
        while (!barcoColocado) {
            bool horizontal = rand() % 2; // 0 = vertical, 1 = horizontal
            unsigned short fila;
            unsigned short columna;
            bool espacioLibre = true;
            if (horizontal) {
                fila = rand() % tamTablero;
                columna = rand() % (tamTablero - tamBarcos[b] + 1);
                for (int i = 0; i < tamBarcos[b]; i++) {
                    if (tableroControlBarcosJ1[fila][columna + i]) {
                        espacioLibre = false;
                        break;
                    }
                }
                if (espacioLibre) {
                    for (int i = 0; i < tamBarcos[b]; i++) {
                        tableroVisibleJ1[fila][columna + i] = caracteresBarcos[b];
                        tableroControlBarcosJ1[fila][columna + i] = true;
                    }
                    barcoColocado = true;
                }
            }
            else {
                fila = rand() % (tamTablero - tamBarcos[b] + 1);
                columna = rand() % tamTablero;
                for (int i = 0; i < tamBarcos[b]; i++) {
                    if (tableroControlBarcosJ1[fila + i][columna]) {
                        espacioLibre = false;
                        break;
                    }
                }
                if (espacioLibre) {
                    for (int i = 0; i < tamBarcos[b]; i++) {
                        tableroVisibleJ1[fila + i][columna] = caracteresBarcos[b];
                        tableroControlBarcosJ1[fila + i][columna] = true;
                    }
                    barcoColocado = true;
                }
            }
        }
    }

    // Colocar barcos para el Jugador 2
    for (int b = 0; b < barcosAColocar; b++) { // Iterar sobre los tama�os de los barcos
        bool barcoColocado = false;
        while (!barcoColocado) {
            bool horizontal = rand() % 2; // 0 = vertical, 1 = horizontal
            unsigned short fila, columna;
            bool espacioLibre = true;
            if (horizontal) {
                fila = rand() % tamTablero;
                columna = rand() % (tamTablero - tamBarcos[b] + 1);
                for (int i = 0; i < tamBarcos[b]; i++) {
                    if (tableroControlBarcosJ2[fila][columna + i]) {
                        espacioLibre = false;
                        break;
                    }
                }
                if (espacioLibre) {
                    for (int i = 0; i < tamBarcos[b]; i++) {
                        tableroVisibleJ2[fila][columna + i] = caracteresBarcos[b];
                        tableroControlBarcosJ2[fila][columna + i] = true;
                    }
                    barcoColocado = true;
                }
            }
            else {
                fila = rand() % (tamTablero - tamBarcos[b] + 1);
                columna = rand() % tamTablero;
                for (int i = 0; i < tamBarcos[b]; i++) {
                    if (tableroControlBarcosJ2[fila + i][columna]) {
                        espacioLibre = false;
                        break;
                    }
                }
                if (espacioLibre) {
                    for (int i = 0; i < tamBarcos[b]; i++) {
                        tableroVisibleJ2[fila + i][columna] = caracteresBarcos[b];
                        tableroControlBarcosJ2[fila + i][columna] = true;
                    }
                    barcoColocado = true;
                }
            }
        }
    }
    

    bool tablerosImpresos = false;

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

		// Comprobar si el Jugador 2 ha perdido sumando todos los valores del tablero de control de barcos del jugador 2
        int sumaJ2 = true;
        bool J2HaPerdido = true;
        for (int f = 0; f < tamTablero; f++) {
            for (int c = 0; c < tamTablero; c++) {
                if (tableroControlBarcosJ2[f][c] == true)
                {
                    sumaJ2 += tableroControlBarcosJ1[f][c];

                    if (sumaJ2 == 0)
                    {
                        J2HaPerdido = true;
                        break;
                    }
                    else
                    {
                        J2HaPerdido = false;
                    }

                    if (!J2HaPerdido) {
                        turno = true;
                        disparoValido = false;
                        break;
                    }

                }
            }     
         
        }

        if (J2HaPerdido)  //GAME OVER
        {    
            system("cls");
            std::cout << "JUGADOR 1 GANADOR";
            juegoActivo = false;
            break;
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

		// Comprobar si el Jugador 1 ha perdido sumando todos los valores del tablero de control de barcos del jugador 1
        int sumaJ1 = true;
		bool J1HaPerdido = false;
        for (int f = 0; f < tamTablero; f++) {
            for (int c = 0; c < tamTablero; c++) {
                if (tableroControlBarcosJ1[f][c] == true) 
                {
					sumaJ1 += tableroControlBarcosJ1[f][c];

                    if (sumaJ1 == 0)
                    {
						J1HaPerdido = true;
                        break;
                    }
                    else
                    {
						J1HaPerdido = false;
                    }

                    if (!J1HaPerdido) {
                        turno = false;
                        disparoValido = false;
                        break;
                    }

                }
            }

    
            
        }

        if (J1HaPerdido) //GAME OVER 
        {                    
            system("cls");
            std::cout << "JUGADOR 2 GANADOR";
            juegoActivo = false;
            break;
        }
    }
}