

#include <stdio.h>

#define MAX_P 100
#define MAX_CHAR 30

struct inventario {
  int id;
  char nombre[MAX_CHAR];
  char categoria[MAX_CHAR];
  float precio;
  int stock;
};

// añadir nuevo producto

void agregar_producto(struct inventario p[MAX_P], int indice) {

  printf("\n   agregando nuevo producto...");
  printf("\n ID: ");
  scanf("%d", &p[indice].id);
  printf("\n NOMBRE: ");
  scanf("%s", p[indice].nombre);
  printf("\n CATEGORIA: ");
  scanf("%s", p[indice].categoria);
  printf("\n PRECIO: ");
  scanf("%f", &p[indice].precio);
  printf("\n STOCK DIPONIBLE: ");
  scanf("%d", &p[indice].stock);
}

// dado el id del producto mostrar datos asosiado
void datos_producto( struct inventario p[MAX_P], int idProducto,int n) { // el indice sera el que se modifica id = indice
  int i,encontrado=0;
  for (i = 0; i < n; i++){
  if(idProducto == p[i].id) {
    printf("\n\nmostrando datos del producto...\n");
    
      printf("\n NOMBRE: %s", p[i].nombre);
      printf("\n CATEGORIA: %s", p[i].categoria);
      printf("\n PRECIO: %.2f", p[i].precio);
      printf("\n STOCK DIPONIBLE: %d", p[i].stock);
      encontrado = 1;
      break;
    
  }
  if (!encontrado)
    printf("\n el ID no existe");
  }

}

// retornar el valor de stock asosiado
void stock_disponible(struct inventario p[MAX_P], int idProducto,int n) { // devolver el .stock
  int i,encontrado=0;
  printf("\nSTOCK DISPONIBLE... ");
  for (i = 0; i < n; i++){
    if (idProducto == p[i].id) {
    
   
      printf("\nel stock disponible es: %d", p[i].stock);
      encontrado = 1;
    } 
    if (!encontrado)
    printf("\n el ID no existe");
  }
}

//funcion mostrar todos los id disponibles

void mostrar_id_inventario(struct inventario p[MAX_P], int n) {
    
  int i;
  printf("\nMOSTRANDO IDS DISPONIBLES...");
  for (i = 0; i < n; i++) {
    printf("\n %d", p[i].id);

  }
}


int main() {
  int idp, i, cant;
  struct inventario p[MAX_P];
  int op;
  

  // MENU
  do {
    printf("\n\n*****   SUPER AHORRO MARKET   *****\n");
    printf("\n [1]. añadir producto: ");
    printf("\n [2]. mostrar datos de un producto: ");
    printf("\n [3]. stock disponible (producto)");
    printf("\n [4]. salir");
    printf("\n : ");
    scanf("%d", &op);
    if (op > 5)
      printf("ingrese un valor correcto");

    switch (op) {
    case 1:
      printf("\n  Cantidad de productos: ");
      scanf("%d", &cant);
      for (i = 0; i < cant; i++)
        agregar_producto(p, i);
      
      break;
    case 2:
      printf("\n ingrese ID del producto: ");
      scanf("%d", &idp);
      datos_producto(p, idp,cant);
      break;
    case 3:
      printf("\n ingrese ID del producto: ");
      scanf("%d", &idp);
      
        stock_disponible(p, idp,cant);
     break;

    case 4:
      printf("\n **programa terminado**\n");
    }

  } while (op != 4);

  return 0;
}