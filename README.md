# Proyecto_2_Sistemas_Operativos

<div style="color: red; font-size: 1.5em; font-weight: bold; text-align: center; margin-top: 20px;">
    ¡ATENCIÓN! Para la correcta compilación de este proyecto se requiere C++ 17 o una versión más reciente.
</div>

En este proyecto se utiliza la biblioteca `std::optional`, lo que significa que **no compilará** en versiones antiguas de C++.

## Integrantes del grupo
- [Carlos Tomás Álvarez Norambuena](https://github.com/Karantooo) **(2022433621)**
- [Antonio Jesús Benavides Puentes](https://github.com/AntoCreed777) **(2023455954)**
- [Javier Alejandro Campos Contreras](https://github.com/huebitoo) **(2023432857)**
- [Pablo Esteban Villagran Hermanns](https://github.com/huebitoo) **(2023432857)**

## Tecnologias utilizadas en el proyecto
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,github,vscode,bash,linux&perline=12" />
  </a>
</p>
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=cpp&perline=12" />
  </a>
</p>


## Instrucciones de compilación

### Versión de compilador recomendada y sistemas testeados
El código esta compilado con g++ en linux. Las distribuciones utilizadas en el testeo son Manjaro, Windows subsystem for linux (WSL) y Kali Linux.

La versión de g++ recomendada para compilar el proyecto es **g++ (GCC) 14.2.1** .
RECALCAMOS QUE ES IMPERATIVO EL USO DE **C++ 17** EN ADELANTE.
### Comandos para ejecutar el código 
El repositorio esta compuesto de 2 partes que están aisladas entre sí. Cada parte esta en su propia carpeta que estan diferenciada por  ```parte_1``` y ```parte_2```.

Para compilarlo y ejecutarlo con valores predeterminados, simplemente vaya a la carpeta de la parte que quiere ejecutar y escriba el comando ```make run```.

Si desea utilizar valores personalizados, siga estos pasos:

1. Dirígase a la carpeta correspondiente de la parte que deseas compilar.
2. Ejecuta el siguiente comando para compilar el proyecto:

  ```bash
   make
  ```
  Si no logra compilar con este comando, ejecute este otro comando dependiendo de la parte que desee compilar:

  1. Parte 1:
  ```bash
    g++ -std=c++17 -I include -o main.out src/main.cpp src/monitor.cpp src/utils.cpp
  ```
  2. Parte 2:
  ```bash
    g++ -std=c++17 -I include -o main.out src/MapAbierto.cpp src/fifo.cpp src/interesting_prime_numbers.cpp src/lru.cpp src/lru_time.cpp src/optimo.cpp src/main.cpp

  ```

Luego de compilar, ejecuta el ejecutable ``main.out`` utilizando las FLAGS correspondientes de los ejemplos proporcionados.

### Ejemplos:

- **Parte_1:** Si desea que se generen ``2 productores``, ``5 consumidores``, con un ```tamaño de cola inicial de 1``` y un tiempo de espera máximo de los consumidores de `1 segundo`, el comando sería:

  ```bash
  ./main.out -p 2 -c 5 -s 1 -t 1
  ```

  - Parte_2: Si desea que se hayan ``3 marcos de pagina``, con el algoritmo ```FIFO``` y usando el archivo ```referencias.txt```, el comando sería:
  
  ```bash
  ./main.out -m 3 -a FIFO -f referencias.txt
  ```



