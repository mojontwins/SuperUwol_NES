20151208
========

project.init ();

He aparcado levemente los Cherils (incluso tengo entradas del diario que pasar a este blog) para dar un poco de margen a Davidian para que haga musiquitas. Seguro que cuando monte las ROMs con la música definitiva nos da un subidón y le pegamos a esto el empujón que lo coloque en la recta final.

Mientras tanto, y para hacerme con las últimas versiones de CC65/Neslib (fue un tremendo error no actualizar en cada juego, me he quedado super atrasado, y eso es una putada), voy a empezar un "Proyecto Super Secreto", o PSS, que me servirá para darle una sorpresa de reyes a estos.

No voy a desvelar en qué estoy trabajando en concreto, sólo diré que es para NES y apuntaré algunas ideas. Hoy he hecho todos los gráficos que, en principio, necesito para el gameplay.

Cosas que apuntar, por ejemplo, sobre el juego:

- Habrá tres modos de juego: 1P, 2P Cooperativo, y 2P Versus Mode. 1P será el que conocemos de toda la vida, 2P Cooperativo eso mismo pero con dos jugadores, y el Vs. M. simplemente ciclará todas las fases una a una hasta que los jugadores se aburran.

- En el 2P Vs. M. cada jugador sólo tiene una vida. El número de items que hay que conseguir debe ser siempre impar. El jugador que muere tiene que esperar a que el otro termine la fase. Cuando termina la fase (porque se consigan todos los items o porque ambos jugadores mueran), el que gane se anotará un punto. Si hay empate no se suma ningún punto. En la fase de resumen de puntuación puede elegirse entre seguir o terminar.

A 1UP lo conocemos desde hace bastante. 2UP es una buena amiga que aún no ha salido en ningún güego.

Sobre motor:

- Usaré un motor de inercia al uso, pero parametrizable para poder usar la misma función de movimiento para los dos jugadores (como en Moggy de SMS).

- Creo que el juego será bastante fácilmente portable a SMS una vez terminado.

- Debe caber en 32K+8K, o sea, NROM256. El cartucho debe ser fácil y barato de producir.

- Cada tile de cada pantalla se representa con 2 bits. Eso significa que en el área de juego de cada pantalla sólo hay 4 tipos de tile: fondo, que mata, obstáculo y plataforma. Aparte, el "techo" y el "suelo" pueden tener agujeros. Tanto techo y suelo se representan con 2 bytes cada uno. Cada bit representa un tile.

- Para llenar toda la pantalla NTSC de 256x224, descontando 16 pixels para un marcador, nos quedan 256x208, o sea, 16x13 tiles. Quitando techo y suelo, el área de juego comprenderá 16x11 tiles. 16x11=176; 176/4=44 bytes; 44 + 4 = 48 bytes por pantalla, lo que está genial.

- Debe haber wrap-around. Tengo que ver como iba el tema de los sprites en NES. Sé que por un lado simplemente desaparecían, creo. En el peor de los casos habrá que recortar 1 tile de cada borde de la pantalla. Debo hacer pruebas antes de decidir (aunque creo que en Sir Ababol se veía bastante bien el tema).

- 4 tipos de tile parece muy poco, pero es que tengo 4 sets de cada tipo, más 4 paletas diferentes. Además, 4 sets de suelo + techo. Eso dan muchas combinaciones, en concreto 4 fondos x 4 plataformas x 4 obstáculos x 4 paletas x 4 suelo/techos = 1024 combinaciones. Por supuesto, no necesitaré tantas. Necesito, eso sí, una función de combinatoria que me elija combinaciones con la suficiente variedad. En total habrá 55 fases (vaya pista), así que lo suyo es apuntar a 64, que es 4x4x4, y juntar cosas. Por ejemplo, combinar 4 paletas con 4 plataformas+fondos con 4 obstáculos+suelo/techos. De este modo habrá 9 combinaciones sin usar, pero nadie se va a morir.

