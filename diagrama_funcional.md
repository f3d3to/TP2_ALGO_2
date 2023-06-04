# Diagramas de funcional del programa

- ASIGNA UNA CANTIDAD PRECISA DE FICHAS A CADA JUGADOR

En este archivo hay un diagrama de cómo funciona el juego.



(La clase juego manipula el tablero)
(La clase Jugador contiene la informacion para cada jugador)
## Juego
  juego.inicializar // pide ingresar los datos

  juego.jugadores // lista de jugadores ingresados
  While soldados1 !=0 and soldados2!=0(): // 
    jugador [1] ubica jugadores, minas, etc // el jugador 1 realiza acciones.
    juego.chequeo() // Chequea el estado en base a las acciones del jugador previo
    cambiar_estado_del_tablero // en base al chequeo ejecuta las acciones y actualiza el Tablero.
    
    juego.hay_ganador()
    jugador = juego.avanzar_jugador()
    jugador [2] ubica jugadores, minas , etc.
    (...)
  