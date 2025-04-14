# FdF
[Español](README.md) | [English](README.en.md)
| 42 Project| Descripción |
| ----------- | ----------- |
| <a href=""> <img src="https://github.com/0bvim/42-project-badges/blob/main/badges/fdfe.png?raw=true" /></a> | FdF es un proyecto gráfico desarrollado en C que permite representar mediante proyecciones isometricas modelos tridimensionales a partir de modelos almacenados en archivos con extensión .fdf donde la información de las distintas componentes xyz están dentro de matrices en 2D. Utiliza la librería gráfica MiniLibX, desarrollada por 42, para crear ventanas, renderizar píxeles e interactuar con eventos del teclado.|

## 🎯 Objetivo 
El objetivo principal del proyecto FdF es representar paisajes en forma de malla tridimensional, a partir de un archivo de entrada con datos de alturas (eje z). A través de diferentes proyecciones se consigue simular la tridimensionalidad de diferentes superficies sobre una pantalla 2D, dibujando líneas que conectan cada punto del modelo.

## 🛠️ Implementación

El flujo del programa se organiza en los siguientes componentes:

### 🧱 Carga y gestión del modelo

El modelo se carga desde un archivo de texto que representa un mapa 2D con alturas (y opcionalmente colores). Este proceso se realiza en `fdf_model_utils.c`, donde:
- Se cuenta el número de filas y columnas (`get_num_rows`, `get_num_cols`),
- Se carga el contenido del archivo en una estructura de tipo `t_model`, que contiene dos matrices: una para las alturas (`**model`) y otra opcional para los colores (`**colors`).

```c
typedef struct s_model_data {
	int **model;
	int **colors;
	int num_rows;
	int num_cols;
} t_model;
```

### 🖼️ Creación de la ventana e imagen
La ventana gráfica se inicializa mediante setup_win, donde se configuran la resolución en pixeles (3000x2000 en mi caso), el puntero de ventana, y una imagen sobre la que se dibujan los píxeles (t_img), además de parámetros como el zoom (scale) y el offset de los ejes x e y.

```c
typedef struct s_mlx_data {
	void *mlx_ptr;
	void *win_ptr;
	t_model *fdf_model;
	t_img img;
	int offset_x;
	int offset_y;
	unsigned int scale;
	int angle;
} t_mlx_data;
```
### 🎨 Renderizado de imagen
La imagen final es construida píxel a píxel sobre una estructura de imagen (img_pixels_ptr) usando set_pixel y set_bg_img.
Para cada punto del modelo, se aplican transformaciones para proyectar los puntos 3D sobre un plano 2D utilizando dos tipos de proyecciones:
- **Proyección Isométrica** (compose_iso, compose_rotate, draw_fdf_iso): Para la parte obligatoria se utiliza compose_iso, que permite generar una proyección isométrica y para la parte bonus se cambia por compose_rotate, que funciona igual que el anterior pero con más cálculos que permiten rotar el modelo con respecto al eje un determinado ángulo.
- **Proyección Caballera** (compose_cav, draw_fdf_cav): una proyección alternativa muy usada en ámbitos de dibujo ténico.
Ambas convierten coordenadas del modelo en puntos en pantalla (t_dot) y luego trazan líneas entre ellos usando el algoritmo de Bresenham implementado en **draw_bresenhan_line.c**.

### 🌈 Gestión de colores
Los colores pueden definirse por punto en el archivo de entrada, o generarse como degradado lineal entre dos extremos (get_gradient_color). Las funciones de fdf_colors.c permiten interpretar estos valores y convertirlos en valores RGB.

```c
typedef struct s_colors {
	int color0;
	int color1;
	int step;
} t_colors;
```
### 🔁 Manejo de eventos
El control del programa se realiza desde el teclado (handle_keys) permitiendo el cambio de perspectivas, modificar la escala, desplazar y rotar la vista del modelo. Y por supuesto si se presiona la tecla ESC el programa finaliza correctamente sin tener fugas de memoria.

## 🚀 Bonus
Una vez completada la parte obligatoria, se implementaron una serie de mejoras al proyecto base, entre ellas están:
- **Una proyección extra:** Perspectiva caballera al presionar la tecla 'C'. ✅
- **Zoom:** Se puede hacer zoom de la perspectiva presionando '+' y se puede alejar presioando '-'. ✅
- **Translación:** Se puede desplazar la vista de la perspectiva pulsando las teclas WASD. ✅
- **Rotación:** Se puede rotar el modelo unos grados a la derecha o a la izquierda pusando  '←' o '→'. ✅