Y poco más. A ver si mañana hago las primeras pruebas, pinto algunas pantallas, escribo un conversor, y hago el esquema del proyecto y la función que dibuja cada pantalla.

20151209
========

Voy a hacer más trabajo inicial mientras, a trozos, voy terminando mapa/enemigos de Bootee. Estoy pensando en la mejor forma de que esto sea factible de portar a SG-1000 y SMS, que tienen pantallas de 192 pixels de alto frente a los 224/240 de la NES.

Si hago los mapas de 16x12 tiles, ocuparían toda la pantalla de SG-1000/SMS, pero podría comerme una fila de arriba o de abajo para unos marcadores minimal. El problema es que teniendo un area de juego de 256x192 nos deja 32 pixels libres en NTSC y ¡48! en una NES PAL. A lo mejor es mucha pantalla.

He pensado que a lo mejor no quedaría mal si duplico una fila de chars arriba y abajo (16 pixels) y pongo el marcador arriba separado 8 pixels (o con un marco) del area de juego.

Creo que lo haré así. 

He creado un tileset básico con los 5 tipos de tile (4 para el mapa, y uno para representar las monedas). Pasaré como pueda algunas de las pantallas del original (12x10 -> 16x12!!) y luego haré el conversor. Cuando esté y tenga los primeros datos, montaré el proyecto y lo dejaré con el renderer de pantallas listo.

~~

Ayer entre una cosa y otra apenas escribí aquí, así que hoy (que es el día siguiente) completo la entrada someramente: 

- Conversor terminado y funcionando.
- Esqueleto del motor (usando los nuevos cc65 y neslib) montado.
- Experimentos hechos. 
- Idea loca [*].
- Renderer de pantallas ahí-ahí (fallan las sombras).

[*] Idea loca: el mundo es cíclico, y hay problemas con el wrap-around (si se sale por la izquierda, desaparecen partes del sprite). Hay una forma de enmascararlo ocultando una coumna del display a la izquierda del todo, pero se me antoja un tanto feúno... Entonces se me ha ocurrido ¿y si centramos el scroll en el punto central en "X" de ambos jugadores / el jugador 1? Podría molar, y si no me gusta no tengo más que desactivarlo (el motor sigue igual). Es más, podría ofrecerlo como opción ingame.

20151210
========

En un momento me puse a revisar el renderer y me di cuenta de qué fallaba con las sombras: al intentar pintar las sombras de los tiles de fondo de la columna "0" (que deberían verse afectados por los de la columna "15", ya que el espacio horizontal en este juego es cíclico) la información aún no estaba "ahí". Así que lo que hago es pintar primero el primer plano y luego relleno el fondo con sombras sobre eso. Y fetén.

Ahora voy a integrar los enemigos lineales de MK1 lo más rápido que pueda y a tomar wind.

~

Vaya por diore... Todo iba chuli hasta que me he dado cuenta de que en este juego voy a usar sprites 8x16 y el conversor no los soporta. Ahora, manos a la obra. Espero tenerlo rápido.

Debería ser igual que el de sprites normales pero tomando trozos de 8x16. El cambio será almacenarlos en el TS y tal. Lo malo es que la repetición va a ser mínima :-/ No ando sobrado de patrones para sprites, esperemos que entre todo.

~~

Bueno, modificado mkts... ¡Y parece que exporta bien! A ver si puedo terminar de apañar los enemigos hoy, aunque mucho me temo que al churum le queda poco tiempo de siesta...

~~

Phew!! In before the lock! Enemigos funcionando. Al menos, los lineales, que era la idea. Ahora ya no puedo seguir. Lo próximo: monedas girando. Empleando la mínima RAM posible!

~~

Hecho, pero tonto de mí no me había acordado de que hay 8 sprites como máximo en horizontal, lo que significa que no puede haber más de 4 monedas en horizontal (si no se cruza otro sprite)...

