#include <iostream>
#include <cmath>

using namespace std;

int main(int i)
{

     int A[4], raiz[100];
     int n(0), grau(0);

    cout<<"\nEntre com os valores da funcao\n\n";

    for(i = 0 ; i < 4 ; i++)
    {
        cout<<"A["<<i<<"]=";
        cin>>A[i];
        grau++;
    }

    cout<<"\na = "<<A[0]<<", b = "<<A[1]<<", c = "<<A[2]<<", d = "<<A[3]<<"\n\n";

    int  dividendo, aux(0) ;

    dividendo = A[3];
    cout<<"dividendo = "<<dividendo<<"\n\n";

    for(i = 1 ; i <= 100 ; i++)
    {
          aux = dividendo % i;

          if(aux == 0)
         {
              aux = i;
              raiz[n] = aux;
              raiz[n+1] = -aux;
              cout<<"raiz["<<n<<"] = "<<raiz[n]<<"\n";
              cout<<"raiz["<<n+1<<"] = "<<raiz[n+1]<<"\n";
              n+=2;
          }
    }

    int aux2[n] [grau];

    for (int linhaN = 0; linhaN < n; linhaN++)
    {
        aux2[linhaN][0] = A[0];
        
        for (int colunaN = 1; colunaN < grau; colunaN++){
            aux2[linhaN][colunaN] = (raiz[linhaN] * aux2[linhaN][colunaN-1]) + A[colunaN];
        }

        if (aux2[linhaN][grau-1] == 0){
            int delta[4],r2,r3;
            cout <<"Raiz 1 = " << raiz[linhaN] << "\n";
            cout <<"Termos do Polinomio: ";
            
            for(int i2 = 0; i2 < grau-1; i2++)
            {
                delta[i2] = aux2[linhaN][i2];
                cout << aux2[linhaN][i2] << ",";
            }

            cout <<"Polinomio: ";
            for(int i2 = 0; i2 < grau-1; i2++)
            {
                if ((i2-(grau-2))*-1 > 1)
                    cout << aux2[linhaN][i2] << "X^(" <<  (i2-(grau-2))*-1 << ")";
                    
                else if((i2-(grau-2))*-1 == 1)
                    cout << aux2[linhaN][i2] << "X";
                    
                else if(aux2[linhaN][i2] > 0)
                    cout <<"+" << aux2[linhaN][i2] << "\n";
            }

            delta[3] = pow(delta[1], 2)-(4*delta[0]*delta[2]);
            r2 = (-delta[1]-sqrt(delta[3]))/2*delta[0];
            r3 = (-delta[1]+sqrt(delta[3]))/2*delta[0];
            cout << "Raiz 1 = " << raiz[linhaN] << "\nRaiz 2 = " << r2 << "\nRaiz 3 = " << r3 << "\n";
            break;
        }
    }
    return 0;
}
