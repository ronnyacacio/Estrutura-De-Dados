#include <stdio.h>
#include <limits.h>
#include "qxdsearching.h"
#include "qxddefs.h"

bool qx_contains(int array[], size_t num_elems, int element, qxSortType sorting){
	if(sorting == ARRAY_NOT_SORTED){
		for(int i = 0; i < num_elems; ++i){
			if(array[i] == element){
				return true;
			}
		}
		return false;
	} else if(sorting == ARRAY_ASC){
		int inicio = 0;
		int fim = num_elems-1;
		while(inicio <= fim){
			int meio = (fim + inicio)/2;
        	if (element == array[meio])
            	return true;
        	if (element < array[meio])
            	fim = meio-1;
        	else
            	inicio = meio+1;
     	}
     	return false;
	} else {
		int inicio = 0;
		int fim = num_elems-1;
		while(inicio <= fim){
			int meio = (fim + inicio)/2;
			if(element == array[meio])
				return true;
			if(element < array[meio])
				inicio = meio+1;
			else
				fim = meio-1;
		}
		return false;	
	}
}

qxIndex qx_find_index(int array[], size_t num_elems, int element, qxSortType sorting){
	if(sorting == ARRAY_NOT_SORTED){
		for(int i = 0; i < num_elems; ++i){
			if(array[i] == element){
				return i;
			}
		}
		return QX_LAMBDA_INDEX;
	} else if(sorting == ARRAY_ASC){
		int inicio = 0;
		int fim = num_elems-1;
		while(inicio <= fim){
			int meio = (fim + inicio)/2;
        	if (element == array[meio])
            	return meio;
        	if (element < array[meio])
            	fim = meio-1;
        	else
            	inicio = meio+1;
     	}
     	return QX_LAMBDA_INDEX;
	} else {
		int inicio = 0;
		int fim = num_elems-1;
		while(inicio <= fim){
			int meio = (fim + inicio)/2;
			if(element == array[meio])
				return meio;
			if(element < array[meio])
				inicio = meio+1;
			else
				fim = meio-1;
		}
		return QX_LAMBDA_INDEX;	
	}	
}

qxIndex qx_lower_bound(int array[], size_t num_elems, int element, qxSortType sorting){
	if(sorting == ARRAY_NOT_SORTED){
		for(int i = 0; i < num_elems; ++i){
			if(array[i] == element){
				return i;
			}
		}
		return QX_LAMBDA_INDEX;
	} else if(sorting == ARRAY_ASC){
		int inicio = 0;
		int fim = num_elems-1;
		while(inicio <= fim){
			int meio = (fim + inicio)/2;
        	if (element == array[meio]){
  		      	if(meio != 0){
  		      		if(array[meio-1] == array[meio]){
  		      			fim = meio-1;
  		      		} else {
  		      			return meio;
  		      		}
  		      	} else {
  		      		return meio;
  		      	}  		     
  		    } else {
	        	if (element < array[meio])
	            	fim = meio-1;
	        	else
	            	inicio = meio+1;
     		}
     	}
     	return QX_LAMBDA_INDEX;
	} else {
		int inicio = 0;
		int fim = num_elems-1;
		while(inicio <= fim){
			int meio = (fim + inicio)/2;
			if(element == array[meio]){
				if(meio != 0){
					if(array[meio-1] == array[meio]){
						fim = meio-1;
					} else {
						return meio;
					}
				} else {
					return meio;
				}
			} else {
				if(element < array[meio])
					inicio = meio+1;
				else
					fim = meio-1;
			}
		}
		return QX_LAMBDA_INDEX;	
	}	
}

qxIndex qx_upper_bound(int array[], size_t num_elems, int element, qxSortType sorting){
	if(sorting == ARRAY_NOT_SORTED){
		for(int i = num_elems-1; i >= 0; --i){
			if(array[i] == element){
				return i;
			}
		}
		return QX_LAMBDA_INDEX;
	} else if(sorting == ARRAY_ASC){
		int inicio = 0;
		int fim = num_elems-1;
		while(inicio <= fim){
			int meio = (fim + inicio)/2;
        	if (element == array[meio]){
  		      	if(meio != num_elems-1){
  		      		if(array[meio+1] == array[meio]){
  		      			inicio = meio+1;
  		      		} else {
  		      			return meio;
  		      		}
  		      	} else {
  		      		return meio;
  		      	}  		     
  		    } else {
	        	if (element < array[meio])
	            	fim = meio-1;
	        	else
	            	inicio = meio+1;
     		}
     	}
     	return QX_LAMBDA_INDEX;
	} else {
		int inicio = 0;
		int fim = num_elems-1;
		while(inicio <= fim){
			int meio = (fim + inicio)/2;
			if(element == array[meio]){
				if(meio != num_elems-1){
					if(array[meio+1] == array[meio]){
						inicio = meio+1;
					} else {
						return meio;
					}
				} else {
					return meio;
				}
			} else {
				if(element < array[meio])
					inicio = meio+1;
				else
					fim = meio-1;
			}
		}
		return QX_LAMBDA_INDEX;	
	}
}