He intentado implementar una rutina para el parpadeo pero por lo pronto no tengo demasiados buenos resultados. Investigaré más sobre este tema, o de lo contrario me lo curraré para que las monedas sean tiles :-/

~~ 

Me temo que tendrán que ser tiles. Pero ¿Podré actualizar hasta 60 tiles en cada frame? ¿Tendré que dividirlo?

~~

Tengo que pensarlo. Está claro que si quiero sprites voy a tener que dejar el parpadeo (por ahora tengo una solución medio qué) pero tendré que intentar evitarlo a priori cuando (re)diseñe las fases. Nada de más de 4 monedas en linea, nada de enemigos entre las monedas. Restricciones a coscorrón. Pero creo que así será la única forma de que quede chulo. Lo fácil sería tontificar los gráficos y hacerlo por tiles... Pero es que ahora mismo está tan bonito...

Por ahora me quedo así. Con sprites. Y a currarme las fases.

20151211
========

Hoy voy a intentar meter a Uwol / Meemaid. Por lo pronto he creado la estructura con todo el metaspriteset y los gráficos parecen bien importados. 

Cogeré el mínimo necesario de MK1 y empezaré a integrarlo. Hay que tener en cuenta que los parámetros principales px, py, pvx, pvy, prx, pry, pj, pctj, pfacing, pjb, pgotten, ppossee deben ser arrays de 2 posiciones para poder tener simultaneamente a Uwol y Meemaid.

Voy a empezar...

~~

Qué difícil es arrancar un proyecto nuevo, coño. He programado el motor de Uwol / Meemaid (al menos la selección de frames y todo el axis vertical), pero resulta que mkts no me estaba generando bien los metasprites.

Arreglado eso parece que hay algo muy raro que hace que las coordenadas se me vayan a tomar por culo ¿qué estoy haciendo mal?

~~

Vaya - todas las hostias de hoy se deben a que hay un error en el compilador que hace que el código para un ">> 6" se genere de forma incorrecta. O sea, he perdido toda la tarde y el problema no era mío.

He abierto un issue en github, a ver si lo reparan.

Mientras tanto, me temo que volveré a la vieja 2.13. A ver si puedo hacer que la nueva neslib funcione en 2.13.3... Si no, cambiaré la precisión a 4 bits (más que suficientes, ya que mi valor mínimo es 8, que sería un 2 en 4 bits). De hecho, antes de cerrar por hoy, voy a ver si el bug se da con 4 bits (según la explicación en nesdev, todo parece indicar que no).

Hilo en nesdev: http://forums.nesdev.com/viewtopic.php?f=2&t=13616&p=160508#p160508
Issue en github: https://github.com/cc65/cc65/issues/244

Probado. Con 4 bits va bien. Voy a hacer los cambios necesarios y a cerrar por hoy. Qué rabia. Quería tener a Uwol / Meemaid dando saltos, pero me encasquillé con esta mierda. Mañana será otro día.

20151212
========

Bueno, ya tengo a Uwol y Meemaid pegando saltos. Intenté hacer la paranoia del scroll pero con 2P es glitchy y no sé si será un mareo. Me lo pensaré un poco más. Por ahora, desactivado.

Próximas cosas:

[X] Tiles que te matan
[X] Coger monedas
[X] Colisión con los malos / perder ropa
[X] Item ropa / recuperar ropa

En 2P COOP, el item ropa solo puede conseguirse si estás desnudo, y sale un item ropa para cada uno. En 2P VS, solo sale uno y se puede coger aunque estés vestido, para putear.

20151213
========

Antes de seguir tengo que optimizar. Me ha dicho David que el juego pierde frames en modo NTSC. Tengo que tratar de ganar ciclos en todas las rutinas. Una de las principales candidatas es la que envía los sprites desordenados a la OAM.

