#include <iostream>
#include <ctime>
#include <chrono>

int main() {
    // Inicializar Tableros
    const unsigned short tamTablero = 10;
    // Creamos dos tableros, para que vean donde se encuentra cada barco de cada jugador
    char tableroVisibleJ1[tamTablero][tamTablero];
    char tableroVisibleJ2[tamTablero][tamTablero];
    // Tableros para controlar la ubicación de los barcos
    bool tableroControlBarcosJ1[tamTablero][tamTablero];
    bool tableroControlBarcosJ2[tamTablero][tamTablero];
    // Arrays colocación barcos
    const unsigned short tamBarcos[4] = { 3, 4, 5, 6 };
    const char caracteresBarcos[4] = { '3', '4', '5', '6' };

    // Caracteres a usar
    const char caracterInicial = '~';
    const char tocado = 'O';
    const char agua = 'X';
    const unsigned short barcosAColocar = 4;

    // Inicializar los tableros
    for (int f = 0; f < tamTablero; f++) 
    {
        for (int c = 0; c < tamTablero; c++) 
        {
            tableroVisibleJ1[f][c] = caracterInicial;
            tableroVisibleJ2[f][c] = caracterInicial;
            tableroControlBarcosJ1[f][c] = false;
            tableroControlBarcosJ2[f][c] = false;
        }
    }

    // Imprimir Tablero del Jugador 1
    std::cout << "Tablero Jugador 1" << std::endl;
    for (int f = 0; f < tamTablero; f++) 
    {
        for (int c = 0; c < tamTablero; c++) 
        {
            std::cout << tableroVisibleJ1[f][c] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << "\n";

    // Imprimir Tablero del Jugador 2
    std::cout << "Tablero Jugador 2" << std::endl;
    for (int f = 0; f < tamTablero; f++) 
    {
        for (int c = 0; c < tamTablero; c++) 
        {
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
    for (int b = 0; b < barcosAColocar; b++) // Iterando sobre los tamaños de los barcos
    { 
        bool barcoColocado = false;
        while (!barcoColocado) 
        {
            bool horizontal = rand() % 2; // 0 = vertical, 1 = horizontal
            unsigned short fila;
            unsigned short columna;
            bool espacioLibre = true;

            if (horizontal) 
            {
                fila = rand() % tamTablero;
                columna = rand() % (tamTablero - tamBarcos[b] + 1); // Con el +1 nos aseguramos que el barco cabe horizontalmente
                for (int i = 0; i < tamBarcos[b]; i++) 
                {
                    if (tableroControlBarcosJ1[fila][columna + i]) 
                    {
                        espacioLibre = false;
                        break;
                    }
                }

                if (espacioLibre) {
                    for (int i = 0; i < tamBarcos[b]; i++) 
                    {
                        tableroVisibleJ1[fila][columna + i] = caracteresBarcos[b];
                        tableroControlBarcosJ1[fila][columna + i] = true;
                    }
                    barcoColocado = true;
                }
            }

            else 
            {
                fila = rand() % (tamTablero - tamBarcos[b] + 1); // Con el +1 nos aseguramos que el barco cabe verticalmente
                columna = rand() % tamTablero;

                for (int i = 0; i < tamBarcos[b]; i++) 
                {
                    if (tableroControlBarcosJ1[fila + i][columna]) 
                    {
                        espacioLibre = false;
                        break;
                    }
                }

                if (espacioLibre) {
                    for (int i = 0; i < tamBarcos[b]; i++) 
                    {
                        tableroVisibleJ1[fila+i][columna] = caracteresBarcos[b];
                        tableroControlBarcosJ1[fila + i][columna] = true;
                    }
                    barcoColocado = true;
                }
            }
        }
    }

    // Colocar barcos para el Jugador 2
    for (int b = 0; b < barcosAColocar; b++) // Iterando sobre los tamaños de los barcos
    { 
        bool barcoColocado = false;

        while (!barcoColocado) 
        {
            bool horizontal = rand() % 2; // 0 = vertical, 1 = horizontal
            unsigned short fila, columna;
            bool espacioLibre = true;

            if (horizontal) 
            {
                fila = rand() % tamTablero;
                columna = rand() % (tamTablero - tamBarcos[b] + 1); // Con el +1 nos aseguramos que el barco cabe horizontalmente

                for (int i = 0; i < tamBarcos[b]; i++) {
                    if (tableroControlBarcosJ2[fila][columna + i]) 
                    {
                        espacioLibre = false;
                        break;
                    }
                }

                if (espacioLibre) {
                    for (int i = 0; i < tamBarcos[b]; i++) 
                    {
                        tableroVisibleJ2[fila][columna + i] = caracteresBarcos[b];
                        tableroControlBarcosJ2[fila][columna + i] = true;
                    }
                    barcoColocado = true;
                }
            }

            else 
            {
                fila = rand() % (tamTablero - tamBarcos[b] + 1); // Con el +1 nos aseguramos que el barco cabe verticalmente
                columna = rand() % tamTablero;

                for (int i = 0; i < tamBarcos[b]; i++) 
                {
                    if (tableroControlBarcosJ2[fila + i][columna]) 
                    {
                        espacioLibre = false;
                        break;
                    }
                }

                if (espacioLibre) 
                {
                    for (int i = 0; i < tamBarcos[b]; i++) 
                    {
                        tableroVisibleJ2[fila + i][columna] = caracteresBarcos[b];
                        tableroControlBarcosJ2[fila + i][columna] = true;
                    }
                    barcoColocado = true;
                }
            }
        }
    }

    // Imprimir Tablero del Jugador 1
    std::cout << "Tablero Jugador 1" << std::endl;

    for (int f = 0; f < tamTablero; f++) 
    {
        for (int c = 0; c < tamTablero; c++) 
        {
            std::cout << tableroVisibleJ1[f][c] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n";

    // Imprimir Tablero del Jugador 2
    std::cout << "Tablero Jugador 2" << std::endl;

    for (int f = 0; f < tamTablero; f++) 
    {
        for (int c = 0; c < tamTablero; c++) 
        {
            std::cout << tableroVisibleJ2[f][c] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n" << "Para continuar con el juego pulsa ENTER...!" << std::endl;
    std::cin.ignore();
    system("cls");
    bool juegoActivo = true;

    // Reiniciamos los tableros para que muestren las olas y no la posicion de los barcos
    for (int f = 0; f < tamTablero; f++) 
    {
        for (int c = 0; c < tamTablero; c++) 
        {
            tableroVisibleJ1[f][c] = caracterInicial;
            tableroVisibleJ2[f][c] = caracterInicial;
        }
    }

    // Juego
    while (juegoActivo)
    {
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

            // Comprobar si el disparo es válido
            if (disparoFila >= 0 && disparoFila < tamTablero && disparoColumna >= 0 && disparoColumna < tamTablero)
            {
                if (tableroControlBarcosJ2[disparoFila][disparoColumna])
                {
                    std::cout << "\n" << "TOCADO!" << std::endl;
                    tableroVisibleJ2[disparoFila][disparoColumna] = tocado;
                    tableroControlBarcosJ2[disparoFila][disparoColumna] = false;
                }

                else
                {
                    std::cout << "\n" << "AGUA!" << std::endl;
                    tableroVisibleJ2[disparoFila][disparoColumna] = agua;
                }
                disparoValido = true;
                turno = true;

            }

            // Si el disparo no es válido, avisar al jugador.
            else
            {
                std::cout << "\n\n\n" << "DISPARO FUERA DEL RANGO DEL TABLERO ESTABLECIDO!" << std::endl << "\n\n\n";
                std::chrono::seconds(5);
                system("cls");
            }
        }

        // Imprimir Tablero del Jugador 2 para ver si el juagador 1 ha tocado algun barco del jugador 2
        system("cls");
        std::cout << "\n" << "Tablero Jugador 2" << std::endl;

        for (int f = 0; f < tamTablero; f++) 
        {
            for (int c = 0; c < tamTablero; c++) 
            {
                std::cout << tableroVisibleJ2[f][c] << " ";
            }
            std::cout << std::endl;
        }

        // Comprobar si el Jugador 2 ha perdido sumando todos los valores del tablero de control de barcos del jugador 2, ya que son booleanos (1/0), si todos sumados suman 0 querrá decir que el jugador ha perdido
        int sumaJ2 = 0;
        bool J2HaPerdido = true;

        for (int f = 0; f < tamTablero; f++) 
        {
            for (int c = 0; c < tamTablero; c++) 
            {
                if (tableroControlBarcosJ2[f][c] == true)
                {
                    sumaJ2++;

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

            // Comprobar si el disparo es válido
            if (disparoFila >= 0 && disparoFila < tamTablero && disparoColumna >= 0 && disparoColumna < tamTablero)
            {
                if (tableroControlBarcosJ1[disparoFila][disparoColumna])
                {
                    std::cout << "\n" << "TOCADO!" << std::endl;
                    tableroVisibleJ1[disparoFila][disparoColumna] = tocado;
                    tableroControlBarcosJ1[disparoFila][disparoColumna] = false;
                }

                else
                {
                    std::cout << "\n" << "AGUA!" << std::endl;
                    tableroVisibleJ1[disparoFila][disparoColumna] = agua;
                }
                disparoValido = true;
                turno = false;
            }
            // Si el disparo no es válido, avisar al jugador.
            else
            {
                std::cout << "\n\n\n" << "DISPARO FUERA DEL RANGO DEL TABLERO ESTABLECIDO!" << std::endl << "\n\n\n";
            }
        }

        // Imprimir Tablero del Jugador 1 para ver si el juagador 2 ha tocado algun barco del jugador 1
        system("cls");
        std::cout << "\n" << "Tablero Jugador 1" << std::endl;
        for (int f = 0; f < tamTablero; f++) 
        {
            for (int c = 0; c < tamTablero; c++) 
            {
                std::cout << tableroVisibleJ1[f][c] << " ";
            }
            std::cout << std::endl;

        }

        // Comprobar si el Jugador 1 ha perdido sumando todos los valores del tablero de control de barcos del jugador 1, ya que son booleanos (1/0), si todos sumados suman 0 querrá decir que el jugador ha perdido
        int sumaJ1 = 0;
        bool J1HaPerdido = false;

        for (int f = 0; f < tamTablero; f++) 
        {
            for (int c = 0; c < tamTablero; c++) 
            {
                if (tableroControlBarcosJ1[f][c] == true)
                {
                    sumaJ1++;

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