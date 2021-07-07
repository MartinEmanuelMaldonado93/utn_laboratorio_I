#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
	this->pFirstNode=NULL;
	this->size=0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
	returnAux= (*this).size;
    }
    return returnAux;
}
/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* new_node = NULL;

    if(this!=NULL && ll_len(this)>=0 && nodeIndex>=0 && nodeIndex < ll_len(this) )
    {
	if(nodeIndex==0)
	{
	    new_node = this->pFirstNode;
	}
	else
	{
	    new_node = this->pFirstNode;
	    for(int i=0; i<nodeIndex  ;i++)
	    {
		new_node = (*new_node).pNextNode;
	    }
	}
    }
    return new_node;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int retorno = -1;
    int len;
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* current_node = NULL;
    Node* previous_node = NULL;

    if(this!=NULL && new_node!=NULL && nodeIndex>=0 && nodeIndex<= ll_len(this) )
    {
	len = ll_len(this);
	if( this->pFirstNode == NULL &&  nodeIndex==0 )
	{
	    (*this).pFirstNode = new_node;
	    (*new_node).pElement = pElement;
	    (*this).size= len+1;
	    retorno=0;
	}
	else if (this->pFirstNode!=NULL && nodeIndex >0 && nodeIndex<len )
	{
	    current_node = getNode(this, nodeIndex);
	    previous_node = getNode(this, nodeIndex-1);
	    (*new_node).pNextNode = current_node;
	    previous_node->pNextNode = new_node;
	    new_node->pElement = pElement;
	    (*this).size= len + 1 ;
	    retorno=0;
	}
	else if ( this->pFirstNode !=NULL && nodeIndex == len )// agrego al final
	{
	    previous_node = getNode(this, nodeIndex-1);
	    previous_node->pNextNode=new_node;
	    new_node->pNextNode= NULL;
	    new_node->pElement=pElement;
	    this->size= len+1;
	    retorno=0;
	}
    }
    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this!=NULL )
    {
	len = ll_len(this);
	returnAux = addNode(this, len , pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* aux_node;
    if(this!=NULL && index>=0 && ll_len(this)>=index)
    {
	aux_node = getNode(this, index);
	if(aux_node !=NULL)
	    returnAux = aux_node->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
* 	   o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* aux_node;
    if(this!=NULL && index>=0 && index < ll_len(this))
    {
	returnAux=0;
	aux_node = getNode(this, index);
	if(aux_node!=NULL)
	{
	    aux_node->pElement = pElement;
	}

    }
    return returnAux;
}
/** \brief Elimina un elemento de la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* next_node;
    Node* current_node;
    Node* previous_node;

    if(this!=NULL && index>=0 && index < len )
    {

	current_node = getNode(this, index);
	if(current_node!=NULL)
	{
	   if(index==0 && this->size ==1 )
	   {
	       returnAux=0;
	       this->pFirstNode=NULL;
	       this->size = 0;
	       free(current_node);
	   }
	   else if(index==0 && len>1 )
	   {
		next_node = getNode(this, 1);
		if( next_node != NULL )
		{
		    returnAux=0;
		    this->pFirstNode= next_node; //piso con nodo 1
		    free(current_node);
		    this->size--;
		}
	   }
	   else if (index>0 && index < len ) // entre 2 nodos
	   {
	       previous_node = getNode(this, index-1);
	       next_node = getNode(this, index+1);
	       if(previous_node !=NULL && next_node !=NULL)
	       {
		   returnAux=0;
		   previous_node->pNextNode = next_node;
		   free(current_node);
		   this->size--;
	       }
	   }
	   else if(index == len-1 )// ultimo
	   {
	       previous_node = getNode(this, index-1);
	       if(previous_node !=NULL )
	       {
		   returnAux=0;
		   previous_node->pNextNode= NULL;
		   free(current_node);
		   this->size--;
	       }
	   }
	}
    }
    return returnAux;
}
/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
	int len = ll_len(this);

	for(int i=0; i<len ;i++)
	{
	    ll_remove(this, i);
	}

	this->pFirstNode=NULL;
	this->size=0;
	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL && ll_clear(this)==0)
    {
	free(this);
	returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* aux_node;
    if(this!=NULL )
    {
	 int len = ll_len(this);
	 for(int i=0; i<len; i++)
	 {
	     aux_node = getNode(this, i);
	     if(aux_node->pElement == pElement)
	     {
		 returnAux = i;
		 break;
	     }
	 }
    }
    return returnAux;
}
/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
	if(this->pFirstNode == NULL )
	{
	    returnAux=1;
	}
	else
	    returnAux=0;
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && index>=0 && index <= ll_len(this))
    {
	if (addNode(this, index, pElement)==0)
	{
	    returnAux=0;
	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index <= ll_len(this) )
    {
	returnAux = ll_get(this, index);
	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
	if(ll_indexOf(this, pElement)== -1)
	    returnAux = 0;
	else
	    returnAux = 1;
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
	    ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
	    ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len1;
    int len2;
    int aux_len2;
    Node* aux_node;
    if(this!=NULL && this2!=NULL )
    {
	returnAux = 0;
	len1 = ll_len(this);
	len2 = ll_len(this2);
	aux_len2= len2;

	if ( len1 >= len2 )
	{
	    for(int i=0; i< len1 ;i++)
	    {
	       aux_node = getNode(this2, i);
	       if(ll_contains(this, aux_node->pElement)==1)
	       {
		   aux_len2--;
	       }
	    }
	    if(aux_len2==0)
	    {
		returnAux = 1;
	    }
	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
	o (si el indice from es menor a 0 o mayor al len de la lista)
	o (si el indice to es menor o igual a from o mayor al len de la lista)
	(puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    void* pElement;
    if(this!=NULL && from >=0 && from<=to && to<=len)
    {
	cloneArray = ll_newLinkedList();
	for(int i=from; i<to;i++)
	{
	    pElement = ll_get(this,i);
	    if(pElement!=NULL)
		ll_add(cloneArray, pElement);
	}
    }
    return cloneArray;
}
/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
	cloneArray = this;
    }
    return cloneArray;
}
/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                            ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int flag_swap= 1;
    void* pElement1;
    void* pElement2;

    if(this!=NULL && pFunc!=NULL && order>0 && order<2)
    {
	while(flag_swap)
	{
	    flag_swap = 0;
	    for(int i=0; i< ll_len(this)-1; i++)
	    {
		pElement1 = ll_get(this, i);
		pElement2 = ll_get(this, i+1);

		if(pElement1 !=NULL && pElement2!=NULL
		&& ((pFunc(pElement1,pElement2)>0 && order ==1)
		|| (pFunc(pElement1,pElement2) <0 && order ==0)))
		{
		    ll_set(this, i, pElement2);
		    ll_set(this, i+1, pElement1);
		    flag_swap = 1;
		}
	    }
	}
	returnAux = 0;
    }
    return returnAux;
}
/**
 * \brief Analiza los elementos de una lista y aplica una funcion en cada elemento
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList
 */
LinkedList* ll_map(LinkedList* this, void (*pFunc)(void* element))
{
    void* pElement_aux = NULL;

    if(this!=NULL && pFunc!=NULL)
    {
	for(int i=0; i<ll_len(this) ; i++)
	{
	    pElement_aux = ll_get(this, i); // obtengo el elemento y lo analizo para aplicar posterior funcion
	    pFunc(pElement_aux);
	}
    }
    return this;
}