Creo que el cambio pasa por hacer la estructura de tamaño fijo. Los elemenos que no existan en cada fase (enemigos de menos, monedas de menos) deben enviarse igualmente, pero fuera de la pantalla. Así la velocidad será fija por nivel y controlaré mucho mejor todo. Además, se tardará menos tiempo en el proceso porque no habrá que estar poniendo a cero la estructura temporal de sprites ni haciendo comprobaciones a la hora de enviarlos a la OAM.

Si hemos dicho que habrá un máximo de 15 monedas, el máximo de metasprites gestionados por el sistema será de 19, lo que viene de la hostia porque es un número primo. Eso significa que con un incremento de 2 lo tengo. Puedo incluso precalcular los ordenes.

Voy a ello...

~~ 

Bueno, ya he conseguido ir a velocidad fija en todas las fases... Pero en NTSC pierdo el frame y va a 30fps. Tengo que optimizar. Y si no es suficiente, encontrar el valor máximo de objetos que puedo procesar.

Lo que me jode es que ni siquiera están las colisiones :-/

~

Creo que va a haber que tomar medidas drásticas. Ahora los jugadores son un array de 2 posiciones y la llamada a la función que los mueve está parametrizada.

Creo que lo suyo va a ser duplicar la función y usar variables normales. Hago copia de seguridad de /dev y meto el cambio, a ver.

~~

Haciendo la guarrada de desdoblar variables y funciones ¡ya tengo tiempo suficiente de frame! Lo malo es eso, que tengo tela de código duplicado. Lo bueno es que la mayor parte de ese código no lo tengo que tocar para nada. Además, puedo hacer todos los cambios con el modo 1P activo y sólo para Uwol y luego no es más que CTRL+C, CTRL+V, y Find & Replace "_uwol" por "_meemaid". Tampoco es tan malo ¿no? Además, nadie mira el código luego.

Aún así, sigo andando por el filo de la navaja, así que mejor que optimice todo lo que pueda.

Estoy dándole vueltas a la mejor forma de detectar las monedas. Lo más directo es hacer una colisión por caja en el bucle que mueve las monedas, pero quizá sea mejor pasar de ahí y hacer una detección en dos partes: primero detectando que el jugador toca un tile donde hay una moneda (siempre andan alineadas a tile, recordemos que se ponen en el mapa), y luego buscando de qué moneda se trata. Con comprobar el punto central del jugador tengo suficiente. Recordemos que aquí los rectángulos lógicos de cada jugador miden 8x16 pixels, así que el centro sería en prx+3, pry+7. Con mirar un ATTR ((prx + 3) >> 4, (pry + 7) >> 4)) lo tengo. Y luego un bucle de cinco vueltas. Precalculo un rda con yy*16+xx basándome en esas coordenadas y lo comparo con las entradas en la ROM, que están en ese formato. Es una comparación de un número con otro, a fin de cuentas.

El otro método sería pasar a ese formato la ubicación del centro del jugador en cada frame, y aprovechando el bucle que mueve las monedas comparar el dato en rom con dicho valor.

La primera forma solo implicaría dos comprobaciones por frame en modo de dos jugadores, aunque luego tenga ahí un bucle metido. Si eso hace que pierda un frame de vez en cuando me da igual si lo que gano es 30 comprobaciones menos por frame en general.

¡Hay que mirar cada ciclo! ¡Que triste es de pedí, pero más triste es de robá!

~~ 

Monedas cogiscibles (con animación que, conociéndome, acabaré cambiando mil veces).

Colisionemos ahora con los enemigos...

~~ 

Probando me he dado cuenta que la búsqueda de la moneda en la colisión ralentiza el juego. Tengo que:

- Desactivar la moneda en el buffer de pantalla.
- Codificar el nº de la moneda en el nibble alto del byte!

~

Hecho. Lo dejo por hoy. Lo próximo que haré será:

- Tema camiseta. Con los tres comportamientos diferentes según sea 1P, 2P_COOP o 2P_VS.
- Detección de que no hay más monedas, aparición de las flechas (tiles y sprites!). Desaparición de los enemigos
- Tiempo. Cálculo de tiempo. Que aparezca Fanty cuando se acabe el tiempo.

