#include <iostream>
#define DIM 1000
using namespace std;
template <typename N>
class Producto{
    public:
    N id,precio,stock;
    Producto(N _id=0,N _precio=0,N _stock=0) : id(_id),precio(_precio),stock(_stock){}
};
template <typename T, typename S>
class Pedido{
    public:
    T fecha,cliente;
    Producto<S> productos[DIM];
    int cantidades[DIM],cantidad;
    Pedido(T _fecha="",T _cliente="") : fecha(_fecha),cliente(_cliente),cantidad(0){}
    void agregarProducto(Producto<S>& producto,int cantidadProducto) {
        if (cantidad < DIM) {
            productos[cantidad] = producto;
            cantidades[cantidad] = cantidadProducto;
            cantidad++;
        }
    }
    float totalProductos(){
        float suma=0;
        for(int i=0;i<cantidad;i++){
            suma+=cantidades[i];
        }
        return suma;
    }
    float precioTotal(){
        float suma=0;
        for(int i=0;i<cantidad;i++){
            suma+=productos[i].precio*cantidades[i];
        }
        return suma;
    }
    float precioTotalConIva(){
        float suma=0,iva=0.15,sumaIva=0;
        for(int i=0;i<cantidad;i++){
            suma+=productos[i].precio*cantidades[i];
        }
        return suma+(suma*iva);
    }
    void mostrarPedido(){
        cout<<endl<<"Fecha del pedido: "<<fecha<<endl;
        cout<<"Cliente: "<<cliente<<endl;
        cout<<"Cantidad de productos: "<<totalProductos()<<endl;
        for(int i=0;i<cantidad;i++){
            cout<<"Id del producto: "<<productos[i].id<<endl;
        }
        cout<<"Precio total del pedido: "<<precioTotal()<<endl;
        printf("Precio total del pedido mas IVA (15%): %.2f",precioTotalConIva());cout<<endl;

    }

};

int main(){
    int n;
    cout << "Ingrese el numero de pedidos: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Producto<float> producto;
        cout<<"Ingrese el ID del producto: ";
        cin>>producto.id;
        cout<<"Ingrese el precio del producto: ";
        cin>>producto.precio;
        cout<<"Ingrese el stock del producto: ";
        cin>>producto.stock;
        fflush(stdin);
        Pedido<string, float> pedido;
        string fecha, cliente;
        cout<<"Ingrese la fecha: ";
        getline(cin, fecha);
        pedido.fecha = fecha;
        cout<<"Ingrese el nombre del cliente: ";
        getline(cin, cliente);
        pedido.cliente = cliente;
        int cantidadProducto;
        cout<<"Ingrese la cantidad del producto: ";
        cin>>cantidadProducto;
        cin.ignore();
        pedido.agregarProducto(producto, cantidadProducto);
        pedido.mostrarPedido();
        cout<<endl;
    }

    return 0;
}
