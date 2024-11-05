# Convenciones a seguir tanto para la parte 1 y 2

- Tratar dentro de lo posible y para lo que de sus conocimientos utilizar las funciones de C++ y no las de C (ejemplo, no utilizar malloc y free y preferir smart pointers o en su defecto new y delete). **Puntualizar que puede que nececitemos utilizar alguna libreria de C que nos fuerze a trabajar como se trabajaria en C en esos casos es evidentemente aceptable.**
- Usaremos snake_case si no se explicitamente lo contrario para casos especificos.
- Una excepcion a lo anterior son las clases, que tienen que ser nombradas en PascalCase.
- La documentacion deberia ser preferiblemente en doxygen. Busquen alguna extension para vs code para que les genere la estructura de la documentacion de manera automatica
- No imponemos, y de hecho no recomendamos, el uso de documentacion para cada funcion. Si la funcion es lo suficientemente expresiva y pequeña no es necesario documentar. **Antes de documentar preguntense si lo que estan escribiendo es largo o bien tendrian problemas para entenderlo normalemente.**

- Por tema de librerias y posibles problemas que puede dar, todo el desarrollo tiene que estar hecho en linux. La eleccion de distribucion es libre.