^ JOIN WHEN GOOGLE DRIVE BEHAVES.

20151214
========

Lo que tenía para hoy, en principio, tenía que ver con el tema de la camiseta que aparece cuando el jugador se da contra un enemigo o los pinchos y pierde la ropa.

Es necesario programar tres comportamientos diferentes según el tipo de juego:

- Modo 1P - Aparece una camiseta en un punto random.
- Modo 2P_COOP - Aparece una camiseta en un punto random. Puede haber dos camisetas. Sólo se puede coger una camiseta si no tenemos ropa.
- Modo 2P_VS - Aparece una camiseta en un punto random. Sólo aparece una. Se puede coger en cualquier momento.

Creo que puedo generalizar y hacer 1P y 2P_VS básicamente con el mismo código (salvo por la colisión extra). No tener a los jugadores en un array es un coñazo, pero ha sido un sacrificio necesario para tener esto funcionando en NTSC a 60Hz.

La camisetas sí las tendré en un array, si no la liamos ya con las combinaciones.

~~

Bueno, a falta de probar un poco más las camisetas están metidas con código mínimo. Soy bueno :D

Ahora voy a controlar que acabamos la fase.

~ 

He metido millones de cosas, pero ahora, por alguna razón, cuando golpean a uwol y tiene que aparecer la camiseta, se cuelga. Sin ningún motivo aparente...

Es en la llamada a clothes_move. Se furriña todo, no lo entiendo. No hago más que contar los metasprites que mando al mixer y siempre suman 19. No sé qué se me estará escapando.

Voy a descansar de esto, tanto cococrash se me atraganta XD

~~

He visto, mirando guarripeichimente, que cuando toco a un enemigo el número de sprites enviados al mixer se incrementa en 2. 

¿Qué es lo que no estoy controlando?

~~

¡Poniendo marcas veo que los dos sprites de los enemigos activos están repetidos! Y además de salir intergalados, las coordenadas salen incrementadas en la segunda copia. Es como si se ejecutase de nuevo el bucle.

Esto suena a variable global reutilizada :D

~~

Eso va a ser. Clothes_create utiliza gpit, que es con la que se itera en los enemigos. Debería ir cambiando esto :*)

~

Esto está arreglado. Ahora voy a ver un par de detalles que no molan:

- No detecta bien qué camiseta tiene que consumir si hay dos (siempre consume la primera) -> revisar en player.h. / BAH, estaba poniendo || en vez de |. Vaya patato estoy hecho.
- La función que actualiza el tile durante VBLANK no está poniendo bien los atributos (no los está poniendo, vaya) -> revisar en printer.h / NO, lo está haciendo bien, lo que pasa es que soy tonto y me he confundido de paleta.

~~

Ahora no tengo ganas de rayarme, y hay cosas que tengo que diseñar, como los marcadores, que ya va siendo hora de que salgan.

En los modos de 1P / 2P_COOP / 2P_VS las cosas que salen en el marcador son levemente diferentes. Voy a hacer aquí una lista para orientarme...

Tengo que añadir una puntuación (no sé para qué).

Según he visto en otros juegos, se deja una linea vacía arriba del todo incluso en NTSC (2 en PAL) por temas de teles comilonas.

Modo 1P

- Vidas
- Tiempo restante
- Total de monedas (acumulado)
- Level (piso/pantalla)
- Score

```
	0               1
	0123456789abcdef0123456789abcdef
	1UP=XX    TIME=XX    COINS=00XXX
	LEVEL=XX/YY          SCORE=ZZZZZ
```

Modo 2P Cooperativo
- Vidas Uwol, Vidas Meemaid
- Tiempo restante
- Total de monedas (acumulado)
- Level (piso/pantalla)
- Score

```
	0               1
	0123456789abcdef0123456789abcdef
	1UP=XX  SCORE=ZZZZZ  COINS=00XXX
	2UP=YY  SCORE=ZZZZZ      TIME=XX
```

