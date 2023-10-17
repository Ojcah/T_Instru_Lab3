# Laboratorio III: Diseño de un sistema de adquisición de datos. Parte II

# *Resultados del Lab3*

## Diseño de GUI

Se muestran el diagrama de bloques generado para la lógica de los controles seleccionados dentro del GUI de LabView, donde es posible apreciar en cierto grado cada una se las secciones; lógica de seleccción de botones, recepción y envió de datos mediante *VISA* y el llamado realizado a la base de datos nombrada "proyecto3".

<p align="center">
<img src="./images/Bloques.jpg" alt="Diagrama de bloques del sistema GUI" style="width:100%;" />
</p>

Este diagrama se basa en el siguiente diseño de ventana.

<p align="center">
<img src="./images/GUI.jpg" alt="Interfaz del la GUI" style="width:50%;" />
</p>

### Base de Datos

Para la base de datos se utilizó el software *SQL Server* para codificar el funcionamiento. Este fue guardado con el nombre "proyecto3", de manera que mediante este titulo se le implementó en el GUI de LabView.

<p align="center">
<img src="./images/BaseDatos.jpg" alt="Código de la Base de Datos SQL" style="width:50%;" />
</p>

Para ejemplificar el funcionamiento de la base de datos se muestran ciertos valores agregados mediante LabView.

<p align="center">
<img src="./images/BaseDatos2.jpg" alt="Ejemplo de los datos guardados en Base de Datos" style="width:50%;" />
</p>

## Circuito armado en placa perforada

En la siguiente imagen se muestra el resultado del montaje en de uno de los canales en la placa perforada, de manera que su uso continuo sea más accesible.

<p align="center">
<img src="./images/Placa1.PNG" alt="Placa perforada con montaje de canal" style="width:45%;" />
</p>

La idea fue implementar optoacopadores como "switches" que permitieran realizar los cambios entre cada una de las escalas de medición que se solicitaban.

Mediante el GUI de LabView se selecciona la escala a observar y se envía mediante *Serial.Write()* al Arduino UNO que lo acciona como un pin digital en alto para el pin seleccionado para cada escala. De manera que la señal en alto de $5 V$ permitiera accionar el optoacoplador y este cerrara el circuito con el amplificador operacional que aplica las ganancias.

<p align="center">
<img src="./images/Placa2.jpg" alt="Placa perforada con montaje de optoacopladores" style="width:45%;" />
</p>

Se muestra el circuito básico de funcionamiento como switch para el opotoacoplador.

<p align="center">
<img src="./images/Placa2_1.jpg" alt="Circuito simulado del optoacoplador como switch" style="width:45%;" />
</p>

Ahora se adicionando el amplificador operacional se vería de la siguiente forma.

<p align="center">
<img src="./images/Placa2_2.jpg" alt="Circuito simulado de switch y amplificador" style="width:55%;" />
</p>

## Mediciones

<p align="center">
<img src="./images/optocoupler.jpg" alt="Optoacoplador para asilamiento electrico" style="width:35%;" />
</p>

<p align="center">
<img src="./images/optocoupler.jpg" alt="Optoacoplador para asilamiento electrico" style="width:35%;" />
</p>

## Demostración del funcionamiento

[Video Demostrativo 1](URL)





