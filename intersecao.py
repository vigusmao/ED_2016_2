from random import randint
from time import time


MAX_ELEMENTO = 10**6
N = 100000



def criar_lista(tamanho):
    conjunto = set()
    while len(conjunto) < tamanho:
        conjunto.add(randint(1, MAX_ELEMENTO))
    return list(conjunto)

    

def intersecao_quadratico(lista1, lista2):
    resultado = []
    for elemento in lista1:
        for candidato in lista2:
            if candidato == elemento:
                resultado += [elemento]
                break
    return resultado

def intersecao_ordenando(lista1, lista2):
    resultado = []
    lista2_ordenada = sorted(lista2)
    for elemento in lista1:
        if busca_binaria(lista2_ordenada, elemento) > -1:
            resultado += [elemento]
    return resultado    
    



def busca_binaria(lista, elemento):
    '''
    Retorna o indice do elemento na lista, se estiver contido;
    caso contrario, retorna -1

    parametros:
       lista: uma lista ORDENADA
       elemento: o elemento desejado
    '''
    inicio = 0
    fim = len(lista) - 1
    while inicio <= fim:
        indice_central = (inicio + fim) // 2
        elemento_central = lista[indice_central]
        if elemento_central == elemento:
            return indice_central
        if elemento_central > elemento:
            fim = indice_central - 1
        else:
            inicio = indice_central + 1
    return -1
            
            


lista1 = criar_lista(N)
lista2 = criar_lista(N)
##
##start = time()
##resultado = intersecao_quadratico(lista1, lista2)
##duracao = time() - start
##print("\nquadratico\n tamanho da intersecao = %d (duracao = %f segundos)" %
##      (len(resultado), duracao))

start = time()
resultado = intersecao_ordenando(lista1, lista2)
duracao = time() - start
print("\nordenando\n tamanho da intersecao = %d (duracao = %f segundos)" %
      (len(resultado), duracao))



























        