Modo 2P vs
- Monedas recogidas por Uwol
- Monedas recogidas por Meemaid

```
	0               1
	0123456789abcdef0123456789abcdef
	1UP COINS=XX            TIME=XXX
	2UP COINS=YY
```

Asín va a caer. Voy a hacer funciones para actualizar el hud, del palo de hud_add_coins, hud_add_score, hud_set_time, hud_set_coins_1up, hud_set_coins_2up; vidas y level son fijos para todo el nivel y los pintaré antes de empezar.

Tengo que ver como montar la pantalla... 

~~

He metido toneladas de hud y todo está super bonito. Esto está casi (al menos la parte del motor del juego). Quedan detalles, mejores transiciones... Y luego la pirámide y tal.

Pero antes quiero ponerme a meter la música.

~~

Tengo que hacer una lista de los sonidos que voy a necesitar:

```
	- Salto					Jump #3 		2
	- Coger Monedas 		Laser 			5
	- Ultima Moneda 		Door 			7
	- Pincho 				Knife 			8
	- Colisión enemigo 		Kill 			4
	- Tic tic  				Wrong 			6
	- Coger camiseta 		Item #2 		3
	- Start 				Start #2 		1
	- Select  				Select #2 		0
```

Tengo también 4 canales de efectos de sonido, y debo usarlos de forma sabia.

Lo suyo es dejar un canal para Uwol y otro para Meemaid, otro canal para los enemigos, y otro para los efectos de monedas / objetos. En el de enemigos meteré "última moneda" para que no se pise con otras cosas, a ver.

```
	0 -> UWOL
	1 -> MEEMAID
	2 -> ENEMS
	3 -> LEVEL
```

~~ 

Antes de irme a fregal... Voy a pensar en Fanty. Fanty irá en el slot 4 para enemigos. Estoy cruzando los dedos para que eso no me ralentice el tema. Si se ralentiza, no tengo más que sustituir uno de los enemigos como en el original. Pero no me gustaría tener que acudir a esa solución.

Lo primero es calcular el tiempo. Voy a mirar la fórmula que usa Shiru en el de Megadrive, que también va a 50/60fps, y uso algo parecido. Porque, sinceramente... me da miedo mirar mi código de Uwol de Spectrum de hace siete años.

Tengo que controlar el tiempo usando ticks. Tengo el frame counter pero para contar de 50 en 50 no me sirve, así que dedicaré un unsigned char especial para contar los frames e ir decrementando el tiempo.

En los últimos 5 segundos debe sonar el "TIC TOC".

Cuando llegue a cero, hago un flash molón de la pantalla (el sencillo, el que tira frames) y aparece Fanty. La música cambia al time attack y dejo que todo siga su curso.

Para Fanty usaré el de MK1 desactivando las colisiones con el escenario. También puedo simplificar la cosa teniendo en cuenta que siempre es el enemigo número 4. Quitar las variables de índices de ahí me simplificará muchísimo las cosas y ahorrará código y ciclos.

Voy, al menos, a adaptar el código antes de irme y cerrar por hoy.

20151215
========

Fanty metido y funcionando. Ahora en realidad el problema es decidir qué hacer cuando hay dos jugadores. Meter dos fantys está totalmente descartado.

El problema estriba en elegir un target para fanty. Hay mil posibilidades y no sé cual es la mejor.

En un principio puse que siguiera al que estuviera más cerca, pero no creo que funcione muy bien.

Ahora mismo está así:

- Persigo a quien más monedas tiene.
- Si tienen las mismas monedas, elijo al azar.
- Si el que está elegido no está disponible (muerto o parpadeando), persigo al otro.

Pero creo que lo he hecho mal, ahora que lo pienso. Revisaré la lógica

~~

Creo que ya lo tengo.

Las cosas que parecen más sencillas terminan siendo las más complicadas. En este juego vamos a tener dos: la puta IA del Fanty (decidir a por quien va) y el tiempo máximo para cada pantalla antes de que salga.

Como ya tengo medio funcionando todo esto, voy a meter las vidas, probar el VS. y un par de cosas más (más que nada para dejar listos y cerrados los marcadores) y me pondré con la pirámide.

Quería hacer un efecto chulo de scroll. La pantalla de arriba para el juego, la de abajo para la pirámide. Lo que pasa es que no puedo cambiar la pantalla del juego sin apagar todo el display. Eso me deja menos opciones. O eso, o me invento un "engaño", algún tipo de flash o algo así. Tengo que pensar en algo que me permita apagar momentaneamente la pantalla.

De todos modos voy a ir escribiendo código para pintar la pirámide en la pantalla de abajo (en $2800).

~~

Pasando de scroll, es un dolor e iba a quedar mal de todos modos.

Joer, qué trabajo mé está costando que quede bonito. Voy a ver si diseño bien esto para que quede guay en 1P o 2P_COOP...

```
0               1
0123456789abcdef0123456789abcdef
  1P=00  SCORE=XXXXX  COINS=XXX  
  2P=00  SCORE=XXXXX  
```

20151216
========

Tengo que hacer algunos arreglos: 

- La detección si se debe o no mostrar una salida sólo debe no hacerlo si sobre el tile en el que aparece hay un tile OBSTÁCULO, y no cualquier tile != 0. [X]
- El Fanty mira en la dirección incorrecta. Debe mirar al jugador. [X]
- La pantalla de la pirámide debe terminar tras unos segundos. [X]
- Meter PAUSE.

Y luego la pantalla de título.

~~

¡Todo hecho! Además, el pause está hecho guay, ya que se sigue ejecutando todo el bucle principal pero sin mover enemigos y jugadores, con lo que las animaciones siguen ciclando: monedas, camiseta, flechas de la salida... Así queda mucho más pro.

Es increíble como estos pequeños detalles hacen que la experiencia de juego mejore tanto. Son más coñazo de programar pero, joder, merece la pena. 

Ahora a la pantalla de título. Tengo que hacer el mejor trabajo posible con los pocos recursos que tengo (no quedan demasiados tiles).

~~ 

Cadenas para el título:

```
	# 2015 THE MOJON TWINS (5->)
	PRESS START! (10->)
	STARRING (12->)
	UWOL & MEEMAID (9->)

	1 PLAYER (12->)
	2 PLAYER
	VS. MODE
```

~~

¡¡Listo! La pantalla de título ha quedado de la hostia de chula. Ahora lo que me queda (aparte de un porrón de fases y pulir y más pulir) es:

- Pantalla de VS. Mode
- Pantalla de Game Over.
- Pantalla de Repite la Pirámide.
- Pantalla de Tu Picha/Totete es Magno.

Me quedo sin tiles. A ver cómo lo hago para que tenga más "age" que un montón de letras. Por lo pronto, el marco de la pantalla de título que es muy chuli lo puedo reaprovechar. Aparte de eso, me quedan 43 patrones. Puf.

Voy a empezar por el VS. mode. Necesito los numeracos grandes que hice para moggy y que pienso rapiñar vilmente, más una función para imprimirlos que pienso rapiñar igual de vilmente.

~~

VS. Screen metida y funcionando. Ahora sólo me quedan los tres finales del juego del modo normal/cooperativo: fame over, repite la pírámide, totete máximo.

~~

Estoy con los endings, pero apunto esto:

```
Davidian, [16.12.15 17:32]
hostia

Davidian, [16.12.15 17:32]
me han pegao un meco

Davidian, [16.12.15 17:32]
y han aumentao los segundos
```

20151217
========

Se me había olvidado que al revisitar las habitaciones tenían que estar sin monedas ni enemigos, y con fanty. Lo de el fanty será automático, no hay problemas.

Hecho. Pero no lo podré probar aún - antes tengo que meter las fases para que sea posible darle una vuelta a esto :-D

Hasta entonces, a ver si soy capaz de reproducir lo que me dijo Davidian ayer, a ir metiendo las músicas nuevas que me vaya pasando, y a seguir puliendo detallicos, que seguro que aparecen bastantes más. Como, por ejemplo, que se pueda usar `PAD_A` para seleccionar y no solo `PAD_SELECT` (en el menú).

También iba a meter nuestra pantalla de splash típica (la que sale en Sir Ababol, Jet Paco y Sgt. Helmet) Pero no tengo patrones libres para el logo mojón. Creo. Voy a ver.

~~

Otra cosa que me falta por meter es poder morirse al salir de la pantalla por abajo, voy a ello. He modificado la primera pantalla para tener este item a mano para probar.

~~

Hecho. Por el momento sólo queda esperar haciendo niveles y puliendo cosas. Ah, voy a mirar lo del logo antes que nada. A mí me la pelan estas cosas, pero todo sea por uniformidad - - - Sí cabe. Voy a meterlo.

~~

20151218
========

Jodó, se me había olvidado que quería meter plataformas móviles y sierras para darle más age a esto, voy a probar a irlas activando y tal. Primero, plataformas móviles. He metido una en la primera pantalla para tenerla a manow.

También he estado haciendo trabajo para la versión de SG-1000. En esta versión y en la de SMS tenemos el grave problema de que no hay espacio suficiente para todos los gráficos de sprites en la tabla de patrones, ya que estas máquinas no permiten espejar por hardware y hay que almacenar los sprites en ambas direcciones.

La solución pasa por cambiar al vuelo los patrones en VRAM en cada frame. Esto hay que hacerlo durante VBlank. En SMS hay que copiar 6 patrones por dos personajes por 32 bytes, o sea, 384 bytes. En SG-1000 hay que copiar 8 patrones por dos capas dos personajes por 8 bytes, o sea, 256 bytes. Según Sverx, debería dar tiempo a hacer esto en VBlank si tengo todo preparado, por eso tengo que darle muchas vueltas para ver cómo organizarme los datos y que la actualización sea lo más inmediata posible. Tengo además que hacer mis pruebas para hacer esto y crearme algún tipo de wrapper que integre metasprites con desordenación con recarga de patrones. Muy dale fran, pero el resultado merece tanto la pena que no me importa darle tanto fran.

Lo apunto aquí para que no se me olvide cuando empiece las versiones de SEGA:

```
	{
	   (game logic)
	   
	   SMS_initSprites ();
	   Add metasprite for 1UP, using patterns 0-5
	   Add metasprite for 2UP, using patterns 6-11
	   Add the rest of the metasprites, out of order
	   SMS_finalizeSprites ();

	   Calculate address of 1UP patterns data for current cell
	   Calculate address of 2UP patterns data for current cell

	   SMS_waitForVBlank ();
	   UNSAFE_SMS_copySpritestoSAT ();
	   Copy 6 patterns (192 bytes) to VRAM 0-5 to update 1UP current cell
	   Copy 6 patterns (192 bytes) to VRAM 6-11 to update 2UP current cell
	}
```

~~

Plataformas móviles metidas con éxito! ¿Y las sierras? ¿Funcionarán? Habrá que adaptar miles, pero ... Voy a hacer una pausa y luego pruebo. Además, no tienen sprite.

¡Creo que meterlas es fliparse un poco porque apenas me quedan patrones! A lo mejor está bien dejar el juego como está... No sé. Me lo pienso.

~ Me lo acabo de pensar. Creo que es más importante dejar sitio para la ogete murciana. Si al final, con todo dentro, cabe, le meto fran.
 ~~

 
~~

Urm - tengo que darle otra vuelta. Con las últimas adiciones se ralentiza en 2P + 3enems. ARGH!

Back to the drawing board ... A intentar ahorrar de donde sea!

Que sí, que lo conseguí.

Y ya.
